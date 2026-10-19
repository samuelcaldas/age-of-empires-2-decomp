"""Unit tests for tools/verify_post_trade_action_distance_candidates.py failure and success paths."""

from pathlib import Path
import subprocess
import sys

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
VERIFY_SCRIPT = PROJECT_ROOT / "tools" / "verify_post_trade_action_distance_candidates.py"

# Add tools to sys.path so we can import verify directly
sys.path.insert(0, str(PROJECT_ROOT / "tools"))
import verify_post_trade_action_distance_candidates as verifier


def test_verify_post_trade_action_distance_candidates_passes():
    """Verify that the robust ELF relocation matcher exits 0 and reports 624/624 match."""
    res = subprocess.run(
        [sys.executable, str(VERIFY_SCRIPT)],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert res.returncode == 0, f"Verifier failed:\nstdout:\n{res.stdout}\nstderr:\n{res.stderr}"
    assert "SUCCESS: Exact 100.0% byte-for-byte match (624/624 bytes identical)!" in res.stdout
    assert "func_002B8E30: section=5, size=616 bytes" in res.stdout
    assert "Padding to 624 bytes: 8 bytes" in res.stdout


def test_verify_rejects_negative_padding(capsys):
    """Verify that code bytes exceeding slice length trigger negative padding rejection."""
    # When expected_slice_len is 600, code bytes (616) exceed 600 -> padding_needed = -16
    ret = verifier.verify(expected_slice_len=600)
    assert ret == 1
    captured = capsys.readouterr()
    assert "negative padding -16" in captured.out
    assert "ERROR: code bytes (616) exceed slice length (600)" in captured.out


def test_verify_rejects_corrupted_padding(capsys):
    """Verify that non-zero padding in original ELF slice is detected and rejected."""
    elf_path = verifier.ELF_PATH
    with open(elf_path, "rb") as f:
        elf_bytes = bytearray(f.read())

    # Corrupt one byte of padding at 0x1B9010 + 620
    elf_bytes[0x1B9010 + 620] = 0xAA

    ret = verifier.verify(elf_override_bytes=elf_bytes)
    assert ret == 1
    captured = capsys.readouterr()
    assert "contains non-zero bytes" in captured.out
    assert "ERROR: original ELF padding" in captured.out


def test_verify_rejects_wrong_target_slice_length(capsys):
    """Verify that truncated or wrong target slice length is rejected."""
    # Truncate ELF data so target slice is under 624 bytes
    truncated_elf = b"\x00" * (0x1B9010 + 500)

    ret = verifier.verify(elf_override_bytes=truncated_elf)
    assert ret == 1
    captured = capsys.readouterr()
    assert "ERROR: target slice length 500 != 624" in captured.out
