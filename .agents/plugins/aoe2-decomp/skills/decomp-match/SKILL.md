---
name: decomp-match
description: Guide and workflow for configuring targets, running ninja matching builds, and verifying binary parity with objdiff.
---

# decomp-match

Use this skill when matching decompiled C/C++ routines against target binaries for Age of Empires II (PC and PS2).

## 1. Configure Target Binary

Run `configure.py` for the desired target edition:

```sh
# For PS2 PAL (Primary)
.venv/bin/python configure.py --version SLES-50282 --compilers <DIR>

# For PC The Conquerors 1.0c (Primary)
.venv/bin/python configure.py --version AGE2_X1_1_0C_EN --compilers <DIR>
```

This verifies the original binary sha1 checksum and generates `build.ninja` and `objdiff.json`.

## 2. Compile and Check Matching

Compile registered objects using Ninja:

```sh
# Build target objects
ninja

# Dry-run check
ninja -n
```

## 3. Objdiff Parity Iteration

1. Inspect assembly differences using `objdiff` (CLI or web UI).
2. Adjust register allocation patterns, loop constructs, variable order, and types in C/C++.
3. Avoid inline assembly hacks: CodeWarrior PS2 uses Metrowerks MIPS compiler heuristics (look for register scheduling, signed vs unsigned comparisons, and temp variables).
4. Verify that binary matching percentage increases or remains 100% without breaking behavioral tests.
