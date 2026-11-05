from pathlib import Path

def test_kt_gs_render_227040_header_exists():
    header = Path("include/kt_gs_render_227040.h")
    assert header.exists(), "kt_gs_render_227040.h must exist"
