"""Tests for tools/verify_exact_linked_807d0.py ensuring strict relocation count, site, ELF, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked_807d0.py"


def test_verifier_rejects_wrong_reloc_counts():
    """Verifier must enforce exactly 45 GPREL16, 22 JAL, and 16 JALR call sites."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_807d0

try:
    verify_exact_linked_807d0.assert_relocation_counts(gprel_count=44, jal_count=22, jalr_count=16)
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
    """Verifier must enforce 31 D_4E3418, 14 D_4E3420, 10 func_202B10, and 12 func_205920."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_807d0

bad_counts = {
    'D_4E3418': 30, # expected 31
    'D_4E3420': 14,
    'func_202B10': 10,
    'func_205920': 12,
}
try:
    verify_exact_linked_807d0.assert_per_symbol_counts(bad_counts)
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
from tools import verify_exact_linked_807d0

try:
    # 0x0F8 is not an expected relocation offset
    verify_exact_linked_807d0.assert_relocation_site(r_offset=0x0F8, r_type=7, target_name='D_4E3418')
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
from tools import verify_exact_linked_807d0

try:
    # 0x0F0 expects D_4E3418, not D_4E3420
    verify_exact_linked_807d0.assert_relocation_site(r_offset=0x0F0, r_type=7, target_name='D_4E3420')
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


def test_verifier_rejects_non_zero_unlinked_addend():
    """Verifier must reject non-zero unlinked addends in ET_REL."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_807d0

try:
    # Non-zero low 16 bits in unlinked instruction
    verify_exact_linked_807d0.assert_relocation_addend(
        r_type=7, sym_vram=0x4E3418, unlinked_word=0x8F830004, resolved_word=0x8F838C58
    )
    sys.exit(0)
except ValueError as e:
    if 'Non-zero unlinked' in str(e):
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
from tools import verify_exact_linked_807d0

try:
    verify_exact_linked_807d0.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked_807d0.EXPECTED_SLICE_SHA1
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
from tools import verify_exact_linked_807d0

try:
    verify_exact_linked_807d0.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
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
    """Verifier must reject if func_002807D0 symbol offset is not 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_807d0

try:
    verify_exact_linked_807d0.assert_function_symbol(
        sym_name="func_002807D0", st_value=4, st_size=2132, st_shndx=5, text_sec_idx=5
    )
    sys.exit(0)
except ValueError as e:
    if "offset mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_enforces_symbol_size():
    """Verifier must reject if func_002807D0 symbol size is not 2132."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked_807d0

try:
    verify_exact_linked_807d0.assert_function_symbol(
        sym_name="func_002807D0", st_value=0, st_size=2000, st_shndx=5, text_sec_idx=5
    )
    sys.exit(0)
except ValueError as e:
    if "size mismatch" in str(e):
        sys.exit(42)
sys.exit(1)
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
from tools import verify_exact_linked_807d0

sym_map = verify_exact_linked_807d0.load_symbols_map()
sym_map["func_202B10"] = 0x123456
try:
    verify_exact_linked_807d0.verify_linked_bytes(symbols_override=sym_map)
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
from tools import verify_exact_linked_807d0

with open(verify_exact_linked_807d0.COMPILED_OBJ_PATH, 'rb') as f:
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
    if name == '.rel.text' and sh_info == 5:
        # Corrupt sh_info (offset 28 within section header)
        struct.pack_into('<I', data, sh_offset + 28, 99)
        break

tmp_path = Path('/tmp/corrupted_info.o')
with open(tmp_path, 'wb') as f:
    f.write(data)

orig_path = verify_exact_linked_807d0.COMPILED_OBJ_PATH
verify_exact_linked_807d0.COMPILED_OBJ_PATH = tmp_path
try:
    verify_exact_linked_807d0.verify_linked_bytes()
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
from tools import verify_exact_linked_807d0

with open(verify_exact_linked_807d0.COMPILED_OBJ_PATH, 'rb') as f:
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
    if name == '.rel.text' and sh_info == 5:
        # Corrupt sh_link (offset 24 within section header)
        struct.pack_into('<I', data, sh_offset + 24, 99)
        break

tmp_path = Path('/tmp/corrupted_link.o')
with open(tmp_path, 'wb') as f:
    f.write(data)

orig_path = verify_exact_linked_807d0.COMPILED_OBJ_PATH
verify_exact_linked_807d0.COMPILED_OBJ_PATH = tmp_path
try:
    verify_exact_linked_807d0.verify_linked_bytes()
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


def test_verifier_rejects_non_multiple_symtab():
    """Verifier must reject if .symtab size is not divisible by 16."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
import struct
from pathlib import Path
from tools import verify_exact_linked_807d0

with open(verify_exact_linked_807d0.COMPILED_OBJ_PATH, 'rb') as f:
    data = bytearray(f.read())

e_shoff = struct.unpack('<I', data[32:36])[0]
e_shentsize, e_shnum = struct.unpack('<HH', data[46:50])

for i in range(e_shnum):
    sh_offset = e_shoff + i * e_shentsize
    sh_type = struct.unpack('<I', data[sh_offset + 4 : sh_offset + 8])[0]
    if sh_type == 2:  # SHT_SYMTAB
        size = struct.unpack('<I', data[sh_offset + 20 : sh_offset + 24])[0]
        struct.pack_into('<I', data, sh_offset + 20, size + 3)
        break

tmp_path = Path('/tmp/corrupted_symtab.o')
with open(tmp_path, 'wb') as f:
    f.write(data)

verify_exact_linked_807d0.COMPILED_OBJ_PATH = tmp_path
try:
    verify_exact_linked_807d0.verify_linked_bytes()
    sys.exit(0)
except ValueError as e:
    if 'Symbol table size not divisible' in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with 45 GPREL16, 22 JALs, 16 JALRs, and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 2132 / 2132 bytes identical" in result.stdout
