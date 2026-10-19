"""Tests for tools/verify_exact_linked_7ff20.py ensuring strict relocation count, site, ELF, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_7ff20.py"


def test_verifier_rejects_wrong_gprel_count():
    """Verifier must raise/exit with error if GPREL16 count differs from 39."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.assert_relocation_counts(gprel_count=38, jal_count=49)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_jal_count():
    """Verifier must raise/exit with error if JAL count differs from 49."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.assert_relocation_counts(gprel_count=39, jal_count=48)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_unsupported_relocation_type():
    """Verifier must raise ValueError on any in-range relocation type other than R_MIPS_GPREL16 or R_MIPS_26."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=0, r_type=2, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Unsupported in-range relocation type" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject unsupported relocation type: stderr={result.stderr}"


def test_verifier_rejects_corrupted_gprel_opcode():
    """Verifier must validate that instruction at GPREL16 site is addiu $a0, $gp, 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_7ff20

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=0, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Invalid opcode/register at GPREL16 site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject corrupted GPREL opcode: stderr={result.stderr}"


def test_verifier_rejects_corrupted_gprel_addend():
    """Verifier must validate that in-situ addend at GPREL16 site is zero."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_7ff20

code = bytearray(struct.pack('<I', 0x27840005) + b'\\x00' * 12)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=0, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Non-zero in-situ addend at GPREL16 site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-zero GPREL addend: stderr={result.stderr}"


def test_verifier_rejects_corrupted_jal_opcode():
    """Verifier must validate that instruction at JAL site is jal 0x0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_7ff20

code = bytearray(struct.pack('<I', 0x00000000) + b'\\x00' * 12)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=0, r_type=4, sym_name="func_366C60", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Invalid opcode at JAL site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject corrupted JAL opcode: stderr={result.stderr}"


def test_verifier_rejects_corrupted_jal_target_field():
    """Verifier must validate that in-situ target field at JAL site is zero."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_7ff20

code = bytearray(struct.pack('<I', 0x0C000001) + b'\\x00' * 12)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=0, r_type=4, sym_name="func_366C60", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Non-zero in-situ target field at JAL site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-zero JAL target field: stderr={result.stderr}"


def test_verifier_rejects_unaligned_relocation_offset():
    """Verifier must reject unaligned relocation offsets (e.g. offset not divisible by 4)."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=3, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Unaligned relocation offset" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject unaligned relocation offset: stderr={result.stderr}"


def test_verifier_rejects_truncated_relocation_offset():
    """Verifier must reject relocation sites that extend beyond code boundary."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked_7ff20.validate_and_apply_relocation(
        r_offset=16, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Relocation site exceeds code boundary" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject truncated relocation site: stderr={result.stderr}"


def test_verifier_rejects_malformed_elf_header():
    """Verifier must reject malformed ELF with invalid magic or truncated headers."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
    sys.exit(0)
except ValueError as e:
    if "Invalid ELF" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject malformed ELF header: stderr={result.stderr}"


def test_verifier_enforces_pinned_hashes():
    """Verifier must reject mismatched original or resolved code slice SHA1 hashes."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_7ff20.EXPECTED_SLICE_SHA1
    )
    sys.exit(0)
except ValueError as e:
    if "Original slice SHA1 mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong slice hash: stderr={result.stderr}"


def test_verifier_rejects_non_multiple_symbol_table_size():
    """Verifier must reject symbol table whose size is not an exact multiple of entry size."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.validate_table_entry_divisibility(
        symtab_size=16 * 10 + 5,
        sym_entsize=16,
        reloc_size=8 * 10,
        reloc_entsize=8
    )
    sys.exit(0)
except ValueError as e:
    if "Symbol table size" in str(e) and "not cleanly divisible" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-multiple symbol table size: stderr={result.stderr}"


def test_verifier_rejects_non_multiple_relocation_table_size():
    """Verifier must reject relocation table whose size is not an exact multiple of entry size."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

try:
    verify_exact_linked_7ff20.validate_table_entry_divisibility(
        symtab_size=16 * 10,
        sym_entsize=16,
        reloc_size=8 * 10 + 3,
        reloc_entsize=8
    )
    sys.exit(0)
except ValueError as e:
    if "Relocation table size" in str(e) and "not cleanly divisible" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-multiple relocation table size: stderr={result.stderr}"


def test_verifier_loads_symbols_from_symbols_txt():
    """Verifier must load and validate symbol values from config/SLES-50282/symbols.txt."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

sym_map = verify_exact_linked_7ff20.load_symbols_map()
assert "D_4E35DC" in sym_map, "D_4E35DC missing from symbols map"
assert sym_map["D_4E35DC"] == 0x4E35DC, f"Wrong D_4E35DC value: {sym_map['D_4E35DC']:#x}"
assert "func_366C60" in sym_map, "func_366C60 missing from symbols map"
assert sym_map["func_366C60"] == 0x366C60, f"Wrong func_366C60 value: {sym_map['func_366C60']:#x}"
sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to load symbols map: stderr={result.stderr}"


def test_verifier_rejects_mutated_symbol_value():
    """Verifier must fail if a symbol in the symbols map has a wrong/mutated address."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_7ff20

# Override func_366C60 with wrong address 0x123456
sym_map = verify_exact_linked_7ff20.load_symbols_map()
sym_map["func_366C60"] = 0x123456
try:
    verify_exact_linked_7ff20.verify_linked_bytes(symbols_override=sym_map)
    sys.exit(0) # Should not succeed
except ValueError as e:
    if "Byte mismatch" in str(e) or "mismatch" in str(e):
        sys.exit(42) # Expected failure
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject mutated symbol value: stderr={result.stderr}"


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with exact counts (39 GPREL16, 49 JAL) and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 1860 / 1860 bytes identical" in result.stdout


if __name__ == '__main__':
    tests = [
        test_verifier_rejects_wrong_gprel_count,
        test_verifier_rejects_wrong_jal_count,
        test_verifier_rejects_unsupported_relocation_type,
        test_verifier_rejects_corrupted_gprel_opcode,
        test_verifier_rejects_corrupted_gprel_addend,
        test_verifier_rejects_corrupted_jal_opcode,
        test_verifier_rejects_corrupted_jal_target_field,
        test_verifier_rejects_unaligned_relocation_offset,
        test_verifier_rejects_truncated_relocation_offset,
        test_verifier_rejects_malformed_elf_header,
        test_verifier_enforces_pinned_hashes,
        test_verifier_rejects_non_multiple_symbol_table_size,
        test_verifier_rejects_non_multiple_relocation_table_size,
        test_verifier_loads_symbols_from_symbols_txt,
        test_verifier_rejects_mutated_symbol_value,
        test_verifier_succeeds_with_exact_counts,
    ]
    print(f"Running {len(tests)} verifier enforcement tests...")
    for t in tests:
        t()
        print(f"  PASS: {t.__name__}")
    print(f"All {len(tests)} tests passed successfully!")
