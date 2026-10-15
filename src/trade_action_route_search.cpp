#pragma exceptions off
#include "trade_action_route_search.h"

#define D_00F99910 (*(int**)0x00F99910)
#define D_00F99930 (*(int*)0x00F99930)

int func_0014C110(TradeAction *self, int mode, int *results, int *p_count, int max_results) {
    TargetObj *target = self->m_target;
    void *timer = *(void**)((char*)target->m_game + 2968);

    if (results == 0) {
        return 0;
    }
    int initial_count = *p_count;
    if (initial_count >= max_results) {
        return 0;
    }

    self->Method2C(1, target->x, target->y);

    if (mode == 0) {
        for (int s0 = 0; s0 < D_00F99930; s0++) {
            int id = D_00F99910[s0 * 2];
            TargetObj *v0 = (TargetObj*)func_332e60(timer, id);
            if (!v0) continue;
            if (v0->m_field39 >= 3) continue;
            TimerNode *node = (TimerNode*)v0->m_node_ptr;
            if (node->m_id != 10) continue;

            if (initial_count > 0) {
                int found = 0;
                for (int a1 = 0; a1 < *p_count; a1++) {
                    if (results[a1] == id) {
                        found = 1;
                        break;
                    }
                }
                if (found) continue;
            }

            results[*p_count] = id;
            (*p_count)++;
            if (*p_count >= max_results) break;
        }
    } else {
        for (int s0 = 4; s0 >= 2; s0--) {
            int *table = D_F99910[s0];
            int count = D_F99930[s0];
            for (int s1 = 0; s1 < count; s1++) {
                int id = table[s1 * 2];
                TargetObj *v0 = (TargetObj*)func_332e60(timer, id);
                if (!v0) continue;
                if (v0->m_field39 >= 3) continue;
                if (mode != -1 && *(int*)((char*)v0->m_game + 2976) != mode) continue;

                if (s0 == 3) {
                    TimerNode *node = (TimerNode*)v0->m_node_ptr;
                    if (self->Method58(node->m_id) == 0) continue;
                }

                if (initial_count > 0) {
                    int found = 0;
                    for (int a1 = 0; a1 < *p_count; a1++) {
                        if (results[a1] == id) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) continue;
                }

                results[*p_count] = id;
                (*p_count)++;
                if (*p_count >= max_results) return 0;
            }
        }
    }
    return 0;
}

int func_0014C420(TradeAction *self, int a1) {
    for (int a2 = 0; a2 < self->m_item_count; a2++) {
        if (a1 == self->m_items[a2].m_id) {
            return 1;
        }
    }
    return 0;
}
