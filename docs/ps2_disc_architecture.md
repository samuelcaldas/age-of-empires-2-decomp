# PS2 Disc Architecture & File Catalog (SLES-50282)

Comprehensive specification and catalog of all files and directories on the European PlayStation 2 CD-ROM of *Age of Empires II: The Age of Kings* (PAL Europe v2.00, `SLES-50282`).

---

## 1. Disc Specifications & Media Descriptor

The European retail release is mastered as a PlayStation 2 CD-ROM (Mode 2 Form 1, 2352 bytes/sector) with an ISO 9660 Level 1 filesystem.

### Primary Volume Descriptor
* **Disc Label / Serial:** `SLES-50282`
* **Volume Identifier:** `AOE2`
* **System Identifier:** `PLAYSTATION`
* **Application Identifier:** `PLAYSTATION`
* **Copyright Notice:** `KONAMI TYO,INC.`
* **Mastering Date:** `2002-05-07 03:06:36.00 UTC`
* **Total Media Size:** `551,100,416 bytes` (525.57 MiB / 269,092 sectors)
* **Disc Image SHA-1:** `77a9cec2083a7c3d82518b3ae47371b55ec2e7ce`
* **Total Entries:** 93 items (85 files, 8 directories)

---

## 2. Multi-Stage Execution & Boot Flow

The console boots through a multi-stage architecture designed by Konami Computer Entertainment Tokyo (KCET) that coordinates the Emotion Engine (EE), the I/O Processor (IOP), and dynamic CodeWarrior overlays:

```mermaid
flowchart TD
    ROM["PS2 ROM / OSD"] -->|Reads CD Root| CNF["SYSTEM.CNF<br/>(BOOT2 = cdrom0:\\SLES_502.82;1)"]
    CNF -->|Executes ELF| SLES["SLES_502.82 (1.59 MB)<br/>KCET Bootloader & Language Selector"]
    
    subgraph SLES_STAGE ["Stage 1: Launcher & Pre-Game"]
        SLES -->|Loads IOP Kernel| IOPRP["MODULES/IOPRP23.IMG"]
        SLES -->|Loads Input & Sound Drivers| BASE_IRX["PADMAN.IRX, LIBSD.IRX, SOUNDCD.IRX"]
        SLES -->|Plays Intro FMVs| PSS["PPS_PAL/*.PSS Videos<br/>(MSLOGO_2, ESLOGO_2, AGE2_2)"]
        SLES -->|Inspects OSD Language / User Input| LANG_PICK{"Language<br/>Selection"}
    end

    LANG_PICK -->|EN| AGE_EN["EN/AGE2_PS2.ELF (3.9 MB)<br/>Primary Target: AOK.ELF"]
    LANG_PICK -->|FR| AGE_FR["FR/AGE2_PS2.ELF (4.0 MB)"]
    LANG_PICK -->|GR| AGE_GR["GR/AGE2_PS2.ELF (4.0 MB)"]
    LANG_PICK -->|IT| AGE_IT["IT/AGE2_PS2.ELF (4.0 MB)"]
    LANG_PICK -->|SP| AGE_SP["SP/AGE2_PS2.ELF (4.0 MB)"]

    SLES -->|LoadExecPS2| AGE_EN

    subgraph ENGINE_STAGE ["Stage 2: Genie Engine & KCET Subsystems"]
        AGE_EN -->|Loads Runtime Drivers| NET_IRX["MODULES2/*.IRX<br/>(SMAP, TCP/IP, i.LINK)"]
        AGE_EN -->|Loads Peripherals| USB_IRX["MODULES/USBMOUSE.IRX<br/>MODULES/USBKEYBD.IRX"]
        AGE_EN -->|Mounts DRS Resources| DRS["ALL_DATA.BIN (89.3 MB)<br/>(Optional HDD Cache pfs0:)"]
        AGE_EN -->|Streams Audio & Speech| AUDIO["DATA.CAT (198.3 MB)"]
        AGE_EN -->|Swaps CodeWarrior Overlays (MWo3)| OVERLAYS["*_CD.BIN Overlays<br/>(Lobby, Menus, Tech Tree, History, RMS)"]
    end
```

---

## 3. Root Files

### `SYSTEM.CNF`
* **Path:** `SYSTEM.CNF`
* **Size:** 56 bytes
* **SHA-1:** `263ce23a419846b0a701833d7b8d8ecb1bc309e4`
* **Encoding:** Plain ASCII with CRLF line terminators (`0x0D 0x0A`).
* **Purpose:** Standard Sony boot configuration file parsed by the PS2 OSD/BIOS upon disc insertion.
* **Directives:**
  ```ini
  BOOT2 = cdrom0:\SLES_502.82;1
  VER = 2.00
  VMODE = PAL
  ```
  - `BOOT2`: Sets the primary EE executable path.
  - `VER`: Retail release version (2.00).
  - `VMODE`: Sets the video standard to PAL (50 Hz / 576i).

---

### `SLES_502.82`
* **Path:** `SLES_502.82`
* **Size:** 1,593,256 bytes
* **SHA-1:** `2f5139c1cb45c6b22b93e0c32bbea8e94a7b4a5f`
* **Format:** ELF32 MIPS R5900 (Emotion Engine).
* **Compiler:** Metrowerks CodeWarrior for PlayStation 2 (`MWCCPS2` v2.3.1.01).
* **Purpose:** The multilingual launcher and bootloader created by Konami Computer Entertainment Tokyo (KCET). It handles:
  1. Bootstrapping the EE, GS (Graphics Synthesizer), and DMAC.
  2. Loading the IOP replacement image (`MODULES/IOPRP23.IMG`) and core audio/pad drivers.
  3. Playing the publisher, developer, and intro FMVs (`PPS_PAL/*.PSS`).
  4. Querying the PS2 system configuration (EEPROM/OSD settings) for language preference, or presenting a language selection menu.
  5. Transferring execution to the localized game engine (`<LANG>/AGE2_PS2.ELF`) via Sony's `LoadExecPS2()` syscall.
  6. Optional caching of `ALL_DATA.BIN` to the internal PS2 HDD (`pfs0:all_data.bin`) if detected.

---

### `ALL_DATA.BIN`
* **Path:** `ALL_DATA.BIN`
* **Size:** 93,636,608 bytes (~89.3 MiB)
* **SHA-1:** `ea17dae27f428c9ce4464d6db870845bf3bbffac`
* **Format:** Ensemble Studios Genie Engine **DRS Archive** (`1.00tribe` container).
* **Header Signature:** `Copyright (c) 1997 Ensemble Studios\0\0\0\0\01.00tribe`
* **Purpose:** Master consolidated archive of game assets. On PC, these resources are split across multiple files (`graphics.drs`, `interfac.drs`, `sounds.drs`, `terrain.drs`). In the PS2 port, KCET unified them into `ALL_DATA.BIN` to maximize CD streaming throughput and minimize seek times:
  - Unit, building, animal, and siege engine sprites (`.slp` format).
  - UI artwork, buttons, cursors, minimap frames, and background graphics.
  - Color palettes (`.bnd` / `.pal`).
  - Terrain textures and blending masks.
  - Sound effects (WAV/ADPCM audio for units, combat, horns, and construction).

---

### `DATA.CAT`
* **Path:** `DATA.CAT`
* **Size:** 207,900,672 bytes (~198.3 MiB)
* **SHA-1:** `3f48a8eb543fbe0642fa602a8eb51f33f6fb38d3`
* **Format:** Konami Sound Data Container (`SdDt` / `sdtr` / `tmid`).
* **Purpose:** Streaming audio catalogue for the PlayStation 2 SPU2 sound hardware:
  - Complete orchestrated background music tracks (BGM) for all 13 civilizations.
  - In-game dynamic battle themes and victory/defeat stingers.
  - Full voice acting and campaign narration dialog for all missions (Joan of Arc, Saladin, Genghis Khan, Barbarossa, William Wallace).
  - Streamed continuously off the CD using KCET's `SDSTR.IRX` and `SD_CD.IRX` drivers.

---

## 4. FMV Cinemática (`PPS_PAL/`)

All video files use the Sony **PSS** format (*PlayStation Stream*), which multiplexes an MPEG-2 video stream with SPU2 ADPCM stereo audio at 25 frames per second (PAL):

| File | Size (Bytes) | SHA-1 | Purpose |
| :--- | :--- | :--- | :--- |
| **`MSLOGO_2.PSS`** | 14,499,844 | `86ca9986b24d9c7921c81ef442878bfce9dfba88` | Animated Microsoft Games company logo. |
| **`ESLOGO_2.PSS`** | 18,382,852 | `4dbe202e811c7501a3ea36c84b1d6e0687702816` | Animated Ensemble Studios developer logo. |
| **`AGE2_2.PSS`** | 113,967,108 | `784b1fba50bfdb3235b2e38cce8ae13d333ae47e` | Full cinematic intro movie (the chess match between rival kings depicted with living armies). |

---

## 5. Localized Language Folders (`EN/`, `FR/`, `GR/`, `IT/`, `SP/`)

The disc contains 5 distinct language builds to fit the 32 MB EE RAM without wasting memory on unused localization tables:
* **`EN`**: English (Primary matching reference)
* **`FR`**: French (*Français*)
* **`GR`**: German (*Deutsch*)
* **`IT`**: Italian (*Italiano*)
* **`SP`**: Spanish (*Español*)

Each folder contains the main engine ELF and 8 dynamic CodeWarrior overlays (`MWo3`):

### The Main Executable (`AGE2_PS2.ELF`)
* **English Build (`EN/AGE2_PS2.ELF`):** 4,076,904 bytes (SHA-1: `f478e19f2059d52899b691483ef5c7522e30e17c`).
* This binary is copied to `orig/SLES-50282/AOK.ELF` in this repository as the primary matching decompilation target.
* Contains the complete Ensemble Studios Genie Engine: simulation, AI scripts, pathfinding, rendering, tactical combat, network synchronization, and KCET platform adaptation layers.

### CodeWarrior Overlays (`MWo3` Format)
All `.BIN` files in the language folders are **Metrowerks CodeWarrior Overlay version 3** binaries (magic header `MWo3` / `0x4D 0x57 0x6F 0x33`). Overlays allow sections of code and UI data to be paged into EE RAM on demand and evicted when returning to the game simulation:

| Overlay File | EN Size (Bytes) | Role & Responsibilities |
| :--- | :--- | :--- |
| **`SMENU_CD.BIN`** | 92,800 | **Start / Setup Menu:** Main menu UI, campaign selection carousel, scenario browser, system audio/video settings, and player profile configuration. |
| **`HIST_CD.BIN`** | 184,832 | **History & Encyclopedia:** In-game historical database of all civilizations, units, historical battles, and background lore. |
| **`THELP_CD.BIN`** | 71,296 | **Tech Tree & Quick Help:** Interactive technological tree viewer (`btnmain17.shp`) and contextual help screens. |
| **`LOBBY_CD.BIN`** | 458,496 | **Multiplayer Lobby:** Network room creation, player slot management, host/peer negotiations, and network buffer serialization (`ps2_DataTrans`). |
| **`MULTIMCD.BIN`** | 83,712 | **Multimedia Player:** Campaign briefing slides, narrative text scrollers, and voiceover synchronization. |
| **`DCOMP_CD.BIN`** | 44,160 | **Random Map Decompressor & Generator:** RMS script interpreter (executes `arabia.rms`, `black_forest.rms`, `baltic.rms`, etc.) and decompression engine. |
| **`RMMMEMCD.BIN`** | 896 | **Random Map Memory Heap:** Dynamic scratchpad memory allocator specifically reserved for map generation calculations. |
| **`MO_OV_CD.BIN`** | 640 | **Movie Overlay:** Synchronization bridge between the active game session and the background PSS video player. |

---

## 6. IOP System & Hardware Drivers (`MODULES/`)

The PlayStation 2 I/O Processor (IOP) is an independent MIPS R3000A core running Sony's modular real-time operating system. All drivers are compiled as `.IRX` (*IOP Relocatable Executable*) modules:

| Module | Size (Bytes) | SHA-1 | Function |
| :--- | :--- | :--- | :--- |
| **`IOPRP23.IMG`** | 230,329 | `71b694b83a60dd55a159981be1ad546740b2efd4` | **IOP Replacement Image:** OS kernel update containing Sony IOP runtime v2.3. |
| **`PADMAN.IRX`** | 43,861 | `7383a8b277d337d4512e38c9288f6c3ce17f9191` | **Controller Manager:** DualShock 2 analog/digital input polling and dual-motor vibration control. |
| **`MCMAN.IRX`** | 90,533 | `3047d914757c2c93d7c711a6135835cc5fa16d7a` | **Memory Card Manager:** Low-level filesystem and Flash memory operations for PS2 8MB Memory Cards. |
| **`MCSERV.IRX`** | 7,353 | `56184eeb1d1a88bb3bb8ba1a88ee787e9e802316` | **Memory Card Service:** High-level RPC service bridging EE save requests to `MCMAN`. |
| **`SIO2MAN.IRX`** | 6,161 | `962451bc044a0559eb4ee8aa7fb78330fc37eb15` | **Serial I/O 2 Manager:** Hardware bus driver controlling controller and memory card ports. |
| **`USBD.IRX`** | 32,601 | `4f3299719ce361515bb64c63286f9f3c7e7b8c87` | **USB Core Driver:** Sony USB 1.1 OHCI host controller driver. |
| **`USBKEYBD.IRX`** | 16,641 | `4322d7bafe579b122ba0a22ffdb1561f95a7dc5a` | **USB Keyboard Driver:** HID keyboard parser (consumed by KCET's `kt_keybd.c`). |
| **`USBMOUSE.IRX`** | 13,255 | `8a20958a74e5033486c873f274cb3bfca5769742` | **USB Mouse Driver:** HID mouse parser for relative motion and buttons (consumed by `kt_mouse.c`). |
| **`USBMLOAD.IRX`** | 13,865 | `4ec6ecb5ea8c853112be8f451f2871302568779b` | **USB Module Loader:** Dynamic module dispatcher for hot-plugged USB peripherals. |
| **`USBMLCNT.IRX`** | 24,347 | `e46304a0e9b9c97b5e80fa9aa07119e7bf33e8a4` | **USB Multi-Controller:** Coordinates simultaneous keyboard and mouse inputs. |
| **`LIBSD.IRX`** | 26,165 | `8bb9e73efb1c7ecdf1f38bf61706ce45b23ea8a6` | **SPU2 Sound Driver:** Low-level synthesizer control, DMA voices, and reverb effects. |
| **`SDRDRV.IRX`** | 6,345 | `2785a855365fb378fe8aebbe86a0665f80bfb9f1` | **Sound Stream Driver:** Streams PCM/ADPCM audio buffers to SPU2 sound memory. |
| **`SDSTR.IRX`** | 34,257 | `8376510f01ba32c028c2cf8a5ba3ebdd1e88863c` | **Sound Streamer:** Manages CD double-buffering for non-blocking music streaming. |
| **`SD_CD.IRX`** | 15,297 | `ba69151ae917ba4d1192e4e10b14798a728b7e21` | **Sound CD Driver:** Optical drive sector reader for audio streams. |
| **`SOUNDCD.IRX`** | 114,669 | `4c0525945199695efae0062a42617f694e99f6ba` | **KCET Sound Engine:** High-level music/voice scheduler and volume mixer. |
| **`ATAD.IRX`** | 11,781 | `0014e30097d64dd24346e9dfd9ea026e63c0a599` | **ATA Disk Driver:** Hardware ATA/IDE interface for the internal PS2 HDD. |
| **`DEV9.IRX`** | 9,197 | `fbaf298e8f81014ccceea84587bf2b12bf8b98e7` | **Expansion Bay Driver:** Controls power and bus lines for the Network Adapter & HDD unit. |
| **`HDD.IRX`** | 30,101 | `4e1950d995c8ba7ebae54d4ff78aa787e95aaec1` | **Hard Disk Manager:** Partition manager and sector caching for PS2 HDD. |
| **`PFS.IRX`** | 49,609 | `b41196fb1ca5e83ecfdf55f32ebfec87be3381e4` | **PlayStation File System:** High-level filesystem driver allowing `ALL_DATA.BIN` caching. |
| **`NETCNF.IRX`** | 56,037 | `4bf6e729a6a8cb1e3ff2d9d95f877ca647087814` | **Sony Network Config:** Parses network settings created by the PS2 Network Access Disc. |
| **`KTNETCNF.IRX`**| 23,452 | `1fdfb0d46d03d00122e0388482ee20c5765c7195` | **KCET Network Config:** Game-specific network profile adapter and Memory Card reader. |

---

## 7. Network & Multiplayer IOP Modules (`MODULES2/`)

The `MODULES2/` directory houses the TCP/IP stack, dial-up modem drivers, and FireWire (i.LINK) networking code:

| Module | Size (Bytes) | SHA-1 | Function |
| :--- | :--- | :--- | :--- |
| **`SMAP.IRX`** | 15,249 | `a108a95610664ee6dd68779c138dcf16f059cb21` | **Ethernet MAC Driver:** Driver for the 10/100 Ethernet controller on the PS2 Network Adapter (`SPEED` chip). |
| **`AVETCP.IRX`** | 190,432 | `9d554a9f39d736a6e7c7a36c781d459048a17688` | **TCP/IP Protocol Stack:** Full IPv4 network protocol implementation (TCP, UDP, ICMP, ARP). |
| **`AVEDHCP.IRX`** | 29,148 | `72b1a37c9431e7f677fbca49514e8674d8dd8f4a` | **DHCP Client:** Automated dynamic IP and DNS assignment. |
| **`AVEPPP.IRX`** | 150,210 | `6baefc0840c885bb400d984cfb776ec852445e99` | **PPP / PPPoE Driver:** Point-to-Point Protocol for dial-up modem connections and DSL setups. |
| **`BSDSOCKI.IRX`** | 32,793 | `5f0611a149b1ff53f53ae838ae455a5b512c1fa0` | **BSD Sockets:** Standard POSIX socket API (`socket`, `bind`, `connect`, `send`, `recv`). |
| **`CXTMDM.IRX`** | 74,500 | `f28a3952ba67c8dc9366df287b4042898c199859` | **Conexant Modem Driver:** Hardware driver for official Conexant-based dial-up modems. |
| **`OMMODEM.IRX`** | 40,915 | `1005a74e5ce620da4735ddaa26fb0360a6cb75b7` | **Optical / Alternate Modem Driver:** Supplementary modem chipset interface. |
| **`OSTMDM_A.IRX`**| 32,585 | `27dd60f9a7442fc84f7678502f90dcfc4ec4d57c` | **Software Modem Driver:** Host-based software modem signal processor. |
| **`NDGLUE.IRX`** | 30,451 | `a65cfdd79555cfb5d7d4c8dbb5cc019316b23a9a` | **Network Driver Glue Layer:** Bridges the hardware MAC drivers (`SMAP`, modems) into `AVETCP`. |
| **`ILINK.IRX`** | 141,493 | `45187e83bc2e2a04e54e48b8772a50a18413bcae` | **i.LINK Driver:** IEEE 1394 FireWire protocol stack for peer-to-peer console linking. |
| **`ILSOCK.IRX`** | 14,953 | `5d6d3c9077e60b29c9ccba9509f6e076774e505d` | **i.LINK Sockets:** Datagram and stream socket abstraction over the IEEE 1394 cable. |
| **`ILINT.IRX`** | 15,558 | `cb8b5ea91ee4c6326129849206d99787ffc5c2d3` | **i.LINK Interrupt Handler:** Low-latency DMA interrupt service routine for FireWire packets. |

---

## 8. Complete 85-File Disc Manifest

The complete list of all 85 files verified against retail media hash `77a9cec2083a7c3d82518b3ae47371b55ec2e7ce`:

| Path | Size (Bytes) | Timestamp | SHA-1 |
| :--- | :--- | :--- | :--- |
| `SYSTEM.CNF` | 56 | 2002-04-14 01:31:20 | `263ce23a419846b0a701833d7b8d8ecb1bc309e4` |
| `SLES_502.82` | 1,593,256 | 2002-04-26 02:34:30 | `2f5139c1cb45c6b22b93e0c32bbea8e94a7b4a5f` |
| `ALL_DATA.BIN` | 93,636,608 | 2002-04-10 01:46:40 | `ea17dae27f428c9ce4464d6db870845bf3bbffac` |
| `DATA.CAT` | 207,900,672 | 2001-06-01 03:12:52 | `3f48a8eb543fbe0642fa602a8eb51f33f6fb38d3` |
| `PPS_PAL/ESLOGO_2.PSS` | 18,382,852 | 2001-05-28 08:59:12 | `4dbe202e811c7501a3ea36c84b1d6e0687702816` |
| `PPS_PAL/AGE2_2.PSS` | 113,967,108 | 2001-05-28 10:08:56 | `784b1fba50bfdb3235b2e38cce8ae13d333ae47e` |
| `PPS_PAL/MSLOGO_2.PSS` | 14,499,844 | 2001-05-28 09:01:28 | `86ca9986b24d9c7921c81ef442878bfce9dfba88` |
| `EN/AGE2_PS2.ELF` | 4,076,904 | 2002-04-26 02:54:18 | `f478e19f2059d52899b691483ef5c7522e30e17c` |
| `EN/DCOMP_CD.BIN` | 44,160 | 2002-04-26 02:54:18 | `26ff64132db85ae431b3bf1f08e5c467a35368a4` |
| `EN/HIST_CD.BIN` | 184,832 | 2002-04-26 02:54:18 | `519890ee388cf6a27e7f9ff3a0352ef29d1c1cf6` |
| `EN/LOBBY_CD.BIN` | 458,496 | 2002-04-26 02:54:18 | `981440263f350c76db394142ba152ec935a8f4c2` |
| `EN/MO_OV_CD.BIN` | 640 | 2002-04-26 02:54:18 | `d228f413d33dbce4731c51829e2c4ff4529dbf17` |
| `EN/MULTIMCD.BIN` | 83,712 | 2002-04-26 02:54:18 | `89d53fef1e50588147d33eb43c9dd20485a3c27e` |
| `EN/RMMMEMCD.BIN` | 896 | 2002-04-26 02:54:18 | `9b26503c5d7df9d1be750eeb557c6bfe0f82df99` |
| `EN/SMENU_CD.BIN` | 92,800 | 2002-04-26 02:54:18 | `5fb1616ffb3c06674e2be005cbbf007ce468ee6b` |
| `EN/THELP_CD.BIN` | 71,296 | 2002-04-26 02:54:18 | `13a772da3cf6326e479c78fe2331570eb7a64188` |
| `FR/AGE2_PS2.ELF` | 4,119,528 | 2002-04-26 03:09:26 | `d4e5f2cf01ce355bb062a498263eb2125bb7c405` |
| `FR/DCOMP_CD.BIN` | 44,160 | 2002-04-26 03:09:26 | `1f33f6b70ff9ba42ae72d422a59a7ee7b2c0f1e0` |
| `FR/HIST_CD.BIN` | 225,920 | 2002-04-26 03:09:26 | `7eb098e9c60e5db997b6fa72d627344e13ec8bb9` |
| `FR/LOBBY_CD.BIN` | 458,496 | 2002-04-26 03:09:26 | `c03dfd8eb1a473b6aa4cf1e2bf65d83be1267425` |
| `FR/MO_OV_CD.BIN` | 640 | 2002-04-26 03:09:26 | `4482062638890db70ce04ec3baee290378034db3` |
| `FR/MULTIMCD.BIN` | 90,240 | 2002-04-26 03:09:26 | `db9661c94474320295da9beaa2aa4a8f95c52c17` |
| `FR/RMMMEMCD.BIN` | 896 | 2002-04-26 03:09:26 | `ce9c3b8782a20a463a89a08e08678d8c2837bc21` |
| `FR/SMENU_CD.BIN` | 93,056 | 2002-04-26 03:09:26 | `fcae475df8a5a4eafe323204df772274431f0cf8` |
| `FR/THELP_CD.BIN` | 71,296 | 2002-04-26 03:09:26 | `3bf8ae677ebecf9643d9b0f025e160a2b53df4e7` |
| `GR/AGE2_PS2.ELF` | 4,123,496 | 2002-04-26 03:21:26 | `0fa02049ba3ecda66144e59f485db694b29bb374` |
| `GR/DCOMP_CD.BIN` | 44,160 | 2002-04-26 03:21:26 | `799ca9a101b0b7593c6be1e99650d37e6da80536` |
| `GR/HIST_CD.BIN` | 225,792 | 2002-04-26 03:21:26 | `0aa974bfa0525ee2f2549d4ce5e71415664db6e5` |
| `GR/LOBBY_CD.BIN` | 458,496 | 2002-04-26 03:21:26 | `b05d15ca1cf4344403164996fb28464fc8b975c7` |
| `GR/MO_OV_CD.BIN` | 640 | 2002-04-26 03:21:26 | `5d3ce446dbe6e47457cb146a4e3fa3f5cf7bf1dc` |
| `GR/MULTIMCD.BIN` | 92,800 | 2002-04-26 03:21:26 | `39f3ae2128ae3445853b0e353c983ffefd376ca3` |
| `GR/RMMMEMCD.BIN` | 896 | 2002-04-26 03:21:26 | `ca44b20468ea92c906660429f44b2f4f22c83ba0` |
| `GR/SMENU_CD.BIN` | 92,928 | 2002-04-26 03:21:26 | `c4ea5b42d593006a24bebb75aa08953906a27e77` |
| `GR/THELP_CD.BIN` | 71,296 | 2002-04-26 03:21:26 | `a492fb86c7707eeeb5eb2e3ea8667a140a33a39e` |
| `IT/AGE2_PS2.ELF` | 4,123,880 | 2002-04-26 03:34:24 | `1fce7262d47aa7d6205739097e0ddaf437812ec5` |
| `IT/DCOMP_CD.BIN` | 44,160 | 2002-04-26 03:34:24 | `3ecf34638aa63f82e8e91845bb08a1fa96637b58` |
| `IT/HIST_CD.BIN` | 215,552 | 2002-04-26 03:34:24 | `3c092403982e5ee6f59b951c143ffea322e7240c` |
| `IT/LOBBY_CD.BIN` | 458,496 | 2002-04-26 03:34:24 | `ebc993dd2a4f4d2f8384666fcce6ee1a686fb84e` |
| `IT/MO_OV_CD.BIN` | 640 | 2002-04-26 03:34:24 | `47c0bcf8bc321c1fcf8f0f5b9d7cb57640428d09` |
| `IT/MULTIMCD.BIN` | 88,576 | 2002-04-26 03:34:24 | `f59795029ebf77f2d59188f6b0fca7a8c3d79f04` |
| `IT/RMMMEMCD.BIN` | 896 | 2002-04-26 03:34:24 | `8be481fc797f1da69d675b871c53d0628e83c27e` |
| `IT/SMENU_CD.BIN` | 93,056 | 2002-04-26 03:34:24 | `b7835848bbdc0f367e9142f1cf44dd8dbf4ef937` |
| `IT/THELP_CD.BIN` | 71,296 | 2002-04-26 03:34:24 | `2a84fc2e4aee7ce9ca3fa09ce03e7a08b53df4ec` |
| `SP/AGE2_PS2.ELF` | 4,112,232 | 2002-04-26 04:06:22 | `b9f5f08ca672f066b1a77761019cf399aa4da8fa` |
| `SP/DCOMP_CD.BIN` | 44,160 | 2002-04-26 04:06:22 | `b999fa4d0b17e4f165a2d04a62e0c52bb881b51e` |
| `SP/HIST_CD.BIN` | 213,376 | 2002-04-26 04:06:22 | `cbe3170b991b1574a4ff4bb0b1a0e1075d5b78b5` |
| `SP/LOBBY_CD.BIN` | 458,496 | 2002-04-26 04:06:22 | `a90c6ca8376ff3bcfa6fb022b724cc6f600f6bca` |
| `SP/MO_OV_CD.BIN` | 640 | 2002-04-26 04:06:22 | `c486ad93214e4431f471b694b918f67e58a2e37e` |
| `SP/MULTIMCD.BIN` | 87,936 | 2002-04-26 04:06:22 | `25bc121087265a712f5aeeefd9dbd637782488a0` |
| `SP/RMMMEMCD.BIN` | 896 | 2002-04-26 04:06:22 | `8c1cfd674176461c2105e1fc163353c7eb1c545e` |
| `SP/SMENU_CD.BIN` | 93,056 | 2002-04-26 04:06:22 | `e2a4fa9f658f86f780e1b9b5f922fc5723b7a8ad` |
| `SP/THELP_CD.BIN` | 71,296 | 2002-04-26 04:06:22 | `e46ca1bf236e78ba7a5a3a789ae65d956fceba14` |
| `MODULES/ATAD.IRX` | 11,781 | 2001-07-04 23:07:00 | `0014e30097d64dd24346e9dfd9ea026e63c0a599` |
| `MODULES/DEV9.IRX` | 9,197 | 2001-07-04 23:07:00 | `fbaf298e8f81014ccceea84587bf2b12bf8b98e7` |
| `MODULES/HDD.IRX` | 30,101 | 2001-07-04 23:07:00 | `4e1950d995c8ba7ebae54d4ff78aa787e95aaec1` |
| `MODULES/KTNETCNF.IRX` | 23,452 | 2001-06-18 02:44:02 | `1fdfb0d46d03d00122e0388482ee20c5765c7195` |
| `MODULES/LIBSD.IRX` | 26,165 | 2001-06-18 02:44:02 | `8bb9e73efb1c7ecdf1f38bf61706ce45b23ea8a6` |
| `MODULES/MCMAN.IRX` | 90,533 | 2001-07-04 23:07:00 | `3047d914757c2c93d7c711a6135835cc5fa16d7a` |
| `MODULES/MCSERV.IRX` | 7,353 | 2001-07-04 23:07:00 | `56184eeb1d1a88bb3bb8ba1a88ee787e9e802316` |
| `MODULES/NETCNF.IRX` | 56,037 | 2001-07-02 08:00:22 | `4bf6e729a6a8cb1e3ff2d9d95f877ca647087814` |
| `MODULES/PADMAN.IRX` | 43,861 | 2001-06-18 02:44:02 | `7383a8b277d337d4512e38c9288f6c3ce17f9191` |
| `MODULES/PFS.IRX` | 49,609 | 2001-07-04 23:07:02 | `b41196fb1ca5e83ecfdf55f32ebfec87be3381e4` |
| `MODULES/SDRDRV.IRX` | 6,345 | 2001-06-18 02:44:02 | `2785a855365fb378fe8aebbe86a0665f80bfb9f1` |
| `MODULES/SDSTR.IRX` | 34,257 | 2001-07-02 07:58:16 | `8376510f01ba32c028c2cf8a5ba3ebdd1e88863c` |
| `MODULES/SD_CD.IRX` | 15,297 | 2001-07-02 07:58:16 | `ba69151ae917ba4d1192e4e10b14798a728b7e21` |
| `MODULES/SIO2MAN.IRX` | 6,161 | 2001-06-18 02:44:02 | `962451bc044a0559eb4ee8aa7fb78330fc37eb15` |
| `MODULES/SOUNDCD.IRX` | 114,669 | 2001-09-08 04:32:10 | `4c0525945199695efae0062a42617f694e99f6ba` |
| `MODULES/USBD.IRX` | 32,601 | 2001-06-18 02:44:04 | `4f3299719ce361515bb64c63286f9f3c7e7b8c87` |
| `MODULES/USBKEYBD.IRX` | 16,641 | 2001-10-31 07:10:30 | `4322d7bafe579b122ba0a22ffdb1561f95a7dc5a` |
| `MODULES/USBMLCNT.IRX` | 24,347 | 2001-11-09 06:10:54 | `e46304a0e9b9c97b5e80fa9aa07119e7bf33e8a4` |
| `MODULES/USBMLOAD.IRX` | 13,865 | 2001-05-28 04:51:16 | `4ec6ecb5ea8c853112be8f451f2871302568779b` |
| `MODULES/USBMOUSE.IRX` | 13,255 | 2001-10-31 07:10:08 | `8a20958a74e5033486c873f274cb3bfca5769742` |
| `MODULES/IOPRP23.IMG` | 230,329 | 2001-05-28 09:06:06 | `71b694b83a60dd55a159981be1ad546740b2efd4` |
| `MODULES2/AVEDHCP.IRX` | 29,148 | 2001-03-01 05:15:04 | `72b1a37c9431e7f677fbca49514e8674d8dd8f4a` |
| `MODULES2/AVEPPP.IRX` | 150,210 | 2001-10-05 09:46:34 | `6baefc0840c885bb400d984cfb776ec852445e99` |
| `MODULES2/AVETCP.IRX` | 190,432 | 2001-06-23 06:01:58 | `9d554a9f39d736a6e7c7a36c781d459048a17688` |
| `MODULES2/BSDSOCKI.IRX` | 32,793 | 2001-10-14 22:07:28 | `5f0611a149b1ff53f53ae838ae455a5b512c1fa0` |
| `MODULES2/CXTMDM.IRX` | 74,500 | 2001-04-04 07:10:08 | `f28a3952ba67c8dc9366df287b4042898c199859` |
| `MODULES2/NDGLUE.IRX` | 30,451 | 2001-10-05 02:56:10 | `a65cfdd79555cfb5d7d4c8dbb5cc019316b23a9a` |
| `MODULES2/OMMODEM.IRX` | 40,915 | 2001-08-23 07:37:42 | `1005a74e5ce620da4735ddaa26fb0360a6cb75b7` |
| `MODULES2/OSTMDM_A.IRX`| 32,585 | 2001-08-23 06:51:44 | `27dd60f9a7442fc84f7678502f90dcfc4ec4d57c` |
| `MODULES2/SMAP.IRX` | 15,249 | 2001-08-01 23:34:52 | `a108a95610664ee6dd68779c138dcf16f059cb21` |
| `MODULES2/ILINT.IRX` | 15,558 | 2001-07-24 06:43:44 | `cb8b5ea91ee4c6326129849206d99787ffc5c2d3` |
| `MODULES2/ILINK.IRX` | 141,493 | 2001-05-28 04:51:16 | `45187e83bc2e2a04e54e48b8772a50a18413bcae` |
| `MODULES2/ILSOCK.IRX` | 14,953 | 2001-05-28 04:51:16 | `5d6d3c9077e60b29c9ccba9509f6e076774e505d` |
