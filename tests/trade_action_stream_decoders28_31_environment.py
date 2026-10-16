"""Validate a proof root, load fixtures explicitly, and build four fresh objects."""

import importlib.util
from pathlib import Path
import re
import subprocess
import sys

ROOT = None
LINKER = None
PROOF = None
SUPPORTS = {}
EXPECTED_GP = 0x4EA7C0
EXPECTED_TARGET = 0x4E2DA0


def require_root(root=None):
    global ROOT, LINKER, PROOF, SUPPORTS
    selected = Path(root or Path.cwd()).resolve()
    assert Path.cwd().resolve() == selected, "proof ROOT must be the current working directory"
    assert (selected / "configure.py").is_file() and (selected / "config/SLES-50282/config.yml").is_file()
    if root is None:
        git_dir = subprocess.run(["git", "-C", str(selected), "rev-parse", "--git-dir"],
                                 cwd=selected, text=True, capture_output=True, check=True).stdout.strip()
        common = subprocess.run(["git", "-C", str(selected), "rev-parse", "--git-common-dir"],
                                cwd=selected, text=True, capture_output=True, check=True).stdout.strip()
        assert (selected / git_dir).resolve() != (selected / common).resolve(), "default ROOT must be a worktree"
    ROOT = selected
    LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"
    PROOF = ROOT / "build/advisor-decoders28-31-proof"
    SUPPORTS = {number: load_support(number) for number in range(28, 32)}
    assert LINKER.is_file(), f"missing linker {LINKER}"
    return ROOT


def load_support(number):
    name = f"trade_action_stream_decoders{number}_support"
    path = ROOT / "tests" / f"{name}.py"
    spec = importlib.util.spec_from_file_location(name, path)
    assert spec is not None and spec.loader is not None, f"cannot load {path}"
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def run(command):
    assert ROOT is not None and Path.cwd().resolve() == ROOT, "commands must run from validated ROOT"
    subprocess.run([str(item) for item in command], cwd=ROOT, check=True)


def functions(number):
    return SUPPORTS[number].FUNCTIONS


def check_configuration():
    config = (ROOT / "config/SLES-50282/config.yml").read_text(encoding="utf-8")
    symbols = (ROOT / "config/SLES-50282/symbols.txt").read_text(encoding="utf-8")
    configure = (ROOT / "configure.py").read_text(encoding="utf-8")
    for number, support in SUPPORTS.items():
        name = f"trade_action_stream_decoders{number}"
        segment = (f"  - name: {name}\n    type: code\n    start: 0x{support.FILE_OFFSET:X}\n"
                   f"    vram: 0x{support.START_ADDRESS:X}\n    subsegments:\n"
                   f"      - [0x{support.FILE_OFFSET:X}, asm, {name}]\n")
        assert config.count(segment) == 1, f"{name}: configuration segment must occur exactly once"
        assert len(re.findall(rf'Object\(\s*NonMatching,\s*"{name}",', configure)) == 1, name
        for function, address, size in functions(number):
            line = f"{function} = 0x{address:X}; // type:func size:0x{size:X} absolute:True"
            assert symbols.splitlines().count(line) == 1, function
    assert "    start: 0x67EF0\n" in config, "post_base boundary mismatch"
    assert EXPECTED_GP == SUPPORTS[28].EXTERNAL_SYMBOLS["_gp"]
    assert EXPECTED_TARGET == SUPPORTS[28].EXTERNAL_SYMBOLS["D_004E2DA0"]


def prepare_build():
    require_root(ROOT)
    run([sys.executable, ROOT / "configure.py", "--version", "SLES-50282",
         "--compilers", ROOT / "compilers", "--binutils", ROOT / "build/mips_binutils",
         "--wrapper", ROOT / "build/tools/wibo", "--objdiff", ROOT / "build/tools/objdiff-cli"])
    targets = [f"build/SLES-50282/src/trade_action_stream_decoders{n}.o" for n in range(28, 32)]
    for target in targets:
        (ROOT / target).unlink(missing_ok=True)
    for target in targets:
        run(["ninja", "-v", target])
    check_configuration()
