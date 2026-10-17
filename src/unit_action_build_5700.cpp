#pragma exceptions off
#include "unit_action_build_5700.h"

extern "C" {
    int func_801AAB30();
    int func_80195DD0(void *self, void *target, void *arg2, float mult);
}

typedef void (*Vtable168Method)(void *self, int a1, int a2, int a3, int t0, int t1, int t2);
typedef void (*Vtable80Method)(void *target);
typedef void (*Vtable94Method)(void *target, int zero, int one, float zero_f);

static bool check_special_siege_attack(void *self, void *target, void *proto) {
    short model_id = *(short *)((char *)proto + 0x8);
    if (model_id == 0x7A || model_id == 0x7B) {
        void **self_vtbl = *(void ***)self;
        Vtable168Method v168 = (Vtable168Method)self_vtbl[90]; // 0x168 / 4 = 90
        short id1 = *(short *)((char *)self + 0x24);
        short id2 = *(short *)((char *)target + 0x24);
        v168(self, id1, id1, 0x200, 0x258, id2, 0);

        void **target_vtbl = *(void ***)target;
        Vtable80Method v80 = (Vtable80Method)target_vtbl[32]; // 0x80 / 4 = 32
        v80(target);
        return true;
    }
    return false;
}

int func_275700(void *self, void *target, void *arg2, float damage_mult) {
    if (target == nullptr) {
        return 0;
    }

#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
#else
    void *proto = *(void **)((char *)self + 0x4);
#endif

    if (check_special_siege_attack(self, target, proto)) {
        return 1;
    }

    int res = func_80195DD0(self, target, arg2, damage_mult);

    if (*(float *)((char *)target + 0x30) >= 1.0f) {
        short model = *(short *)((char *)proto + 0x8);
        if (model == 0x2A) {
            void **target_vtbl = *(void ***)target;
            Vtable94Method v94 = (Vtable94Method)target_vtbl[37]; // 0x94 / 4 = 37
            v94(target, 0, 1, 0.0f);
        }
    }

    return res;
}
