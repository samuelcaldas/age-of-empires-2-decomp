#pragma exceptions off
#include "tactical_ai_player_ops.h"

void func_00305B90(Manager *self) {
}

void *func_00305BA0(Manager *self, int identifier) {
    void *result = 0;
    if (identifier > 0) {
        result = func_332e60(*(void **)((char *)self + 4), identifier - 1);
    }
    return result;
}

void func_00305BD0(Manager *self) {
    if (!self->m_field04) return;

    for (int s0 = 1; s0 < self->m_field04->m_count; s0++) {
        int s1;
        void *item = self->m_field04->m_items[s0];
        if (!item) continue;

        int idx = s0 - 1;
        for (s1 = 0; s1 < self->m_counts[idx]; s1++) {
            func_2e05f0(item, self->m_data[idx][s1], 0);
        }
    }
}
