#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00221B60(int type);
void func_0021C610(void *ctx, int mode);
void func_0021C4A0(void *ctx, int mode);
void func_0021D2C0(void *ctx, int a1, unsigned long long a2, const int *rect, int a4, int a5);
void func_0021C410(void *ctx, int mode);
void func_0021A680(void *arg);
void func_0021C1D0(void *ctx, int a1, int a2, int a3, int a4, int a5);
void func_0021CFB0(void *ctx, unsigned long long val_20, int s0, int self_28, const int *rect1, const int *rect2, int a6, int a7);
void func_0021C710(void *ctx, unsigned long long val);
void func_0021BFD0(void *ctx, unsigned long long val);
void func_0021C0D0(void *ctx, int a1, int a2, int a3, int a4, int a5);

static void setup_rect1(void *self, const int *rect1, int *local_rect1) {
    if (rect1 != 0) {
        local_rect1[0] = rect1[0];
        local_rect1[1] = rect1[1];
        local_rect1[2] = rect1[2];
        local_rect1[3] = rect1[3];
        return;
    }
    const int *self_rect = (const int *)((char *)self + 4);
    local_rect1[0] = self_rect[0];
    local_rect1[1] = self_rect[1];
    local_rect1[2] = self_rect[2];
    local_rect1[3] = self_rect[3];
}

static int render_scissor_rect(void *self, const int *local_rect1) {
    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        void *ctx = func_00221B60(0x13);
        func_0021C610(ctx, 3);
        func_0021C4A0(ctx, 0);
        func_0021D2C0(ctx, 0, 0, local_rect1, 0x4000, 1);
        func_0021C4A0(ctx, 1);
        func_0021C610(ctx, 0xD);
        return 0;
    }

    func_0021C410(0, 0);
    func_0021D2C0(0, 0, 0x80000000ULL, local_rect1, 0x4000, 1);
    func_0021C410(0, 1);
    return 0;
}

static void render_context_path(void *self, void *arg2, int s0, const int *local_rect1, const int *local_rect2) {
    void *ctx = func_00221B60(0xF);
    func_0021C1D0(ctx, 0, 1, 0, 1, 0x80);

    unsigned long long val_20 = *(unsigned long long *)((char *)arg2 + 0x20);
    int self_28 = *(int *)((char *)self + 0x28);
    func_0021CFB0(ctx, val_20, s0, self_28, local_rect1, local_rect2, 0x4000, 1);
}

static void render_direct_path(void *self, void *arg2, int s0, const int *local_rect1, const int *local_rect2) {
    unsigned long long v1_or = (1ULL << 32) | 0x61ULL;
    func_0021C710(0, v1_or);

    int r2 = local_rect2[2] - 1;
    int r3 = local_rect2[3] - 1;
    int r0 = local_rect2[0];
    int r1 = local_rect2[1];

    unsigned long long packed_coords = 0;
    packed_coords |= (unsigned long long)(r0 << 4) | 0xAULL;
    packed_coords |= ((unsigned long long)(r2)) << 14;
    packed_coords |= ((unsigned long long)(r1)) << 24;
    packed_coords |= ((unsigned long long)(r3)) << 34;

    func_0021BFD0(0, packed_coords);
    func_0021C0D0(0, 0, 1, 0, 1, 0x80);

    unsigned long long val_20 = *(unsigned long long *)((char *)arg2 + 0x20);
    int self_28 = *(int *)((char *)self + 0x28);
    func_0021CFB0(0, val_20, s0, self_28, local_rect1, local_rect2, 0x4000, 0);
    func_0021C710(0, 1);
    func_0021BFD0(0, 0);
}

int func_0021A960(void *self, const int *rect1, void *arg2, const int *rect2, int flags_t0, int arg5) {
    int local_rect1[4];
    setup_rect1(self, rect1, local_rect1);

    if ((flags_t0 & 0x400) != 0) {
        local_rect1[2]++;
        local_rect1[3]++;
        return render_scissor_rect(self, local_rect1);
    }

    if (rect2 == 0 && arg2 == 0) {
        return 1;
    }

    int local_rect2[4];
    if (rect2 != 0) {
        local_rect2[0] = rect2[0];
        local_rect2[1] = rect2[1];
        local_rect2[2] = rect2[2];
        local_rect2[3] = rect2[3];
    }
    if (rect2 == 0) {
        const int *arg2_rect = (const int *)((char *)arg2 + 4);
        local_rect2[0] = arg2_rect[0];
        local_rect2[1] = arg2_rect[1];
        local_rect2[2] = arg2_rect[2];
        local_rect2[3] = arg2_rect[3];
    }

    if (arg2 != 0) {
        void *field14 = *(void **)((char *)arg2 + 0x14);
        unsigned int field84 = *(unsigned int *)((char *)arg2 + 0x84);
        if (field14 == 0 && field84 < 9) {
            return 1;
        }
    }

    int s0 = 0;
    if (arg2 != 0) {
        int mode = *(int *)((char *)arg2 + 0x1C);
        if (mode == 2) {
            s0 = 1;
        }
        if (mode == 0 || flags_t0 == 0) {
            s0 = 0;
        }
        func_0021A680(arg2);
    }

    char *self_bytes = (char *)self;
    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);

    if ((flags & 0x200) == 0) {
        render_context_path(self, arg2, s0, local_rect1, local_rect2);
        return 0;
    }

    render_direct_path(self, arg2, s0, local_rect1, local_rect2);
    return 0;
}
}
