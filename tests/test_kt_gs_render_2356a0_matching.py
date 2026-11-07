import pytest
import kt_gs_render_2356a0_matching_support as ms

@pytest.mark.parametrize("name,spec", ms.FUNCTIONS.items())
def test_function_matches_original(tmp_path, name, spec):
    address, size = spec
    obj_path = ms.compile_gs_render_2356a0(tmp_path)
    actual = ms.compiled_bytes(obj_path, name)
    expected = ms.original_bytes(address, size)
    assert actual == expected, f"{name} at 0x{address:08X} did not match original binary bytes"
