#pragma exceptions off
#include "tactical_ai_player_dispatch.h"

void func_00305CB0(DispatchManager *self, DispatchPlayer *player) {
    int s7 = 0;
    if (!player) return;

    int s0 = player->m_player_id - 1;
    if (s0 < 0) return;

    for (int s1 = 0; s1 < self->m_counts[s0]; s1++) {
        func_2e05f0(player, self->m_data[s0][s1], 0);
    }

    int a0;
    for (int a1 = 0; a1 < self->m_counts2[s0]; a1++) {
        a0 = self->m_data2[s0][a1];
        if (a0 < 0) continue;

        if (a0 < player->m_item_count) {
            if (player->m_items[a0]) {
                player->m_items[a0]->m_field43 = 1;
                player->m_items[a0]->m_field42 = 0;
            }
        }
    }

    int target = 109;
    int one = 1;
    int t0;
    for (int v0 = 0; v0 < self->m_counts3[s0]; v0++) {
        t0 = self->m_data3[s0][v0];
        if (t0 < 0) continue;

        if (t0 < player->m_item_count) {
            if (player->m_items[t0]) {
                if (t0 == target) {
                    s7 = 1;
                }
                player->m_items[t0]->m_field43 = one;
                player->m_items[t0]->m_field42 = 0;
            }
        }
    }

    func_2d42a0(player->m_field1B34);

    if (*(int *)((char *)D_004E3180 + 456) != 7) {
        switch (self->m_mode[s0]) {
        case 1:
            func_2e0630(player, 25);
            break;
        case 2:
            func_2e0630(player, 23);
            break;
        case 3:
            func_2e0630(player, 24);
            break;
        case 4:
            func_2e0630(player, 39);
            break;
        }
    }

    if (s7 == 1) {
        *(float *)((char *)player->m_fieldBAC + 192) = 1.0f;
    }
}
