#include "tactical_ai_combat_subsystem_controller_processor.h"

static inline bool check_controller_gate(CombatSubsystemControllerInstance *self) {
    int mode = D_004E3180->m_mode;
    if (mode != 4 && mode != 6) {
        if (D_004E3180->m_mode != 7) {
            if (mode != 5) return false;
        }
    }
    if (func_185DC0(D_004E3180) != 0) return false;
    if (D_004E3180->m_sub28->m_field_80 == 0) return false;
    if (func_1F26F0((void*)0xA80BB0) != 0) return false;
    if (func_1F26D0((void*)0xA80BB0) != 0 && func_1F26D0((void*)0xA80BB0) != self) return false;
    if (self->m_lock_342C != 0) return false;
    return self->m_field_90 != 0;
}

int func_00329550(CombatSubsystemControllerInstance *self) {
    if (!check_controller_gate(self)) {
        func_00329350(self, 0);
        return 0;
    }

    int s0 = 0;
    short s1 = 0;
    int rect[4]; int pos[2];
    func_2254D0(self->m_obj_20->m_field_4, rect);
    func_225560(pos);
    Sub28 *sub28 = D_004E3180->m_sub28;
    if ((short)func_225520(1) >= 0 && (short)func_225520(2) >= 0 && self->m_field_190 != 2) {
        int margin = sub28->m_margin_88;
        if (pos[0] < rect[0] + margin) { s0 = -1; }
        else if (rect[2] - margin - 12 < pos[0]) { s0 = 1; }
        if (pos[1] < rect[1] + margin) { s1 = -1; }
        else if (rect[3] - margin - 17 < pos[1]) { s1 = 1; }
    }
    if (s0 != 0 || s1 != 0) {
        unsigned int now = func_2261C0();
        float speed;
        if (self->m_mode_3410 == 0) {
            func_00329350(self, 1); speed = 1.0f;
        } else {
            unsigned int dt = now - self->m_time_340C;
            float progress = (float)dt / (float)sub28->m_duration_94;
            int floor_val = func_123350(progress);
            float f_floor = (float)floor_val;
            if (progress - f_floor >= 0.5f) { f_floor += 0.5f; }
            speed = f_floor;
        }
        if (speed > sub28->m_max_speed_90) { speed = sub28->m_max_speed_90; }
        if (speed > 0.0f) {
            float speed2 = speed * 2.0f;
            if (speed2 > sub28->m_max_speed_90) { speed2 = sub28->m_max_speed_90; }
            TargetObj *target = self->m_target;
            if (s0 == -1) { func_204920(target, 0, target->m_x - speed, target->m_y - speed); }
            else if (s0 == 1) { func_204920(target, 0, target->m_x + speed, target->m_y + speed); }
            if (s1 == -1) { func_204920(target, 0, target->m_x + speed2, target->m_y - speed2); }
            else if (s1 == 1) { func_204920(target, 0, target->m_x - speed2, target->m_y + speed2); }
            self->m_vtable->func_28(self, 1);
            if (self->m_child_3408 != 0) { self->m_child_3408->m_vtable->func_28(self->m_child_3408, 1); }
            self->m_time_340C = now;
        }
    }
    if (s0 == 0 && s1 == 0) {
        func_00329350(self, 0);
    }
    return self->m_mode_3410;
}
