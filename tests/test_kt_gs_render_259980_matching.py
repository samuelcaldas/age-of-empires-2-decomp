import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import kt_gs_render_259980_matching_support as ms

def test_slice_matches_original_elf():
    assert ms.matches_expected()
