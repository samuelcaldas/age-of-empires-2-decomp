import kt_gs_render_239e90_matching_support as ms

def test_kt_gs_render_239e90_matching(tmp_path):
    ms.require_original()
    ms.require_compiler()

    obj_path = tmp_path / "kt_gs_render_239e90.o"
    ms.compile_source(obj_path)

    vram, size = ms.FUNCTIONS["func_00239E90"]
    actual = ms.extract_function_bytes(obj_path, "func_00239E90")
    expected = ms.read_original_bytes(vram, size)

    assert actual == expected
