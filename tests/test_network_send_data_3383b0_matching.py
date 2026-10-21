from pathlib import Path
import subprocess
import sys
import pytest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/"tests"))
import network_match_support as match
SOURCE=ROOT/"src/network_send_data_3383b0.cpp"
ADDRESS=0x3383B0
SIZE=188
RELOCATIONS=5
EXTERNALS=['func_00337840=0x337840', 'func_118de0=0x118DE0', 'D_004D2110=0x4D2110']
PADDING=4
def test_exact_match():
    missing=match.private_inputs_missing()
    if missing: pytest.skip("requires original ELF and PS2 tools; missing: "+", ".join(missing))
    command=[str(ROOT/".venv/bin/python"),"tests/network_match_support.py",str(SOURCE),"func_003383B0",hex(ADDRESS),str(SIZE),"--expect-relocations",str(RELOCATIONS)]
    for symbol in EXTERNALS: command.extend(["--extern",symbol])
    result=subprocess.run(command,cwd=ROOT,capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    image=match.verified_original_image()
    assert match.original_bytes(image,ADDRESS+SIZE,PADDING)==b"\0"*PADDING
