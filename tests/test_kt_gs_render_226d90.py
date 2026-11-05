from pathlib import Path

def test_kt_gs_render_226d90_header_exists():
    header = Path("include/kt_gs_render_226d90.h")
    assert header.exists(), "kt_gs_render_226d90.h must exist"
