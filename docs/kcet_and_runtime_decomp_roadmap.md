# Roadmap: 100% Decompilation of KCET & Metrowerks Runtime (MSL)

Strategic plan to achieve 100% matching decompilation of the **Konami Computer Entertainment Tokyo (KCET)** hardware abstraction layer and the **Metrowerks Standard Library (MSL)** C runtime in *Age of Empires II: The Age of Kings* (PlayStation 2 PAL, `SLES-50282`).

---

## 1. Executive Summary & Strategy

The executable image `orig/SLES-50282/AOK.ELF` contains approximately **2,661,232 bytes (~2.66 MB)** of executable machine code (`.text`). Analysis shows that **between 318 KiB and 393 KiB (~12% to 15%)** of this code belongs to standardized third-party runtimes and platform abstraction layers:

```
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                        AOK.ELF Total Executable Code (~2.66 MB)                        │
├────────────────────────────────┬───────────────────────────────────────────────────────┤
│  Third-Party / Platform (15%)  │            Genie Engine Core (Ensemble Studios) (85%) │
│  ~393 KiB                      │            ~2,268 KiB                                 │
│  ├─ Metrowerks MSL (~150 KiB)  │            ├─ Unit & Building State Machines          │
│  ├─ Sony PS2 SDK   (~168 KiB)  │            ├─ Pathfinding & Zone Spatial Grids        │
│  └─ KCET Hardware  (~75 KiB)   │            └─ Combat & Tactical AI Controllers        │
└────────────────────────────────┴───────────────────────────────────────────────────────┘
```

By prioritizing the **Metrowerks Standard Library (MSL)** first, followed immediately by the **KCET Hardware Layer**, we establish a 100% matched platform and runtime foundation that unblocks clean compilation and linking for all game engine code.

---

## 2. Phase 1: Metrowerks MSL C Runtime (Sprint 2)

### 2.1 Scope and Provenance
The Metrowerks Standard Library for MIPS/PS2 (`0x00100000` – `0x00125000`) provides standard C library (libc), math routines (libm), and C++ runtime support (`crt0.s`, array constructors/destructors, pure virtual handlers).

The original source code for these routines is public and standard across Metrowerks CodeWarrior distributions for MIPS. Slices are already bounded in [`config/SLES-50282/config.yml`](../config/SLES-50282/config.yml):

| Target | VMA Range | Extent | Responsibilities & Public Provenance |
|---|---|---|---|
| `msl/atoi.c` | `0x114378` – `0x1143A0` | 40 B | Base-10 integer string conversion via `strtol` |
| `msl/atol.c` | `0x1143A0` – `0x1143C0` | 32 B | Signed long string conversion via `strtol` |
| `msl/rand.c` | `0x119868` – `0x119898` | 48 B | Linear congruential generator (`1103515245 * seed + 12345`) |
| `msl/srand.c` | `0x119858` – `0x119868` | 16 B | Random seed setter at `context + 0x58` |
| `msl/strcat.c` | `0x11A7BC` – `0x11A8E8` | 300 B | String concatenation with tail copy call |
| `msl/strcmp.c` | `0x11AA78` – `0x11ABBC` | 324 B | Lexicographical unsigned char byte comparison |
| `msl/strcpy.c` | `0x11ABBC` – `0x11ACD0` | 276 B | Null-terminated byte copy loop |
| `msl/memset.c` | `0x117CAC` – `0x117D70` | 196 B | Word-aligned block fill |
| `msl/qsort.c` | `0x118E30` – `0x119858` | 2,600 B | Quick sort algorithm with median-of-three pivot selection |
| **Initial MSL Batch** | | **3,832 B** | **100% matching target for Phase 1** |

### 2.2 Toolchain & Configuration
- **Compiler:** Metrowerks CodeWarrior for PlayStation 2 (`compilers/PS2/mwcc-2.3.1.01/mwccps2.exe`).
- **Flags:** `-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c`.
- **Target Library in `configure.py`:**
  ```python
  {
      "lib": "msl",
      "objects": [
          Object(Matching, "msl/atoi", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/atol", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/rand", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/srand", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/strcat", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/strcmp", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/strcpy", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/memset", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
          Object(Matching, "msl/qsort", cflags=["-O3", "-inline", "on", "-lang=c", "-Iinclude"], toolchain_version="PS2/mwcc-2.3.1.01"),
      ],
  }
  ```

---

## 3. Phase 2: KCET Hardware Layer 100% Decompilation (Sprint 1)

### 3.1 Overview & Architecture
The KCET subsystem occupies a contiguous block from `0x00125800` to `0x00137800` (~73 KiB) plus `libscf.c` (~2 KiB). It is written in pure ANSI C and compiled with Sony EE-GCC.

Three modules are already **100.0% matching**:
- [`src/kt_mouse.c`](../src/kt_mouse.c): 45 / 45 functions (4,312 B) — **100% MATCH**
- [`src/kt_keybd.c`](../src/kt_keybd.c): 36 / 36 functions (4,936 B) — **100% MATCH**
- [`src/kt_usbkeybd_drv.c`](../src/kt_usbkeybd_drv.c): 6 / 6 functions (628 B) — **100% MATCH**

### 3.2 Remaining Modules to Achieve 100% KCET Completion:

| Module | VRAM Range | Extent | Target Responsibilities & Evidence | Status |
|---|---|---|---|---|
| **`kt_gpu.c`** | `0x00125800` – `0x00125C34` | ~1.1 KiB | Graphics Synthesizer frame sync, display mode config (`kind < numberof(func_list)`) | Pending split |
| **`kt_libpad.c`** | `0x00125C38` – `0x00128BA4` | ~11.9 KiB | DualShock 2 analog/digital pad polling, actuator vibration (`n_pad > 0`) | Pending split |
| **`kt_hd.c`** | `0x00128BA8` – `0x001295FC` | ~2.6 KiB | PS2 TOOL dev filesystem interface (`host0:`, `sim:`, `atfile:`) | Pending split |
| **`kt_libcdvd_server.c`** | `0x00129600` – `0x0012BDF8` | ~9.8 KiB | CD/DVD RPC server, disc read streaming, tray detect (`ktSceCdInitMmode`) | Pending split |
| **`kt_file.c`** | `0x0012CC00` – `0x0012DBFC` | ~4.0 KiB | Unified file descriptor layer wrapping CDVD and dev filesystems | Pending split |
| **`kt_mc_2.c`** | `0x0012DC00` – `0x001340FC` | ~25.2 KiB | PlayStation 2 Memory Card file save/load/format manager (`ktMcInit2`) | Pending split |
| **`kt_kernel.c`** | `0x00134100` – `0x001347FC` | ~1.8 KiB | EE kernel thread creation, semaphores, synchronization (`SignalSema`) | Pending split |
| **`socketee.c`** | `0x00337520` – `0x00337840` | ~3.2 KiB | EE Sockets i.LINK / SCE network RPC | 80% Matched |
| **`libscf.c`** | `0x00389580` – `0x00389B60` | ~1.5 KiB | Sony PS2 system configuration, language & timezone query | Pending split |

### 3.3 Toolchain & Flags
- **Compiler:** Sony PS2 SDK 1.6.5 EE-GCC 2.9-991111 (`compilers/PS2/ee-gcc2.9-991111`).
- **Flags:** `-O2 -G0 -Iinclude` (MIPS 64-bit EABI register conventions).

---

## 4. Phase 3: Sony Official PS2 SDK Mapping (~168 KiB)

The top of the executable image (`0x00360000` – `0x00389B70`) contains compiled static archives from Sony Computer Entertainment:
- `libgraph.a` (version `2300` at `0x389B70`)
- `libdma.a` (version `2300` at `0x389BE0`)
- `libkernl.a` (version `2300` at `0x389C5C`)
- `libpad.a` (version `2300` at `0x38A5E0`)
- `libcdvd.a` (version `2300` at `0x38A640`)
- `libmc.a` (version `2320` at `0x38BFB0`)

These are vendor static libraries. Once identified and bounded, they can be matched directly against the official static objects rather than manually decompiled, immediately claiming ~168 KiB of 100% matching.

---

## 5. Execution Workflow & Acceptance Gates

For every unit in Phase 1 (MSL) and Phase 2 (KCET):
1. **Red (TDD):** Native unit test (`tests/native/msl_*_test.c` or pytest) asserting functional equivalence before implementation.
2. **Green (C Implementation):** Implement in `src/msl/*.c` or `src/kt_*.c` to pass native behavior tests.
3. **Refactor & Binary Matching:** Compile with respective toolchain (`mwccps2` for MSL, `ee-gcc` for KCET) until byte-exact match (`objdiff` 100.0%).
4. **Registration:** Promote from `NonMatching` to `Matching` in [`configure.py`](../configure.py) and update [`config.yml`](../config/SLES-50282/config.yml).
5. **Regression Verification:** Run full test suite (`ninja -n`, native harness, pytest) cleanly.
