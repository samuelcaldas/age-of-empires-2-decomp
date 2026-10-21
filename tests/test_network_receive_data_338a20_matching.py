from pathlib import Path
import subprocess
import sys
import pytest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/"tests"))
import network_match_support as match
SOURCE=ROOT/"src/network_receive_data_338a20.cpp"
ADDRESS=0x338A20
SIZE=368
RELOCATIONS=4
EXTERNALS=['func_104D60=0x104D60', 'func_104D40=0x104D40', 'func_117AF8=0x117AF8', 'D_004E3564=0x4E3564']
PADDING=0
def test_exact_match():
    missing=match.private_inputs_missing()
    if missing: pytest.skip("requires original ELF and PS2 tools; missing: "+", ".join(missing))
    command=[str(ROOT/".venv/bin/python"),"tests/network_match_support.py",str(SOURCE),"func_00338A20",hex(ADDRESS),str(SIZE),"--expect-relocations",str(RELOCATIONS)]
    for symbol in EXTERNALS: command.extend(["--extern",symbol])
    result=subprocess.run(command,cwd=ROOT,capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    image=match.verified_original_image()
    assert match.original_bytes(image,ADDRESS+SIZE,PADDING)==b"\0"*PADDING
