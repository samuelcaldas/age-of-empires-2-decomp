#pragma exceptions off
#include "unit_action_visibility.h"

typedef void (*NotifyLOSFn)(void *component, void *player, void *action, float x, float y, float z);

void func_00267E60(ActionRebind *self) {
    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }
    func_26A540(self, 0);
    self->m_field30 = 0.0f;
}

void func_00267EB0(ActionRebind *self) {
    if (self->m_field24 < 0) {
        return;
    }
    if (self->m_world == 0) {
        return;
    }
    void *field4 = self->m_field4;
    if (field4 == 0) {
        return;
    }

    void *world_sub = *(void**)((char*)self->m_world + 2968);
    unsigned char flag = *(unsigned char*)((char*)world_sub + 49);
    if (flag != 0 && flag != 3) {
        return;
    }

    if (*(unsigned char*)((char*)field4 + 144) == 0) {
        if (*(unsigned char*)((char*)field4 + 3) == 0) {
            return;
        }
    }

    int tile_y = func_123350(self->m_y);
    int tile_x = func_123350(self->m_x);

    int *row = D_50A5A0[tile_y];
    unsigned int sight = (unsigned int)row[tile_x];

    unsigned int s4 = sight & 0xFFFF;
    unsigned int s1 = sight >> 16;
    int s0 = 0;

    while (s1 != 0) {
        if ((s1 & 1) != 0) {
            void *player = *(void**)((char*)*(void**)((char*)world_sub + 84) + s0 * 4);
            if (*(unsigned char*)((char*)field4 + 3) != 0) {
                func_328300(*(void**)((char*)player + 3172), self->m_field24, *(unsigned char*)((char*)field4 + 145));
            }
            if (*(unsigned char*)((char*)field4 + 144) == 1 && s0 > 0 && (s4 & 1) == 0) {
                if (func_1EBA00((char*)player + 140) == 0) {
                    void *comp = *(void**)((char*)*(void**)((char*)player + 112) + 972);
                    NotifyLOSFn notify = *(NotifyLOSFn*)((char*)*(void**)((char*)comp + 160) + 116);
                    notify(comp, player, self, self->m_x, self->m_y, self->m_z);
                }
            }
        }
        s0++;
        s4 >>= 1;
        s1 >>= 1;
    }

    if (*(unsigned char*)((char*)field4 + 144) == 2) {
        func_1ECD00((char*)self->m_world + 152, self);
    }
}

void func_00268070(ActionRebind *self) {
    if (self->m_field24 < 0) {
        return;
    }
    if (self->m_world == 0) {
        return;
    }
    void *field4 = self->m_field4;
    if (field4 == 0) {
        return;
    }

    if (*(unsigned char*)((char*)field4 + 144) != 2) {
        return;
    }

    int tile_y = func_123350(self->m_y);
    int tile_x = func_123350(self->m_x);

    int *row = D_50A5A0[tile_y];
    unsigned int sight = (unsigned int)row[tile_x];

    unsigned int s3 = (sight & 0xFFFF) >> 1;
    unsigned int s1 = (sight >> 16) >> 1;
    int s0 = 1;

    void *world_sub = *(void**)((char*)self->m_world + 2968);

    while (s1 != 0) {
        if ((s1 & 1) != 0) {
            void *player = *(void**)((char*)*(void**)((char*)world_sub + 84) + s0 * 4);
            if ((s3 & 1) == 0) {
                if (func_1EBA00((char*)player + 140) == 0) {
                    void *comp = *(void**)((char*)*(void**)((char*)player + 112) + 972);
                    NotifyLOSFn notify = *(NotifyLOSFn*)((char*)*(void**)((char*)comp + 160) + 116);
                    notify(comp, player, self, self->m_x, self->m_y, self->m_z);
                }
            }
        }
        s0++;
        s3 >>= 1;
        s1 >>= 1;
    }

    tile_y = func_123350(self->m_y);
    tile_x = func_123350(self->m_x);
    int *sight_row = D_50A5A0[tile_y];
    func_1ECBF0((char*)self->m_world + 152, self, (void*)&sight_row[tile_x]);
}
