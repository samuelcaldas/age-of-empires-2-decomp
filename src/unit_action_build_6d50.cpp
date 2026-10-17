#pragma exceptions off
#include "unit_action_build_6d50.h"

extern "C" {
    void *func_2C2D20(int sound_id);
    void func_2C2DC0(void *sound_obj);
}

typedef void (*SoundInitFn)(void *sound, void *self, int flag);

#if defined(__LP64__) || defined(_LP64)
#define SELF_PROTO_OFFSET 0x8
#define SELF_SOUND_OFFSET 0x190
#else
#define SELF_PROTO_OFFSET 0x4
#define SELF_SOUND_OFFSET 0xC8
#endif

static void cleanup_existing_sound(void *self) {
    void *existing = *(void **)((char *)self + SELF_SOUND_OFFSET);
    if (existing == 0) {
        return;
    }
    func_2C2DC0(existing);
    *(void **)((char *)self + SELF_SOUND_OFFSET) = 0;
}

static bool is_special_entity(short id) {
    if (id == 0x23 || id == 0x1A6 || id == 0x224) return true;
    if (id == 0x226 || id == 0x24C || id == 0x24) return true;
    if (id == 0x117 || id == 0x118 || id == 0x21E) return true;
    return false;
}

static bool is_silent_category(short cat) {
    if (cat == 58 || cat == 34 || cat == 33 || cat == 32) return true;
    if (cat == 31 || cat == 30 || cat == 29 || cat == 16) return true;
    if (cat == 15 || cat == 14 || cat == 11 || cat == 8) return true;
    if (cat == 7 || cat == 5 || cat == 1) return true;
    return false;
}

static int map_category_sound(void *proto, short cat) {
    if (cat == 4) return 1;
    if (cat == 53 || cat == 43 || cat == 18) return 5;
    if (cat == 59 || cat == 9) return 3;
    if (cat == 10) return 4;
    if (cat == 21) return 2;
    if (cat == 19 || cat == 2) return 9;
    if (cat == 20) return 10;
    if (cat == 49 || cat == 52 || cat == 39 || cat == 51 || cat == 27 || cat == 3) {
        if (cat == 52) return 8;
        int field_158 = *(int *)((char *)proto + 0x158);
        return (field_158 < 0) ? 0 : 8;
    }
    return 7;
}

static int determine_sound_id(void *proto) {
    short category = *(short *)((char *)proto + 0xE);
    if (category == 0x36) {
        return 6;
    }
    if (category == 0x33) {
        short entity_id = *(short *)((char *)proto + 0x8);
        if (is_special_entity(entity_id)) {
            return 6;
        }
    }
    if (is_silent_category(category)) {
        return -1;
    }
    return map_category_sound(proto, category);
}

static void play_construction_sound(void *self, int sound_id) {
    if (sound_id < 0) {
        return;
    }
    void *sound_obj = func_2C2D20(sound_id);
    if (sound_obj == 0) {
        return;
    }
    void *vtable = *(void **)((char *)sound_obj + 0x4);
    SoundInitFn fn = *(SoundInitFn *)((char *)vtable + 0x8);
    fn(sound_obj, self, 2);
    *(void **)((char *)self + SELF_SOUND_OFFSET) = sound_obj;
}

void func_276D50(void *self) {
    cleanup_existing_sound(self);
    void *proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    int sound_id = determine_sound_id(proto);
    play_construction_sound(self, sound_id);
}
