#pragma exceptions off
#include "trade_action_market_ops.h"

extern "C" {
    extern float D_004E2824;
}

void func_00149450(MarketScoring *self, const float *weights) {
    float range[4];
    range[1] = self->m_bounds[1].max - self->m_bounds[1].min;
    range[0] = self->m_bounds[0].max - self->m_bounds[0].min;
    range[3] = self->m_bounds[3].max - self->m_bounds[3].min;
    range[2] = self->m_bounds[2].max - self->m_bounds[2].min;
    float eps = D_004E2824;

    for (int i = 0; i < self->m_count; i++) {
        if (self->m_items[i].m_mode == 1) {
            if (range[3] < eps) {
                self->m_items[i].m_score1 = 10.0f;
            } else {
                self->m_items[i].m_score1 = 10.0f - 10.0f * ((self->m_items[i].m_val1 - self->m_bounds[3].min) / range[3]);
            }
            if (range[2] < eps) {
                self->m_items[i].m_score2 = 75.0f;
            } else {
                self->m_items[i].m_score2 = 75.0f - 75.0f * ((self->m_items[i].m_val2 - self->m_bounds[2].min) / range[2]);
            }
        } else {
            if (range[1] < eps) {
                self->m_items[i].m_score1 = 10.0f;
            } else {
                self->m_items[i].m_score1 = 10.0f - 10.0f * ((self->m_items[i].m_val1 - self->m_bounds[1].min) / range[1]);
            }
            if (range[0] < eps) {
                self->m_items[i].m_score2 = 75.0f;
            } else {
                self->m_items[i].m_score2 = 75.0f - 75.0f * ((self->m_items[i].m_val2 - self->m_bounds[0].min) / range[0]);
            }
        }

        if (self->m_items[i].m_res_idx != (char)-1) {
            self->m_items[i].m_score3 = 10.0f * weights[self->m_items[i].m_res_idx];
        } else {
            self->m_items[i].m_score3 = 0.0f;
        }

        self->m_items[i].m_total_score = self->m_items[i].m_score4 + (self->m_items[i].m_score3 + (self->m_items[i].m_score1 + self->m_items[i].m_score2));
    }
}

int func_00149600(const void *a, const void *b) {
    float f0 = *(float*)((char*)a + 0x1C);
    float f1 = *(float*)((char*)b + 0x1C);
    if (f0 == f1) return 0;
    if (f0 < f1) return 1;
    if (f0 > f1) return -1;
    return 0;
}
