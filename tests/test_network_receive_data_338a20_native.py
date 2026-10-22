from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[1]
def test_native(tmp_path):
 exe=tmp_path/"test"
 result=subprocess.run(["g++","-m32","-std=c++98","-O2","-Iinclude","tests/native/network_receive_data_338a20_test.cpp","src/network_receive_data_338a20.cpp","-o",str(exe)],cwd=ROOT,capture_output=True,text=True)
 assert result.returncode==0,result.stderr
 run=subprocess.run([str(exe)],capture_output=True,text=True)
 assert run.returncode==0,run.stderr
