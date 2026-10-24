#pragma exceptions off
#include "unit_action_build_79080.h"

extern "C" {
    int func_26AD20(void *self, int flag);
    void func_1827B0(void *sound_sys, int effect_id);
    void func_26AD60(void *self, int flag);
    void func_1DC9D0(void *self, void *new_sprite);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define UNIT_SOUND_OFFSET    0x18
#define UNIT_SPRITE_OFFSET   0x20
#define OWNER_WORLD_OFFSET   0x1730
#define WORLD_EFFECTS_OFFSET 0x98
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define UNIT_SOUND_OFFSET    0xC
#define UNIT_SPRITE_OFFSET   0x10
#define OWNER_WORLD_OFFSET   0xB98
#define WORLD_EFFECTS_OFFSET 0x4C
#endif

static void trigger_transition_effect(void *self) {
    if (func_26AD20(self, 0x100) == 0) return;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    int effect_idx = *(int *)((char *)proto + 0x15C);
    int *effects = *(int **)((char *)world + WORLD_EFFECTS_OFFSET);
    int effect_id = effects[effect_idx];
    void *sound_sys = *(void **)((char *)self + UNIT_SOUND_OFFSET);
    func_1827B0(sound_sys, effect_id);
}

void func_00279080(void *self, void *new_sprite) {
    void *current_sprite = *(void **)((char *)self + UNIT_SPRITE_OFFSET);
    if (current_sprite == new_sprite) return;
    trigger_transition_effect(self);
    func_26AD60(self, 0x100);
    unsigned char saved_facet = *(unsigned char *)((char *)self + 0x35);
    func_1DC9D0(self, new_sprite);
    *(unsigned char *)((char *)self + 0x35) = saved_facet;
}
