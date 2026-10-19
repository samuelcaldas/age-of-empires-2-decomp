#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021B830(void *manager);

int func_0021B880(void *manager, void *config, void **out_viewport, int unused, void *extra_ptr) {
    unsigned int *config_state = (unsigned int *)((char *)config + 104);
    int flags = *(int *)((char *)config + 4);
    register int bpp = 0;
    void *viewport = func_0021B830(manager);
    if (viewport == 0) {
        return 1;
    }

    char *vp = (char *)viewport;
    *(int *)(vp + 40) = (int)0x80808080;

    int count;
    int *dst;
    int *src;
    dst = (int *)(vp + 48);
    count = 27;
    src = (int *)config;
    do {
        *dst++ = *src++;
    } while (--count > 0);

    unsigned long long wide_flags = (unsigned int)flags;
    if (wide_flags & 4) {
        *(int *)(vp + 12) = *(int *)(vp + 4) + *(int *)((char *)config + 12) - 1;
    }
    if (wide_flags & 2) {
        *(int *)(vp + 16) = *(int *)(vp + 8) + *(int *)((char *)config + 8) - 1;
    }

    if ((wide_flags & 1) && ((unsigned long long)*config_state & 0x200)) {
        *out_viewport = viewport;
        *(int *)(vp + 4) = 0;
        *(int *)(vp + 12) = 639;
        *(int *)(vp + 8) = 0;
        *(int *)(vp + 16) = 511;
        *(int *)(vp + 60) = 640;
        *(int *)(vp + 56) = 512;
        *(int *)(vp + 132) = 16;
        *(int *)(vp + 28) = 2;
        *(int *)(vp + 68) = 1;
        *(int *)(vp + 84) = 0;
        *(int *)(vp + 152) |= 0x4000;
        *(void **)((char *)manager + 0x420) = viewport;
    }

    if (wide_flags & 0x1000) {
        unsigned long long config_pixel_flags = *(unsigned int *)((char *)config + 76);
        if (config_pixel_flags & 0x40) {
            bpp = *(int *)((char *)config + 84);
        }
        if (config_pixel_flags & 0x20) {
            bpp = 8;
            *(int *)(vp + 132) = 8;
        }
        if (config_pixel_flags & 0x8) {
            bpp = 4;
            *(int *)(vp + 132) = 4;
        }
        *(int *)(vp + 28) = 2;
        if (bpp == 32) goto pixel_format_32;
        if (bpp == 16) goto pixel_format_16;
        if (bpp == 8)  goto pixel_format_8;
        if (bpp == 4)  goto pixel_format_4;
        goto pixel_format_done;
    pixel_format_4:
        *(int *)(vp + 28) = 20;
        goto pixel_format_done;
    pixel_format_8:
        *(int *)(vp + 28) = 19;
        goto pixel_format_done;
    pixel_format_16:
        *(int *)(vp + 28) = 2;
        goto pixel_format_done;
    pixel_format_32:
        *(int *)(vp + 28) = 0;
    pixel_format_done:
        ;
    }

    if (!((unsigned long long)*config_state & 0x200)) {
        *(void **)(vp + 84) = extra_ptr;
    }

    unsigned int width = *(unsigned int *)(vp + 60);
    unsigned int bpp_val = *(unsigned int *)(vp + 132);
    unsigned int aligned = (width + 3) & ~3U;
    *(unsigned int *)(vp + 64) = (aligned * bpp_val) >> 3;
    *(void **)(vp + 24) = manager;
    *out_viewport = viewport;

    return 0;
}
}
