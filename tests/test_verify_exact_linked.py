"""Tests for tools/verify_exact_linked.py ensuring strict relocation count enforcement."""

import subprocess
import sys
from pathlib import Path
import pytest

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked.py"


def test_verifier_rejects_wrong_gprel_count():
    """Verifier must raise/exit with error if GPREL16 count differs from 49."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

# Call verify_relocations or verify with wrong count
try:
    verify_exact_linked.assert_relocation_counts(gprel_count=48, jal_count=51)
    sys.exit(0) # Should not succeed
except (AssertionError, ValueError) as e:
    sys.exit(42) # Expected failure
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Verifier failed to reject wrong GPREL count: returncode={result.returncode}, stderr={result.stderr}"


def test_verifier_rejects_wrong_jal_count():
    """Verifier must raise/exit with error if JAL count differs from 51."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

try:
    verify_exact_linked.assert_relocation_counts(gprel_count=49, jal_count=50)
    sys.exit(0)
except (AssertionError, ValueError) as e:
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Verifier failed to reject wrong JAL count: returncode={result.returncode}, stderr={result.stderr}"


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with exact counts (49 GPREL16, 51 JAL) and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "GPREL16 resolved sites:  49 (enforced exact: 49)" in result.stdout or "GPREL16 resolved sites:  49" in result.stdout
    assert "JAL (R_MIPS_26) resolved:51 (enforced exact: 51)" in result.stdout or "JAL (R_MIPS_26) resolved:51" in result.stdout
    assert "EXACT MATCH! 1672 / 1672 bytes identical" in result.stdout
