#include "tactical_ai_combat_subsystem_controller_drag.h"

static inline bool check_drag_gate(CombatSubsystemControllerInstance *self) {
    if (func_185DC0(D_004E3180) != 0) return false;
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    return self->m_field_90 != 0;
}

int func_003299F0(CombatSubsystemControllerInstance *self) {
    if (!check_drag_gate(self)) {
        func_00329450(self, 0);
        return 0;
    }

    unsigned char buf[256];
    sub_0036ddf0(buf);

    short s1 = 0;
    short s2 = 0;
    short s3 = 0;

    SystemManager *mgr = D_004E3180;
    Sub28 *sub28 = mgr->m_sub28;

    if (mgr->m_field_1CC == 18) {
        TargetObj *target = self->m_target;
        if (target != 0) {
            TargetSubCA8 *sub_ca8 = target->m_sub_ca8;
            if (sub_ca8 != 0) {
                float margin = sub28->m_margin_9C;
                float tx = sub_ca8->m_x;
                float ty = sub_ca8->m_y;

                if (buf[166 - 128] < 2) {
                    sub_ca8->m_vtable->func_44(sub_ca8, tx + margin, ty - margin);
                    s1 = 1;
                }
                if (buf[168 - 128] < 2) {
                    sub_ca8->m_vtable->func_44(sub_ca8, tx - margin, ty + margin);
                    s1 = 1;
                }
                if (buf[165 - 128] < 2) {
                    sub_ca8->m_vtable->func_44(sub_ca8, tx - margin, ty - margin);
                    s1 = 1;
                }
                if (buf[167 - 128] < 2) {
                    sub_ca8->m_vtable->func_44(sub_ca8, tx + margin, ty + margin);
                    s1 = 1;
                }

                if (buf[165 - 128] < 2) {
                    s2 = -1;
                } else if (buf[167 - 128] < 2) {
                    s2 = 1;
                }

                if (buf[166 - 128] < 2) {
                    s3 = -1;
                } else if (buf[168 - 128] < 2) {
                    s3 = 1;
                }
            }
        }
    }

    if (s2 != 0 || s3 != 0) {
        unsigned int now = func_2261C0();
        float speed;
        if (self->m_lock_342C == 0) {
            func_00329450(self, 1);
            speed = 1.0f;
        } else {
            unsigned int dt = now - self->m_time_3428;
            float progress = (float)dt / (float)sub28->m_duration_94;
            int floor_val = func_123350(progress);
            float f_floor = (float)floor_val;
            if (progress - f_floor >= 0.5f) {
                f_floor += 0.5f;
            }
            speed = f_floor;
        }

        if (speed > sub28->m_max_speed_98) {
            speed = sub28->m_max_speed_98;
        }

        if (speed > 0.0f) {
            float speed2 = speed * 2.0f;
            if (speed2 > sub28->m_max_speed_98) {
                speed2 = sub28->m_max_speed_98;
            }
            TargetObj *target = self->m_target;
            if (s2 == -1) {
                func_204920(target, 0, target->m_x - speed, target->m_y - speed);
            } else if (s2 == 1) {
                func_204920(target, 0, target->m_x + speed, target->m_y + speed);
            }
            if (s3 == -1) {
                func_204920(target, 0, target->m_x + speed2, target->m_y - speed2);
            } else if (s3 == 1) {
                func_204920(target, 0, target->m_x - speed2, target->m_y + speed2);
            }
            s1 = 1;
            self->m_time_3428 = now;
        }
    }

    if (s2 == 0 && s3 == 0) {
        func_00329450(self, 0);
    }

    if (s1 != 0) {
        self->m_vtable->func_28(self, 1);
        if (self->m_child_3408 != 0) {
            self->m_child_3408->m_vtable->func_28(self->m_child_3408, 1);
        }
    }

    return s1;
}
