"""Tests for tools/verify_exact_linked_80680.py ensuring strict relocation count, ELF, symbol, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_80680.py"


def test_verifier_enforces_zero_relocations():
    """Verifier must enforce that func_00280680 has exactly 1 GPREL16 and 2 JALs."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.assert_relocation_counts(gprel_count=0, jal_count=2)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_enforces_pinned_hashes():
    """Verifier must reject mismatched original or resolved code slice SHA1 hashes."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_80680.EXPECTED_SLICE_SHA1
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
    assert result.returncode == 42


def test_verifier_rejects_malformed_elf_header():
    """Verifier must reject malformed ELF with invalid magic or truncated headers."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
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
    assert result.returncode == 42


def test_verifier_enforces_symbol_offset():
    """Verifier must reject if func_00280680 symbol offset is not 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.assert_function_symbol(
        sym_name="func_00280680", st_value=4, st_size=236, st_shndx=5, text_sec_idx=5
    )
    sys.exit(0)
except ValueError as e:
    if "offset mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-zero symbol offset: stderr={result.stderr}"


def test_verifier_enforces_symbol_size():
    """Verifier must reject if func_00280680 symbol size is not 236."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.assert_function_symbol(
        sym_name="func_00280680", st_value=0, st_size=100, st_shndx=5, text_sec_idx=5
    )
    sys.exit(0)
except ValueError as e:
    if "size mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong symbol size: stderr={result.stderr}"


def test_verifier_enforces_symbol_section():
    """Verifier must reject if func_00280680 symbol section is not .text."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

try:
    verify_exact_linked_80680.assert_function_symbol(
        sym_name="func_00280680", st_value=0, st_size=236, st_shndx=1, text_sec_idx=5
    )
    sys.exit(0)
except ValueError as e:
    if "section mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong symbol section: stderr={result.stderr}"


def test_verifier_rejects_mutated_symbol_value():
    """Verifier must fail if a symbol in the symbols map has a wrong/mutated address."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

sym_map = verify_exact_linked_80680.load_symbols_map()
sym_map["func_366AF0"] = 0x123456
try:
    verify_exact_linked_80680.verify_linked_bytes(symbols_override=sym_map)
    sys.exit(0)
except ValueError as e:
    if "Byte mismatch" in str(e) or "mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject mutated symbol value: stderr={result.stderr}"


def test_verifier_rejects_out_of_bounds_relocation():
    """Verifier must reject any relocation record in .rel.text that exceeds function bounds."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80680

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked_80680.validate_and_apply_relocation(
        r_offset=240, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=236
    )
    sys.exit(0)
except ValueError as e:
    if "exceeds code boundary" in str(e) or "out of function bounds" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject out-of-bounds relocation: stderr={result.stderr}"


def test_verifier_rejects_wrong_elf_machine():
    """Verifier must reject ELF file if e_machine is not EM_MIPS (8)."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_80680

with open("build/SLES-50282/src/unit_action_build_80680.o", "rb") as f:
    data = bytearray(f.read())

# Overwrite e_machine at offset 0x12 with 3 (EM_386)
struct.pack_into('<H', data, 0x12, 3)
try:
    verify_exact_linked_80680.validate_elf_bytes(data)
    sys.exit(0)
except ValueError as e:
    if "Invalid ELF machine" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong ELF machine: stderr={result.stderr}"


def test_verifier_rejects_wrong_rel_sh_info():
    """Verifier must reject ELF where .rel.text sh_info does not target .text index."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_80680

with open("build/SLES-50282/src/unit_action_build_80680.o", "rb") as f:
    data = bytearray(f.read())

raw, secs, _ = verify_exact_linked_80680.parse_elf_sections_from_bytes(data)
rel_sec_idx = secs['.rel.text']['index']

# Offset of .rel.text section header in section header table
e_shoff = struct.unpack_from('<I', data, 0x20)[0]
e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
rel_shdr_off = e_shoff + rel_sec_idx * e_shentsize

# Overwrite sh_info (at offset + 28) with 99 (invalid text section target)
struct.pack_into('<I', data, rel_shdr_off + 28, 99)

try:
    verify_exact_linked_80680.parse_elf_sections_from_bytes(data)
    sys.exit(0)
except ValueError as e:
    if "does not target .text index" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong .rel.text sh_info: stderr={result.stderr}"


def test_verifier_rejects_wrong_rel_sh_link():
    """Verifier must reject ELF where .rel.text sh_link does not target .symtab index."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked_80680

with open("build/SLES-50282/src/unit_action_build_80680.o", "rb") as f:
    data = bytearray(f.read())

raw, secs, _ = verify_exact_linked_80680.parse_elf_sections_from_bytes(data)
rel_sec_idx = secs['.rel.text']['index']

e_shoff = struct.unpack_from('<I', data, 0x20)[0]
e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
rel_shdr_off = e_shoff + rel_sec_idx * e_shentsize

# Overwrite sh_link (at offset + 24) with 99 (invalid symtab target)
struct.pack_into('<I', data, rel_shdr_off + 24, 99)

try:
    verify_exact_linked_80680.parse_elf_sections_from_bytes(data)
    sys.exit(0)
except ValueError as e:
    if "does not target .symtab index" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject wrong .rel.text sh_link: stderr={result.stderr}"


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with exact counts (1 GPREL16, 2 JALs) and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 236 / 236 bytes identical" in result.stdout


if __name__ == '__main__':
    tests = [
        test_verifier_enforces_zero_relocations,
        test_verifier_enforces_pinned_hashes,
        test_verifier_rejects_malformed_elf_header,
        test_verifier_enforces_symbol_offset,
        test_verifier_enforces_symbol_size,
        test_verifier_enforces_symbol_section,
        test_verifier_rejects_mutated_symbol_value,
        test_verifier_rejects_out_of_bounds_relocation,
        test_verifier_rejects_wrong_elf_machine,
        test_verifier_rejects_wrong_rel_sh_info,
        test_verifier_rejects_wrong_rel_sh_link,
        test_verifier_succeeds_with_exact_counts,
    ]
    print(f"Running {len(tests)} verifier enforcement tests...")
    for t in tests:
        t()
        print(f"  PASS: {t.__name__}")
    print(f"All {len(tests)} tests passed successfully!")
