#pragma exceptions off
#include "unit_action_build_79ca0.h"

extern "C" {
    int func_26AD20(void *self, int flag);
    void func_26AD60(void *self, int flag);
    void *func_332E60(void *world, int target_id);
}

typedef void (*ResumeOrderFn)(void *self, void *target, int param1, int param2,
                              float x, float y, float z);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_OWNER_OFFSET  0x10
#define OWNER_WORLD_OFFSET 0x1730
#else
#define UNIT_OWNER_OFFSET  0x8
#define OWNER_WORLD_OFFSET 0xB98
#endif

static void resume_with_target_id(void *self, short target_id) {
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    void *target = func_332E60(world, (int)target_id);
    float sx = *(float *)((char *)self + 0x110);
    float sy = *(float *)((char *)self + 0x114);
    void **vtbl = *(void ***)self;
    ResumeOrderFn resume_order = (ResumeOrderFn)vtbl[192];
    resume_order(self, target, 1, -1, sx, sy, 0.0f);
}

static void resume_with_coordinates(void *self) {
    float sx = *(float *)((char *)self + 0x110);
    float sy = *(float *)((char *)self + 0x114);
    if (sx <= -1.0f || sy <= -1.0f) return;
    void **vtbl = *(void ***)self;
    ResumeOrderFn resume_order = (ResumeOrderFn)vtbl[192];
    resume_order(self, 0, 1, -1, sx, sy, 0.0f);
}

void func_00279CA0(void *self) {
    if (func_26AD20(self, 0x400) == 0) return;
    func_26AD60(self, 0x400);
    short target_id = *(short *)((char *)self + 0x10E);
    if (target_id >= 0) {
        resume_with_target_id(self, target_id);
        return;
    }
    resume_with_coordinates(self);
}
