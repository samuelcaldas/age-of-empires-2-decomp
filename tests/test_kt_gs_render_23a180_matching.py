import kt_gs_render_23a180_matching_support as ms

def test_kt_gs_render_23a180_matching(tmp_path):
    ms.require_original()
    ms.require_compiler()

    obj_path = tmp_path / "kt_gs_render_23a180.o"
    ms.compile_source(obj_path)

    vram, size = ms.FUNCTIONS["func_0023A180"]
    actual = ms.extract_function_bytes(obj_path, "func_0023A180")
    expected = ms.read_original_bytes(vram, size)

    assert actual == expected
