import hashlib
import os
import struct
import pytest

SLES_PATH = "orig/SLES-50282/SLES_502.82"
EXPECTED_SHA1 = "2f5139c1cb45c6b22b93e0c32bbea8e94a7b4a5f"
EXPECTED_MD5 = "f9465df60fb989635f152c3a2c18a1cc"
EXPECTED_SIZE = 1593256

@pytest.fixture(scope="module")
def sles_bytes():
    assert os.path.exists(SLES_PATH), f"Original SLES binary missing: {SLES_PATH}"
    with open(SLES_PATH, "rb") as f:
        data = f.read()
    return data

def test_sles_binary_identity(sles_bytes):
    assert len(sles_bytes) == EXPECTED_SIZE
    assert hashlib.sha1(sles_bytes).hexdigest() == EXPECTED_SHA1
    assert hashlib.md5(sles_bytes).hexdigest() == EXPECTED_MD5

def test_sles_elf_header(sles_bytes):
    magic = sles_bytes[:4]
    assert magic == b"\x7fELF"
    ei_class = sles_bytes[4]
    assert ei_class == 1  # 32-bit
    ei_data = sles_bytes[5]
    assert ei_data == 1   # Little-endian
    
    e_entry = struct.unpack("<I", sles_bytes[24:28])[0]
    assert e_entry == 0x00100008

def test_sles_embedded_strings_and_modules(sles_bytes):
    # Verify module names for IOP drivers loaded by SLES boot
    required_modules = [
        b"sio2man.irx",
        b"padman.irx",
        b"mcman.irx",
        b"mcserv.irx",
        b"usbd.irx",
        b"usbmouse.irx",
        b"usbkeybd.irx",
        b"usbmload.irx",
        b"usbmlcnt.irx",
        b"libsd.irx",
        b"sd_cd.irx",
        b"sdstr.irx",
        b"soundcd.irx",
        b"sdrdrv.irx",
        b"ioprp23.img"
    ]
    for mod in required_modules:
        assert mod in sles_bytes, f"Missing required module string: {mod.decode()}"

def test_sles_intro_movies_and_pss(sles_bytes):
    movies = [b"mslogo_2.pss", b"eslogo_2.pss", b"age2_2.pss"]
    for m in movies:
        assert m in sles_bytes, f"Missing intro movie reference: {m.decode()}"
    assert b"pss_main.c" in sles_bytes
    assert b"pss_audiodec.c" in sles_bytes

def test_sles_payload_reconstruction(sles_bytes):
    # Verify ELF structure boundaries
    assert sles_bytes[0x100:0x108] == b"\x00\x00\x00\x00\x00\x00\x00\x00"
    # Entry instruction at 0x108 (lui $v0, 0x28)
    assert sles_bytes[0x108:0x10c] == b"\x28\x00\x02\x3c"

