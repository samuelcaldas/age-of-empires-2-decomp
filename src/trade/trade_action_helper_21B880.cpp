#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021B830(void *manager);

static void CopyConfigWords(void *viewport, void *config) {
    int *src = (int *)config;
    int *dst = (int *)((char *)viewport + 48);
    for (int i = 0; i < 27; ++i) {
        dst[i] = src[i];
    }
}

static void ApplyConfigRect(void *viewport, void *config, int flags) {
    char *vp = (char *)viewport;
    char *cfg = (char *)config;

    if (flags & 4) {
        int x1 = *(int *)(vp + 4);
        int w = *(int *)(cfg + 12);
        *(int *)(vp + 12) = x1 + w - 1;
    }

    if (flags & 2) {
        int y1 = *(int *)(vp + 8);
        int h = *(int *)(cfg + 8);
        *(int *)(vp + 16) = y1 + h - 1;
    }
}

static void ApplyFullscreenOverride(void *viewport, void *manager) {
    char *vp = (char *)viewport;
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
    *(void **)((char *)manager + 1056) = viewport;
}

static int ResolveFormatCode(int bpp) {
    if (bpp == 32) {
        return 0;
    }
    if (bpp == 16) {
        return 2;
    }
    if (bpp == 8) {
        return 19;
    }
    if (bpp == 4) {
        return 20;
    }
    return 2;
}

static void ApplyPixelFormat(void *viewport, void *config) {
    char *vp = (char *)viewport;
    char *cfg = (char *)config;
    unsigned short flags_76 = *(unsigned short *)(cfg + 76);
    int bpp = 0;

    if (flags_76 & 0x40) {
        bpp = *(int *)(cfg + 84);
    }
    if (flags_76 & 0x20) {
        bpp = 8;
        *(int *)(vp + 132) = 8;
    }
    if (flags_76 & 0x8) {
        bpp = 4;
        *(int *)(vp + 132) = 4;
    }

    *(int *)(vp + 28) = ResolveFormatCode(bpp);
}

int func_0021B880(void *manager, void *config, void **out_viewport, int unused, void *extra_ptr) {
    int flags = *(int *)((char *)config + 4);
    void *viewport = func_0021B830(manager);
    if (viewport == 0) {
        return 1;
    }

    char *vp = (char *)viewport;
    *(int *)(vp + 40) = (int)0x80808080;
    CopyConfigWords(viewport, config);
    ApplyConfigRect(viewport, config, flags);

    unsigned short flags_68 = *(unsigned short *)((char *)config + 104);
    if ((flags & 1) && (flags_68 & 0x200)) {
        *out_viewport = viewport;
        ApplyFullscreenOverride(viewport, manager);
    }

    if (flags & 0x1000) {
        ApplyPixelFormat(viewport, config);
    }

    if (!(flags_68 & 0x200)) {
        *(void **)(vp + 84) = extra_ptr;
    }

    int bpp = *(int *)(vp + 132);
    *(int *)(vp + 64) = bpp >> 3;
    *(void **)(vp + 24) = manager;
    *out_viewport = viewport;

    return 0;
}
}
