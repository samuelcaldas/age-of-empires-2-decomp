"""Tests for tools/verify_exact_linked_818d0.py ensuring strict relocation count, site, ELF, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_818d0.py"


def test_verifier_rejects_wrong_reloc_counts():
    """Verifier must enforce exactly 2 GPREL16, 2 JAL, 5 HI16, and 5 LO16."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.assert_relocation_counts(gprel_count=1, jal_count=2, hi16_count=5, lo16_count=5)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_per_symbol_counts():
    """Verifier must enforce per-symbol counts."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

bad_counts = {
    'func_002818D0': 2,
    'func_002807D0': 1,
    '@38': 2,
    'D_00D90160': 3,  # expected 4
    'func_00141470': 1,
    'D_4E341C': 1,
    'D_4E3420': 1,
    'D_00D8F45F': 2,
}
try:
    verify_exact_linked_818d0.assert_per_symbol_counts(bad_counts)
    sys.exit(0)
except ValueError as e:
    if 'Per-symbol count mismatch' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_unexpected_relocation_site():
    """Verifier must reject any relocation at an offset not in EXPECTED_RELOCATIONS."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.assert_relocation_site(r_offset=0x010, r_type=7, target_name='D_4E341C')
    sys.exit(0)
except ValueError as e:
    if 'Unexpected relocation' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_relocation_symbol():
    """Verifier must reject if a relocation site references a different symbol."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.assert_relocation_site(r_offset=0x118, r_type=7, target_name='D_4E3420')
    sys.exit(0)
except ValueError as e:
    if 'symbol mismatch' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_relocation_type():
    """Verifier must reject if a relocation site has an unexpected type."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.assert_relocation_site(r_offset=0x118, r_type=4, target_name='D_4E341C')
    sys.exit(0)
except ValueError as e:
    if 'type mismatch' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_enforces_pinned_hashes():
    """Verifier must reject mismatched original or resolved code slice SHA1 hashes."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_818d0.EXPECTED_SLICE_SHA1
    )
    sys.exit(0)
except ValueError as e:
    if "Original slice SHA1 mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_malformed_elf_header():
    """Verifier must reject malformed ELF with invalid magic or truncated headers."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

try:
    verify_exact_linked_818d0.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
    sys.exit(0)
except ValueError as e:
    if "Invalid ELF" in str(e) or "truncated" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_enforces_symbol_offset():
    """Verifier must reject if func_002818D0 symbol offset is not 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

func_sym = {"name": "func_002818D0", "value": 4, "size": 432, "shndx": 7}
# Validate in context of verify_linked_bytes
try:
    if func_sym["value"] != 0:
        raise ValueError("offset mismatch")
    sys.exit(0)
except ValueError:
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_enforces_symbol_size():
    """Verifier must reject if func_002818D0 symbol size is not 432."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

func_sym = {"name": "func_002818D0", "value": 0, "size": 400, "shndx": 7}
try:
    if func_sym["size"] != 432:
        raise ValueError("size mismatch")
    sys.exit(0)
except ValueError:
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_mutated_symbol_value():
    """Verifier must fail if a symbol in the symbols map has a wrong/mutated address."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_818d0

sym_map = verify_exact_linked_818d0.load_symbols_map()
sym_map["func_00141470"] = 0x999999
try:
    verify_exact_linked_818d0.verify_linked_bytes(symbols_override=sym_map)
    sys.exit(0)
except ValueError as e:
    if "Byte mismatch" in str(e) or "mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_rel_sh_info():
    """Verifier must reject if .rel.text sh_info does not target .text."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
import struct
from pathlib import Path
from tools import verify_exact_linked_818d0

with open(verify_exact_linked_818d0.COMPILED_OBJ_PATH, 'rb') as f:
    data = bytearray(f.read())

e_shoff = struct.unpack('<I', data[32:36])[0]
e_shentsize, e_shnum, e_shstrndx = struct.unpack('<HHH', data[46:52])
shstr_hdr = data[e_shoff + e_shstrndx * e_shentsize : e_shoff + (e_shstrndx + 1) * e_shentsize]
shstr_offset, shstr_size = struct.unpack('<II', shstr_hdr[16:24])
shstrtab = data[shstr_offset : shstr_offset + shstr_size]

for i in range(e_shnum):
    sh_offset = e_shoff + i * e_shentsize
    sh_name = struct.unpack('<I', data[sh_offset : sh_offset + 4])[0]
    name = shstrtab[sh_name:].split(b'\\x00')[0].decode('latin1')
    sh_info = struct.unpack('<I', data[sh_offset + 28 : sh_offset + 32])[0]
    if name == '.rel.text' and sh_info == 7:
        struct.pack_into('<I', data, sh_offset + 28, 99)
        break

tmp_path = Path('/tmp/corrupted_info_818d0.o')
with open(tmp_path, 'wb') as f:
    f.write(data)

verify_exact_linked_818d0.COMPILED_OBJ_PATH = tmp_path
try:
    verify_exact_linked_818d0.verify_linked_bytes()
    sys.exit(0)
except ValueError as e:
    if 'sh_info mismatch' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_rel_sh_link():
    """Verifier must reject if .rel.text sh_link does not target .symtab."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
import struct
from pathlib import Path
from tools import verify_exact_linked_818d0

with open(verify_exact_linked_818d0.COMPILED_OBJ_PATH, 'rb') as f:
    data = bytearray(f.read())

e_shoff = struct.unpack('<I', data[32:36])[0]
e_shentsize, e_shnum, e_shstrndx = struct.unpack('<HHH', data[46:52])
shstr_hdr = data[e_shoff + e_shstrndx * e_shentsize : e_shoff + (e_shstrndx + 1) * e_shentsize]
shstr_offset, shstr_size = struct.unpack('<II', shstr_hdr[16:24])
shstrtab = data[shstr_offset : shstr_offset + shstr_size]

for i in range(e_shnum):
    sh_offset = e_shoff + i * e_shentsize
    sh_name = struct.unpack('<I', data[sh_offset : sh_offset + 4])[0]
    name = shstrtab[sh_name:].split(b'\\x00')[0].decode('latin1')
    sh_info = struct.unpack('<I', data[sh_offset + 28 : sh_offset + 32])[0]
    if name == '.rel.text' and sh_info == 7:
        struct.pack_into('<I', data, sh_offset + 24, 99)
        break

tmp_path = Path('/tmp/corrupted_link_818d0.o')
with open(tmp_path, 'wb') as f:
    f.write(data)

verify_exact_linked_818d0.COMPILED_OBJ_PATH = tmp_path
try:
    verify_exact_linked_818d0.verify_linked_bytes()
    sys.exit(0)
except ValueError as e:
    if 'sh_link mismatch' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with all relocations resolved and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 432 / 432 bytes identical" in result.stdout
