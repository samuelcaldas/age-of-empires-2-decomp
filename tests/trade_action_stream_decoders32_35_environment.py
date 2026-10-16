"""Validate a disposable snapshot and prepare four fresh decoder objects."""

import importlib.util
from pathlib import Path
import re
import subprocess
import sys

ROOT = None
LINKER = None
PROOF = None
SUPPORTS = {}


def load_support(number):
    name = f"trade_action_stream_decoders{number}_support"
    path = ROOT / "tests" / f"{name}.py"
    spec = importlib.util.spec_from_file_location(name, path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def require_root(root=None):
    global ROOT, LINKER, PROOF, SUPPORTS
    selected = Path(root or Path.cwd()).resolve()
    assert Path.cwd().resolve() == selected, "explicit snapshot root must equal cwd"
    assert (selected / ".decoder32_35_snapshot").is_file(), "requires disposable Docker snapshot"
    assert (selected / "configure.py").is_file()
    ROOT = selected
    LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"
    PROOF = ROOT / "build/advisor-decoder32-35-proof"
    SUPPORTS = {number: load_support(number) for number in range(32, 36)}
    assert LINKER.is_file(), f"missing GNU MIPS linker {LINKER}"
    return ROOT


def run(command):
    assert ROOT is not None and Path.cwd().resolve() == ROOT
    subprocess.run([str(value) for value in command], cwd=ROOT, check=True)


def functions(number):
    return SUPPORTS[number].FUNCTIONS


def check_configuration():
    config = (ROOT / "config/SLES-50282/config.yml").read_text()
    symbols = (ROOT / "config/SLES-50282/symbols.txt").read_text().splitlines()
    configure = (ROOT / "configure.py").read_text()
    for number, support in SUPPORTS.items():
        name = f"trade_action_stream_decoders{number}"
        segment = (f"  - name: {name}\n    type: code\n    start: 0x{support.FILE_OFFSET:X}\n"
                   f"    vram: 0x{support.START_ADDRESS:X}\n    subsegments:\n"
                   f"      - [0x{support.FILE_OFFSET:X}, asm, {name}]\n")
        assert config.count(segment) == 1, f"{name} segment is not unique"
        assert len(re.findall(rf'Object\(\s*NonMatching,\s*"{name}",', configure)) == 1
        for function, address, size in functions(number):
            line = f"{function} = 0x{address:X}; // type:func size:0x{size:X} absolute:True"
            assert symbols.count(line) == 1, function
    assert "    start: 0x68AA0\n" in config, "post_base boundary mismatch"


def prepare_build():
    require_root(ROOT)
    run([sys.executable, ROOT / "configure.py", "--version", "SLES-50282",
         "--compilers", ROOT / "compilers", "--binutils", ROOT / "build/mips_binutils",
         "--wrapper", ROOT / "build/tools/wibo", "--objdiff", ROOT / "build/tools/objdiff-cli"])
    targets = [ROOT / f"build/SLES-50282/src/trade_action_stream_decoders{n}.o"
               for n in range(32, 36)]
    for target in targets:
        target.unlink(missing_ok=True)
    for target in targets:
        run(["ninja", "-v", target.relative_to(ROOT)])
    check_configuration()
