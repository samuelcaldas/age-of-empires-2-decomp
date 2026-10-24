#pragma exceptions off
#include "unit_action_build_77e50.h"

extern "C" {
    int func_2E03F0(void *owner, short proto_id, int flag, float ratio);
    int func_268FB0(void *self, float delta_hp);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET 0x8
#else
#define UNIT_PROTO_OFFSET 0x4
#endif

static bool is_direct_repair_cost_applicable(short type) {
    if (type == 20) return true;
    if (type == 21 || type == 22) return true;
    if (type == 2) return true;
    if (type == 13) return true;
    if (type == 51) return true;
    return (type >= 53 && type <= 55);
}

static float clamp_delta_hp(float current_hp, float delta_hp, short max_hp) {
    float max_hp_f = (float)max_hp;
    if ((current_hp + delta_hp) > max_hp_f) {
        return max_hp_f - current_hp;
    }
    return delta_hp;
}

static void apply_direct_repair(void *self, void *owner, void *proto, float delta_hp) {
    short max_hp = *(short *)((char *)proto + 0x3E);
    float current_hp = *(float *)((char *)self + 0x30);
    float clamped_hp = clamp_delta_hp(current_hp, delta_hp, max_hp);
    float ratio = clamped_hp / (float)(max_hp * 2);
    short proto_id = *(short *)((char *)proto + 0x8);
    if (func_2E03F0(owner, proto_id, 1, ratio) == 0) {
        return;
    }
    func_268FB0(self, clamped_hp);
}

int func_00277E50(void *self, float delta_hp, void *owner) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (!is_direct_repair_cost_applicable(type)) {
        func_268FB0(self, delta_hp);
        return 2;
    }
    apply_direct_repair(self, owner, proto, delta_hp);
    return 2;
}
