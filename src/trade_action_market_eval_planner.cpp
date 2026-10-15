#pragma exceptions off
#include "trade_action_market_eval_planner.h"

int func_0014EE90(TradeAction *self, int category, int target_identifier, int limit, int *distance) {
    TargetObj *target = self->m_target;
    int mode = 2;

    void *world = target->m_world;
    void *game_mgr = *(void **)((char *)world + 0xB98);
    TargetObj *s3 = (TargetObj *)func_332e60(game_mgr, target_identifier);

    if (target_identifier != -1 && s3 != 0) {
        if ((func_269FF0(s3) & 0xFF) == (func_269FF0(self->m_target) & 0xFF)) {
            target = s3;
            mode = 0;
        }
    }

    if (limit == -1) {
        if (mode == 0) mode = 1;
        if (mode == 2) mode = 3;
    }

    int visited[100];
    int count = 0;
    int tested = 0;
    bool retry = false;
    int y;

    func_1E9130(D_004E3244->m_controller);

    while (mode < 4 && count < 100 && tested < 30) {
        while (count < 100 && tested < 30) {
            int x = func_123350(target->pos_x);
            y = func_123350(target->pos_y);
            int team = func_269FF0(target) & 0xFF;

            void *search_mgr = *(void **)((char *)self->m_target->m_world + 0xC64);
            CandidateNode *cand = func_3283C0(search_mgr, x, y, team, category, visited, count);

            if (!cand) break;

            TargetObj *cand_obj = func_001510D0(self, cand->m_id);
            if (!cand_obj) {
                visited[count++] = cand->m_id;
                continue;
            }

            TargetObj *my_target = self->m_target;
            if (my_target == target) {
                float max_d = 5.0f + *(float *)((char *)my_target->m_field04 + 0x1C);
                if ((float)cand->m_dist > max_d) break;
            }

            if (s3 == target) {
                float max_d = 10.0f + *(float *)((char *)s3->m_field04 + 0x1C);
                if ((float)cand->m_dist > max_d) break;
            }

            if (my_target->m_field39 < 2) {
                visited[count++] = cand->m_id;
                tested++;
                continue;
            }

            if (limit != -1 && (mode == 0 || mode == 2)) {
                if ((int)cand_obj->m_field3A >= limit) {
                    visited[count++] = cand->m_id;
                    tested++;
                    continue;
                }
            }

            if (my_target->Method1B8(cand->m_id, 0, -1, -1, retry, 0.0f) == 1) {
                if (distance) *distance = cand->m_dist;
                return cand->m_id;
            }

            visited[count++] = cand->m_id;
            tested++;
            retry = true;
        }

        if (mode == 0) {
            mode = 1;
        } else if (mode == 1) {
            target = self->m_target;
            if (limit == -1) mode = 3;
            else mode = 2;
        } else if (mode == 2) {
            mode = 3;
        } else if (mode == 3) {
            break;
        }
    }

    return -1;
}
