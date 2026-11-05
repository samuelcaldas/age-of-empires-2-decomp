from pathlib import Path

def test_kt_gs_render_2272a0_header_exists():
    header = Path("include/kt_gs_render_2272a0.h")
    assert header.exists(), "kt_gs_render_2272a0.h must exist"
