#pragma exceptions off
#include "unit_action_build_e80.h"

extern "C" {
    void func_0026AD60(void *self, int flag);
    void func_00194E90(void *self, void *target, int flag1, float x, float y, float z);
    void func_0026AD30(void *self, int flag);
    void func_00272A88(void *self, float amount);
    int func_123350(float val);
}

typedef void (*Vtable374Method)(void *self);
typedef void (*StatsCostMethod)(void *owner, int res_id, float amount, int zero);

static bool is_excluded_filter_type(short type) {
    switch (type) {
        case 0x28: case 0x2A: case 0x3A: case 0xE:
        case 0xB: case 0x1: case 0x26: case 0x29:
        case 0x9: case 0xA:
            return true;
        default:
            return false;
    }
}

static void apply_cost_entries(void *self, void *proto) {
    if (*(unsigned char *)((char *)proto + 0x0) == 0x50) {
        return;
    }

    int total_cost = 0;
    for (int i = 0; i < 3; ++i) {
        char *entry = (char *)proto + 0x12C + i * 6;
        short res_id = *(short *)entry;
        if (res_id >= 0 && *(unsigned char *)(entry + 4) == 1) {
            total_cost += *(short *)(entry + 2);
        }
    }

#if defined(__LP64__) || defined(_LP64)
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *owner = *(void **)((char *)self + 0x8);
#endif
    void **vtbl = *(void ***)((char *)owner + 0x1B30);
    StatsCostMethod cost_fn = (StatsCostMethod)vtbl[31];

    cost_fn(owner, 0x62, (float)total_cost, 0);
    cost_fn(owner, 0xA4, (float)total_cost, 0);
}

static void init_fields_and_stats(void *self, void *proto, void *owner) {
    *(char *)((char *)self + 0x118) = 0;
    void **self_vtbl = *(void ***)self;
    Vtable374Method v374 = (Vtable374Method)self_vtbl[221];
    v374(self);

    float f0 = *(float *)((char *)proto + 0x148);
    *(float *)((char *)self + 0x120) = f0;
    func_0026AD60(self, 0x100);
    *(char *)((char *)self + 0x11A) = 0;

    func_00272A88(self, 1.0f);

    short type = *(short *)((char *)proto + 0xE);
    if (type == 0x12 || type == 0x35) {
        *(float *)((char *)self + 0x40) = 100.0f;
        *(short *)((char *)self + 0x3C) = 0x22;
    }

    for (int i = 0; i < 6; ++i) {
        *(short *)((char *)self + 0x100 + i * 2) = 0;
    }

    void *stats = *(void **)((char *)owner + 0xBAC);
    float stat_104 = *(float *)((char *)stats + 0x104);
    int rounded = func_123350(1000.0f * stat_104);
    *(short *)((char *)self + 0x10C) = (short)rounded;

    func_0026AD60(self, 0x400);
    *(short *)((char *)self + 0x10E) = -1;
    *(float *)((char *)self + 0x110) = -1.0f;
    *(float *)((char *)self + 0x114) = -1.0f;
}

int func_00272E80(void *self, void *target, int flag1,
                  float x, float y, float z) {
    *(int *)((char *)self + 0xC8) = 0;
    *(short *)((char *)self + 0x124) = 0;
    func_0026AD60(self, 0x200);

    func_00194E90(self, target, flag1, x, y, z);
    *(int *)((char *)self + 0x11C) = 0;

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *proto = *(void **)((char *)self + 0x4);
    void *owner = *(void **)((char *)self + 0x8);
#endif

    if (*(void **)((char *)owner + 0xBA0) == nullptr) {
        short type = *(short *)((char *)proto + 0xE);
        if (!is_excluded_filter_type(type)) {
            func_0026AD30(self, 0x80);
        }
    }

    init_fields_and_stats(self, proto, owner);
    apply_cost_entries(self, proto);

    return 1;
}
