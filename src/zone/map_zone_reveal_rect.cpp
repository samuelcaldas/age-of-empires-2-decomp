#include "map_zone_reveal_rect.h"

extern "C" {
    extern int D_004E3058;
    extern int *D_50A5A0[];
    void func_002082B0(void *obj, int x, int y);
}

int func_001384C0(ZoneMapReveal *self, int min_x, int min_y, int max_x, int max_y, int flag) {
    if (D_004E3058) {
        return 0;
    }
    int revealed_count = 0;
    ZonePlayerMgr *mgr = self->m_player_mgr;
    int is_ally = 0;
    StancePlayer *ally_player = 0;
    if (mgr->m_player_id != -1) {
        StancePlayer *player = mgr->m_players[mgr->m_player_id];
        if (player->m_stance[self->m_world->m_fieldBA0] == 1) {
            is_ally = 1;
        }
    }
    if (is_ally) {
        ally_player = mgr->m_players[mgr->m_player_id];
    }

    if (min_x >= self->m_width || max_x < 0) {
        return 0;
    }
    if (min_y >= self->m_height || max_y < 0) {
        return 0;
    }
    if (min_x < 0) {
        min_x = 0;
    }
    if (max_x >= self->m_width) {
        max_x = self->m_width - 1;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if (max_y >= self->m_height) {
        max_y = self->m_height - 1;
    }

    int min_x_bytes = min_x * 4;
    int tile_col_offset = min_x * 28;
    for (int y = min_y; y <= max_y; y++) {
        unsigned char *tile_ptr = self->m_row_ptrs[y] + min_x;
        int *flag_ptr = *(int**)((char*)D_50A5A0 + y * 4) + min_x;
        char *tile28 = self->m_fieldC->m_grid[y] + tile_col_offset;
        for (int x = min_x; x <= max_x; x++, tile_ptr++, flag_ptr++, tile28 += 28) {
            if (*tile_ptr == 255) {
                revealed_count++;
                self->m_field1C++;
                func_002082B0(self->m_world->m_fieldBB0, x, y);
                if (is_ally) {
                    func_002082B0((char*)ally_player + 3012, x, y);
                }
                if (flag) {
                    tile28[9] = (char)128;
                }
                *flag_ptr |= self->m_field2C;
                *tile_ptr = 0;
            }
        }
    }
    return revealed_count;
}
