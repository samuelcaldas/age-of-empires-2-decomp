"""Unit tests for tools/verify_post_trade_action_plan_step.py failure guards."""

from pathlib import Path
import sys

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
VERIFY_SCRIPT = PROJECT_ROOT / "tools" / "verify_post_trade_action_plan_step.py"

sys.path.insert(0, str(PROJECT_ROOT / "tools"))
import verify_post_trade_action_plan_step as verifier


@pytest.fixture(autouse=True)
def require_prerequisites():
    if not verifier.ELF_PATH or not Path(verifier.ELF_PATH).is_file():
        pytest.skip("requires licensed original ELF")
    if not verifier.COMPILER or not Path(verifier.COMPILER).is_file():
        pytest.skip("requires licensed compiler")
    if not verifier.WIBO or not Path(verifier.WIBO).is_file():
        pytest.skip("requires wibo")


def test_verify_rejects_negative_padding(capsys):
    """Verify that code bytes exceeding slice length trigger negative padding rejection."""
    ret = verifier.verify(expected_slice_len=500)
    assert ret == 1
    captured = capsys.readouterr()
    assert "negative padding" in captured.out
    assert "ERROR: code bytes" in captured.out


def test_verify_rejects_corrupted_padding(capsys):
    """Verify that non-zero padding in original ELF slice is detected and rejected."""
    elf_path = verifier.ELF_PATH
    with open(elf_path, "rb") as f:
        elf_bytes = bytearray(f.read())

    # Corrupt one byte of padding at 0x1B9D10 + 1578
    elf_bytes[0x1B9D10 + 1578] = 0xAA

    ret = verifier.verify(elf_override_bytes=elf_bytes)
    assert ret == 1
    captured = capsys.readouterr()
    assert "contains non-zero bytes" in captured.out
    assert "ERROR: original ELF padding" in captured.out


def test_verify_rejects_wrong_target_slice_length(capsys):
    """Verify that truncated or wrong target slice length is rejected."""
    truncated_elf = b"\x00" * (0x1B9D10 + 500)

    ret = verifier.verify(elf_override_bytes=truncated_elf)
    assert ret == 1
    captured = capsys.readouterr()
    assert "ERROR: target slice length 500 != 1584" in captured.out
