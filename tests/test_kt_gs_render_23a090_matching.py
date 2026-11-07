import kt_gs_render_23a090_matching_support as ms

def test_kt_gs_render_23a090_matching(tmp_path):
    ms.require_original()
    ms.require_compiler()

    obj_path = tmp_path / "kt_gs_render_23a090.o"
    ms.compile_source(obj_path)

    vram, size = ms.FUNCTIONS["func_0023A090"]
    actual = ms.extract_function_bytes(obj_path, "func_0023A090")
    expected = ms.read_original_bytes(vram, size)

    assert actual == expected
