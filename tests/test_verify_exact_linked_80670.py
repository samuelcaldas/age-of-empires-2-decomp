"""Tests for tools/verify_exact_linked_80670.py ensuring strict relocation count, ELF, symbol, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_80670.py"


def test_verifier_enforces_zero_relocations():
    """Verifier must enforce that func_00280670 has exactly 0 relocations."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.assert_relocation_counts(reloc_count=1)
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
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_80670.EXPECTED_SLICE_SHA1
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
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
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
    """Verifier must reject if func_00280670 symbol offset is not 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.assert_function_symbol(
        sym_name="func_00280670", st_value=4, st_size=8, st_shndx=5, text_sec_idx=5
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
    """Verifier must reject if func_00280670 symbol size is not 8."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.assert_function_symbol(
        sym_name="func_00280670", st_value=0, st_size=16, st_shndx=5, text_sec_idx=5
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
    """Verifier must reject if func_00280670 symbol section is not .text."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_80670

try:
    verify_exact_linked_80670.assert_function_symbol(
        sym_name="func_00280670", st_value=0, st_size=8, st_shndx=1, text_sec_idx=5
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


def test_verifier_succeeds_with_exact_bytes():
    """Verifier must succeed with 0 relocations, valid symbol extent, and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "Symbol func_00280670 validated" in result.stdout or "func_00280670" in result.stdout
    assert "EXACT MATCH! 8 / 8 bytes identical" in result.stdout


if __name__ == '__main__':
    tests = [
        test_verifier_enforces_zero_relocations,
        test_verifier_enforces_pinned_hashes,
        test_verifier_rejects_malformed_elf_header,
        test_verifier_enforces_symbol_offset,
        test_verifier_enforces_symbol_size,
        test_verifier_enforces_symbol_section,
        test_verifier_succeeds_with_exact_bytes,
    ]
    print(f"Running {len(tests)} verifier enforcement tests...")
    for t in tests:
        t()
        print(f"  PASS: {t.__name__}")
    print(f"All {len(tests)} tests passed successfully!")
