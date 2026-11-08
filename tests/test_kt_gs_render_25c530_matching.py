import subprocess
from pathlib import Path
import sys
sys.path.insert(0, str(Path(__file__).parent))
import kt_gs_render_25c530_matching_support as ms

def test_kt_gs_render_25c530_matching():
    obj = Path("build/SLES-50282/src/kcet/kt_gs_render_25c530.o")
    cmd = ["ninja", str(obj)]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"ninja failed: {res.stderr}"

    compiled = ms.extract_compiled_bytes(obj)
    expected = ms.get_expected_bytes()
    assert len(compiled) == len(expected), f"Size mismatch: {len(compiled)} != {len(expected)}"
    assert compiled == expected, "Bytes mismatch!"
