"""Static helpers for scripts/ralph_decomp.sh: automatic slicing, loop state, measurement.

Everything here is deterministic. Only code generation is left to the AI agent.
"""

from __future__ import annotations

import argparse
import bisect
import functools
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Tuple

PROJECT_ROOT = Path(__file__).resolve().parents[1]
SYMBOLS_TXT = PROJECT_ROOT / "config/SLES-50282/symbols.txt"
TEXT_START = 0x100000
TEXT_END = 0x4E2FE0
DEFAULT_MAX_SLICE = 0x800
DEFAULT_MIN_PCT = 90.0
DEFAULT_MAX_ATTEMPTS = 5
DEFAULT_MAX_PASSES = 3
HARD_MAX_SLICE = 0x4000
VALID_MARK_STATUSES = {"asm"}
STRONG_HINTS = {"syscall", "cop0"}
UNDECODABLE_FRACTION = 0.25
SIDE_BY_SIDE_MAX_LINES = 60
GUARDED_PATHS = ("scripts", "tests", "configure.py", "config", "src", "include")
GUARD_IGNORED_TOP_LEVEL = ("staging", "build")

NOP = 0x00000000
JR_RA = 0x03E00008
BRANCH_OPCODES = {0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
COP1_OPCODE = 0x11
COP1_BRANCH_RS = 0x08
J_OPCODE = 0x02
SYMBOL_PATTERN = re.compile(
    r"^\S+\s*=\s*(0x[0-9A-Fa-f]+);\s*//\s*(?=.*\btype:func\b)(?=.*\bsize:(0x[0-9A-Fa-f]+|\d+))"
)


QUOTA_MARKERS = (
    "RESOURCE_EXHAUSTED",            # provider quota used up
    "credits balance is too low",    # account credits used up
)
MODEL_CONFIG_MARKERS = (
    "invalid model selection",       # agent CLI rejects its model/effort config
)
TRANSIENT_PATTERN = re.compile(r"\bmodel\b[^\n]*\bis not recognized\b")  # intermittent; retried with backoff
ENVIRONMENT_CLASSES = ("quota", "model_config", "transient")
NO_END_REASON = "no function end"


def classify_agent_failure(agent_log: str) -> str:
    """'quota', 'model_config', 'transient' for environment failures, else 'none'. Quota wins over the rest."""
    if any(marker in agent_log for marker in QUOTA_MARKERS):
        return "quota"
    if any(marker in agent_log for marker in MODEL_CONFIG_MARKERS):
        return "model_config"
    if TRANSIENT_PATTERN.search(agent_log):
        return "transient"
    return "none"


def is_agent_unavailable(agent_log: str) -> bool:
    """True when an agent log shows a failure that must stop the loop (quota or bad model config)."""
    return classify_agent_failure(agent_log) in ("quota", "model_config")


class SliceBoundaryError(ValueError):
    """No function end (jr ra + delay slot) found within the available code."""


@dataclass(frozen=True)
class Slice:
    func: str
    vram: int
    size: int


def _word(code: bytes, offset: int) -> int:
    return struct.unpack_from("<I", code, offset)[0]


def _is_branch(instruction: int) -> bool:
    opcode = instruction >> 26
    if opcode in BRANCH_OPCODES:
        return True
    return opcode == COP1_OPCODE and ((instruction >> 21) & 0x1F) == COP1_BRANCH_RS


def _branch_target(offset: int, instruction: int) -> int:
    immediate = instruction & 0xFFFF
    signed = immediate - 0x10000 if immediate & 0x8000 else immediate
    return offset + 4 + signed * 4


def _is_tail_call(instruction: int, pc: int, function_vram: int) -> bool:
    """True for an unconditional ``j`` to code before the function (a tail call exit)."""
    if instruction >> 26 != J_OPCODE:
        return False
    target = ((pc + 4) & 0xF0000000) | ((instruction & 0x3FFFFFF) << 2)
    return target < function_vram


def find_function_size(code: bytes, start: int, max_size: int, base: int = 0) -> int:
    """Return the byte size of the function at ``start`` (through jr ra or a tail call + delay slot).

    ``base`` is the VRAM address of ``code[0]``; it decides whether a ``j`` leaves the function.
    Raises SliceBoundaryError when no return is found within the buffer or cap.
    """
    limit = min(len(code), start + max_size)
    function_vram = base + start
    farthest_target = start
    last_return_end: Optional[int] = None
    offset = start
    while offset + 4 <= limit:
        instruction = _word(code, offset)
        if _is_branch(instruction):
            farthest_target = max(farthest_target, _branch_target(offset, instruction))
        if instruction == JR_RA or _is_tail_call(instruction, base + offset, function_vram):
            end = offset + 8
            if end > len(code):
                break
            last_return_end = end
            if end > farthest_target:
                return end - start
        offset += 4
    if last_return_end is not None and offset >= start + max_size:
        return last_return_end - start
    raise SliceBoundaryError(f"no function end within 0x{limit - start:X} bytes at offset 0x{start:X}")


def parse_covered(symbols_text: str) -> List[Tuple[int, int]]:
    """Intervals of functions with a known size in symbols.txt."""
    covered = []
    for line in symbols_text.splitlines():
        match = SYMBOL_PATTERN.match(line.strip())
        if match:
            start = int(match.group(1), 16)
            covered.append((start, start + int(match.group(2), 0)))
    return sorted(covered)


class CoveredIndex:
    """Merged, sorted address intervals with O(log n) containment queries."""

    def __init__(self, intervals: List[Tuple[int, int]]):
        merged: List[List[int]] = []
        for begin, stop in sorted(intervals):
            if merged and begin <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], stop)
                continue
            merged.append([begin, stop])
        self._begins = [begin for begin, _ in merged]
        self._stops = [stop for _, stop in merged]

    def end_of_containing(self, address: int) -> Optional[int]:
        """End of the merged interval containing ``address``, or None."""
        position = bisect.bisect_right(self._begins, address) - 1
        if position >= 0 and address < self._stops[position]:
            return self._stops[position]
        return None

    def next_begin_after(self, address: int) -> Optional[int]:
        """Smallest interval start strictly greater than ``address``, or None."""
        position = bisect.bisect_right(self._begins, address)
        return self._begins[position] if position < len(self._begins) else None


def _skip_covered_and_padding(code: bytes, base: int, covered: List[Tuple[int, int]]) -> Optional[int]:
    index = covered if isinstance(covered, CoveredIndex) else CoveredIndex(covered)
    address = base
    end = base + len(code)
    while address + 4 <= end:
        stop = index.end_of_containing(address)
        if stop is not None:
            address = stop
        elif _word(code, address - base) == NOP:
            address += 4
        else:
            return address
    return None


def next_slice(
    code: bytes, base: int, covered: List[Tuple[int, int]], max_size: int = DEFAULT_MAX_SLICE
) -> Optional[Slice]:
    """First uncovered function in ``code`` (loaded at ``base``), or None when done."""
    index = covered if isinstance(covered, CoveredIndex) else CoveredIndex(covered)
    address = _skip_covered_and_padding(code, base, index)
    if address is None:
        return None
    following = index.next_begin_after(address)
    room = HARD_MAX_SLICE if following is None else min(HARD_MAX_SLICE, following - address)
    size = _size_with_growing_cap(code, address - base, max_size, room, base)
    return Slice(func=f"func_{address:08X}", vram=address, size=size)


def _size_with_growing_cap(code: bytes, start: int, cap: int, room: int, base: int) -> int:
    """Function size, doubling the cap (up to ``room``) while no return is found."""
    cap = min(cap, room)
    while True:
        try:
            return find_function_size(code, start, cap, base)
        except SliceBoundaryError:
            if cap >= room:
                raise
            cap = min(cap * 2, room)


@dataclass(frozen=True)
class Unbounded:
    """A region where no function end was found; the loop records it as asm."""

    vram: int
    size: int


def select_new_slices(
    code: bytes, base: int, intervals: List[Tuple[int, int]], count: int, max_slice: int
) -> Tuple[List[Slice], List[Unbounded]]:
    """Up to ``count`` uncovered functions plus the regions no function end could bound.

    Chosen and unbounded spans count as covered for the next pick, so results never overlap.
    """
    chosen: List[Slice] = []
    unbounded: List[Unbounded] = []
    extra: List[Tuple[int, int]] = []
    while len(chosen) < count:
        index = CoveredIndex(list(intervals) + extra)
        address = _skip_covered_and_padding(code, base, index)
        if address is None:
            break
        following = index.next_begin_after(address)
        room = HARD_MAX_SLICE if following is None else min(HARD_MAX_SLICE, following - address)
        try:
            size = _size_with_growing_cap(code, address - base, max_slice, room, base)
        except SliceBoundaryError:
            unbounded.append(Unbounded(vram=address, size=room))
            extra.append((address, address + room))
            continue
        chosen.append(Slice(func=f"func_{address:08X}", vram=address, size=size))
        extra.append((address, address + size))
    return chosen, unbounded


def choose_batch(
    state: "LoopState", code: bytes, base: int, symbol_intervals: List[Tuple[int, int]],
    count: int, max_slice: int, max_passes: int,
) -> dict:
    """Up to ``count`` distinct work items: new slices first, then revisits. Unbounded regions become asm."""
    chosen, unbounded = select_new_slices(code, base, symbol_intervals + state.covered(), count, max_slice)
    marked = []
    for region in unbounded:
        func = f"func_{region.vram:08X}"
        state.mark(func, region.vram, region.size, "asm", NO_END_REASON)
        marked.append(func)
    items = [_new_item(found, code[found.vram - base : found.vram - base + found.size]) for found in chosen]
    for entry in state.pending(max_passes):
        if len(items) >= count:
            break
        state.touch(entry["func"])
        items.append({"kind": "revisit", "func": entry["func"], "vram": entry["vram"], "size": entry["size"],
                      "hints": [], "likely_asm": False})
    if not items:
        return {"kind": "done", "unresolved": _unresolved_summary(state, max_passes)}
    return {"kind": "batch", "items": items, "marked_asm": marked}


def _unresolved_summary(state: "LoopState", max_passes: int) -> List[dict]:
    return [{"func": e["func"], "status": e["status"], "pct": e["pct"]} for e in state.unresolved(max_passes)]


def _new_item(found: Slice, slice_bytes: bytes) -> dict:
    return slice_reply(found, slice_bytes)


def classify_code(words: List[int]) -> List[str]:
    """Names of non-C instruction families found in ``words`` (sorted, de-duplicated)."""
    hints = set()
    for word in words:
        hints.update(_instruction_hints(word))
    if _undecodable_fraction(words) >= UNDECODABLE_FRACTION:
        hints.add("undecodable")
    return sorted(hints)


def _instruction_hints(word: int) -> List[str]:
    opcode, funct = word >> 26, word & 0x3F
    if opcode == 0x10:
        return ["cop0"]
    if opcode == 0x1C:
        return ["mmi"]
    if opcode in (0x1E, 0x1F):
        return ["lq_sq"]
    if opcode == 0x2F:
        return ["cache"]
    if opcode != 0:
        return []
    return {0x0C: ["syscall"], 0x0F: ["sync"]}.get(funct) or _break_hint(word, funct)


def _break_hint(word: int, funct: int) -> List[str]:
    divide_by_zero_codes = (6, 7)  # emitted by divbyzerocheck: plain C
    if funct != 0x0D or ((word >> 6) & 0x3FF) in divide_by_zero_codes:
        return []
    return ["break"]


def _undecodable_fraction(words: List[int]) -> float:
    if not words:
        return 0.0
    from capstone import CS_ARCH_MIPS, CS_MODE_LITTLE_ENDIAN, CS_MODE_MIPS64, Cs

    disassembler = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)
    failures = sum(1 for word in words if not list(disassembler.disasm(struct.pack("<I", word), 0)))
    return failures / len(words)


def is_likely_asm(hints: List[str]) -> bool:
    """True when a hint is strong enough to suggest hand-written assembly."""
    return any(hint in STRONG_HINTS for hint in hints)


class LoopState:
    """Resumable loop state, written atomically."""

    STATUS_RANK = {"retry": 0, "partial": 1, "blocked": 2}

    def __init__(self, path: Path):
        self.path = Path(path)
        self.data: Dict[str, Dict[str, dict]] = {"slices": {}}
        if self.path.is_file():
            self.data = json.loads(self.path.read_text())

    def record(
        self,
        func: str,
        vram: int,
        size: int,
        pct: float,
        attempts: int,
        min_pct: float,
        max_attempts: int,
        seconds: float = 0.0,
        stall: int = 0,
    ) -> str:
        """Store one measured attempt and return the resulting status."""
        entry = self._entry(func, vram, size)
        entry["history"].append({"pct": pct, "seconds": seconds, "timestamp": time.time()})
        entry.update(pct=pct, attempts=attempts)
        entry["status"] = self._status_after(entry, min_pct, max_attempts, stall)
        self._save()
        return entry["status"]

    def mark(self, func: str, vram: int, size: int, status: str, reason: str) -> None:
        """Force a terminal status (for example ``asm``) with a human-readable reason."""
        if status not in VALID_MARK_STATUSES:
            raise ValueError(f"unsupported status {status!r}; expected one of {sorted(VALID_MARK_STATUSES)}")
        entry = self._entry(func, vram, size)
        entry.update(status=status, reason=reason)
        self._save()

    def touch(self, func: str) -> None:
        """Count a revisit of ``func`` so equal-rank entries rotate instead of starving."""
        entry = self.data["slices"][func]
        self.data["counter"] = self.data.get("counter", 0) + 1
        entry["passes"] = entry.get("passes", 0) + 1
        entry["last_pass"] = self.data["counter"]
        self._save()

    def is_stalled(self, func: str, window: int) -> bool:
        """True when the last ``window`` attempts all failed to beat the best earlier result."""
        history = self.data["slices"].get(func, {}).get("history", [])
        if window <= 0 or len(history) <= window:
            return False
        best_before = max(item["pct"] for item in history[:-window])
        return all(item["pct"] <= best_before for item in history[-window:])

    def _entry(self, func: str, vram: int, size: int) -> dict:
        entry = self.data["slices"].setdefault(func, {"func": func})
        entry.update(vram=vram, size=size)
        entry.setdefault("history", [])
        entry.setdefault("passes", 0)
        entry.setdefault("last_pass", 0)
        entry.pop("reason", None)
        return entry

    def _status_after(self, entry: dict, min_pct: float, max_attempts: int, stall: int) -> str:
        status = self._classify(entry["pct"], entry["attempts"], min_pct, max_attempts)
        if status == "retry" and self.is_stalled(entry["func"], stall):
            return "blocked"
        return status

    @staticmethod
    def _classify(pct: float, attempts: int, min_pct: float, max_attempts: int) -> str:
        if pct >= 100.0:
            return "done"
        if pct >= min_pct:
            return "partial"
        return "blocked" if attempts >= max_attempts else "retry"

    def status(self, func: str) -> Optional[str]:
        entry = self.data["slices"].get(func)
        return entry["status"] if entry else None

    def pending(self, max_passes: Optional[int] = None) -> List[dict]:
        """Entries still worth revisiting, least-visited first within the same status."""
        entries = [e for e in self._open_entries() if max_passes is None or e.get("passes", 0) < max_passes]
        return sorted(entries, key=self._revisit_key)

    def unresolved(self, max_passes: int) -> List[dict]:
        """Open entries that used up their revisits."""
        return sorted((e for e in self._open_entries() if e.get("passes", 0) >= max_passes), key=self._revisit_key)

    def _open_entries(self) -> List[dict]:
        return [e for e in self.data["slices"].values() if e["status"] in self.STATUS_RANK]

    def _revisit_key(self, entry: dict) -> tuple:
        return (self.STATUS_RANK[entry["status"]], entry.get("passes", 0), entry.get("last_pass", 0), entry["vram"])

    def covered(self) -> List[Tuple[int, int]]:
        return sorted((e["vram"], e["vram"] + e["size"]) for e in self.data["slices"].values())

    def remove(self, func: str) -> None:
        """Forget ``func`` entirely so it is selected as new work again."""
        self.data["slices"].pop(func, None)
        self._save()

    def _save(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        temporary = self.path.with_suffix(".json.tmp")
        temporary.write_text(json.dumps(self.data, indent=2, sort_keys=True))
        os.replace(temporary, self.path)


def summarize(state: LoopState, symbols_text: str, text_start: int, text_end: int) -> dict:
    """Progress report: bytes per status, time spent and a naive ETA. ``cpp_bytes`` counts only ``done``."""
    entries = list(state.data["slices"].values())
    finished = [e for e in entries if e["status"] in ("done", "asm")]
    covered = _merged_length(parse_covered(symbols_text) + [(e["vram"], e["vram"] + e["size"]) for e in finished])
    counts: Dict[str, int] = {}
    for entry in entries:
        counts[entry["status"]] = counts.get(entry["status"], 0) + 1
    total_seconds = sum(item["seconds"] for e in entries for item in e.get("history", []))
    timed = [e for e in entries if e.get("history")]
    return {
        "total_bytes": text_end - text_start,
        "covered_bytes": covered,
        "cpp_bytes": _status_bytes(entries, "done"),
        "asm_bytes": _status_bytes(entries, "asm"),
        "partial_bytes": _status_bytes(entries, "partial"),
        "blocked_bytes": _status_bytes(entries, "blocked"),
        "counts": counts,
        "total_seconds": total_seconds,
        "average_seconds_per_slice": total_seconds / len(timed) if timed else 0.0,
        "eta_seconds": _eta(finished, text_end - text_start - covered),
        "asm": [{"func": e["func"], "reason": e.get("reason", "")} for e in entries if e["status"] == "asm"],
    }


def _status_bytes(entries: List[dict], status: str) -> int:
    return _merged_length([(e["vram"], e["vram"] + e["size"]) for e in entries if e["status"] == status])


def requeue_unavailable(state_path: Path, dry_run: bool = False) -> dict:
    """Drop blocked slices whose attempt logs show only environment failures, so the loop retries them.

    Writes ``state.json.bak-<timestamp>`` before changing anything; nothing is written when nothing changes.
    """
    state_path = Path(state_path)
    state = LoopState(state_path)
    root = state_path.parent
    requeued = sorted(func for func, entry in state.data["slices"].items()
                      if _only_environment_failures(root, func, entry))
    if not requeued or dry_run:
        return {"requeued": requeued, "backup": None}
    backup = _backup_path(state_path)
    shutil.copy2(state_path, backup)
    for func in requeued:
        state.remove(func)
    return {"requeued": requeued, "backup": str(backup)}


def _only_environment_failures(root: Path, func: str, entry: dict) -> bool:
    if entry.get("status") != "blocked":
        return False
    logs = sorted((root / func).glob("attempt-*/agent.log"))
    return bool(logs) and all(
        classify_agent_failure(path.read_text(errors="ignore")) in ENVIRONMENT_CLASSES for path in logs)


def _backup_path(state_path: Path) -> Path:
    stamp = time.strftime("%Y%m%d-%H%M%S")
    candidate = state_path.with_name(f"{state_path.name}.bak-{stamp}")
    counter = 2
    while candidate.exists():
        candidate = state_path.with_name(f"{state_path.name}.bak-{stamp}-{counter}")
        counter += 1
    return candidate


def _merged_length(intervals: List[Tuple[int, int]]) -> int:
    index = CoveredIndex(intervals)
    return sum(stop - begin for begin, stop in zip(index._begins, index._stops))


def _eta(finished: List[dict], remaining_bytes: int) -> Optional[float]:
    seconds = sum(item["seconds"] for e in finished for item in e.get("history", []))
    size = sum(e["size"] for e in finished)
    if seconds <= 0 or size <= 0:
        return None
    return remaining_bytes * seconds / size


def _disassembler():
    from capstone import CS_ARCH_MIPS, CS_MODE_LITTLE_ENDIAN, CS_MODE_MIPS64, Cs

    return Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)


def _disassemble_word(disassembler, raw: bytes, address: int) -> str:
    decoded = next(disassembler.disasm(raw, address), None)
    return f"{decoded.mnemonic} {decoded.op_str}" if decoded else ".word"


def side_by_side(
    original: bytes,
    compiled: bytes,
    mismatches: List[dict],
    vram: int,
    context: int = 2,
    max_lines: int = SIDE_BY_SIDE_MAX_LINES,
) -> List[str]:
    """Original vs. compiled disassembly around the divergent words (``!`` marks them)."""
    patched = bytearray(compiled)
    for item in mismatches:
        patched[item["offset"] : item["offset"] + 4] = bytes.fromhex(item["compiled"])
    diverging = {item["offset"] for item in mismatches}
    if len(patched) < len(original):
        diverging.update(range(len(patched) - len(patched) % 4, len(original), 4))
    shown = _context_offsets(diverging, len(original), context)
    disassembler = _disassembler()
    lines = [_format_pair(disassembler, original, bytes(patched), offset, vram, offset in diverging)
             for offset in shown[:max_lines]]
    if len(shown) > max_lines:
        lines.append(f"... {len(shown) - max_lines} more lines omitted")
    return lines


def _context_offsets(diverging: set, length: int, context: int) -> List[int]:
    wanted = set()
    for offset in diverging:
        first = max(0, offset - 4 * context)
        wanted.update(range(first, min(length, offset + 4 * context + 4), 4))
    return sorted(wanted)


def _format_pair(disassembler, original: bytes, compiled: bytes, offset: int, vram: int, differs: bool) -> str:
    address = vram + offset
    left = _disassemble_word(disassembler, original[offset : offset + 4], address)
    chunk = compiled[offset : offset + 4]
    right = _disassemble_word(disassembler, chunk, address) if len(chunk) == 4 else "<missing>"
    marker = "! " if differs else "  "
    return f"{marker}{address:08X}  {left:<32} | {right}"


def _guarded_files(root: Path) -> Dict[str, str]:
    hashes: Dict[str, str] = {}
    for name in GUARDED_PATHS:
        target = root / name
        candidates = [target] if target.is_file() else sorted(target.rglob("*")) if target.is_dir() else []
        for path in candidates:
            if path.is_file() and "__pycache__" not in path.parts and path.suffix != ".pyc":
                hashes[path.relative_to(root).as_posix()] = hashlib.sha1(path.read_bytes()).hexdigest()
    return hashes


def _git_lines(root: Path, *args: str) -> List[str]:
    done = subprocess.run(["git", "-C", str(root), *args], check=True, capture_output=True, text=True)
    return [line for line in done.stdout.splitlines() if line]


def _untracked(root: Path) -> List[str]:
    files = _git_lines(root, "ls-files", "--others", "--exclude-standard")
    return sorted(f for f in files if f.split("/")[0] not in GUARD_IGNORED_TOP_LEVEL and "__pycache__" not in f)


def _dirty_tracked(root: Path) -> List[str]:
    return sorted(line[3:] for line in _git_lines(root, "status", "--porcelain", "--untracked-files=no"))


def guard_snapshot(root: Path) -> dict:
    """Fingerprint of the files an agent must not touch, plus pre-existing strays and dirt."""
    return {"files": _guarded_files(Path(root)), "untracked": _untracked(Path(root)), "dirty": _dirty_tracked(Path(root))}


def guard_verify(root: Path, snapshot: dict, restore: bool = False) -> dict:
    """Report (and optionally undo) guarded-file edits and new stray files since ``snapshot``."""
    root = Path(root)
    now = _guarded_files(root)
    before = snapshot["files"]
    changed = sorted(path for path, digest in before.items() if now.get(path) != digest)
    stray = sorted(set(_untracked(root)) - set(snapshot["untracked"]))
    unrestorable = [path for path in changed if path in snapshot["dirty"]]
    if restore:
        _restore(root, [path for path in changed if path not in unrestorable], stray)
    return {"changed": changed, "stray": stray, "unrestorable": unrestorable}


def _restore(root: Path, changed: List[str], stray: List[str]) -> None:
    if changed:
        subprocess.run(["git", "-C", str(root), "checkout", "--", *changed], check=True, capture_output=True)
    for path in stray:
        (root / path).unlink()


@functools.lru_cache(maxsize=1)
def _load_text_section() -> bytes:
    """The original ``.text`` bytes, read from the ELF once per process."""
    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    return decomp_pipeline.get_original_bytes(TEXT_START, TEXT_END - TEXT_START)


def _emit(payload: dict) -> None:
    print(json.dumps(payload))


def slice_reply(found: Slice, code: bytes) -> dict:
    """JSON payload for a new slice, with non-C hints computed from its own bytes."""
    count = found.size // 4
    hints = classify_code(list(struct.unpack_from(f"<{count}I", code, 0)))
    return {"kind": "new", "func": found.func, "vram": found.vram, "size": found.size,
            "hints": hints, "likely_asm": is_likely_asm(hints)}


def _command_next(args: argparse.Namespace) -> int:
    result = choose_batch(LoopState(args.state), _load_text_section(), TEXT_START,
                          parse_covered(SYMBOLS_TXT.read_text()), 1, args.max_slice, args.max_passes)
    _emit(result["items"][0] if result["kind"] == "batch" else result)
    return 0


def _command_batch(args: argparse.Namespace) -> int:
    _emit(choose_batch(LoopState(args.state), _load_text_section(), TEXT_START,
                       parse_covered(SYMBOLS_TXT.read_text()), args.count, args.max_slice, args.max_passes))
    return 0


def _command_requeue(args: argparse.Namespace) -> int:
    _emit(requeue_unavailable(args.state, dry_run=args.dry_run))
    return 0


def _command_classify_failure(args: argparse.Namespace) -> int:
    text = args.log.read_text(errors="ignore") if args.log.is_file() else ""
    _emit({"class": classify_agent_failure(text), "log": str(args.log)})
    return 0


def _command_record(args: argparse.Namespace) -> int:
    status = LoopState(args.state).record(
        args.func, args.vram, args.size, args.pct, args.attempts, args.min_pct, args.max_attempts,
        seconds=args.seconds, stall=args.stall,
    )
    _emit({"func": args.func, "status": status, "pct": args.pct})
    return 0


def _command_mark(args: argparse.Namespace) -> int:
    LoopState(args.state).mark(args.func, args.vram, args.size, args.status, args.reason)
    _emit({"func": args.func, "status": args.status})
    return 0


def _command_fatal_check(args: argparse.Namespace) -> int:
    log_text = args.log.read_text(errors="ignore") if args.log.is_file() else ""
    unavailable = is_agent_unavailable(log_text)
    _emit({"agent_unavailable": unavailable, "log": str(args.log)})
    return 0 if unavailable else 1


def _command_summary(args: argparse.Namespace) -> int:
    symbols = SYMBOLS_TXT.read_text() if SYMBOLS_TXT.is_file() else ""
    _emit(summarize(LoopState(args.state), symbols, TEXT_START, TEXT_END))
    return 0


def _command_guard(args: argparse.Namespace) -> int:
    if args.action == "snapshot":
        args.file.parent.mkdir(parents=True, exist_ok=True)
        args.file.write_text(json.dumps(guard_snapshot(args.root)))
        _emit({"snapshot": str(args.file)})
        return 0
    _emit(guard_verify(args.root, json.loads(args.file.read_text()), restore=args.restore))
    return 0


def _command_disasm(args: argparse.Namespace) -> int:
    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    data = decomp_pipeline.get_original_bytes(args.vram, args.size)
    disassembler = _disassembler()
    for offset in range(0, len(data), 4):
        raw = data[offset : offset + 4]
        text = _disassemble_word(disassembler, raw, args.vram + offset)
        print(f"{args.vram + offset:08X}:  {raw.hex()}  {text}")
    return 0


def _command_measure(args: argparse.Namespace) -> int:
    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    result = decomp_pipeline.diff_draft(args.func, args.vram, args.size, args.obj)
    original = decomp_pipeline.get_original_bytes(args.vram, args.size)
    compiled, _ = decomp_pipeline.extract_compiled_symbol_bytes(args.obj, args.func)
    _emit({"pct": result["match_percentage"], "is_match": result["is_match"],
           "actual_size": result["actual_size"], "mismatches": result["mismatches"][:10],
           "side_by_side": side_by_side(original, compiled, result["mismatches"], args.vram)})
    return 0


def _hex(value: str) -> int:
    return int(value, 0)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    nxt = sub.add_parser("next", help="Print the next slice as JSON")
    nxt.add_argument("--state", type=Path, required=True)
    nxt.add_argument("--max-slice", type=_hex, default=DEFAULT_MAX_SLICE)
    nxt.add_argument("--max-passes", type=int, default=DEFAULT_MAX_PASSES)
    nxt.set_defaults(handler=_command_next)
    batch = sub.add_parser("batch", help="Up to N distinct work items for one wave, as JSON")
    batch.add_argument("--state", type=Path, required=True)
    batch.add_argument("--count", type=int, required=True)
    batch.add_argument("--max-slice", type=_hex, default=DEFAULT_MAX_SLICE)
    batch.add_argument("--max-passes", type=int, default=DEFAULT_MAX_PASSES)
    batch.set_defaults(handler=_command_batch)
    requeue = sub.add_parser("requeue-unavailable", help="Retry blocked slices that only hit environment failures")
    requeue.add_argument("--state", type=Path, required=True)
    requeue.add_argument("--dry-run", action="store_true")
    requeue.set_defaults(handler=_command_requeue)
    classify = sub.add_parser("classify-failure", help="Print the failure class of an agent log")
    classify.add_argument("--log", type=Path, required=True)
    classify.set_defaults(handler=_command_classify_failure)
    rec = sub.add_parser("record", help="Record a measured result in the loop state")
    _add_slice_arguments(rec)
    rec.add_argument("--pct", type=float, required=True)
    rec.add_argument("--attempts", type=int, required=True)
    rec.add_argument("--min-pct", type=float, default=DEFAULT_MIN_PCT)
    rec.add_argument("--max-attempts", type=int, default=DEFAULT_MAX_ATTEMPTS)
    rec.add_argument("--seconds", type=float, default=0.0)
    rec.add_argument("--stall", type=int, default=0, help="Block after N attempts without improvement (0 = off)")
    rec.set_defaults(handler=_command_record)
    mark = sub.add_parser("mark", help="Force a terminal status such as asm")
    _add_slice_arguments(mark)
    mark.add_argument("--status", required=True, choices=sorted(VALID_MARK_STATUSES))
    mark.add_argument("--reason", required=True)
    mark.set_defaults(handler=_command_mark)
    summary = sub.add_parser("summary", help="Progress report as JSON")
    summary.add_argument("--state", type=Path, required=True)
    summary.set_defaults(handler=_command_summary)
    guard = sub.add_parser("guard", help="Detect or undo edits outside the allowed files")
    guard.add_argument("action", choices=["snapshot", "verify"])
    guard.add_argument("--root", type=Path, default=PROJECT_ROOT)
    guard.add_argument("--file", type=Path, required=True)
    guard.add_argument("--restore", action="store_true")
    guard.set_defaults(handler=_command_guard)
    fatal = sub.add_parser("fatal-check", help="Exit 0 when an agent log reports an environment failure")
    fatal.add_argument("--log", type=Path, required=True)
    fatal.set_defaults(handler=_command_fatal_check)
    dis = sub.add_parser("disasm", help="Disassemble original bytes")
    dis.add_argument("--vram", type=_hex, required=True)
    dis.add_argument("--size", type=_hex, required=True)
    dis.set_defaults(handler=_command_disasm)
    mea = sub.add_parser("measure", help="Similarity of a compiled object vs. the original")
    mea.add_argument("--func", required=True)
    mea.add_argument("--vram", type=_hex, required=True)
    mea.add_argument("--size", type=_hex, required=True)
    mea.add_argument("--obj", type=Path, required=True)
    mea.set_defaults(handler=_command_measure)
    return parser


def _add_slice_arguments(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--state", type=Path, required=True)
    parser.add_argument("--func", required=True)
    parser.add_argument("--vram", type=_hex, required=True)
    parser.add_argument("--size", type=_hex, required=True)


def main() -> int:
    args = build_parser().parse_args()
    return args.handler(args)


if __name__ == "__main__":
    sys.exit(main())
