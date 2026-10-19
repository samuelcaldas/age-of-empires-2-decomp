"""Tests for tools/verify_exact_linked_80770.py ensuring strict relocation count, site, ELF, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_80770.py"


def test_verifier_rejects_wrong_reloc_counts():
    """Verifier must enforce exactly 1 HI16, 1 LO16, and 2 JAL relocations."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80770

try:
    verify_exact_linked_80770.assert_relocation_counts(hi_count=0, lo_count=1, jal_count=2)
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
from tools import verify_exact_linked_80770

try:
    verify_exact_linked_80770.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_80770.EXPECTED_SLICE_SHA1
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
from tools import verify_exact_linked_80770

try:
    verify_exact_linked_80770.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
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
    """Verifier must reject if func_00280770 symbol offset is not 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80770

try:
    verify_exact_linked_80770.assert_function_symbol(
        sym_name="func_00280770", st_value=4, st_size=96, st_shndx=5, text_sec_idx=5
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
    assert result.returncode == 42


def test_verifier_enforces_symbol_size():
    """Verifier must reject if func_00280770 symbol size is not 96."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80770

try:
    verify_exact_linked_80770.assert_function_symbol(
        sym_name="func_00280770", st_value=0, st_size=100, st_shndx=5, text_sec_idx=5
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
    assert result.returncode == 42


def test_verifier_rejects_mutated_symbol_value():
    """Verifier must fail if a symbol in the symbols map has a wrong/mutated address."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80770

sym_map = verify_exact_linked_80770.load_symbols_map()
sym_map["func_138A50"] = 0x123456
try:
    verify_exact_linked_80770.verify_linked_bytes(symbols_override=sym_map)
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
    assert result.returncode == 42


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with 1 HI16, 1 LO16, 2 JALs, and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 96 / 96 bytes identical" in result.stdout


if __name__ == '__main__':
    tests = [
        test_verifier_rejects_wrong_reloc_counts,
        test_verifier_enforces_pinned_hashes,
        test_verifier_rejects_malformed_elf_header,
        test_verifier_enforces_symbol_offset,
        test_verifier_enforces_symbol_size,
        test_verifier_rejects_mutated_symbol_value,
        test_verifier_succeeds_with_exact_counts,
    ]
    print(f"Running {len(tests)} verifier enforcement tests...")
    for t in tests:
        t()
        print(f"  PASS: {t.__name__}")
    print(f"All {len(tests)} tests passed successfully!")
