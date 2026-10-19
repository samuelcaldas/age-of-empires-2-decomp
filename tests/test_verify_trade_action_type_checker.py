"""Unit tests for tools/verify_trade_action_type_checker.py failure and success paths."""

import io
from pathlib import Path
import subprocess
import sys

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
VERIFY_SCRIPT = PROJECT_ROOT / "tools" / "verify_trade_action_type_checker.py"

# Add tools to sys.path so we can import verify directly
sys.path.insert(0, str(PROJECT_ROOT / "tools"))
import verify_trade_action_type_checker as verifier


def test_verify_trade_action_type_checker_passes():
    """Verify that the robust ELF relocation matcher exits 0 and reports 160/160 match."""
    res = subprocess.run(
        [sys.executable, str(VERIFY_SCRIPT)],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert res.returncode == 0, f"Verifier failed:\nstdout:\n{res.stdout}\nstderr:\n{res.stderr}"
    assert "SUCCESS: Exact 100.0% byte-for-byte match (160/160 bytes identical)!" in res.stdout
    assert "func_002B90A0: section=5, size=144 bytes" in res.stdout
    assert "func_002B9130: section=9, size=8 bytes" in res.stdout
    assert "Padding to 160 bytes: 8 bytes" in res.stdout


def test_verify_rejects_negative_padding(capsys):
    """Verify that code bytes exceeding slice length trigger negative padding rejection."""
    # When expected_slice_len is 140, code bytes (152) exceed 140 -> padding_needed = -12
    ret = verifier.verify(expected_slice_len=140)
    assert ret == 1
    captured = capsys.readouterr()
    assert "negative padding -12" in captured.out
    assert "ERROR: code bytes (152) exceed slice length (140)" in captured.out


def test_verify_rejects_corrupted_padding(capsys):
    """Verify that non-zero padding in original ELF slice is detected and rejected."""
    elf_path = verifier.ELF_PATH
    with open(elf_path, "rb") as f:
        elf_bytes = bytearray(f.read())

    # Corrupt one byte of padding at 0x1B9280 + 155
    elf_bytes[0x1B9280 + 155] = 0xAA

    ret = verifier.verify(elf_override_bytes=elf_bytes)
    assert ret == 1
    captured = capsys.readouterr()
    assert "contains non-zero bytes" in captured.out
    assert "ERROR: original ELF padding" in captured.out


def test_verify_rejects_wrong_target_slice_length(capsys):
    """Verify that truncated or wrong target slice length is rejected."""
    # Truncate ELF data so target slice is under 160 bytes
    truncated_elf = b"\x00" * (0x1B9280 + 100)

    ret = verifier.verify(elf_override_bytes=truncated_elf)
    assert ret == 1
    captured = capsys.readouterr()
    assert "ERROR: target slice length 100 != 160" in captured.out
