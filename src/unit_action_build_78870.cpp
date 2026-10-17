#pragma exceptions off
#include "unit_action_build_78870.h"

extern "C" {
    float func_2786F0(void *self);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET 0x8
#else
#define UNIT_PROTO_OFFSET 0x4
#endif

static bool is_threat_type_applicable(short type) {
    if (type == 0 || type == 0x2C) return true;
    return (type == 4 || type == 0x24);
}

void func_00278870(void *self, float *accum_ptr, float divisor) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (!is_threat_type_applicable(type)) return;
    if (divisor <= 0.0f) return;
    float dps = func_2786F0(self);
    *accum_ptr += (dps / divisor);
}

void func_00278910(void *self, float *accum_ptr, float divisor) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (!is_threat_type_applicable(type)) return;
    if (divisor <= 0.0f) return;
    float dps = func_2786F0(self);
    *accum_ptr -= (dps / divisor);
}
