#pragma exceptions off
#include "unit_action_build_7acb0.h"

extern "C" {
    int func_123350(float val);
    int func_1233E0(float val);
    float func_1234E0(float val);
    int func_100190(float val, double threshold);
    void func_27B4B0(void *self, int param, float val1, float val2);
    void func_27B700(void *self, float sector, int a1, int a2, float acc);
}

#if defined(__LP64__) || defined(_LP64)
#define MGR_OWNER_OFFSET   0x5D8
#define OWNER_PROPS_OFFSET 0x1758
#else
#define MGR_OWNER_OFFSET   0x5D4
#define OWNER_PROPS_OFFSET 0xBAC
#endif

static bool should_skip_tick(void *self) {
    int counter = *(int *)((char *)self + 0x5E8) + 1;
    *(int *)((char *)self + 0x5E8) = counter;
    int interval = *(int *)((char *)self + 0x5E4);
    if (counter < interval) return true;
    *(int *)((char *)self + 0x5E8) = counter - interval;
    return false;
}

static void update_threshold(void *self, void *props) {
    float f12 = *(float *)((char *)props + 0x94);
    float f20 = *(float *)((char *)props + 0xA0);
    if ((f12 + f20) < 0.0f) {
        func_27B4B0(self, 0, 0.0f, 0.0f);
    } else {
        int v0_1 = func_123350(f12);
        float f20_val = (float)v0_1;
        int v0_2 = func_123350(f20);
        float f13_val = (float)v0_2;
        func_27B4B0(self, 0, f20_val, f13_val);
    }
}

static void update_accumulators(void *self, void *props) {
    int c0 = func_123350(*(float *)((char *)props + 0x50)) - *(int *)((char *)self + 0x5FC);
    int d0 = func_123350(*(float *)((char *)props + 0x2A8));
    int s7 = func_123350(*(float *)((char *)props + 0xAC)) - *(int *)((char *)self + 0x600);
    int s6 = func_123350(*(float *)((char *)props + 0x268)) - *(int *)((char *)self + 0x5F0);
    int v0_val = func_123350(*(float *)((char *)props + 0x260)) - *(int *)((char *)self + 0x604);
    int s0 = func_123350(*(float *)((char *)props + 0x26C)) - *(int *)((char *)self + 0x608);
    int fp = func_123350(*(float *)((char *)props + 0x264)) - *(int *)((char *)self + 0x5F4);
    int s1 = func_123350(*(float *)((char *)props + 0x260)) - *(int *)((char *)self + 0x5F8);

    int s2 = *(int *)((char *)self + 0x624) + *(int *)((char *)self + 0x628);
    float f12_sq = 0.0f;
    float f20_sq = 0.0f;
    if (s2 > 0) {
        f12_sq = (float)(s7 + s6) / (float)s2;
        f20_sq = (float)(s7 + s6 + s0 + s1) / (float)s2;
    }

    float sqrt_val = func_1234E0(f12_sq);
    int s3 = 0;
    if (func_100190(sqrt_val, 0.12) != 0) {
        s3 = 1;
    }

    int flag = *(int *)((char *)self + 0x620);
    if (flag == 0) {
        if (s3 == 1) {
            *(int *)((char *)self + 0x620) = 1;
            *(int *)((char *)self + 0x690) += s7 + s0;
            *(int *)((char *)self + 0x694) += s6 + s1;
            *(short *)((char *)self + 0x698) += (short)(c0 + v0_val);
            *(short *)((char *)self + 0x69A) += (short)(d0 + fp);
            *(float *)((char *)self + 0x68C) += f20_sq;
        }
    } else {
        if (s3 == 1) {
            *(int *)((char *)self + 0x690) += s7 + s0;
            *(int *)((char *)self + 0x694) += s6 + s1;
            *(short *)((char *)self + 0x698) += (short)(c0 + v0_val);
            *(short *)((char *)self + 0x69A) += (short)(d0 + fp);
            *(float *)((char *)self + 0x68C) += f20_sq;
        }
    }
}

static void evaluate_sectors(void *self, void *props) {
    float acc_val = *(float *)((char *)self + 0x68C);
    float sqrt_acc = func_1234E0(acc_val);
    if (func_100190(sqrt_acc, 0.15) == 0) {
        return;
    }

    int s2 = *(int *)((char *)self + 0x624) + *(int *)((char *)self + 0x628);
    float sector_vals[8];
    for (int i = 0; i < 8; ++i) {
        int v1 = func_1233E0(*(float *)((char *)props + 0x1B8 + i * 4)) - *(int *)((char *)self + 0x63C + i * 4);
        int v2 = func_1233E0(*(float *)((char *)props + 0x1F8 + i * 4)) - *(int *)((char *)self + 0x66C + i * 4);
        sector_vals[i] = (s2 > 0) ? ((float)(v1 + v2) / (float)s2) : 0.0f;
    }

    int selected_sector = 0;
    float max_val = 0.0f;
    for (int i = 0; i < 8; ++i) {
        if (sector_vals[i] > max_val) {
            max_val = sector_vals[i];
            selected_sector = i + 1;
        }
    }

    func_27B700(self, (float)selected_sector, 11, 0, sqrt_acc);

    *(int *)((char *)self + 0x620) = 0;
    *(int *)((char *)self + 0x690) = 0;
    *(int *)((char *)self + 0x694) = 0;
    *(short *)((char *)self + 0x698) = 0;
    *(short *)((char *)self + 0x69A) = 0;
    *(float *)((char *)self + 0x68C) = 0.0f;
}

static void refresh_props_cache(void *self, void *props) {
    *(int *)((char *)self + 0x5EC) = func_123350(*(float *)((char *)props + 0xAC));
    *(int *)((char *)self + 0x5F0) = func_123350(*(float *)((char *)props + 0x2B0));
    *(int *)((char *)self + 0x5F4) = func_123350(*(float *)((char *)props + 0x26C));
    *(int *)((char *)self + 0x5F8) = func_123350(*(float *)((char *)props + 0x264));
    *(int *)((char *)self + 0x5FC) = func_123350(*(float *)((char *)props + 0x50));
    *(int *)((char *)self + 0x600) = func_123350(*(float *)((char *)props + 0x2A8));
    *(int *)((char *)self + 0x604) = func_123350(*(float *)((char *)props + 0x268));
    *(int *)((char *)self + 0x608) = func_123350(*(float *)((char *)props + 0x260));
    *(int *)((char *)self + 0x624) = func_123350(*(float *)((char *)props + 0x290));
    *(int *)((char *)self + 0x628) = func_123350(*(float *)((char *)props + 0x294));

    if (*(int *)((char *)self + 0x620) == 0) {
        for (int i = 0; i < 8; ++i) {
            *(int *)((char *)self + 0x63C + i * 4) = func_1233E0(*(float *)((char *)props + 0x1B8 + i * 4));
            *(int *)((char *)self + 0x66C + i * 4) = func_1233E0(*(float *)((char *)props + 0x1F8 + i * 4));
        }
    }
}

void func_0027AC90(void *self) {
    if (should_skip_tick(self)) return;

    void *owner = *(void **)((char *)self + MGR_OWNER_OFFSET);
    void *props = *(void **)((char *)owner + OWNER_PROPS_OFFSET);

    update_threshold(self, props);
    update_accumulators(self, props);
    evaluate_sectors(self, props);
    refresh_props_cache(self, props);
}

void func_0027ACB0(void *self) {
    func_0027AC90(self);
}
