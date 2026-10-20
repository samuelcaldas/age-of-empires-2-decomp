#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_CLAMP_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_CLAMP_H

struct ViewBounds {
    char pad00[8];
    int max_x;
    int max_y;
};

struct CombatSubsystemControllerInstance {
    char pad00[308];
    ViewBounds *m_bounds;
};

extern "C" {
    void func_0032E580(CombatSubsystemControllerInstance *self, float *coords);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_COORD_CLAMP_H
