import hashlib
import os
import struct
import pytest

MODULES_DIR = "orig/SLES-50282/MODULES"

EXPECTED_IRX = {
    "SOUNDCD.IRX": {
        "size": 114669,
        "sha1": "b99cd70bf2d5fbd25ec65428eb7c5ef5b4cce934",
        "module_name": b"kcet sd drv."
    },
    "SDSTR.IRX": {
        "size": 34257,
        "sha1": "461e0e2fa06e8cc650214cc5a077d8074b86be5d",
        "module_name": b"sdstr_driver"
    },
    "SD_CD.IRX": {
        "size": 15297,
        "sha1": "d9d32ad95e93f8d3cbb70dfb0fd53d198a770022",
        "module_name": b"sdcd_Lib"
    },
    "SDRDRV.IRX": {
        "size": 6345,
        "sha1": "199da7b0ca8502b82a906bc9ef7ddd20896f113c",
        "module_name": b"sdr_driver"
    },
    "USBMLCNT.IRX": {
        "size": 24347,
        "sha1": "a950483a045ea4c292a90e1f45fabeeffa6d8bc6",
        "module_name": b"usbmlcnt"
    },
    "USBMLOAD.IRX": {
        "size": 13865,
        "sha1": "884f27e27e7f8764fab5365996147c2ed3d1ff9a",
        "module_name": b"USB_module_loader"
    }
}

@pytest.mark.parametrize("filename,meta", EXPECTED_IRX.items())
def test_iop_driver_identity_and_matching(filename, meta):
    path = os.path.join(MODULES_DIR, filename)
    assert os.path.exists(path), f"IRX missing: {path}"
    with open(path, "rb") as f:
        data = f.read()
    
    assert len(data) == meta["size"]
    assert hashlib.sha1(data).hexdigest() == meta["sha1"]
    assert meta["module_name"] in data
    
    # ELF Header check (MIPS R3000 IOP module)
    assert data[:4] == b"\x7fELF"
    assert data[4] == 1  # 32-bit
    assert data[5] == 1  # LSB little-endian
    e_machine = struct.unpack("<H", data[18:20])[0]
    assert e_machine == 8  # EM_MIPS
