/**
 * sles_boot.h - PlayStation 2 SLES_502.82 Bootloader and Language Selector
 *
 * Age of Empires II (PS2 PAL SLES-50282)
 * Entry Point: 0x00100008, Load Address: 0x00100000
 * Binary Size: 1,593,256 bytes
 */

#ifndef SLES_BOOT_H
#define SLES_BOOT_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    LANG_EN = 0,
    LANG_FR = 1,
    LANG_GR = 2,
    LANG_IT = 3,
    LANG_SP = 4,
    LANG_COUNT = 5
} SlesLanguage;

typedef struct {
    const char *lang_code;
    const char *elf_path;
} SlesLangTarget;

typedef struct {
    uint32_t entry_point;
    uint32_t text_base;
    uint32_t text_size;
    uint32_t data_base;
    uint32_t bss_base;
    uint32_t bss_size;
} SlesBootHeader;
_Static_assert(sizeof(SlesBootHeader) == 24, "SlesBootHeader size");

/* Boot initialization & launcher prototypes */
void sles_boot_init(void);
void sles_load_iop_modules(void);
void sles_play_intro_movies(void);
int  sles_select_language(void);
void sles_launch_game(SlesLanguage lang);

/* Hardware and movie player helpers */
void sles_pss_play(const char *pss_filename);
int  sles_sif_load_module(const char *module_name, const char *args);

#ifdef __cplusplus
}
#endif

#endif /* SLES_BOOT_H */
