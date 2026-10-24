#pragma exceptions off
#include "unit_action_build_clear_area.h"

struct Cell {
    char pad_00[13];
    unsigned char m_count;
    char pad_0e[6];
    void **m_entities;
    char pad_18[4];
};

static void process_entity(void *entity, ActionRebind *self) {
    void *ent_master = *(void**)((char*)entity + 4);
    if (*(unsigned char*)ent_master != 80) {
        return;
    }
    if (func_26ad20(entity, 2048) == 0) {
        return;
    }

    float diff_x = *(float*)((char*)entity + 68) - *(float*)((char*)self + 68);
    float diff_y = *(float*)((char*)entity + 72) - *(float*)((char*)self + 72);
    if (diff_x < 0.0f) diff_x = -diff_x;
    if (diff_y < 0.0f) diff_y = -diff_y;

    void *self_master = *(void**)((char*)self + 4);
    float r_sum = *(float*)((char*)self_master + 32) + *(float*)((char*)ent_master + 32);

    if (diff_x >= r_sum || diff_y >= r_sum) {
        return;
    }

    func_26e750(entity);
}

static void scan_cell(Cell *cell, ActionRebind *self) {
    unsigned char count = cell->m_count;
    for (int i = 0; i < (int)count; ++i) {
        void *entity = cell->m_entities[i];
        process_entity(entity, self);
    }
}

void func_00271220(ActionRebind *self) {
    void *world = *(void**)((char*)self + 8);
    void *master = *(void**)((char*)self + 4);
    void *player_world = *(void**)((char*)world + 2968);
    void *spatial = *(void**)((char*)player_world + 60);

    float self_x = *(float*)((char*)self + 68);
    float self_y = *(float*)((char*)self + 72);
    float rad_x = *(float*)((char*)master + 32);
    float rad_y = *(float*)((char*)master + 36);

    int min_x = func_123350(self_x - rad_x) - 5;
    int min_y = func_123350(self_y - rad_y) - 5;
    int max_x = func_123350(self_x + rad_x) + 5;
    int max_y = func_123350(self_y + rad_y) + 5;

    int grid_w = *(int*)((char*)spatial + 8);
    int grid_h = *(int*)((char*)spatial + 12);

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= grid_w) max_x = grid_w - 1;
    if (max_y >= grid_h) max_y = grid_h - 1;

    Cell **grid = *(Cell***)((char*)spatial + 0x8E8C);
    for (int y = min_y; y <= max_y; ++y) {
        Cell *row = grid[y];
        for (int x = min_x; x <= max_x; ++x) {
            scan_cell(&row[x], self);
        }
    }
}
