#pragma exceptions off
#include "unit_action_build_tile_path.h"

struct PathUnitMaster {
    unsigned char m_class;
    char pad_1[0x1F];
    float m_radius;
};

struct PathUnit {
    void *vtable;
    PathUnitMaster *m_master;
    char pad_8[0x44 - 8];
    float m_x;
    float m_y;
};

struct PathTile {
    char pad_0[0xD];
    unsigned char m_unit_count;
    char pad_e[0x14 - 0xE];
    PathUnit **m_units;
    char pad_18[28 - 0x18];
};

struct PathZone {
    void *vtable;
    int m_field4;
    int m_width;
    int m_height;
    char pad_10[0x8E8C - 0x10];
    PathTile **m_grid;
};

struct PathAction {
    void *vtable;
    PathUnitMaster *m_master;
    void *m_actor;
    char pad_c[0x44 - 0xC];
    float m_x;
    float m_y;
};

void func_00271220(ActionRebind *self) {
    PathAction *act = (PathAction*)self;
    PathUnitMaster *master = act->m_master;
    void *actor = act->m_actor;
    void *world = *(void**)((char*)actor + 0xB98);
    PathZone *zone = *(PathZone**)((char*)world + 0x3C);

    float px = act->m_x;
    float py = act->m_y;
    float rx = master->m_radius;

    int min_x = func_123350(px - rx) - 5;
    int min_y = func_123350(py - rx) - 5;
    int max_x = func_123350(px + rx) + 5;
    int max_y = func_123350(py + rx) + 5;

    int w = zone->m_width;
    int h = zone->m_height;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= w) max_x = w - 1;
    if (max_y >= h) max_y = h - 1;

    for (int y = min_y; y <= max_y; ++y) {
        PathTile *row = zone->m_grid[y];
        for (int x = min_x; x <= max_x; ++x) {
            PathTile *tile = &row[x];
            int count = tile->m_unit_count;
            for (int i = 0; i < count; ++i) {
                PathUnit *unit = tile->m_units[i];
                if (unit->m_master->m_class != 80) {
                    continue;
                }
                if (!func_26AD20(unit, 0x800)) {
                    continue;
                }

                float dx = unit->m_x - px;
                if (dx < 0.0f) dx = -dx;
                float dy = unit->m_y - py;
                if (dy < 0.0f) dy = -dy;

                float thresh = rx + unit->m_master->m_radius;
                if (dx < thresh && dy < thresh) {
                    func_0026E750(unit);
                }
            }
        }
    }
}
