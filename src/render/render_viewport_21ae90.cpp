#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_0021B130(void *self, const int *rect1, void *target, const int *rect3);

static void init_rect(const int *src, int w, int h, int *dst) {
    if (src != 0) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        return;
    }
    dst[0] = 0;
    dst[1] = 0;
    dst[2] = w;
    dst[3] = h;
}

static bool check_overlap(const int *r, int w, int h) {
    if (r[0] >= w || r[2] < 0) {
        return false;
    }
    if (r[1] >= h || r[3] < 0) {
        return false;
    }
    return true;
}

static void clip_rect(int *r, int w, int h) {
    if (r[0] < 0) {
        r[0] = 0;
    }
    if (r[2] > w) {
        r[2] = w;
    }
    if (r[1] < 0) {
        r[1] = 0;
    }
    if (r[3] > h) {
        r[3] = h;
    }
}

int func_0021AE90(void *self, const int *rect1, void *target, const int *rect3, int arg4, int arg5) {
    char *self_bytes = (char *)self;
    char *target_bytes = (char *)target;

    if (target != 0) {
        unsigned int target_flags = *(unsigned int *)(target_bytes + 0x98);
        if ((target_flags & 0x4000) != 0) {
            return 0;
        }

        int self_1c = *(int *)(self_bytes + 0x1C);
        int target_1c = *(int *)(target_bytes + 0x1C);
        if (self_1c != target_1c) {
            return 1;
        }
        if (self_1c == 0x14 || target_1c == 0x14) {
            return 1;
        }
    }

    int self_h = *(int *)(self_bytes + 0x38);
    int self_w = *(int *)(self_bytes + 0x3C);
    int target_w = 0;
    int target_h = 0;
    if (target != 0) {
        target_w = *(int *)(target_bytes + 0x3C);
        target_h = *(int *)(target_bytes + 0x38);
    }

    int local_rect1[4];
    init_rect(rect1, self_w, self_h, local_rect1);

    int local_rect3[4];
    init_rect(rect3, target_w, target_h, local_rect3);

    if (!check_overlap(local_rect1, self_w, self_h)) {
        return 0;
    }

    if (target != 0 && !check_overlap(local_rect3, target_w, target_h)) {
        return 0;
    }

    clip_rect(local_rect1, self_w, self_h);
    if (target != 0) {
        clip_rect(local_rect3, target_w, target_h);
    }

    int self_1c = *(int *)(self_bytes + 0x1C);
    if (self_1c == 0x13) {
        func_0021B130(self, local_rect1, target, local_rect3);
    }

    return 0;
}
}
