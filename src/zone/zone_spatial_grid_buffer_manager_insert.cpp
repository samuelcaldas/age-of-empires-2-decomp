#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_insert.h"

struct ElementTeam {
    char pad_00[0xBA0];
    int team;
};

struct Element {
    char pad_00[0x4];
    unsigned char *type_info; // 0x04
    ElementTeam *team_obj;    // 0x08
    char pad_0C[0x18];        // 0x0C - 0x23
    short flag_24;            // 0x24
    char pad_26[0xA0];        // 0x26 - 0xC5
    unsigned char flag_C6;    // 0xC6
    char pad_C7[0x2D];        // 0xC7 - 0xF3
    char data_F4[1];          // 0xF4
};

struct SpatialGridBufferManager {
    ElementTeam *owner;       // 0x000
    Element *elems[200];      // 0x004
    void *ptrs[200];          // 0x324
    int vals[200];            // 0x644
    short shorts[200];        // 0x964
    short cap;                // 0xAF4
    short count;              // 0xAF6
};

extern "C" int func_001ECC00(void *self_ptr, void *elem_ptr, void *arg2) {
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    Element *elem = (Element *)elem_ptr;

    if (self->count >= self->cap) {
        return 0;
    }

    if (elem->team_obj->team != self->owner->team) {
        return 0;
    }

    if (self->count > 0) {
        for (int i = 0; i < self->count; ++i) {
            if (self->elems[i] == elem) {
                return 0;
            }
        }
    }

    self->elems[self->count] = elem;
    self->ptrs[self->count] = arg2;
    self->vals[self->count] = *(int *)arg2;
    self->shorts[self->count] = elem->flag_24;

    if (*elem->type_info >= 0x32 && elem->flag_C6 > 0) {
        self->ptrs[self->count] = elem->data_F4;
    }

    self->count++;
    return 1;
}
