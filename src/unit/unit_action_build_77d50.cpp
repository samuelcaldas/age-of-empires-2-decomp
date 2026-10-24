#pragma exceptions off
#include "unit_action_build_77d50.h"

extern "C" {
    int func_2E03F0(void *owner, short proto_id, int flag, float ratio);
    int func_268FB0(void *self, float delta_hp);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET 0x8
#define UNIT_OWNER_OFFSET 0x10
#else
#define UNIT_PROTO_OFFSET 0x4
#define UNIT_OWNER_OFFSET 0x8
#endif

static bool is_repair_cost_applicable(short type) {
    if (type == 20) return true;
    if (type == 21 || type == 22) return true;
    if (type == 2) return true;
    return type == 53;
}

static float calculate_delta_hp(float delta_time, short max_hp, short build_time, float current_hp) {
    float max_hp_f = (float)max_hp;
    float build_time_f = (float)build_time;
    float delta_hp = (delta_time * max_hp_f) / build_time_f;
    if ((current_hp + delta_hp) > max_hp_f) {
        return max_hp_f - current_hp;
    }
    return delta_hp;
}

static void apply_repair_step(void *self, void *proto, float delta_time) {
    short max_hp = *(short *)((char *)proto + 0x3E);
    short build_time = *(short *)((char *)proto + 0x13E);
    float current_hp = *(float *)((char *)self + 0x30);
    float delta_hp = calculate_delta_hp(delta_time, max_hp, build_time, current_hp);
    float ratio = delta_hp / (float)(max_hp * 2);
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    short proto_id = *(short *)((char *)proto + 0x8);
    if (func_2E03F0(owner, proto_id, 1, ratio) == 0) {
        return;
    }
    func_268FB0(self, delta_hp);
}

int func_00277D50(void *self, float delta_time) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (!is_repair_cost_applicable(type)) {
        func_268FB0(self, delta_time);
        return 2;
    }
    apply_repair_step(self, proto, delta_time);
    return 2;
}
