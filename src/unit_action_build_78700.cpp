#pragma exceptions off
#include "unit_action_build_78700.h"

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define OWNER_COUNT_OFFSET   0xD8
#define OWNER_ARRAY_OFFSET   0xE0
#define PROTO_ENTRIES_OFFSET 0x110
#define PROTO_COUNT_OFFSET   0x118
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define OWNER_COUNT_OFFSET   0x6C
#define OWNER_ARRAY_OFFSET   0x70
#define PROTO_ENTRIES_OFFSET 0xF0
#define PROTO_COUNT_OFFSET   0xF4
#endif

struct DamageEntry {
    short damage_class;
    short amount;
};

static float sum_damage_entries(DamageEntry *entries, short count, short unit_type) {
    if (entries == 0) return 0.0f;
    float total = 0.0f;
    for (int i = 0; i < count; ++i) {
        short dclass = entries[i].damage_class;
        if (dclass == 3 || (unit_type != 4 && dclass == 4)) {
            total += (float)entries[i].amount;
        }
    }
    return total;
}

static float compute_projectile_damage(void *self, void *proto) {
    int proj_idx = *(int *)((char *)proto + 0x158);
    if (proj_idx < 0) return 0.0f;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    int unit_count = *(int *)((char *)owner + OWNER_COUNT_OFFSET);
    if (proj_idx >= unit_count) return 0.0f;
    void **unit_array = *(void ***)((char *)owner + OWNER_ARRAY_OFFSET);
    void *proj = unit_array[proj_idx];
    DamageEntry *entries = *(DamageEntry **)((char *)proj + PROTO_ENTRIES_OFFSET);
    short count = *(short *)((char *)proj + PROTO_COUNT_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    return sum_damage_entries(entries, count, type);
}

static float calculate_total_damage(void *self, void *proto) {
    float capability = *(float *)((char *)proto + 0xF8);
    short unit_type = *(short *)((char *)proto + 0xE);
    if (capability <= 1.0f && unit_type == 4) {
        return compute_projectile_damage(self, proto);
    }
    if (capability <= 1.0f) {
        return (unit_type == 4) ? 2.5f : 0.0f;
    }
    DamageEntry *entries = *(DamageEntry **)((char *)proto + PROTO_ENTRIES_OFFSET);
    short count = *(short *)((char *)proto + PROTO_COUNT_OFFSET);
    return sum_damage_entries(entries, count, unit_type);
}

float func_00278700(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    float reload_time = *(float *)((char *)proto + 0x100);
    if (reload_time <= 0.0f) return 0.0f;
    float total_damage = calculate_total_damage(self, proto);
    return total_damage / reload_time;
}
