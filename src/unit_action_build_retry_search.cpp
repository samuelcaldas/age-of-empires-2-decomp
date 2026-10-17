#pragma exceptions off
#include "unit_action_build_retry_search.h"

struct GridCell {
    char pad_0[5];
    unsigned char m_flag;
    char pad_6[22];
};

struct ZoneLayout {
    void *vtable;
    int m_field4;
    int m_width;
    int m_height;
    char pad_10[0x8E8C - 0x10];
    GridCell **m_grid;
};

static int is_tile_match(unsigned char st, unsigned char tile_flag) {
    if (st == 27) {
        if (tile_flag == 0 || tile_flag == 12 || tile_flag == 3) {
            return 1;
        }
        if (tile_flag >= 7 && tile_flag <= 9) {
            return 1;
        }
        if (tile_flag >= 29 && tile_flag < 32) {
            return 1;
        }
        return 0;
    }
    if (st == tile_flag) {
        return 1;
    }
    return 0;
}

static int is_excluded(int x, int y, int num_pts, const int *pts_x, const int *pts_y) {
    for (int i = 0; i < num_pts; ++i) {
        if (x == pts_x[i] && y == pts_y[i]) {
            return 1;
        }
    }
    return 0;
}

void func_00270BA0(ActionRebind *self, int status) {
    void *actor = self->m_world;
    void *master = self->m_field4;
    void *world = *(void**)((char*)actor + 0xB98);
    ZoneLayout *zone = *(ZoneLayout**)((char*)world + 0x3C);

    float ext_x = *(float*)((char*)master + 0x4C);
    float ext_y = *(float*)((char*)master + 0x50);

    int min_x = func_123350(self->m_x - ext_x);
    int min_y = func_123350(self->m_y - ext_y);
    int max_x = func_123350((self->m_x + ext_x) - 0.01f);
    int max_y = func_123350((self->m_y + ext_y) - 0.01f);

    func_314DC0(&min_x, &min_y, &max_x, &max_y, 0, 0, zone->m_width - 1, zone->m_height - 1);

    int pts_x[4];
    int pts_y[4];
    int num_pts = 0;

    short master_type = *(short*)((char*)master + 8);
    if (master_type == 109) {
        num_pts = 4;
        pts_x[0] = min_x; pts_x[1] = min_x; pts_x[2] = min_x + 1; pts_x[3] = min_x + 1;
        pts_y[0] = min_y + 2; pts_y[1] = min_y + 3; pts_y[2] = min_y + 2; pts_y[3] = min_y + 3;
    }

    int modified = 0;
    unsigned char st = (unsigned char)status;

    for (int y = min_y; y <= max_y; ++y) {
        GridCell *row = zone->m_grid[y];
        for (int x = min_x; x <= max_x; ++x) {
            GridCell *tile = &row[x];
            if (is_tile_match(st, tile->m_flag) == 0) {
                continue;
            }
            if (is_excluded(x, y, num_pts, pts_x, pts_y) != 0) {
                continue;
            }
            tile->m_flag = (unsigned char)status;
            modified = 1;
        }
    }

    if (modified != 0) {
        func_1CF9B0(zone, 0, 0, (short)min_x, (short)min_y, (short)max_x, (short)max_y, status, 0LL, 0LL);
    }
}
