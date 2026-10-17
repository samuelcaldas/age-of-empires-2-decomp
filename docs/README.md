# Documentation index

Start with the top-level [README](../README.md).

- [game_files.md](game_files.md): where each original file comes from, how to extract it, and how to verify it
- [ps2_binary_analysis.md](ps2_binary_analysis.md): disc architecture, Metrowerks compiler, debug strings, and source files discovered in the PS2 binary
- [ps2_library_map.md](ps2_library_map.md): bounded third-party runtime routines and Sony SDK version markers in the PAL ELF
- [toolchain.md](toolchain.md): compilers, how to identify them from the binaries, and what is still unverified
- [elevation_mesh_serializer_328020.md](elevation_mesh_serializer_328020.md): pure-C++ serializer at `0x328020`, 224-byte exact MWCC match, ordered-write contracts, and real mutation tests
- [trade_action_route_finish.md](trade_action_route_finish.md): exact route-buffer reconstruction, corrected ELF mapping, and regression validation
- [trade_action_helpers_217840.md](trade_action_helpers_217840.md): eight independent trade-action setters, callback behavior, and native regression coverage
- [trade_action_helper_218350.md](trade_action_helper_218350.md): reconstructed helper, exact original code/padding boundary, isolated build comparison, and seven-case native contracts
- [trade_action_dispatcher_2b66b0.md](trade_action_dispatcher_2b66b0.md): trade action dispatcher slice 0x2B66B0, modular architecture, and 16-case native test validation
- [trade_action_candidates_2b76b0.md](trade_action_candidates_2b76b0.md): trade action candidate evaluator slices 0x2B76B0, 0x2B7BB0, & 0x2B8560, candidate pool resolution, and 24-case native test validation
- [ps2_binary_analysis.md](ps2_binary_analysis.md#61901-trade-action-helper-0x2184d0-0x218820-end-exclusive-trade_action_helper_2184d0cpp): adjacent helper `0x2184D0` slice, division-trap repair, and verification
- [open_empire_re_analysis.md](open_empire_re_analysis.md): reverse engineering discoveries from glouw's Open Empire (DRS archive parsing, SLP shape bytecode VM, palette switching, and blendomatic transitions)
- [agy_orchestration.md](agy_orchestration.md): how the agy CLI is used as a delegated worker (wrapper, profiles, batches, and what is and is not enforced)
- [kcet_hardware_analysis.md](kcet_hardware_analysis.md): memory layout, boundaries, and structure of the 10 KCET hardware modules in the PS2 binary
- [adr/0001-target-editions.md](adr/0001-target-editions.md): edition decision, rationale, open verification items, and sources
