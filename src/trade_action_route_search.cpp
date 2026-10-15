#pragma exceptions off
#include "trade_action_route_search.h"

void func_0014C110(TradeAction *self, int mode, int *results, int *p_count, int max_results) {
    TargetObj *target = self->m_target;
    void *timer = *(void**)((char*)target->m_game + 2968);

    if (results == 0) {
        return;
    }
    int initial_count = *p_count;
    if (initial_count >= max_results) {
        return;
    }

    self->Method2C(1, target->x, target->y);

    if (mode == 0) {
        for (int s0 = 0; s0 < D_00F99930[0]; s0++) {
            SearchItem *item = &D_00F99910[0][s0];
            int id = item->id;
            TargetObj *v0 = (TargetObj*)func_332e60(timer, id);
            if (!v0) {
                continue;
            }
            if (v0->m_field39 >= 3) {
                continue;
            }
            TimerNode *node = v0->m_node;
            if (node->m_id != 10) {
                continue;
            }

            if (initial_count > 0) {
                int a1 = 0;
                while (a1 < *p_count) {
                    if (results[a1] == item->id) {
                        break;
                    }
                    a1++;
                }
                if (a1 < *p_count) {
                    continue;
                }
            }

            results[*p_count] = item->id;
            (*p_count)++;
            if (*p_count >= max_results) {
                return;
            }
        }
    } else {
        for (int s0 = 4; s0 >= 2; s0--) {
            SearchItem *table = D_00F99910[s0];
            int count = D_00F99930[s0];
            for (int s1 = 0; s1 < count; s1++) {
                SearchItem *item = &table[s1];
                int id = item->id;
                TargetObj *v0 = (TargetObj*)func_332e60(timer, id);
                if (!v0) {
                    continue;
                }
                if (v0->m_field39 >= 3) {
                    continue;
                }
                if (mode != -1 && *(int*)((char*)v0->m_game + 2976) != mode) {
                    continue;
                }

                if (s0 == 3) {
                    TimerNode *node = v0->m_node;
                    if (self->Method58(node->m_id) == 0) {
                        continue;
                    }
                }

                if (initial_count > 0) {
                    int a1 = 0;
                    while (a1 < *p_count) {
                        if (results[a1] == item->id) {
                            break;
                        }
                        a1++;
                    }
                    if (a1 < *p_count) {
                        continue;
                    }
                }

                results[*p_count] = item->id;
                (*p_count)++;
                if (*p_count >= max_results) {
                    return;
                }
            }
        }
    }
}

int func_0014C420(TradeAction *self, int a1) {
    for (int a2 = 0; a2 < self->m_item_count; a2++) {
        if (a1 == self->m_items[a2].m_id) {
            return 1;
        }
    }
    return 0;
}
