#ifndef OVERLAY_LOADER_H
#define OVERLAY_LOADER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Memory addresses for overlay destination buffers */
#ifndef OVERLAY_LOAD_ADDR
#define OVERLAY_LOAD_ADDR           0x01D98000
#endif
#define THELP_OVERLAY_LOAD_ADDR     0x01F68000
#define MO_OV_OVERLAY_LOAD_ADDR     0x01ED7000
#define DCOMP_OVERLAY_PTR           0x01E58000

/* Entry point constants */
#define MO_OV_ENTRY_POINT           0x01ED7080
#define RMMMEM_ENTRY_POINT          0x01D98080
#define HIST_ENTRY_POINT            0x01D98820
#define DCOMP_ENTRY_INIT            0x01D9BEF0
#define DCOMP_ENTRY_DISPATCH        0x01D9BCE0

/* Function pointer types for entry points */
typedef void *(*MoOvEntryFn)(void);
typedef void (*RmmMemEntryFn)(void);
typedef void (*HistEntryFn)(void);
typedef void (*DcompInitFn)(void);
typedef void (*DcompDispatchFn)(void);

/* Global overlay variables */
extern void *g_mo_ov_handle;        /* gp - 0x71a4 */
extern void *g_dcomp_ptr;           /* gp - 0x7928 */
extern unsigned char g_dcomp_loaded;/* gp - 0x745C */
extern void *g_game_context;        /* gp - 0x7640 */

extern MoOvEntryFn g_mo_ov_entry;
extern RmmMemEntryFn g_rmmmem_entry;
extern HistEntryFn g_hist_entry;
extern DcompInitFn g_dcomp_init;
extern DcompDispatchFn g_dcomp_dispatch;

/* External subsystem helpers */
void func_0036CC40(void *handle);
void func_257E40(void *ctx);

/* Task 1: Standalone streamers */
int func_00300C90(void);
int func_00300C60(void);
int func_003800F0(void);

/* Task 2: Dynamic invokers */
void func_0036C350(void);
int func_0022F550(void *screen_obj);
int func_00258E40(void *context);

/* Task 3: DCOMP loaders */
void func_00226DE0(void);
void func_00226FA0(void);

#ifdef __cplusplus
}
#endif

#endif /* OVERLAY_LOADER_H */
