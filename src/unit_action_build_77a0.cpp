#pragma exceptions off
#include <cmath>
#include "unit_action_build_77a0.h"

extern "C" {
    int func_123350(float val);
    int func_367560(void *entity);
    int func_1AAB30();
}

typedef float (*CalculateDamageFn)(void *self, void *entity);
typedef void (*TakeDamageFn)(void *entity, short type_f4, int type_f0,
                             void *attacker_owner, void *arg_a1, int flag, float damage);
typedef void (*DestroyFn)(void *entity, int zero_arg, int one_arg);
typedef int (*RelationFn)(void *owner, void *target_relation);

#if defined(__LP64__) || defined(_LP64)
#define SELF_PROTO_OFFSET    0x8
#define SELF_OWNER_OFFSET    0x10
#define OWNER_B98_OFFSET     0x1730
#define B98_MAP_OFFSET       0x78
#define MAP_WIDTH_OFFSET     0x10
#define MAP_HEIGHT_OFFSET    0x18
#define MAP_ROWS_OFFSET      0x8E8C
#define ENTITY_PROTO_OFFSET  0x8
#define ENTITY_OWNER_OFFSET  0x10
#define OWNER_1B30_OFFSET    0x2E60
#define OWNER_BA0_OFFSET     0x1740
#else
#define SELF_PROTO_OFFSET    0x4
#define SELF_OWNER_OFFSET    0x8
#define OWNER_B98_OFFSET     0xB98
#define B98_MAP_OFFSET       0x3C
#define MAP_WIDTH_OFFSET     0x8
#define MAP_HEIGHT_OFFSET    0xC
#define MAP_ROWS_OFFSET      0x8E8C
#define ENTITY_PROTO_OFFSET  0x4
#define ENTITY_OWNER_OFFSET  0x8
#define OWNER_1B30_OFFSET    0x1B30
#define OWNER_BA0_OFFSET     0xBA0
#endif

static float get_blast_radius(void *self) {
    void *proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    return *(float *)((char *)proto + 0xFC);
}

static void compute_clamped_bounds(float center, float radius, int max_limit, int &min_val, int &max_val) {
    min_val = func_123350(center - radius) - 6;
    if (min_val < 0) min_val = 0;
    max_val = func_123350(center + radius) + 6;
    if (max_val > max_limit) max_val = max_limit;
}

static bool check_entity_filter(void *self, void *entity, void *ignored_entity) {
    if (entity == ignored_entity) return false;
    if (entity == self) return false;
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    int flags = func_367560(entity) & 0xFF;
    if (flags < *(unsigned char *)((char *)self_proto + 0xE9)) return false;
    void *entity_proto = *(void **)((char *)entity + ENTITY_PROTO_OFFSET);
    if (*(unsigned char *)entity_proto == 0x50 && *(int *)((char *)entity + 0x130) != 0) return false;
    return true;
}

static bool check_alliance(void *self, void *entity) {
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    if (*(float *)((char *)self_proto + 0xF8) <= 1.0f) return true;
    void *self_owner = *(void **)((char *)self + SELF_OWNER_OFFSET);
    void *entity_owner = *(void **)((char *)entity + ENTITY_OWNER_OFFSET);
    void *relation_obj = *(void **)((char *)self_owner + OWNER_1B30_OFFSET);
    RelationFn check_fn = *(RelationFn *)((char *)relation_obj + 0x24);
    void *target_data = *(void **)((char *)entity_owner + OWNER_BA0_OFFSET);
    return check_fn(self_owner, target_data) == 0;
}

static bool check_proto_type_match(void *self, void *entity, void *target_entity) {
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    short type = *(short *)((char *)self_proto + 0x8);
    if (type != 0x23 && type != 0x1A6 && type != 0x224) return true;
    void *entity_proto = *(void **)((char *)entity + ENTITY_PROTO_OFFSET);
    if (*(unsigned char *)entity_proto == 0x50) return true;
    return entity == target_entity;
}

static float compute_distance_sq(void *entity, float center_x, float center_y) {
    float entity_x = *(float *)((char *)entity + 0x44);
    float entity_y = *(float *)((char *)entity + 0x48);
    float dx = std::abs(entity_x - center_x);
    float dy = std::abs(entity_y - center_y);
    void *entity_proto = *(void **)((char *)entity + ENTITY_PROTO_OFFSET);
    float radius_x = *(float *)((char *)entity_proto + 0x20);
    float radius_y = *(float *)((char *)entity_proto + 0x24);
    float delta_x = (dx <= radius_x) ? 0.0f : (dx - radius_x);
    float delta_y = (dy <= radius_y) ? 0.0f : (dy - radius_y);
    return (delta_x * delta_x) + (delta_y * delta_y);
}

static bool check_accuracy(void *self) {
    int roll = (func_1AAB30() * 100) / 0x7FFF;
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    short accuracy = *(short *)((char *)self_proto + 0x106);
    return accuracy >= roll;
}

static bool should_skip_falloff(void *self, void *entity, void *target_entity) {
    if (entity != target_entity) return false;
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    short type = *(short *)((char *)self_proto + 0x8);
    if (type == 0x20F || type == 0x210) return true;
    void *target_proto = *(void **)((char *)target_entity + ENTITY_PROTO_OFFSET);
    return *(unsigned char *)target_proto == 0x50;
}

static float calculate_damage(void *self, void *entity, void *target_entity,
                              float dist_sq, float blast_radius) {
    void **self_vtbl = *(void ***)self;
    CalculateDamageFn calc_fn = (CalculateDamageFn)self_vtbl[66];
    float damage = calc_fn(self, entity);
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    if (*(short *)((char *)self_proto + 0x104) < 0 && !should_skip_falloff(self, entity, target_entity)) {
        float distance = std::sqrt(dist_sq);
        damage *= (blast_radius - distance) / blast_radius;
    }
    short type = *(short *)((char *)self_proto + 0x8);
    if (type == 0xEF || type == 0x22E) damage *= 0.5f;
    return damage;
}

static void apply_damage(void *self, void *entity, void *arg_a1, float damage) {
    void *self_proto = *(void **)((char *)self + SELF_PROTO_OFFSET);
    void *self_owner = *(void **)((char *)self + SELF_OWNER_OFFSET);
    void **entity_vtbl = *(void ***)entity;
    TakeDamageFn take_dmg = (TakeDamageFn)entity_vtbl[33];
    short type_f4 = *(short *)((char *)self_proto + 0xF4);
    int type_f0 = *(int *)((char *)self_proto + 0xF0);
    take_dmg(entity, type_f4, type_f0, self_owner, arg_a1, 1, damage);
    if (*(float *)((char *)entity + 0x30) < 1.0f) {
        DestroyFn destroy_fn = (DestroyFn)entity_vtbl[37];
        destroy_fn(entity, 0, 1);
    }
}

static void process_entity(void *self, void *entity, float center_x, float center_y,
                           float blast_radius, float radius_sq,
                           void *arg_a1, void *ignored_entity, void *target_entity) {
    if (!check_entity_filter(self, entity, ignored_entity)) return;
    if (!check_alliance(self, entity)) return;
    if (!check_proto_type_match(self, entity, target_entity)) return;
    float dist_sq = compute_distance_sq(entity, center_x, center_y);
    if (dist_sq >= radius_sq) return;
    if (!check_accuracy(self)) return;
    float damage = calculate_damage(self, entity, target_entity, dist_sq, blast_radius);
    apply_damage(self, entity, arg_a1, damage);
}

int func_2777A0(void *self, float center_x, float center_y,
                void *arg_a1, void *ignored_entity, void *target_entity) {
    float blast_radius = get_blast_radius(self);
    if (blast_radius <= 0.0f) return 0;
    float radius_sq = blast_radius * blast_radius;
    void *owner = *(void **)((char *)self + SELF_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_B98_OFFSET);
    void *map = *(void **)((char *)world + B98_MAP_OFFSET);
    int map_width = (int)*(short *)((char *)map + MAP_WIDTH_OFFSET);
    int map_height = (int)*(short *)((char *)map + MAP_HEIGHT_OFFSET);
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
    compute_clamped_bounds(center_x, blast_radius, map_width, min_x, max_x);
    compute_clamped_bounds(center_y, blast_radius, map_height, min_y, max_y);
    void **tile_rows = *(void ***)((char *)map + MAP_ROWS_OFFSET);
    for (int ty = min_y; ty < max_y; ++ty) {
        char *row = (char *)tile_rows[ty];
        for (int tx = min_x; tx < max_x; ++tx) {
            char *tile = row + (tx * 28);
            unsigned char count = *(unsigned char *)(tile + 0xD);
            void **entities = *(void ***)(tile + 0x14);
            for (int i = 0; i < count; ++i) {
                process_entity(self, entities[i], center_x, center_y, blast_radius,
                               radius_sq, arg_a1, ignored_entity, target_entity);
            }
        }
    }
    return 1;
}
