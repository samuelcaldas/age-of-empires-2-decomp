#pragma exceptions off
#include "unit_action_build_7acb0.h"

extern "C" {
    void func_27B4B0(void *self, int param, float val);
    void func_27B700(void *self);
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

static float get_threshold_val(void *self) {
    void *owner = *(void **)((char *)self + MGR_OWNER_OFFSET);
    void *props = *(void **)((char *)owner + OWNER_PROPS_OFFSET);
    float val1 = *(float *)((char *)props + 0x94);
    float val2 = *(float *)((char *)props + 0xA0);
    if ((val1 + val2) < 0.0f) return 0.0f;
    return val1;
}

void func_0027ACB0(void *self) {
    if (should_skip_tick(self)) return;
    float threshold = get_threshold_val(self);
    func_27B4B0(self, 0, threshold);
    func_27B700(self);
}
