# PS2 Library Code Map: SLES-50282

This inventory records third-party code that can be bounded with the available
stripped PAL ELF. It intentionally separates identified code ranges from SDK
version strings: a library tag proves that a library version was linked, but
not where its code resides.

## Scope and measurement

The file-backed `LOAD` range is file offsets `0x1e0–0x3e31c0`, mapped to VMA
`0x100000–0x4e2fe0`, for 4,075,488 bytes. The ELF has no usable `.text` section
or symbols, so this is a load-range denominator rather than a verified pure
code-section size. File offset converts to VMA as `offset + 0xffe20`.

The only third-party code currently bounded with defensible routine boundaries
is a set of Metrowerks MSL C runtime routines. The displayed sizes are the exact
address spans configured as named `asm` analysis targets, not decompiled C/C++
implementations; no MSL or Sony library routines are registered as matched objects.

| Library / routine | VMA range (end exclusive) | File-offset range (end exclusive) | Size | Evidence | Confidence |
|---|---:|---:|---:|---|---|
| Metrowerks MSL `atoi` | `0x114378–0x1143a0` | `0x14558–0x14580` | 40 B | Decimal-conversion wrapper calling the shared base-10 conversion routine; its callers use it as `atoi`. | High for routine identity; medium for exact MSL source provenance |
| Metrowerks MSL `atol` | `0x1143a0–0x1143c0` | `0x14580–0x145a0` | 32 B | Adjacent signed-long conversion wrapper calling the same base-10 conversion routine. | High for routine identity; medium for exact MSL source provenance |
| Metrowerks MSL `memset` | `0x117cac–0x117d70` | `0x17e8c–0x17f50` | 196 B | Existing `memset` label, recognizable fill loop, and numerous game call sites. | High |
| Metrowerks MSL `qsort` | `0x118e30–0x119858` | `0x19010–0x19a38` | 2,600 B | Sorting implementation called with game comparator functions, including the trade-route score comparator. | High for routine identity; medium for exact MSL source provenance |
| Metrowerks MSL `srand` | `0x119858–0x119868` | `0x19a38–0x19a48` | 16 B | Seeds the state used by the adjacent pseudo-random generator. | Medium |
| Metrowerks MSL `rand` | `0x119868–0x119898` | `0x19a48–0x19a78` | 48 B | Updates and returns the adjacent pseudo-random generator state. | Medium |
| Metrowerks MSL `strcat` | `0x11a7bc–0x11a8e8` | `0x1a99c–0x1aac8` | 300 B | Recognizable string concatenation loop, including a call to the copy routine. | High for routine identity; medium for exact MSL source provenance |
| Metrowerks MSL `strcmp` | `0x11aa78–0x11abbc` | `0x1ac58–0x1ad9c` | 324 B | Byte-wise string comparison and difference return. | High for routine identity; medium for exact MSL source provenance |
| Metrowerks MSL `strcpy` | `0x11abbc–0x11acd0` | `0x1ad9c–0x1aeb0` | 276 B | Null-terminated byte copy loop. | High for routine identity; medium for exact MSL source provenance |
| **Identified MSL code lower bound** | | | **3,832 B** | Sum of the bounded routines above. | **High that these ranges are identified; not a full library total** |

The identified routines account for **0.0940%** of the 4,075,488-byte
file-backed range. Subtracting those bytes leaves **4,071,656 bytes (99.9060%)
not assigned by this inventory**. That residual is not a game-code measurement:
it includes game and KCET code, unbounded third-party code, file-backed data,
and any other unclassified content. Accordingly, the current evidence cannot
support an exact total for third-party code or an exact number of bytes still
to decompile as game code.

## Sony SDK and middleware evidence

The ELF contains the following embedded Sony SDK version tags. The file offsets
and corresponding VMAs identify strings only; they are not code ranges and are
excluded from the 3,832-byte code total.

| Sony module | Version tag | File offset | VMA | What the evidence establishes |
|---|---:|---:|---:|---|
| `libgraph` | `2300` | `0x289d50` | `0x389b70` | Sony Graphics library version string is linked in the ELF. |
| `libdma` | `2300` | `0x289dc0` | `0x389be0` | Sony DMA library version string is linked in the ELF. |
| `libkernl` | `2300` | `0x289e3c` | `0x389c5c` | Sony kernel library version string is linked in the ELF. |
| `libpad` | `2300` | `0x28a6c0` | `0x38a5e0` | Sony pad library version string is linked in the ELF. |
| `libcdvd` | `2300` | `0x28a720` | `0x38a640` | Sony CD/DVD library version string is linked in the ELF. |
| `libmc` | `2320` | `0x28c190` | `0x38bfb0` | Sony memory-card library version string is linked in the ELF. |
| `libscf` | `2300` | `0x38d310` | `0x48d130` | Sony system-configuration library version string is linked in the ELF. |

Other strings include C++ exception diagnostics, `libsd.irx`, and an MpegTV
copyright notice. These identify runtime, IOP-module, or middleware references
but do not delimit EE code. No reliable Sony SDK, MSL exception/stdio, or
middleware code boundaries have been established from the available symbols,
strings, and disassembly. Those areas remain unmeasured rather than being
misclassified as game code.

## Configuration and progress tracking

`config/SLES-50282/config.yml` marks the nine bounded MSL routines as named
`asm` analysis targets, and `config/SLES-50282/symbols.txt` records their labels
and the Sony SDK version-string labels. Intervening unknown bytes remain binary
segments. These targets generate original-side disassembly for analysis, not
C/C++ implementations or matched library objects. Generated analysis assembly
does not count as decompilation progress. Sony SDK tags are symbol labels only
because no trustworthy module code spans are known. The
existing `libs` progress category is object-based; library splits are not
registered as matched objects and therefore do not increase game-match progress.
