from pathlib import Path
import subprocess
import sys
import pytest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/"tests"))
import network_match_support as match
SOURCE=ROOT/"src/network_send_peers_338b90.cpp"
ADDRESS=0x338B90
SIZE=196
RELOCATIONS=2
EXTERNALS=['func_003383B0=0x3383B0']
PADDING=12
def test_exact_match():
    missing=match.private_inputs_missing()
    if missing: pytest.skip("requires original ELF and PS2 tools; missing: "+", ".join(missing))
    command=[str(ROOT/".venv/bin/python"),"tests/network_match_support.py",str(SOURCE),"func_00338B90",hex(ADDRESS),str(SIZE),"--expect-relocations",str(RELOCATIONS)]
    for symbol in EXTERNALS: command.extend(["--extern",symbol])
    result=subprocess.run(command,cwd=ROOT,capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    image=match.verified_original_image()
    assert match.original_bytes(image,ADDRESS+SIZE,PADDING)==b"\0"*PADDING
