#ifndef GAME_THREAD_H
#define GAME_THREAD_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Boot Phase Constants */
#define BOOT_PHASE_INIT_START       0x00
#define BOOT_PHASE_AUDIO_POLL       0x06
#define BOOT_PHASE_PREPARE_OVERLAY  0x08
#define BOOT_PHASE_LOAD_OVERLAY     0x0C
#define BOOT_PHASE_OVERLAY_ENTRY1   0x10
#define BOOT_PHASE_OVERLAY_ENTRY2   0x11

/* Memory addresses for asset loading */
#define OVERLAY_LOAD_ADDR           0x01D98000
#define OVERLAY_ENTRY_POINT_1       0x01DE9900
#define OVERLAY_ENTRY_POINT_2       0x01DE9B00

/* State machine GP offsets / global variables */
extern s16 g_boot_phase_init;   /* gp - 0x74B8 */
extern s16 g_boot_phase;        /* gp - 0x74B6 */
extern s16 g_boot_subphase;     /* gp - 0x74B4 */

extern u64 g_frame_counter_1;   /* 0x00CA1550 */
extern u64 g_frame_counter_2;   /* 0x00CA1560 */

extern s32 g_sema_render;       /* 0x00C6F390 */
extern s32 g_sema_vsync;        /* 0x00C6F3B0 */
extern s32 g_sema_msg_queue;    /* 0x00C6F3D0 */
extern int g_game_loop_break;

/* Function Declarations */
void func_002206A0(void);
void func_002206F0(void);
void func_002206F0_iter(void);
void func_00221F40(void);
void func_00222180(s16 phase);
void func_00222190(void);
int func_002221A0(void);
int func_002240B0(const char *filename, void *destination);
int func_100270(u32 size, void *dest);
int func_104D40(s32 sema_id);
int func_104D60(s32 sema_id);

#ifdef __cplusplus
}
#endif

#endif /* GAME_THREAD_H */
