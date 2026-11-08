from __future__ import annotations

import kt_gs_render_253dc0_matching_support as ms


def test_kt_gs_render_253dc0_binary_match() -> None:
    expected = ms.extract_expected_bytes()
    actual = ms.extract_compiled_bytes()
    assert len(actual) == len(expected), f"Size mismatch: actual={len(actual)}, expected={len(expected)}"
    assert actual == expected, "Binary mismatch in kt_gs_render_253dc0"
