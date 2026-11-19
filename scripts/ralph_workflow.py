#!/usr/bin/env python3
"""
Ralph-style decompilation loop as a run_workflow script.

Mirrors scripts/ralph_decomp.sh wave-by-wave.  Each wave fans out
RALPH_PARALLEL decomp agents in parallel (one per slice); the sequential
measurement / record / promote / commit steps happen after every wave.

Usage (from the agy coordinator):
    run_workflow(ScriptPath="scripts/ralph_workflow.py", Args={...})

Args (all optional, same semantics as the env-vars in ralph_decomp.sh):
    ralph_parallel        int   default 2
    ralph_model           str   default ""
    ralph_min_pct         float default 90
    ralph_max_attempts    int   default 5
    ralph_max_slice       str   default "0x800"
    ralph_timeout         int   default 1800
    ralph_dry_run         bool  default false
    ralph_dir             str   default "build/ralph"
    ralph_stall           int   default 2
    ralph_max_passes      int   default 3
    ralph_asm_policy      str   default "once"   (once|skip|off)
    ralph_summary_every   int   default 5
    ralph_unavailable_retries  int default 3
    ralph_unavailable_backoff  int default 30
    ralph_wait_on_quota   int   default 0
    ralph_push            int   default 1
    ralph_branch          str   default "main"
"""

import asyncio
import json
import os
import subprocess
import sys
import textwrap
import time

# ---------------------------------------------------------------------------
# Config from Args (injected by run_workflow)
# ---------------------------------------------------------------------------
_A = args  # noqa: F821  – injected by run_workflow runtime

RALPH_PARALLEL          = int(_A.get("ralph_parallel", 2))
RALPH_MODEL             = str(_A.get("ralph_model", ""))
RALPH_MIN_PCT           = float(_A.get("ralph_min_pct", 90))
RALPH_MAX_ATTEMPTS      = int(_A.get("ralph_max_attempts", 5))
RALPH_MAX_SLICE         = str(_A.get("ralph_max_slice", "0x800"))
RALPH_TIMEOUT           = int(_A.get("ralph_timeout", 1800))
RALPH_DRY_RUN           = bool(_A.get("ralph_dry_run", False))
RALPH_DIR               = str(_A.get("ralph_dir", "build/ralph"))
RALPH_STALL             = int(_A.get("ralph_stall", 2))
RALPH_MAX_PASSES        = int(_A.get("ralph_max_passes", 3))
RALPH_ASM_POLICY        = str(_A.get("ralph_asm_policy", "once"))
RALPH_SUMMARY_EVERY     = int(_A.get("ralph_summary_every", 5))
RALPH_UNAVAILABLE_RETRIES = int(_A.get("ralph_unavailable_retries", 3))
RALPH_UNAVAILABLE_BACKOFF = int(_A.get("ralph_unavailable_backoff", 30))
RALPH_WAIT_ON_QUOTA     = int(_A.get("ralph_wait_on_quota", 0))
RALPH_PUSH              = int(_A.get("ralph_push", 1))
RALPH_BRANCH            = str(_A.get("ralph_branch", "main"))

ROOT = WORKSPACES[0] if WORKSPACES else os.getcwd()  # noqa: F821
PY   = os.path.join(ROOT, ".venv", "bin", "python")
SLICE_CMD  = [PY, "scripts/ralph_slice.py"]
PIPELINE   = [PY, "scripts/decomp_pipeline.py"]
METRICS    = [PY, "scripts/ralph_metrics.py"]
STATE      = os.path.join(ROOT, RALPH_DIR, "state.json")
EVENTS     = os.path.join(ROOT, RALPH_DIR, "metrics", "events.jsonl")

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _run(cmd, *, capture=True, check=True, cwd=ROOT, **kw):
    """Run a subprocess, raise on failure (unless check=False)."""
    r = subprocess.run(
        cmd, capture_output=capture, text=True, cwd=cwd, check=False, **kw
    )
    if check and r.returncode != 0:
        raise RuntimeError(
            f"Command {cmd} failed (rc={r.returncode}):\n{r.stderr or r.stdout}"
        )
    return r


def _jget(json_str, key):
    return json.loads(json_str)[key]


def _jopt(json_str, key):
    v = json.loads(json_str).get(key)
    if v is None or v is False:
        return ""
    if isinstance(v, list):
        return " ".join(str(x) for x in v)
    return str(v)


def _emit(kind, **kv):
    pairs = [f"{k}={v}" for k, v in kv.items()]
    try:
        _run(METRICS + ["record", "--events", EVENTS, "--type", kind] + pairs)
    except Exception as e:
        log(f"metrics: could not record {kind}: {e}")  # noqa: F821


def _preflight():
    assert os.path.isfile(PY), f"missing {PY}"
    assert os.path.isfile(os.path.join(ROOT, "orig/SLES-50282/AOK.ELF")), \
        "missing orig/SLES-50282/AOK.ELF"
    sha_file = os.path.join(ROOT, "config/SLES-50282/build.sha1")
    expected = open(sha_file).read().strip().replace(" ", "")[:40]
    import hashlib
    h = hashlib.sha1(
        open(os.path.join(ROOT, "orig/SLES-50282/AOK.ELF"), "rb").read()
    ).hexdigest()
    assert h == expected, f"AOK.ELF sha1 mismatch ({h} != {expected})"
    assert os.path.isfile(
        os.path.join(ROOT, "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe")
    ), "missing MWCC compiler"
    assert os.path.isfile(
        os.path.join(ROOT, "build/tools/wibo")
    ), "missing build/tools/wibo"
    assert RALPH_ASM_POLICY in ("once", "skip", "off"), \
        "ralph_asm_policy must be once|skip|off"
    assert RALPH_PUSH in (0, 1), "ralph_push must be 0 or 1"
    assert RALPH_PARALLEL >= 1, "ralph_parallel must be >= 1"


def _build_prompt(func, vram, size, feedback_file, hints=""):
    hexdump = _run(
        [PY, "-c",
         "import sys;sys.path.insert(0,'scripts');import decomp_pipeline as d;"
         "b=d.get_original_bytes(int(sys.argv[1],0),int(sys.argv[2],0));"
         "print('\\n'.join(' '.join(b[i:i+16][j:j+4].hex() for j in range(0,len(b[i:i+16]),4))"
         " for i in range(0,len(b),16)))",
         vram, size],
        cwd=ROOT,
    ).stdout.strip()
    disasm = _run(
        SLICE_CMD + ["disasm", "--vram", vram, "--size", size], cwd=ROOT
    ).stdout.strip()
    neighbours = _run(
        [PY, "-c",
         "import subprocess, sys\n"
         "r=subprocess.run(['grep','-E','type:func','config/SLES-50282/symbols.txt'],"
         "capture_output=True,text=True);lines=r.stdout.strip().splitlines();"
         "print('\\n'.join(lines[-8:]))"],
        cwd=ROOT,
    ).stdout.strip()
    feedback = ""
    if os.path.isfile(feedback_file) and os.path.getsize(feedback_file) > 0:
        feedback = "\n## Previous attempt feedback (fix this)\n" + open(feedback_file).read()
    hints_line = ""
    if hints:
        hints_line = (
            f"- Static hint: contains non-C instructions ({hints}); likely hand-written asm. "
            "One attempt only. If no C/C++ can produce it, reply `UNMATCHABLE: <reason>`."
        )
    tmpl = open(os.path.join(ROOT, "scripts/ralph_prompt.tmpl.md")).read()
    staging = f"staging/{func}.cpp"
    for k, v in {
        "FUNC": func, "VRAM": vram, "SIZE": size,
        "STAGING_FILE": staging,
        "STAGING_FILE_OBJ": staging[:-4] + ".o",
        "HEXDUMP": hexdump, "DISASM": disasm,
        "NEIGHBOURS": neighbours,
        "FEEDBACK": feedback,
        "HINTS_LINE": hints_line,
    }.items():
        tmpl = tmpl.replace("{{" + k + "}}", v)
    return tmpl


def _measure_attempt(func, vram, size, feedback_file):
    """Compile + measure. Returns float pct; writes feedback to feedback_file."""
    source = os.path.join(ROOT, f"staging/{func}.cpp")
    with open(feedback_file, "w") as f:
        pass
    if not os.path.isfile(source) or os.path.getsize(source) == 0:
        with open(feedback_file, "w") as f:
            f.write(f"No file written at {source}.")
        return 0.0
    r = _run(PIPELINE + ["compile", "--source", source], check=False, cwd=ROOT)
    if r.returncode != 0:
        with open(feedback_file, "w") as f:
            f.write(f"Compilation failed:\n{r.stdout}\n{r.stderr}")
        return 0.0
    obj = os.path.join(ROOT, f"staging/{func}.o")
    r2 = _run(
        SLICE_CMD + ["measure", "--func", func, "--vram", vram, "--size", size, "--obj", obj],
        check=False, cwd=ROOT,
    )
    if r2.returncode != 0:
        with open(feedback_file, "w") as f:
            f.write(f"Measure failed:\n{r2.stdout}\n{r2.stderr}")
        return 0.0
    result = json.loads(r2.stdout)
    sbs = result.pop("side_by_side", [])
    with open(feedback_file, "w") as f:
        f.write("Measured: " + json.dumps(result) + "\n")
        if sbs:
            f.write("Original | compiled around divergences (! = differs):\n")
            f.write("\n".join(sbs) + "\n")
    return float(result.get("pct", 0))


def _publish_commits():
    if RALPH_PUSH != 1:
        return True
    r = _run(["git", "fetch", "-q", "origin"], check=False, cwd=ROOT)
    if r.returncode != 0:
        return False
    r2 = _run(["git", "rebase", "-q", f"origin/{RALPH_BRANCH}"], check=False, cwd=ROOT)
    if r2.returncode != 0:
        _run(["git", "rebase", "--abort"], check=False, cwd=ROOT)
        log(f"rebase onto origin/{RALPH_BRANCH} failed; not pushing")  # noqa
        return False
    _run(["git", "push", "-q", "origin", f"HEAD:{RALPH_BRANCH}"], cwd=ROOT)
    return True


def _promote_and_commit(func, vram, size, pct, attempts, seconds, wave_no):
    offset = hex(int(vram, 16) - 0x100000 + 0x1E0)
    _run(
        PIPELINE + [
            "promote", "--func", func, "--module", "kcet",
            "--source", f"staging/{func}.cpp",
            "--header", f"{func}.h",
            "--vram", vram, "--offset", offset, "--size", size,
        ],
        cwd=ROOT,
    )
    _run(
        ["git", "add", "--",
         f"src/kcet/{func}.cpp",
         "config/SLES-50282/config.yml",
         "config/SLES-50282/symbols.txt",
         "configure.py"],
        cwd=ROOT,
    )
    msg_r = _run(
        SLICE_CMD + [
            "commit-message",
            "--func", func, "--vram", vram, "--size", size,
            "--pct", str(pct), "--attempts", str(attempts),
            "--seconds", str(seconds), "--wave", str(wave_no),
            "--agent", "workflow", "--model", RALPH_MODEL or "default",
        ],
        cwd=ROOT,
    )
    subprocess.run(
        ["git", "commit", "-q", "-F", "-"],
        input=msg_r.stdout, cwd=ROOT,
        capture_output=True, text=True, check=True,
    )
    if not _publish_commits():
        log("push failed; commits stay local until the next publish")  # noqa


def _mark_asm(func, vram, size, reason):
    _run(
        SLICE_CMD + [
            "mark", "--state", STATE, "--func", func,
            "--vram", vram, "--size", size, "--status", "asm", "--reason", reason,
        ],
        cwd=ROOT,
    )
    log(f"{func} marked asm: {reason}")  # noqa


def _guard_snapshot(guard_file):
    _run(SLICE_CMD + ["guard", "snapshot", "--file", guard_file], cwd=ROOT)


def _guard_check(guard_file, label):
    r = _run(SLICE_CMD + ["guard", "verify", "--file", guard_file, "--restore"],
             check=False, cwd=ROOT)
    if r.returncode != 0:
        log(f"guard verify failed: {r.stderr}")  # noqa
        return
    report = r.stdout
    if '"changed": []' not in report or '"stray": []' not in report:
        log(f"{label} guard restored agent edits: {report}")  # noqa


def _unmatchable_reason(agent_log_path):
    if not os.path.isfile(agent_log_path):
        return ""
    lines = [l for l in open(agent_log_path).read().splitlines() if l.strip()]
    if not lines:
        return ""
    last = lines[-1]
    import re
    m = re.match(r"^UNMATCHABLE:\s*(.+)$", last)
    return m.group(1) if m else ""


def _failure_class(agent_log_path):
    r = _run(SLICE_CMD + ["classify-failure", "--log", agent_log_path],
             check=False, cwd=ROOT)
    if r.returncode != 0:
        return "none"
    return _jget(r.stdout, "class")


def _print_summary():
    r = _run(SLICE_CMD + ["summary", "--state", STATE], cwd=ROOT)
    s = json.loads(r.stdout)
    t = s["total_bytes"] or 1
    pct = lambda b: 100.0 * b / t
    log(
        "[ralph] progress: C/C++ real {:.2f}% ({} bytes) | asm {:.2f}% | "
        "partial {:.2f}% | blocked {:.2f}% | covered {:.2f}% counts={} time={:.0f}s eta={}".format(
            pct(s["cpp_bytes"]), s["cpp_bytes"], pct(s["asm_bytes"]),
            pct(s["partial_bytes"]), pct(s["blocked_bytes"]),
            pct(s["covered_bytes"]), s["counts"], s["total_seconds"],
            "n/a" if s["eta_seconds"] is None else f"{s['eta_seconds']:.0f}s",
        )
    )  # noqa


def _snapshot_metrics():
    try:
        _run(METRICS + ["snapshot", "--state", STATE, "--events", EVENTS])
    except Exception as e:
        log(f"metrics: could not record snapshot: {e}")  # noqa


# ---------------------------------------------------------------------------
# Per-slice decomp agent prompt builder (pure Python, no agent invocation here)
# ---------------------------------------------------------------------------

def _build_slice_prompt(func, vram, size, feedback_file, hints):
    """Build the full prompt text for one decomp slice."""
    return _build_prompt(func, vram, size, feedback_file, hints)


# ---------------------------------------------------------------------------
# Wave execution
# ---------------------------------------------------------------------------

async def run_wave(batch_json, wave_no):
    """
    One wave: parallel agent fan-out then sequential measure/record/promote.
    Returns number of slices processed (WAVE_SIZE equivalent).
    """
    items = []
    for it in batch_json.get("items", []):
        func  = it["func"]
        vram  = "0x%X" % it["vram"]
        size  = "0x%X" % it["size"]
        la    = it.get("likely_asm", False)
        hints = " ".join(it.get("hints", [])) if la else ""
        limit = RALPH_MAX_ATTEMPTS
        if la and RALPH_ASM_POLICY == "skip":
            _mark_asm(func, vram, size, f"hints: {hints}")
            continue
        if la and RALPH_ASM_POLICY == "once":
            limit = 1
        # stage the source stub
        _run(PIPELINE + ["stage", "--func", func, "--vram", vram, "--size", size],
             cwd=ROOT)
        items.append({"func": func, "vram": vram, "size": size,
                      "hints": hints, "limit": limit,
                      "attempts": 0, "seconds": 0})

    for func in batch_json.get("marked_asm", []):
        log(f"{func} marked asm: no function end")  # noqa

    if not items:
        return 0

    # Dry-run: just write prompts
    if RALPH_DRY_RUN:
        for it in items:
            func, vram, size = it["func"], it["vram"], it["size"]
            attempt_dir = os.path.join(ROOT, RALPH_DIR, func, "attempt-1")
            os.makedirs(attempt_dir, exist_ok=True)
            prompt_path = os.path.join(attempt_dir, "prompt.md")
            prompt_text = _build_slice_prompt(func, vram, size, "/dev/null", it["hints"])
            open(prompt_path, "w").write(prompt_text)
            log(f"dry run: {func} {vram} {size} hints=[{it['hints']}] -> {prompt_path}")  # noqa
        return len(items)

    # Active indices: all items start active
    active = list(range(len(items)))

    phase(f"Wave {wave_no}")  # noqa

    while active:
        # Snapshot guard before the round
        guard_file = os.path.join(ROOT, RALPH_DIR, "guard.json")
        _guard_snapshot(guard_file)

        # Build prompts for this round
        round_items = []
        for idx in active:
            it = items[idx]
            it["attempts"] += 1
            func, vram, size = it["func"], it["vram"], it["size"]
            attempt_dir = os.path.join(ROOT, RALPH_DIR, func, f"attempt-{it['attempts']}")
            os.makedirs(attempt_dir, exist_ok=True)
            feedback_file = os.path.join(ROOT, RALPH_DIR, func, "feedback.txt")
            if not os.path.exists(feedback_file):
                open(feedback_file, "w").close()
            prompt_text = _build_slice_prompt(func, vram, size, feedback_file, it["hints"])
            prompt_path = os.path.join(attempt_dir, "prompt.md")
            open(prompt_path, "w").write(prompt_text)
            log(f"{func} attempt {it['attempts']}/{it['limit']} via workflow agent (wave {wave_no})")  # noqa
            round_items.append((idx, it, attempt_dir, prompt_text))

        # Fan out: one decomp agent per slice in parallel
        # Each agent writes staging/<func>.cpp and replies with a one-line outcome.
        schema = {"type": "string"}

        async def run_one(item_tuple):
            idx, it, attempt_dir, prompt_text = item_tuple
            func = it["func"]
            # Inter-agent style prompt (terse, outcome first)
            full_prompt = (
                f"Decomp task: match function {func}.\n\n"
                + prompt_text
            )
            started = time.monotonic()
            agent_model = RALPH_MODEL if RALPH_MODEL in ("flash_lite", "flash", "pro") else "inherit"
            result = await agent(  # noqa: F821
                full_prompt,
                schema=schema,
                role=f"Decomp {func} w{wave_no}a{it['attempts']}",
                workspace="inherit",
                model=agent_model,
            )
            elapsed = int(time.monotonic() - started)
            # Write seconds file for metrics
            open(os.path.join(attempt_dir, "seconds"), "w").write(str(elapsed))
            # Write agent reply to agent.log
            open(os.path.join(attempt_dir, "agent.log"), "w").write(str(result))
            return idx, elapsed

        results = await parallel(round_items, run_one)  # noqa: F821

        # Restore any guard violations after agents ran
        _guard_check(guard_file, f"wave {wave_no}")

        # Accumulate seconds
        for idx, elapsed in results:
            items[idx]["seconds"] += elapsed

        # Sequential: measure, record, promote
        next_active = []
        for idx in active:
            it = items[idx]
            func, vram, size = it["func"], it["vram"], it["size"]
            attempt_dir = os.path.join(ROOT, RALPH_DIR, func, f"attempt-{it['attempts']}")
            feedback_file = os.path.join(ROOT, RALPH_DIR, func, "feedback.txt")
            agent_log = os.path.join(attempt_dir, "agent.log")

            # Check for UNMATCHABLE
            reason = _unmatchable_reason(agent_log)
            if reason:
                _mark_asm(func, vram, size, reason)
                _emit("slice_final", func=func, vram=vram, size=size,
                      status="asm", pct=0,
                      attempts=it["attempts"], seconds=it["seconds"])
                continue

            # Measure
            pct = _measure_attempt(func, vram, size, feedback_file)
            diff_path = os.path.join(attempt_dir, "diff.txt")
            if os.path.isfile(feedback_file):
                import shutil
                shutil.copy(feedback_file, diff_path)
            elapsed_now_file = os.path.join(attempt_dir, "seconds")
            elapsed_now = int(open(elapsed_now_file).read().strip()) if os.path.isfile(elapsed_now_file) else 0
            log(f"{func} similarity {pct}% ({elapsed_now}s)")  # noqa

            # Record
            record_r = _run(
                SLICE_CMD + [
                    "record", "--state", STATE,
                    "--func", func, "--vram", vram, "--size", size,
                    "--pct", str(pct),
                    "--attempts", str(it["attempts"]),
                    "--min-pct", str(RALPH_MIN_PCT),
                    "--max-attempts", str(it["limit"]),
                    "--seconds", str(elapsed_now),
                    "--stall", str(RALPH_STALL),
                ],
                cwd=ROOT,
            )
            status_now = _jget(record_r.stdout, "status")

            _emit("attempt",
                  func=func, vram=vram, size=size,
                  attempt=it["attempts"], agent="workflow",
                  model=RALPH_MODEL or "default",
                  pct=pct, seconds=elapsed_now,
                  outcome=status_now, wave=wave_no, slot=idx)

            if status_now == "retry" and it["attempts"] < it["limit"]:
                next_active.append(idx)
            else:
                # finish_slice
                final = status_now
                if status_now == "done":
                    _promote_and_commit(func, vram, size, pct,
                                        it["attempts"], it["seconds"], wave_no)
                    log(f"{func} promoted")  # noqa
                elif status_now == "partial":
                    log(f"{func} partial ({pct}%), kept in staging, advancing")  # noqa
                elif it["hints"] and RALPH_ASM_POLICY == "once":
                    _mark_asm(func, vram, size,
                               f"hints: {it['hints']}; best {pct}% in 1 attempt")
                    final = "asm"
                else:
                    log(f"{func} blocked ({pct}%), skipping; revisited later (max {RALPH_MAX_PASSES} passes)")  # noqa
                _emit("slice_final", func=func, vram=vram, size=size,
                      status=final, pct=pct,
                      attempts=it["attempts"], seconds=it["seconds"])

        active = next_active

    _emit("wave", index=wave_no, size=len(items),
          wall_seconds=0, parallel=RALPH_PARALLEL)
    return len(items)


# ---------------------------------------------------------------------------
# Main loop
# ---------------------------------------------------------------------------

phase("Preflight")  # noqa
_preflight()
os.makedirs(os.path.join(ROOT, RALPH_DIR, "metrics"), exist_ok=True)

# Backfill metrics
try:
    _run(METRICS + ["backfill", "--state", STATE, "--events", EVENTS])
except Exception:
    log("metrics: backfill skipped")  # noqa

processed = 0
wave_no   = 0

phase("Decomp loop")  # noqa

while True:
    batch_r = _run(
        SLICE_CMD + [
            "batch", "--state", STATE,
            "--count", str(RALPH_PARALLEL),
            "--max-slice", RALPH_MAX_SLICE,
            "--max-passes", str(RALPH_MAX_PASSES),
        ],
        cwd=ROOT,
    )
    batch = json.loads(batch_r.stdout)
    kind = _jget(batch_r.stdout, "kind")

    if kind == "done":
        log(  # noqa
            f"no work left. unresolved after {RALPH_MAX_PASSES} passes: "
            f"{_jget(batch_r.stdout, 'unresolved')}"
        )
        _print_summary()
        _snapshot_metrics()
        break

    wave_no += 1
    before = processed
    wave_size = await run_wave(batch, wave_no)  # noqa: F821

    if RALPH_DRY_RUN:
        break

    processed += wave_size
    if (
        RALPH_SUMMARY_EVERY > 0
        and processed // RALPH_SUMMARY_EVERY > before // RALPH_SUMMARY_EVERY
    ):
        _print_summary()
        _snapshot_metrics()

log(f"ralph_workflow done. waves={wave_no} slices_processed={processed}")  # noqa
