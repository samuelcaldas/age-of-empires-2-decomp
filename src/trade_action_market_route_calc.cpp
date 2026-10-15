#pragma exceptions off
#include "trade_action_market_route_calc.h"

int func_0014F250(TradeAction *self, int *out_x, int a2, int a3) {
    short s5 = self->m_field44;
    if (s5 == 705) {
        if (self->m_field50 != -1.0f && self->m_field54 != -1.0f) {
            return 0;
        }
    }

    TargetObj *s4 = self->m_target;
    int s7 = -1;
    float f20 = s4->x;
    int tile_x = func_123350(f20);
    float f21 = s4->y;
    int tile_y = func_123350(f21);

    TimerNode *node = s4->m_node;
    int s2 = func_123350(node->m_radius) + 3;

    int s0 = func_123350(f20 - (float)s2);
    int s1 = func_123350(f20 + (float)s2);
    int s3 = func_123350(f21 - (float)s2);
    s2 = func_123350(f21 + (float)s2);

    if (s5 == 730) {
        float f50 = self->m_field50;
        s0 = func_123350(f50) - 7;
        s1 = func_123350(f50) + 7;
        float f54 = self->m_field54;
        s3 = func_123350(f54) - 7;
        s2 = func_123350(f54) + 7;
    }

    void *world = s4->m_game;
    void *mgr = *(void**)((char*)world + 2968);
    void *mgr2 = *(void**)((char*)world + 2964);
    void *map = *(void**)((char*)mgr + 60);

    if (s0 < 0) s0 = 0;
    int map_w = *(int*)((char*)map + 8);
    if (s1 > map_w - 1) s1 = map_w - 1;
    if (s3 < 0) s3 = 0;
    int map_h = *(int*)((char*)map + 12);
    if (s2 > map_h - 1) s2 = map_h - 1;

    int rand_val = func_001AAB30() % 3;
    int v224 = func_269FF0(self->m_target, rand_val);
    int v256 = v224 & 0xff;

    int out_tile_x = 0;
    int out_tile_y = 0;

    for (int y = s3; y <= s2; y++) {
        int dy = y - tile_y;
        int dy_sq = dy * dy;

        for (int x = s0; x <= s1; x++) {
            if (func_0014BDC0(self, mgr2, x, y) != 0) {
                continue;
            }
            if (func_269E50(self->m_target, x, y) != v256) {
                continue;
            }
            if (self->m_target->Method300((float)x, (float)y) == 0) {
                continue;
            }
            if (a3 != 0) {
                if (func_00149D90(self, x, y) != 0) {
                    continue;
                }
            }

            int dx = x - tile_x;
            int dist_sq = dx * dx + dy_sq;
            if (self->m_field50 != -1.0f) {
                int d54 = y - func_123350(self->m_field54);
                int d50 = x - func_123350(self->m_field50);
                dist_sq += d54 * d54 + d50 * d50;
            }

            if (s7 == -1 || dist_sq < s7 + v224) {
                s7 = dist_sq;
                *out_x = x;
                *(int*)a2 = y;
            }
        }
    }

    if (s7 == -1) {
        return 0;
    }

    out_tile_x = *out_x;
    out_tile_y = *(int*)a2;

    int dx_end = out_tile_x - func_123350(self->m_target->x);
    int dy_end = out_tile_y - func_123350(self->m_target->y);
    int final_dist_sq = dx_end * dx_end + dy_end * dy_end;
    if (final_dist_sq < 36) {
        return 0;
    }

    self->Method60(out_tile_x, out_tile_y);
    return 1;
}
