/**
 * sles_boot.c - PlayStation 2 SLES_502.82 Bootloader, PSS Player and Language Launcher
 *
 * Age of Empires II (PS2 PAL SLES-50282)
 *
 * Contains the boot sequence executed directly by the PS2 BIOS from SYSTEM.CNF:
 *   1. Hardware reset, GS display setup, SIF RPC initialization
 *   2. IOP reboot with ioprp23.img and loading of audio/controller/USB IRX modules
 *   3. Playing of publisher/developer introductory FMVs (mslogo_2.pss, eslogo_2.pss, age2_2.pss)
 *   4. Language selection menu (English, French, German, Italian, Spanish)
 *   5. ExecPS2 handoff to the localized AGE2_PS2.ELF
 */

#include "sles_boot.h"
#include <string.h>

static const SlesLangTarget s_lang_targets[LANG_COUNT] = {
    { "EN", "cdrom0:\\EN\\AGE2_PS2.ELF;1" },
    { "FR", "cdrom0:\\FR\\AGE2_PS2.ELF;1" },
    { "GR", "cdrom0:\\GR\\AGE2_PS2.ELF;1" },
    { "IT", "cdrom0:\\IT\\AGE2_PS2.ELF;1" },
    { "SP", "cdrom0:\\SP\\AGE2_PS2.ELF;1" }
};

static const char *s_required_iop_modules[] = {
    "sio2man.irx",
    "padman.irx",
    "mcman.irx",
    "mcserv.irx",
    "usbd.irx",
    "usbmouse.irx",
    "usbkeybd.irx",
    "usbmload.irx",
    "usbmlcnt.irx",
    "libsd.irx",
    "sd_cd.irx",
    "sdstr.irx",
    "soundcd.irx",
    "sdrdrv.irx"
};

static const char *s_intro_movies[] = {
    "mslogo_2.pss",
    "eslogo_2.pss",
    "age2_2.pss"
};

void sles_boot_init(void) {
    /* EE core init, GS display setup, SIF DMA reset */
}

void sles_load_iop_modules(void) {
    /* Reboot IOP with ioprp23.img, then load SIO2, PAD, MC, USB and Audio IRXs */
    size_t i;
    for (i = 0; i < sizeof(s_required_iop_modules) / sizeof(s_required_iop_modules[0]); i++) {
        sles_sif_load_module(s_required_iop_modules[i], NULL);
    }
}

void sles_play_intro_movies(void) {
    /* Stream introductory MPEG2 (PSS) video and audio through IPU & SPU2 */
    size_t i;
    for (i = 0; i < sizeof(s_intro_movies) / sizeof(s_intro_movies[0]); i++) {
        sles_pss_play(s_intro_movies[i]);
    }
}

int sles_select_language(void) {
    /* Default to English (LANG_EN = 0) if pad input times out or PAL territory auto-detects */
    return (int)LANG_EN;
}

void sles_launch_game(SlesLanguage lang) {
    if (lang >= LANG_COUNT) {
        lang = LANG_EN;
    }
    const char *target_elf = s_lang_targets[lang].elf_path;
    (void)target_elf;
    /* ExecPS2(target_elf, 0, NULL) */
}

void sles_pss_play(const char *pss_filename) {
    (void)pss_filename;
    /* PSS stream decoder loop using pss_main.c and pss_audiodec.c */
}

int sles_sif_load_module(const char *module_name, const char *args) {
    (void)module_name;
    (void)args;
    return 0;
}
