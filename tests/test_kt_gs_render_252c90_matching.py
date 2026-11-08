import kt_gs_render_252c90_matching_support as ms

def test_kt_gs_render_252c90_matching():
    target = ms.extract_target_bytes()
    assert len(target) == 0xF0
    compiled = ms.extract_compiled_bytes()
    assert compiled is not None, "Compile build/SLES-50282/src/kcet/kt_gs_render_252c90.o first"
    assert compiled == target, f"Mismatch: compiled {len(compiled)} bytes vs target {len(target)} bytes"
