"""Tests for tools/verify_exact_linked.py ensuring strict relocation count, site, ELF, and hash validation enforcement."""

import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
VERIFIER_SCRIPT = REPO_ROOT / "tools" / "verify_exact_linked.py"


def test_verifier_rejects_wrong_gprel_count():
    """Verifier must raise/exit with error if GPREL16 count differs from 49."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

try:
    verify_exact_linked.assert_relocation_counts(gprel_count=48, jal_count=51)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_wrong_jal_count():
    """Verifier must raise/exit with error if JAL count differs from 51."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

try:
    verify_exact_linked.assert_relocation_counts(gprel_count=49, jal_count=50)
    sys.exit(0)
except (AssertionError, ValueError):
    sys.exit(42)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42


def test_verifier_rejects_unsupported_relocation_type():
    """Verifier must raise ValueError on any in-range relocation type other than R_MIPS_GPREL16 or R_MIPS_26."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=0, r_type=2, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Unsupported in-range relocation type" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject unsupported relocation type: stderr={result.stderr}"


def test_verifier_rejects_corrupted_gprel_opcode():
    """Verifier must validate that instruction at GPREL16 site is addiu $a0, $gp, 0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=0, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Invalid opcode/register at GPREL16 site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject corrupted GPREL opcode: stderr={result.stderr}"


def test_verifier_rejects_corrupted_gprel_addend():
    """Verifier must validate that in-situ addend at GPREL16 site is zero."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

code = bytearray(struct.pack('<I', 0x27840005) + b'\\x00' * 12)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=0, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Non-zero in-situ addend at GPREL16 site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-zero GPREL addend: stderr={result.stderr}"


def test_verifier_rejects_corrupted_jal_opcode():
    """Verifier must validate that instruction at JAL site is jal 0x0."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

code = bytearray(struct.pack('<I', 0x00000000) + b'\\x00' * 12)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=0, r_type=4, sym_name="func_366C60", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Invalid opcode at JAL site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject corrupted JAL opcode: stderr={result.stderr}"


def test_verifier_rejects_corrupted_jal_target_field():
    """Verifier must validate that in-situ target field at JAL site is zero."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

code = bytearray(struct.pack('<I', 0x0C000001) + b'\\x00' * 12)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=0, r_type=4, sym_name="func_366C60", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Non-zero in-situ target field at JAL site" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject non-zero JAL target field: stderr={result.stderr}"


def test_verifier_rejects_unaligned_relocation_offset():
    """Verifier must reject unaligned relocation offsets (e.g. offset not divisible by 4)."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=3, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Unaligned relocation offset" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject unaligned relocation offset: stderr={result.stderr}"


def test_verifier_rejects_truncated_relocation_offset():
    """Verifier must reject relocation sites that extend beyond code boundary."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

code = bytearray(b'\\x00' * 16)
try:
    verify_exact_linked.validate_and_apply_relocation(
        r_offset=16, r_type=7, sym_name="D_4E35DC", compiled_bytes=code, func_size=16
    )
    sys.exit(0)
except ValueError as e:
    if "Relocation site exceeds code boundary" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject truncated relocation site: stderr={result.stderr}"


def test_verifier_rejects_malformed_elf_header():
    """Verifier must reject malformed ELF with invalid magic or truncated headers."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

try:
    verify_exact_linked.validate_elf_bytes(b'NOT_AN_ELF_HEADER_AT_ALL')
    sys.exit(0)
except ValueError as e:
    if "Invalid ELF" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject malformed ELF header: stderr={result.stderr}"


def test_verifier_enforces_pinned_hashes():
    """Verifier must reject mismatched original or resolved code slice SHA1 hashes."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys
from tools import verify_exact_linked

try:
    verify_exact_linked.assert_slice_hashes(
        orig_sha1="wrong_hash_00000000000000000000000000000000",
        resolved_sha1=verify_exact_linked.EXPECTED_SLICE_SHA1
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
    assert result.returncode == 42, f"Failed to reject wrong slice hash: stderr={result.stderr}"


def test_verifier_rejects_short_e_shentsize():
    """Verifier must reject ELF with e_shentsize < 40 (standard Elf32_Shdr size)."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

with open("build/SLES-50282/src/unit_action_build_7f890.o", "rb") as f:
    data = bytearray(f.read())

# Overwrite e_shentsize at offset 0x2e with 32 (< 40)
struct.pack_into('<H', data, 0x2e, 32)
try:
    verify_exact_linked.validate_elf_bytes(data)
    sys.exit(0)
except ValueError as e:
    if "Invalid section header entry size" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject short e_shentsize: stderr={result.stderr}"


def test_verifier_rejects_invalid_symtab_sh_link():
    """Verifier must reject ELF where .symtab section has an out-of-range sh_link."""
    result = subprocess.run(
        [sys.executable, "-c", """
import sys, struct
from tools import verify_exact_linked

with open("build/SLES-50282/src/unit_action_build_7f890.o", "rb") as f:
    data = bytearray(f.read())

# Corrupt .symtab section's sh_link to 999
# First find .symtab section offset in section header table
e_shoff = struct.unpack_from('<I', data, 0x20)[0]
e_shentsize = struct.unpack_from('<H', data, 0x2e)[0]
e_shnum = struct.unpack_from('<H', data, 0x30)[0]
# Find which section has sh_type == 2 (SHT_SYMTAB)
for i in range(e_shnum):
    off = e_shoff + i * e_shentsize
    sh_type = struct.unpack_from('<I', data, off + 4)[0]
    if sh_type == 2: # SHT_SYMTAB
        # sh_link is at offset + 24 (6th uint32)
        struct.pack_into('<I', data, off + 24, 999)
        break

try:
    verify_exact_linked.parse_elf_sections_from_bytes(data)
    sys.exit(0)
except ValueError as e:
    if "Invalid .symtab sh_link" in str(e):
        sys.exit(42)
sys.exit(1)
"""],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 42, f"Failed to reject invalid .symtab sh_link: stderr={result.stderr}"


def test_verifier_succeeds_with_exact_counts():
    """Verifier must succeed with exact counts (49 GPREL16, 51 JAL) and output exact match."""
    result = subprocess.run(
        [sys.executable, str(VERIFIER_SCRIPT)],
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"Verifier failed: {result.stderr}"
    assert "EXACT MATCH! 1672 / 1672 bytes identical" in result.stdout


if __name__ == '__main__':
    tests = [
        test_verifier_rejects_wrong_gprel_count,
        test_verifier_rejects_wrong_jal_count,
        test_verifier_rejects_unsupported_relocation_type,
        test_verifier_rejects_corrupted_gprel_opcode,
        test_verifier_rejects_corrupted_gprel_addend,
        test_verifier_rejects_corrupted_jal_opcode,
        test_verifier_rejects_corrupted_jal_target_field,
        test_verifier_rejects_unaligned_relocation_offset,
        test_verifier_rejects_truncated_relocation_offset,
        test_verifier_rejects_malformed_elf_header,
        test_verifier_enforces_pinned_hashes,
        test_verifier_rejects_short_e_shentsize,
        test_verifier_rejects_invalid_symtab_sh_link,
        test_verifier_succeeds_with_exact_counts,
    ]
    print(f"Running {len(tests)} verifier enforcement tests...")
    for t in tests:
        t()
        print(f"  PASS: {t.__name__}")
    print(f"All {len(tests)} tests passed successfully!")
