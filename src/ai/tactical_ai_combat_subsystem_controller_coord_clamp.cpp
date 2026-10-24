#include "tactical_ai_combat_subsystem_controller_coord_clamp.h"

void func_0032E580(CombatSubsystemControllerInstance *self, float *coords) {
    if (self == 0 || self->m_bounds == 0 || coords == 0) {
        return;
    }

    if (coords[0] < 0.0f) {
        coords[0] = 0.0f;
    } else if (coords[0] > (float)self->m_bounds->max_x - 1.0f) {
        coords[0] = (float)self->m_bounds->max_x - 1.0f;
    }

    if (coords[1] < 0.0f) {
        coords[1] = 0.0f;
    } else if (coords[1] > (float)self->m_bounds->max_y - 1.0f) {
        coords[1] = (float)self->m_bounds->max_y - 1.0f;
    }
}
