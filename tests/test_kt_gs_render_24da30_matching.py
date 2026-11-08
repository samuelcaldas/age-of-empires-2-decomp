import kt_gs_render_24da30_matching_support as ms

def test_kt_gs_render_24da30_matching(tmp_path):
    ms.require_original()
    ms.require_compiler()

    obj_path = tmp_path / "kt_gs_render_24da30.o"
    ms.compile_source(obj_path)

    for name, (vram, size) in ms.FUNCTIONS.items():
        actual = ms.extract_function_bytes(obj_path, name)
        expected = ms.read_original_bytes(vram, size)
        assert actual == expected, f"Mismatch in {name}"
