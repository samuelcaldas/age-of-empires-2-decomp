#pragma exceptions off
#include "trade_action_route_advance.h"

extern "C" {
float sqrtf(float);
}

int func_0014B310(TradeAction *self, int a1, int a2) {
    if ((self->m_mode == 2 || self->m_mode == 3) && (*(void**)((char*)self->m_target->m_game + 2976) != 0)) {
        return 0;
    }
    if (a1 == 0 && self->m_field48 != -1) {
        return 0;
    }

    float f20 = 0.0f;
    int s2 = -1;
    float f21 = 0.0f;
    int s1 = 0;

    for (int s3 = 0; s3 < self->m_waypoint_count; s3++) {
        short wp_id;
        if (self->m_waypoint_cap - 1 < s3) {
            wp_id = self->m_waypoints[0];
        } else {
            wp_id = self->m_waypoints[s3];
        }
        TargetObj *v0 = (TargetObj*)func_332e60(*(void**)((char*)self->m_target->m_game + 2968), wp_id);
        if (!v0) {
            continue;
        }
        TargetObj *target = self->m_target;
        TimerNode *node = v0->m_node;
        float dx = v0->x - target->x;
        float dy = v0->y - target->y;
        f20 += dx;
        if (node->m_id == 22) {
            f21 += dy;
            if (s2 == -1) {
                s1 = 1;
                s2 = v0->m_field24;
            }
        } else {
            f21 += dy;
        }
    }

    if (self->m_waypoint_count == 0) {
        if (a2 != self->m_target->m_field24) {
            TargetObj *v0 = (TargetObj*)func_332e60(*(void**)((char*)self->m_target->m_game + 2968), a2);
            if (v0) {
                TargetObj *target = self->m_target;
                float dx = v0->x - target->x;
                float dy = v0->y - target->y;
                f20 += dx;
                f21 += dy;
            }
        }
    }

    short s3 = self->m_target->m_node->m_id;
    if (func_00202B10(self->m_target->m_game) == 1) {
        if (self->m_target->Method276() > 0.0f) {
            if (s3 != 21 && s3 != 2 && s3 != 20 && s3 != 22 && s3 != 53 && s3 != 3 && s3 != 52 && s3 != 27 && s3 != 39 && s3 != 54) {
                if (s1 == 1 && a2 == -1) {
                    self->Method2C(self->m_target->x, self->m_target->y);
                }
            }
        }
    }

    for (int s1_idx = 0; s1_idx < *(int*)0x00F99934; s1_idx++) {
        int *table = *(int**)0x00F99914;
        if (self->m_target->m_field24 == table[s1_idx * 2]) {
            continue;
        }
        TargetObj *s3_obj = (TargetObj*)func_001510D0(self);
        short s4 = -1;
        if (s3_obj) {
            s4 = s3_obj->m_node->m_id;
            if (s3_obj->Method356() && s3_obj->m_field39 < 3 && s3_obj->Method276() >= D_004E2824) {
                if (s4 != 3 && s4 != 52 && s4 != 27 && s4 != 39 && s4 != 54) {
                    TargetObj *sub = s3_obj->Method356();
                    if (func_001471A0(*(void**)sub) == -1) {
                        if ((s3_obj->Method472() & 0xff) == 0) {
                            TargetObj *v0_sub = s3_obj->Method356();
                            v0_sub->Method344(1, s2);
                        }
                    }
                }
            }
        }
    }

    float f22 = self->m_target->Method276() * 2.0f;
    if (func_00202B10(self->m_target->m_game) == 1) {
        if (self->m_target->m_node->m_id == 20) {
            f22 = 10.0f;
        }
    }

    float len_sq = f20 * f20 + f21 * f21;
    if (len_sq < D_004E2824) {
        f20 = -1.0f + 2.0f * ((float)func_1AAB30() / 32767.0f);
        f21 = -1.0f + 2.0f * ((float)func_1AAB30() / 32767.0f);
        len_sq = f20 * f20 + f21 * f21;
    }

    float len = sqrtf(len_sq);
    float dir_x = -f20 / len;
    float dir_y = -f21 / len;
    float dest_x = self->m_target->x + f22 * dir_x;
    float dest_y = self->m_target->y + f22 * dir_y;

    if (*(void**)((char*)self->m_target->m_game + 2976) != 0 && self->m_mode == 1 && self->m_target->m_field64 == -1) {
        float dx = self->m_field154 - dest_x;
        float dy = self->m_field158 - dest_y;
        float dist = sqrtf(dx * dx + dy * dy);
        if (dist > 5.0f) {
            dest_x = self->m_field154 + 5.0f * dir_x;
            dest_y = self->m_field158 + 5.0f * dir_y;
        }
    }

    return self->MethodA0(1, dest_x, dest_y, self->m_target->z);
}

int func_0014B8E0(void *self) {
    return 0;
}
