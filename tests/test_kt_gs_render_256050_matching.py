from __future__ import annotations

import kt_gs_render_256050_matching_support as ms


def test_kt_gs_render_256050_matching():
    target = ms.extract_target_bytes()
    compiled = ms.extract_compiled_bytes()
    assert len(compiled) == len(target), f"Size mismatch: compiled {len(compiled)} vs target {len(target)}"
    assert compiled == target, "Byte mismatch against original AOK.ELF"
