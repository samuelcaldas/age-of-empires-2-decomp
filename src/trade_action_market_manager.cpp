#pragma exceptions off
#include "trade_action_market_manager.h"

typedef void (*NotifyFn)(void *mgr, short s0, void *s1, int code, short obj_id, int a6, int a7);

int func_0014D290(TradeAction *self, Message *msg, int param) {
    TargetObj *target = self->m_target;
    void *s2 = 0;
    int s6 = 0;

    if (target->m_field64 != -1) {
        void *game = target->m_game;
        void *timer = *(void**)((char*)game + 2968);
        s2 = func_333b30(timer, target->m_field64);
        if (s2) {
            if (func_1BBE40(s2, 0)) {
                if (*(int*)((char*)s2 + 236) == 1) {
                    s6 = 1;
                }
            }
        }
    }

    short a1_val = self->m_field4A;
    TargetObj *s3 = 0;
    if (a1_val >= 0) {
        void *game = self->m_target->m_game;
        void *timer = *(void**)((char*)game + 2968);
        s3 = (TargetObj*)func_332e60(timer, a1_val);
    }

    short cmd = msg->m_id;

    if (cmd == 616) {
        return 2;
    }
    if (cmd == 615 || cmd == 614 || cmd == 613 || cmd == 617 || cmd == 610 || cmd == 608 || cmd == 607 || cmd == 606 || cmd == 605) {
        return 2;
    }

    if (cmd == 500 || cmd == 527) {
        int s5 = 0;
        for (int a1 = 0; a1 < self->m_waypoint_count; a1++) {
            if (msg->m_id == self->m_waypoints[a1]) {
                s5 = 1;
                break;
            }
            if (a1 >= self->m_waypoint_cap) break;
        }

        self->Method24(msg);
        func_00147CE0(self, msg);

        void *action_mgr = *(void**)((char*)self->m_target->m_game + 6960);
        NotifyFn fn = *(NotifyFn*)(*(char**)action_mgr + 280);
        fn(action_mgr, self->m_target->m_field24, 0, 513, 0, 0, 0);

        if (self->m_waypoint_count < 10) {
            int exists = 0;
            for (int a0 = 0; a0 < self->m_waypoint_count; a0++) {
                if (msg->m_id == self->m_waypoints[a0]) {
                    exists = 1;
                    break;
                }
            }
            if (!exists && self->m_waypoint_count < self->m_waypoint_cap) {
                self->m_waypoints[self->m_waypoint_count++] = msg->m_id;
            }
        }

        func_26AD30(self->m_target, 16, 1);

        if (msg->m_param <= 0) {
            void *mgr = *(void**)((char*)self->m_target->m_game + 6960);
            NotifyFn notify = *(NotifyFn*)(*(char**)mgr + 280);
            notify(mgr, self->m_target->m_field24, 0, 521, 0, 0, 0);
            func_00150F50(self, param);
            return 4;
        }

        TargetObj *s4 = (TargetObj*)func_001510D0(self, msg->m_id);
        if (!s4) {
            return 2;
        }

        void *game = self->m_target->m_game;
        void *mgr = *(void**)((char*)game + 6960);
        typedef int (*CheckFn)(void*, int);
        CheckFn check = *(CheckFn*)(*(char**)mgr + 36);
        if (check(mgr, *(int*)((char*)s4->m_game + 2976)) != 1) {
            return 2;
        }

        if (!s5 && !func_00202B10(self->m_target->m_game) && self->m_field4A != msg->m_id && !s6) {
            func_0014C480(self);
        }

        if (self->m_field48 == 600 && self->m_field4A == msg->m_id) {
            return 2;
        }

        if (self->m_field44 != -1 && self->m_field44 != 711 && !func_00202B10(self->m_target->m_game)) {
            return 2;
        }

        if (s2 && !func_00202B10(self->m_target->m_game) && !func_1BBE40(s2, 1)) {
            return 2;
        }

        return 2;
    }

    return 2;
}
