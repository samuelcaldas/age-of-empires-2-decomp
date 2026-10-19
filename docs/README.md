# Documentation index

Start with the top-level [README](../README.md).

- [testing.md](testing.md): mandatory TDD workflow, Docker test commands, and regression completion evidence
- [game_files.md](game_files.md): where each original file comes from, how to extract it, and how to verify it
- [ps2_binary_analysis.md](ps2_binary_analysis.md): disc architecture, Metrowerks compiler, debug strings, and source files discovered in the PS2 binary
- [ps2_library_map.md](ps2_library_map.md): bounded third-party runtime routines and Sony SDK version markers in the PAL ELF
- [toolchain.md](toolchain.md): compilers, how to identify them from the binaries, and what is still unverified
- [elevation_mesh_serializer_328020.md](elevation_mesh_serializer_328020.md): pure-C++ serializer at `0x328020`, 224-byte exact MWCC match, ordered-write contracts, and real mutation tests
- [trade_action_route_finish.md](trade_action_route_finish.md): exact route-buffer reconstruction, corrected ELF mapping, and regression validation
- [trade_action_helpers_217840.md](trade_action_helpers_217840.md): eight independent trade-action setters, callback behavior, and native regression coverage
- [trade_action_helper_218350.md](trade_action_helper_218350.md): reconstructed helper, exact original code/padding boundary, isolated build comparison, and seven-case native contracts
- [trade_action_helper_21DBE0.md](trade_action_helper_21DBE0.md): binary analysis, ELF disassembly trace, and native test contracts for trade action helper 0x21DBE0
- [trade_action_helper_21DC50.md](trade_action_helper_21DC50.md): binary analysis, ELF disassembly trace, and native test contracts for trade action helper 0x21DC50
- [trade_action_helper_21DCA0.md](trade_action_helper_21DCA0.md): binary analysis, ELF disassembly trace, and native test contracts for trade action helper 0x21DCA0
- [trade_action_helper_21DD10.md](trade_action_helper_21DD10.md): binary analysis, ELF disassembly trace, and native test contracts for trade action helper 0x21DD10
- [trade_action_helper_21DE20.md](trade_action_helper_21DE20.md): binary analysis, ELF disassembly trace, and native test contracts for trade action helper 0x21DE20
- [trade_action_palette_21B560.md](trade_action_palette_21B560.md): original 16-by-16 palette upload arguments and the separate zero-width red/green regression
- [trade_action_helper_21B640.md](trade_action_helper_21B640.md): 6-slot viewport/palette allocation pool, 344-byte 100% C++ match, and native regression tests
- [trade_action_helper_21B7B0.md](trade_action_helper_21B7B0.md): palette and viewport allocation helpers, 196-byte 100% C++ match, and native regression tests
- [trade_action_helper_21B880.md](trade_action_helper_21B880.md): viewport descriptor allocator and configurator, 97.85% C++ match, and native regression tests
- [trade_action_helper_21BAE0.md](trade_action_helper_21BAE0.md): palette delegation and nearest color search, 316-byte 100% C++ match across all 3 functions, and native regression tests
- [trade_action_helper_21BC30.md](trade_action_helper_21BC30.md): streaming DRS loader and control helpers, 79.16% C++ match (two 100% functions), and native regression tests
- [trade_action_helper_21BDF0.md](trade_action_helper_21BDF0.md): engine/display setup and primary manager dispatcher, 468-byte 100% C++ match across both functions, and native regression tests
- [trade_action_helper_21BFD0.md](trade_action_helper_21BFD0.md): GS packet/register setup helpers, 1,048-byte 100% C++ match across all 5 functions, and native regression tests
- [trade_action_helper_21DE90.md](trade_action_helper_21DE90.md): eight-input packet dispatcher, native chain tests, and complete 192-byte relocated C++ match
- [trade_action_helper_21DF50.md](trade_action_helper_21DF50.md): nine-input packet builder, ten writer arguments, wrapped arithmetic, and remaining target differences
- [trade_action_dispatcher_2b66b0.md](trade_action_dispatcher_2b66b0.md): trade action dispatcher slice 0x2B66B0, modular architecture, and 16-case native test validation
- [trade_action_candidates_2b76b0.md](trade_action_candidates_2b76b0.md): trade action candidate evaluator slices 0x2B76B0, 0x2B7BB0, 0x2B8560 & 0x2B8980, distance pool resolution, and 28-case native test validation
- [ps2_binary_analysis.md](ps2_binary_analysis.md#61901-trade-action-helper-0x2184d0-0x218820-end-exclusive-trade_action_helper_2184d0cpp): adjacent helper `0x2184D0` slice, division-trap repair, and verification
- [open_empire_re_analysis.md](open_empire_re_analysis.md): reverse engineering discoveries from glouw's Open Empire (DRS archive parsing, SLP shape bytecode VM, palette switching, and blendomatic transitions)
- [observability.md](observability.md): offline-first verification tracking, terminal watch, static dashboard and tracked README SVG badges
- [agy_orchestration.md](agy_orchestration.md): how the agy CLI is used as a delegated worker (wrapper, profiles, batches, and what is and is not enforced)
- [kcet_hardware_analysis.md](kcet_hardware_analysis.md): memory layout, boundaries, and structure of the 10 KCET hardware modules in the PS2 binary
- [adr/0001-target-editions.md](adr/0001-target-editions.md): edition decision, rationale, open verification items, and sources
