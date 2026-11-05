import subprocess
from pathlib import Path

def test_kt_gs_render_2263f0_symbols():
    header = Path("include/kt_gs_render_2263f0.h")
    assert header.exists(), "kt_gs_render_2263f0.h must exist"
