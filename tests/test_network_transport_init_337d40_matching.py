"""Exact comparison tooling for the transport-init candidate."""
import pytest
from network_match_support import (
    assert_exact, compile_object, private_inputs_missing, verified_original_image,
    original_bytes, relocated_function, first_difference,
)

EXTERNALS = {
    **{name: int(name[2:], 16) for name in (
        "D_004E3560", "D_004E3564", "D_004E353C", "D_004E3538", "D_004E3534",
        "D_004E3548", "D_004E3540", "D_010890B0", "D_010890C0", "D_010890D0",
        "D_010931A0", "D_0108B1A0", "D_004D1F60", "D_004D1F80", "D_004D1FC0",
        "D_004D2000", "D_004D2040", "D_004D2090", "D_004D20B0")},
    **{name: int(name[5:], 16) for name in (
        "func_104D20", "func_389120", "func_388BA0", "func_388C20", "func_388CC0",
        "func_104B20", "func_104B40", "func_118de0", "func_337B30")},
    "_gp": 0x4EA7C0,
}
RELOCATIONS = 107


def test_candidate_relocations_and_comparison(tmp_path):
    missing = private_inputs_missing()
    if missing:
        pytest.skip("private inputs missing: " + ", ".join(missing))
    image = verified_original_image()
    path = compile_object("src/network/network_transport_init_337d40.cpp", tmp_path)
    actual = relocated_function(path, "func_00337D40", 0x337D40, 920,
                                EXTERNALS, RELOCATIONS)
    expected = original_bytes(image, 0x337D40, 920)
    difference = first_difference(actual, expected)
    print("PAL:", sum(a == b for a, b in zip(actual, expected)), "/920 equal bytes;",
          "first difference:", None if difference is None else hex(0x337D40 + difference))
    assert_exact(actual, expected, 0x337D40)


if __name__ == "__main__":
    import sys
    from network_match_support import main
    args = ["src/network/network_transport_init_337d40.cpp", "func_00337D40", "0x337D40", "920",
            "--expect-relocations", str(RELOCATIONS)]
    for name, address in EXTERNALS.items():
        args += ["--extern", f"{name}={address:#x}"]
    sys.exit(main(args))
