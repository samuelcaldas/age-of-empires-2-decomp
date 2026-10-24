#pragma exceptions off
#include "trade_action_pathing.h"

int func_0014A640(TradeAction *self, int a1, int a2) {
    if (a2 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method416(a1) == 1) {
        func_001471B0(self, 617);
        func_14BD20(self, a1, -1.0f, -1.0f, -1.0f);
        return 1;
    }
    return 0;
}

int func_0014A6E0(TradeAction *self, int a1, float x, float y, float z) {
    if (a1 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method424(x, y, z) == 1) {
        func_001471B0(self, 614);
        func_14BD20(self, -1, x, y, z);
        return 1;
    }
    return 0;
}

int func_0014A7A0(TradeAction *self, int a1, float x, float y, float z) {
    if (a1 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method420(x, y, self->m_target->z) == 1) {
        TargetObj *s0 = self->m_target;
        func_001471B0(self, 621);
        if (!s0) {
            func_14bd90(self, self->m_target->m_field24, -1, 0.0f, 0.0f, 0.0f);
        } else {
            func_14bd90(self, self->m_target->m_field24, s0->m_node->m_id, s0->x, s0->y, s0->z);
        }
        return 1;
    }
    return 0;
}

int func_0014A880(TradeAction *self, int a1, int a2) {
    if (a2 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method372(a1) == 1) {
        void *game = self->m_target->m_game;
        void *timer = *(void**)((char*)game + 2968);
        TargetObj *s0 = (TargetObj*)func_332e60(timer, a1);
        func_001471B0(self, 610);
        if (!s0) {
            float f = 0.0f;
            func_14BD20(self, a1, 0.0f, 0.0f, f);
        } else {
            func_14BD20(self, a1, s0->x, s0->y, s0->z);
        }
        return 1;
    }
    return 0;
}

int func_0014A970(TradeAction *self, int a1, int a2) {
    if (a2 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method376(a1) == 1) {
        void *game = self->m_target->m_game;
        void *timer = *(void**)((char*)game + 2968);
        TargetObj *s0 = (TargetObj*)func_332e60(timer, a1);
        func_001471B0(self, 610);
        if (!s0) {
            float f = 0.0f;
            func_14BD20(self, a1, 0.0f, 0.0f, f);
        } else {
            func_14BD20(self, a1, s0->x, s0->y, s0->z);
        }
        return 1;
    }
    return 0;
}

int func_0014AA60(TradeAction *self, int a1, float x, float y, float z) {
    if (a1 == 0 && self->m_field48 != -1) {
        return 0;
    }
    if (self->m_target->Method380(x, y, z) == 1) {
        func_001471B0(self, 610);
        func_14BD20(self, -1, x, y, z);
        return 1;
    }
    return 0;
}
