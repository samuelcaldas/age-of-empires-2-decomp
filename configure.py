#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import hashlib
import sys
from pathlib import Path

import yaml

from tools.project import (
    Object,
    Platform,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions. See docs/adr/0001-target-editions.md for why each one is listed.
DEFAULT_VERSION = 0
VERSIONS = [
    "AGE2_X1_1_0C_EN",  # 0: The Conquerors 1.0c, PC (primary)
    "EMPIRES2_2_0A_EN",  # 1: Age of Kings 2.0a, PC (secondary)
    "SLES-50282",  # 2: Age of Kings, PS2 PAL (primary)
    "SLPM-62076",  # 3: Age of Kings, PS2 NTSC-J (secondary)
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (MSVC for PC, CodeWarrior/EE GCC for PS2, default: compilers/ if present)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--delink",
    metavar="BINARY | DIR",
    type=Path,
    help="path to delink binary (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional, needed for the NTSC-J build)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.delink_path = args.delink
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
compilers_dir = args.compilers
if compilers_dir is None and Path("compilers").is_dir():
    compilers_dir = Path("compilers")
config.compilers_path = compilers_dir
config.generate_map = args.map
config.non_matching = args.non_matching
config.progress = args.progress
config.sjiswrap_path = args.sjiswrap
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions. TODO: pin once the toolchains are identified (docs/toolchain.md).
config.compilers_tag = None
config.objdiff_tag = "v3.7.0"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.2.0"
if version_num in [0, 1]:
    config.platform = Platform.WIN32
    config.delink_tag = "v0.16.1"
elif version_num in [2, 3]:
    config.platform = Platform.PS2
    # Generic MIPS binutils, as in nfsmw. Not the original EE toolchain (see docs/toolchain.md).
    config.binutils_tag = "2.45"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"

# Platform flags stay empty until the first object is registered and the toolchain is confirmed.
if config.platform == Platform.PS2:
    config.asflags = [
        "-no-pad-sections",
        "-EL",
        "-march=5900",
        "-mabi=eabi",
        "-I include",
    ]
    config.cflags = [
        "-O3",
        "-inline",
        "on",
        "-msext",
        "on",
        "-char",
        "signed",
        "-sym",
        "off",
        "-Iinclude",
    ]
    config.ldflags = [
        "-EL",
        "-T",
        str(Path("build") / config.version / "ldscript.ld"),
    ]
    config.linker_version = "PS2/mwcc-2.3.1.01"  # Confirmed from .comment: MW MIPS C Compiler (2.3.1.01)
    config.context_defines = ["_R5900", "__mips__"]
elif config.platform == Platform.WIN32:
    config.ldflags = [
        "/NODEFAULTLIB",
        f"/PDB:./build/{config.version}/{config.version}.pdb",
        "/DEBUG",
    ]
    # age2_x1.exe is the SafeDisc loader. Its Rich header shows link 5.10 and cvtres 5.00.1668 (VS97 SP3).
    # The game code may be in age2_x1.icd, built with VC++ 6.0. Target still open (docs/toolchain.md)
    config.linker_version = "Win32/VS97-SP3-unconfirmed"
    config.context_defines = ["_WIN32"]

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Object lists stay empty until the original binaries are split (docs/game_files.md).
Matching = True  # Object matches and should be linked
NonMatching = False  # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching

if config.platform == Platform.PS2:
    config.libs = [
        {
            "lib": "kcet",
            "objects": [
                Object(
                    Matching,
                    "kt_mouse",
                    cflags=["-O2", "-G0", "-Iinclude"],
                    toolchain_version="PS2/ee-gcc2.9-991111",
                ),
            ],
        },
        {
            "lib": "game",
            "objects": [
                Object(
                    Matching,
                    "map_zone",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "screen_obj",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sight_table",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "map_zone_los",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "map_zone_add_rect",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "map_zone_rect",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "map_zone_reveal_rect",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "visible_map",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "item_creator",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "spatial_item_creator",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_update",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_node_mgr",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_spatial_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_destructors",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "base_list_stream_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "sub_list_queries",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "sub_list_action",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_items",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_events",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_handlers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_dispatch",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_getters",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_constants",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_teardown",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_setup",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_action_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_accessors",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_validate",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_targets",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_target_notify",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_action_name",
                    cflags=config.cflags + ["-sdatathreshold", "0"],
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_float_accessors",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_target_entities",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_callback_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_item_base",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "sub_list_build_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_load",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_log",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_alloc_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "build_ai_add_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_list_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "build_ai_query",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "sub_list_con_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_load",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_log",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_plan_setup",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_query",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_helpers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "con_ai_clean",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "diplomacy_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "diplomacy_ai_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "diplomacy_ai_query",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "diplomacy_ai_helpers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "diplomacy_ai_actions",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "diplomacy_ai_relations",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "emotional_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "emotional_ai_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_init",
                    source="tactical_ai_init.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_load",
                    source="tactical_ai_load.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_save",
                    source="tactical_ai_save.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_query",
                    source="tactical_ai_query.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_matrix",
                    source="tactical_ai_matrix.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_nodes",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_predicates",
                    source="tactical_ai_predicates.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_actions",
                    source="tactical_ai_actions.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_methods",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_dispatch",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_spatial",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_bounds",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_candidates",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_scoring",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_scanner",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_getters",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_parser",
                    source="tactical_ai_parser.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_compiler",
                    source="tactical_ai_compiler.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_analyzer",
                    source="tactical_ai_analyzer.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_predicates2",
                    source="tactical_ai_predicates2.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_random",
                    source="tactical_ai_random.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_defrule",
                    source="tactical_ai_defrule.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_cleanup",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_scope",
                    source="tactical_ai_scope.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_node_item",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_condition",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_param_desc",
                    source="tactical_ai_param_desc.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_infantry",
                    source="tactical_ai_infantry.cpp",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "strategy_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "strategy_ai_matrix",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_ai_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_ai_actions",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_init",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_save",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_load",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_getters",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_update",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_routes",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_callbacks",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_getters2",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_evaluator",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_eval",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_market_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_market_strategy",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_items",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_navigation",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_waypoints1",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_waypoints2",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_pathing",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_trade_step",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_cargo_exchange",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_route_advance",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_route_status",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_target_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_destination",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_route_search",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_search",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_state_updates",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_trade_eval",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_trade",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_manager",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_select",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_eval_planner",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_route_calc",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_status",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_helpers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_market_cleanup",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_route_finish",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_target_resolver",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_target_management",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_trade_state",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_trade_helpers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_trade_finalize",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_reader",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_writers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_buffers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_decoders",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_unpacker",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_handlers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_records",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_parsers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_bitmasks",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_transformers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_filters",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_aggregators",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_collectors",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_accumulators",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_emitters",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_encoders",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_serializers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_packers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_sequence",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_patterns",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_dispatchers",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_unions",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_mutators",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_decoders2",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_decoders3",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_transformers2",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_decoders4",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_evaluators",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_operators",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_evaluators2",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders5",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders6",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders7",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders8",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders9",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "trade_action_stream_decoders10",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_stream_decoders11",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_helper_217730",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_helper_217840",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "zone_path_eval",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "zone_path_queries",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "zone_raycast_query",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "zone_constructor",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "zone_destructor",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "zone_init_params",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_core",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_movement",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_getters3",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_getters4",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_getters5",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "trade_action_getters6",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_player_ops",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_targets",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_properties",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_rebind",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "unit_action_visibility",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    NonMatching,
                    "tactical_ai_player_dispatch",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_action_constructors",
                    cflags=config.cflags + ["-sdatathreshold", "0"],
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
                Object(
                    Matching,
                    "tactical_ai_action_items",
                    cflags=config.cflags,
                    toolchain_version="PS2/mwcc-2.3.1.01",
                ),
            ],

        },
    ]
else:
    config.libs = []
config.warn_missing_source = False
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("libs", "Library Code"),
]
config.progress_each_module = args.verbose


def original_binary_path() -> Path:
    """Return the original binary path declared in config.yml for the selected version.

    Returns:
        The top-level target_path (PC) or options.target_path (PS2).

    Raises:
        KeyError: If config.yml declares no target_path.
    """
    with config.config_path.open("r", encoding="utf-8") as config_file:
        yaml_config = yaml.safe_load(config_file)
    return Path(yaml_config.get("target_path") or yaml_config["options"]["target_path"])


def pinned_sha1() -> str:
    """Return the SHA-1 pinned in config/<version>/build.sha1, or an empty string if unset.

    Returns:
        The first token of the file, or "" when the file is empty.
    """
    tokens = config.check_sha_path.read_text(encoding="utf-8").split()
    return tokens[0] if tokens else ""


def file_sha1(path: Path) -> str:
    """Return the SHA-1 hex digest of a file, read in 1 MiB chunks.

    Parameters:
        path: File to hash.

    Returns:
        Lowercase hex digest.
    """
    digest = hashlib.sha1()
    with path.open("rb") as binary_file:
        for chunk in iter(lambda: binary_file.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def require_original_binary() -> None:
    """Abort configuration when the original binary is missing or does not match the pinned SHA-1.

    Raises:
        SystemExit: With the expected path when the file is absent, or the expected and actual
            hashes when they differ.
    """
    expected_path = original_binary_path()
    if not expected_path.is_file():
        sys.exit(
            f"Original binary not found: {expected_path}\n"
            "See docs/game_files.md for the expected layout."
        )

    expected_sha1 = pinned_sha1()
    if not expected_sha1:
        print(f"warning: no SHA-1 pinned in {config.check_sha_path} yet; skipping hash check")
        return

    actual_sha1 = file_sha1(expected_path)
    if actual_sha1 != expected_sha1:
        sys.exit(
            f"SHA-1 mismatch for {expected_path}\n"
            f"  expected {expected_sha1}\n"
            f"  actual   {actual_sha1}\n"
            "See docs/game_files.md for the expected dump."
        )


def require_toolchain() -> None:
    """Abort configuration when no compiler directory was supplied.

    The MSVC and EE GCC toolchains are licensed, so they cannot be downloaded automatically.

    Raises:
        SystemExit: When --compilers was not given.
    """
    if config.compilers_path is None:
        sys.exit(
            "Compilers missing: pass --compilers <DIR> with the toolchain for this target.\n"
            "See docs/toolchain.md."
        )


if args.mode == "configure":
    require_original_binary()
    require_toolchain()
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
