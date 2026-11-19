#!/usr/bin/env bash
# Ralph-style loop: decompile the whole PS2 .text, slice by slice, in waves of RALPH_PARALLEL slices.
# Only the code generation step (invoke_agent) is non-static; agents run in parallel, everything else is sequential.
# Usage: AGENT=agy|codex|claude [RALPH_MODEL=..] [RALPH_PARALLEL=2] scripts/ralph_decomp.sh
# See docs/ralph_decomp.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

AGENT="${AGENT:-agy}"
RALPH_MODEL="${RALPH_MODEL:-}"
RALPH_EFFORT="${RALPH_EFFORT:-}"              # agy only; empty = no --effort flag (agy rejects it with some models)
RALPH_MIN_PCT="${RALPH_MIN_PCT:-90}"
RALPH_MAX_ATTEMPTS="${RALPH_MAX_ATTEMPTS:-5}"
RALPH_MAX_SLICE="${RALPH_MAX_SLICE:-0x800}"
RALPH_TIMEOUT="${RALPH_TIMEOUT:-1800}"
RALPH_DRY_RUN="${RALPH_DRY_RUN:-0}"
RALPH_DIR="${RALPH_DIR:-build/ralph}"
RALPH_STALL="${RALPH_STALL:-2}"               # attempts without improvement before blocking (0 = off)
RALPH_MAX_PASSES="${RALPH_MAX_PASSES:-3}"     # revisits per partial/blocked slice before giving up
RALPH_ASM_POLICY="${RALPH_ASM_POLICY:-once}"  # likely-asm slices: once (1 attempt) | skip | off
RALPH_SUMMARY_EVERY="${RALPH_SUMMARY_EVERY:-5}"
RALPH_PARALLEL="${RALPH_PARALLEL:-2}"                   # slices per wave; 1 = sequential
RALPH_UNAVAILABLE_RETRIES="${RALPH_UNAVAILABLE_RETRIES:-3}"  # transient model errors retried per agent call
RALPH_UNAVAILABLE_BACKOFF="${RALPH_UNAVAILABLE_BACKOFF:-30}" # seconds before the first retry; doubles each time
RALPH_WAIT_ON_QUOTA="${RALPH_WAIT_ON_QUOTA:-0}"         # 0 = stop on quota; N = sleep N s and retry the call
RALPH_PUSH="${RALPH_PUSH:-1}"                          # 1 = fetch+rebase and push after each promotion commit; 0 = commit only
RALPH_BRANCH="${RALPH_BRANCH:-main}"
CURRENT_WAVE=0
PY=".venv/bin/python"
SLICE="$PY scripts/ralph_slice.py"
PIPELINE="$PY scripts/decomp_pipeline.py"
METRICS="$PY scripts/ralph_metrics.py"
STATE="$RALPH_DIR/state.json"
EVENTS="$RALPH_DIR/metrics/events.jsonl"
LOCK="$RALPH_DIR/lock.pid"
LOCK_OWNER=""
WAVE_SIZE=0

log() { printf '[ralph %s] %s\n' "$(date +%H:%M:%S)" "$*"; }
die() { printf '[ralph] ERROR: %s\n' "$*" >&2; exit 1; }

preflight() {
  [[ -x "$PY" ]] || die "missing $PY"
  [[ -f orig/SLES-50282/AOK.ELF ]] || die "missing orig/SLES-50282/AOK.ELF"
  local expected actual
  expected="$(tr -d '[:space:]' < config/SLES-50282/build.sha1 | cut -c1-40)"
  actual="$(sha1sum orig/SLES-50282/AOK.ELF | cut -c1-40)"
  [[ "$expected" == "$actual" ]] || die "AOK.ELF sha1 mismatch ($actual != $expected)"
  [[ -f compilers/PS2/mwcc-2.3.1.01/mwccps2.exe ]] || die "missing MWCC compiler"
  [[ -x build/tools/wibo ]] || die "missing build/tools/wibo"
  [[ "$RALPH_MIN_PCT" =~ ^[0-9]+(\.[0-9]+)?$ ]] || die "RALPH_MIN_PCT must be numeric"
  [[ "$RALPH_MAX_ATTEMPTS" =~ ^[0-9]+$ ]] || die "RALPH_MAX_ATTEMPTS must be an integer"
  [[ "$RALPH_STALL" =~ ^[0-9]+$ ]] || die "RALPH_STALL must be an integer"
  [[ "$RALPH_MAX_PASSES" =~ ^[0-9]+$ ]] || die "RALPH_MAX_PASSES must be an integer"
  [[ "$RALPH_SUMMARY_EVERY" =~ ^[0-9]+$ ]] || die "RALPH_SUMMARY_EVERY must be an integer"
  [[ "$RALPH_PARALLEL" =~ ^[1-9][0-9]*$ ]] || die "RALPH_PARALLEL must be a positive integer"
  [[ "$RALPH_UNAVAILABLE_RETRIES" =~ ^[0-9]+$ ]] || die "RALPH_UNAVAILABLE_RETRIES must be an integer"
  [[ "$RALPH_UNAVAILABLE_BACKOFF" =~ ^[0-9]+$ ]] || die "RALPH_UNAVAILABLE_BACKOFF must be an integer"
  [[ "$RALPH_WAIT_ON_QUOTA" =~ ^[0-9]+$ ]] || die "RALPH_WAIT_ON_QUOTA must be an integer (seconds)"
  case "$RALPH_PUSH" in 0|1) ;; *) die "RALPH_PUSH must be 0 or 1" ;; esac
  case "$RALPH_ASM_POLICY" in once|skip|off) ;; *) die "RALPH_ASM_POLICY must be once|skip|off" ;; esac
  case "$AGENT" in
    agy|codex|claude) command -v "$AGENT" >/dev/null || die "$AGENT not in PATH" ;;
    *) [[ -x "$AGENT" ]] || die "AGENT must be agy|codex|claude or an executable (got: $AGENT)" ;;
  esac
}

# Pidfile lock. A holder counts only while its pid lives and its command line is this script.
acquire_lock() {
  mkdir -p "$RALPH_DIR"
  if [[ -f "$LOCK" ]]; then
    local holder
    holder="$(tr -dc '0-9' <"$LOCK")"
    if [[ -n "$holder" ]] && kill -0 "$holder" 2>/dev/null && grep -aq 'ralph_decomp' "/proc/$holder/cmdline" 2>/dev/null; then
      die "another ralph_decomp.sh is running (pid $holder, lock $LOCK)"
    fi
    log "removing stale lock (pid ${holder:-unknown} is not a running ralph_decomp.sh)"
  fi
  LOCK_OWNER="$BASHPID"
  printf '%s\n' "$LOCK_OWNER" >"$LOCK"
  trap release_lock EXIT
  trap 'exit 130' INT TERM
}

release_lock() {
  # Background jobs inherit the trap; only the process that took the lock removes the file.
  if [[ -n "$LOCK_OWNER" && "$BASHPID" == "$LOCK_OWNER" && -f "$LOCK" ]]; then
    [[ "$(tr -dc '0-9' <"$LOCK")" == "$LOCK_OWNER" ]] && rm -f "$LOCK"
  fi
  return 0
}

json_get() { "$PY" -c 'import json,sys; print(json.loads(sys.argv[1])[sys.argv[2]])' "$1" "$2"; }
# Like json_get but prints an empty string when the key is missing or false/empty.
json_opt() { "$PY" -c 'import json,sys; v=json.loads(sys.argv[1]).get(sys.argv[2]); print(" ".join(map(str,v)) if isinstance(v,list) else ("" if v in (None,False) else v))' "$1" "$2"; }

# Metrics never stop the loop: a failed write is logged and ignored.
emit() { # type key=value...
  local kind="$1"; shift
  $METRICS record --events "$EVENTS" --type "$kind" "$@" >/dev/null 2>&1 || log "metrics: could not record $kind"
}

build_prompt() { # func vram size feedback_file hints
  local func="$1" vram="$2" size="$3" feedback_file="$4" hints="${5:-}"
  local staging="staging/${func}.cpp" hexdump disasm neighbours feedback=""
  hexdump="$("$PY" -c 'import sys;sys.path.insert(0,"scripts");import decomp_pipeline as d;b=d.get_original_bytes(int(sys.argv[1],0),int(sys.argv[2],0));print("\n".join(" ".join(b[i:i+16][j:j+4].hex() for j in range(0,len(b[i:i+16]),4)) for i in range(0,len(b),16)))' "$vram" "$size")"
  disasm="$($SLICE disasm --vram "$vram" --size "$size")"
  neighbours="$(grep -E 'type:func' config/SLES-50282/symbols.txt | tail -n 8 || true)"
  [[ -s "$feedback_file" ]] && feedback=$'\n## Previous attempt feedback (fix this)\n'"$(cat "$feedback_file")"
  "$PY" - "$func" "$vram" "$size" "$staging" "$hexdump" "$disasm" "$neighbours" "$feedback" "$hints" <<'PYEOF'
import sys
func, vram, size, staging, hexdump, disasm, neighbours, feedback, hints = sys.argv[1:10]
text = open("scripts/ralph_prompt.tmpl.md").read()
for key, value in {
    "FUNC": func, "VRAM": vram, "SIZE": size, "STAGING_FILE": staging,
    "STAGING_FILE_OBJ": staging[:-4] + ".o", "HEXDUMP": hexdump,
    "DISASM": disasm, "NEIGHBOURS": neighbours, "FEEDBACK": feedback,
    "HINTS_LINE": ("- Static hint: contains non-C instructions (" + hints + "); likely hand-written asm. "
                   "One attempt only. If no C/C++ can produce it, reply `UNMATCHABLE: <reason>`.") if hints else "",
}.items():
    text = text.replace("{{" + key + "}}", value)
sys.stdout.write(text)
PYEOF
}

# The only non-static step. Prompt goes in via stdin (agy: --print reads the prompt arg).
invoke_agent() { # prompt_file log_file
  local prompt_file="$1" log_file="$2" model_args=()
  case "$AGENT" in
    agy)
      [[ -n "$RALPH_MODEL" ]] && model_args=(--model "$RALPH_MODEL")
      [[ -n "$RALPH_EFFORT" ]] && model_args+=(--effort "$RALPH_EFFORT")
      timeout "$RALPH_TIMEOUT" agy --print "$(cat "$prompt_file")" --dangerously-skip-permissions \
        "${model_args[@]}" >"$log_file" 2>&1 ;;
    codex)
      [[ -n "$RALPH_MODEL" ]] && model_args=(-m "$RALPH_MODEL")
      timeout "$RALPH_TIMEOUT" codex exec --dangerously-bypass-approvals-and-sandbox \
        "${model_args[@]}" - <"$prompt_file" >"$log_file" 2>&1 ;;
    claude)
      [[ -n "$RALPH_MODEL" ]] && model_args=(--model "$RALPH_MODEL")
      timeout "$RALPH_TIMEOUT" claude -p --dangerously-skip-permissions \
        "${model_args[@]}" <"$prompt_file" >"$log_file" 2>&1 ;;
    *) timeout "$RALPH_TIMEOUT" "$AGENT" <"$prompt_file" >"$log_file" 2>&1 ;;
  esac
}

# Static: compile + measure. Prints pct; writes feedback to $3.
measure_attempt() { # func vram size feedback_file
  local func="$1" vram="$2" size="$3" feedback_file="$4" source="staging/${1}.cpp" result
  : >"$feedback_file"
  if [[ ! -s "$source" ]]; then echo "0"; echo "No file written at $source." >"$feedback_file"; return; fi
  local compile_output
  if ! compile_output="$($PIPELINE compile --source "$source" 2>&1)"; then
    echo "0"; printf 'Compilation failed:\n%s\n' "$compile_output" >"$feedback_file"; return
  fi
  result="$($SLICE measure --func "$func" --vram "$vram" --size "$size" --obj "staging/${func}.o" 2>&1)" || {
    echo "0"; printf 'Measure failed:\n%s\n' "$result" >"$feedback_file"; return; }
  "$PY" -c 'import json,sys
r=json.loads(sys.argv[1]); sbs=r.pop("side_by_side",[])
print("Measured: "+json.dumps(r))
if sbs: print("Original | compiled around divergences (! = differs):"); print("\n".join(sbs))' "$result" >"$feedback_file"
  json_get "$result" pct
}

promote_and_commit() { # func vram size pct attempts seconds
  local func="$1" vram="$2" size="$3" pct="$4" attempts="$5" seconds="$6" offset
  offset=$(( vram - 0x100000 + 0x1E0 ))
  $PIPELINE promote --func "$func" --module kcet --source "staging/${func}.cpp" \
    --header "${func}.h" --vram "$vram" --offset "$offset" --size "$size"
  commit_promotion "$func" "$vram" "$size" "$pct" "$attempts" "$seconds" "$CURRENT_WAVE" "$AGENT" "${RALPH_MODEL:-default}"
}

# Commits one promoted slice with a generated message, then publishes it when RALPH_PUSH=1.
commit_promotion() { # func vram size pct attempts seconds wave agent model
  local func="$1" vram="$2" size="$3" message
  git add -- "src/kcet/${func}.cpp" config/SLES-50282/config.yml config/SLES-50282/symbols.txt configure.py
  message="$($SLICE commit-message --func "$func" --vram "$vram" --size "$size" --pct "$4" --attempts "$5" \
    --seconds "$6" --wave "$7" --agent "$8" --model "$9")"
  git commit -q -F - <<<"$message"
  publish_commits || log "push failed; commits stay local until the next publish"
}

# Syncs with origin (fetch + rebase) and pushes to RALPH_BRANCH. Returns 1 and leaves the repo clean when it cannot.
publish_commits() {
  [[ "$RALPH_PUSH" == "1" ]] || return 0
  git fetch -q origin || return 1
  if ! git rebase -q "origin/$RALPH_BRANCH"; then
    git rebase --abort 2>/dev/null || true
    log "rebase onto origin/$RALPH_BRANCH failed; not pushing"
    return 1
  fi
  git push -q origin "HEAD:$RALPH_BRANCH"
}

# Replaces the agent's edits outside staging/ and build/; logs what it undid.
guard_check() { # snapshot_file label
  local report
  report="$($SLICE guard verify --file "$1" --restore)" || { log "guard verify failed"; return; }
  [[ "$report" == *'"changed": []'* && "$report" == *'"stray": []'* ]] || log "$2 guard restored agent edits: $report"
}

unmatchable_reason() { # agent_log -> prints reason when the last line is UNMATCHABLE
  local last
  last="$(grep -v '^[[:space:]]*$' "$1" | tail -n 1 || true)"
  [[ "$last" =~ ^UNMATCHABLE:[[:space:]]*(.+)$ ]] && printf '%s' "${BASH_REMATCH[1]}"
  return 0
}

failure_class() { # agent_log -> none|quota|model_config|transient
  json_get "$($SLICE classify-failure --log "$1")" class
}

# Environment failures are not slice failures: stop without recording the slice. Exits 3.
stop_on_agent_failure() { # func class agent_log
  local cause
  case "$2" in
    quota) cause="quota/créditos esgotados" ;;
    model_config) cause="modelo/opções inválidos" ;;
    *) cause="modelo indisponível após $RALPH_UNAVAILABLE_RETRIES tentativas" ;;
  esac
  printf '\n[ralph] PARADO: o agente %s falhou em %s (%s): %s.\n' "$AGENT" "$1" "$2" "$cause" >&2
  printf '[ralph] Nenhum resultado foi gravado para este slice; o estado salvo continua válido.\n' >&2
  printf '[ralph] Log do agente: %s\n' "$3" >&2
  printf '[ralph] Corrija a causa (créditos, RALPH_MODEL ou AGENT) e rode scripts/ralph_decomp.sh de novo.\n' >&2
  exit 3
}

# Background job for one slice: one agent call with transient retries and optional quota wait.
# Exit 0: usable log. Exit 3: environment failure (stops the wave). Writes failures.txt and seconds in the attempt dir.
run_agent_job() { # func prompt_file attempt_dir
  local func="$1" prompt="$2" dir="$3" log_file class tries=0 backoff="$RALPH_UNAVAILABLE_BACKOFF" started=$SECONDS
  log_file="$dir/agent.log"
  while true; do
    invoke_agent "$prompt" "$log_file" || log "$func agent exited non-zero (see agent.log)"
    class="$(failure_class "$log_file")"
    [[ "$class" == "none" ]] && break
    printf '%s\n' "$class" >>"$dir/failures.txt"
    case "$class" in
      transient)
        tries=$(( tries + 1 ))
        (( tries <= RALPH_UNAVAILABLE_RETRIES )) || stop_on_agent_failure "$func" "$class" "$log_file"
        log "$func model temporarily unavailable; retry $tries/$RALPH_UNAVAILABLE_RETRIES in ${backoff}s"
        sleep "$backoff"
        backoff=$(( backoff * 2 )) ;;
      quota)
        (( RALPH_WAIT_ON_QUOTA > 0 )) || stop_on_agent_failure "$func" "$class" "$log_file"
        log "$func quota exhausted; waiting ${RALPH_WAIT_ON_QUOTA}s before retrying"
        sleep "$RALPH_WAIT_ON_QUOTA" ;;
      *) stop_on_agent_failure "$func" "$class" "$log_file" ;;
    esac
  done
  printf '%s\n' $(( SECONDS - started )) >"$dir/seconds"
}

mark_asm() { # func vram size reason
  $SLICE mark --state "$STATE" --func "$1" --vram "$2" --size "$3" --status asm --reason "$4" >/dev/null
  log "$1 marked asm: $4"
}

# Records the final status of a slice (after its last recorded attempt).
finish_slice() { # func vram size pct status hints attempts seconds
  local func="$1" vram="$2" size="$3" pct="$4" status="$5" hints="$6" attempts="$7" seconds="$8" final="$5"
  if [[ "$status" == "done" ]]; then
    promote_and_commit "$func" "$vram" "$size" "$pct" "$attempts" "$seconds"; log "$func promoted"
  elif [[ "$status" == "partial" ]]; then
    log "$func partial (${pct}%), kept in staging, advancing"
  elif [[ -n "$hints" && "$RALPH_ASM_POLICY" == "once" ]]; then
    mark_asm "$func" "$vram" "$size" "hints: $hints; best ${pct}% in 1 attempt"; final="asm"
  else
    log "$func blocked (${pct}%), skipping; revisited later (max $RALPH_MAX_PASSES passes)"
  fi
  emit slice_final func="$func" vram="$vram" size="$size" status="$final" pct="$pct" attempts="$attempts" seconds="$seconds"
}

# Tab-separated lines for one wave: ITEM func vram size likely_asm hints | ASM func.
wave_lines() { # batch_json
  "$PY" -c 'import json,sys
d = json.loads(sys.argv[1])
for it in d.get("items", []):
    print("\t".join(["ITEM", it["func"], "0x%X" % it["vram"], "0x%X" % it["size"],
                     "1" if it.get("likely_asm") else "0", " ".join(it.get("hints", []))]))
for func in d.get("marked_asm", []):
    print("ASM\t" + func)' "$1"
}

# Runs one wave of slices. Agents run in parallel in background jobs; measuring, recording,
# promoting and metrics run one slice at a time once no agent is active. Sets WAVE_SIZE.
run_wave() { # batch_json wave_no
  local batch="$1" wave_no="$2" wave_started=$SECONDS kind a b c d e index limit n=0 status=0
  CURRENT_WAVE="$wave_no"
  local -a funcs=() vrams=() sizes=() hints=() limits=() attempts=() seconds=() active=() jobs=() next=()
  local dir feedback prompt pct record seconds_now reason status_now entry pid func vram size cls
  while IFS=$'\t' read -r kind a b c d e; do
    case "$kind" in
      ASM) log "$a marked asm: no function end" ;;
      ITEM)
        [[ "$d" == "1" ]] || e=""
        if [[ "$d" == "1" && "$RALPH_ASM_POLICY" == "skip" ]]; then
          mark_asm "$a" "$b" "$c" "hints: $e"; continue
        fi
        limit="$RALPH_MAX_ATTEMPTS"
        [[ "$d" == "1" && "$RALPH_ASM_POLICY" == "once" ]] && limit=1
        $PIPELINE stage --func "$a" --vram "$b" --size "$c" >/dev/null
        funcs+=("$a"); vrams+=("$b"); sizes+=("$c"); hints+=("$e"); limits+=("$limit")
        attempts+=(0); seconds+=(0); n=$(( n + 1 )) ;;
    esac
  done < <(wave_lines "$batch")
  WAVE_SIZE=$n
  (( n > 0 )) || return 0
  for (( index = 0; index < n; index++ )); do active+=("$index"); done
  if [[ "$RALPH_DRY_RUN" == "1" ]]; then
    for index in "${active[@]}"; do
      dir="$RALPH_DIR/${funcs[index]}/attempt-1"; mkdir -p "$dir"
      build_prompt "${funcs[index]}" "${vrams[index]}" "${sizes[index]}" /dev/null "${hints[index]}" >"$dir/prompt.md"
      log "dry run: ${funcs[index]} ${vrams[index]} ${sizes[index]} hints=[${hints[index]}] -> $dir/prompt.md"
    done
    return 0
  fi
  local round=0
  while (( ${#active[@]} > 0 )); do
    round=$(( round + 1 )); jobs=()
    $SLICE guard snapshot --file "$RALPH_DIR/guard.json" >/dev/null
    for index in "${active[@]}"; do
      func="${funcs[index]}"
      attempts[index]=$(( attempts[index] + 1 ))
      dir="$RALPH_DIR/$func/attempt-${attempts[index]}"; mkdir -p "$dir"
      feedback="$RALPH_DIR/$func/feedback.txt"; touch "$feedback"
      prompt="$dir/prompt.md"
      build_prompt "$func" "${vrams[index]}" "${sizes[index]}" "$feedback" "${hints[index]}" >"$prompt"
      log "$func attempt ${attempts[index]}/${limits[index]} via $AGENT (wave $wave_no, slot $index)"
      run_agent_job "$func" "$prompt" "$dir" &
      jobs+=("$!:$index")
    done
    for entry in "${jobs[@]}"; do
      pid="${entry%%:*}"
      wait "$pid" || status=$?
    done
    guard_check "$RALPH_DIR/guard.json" "wave $wave_no round $round"
    for index in "${active[@]}"; do
      dir="$RALPH_DIR/${funcs[index]}/attempt-${attempts[index]}"
      [[ -f "$dir/failures.txt" ]] || continue
      while read -r cls; do
        emit agent_failure func="${funcs[index]}" class="$cls" attempt="${attempts[index]}" agent="$AGENT" \
          model="${RALPH_MODEL:-default}" wave="$wave_no"
      done <"$dir/failures.txt"
    done
    if (( status != 0 )); then
      log "wave $wave_no stopped by an environment failure; this round is not recorded"
      exit "$status"
    fi
    next=()
    for index in "${active[@]}"; do
      func="${funcs[index]}"; vram="${vrams[index]}"; size="${sizes[index]}"
      dir="$RALPH_DIR/$func/attempt-${attempts[index]}"; feedback="$RALPH_DIR/$func/feedback.txt"
      seconds_now="$(cat "$dir/seconds" 2>/dev/null || echo 0)"
      seconds[index]=$(( seconds[index] + seconds_now ))
      reason="$(unmatchable_reason "$dir/agent.log")"
      if [[ -n "$reason" ]]; then
        mark_asm "$func" "$vram" "$size" "$reason"
        emit slice_final func="$func" vram="$vram" size="$size" status=asm pct=0 attempts="${attempts[index]}" seconds="${seconds[index]}"
        continue
      fi
      pct="$(measure_attempt "$func" "$vram" "$size" "$feedback")"
      cp "$feedback" "$dir/diff.txt"
      log "$func similarity ${pct}% (${seconds_now}s)"
      record="$($SLICE record --state "$STATE" --func "$func" --vram "$vram" --size "$size" --pct "$pct" \
        --attempts "${attempts[index]}" --min-pct "$RALPH_MIN_PCT" --max-attempts "${limits[index]}" \
        --seconds "$seconds_now" --stall "$RALPH_STALL")"
      status_now="$(json_get "$record" status)"
      emit attempt func="$func" vram="$vram" size="$size" attempt="${attempts[index]}" agent="$AGENT" \
        model="${RALPH_MODEL:-default}" pct="$pct" seconds="$seconds_now" outcome="$status_now" \
        wave="$wave_no" slot="$index"
      if [[ "$status_now" == "retry" ]]; then
        next+=("$index")
      else
        finish_slice "$func" "$vram" "$size" "$pct" "$status_now" "${hints[index]}" "${attempts[index]}" "${seconds[index]}"
      fi
    done
    active=(${next[@]+"${next[@]}"})
  done
  emit wave index="$wave_no" size="$n" wall_seconds="$(( SECONDS - wave_started ))" parallel="$RALPH_PARALLEL"
}

print_summary() {
  "$PY" -c 'import json,sys; s=json.loads(sys.argv[1]); t=s["total_bytes"] or 1
pct=lambda b: 100.0*b/t
print("[ralph] progress: C/C++ real {:.2f}% ({} bytes) | asm {:.2f}% | partial {:.2f}% | blocked {:.2f}% | covered {:.2f}% counts={} time={:.0f}s eta={}".format(
  pct(s["cpp_bytes"]), s["cpp_bytes"], pct(s["asm_bytes"]), pct(s["partial_bytes"]), pct(s["blocked_bytes"]),
  pct(s["covered_bytes"]), s["counts"], s["total_seconds"],
  "n/a" if s["eta_seconds"] is None else "{:.0f}s".format(s["eta_seconds"])))' "$($SLICE summary --state "$STATE")"
}

snapshot_metrics() {
  $METRICS snapshot --state "$STATE" --events "$EVENTS" >/dev/null 2>&1 || log "metrics: could not record snapshot"
}

main() {
  preflight
  acquire_lock
  mkdir -p "$(dirname "$EVENTS")"
  local processed=0 wave_no=0 before batch kind
  $METRICS backfill --state "$STATE" --events "$EVENTS" >/dev/null 2>&1 || log "metrics: backfill skipped"
  while true; do
    batch="$($SLICE batch --state "$STATE" --count "$RALPH_PARALLEL" --max-slice "$RALPH_MAX_SLICE" --max-passes "$RALPH_MAX_PASSES")"
    kind="$(json_get "$batch" kind)"
    if [[ "$kind" == "done" ]]; then
      log "no work left. unresolved after $RALPH_MAX_PASSES passes: $(json_get "$batch" unresolved)"
      print_summary; snapshot_metrics; break
    fi
    wave_no=$(( wave_no + 1 ))
    before=$processed
    run_wave "$batch" "$wave_no"
    [[ "$RALPH_DRY_RUN" == "1" ]] && break
    processed=$(( processed + WAVE_SIZE ))
    if (( RALPH_SUMMARY_EVERY > 0 && processed / RALPH_SUMMARY_EVERY > before / RALPH_SUMMARY_EVERY )); then
      print_summary; snapshot_metrics
    fi
  done
}

[[ "${RALPH_LIB_ONLY:-0}" == "1" ]] || main "$@"
