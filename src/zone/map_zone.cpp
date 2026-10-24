#include "map_zone.h"

extern "C" {
    extern float D_004E2F24;
    extern float D_004E2A98;
    extern int *D_50A5A0[];
    void func_226f70(void *stream, void *src, int size);
    void func_002082B0(void *obj, int x, int y);
}

void func_00137810(MapZone *self, void *stream) {
    func_226f70(stream, &self->m_width, 4);
    func_226f70(stream, &self->m_height, 4);
    if (D_004E2F24 >= D_004E2A98) {
        func_226f70(stream, &self->m_field1C, 4);
    }
    func_226f70(stream, &self->m_world->m_fieldBA0, 2);
    if (self->m_width > 0 && self->m_height > 0) {
        func_226f70(stream, self->m_tile_data, self->m_width * self->m_height);
    }
}

int func_001378C0(MapZone *self, int x, int y) {
    int tile_flags = D_50A5A0[y][x];
    if (tile_flags & self->m_world->m_fieldC28) {
        return 15;
    }
    if (tile_flags & self->m_world->m_fieldC24) {
        return 128;
    }
    return 0;
}

void func_00137920(MapZone *self) {
    int x;
    int y;
    for (y = 0; y < self->m_height; y++) {
        for (x = 0; x < self->m_width; x++) {
            if (self->m_row_ptrs[y][x] == 255) {
                self->m_row_ptrs[y][x] = 0;
                self->m_field1C++;
                D_50A5A0[y][x] |= self->m_field2C;
                func_002082B0(self->m_world->m_fieldBB0, x, y);
            }
        }
    }
    self->m_world->m_fieldBBC = 1;
}
