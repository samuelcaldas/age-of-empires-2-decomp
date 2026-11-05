from pathlib import Path

def test_kt_gs_render_226770_header_exists():
    header = Path("include/kt_gs_render_226770.h")
    assert header.exists(), "kt_gs_render_226770.h must exist"
