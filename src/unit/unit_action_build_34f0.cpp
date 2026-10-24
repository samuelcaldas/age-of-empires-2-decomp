#pragma exceptions off
#include "unit_action_build_34f0.h"

extern "C" {
    int func_123350(float val);
    int func_80196610(void *self);
}

typedef void (*Vtable32CMethod)(void *self, void *arg1, int a2, int a3);

static void update_progress_type_18(void *self, void *owner) {
    void *mgr = *(void **)((char *)owner + 0xB98);
    void *stats = *(void **)((char *)owner + 0xBAC);
    float dt = *(float *)((char *)mgr + 0xAC);
    float rate = *(float *)((char *)stats + 0x8C);
    float val = *(float *)((char *)self + 0x40) + dt * rate;

    if (val > 100.0f) {
        val = 100.0f;
    }
    *(float *)((char *)self + 0x40) = val;
    *(short *)((char *)self + 0x3C) = 0x22;
}

static void update_progress_type_53(void *self, void *owner) {
    void *mgr = *(void **)((char *)owner + 0xB98);
    void *stats = *(void **)((char *)owner + 0xBAC);
    float dt = *(float *)((char *)mgr + 0xAC);
    float rate = *(float *)((char *)stats + 0x14C);
    float val = *(float *)((char *)self + 0x40) + dt * rate;

    if (val > 100.0f) {
        val = 100.0f;
    }
    *(float *)((char *)self + 0x40) = val;
    *(short *)((char *)self + 0x3C) = 0x22;
}

static void update_countdown_type_40(void *self, void *owner) {
    if (*(float *)((char *)self + 0x40) <= 0.0f) {
        return;
    }

    void *mgr = *(void **)((char *)owner + 0xB98);
    short step = *(short *)((char *)mgr + 0x20);
    short count = *(short *)((char *)self + 0x10C) - step;
    *(short *)((char *)self + 0x10C) = count;

    if (count > 0) {
        return;
    }

    *(float *)((char *)self + 0x40) -= 1.0f;
    for (int i = 0; i < 6; ++i) {
        *(short *)((char *)self + 0x100 + i * 2) -= 1;
    }

    void *stats = *(void **)((char *)owner + 0xBAC);
    float stat_104 = *(float *)((char *)stats + 0x104);
    *(short *)((char *)self + 0x10C) = (short)func_123350(1000.0f * stat_104);
}

static void check_special_sub_action(void *self, void *proto) {
    short model_id = *(short *)((char *)proto + 0x8);
    if (model_id == 0x20F || model_id == 0x210 || model_id == 0x2C2) {
        void **vtbl = *(void ***)self;
        Vtable32CMethod fn = (Vtable32CMethod)vtbl[203]; // 0x32C / 4 = 203
        fn(self, self, 0, 0);
        func_80196610(self);
    }
}

static void update_building_progress(void *self, void *proto, void *owner) {
    short model_id = *(short *)((char *)proto + 0x8);
    if (model_id != 0x2B4 && model_id != 0x2B6) {
        return;
    }

    if (*(float *)((char *)self + 0x30) < 1.0f) {
        return;
    }

    void *stats = *(void **)((char *)owner + 0xBAC);
    float limit = *(float *)((char *)stats + 0x180);
    if (limit <= 0.0f) {
        return;
    }

    float max_health = (float)*(short *)((char *)proto + 0x3E);
    if (*(float *)((char *)self + 0x30) >= max_health) {
        void *mgr = *(void **)((char *)owner + 0xB98);
        float dt = *(float *)((char *)mgr + 0xAC);
        *(float *)((char *)self + 0x11C) += dt;
        return;
    }

    void *mgr = *(void **)((char *)owner + 0xB98);
    float dt = *(float *)((char *)mgr + 0xAC);
    *(float *)((char *)self + 0x11C) -= dt;
    *(float *)((char *)self + 0x30) += 1.0f;
    if (*(float *)((char *)self + 0x30) > max_health) {
        *(float *)((char *)self + 0x30) = max_health;
    }
}

int func_2734F0(void *self) {
    if (*(unsigned char *)((char *)self + 0x39) != 2) {
        return 0;
    }

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *proto = *(void **)((char *)self + 0x4);
    void *owner = *(void **)((char *)self + 0x8);
#endif

    short type = *(short *)((char *)proto + 0xE);
    if (type == 0x12) {
        update_progress_type_18(self, owner);
    }
    if (type == 0x35) {
        update_progress_type_53(self, owner);
    }
    if (type == 0x28) {
        update_countdown_type_40(self, owner);
    }

    if (*(float *)((char *)self + 0x30) < 1.0f && *(unsigned char *)((char *)self + 0x39) == 2) {
        check_special_sub_action(self, proto);
    }

    update_building_progress(self, proto, owner);
    return 1;
}
