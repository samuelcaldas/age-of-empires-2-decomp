/* KCET GPU Driver Subsystem (kt_gpu.h) */
#ifndef KT_GPU_H
#define KT_GPU_H

#include "common.h"

/* Max GPU command dispatch handlers */
#define KT_GPU_MAX_HANDLERS 29

/* GS Register Constants */
#define GS_REG_FRAME_1   0x4C
#define GS_REG_FRAME_2   0x4D
#define GS_REG_ZBUF_1    0x4E
#define GS_REG_ZBUF_2    0x4F
#define GS_REG_XYZ2      0x05
#define GS_REG_RGBAQ     0x01
#define GS_REG_TEST_1    0x47
#define GS_REG_TEST_2    0x48
#define GS_REG_PRMODECONT 0x1A
#define GS_REG_SCANMSK   0x22
#define GS_REG_COLCLAMP  0x3F
#define GS_REG_PABE      0x49
#define GS_REG_DTHE      0x4A

typedef struct {
#if defined(__LP64__)
    u32 buffer;
#else
    char *buffer;
#endif
    s32 count;
    s32 sema;
    s32 flags;
} GpuWorkState;
_Static_assert(sizeof(GpuWorkState) == 16, "GpuWorkState size");
_Static_assert(offsetof(GpuWorkState, buffer) == 0, "GpuWorkState buffer offset");
_Static_assert(offsetof(GpuWorkState, count) == 4, "GpuWorkState count offset");
_Static_assert(offsetof(GpuWorkState, sema) == 8, "GpuWorkState sema offset");
_Static_assert(offsetof(GpuWorkState, flags) == 12, "GpuWorkState flags offset");

void func_00125808(void *p, u64 *data);
void func_00125858(void *p, u64 *data);
void func_001258A8(void *p, u64 *data);
void func_001258F8(void *p, u64 *data);
void func_00125940(void *p, u32 *data);
void func_00125988(void *p);
void func_001259C8(void *p, u8 *cmd, int flag);

#endif /* KT_GPU_H */
