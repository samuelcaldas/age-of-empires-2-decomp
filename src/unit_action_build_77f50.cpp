#pragma exceptions off
#include "unit_action_build_77f50.h"

extern "C" {
    int func_2E01E0(void *owner, short proto_id, int arg2, int arg3, int arg4, int arg5, float ratio);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET 0x8
#define UNIT_OWNER_OFFSET 0x10
#else
#define UNIT_PROTO_OFFSET 0x4
#define UNIT_OWNER_OFFSET 0x8
#endif

static float calculate_repair_ratio(float current_hp, short max_hp) {
    float max_hp_f = (float)max_hp;
    float missing_hp = max_hp_f - current_hp;
    return (missing_hp / max_hp_f) / 2.0f;
}

int func_00277F50(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    float current_hp = *(float *)((char *)self + 0x30);
    short max_hp = *(short *)((char *)proto + 0x3E);
    short proto_id = *(short *)((char *)proto + 0x8);
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    float ratio = calculate_repair_ratio(current_hp, max_hp);
    int result = func_2E01E0(owner, proto_id, 0, 0, 0, 0, ratio);
    return ((result & 0xFF) != 0) ? 1 : 0;
}
