---
name: decomp-tdd
description: Execute mandatory Red-Green-Refactor test-driven development and native 32-bit behavioral regression tests using pytest or Docker.
---

# decomp-tdd

Use this skill when developing a new decompiled function, modifying behavior, or fixing bugs in this repository.

## Mandatory TDD Workflow

1. **Red Gate:**
   - Create or locate the behavioral test in `tests/test_*.py` and `tests/native/*_test.cpp`.
   - Run the test against the current codebase:
     ```sh
     pytest -q -ra tests/<test_module>.py
     ```
   - Confirm and record the expected failure assertion. A compilation error or missing tool is a blocker, not a Red test evidence.

2. **Green Gate:**
   - Implement only the C/C++ logic required to satisfy the failing assertion.
   - Run the test again and verify it passes cleanly.

3. **Refactor Gate:**
   - Clean up code, add fixed-width types (`u8`, `u16`, `u32`, `s32`, `GuestAddr`), add layout assertions (`_Static_assert`), and format with `.clang-format`.
   - Verify that all tests remain green.

4. **Regression Gate:**
   - Run the full subsystem tests and all affected test suites.
   - When running in Docker environment (standard isolated test environment):
     ```sh
     docker --context docker-dev run --rm \
       -e TZ=America/Sao_Paulo \
       --mount "type=bind,source=$(pwd),target=/workspace" \
       aoe-tests:verification python -m pytest -q -ra
     ```
