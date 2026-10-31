#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_sync_tables.h"

#define V_SLOT_10(base) \
    virtual void* v##base##0(); virtual void* v##base##1(); virtual void* v##base##2(); virtual void* v##base##3(); virtual void* v##base##4(); \
    virtual void* v##base##5(); virtual void* v##base##6(); virtual void* v##base##7(); virtual void* v##base##8(); virtual void* v##base##9();

struct ElementTeam;
struct Element;

struct World {
    char pad_00[0x54];
    ElementTeam **teams; // 0x54
};

struct NonVirtualA0 {
    char pad[0xA0];
};

struct TeamObj3CC : public NonVirtualA0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26();
    virtual void func_74(ElementTeam *team, Element *elem, float x, float y, float z);
};

struct TeamObj70 {
    char pad_00[0x3CC];
    TeamObj3CC *field_3CC; // 0x3CC
};

struct ElementTeamBase {
    char pad_00[0x70];
    TeamObj70 *field_70;     // 0x70
    char pad_74[0x18];       // 0x74 - 0x8B
    char sub_8C[1];          // 0x8C
    char pad_8D[0xB0B];      // 0x8D - 0xB97
    World *world;            // 0xB98
    char pad_B9C[4];         // 0xB9C
    int team;                // 0xBA0
    char pad_BA4[0xF8C];     // 0xBA4 - 0x1B2F
};

struct ElementTeam : public ElementTeamBase {
    V_SLOT_10(0)
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    virtual void* v60(); virtual void* v61(); virtual void* v62(); virtual void* v63();
    virtual void* v64(); virtual void* v65(); virtual void* v66(); virtual void* v67();
    virtual void Method118(int a1, int a2, int a3, short a4, int t1, int t2);
};

struct Element {
    char pad_00[0x24];
    short flag_24;           // 0x24
    char pad_26[0x1E];       // 0x26 - 0x43
    float x;                 // 0x44
    float y;                 // 0x48
    float z;                 // 0x4C
};

struct SpatialGridBufferManager {
    ElementTeam *owner;       // 0x000
    Element *elems[200];      // 0x004
    int *ptrs[200];           // 0x324
    int vals[200];            // 0x644
    short shorts[200];        // 0x964
    short cap;                // 0xAF4
    short count;              // 0xAF6
};

extern "C" {
int func_001ECD00(void *self, void *elem);
Element *func_332e60(void *world, short id);
int func_001EBA00(void *ptr);
int func_202B10(void *team);
}

extern "C" void func_001ECE20(void *self_ptr) {
    int i;
    int team_idx;
    unsigned int diff;
    Element *elem;
    Element *to_remove;
    SpatialGridBufferManager *self = (SpatialGridBufferManager *)self_ptr;
    ElementTeam *other_team;

    to_remove = 0;
    if (self->count <= 0) {
        return;
    }
    for (i = 0; i < self->count; i++) {
        int val_ptr = *self->ptrs[i];
        int old_val = self->vals[i];
        if (val_ptr == old_val) {
            continue;
        }

        self->vals[i] = val_ptr;
        elem = self->elems[i];
        if (!elem || func_332e60(self->owner->world, self->shorts[i]) != elem) {
            to_remove = elem;
            continue;
        }

        diff = (old_val & (old_val ^ val_ptr)) & 0xFFFF;
        team_idx = 1;
        diff >>= 1;
        while (diff != 0) {
            if (diff & 1) {
                if (team_idx != self->owner->team) {
                    other_team = self->owner->world->teams[team_idx];
                    if (func_001EBA00(other_team->sub_8C) == 0) {
                        other_team->field_70->field_3CC->func_74(other_team, elem, elem->x, elem->y, elem->z);
                    }
                    if (func_202B10(other_team) != 0) {
                        other_team->Method118(-1, team_idx, 0x20D, elem->flag_24, 0, 0);
                    }
                }
            }
            team_idx++;
            diff >>= 1;
        }
    }

    if (to_remove != 0) {
        func_001ECD00(self, to_remove);
    }
}
