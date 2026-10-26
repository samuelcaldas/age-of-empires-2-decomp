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

/* Entry points */
#define MO_OV_ENTRY_POINT           0x01ED7080
#define RMMMEM_ENTRY_POINT          0x01D98080
#define HIST_ENTRY_POINT            0x01D98820
#define DCOMP_ENTRY_INIT            0x01D9BEF0
#define DCOMP_ENTRY_DISPATCH        0x01D9BCE0

/* Global overlay variables */
extern void *g_mo_ov_handle;        /* gp - 0x71a4 */
extern void *g_dcomp_ptr;           /* gp - 0x7928 */
extern unsigned char g_dcomp_loaded;/* gp - 0x745C */

/* Task 1: Standalone streamers */
int func_00300C90(void);
int func_00300C60(void);
int func_003800F0(void);

#ifdef __cplusplus
}
#endif

#endif /* OVERLAY_LOADER_H */
