"""Static helpers for scripts/ralph_decomp.sh: automatic slicing, loop state, measurement.

Everything here is deterministic. Only code generation is left to the AI agent.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
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

NOP = 0x00000000
JR_RA = 0x03E00008
BRANCH_OPCODES = {0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
COP1_OPCODE = 0x11
COP1_BRANCH_RS = 0x08
SYMBOL_PATTERN = re.compile(
    r"^\S+\s*=\s*(0x[0-9A-Fa-f]+);\s*//\s*(?=.*\btype:func\b)(?=.*\bsize:(0x[0-9A-Fa-f]+|\d+))"
)


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


def find_function_size(code: bytes, start: int, max_size: int) -> int:
    """Return the byte size of the function at ``start`` (through jr ra + delay slot).

    Raises SliceBoundaryError when no return is found within the buffer or cap.
    """
    limit = min(len(code), start + max_size)
    farthest_target = start
    last_return_end: Optional[int] = None
    offset = start
    while offset + 4 <= limit:
        instruction = _word(code, offset)
        if _is_branch(instruction):
            farthest_target = max(farthest_target, _branch_target(offset, instruction))
        if instruction == JR_RA:
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


def _skip_covered_and_padding(code: bytes, base: int, covered: List[Tuple[int, int]]) -> Optional[int]:
    address = base
    end = base + len(code)
    while address + 4 <= end:
        containing = [stop for begin, stop in covered if begin <= address < stop]
        if containing:
            address = max(containing)
        elif _word(code, address - base) == NOP:
            address += 4
        else:
            return address
    return None


def next_slice(
    code: bytes, base: int, covered: List[Tuple[int, int]], max_size: int = DEFAULT_MAX_SLICE
) -> Optional[Slice]:
    """First uncovered function in ``code`` (loaded at ``base``), or None when done."""
    address = _skip_covered_and_padding(code, base, covered)
    if address is None:
        return None
    following = [begin for begin, _ in covered if begin > address]
    cap = min([max_size] + [begin - address for begin in following])
    size = find_function_size(code, address - base, cap)
    return Slice(func=f"func_{address:08X}", vram=address, size=size)


class LoopState:
    """Resumable loop state, written atomically."""

    def __init__(self, path: Path):
        self.path = Path(path)
        self.data: Dict[str, Dict[str, dict]] = {"slices": {}}
        if self.path.is_file():
            self.data = json.loads(self.path.read_text())

    def record(
        self, func: str, vram: int, size: int, pct: float, attempts: int, min_pct: float, max_attempts: int
    ) -> None:
        self.data["slices"][func] = {
            "func": func,
            "vram": vram,
            "size": size,
            "pct": pct,
            "attempts": attempts,
            "status": self._classify(pct, attempts, min_pct, max_attempts),
        }
        self._save()

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

    def pending(self) -> List[dict]:
        rank = {"retry": 0, "partial": 1, "blocked": 2}
        entries = [e for e in self.data["slices"].values() if e["status"] in rank]
        return sorted(entries, key=lambda e: (rank[e["status"]], e["vram"]))

    def covered(self) -> List[Tuple[int, int]]:
        return sorted((e["vram"], e["vram"] + e["size"]) for e in self.data["slices"].values())

    def _save(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        temporary = self.path.with_suffix(".json.tmp")
        temporary.write_text(json.dumps(self.data, indent=2, sort_keys=True))
        os.replace(temporary, self.path)


def _load_text_section() -> bytes:
    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    return decomp_pipeline.get_original_bytes(TEXT_START, TEXT_END - TEXT_START)


def _emit(payload: dict) -> None:
    print(json.dumps(payload))


def _command_next(args: argparse.Namespace) -> int:
    state = LoopState(args.state)
    covered = parse_covered(SYMBOLS_TXT.read_text()) + state.covered()
    found = next_slice(_load_text_section(), TEXT_START, covered, args.max_slice)
    if found:
        _emit({"kind": "new", "func": found.func, "vram": found.vram, "size": found.size})
        return 0
    pending = state.pending()
    if pending:
        _emit({"kind": "revisit", **pending[0]})
        return 0
    _emit({"kind": "done"})
    return 0


def _command_record(args: argparse.Namespace) -> int:
    LoopState(args.state).record(
        args.func, args.vram, args.size, args.pct, args.attempts, args.min_pct, args.max_attempts
    )
    return 0


def _command_disasm(args: argparse.Namespace) -> int:
    from capstone import CS_ARCH_MIPS, CS_MODE_LITTLE_ENDIAN, CS_MODE_MIPS64, Cs

    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    data = decomp_pipeline.get_original_bytes(args.vram, args.size)
    disassembler = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)
    for offset in range(0, len(data), 4):
        raw = data[offset : offset + 4]
        decoded = next(disassembler.disasm(raw, args.vram + offset), None)
        text = f"{decoded.mnemonic} {decoded.op_str}" if decoded else ".word"
        print(f"{args.vram + offset:08X}:  {raw.hex()}  {text}")
    return 0


def _command_measure(args: argparse.Namespace) -> int:
    sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
    import decomp_pipeline

    result = decomp_pipeline.diff_draft(args.func, args.vram, args.size, args.obj)
    _emit({"pct": result["match_percentage"], "is_match": result["is_match"],
           "actual_size": result["actual_size"], "mismatches": result["mismatches"][:10]})
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    nxt = sub.add_parser("next", help="Print the next slice as JSON")
    nxt.add_argument("--state", type=Path, required=True)
    nxt.add_argument("--max-slice", type=lambda x: int(x, 0), default=DEFAULT_MAX_SLICE)
    nxt.set_defaults(handler=_command_next)
    rec = sub.add_parser("record", help="Record a measured result in the loop state")
    rec.add_argument("--state", type=Path, required=True)
    rec.add_argument("--func", required=True)
    rec.add_argument("--vram", type=lambda x: int(x, 0), required=True)
    rec.add_argument("--size", type=lambda x: int(x, 0), required=True)
    rec.add_argument("--pct", type=float, required=True)
    rec.add_argument("--attempts", type=int, required=True)
    rec.add_argument("--min-pct", type=float, default=DEFAULT_MIN_PCT)
    rec.add_argument("--max-attempts", type=int, default=DEFAULT_MAX_ATTEMPTS)
    rec.set_defaults(handler=_command_record)
    dis = sub.add_parser("disasm", help="Disassemble original bytes")
    dis.add_argument("--vram", type=lambda x: int(x, 0), required=True)
    dis.add_argument("--size", type=lambda x: int(x, 0), required=True)
    dis.set_defaults(handler=_command_disasm)
    mea = sub.add_parser("measure", help="Similarity of a compiled object vs. the original")
    mea.add_argument("--func", required=True)
    mea.add_argument("--vram", type=lambda x: int(x, 0), required=True)
    mea.add_argument("--size", type=lambda x: int(x, 0), required=True)
    mea.add_argument("--obj", type=Path, required=True)
    mea.set_defaults(handler=_command_measure)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    return args.handler(args)


if __name__ == "__main__":
    sys.exit(main())
