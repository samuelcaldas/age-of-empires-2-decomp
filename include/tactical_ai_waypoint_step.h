#ifndef TACTICAL_AI_WAYPOINT_STEP_H
#define TACTICAL_AI_WAYPOINT_STEP_H

#include "tactical_ai_action_waypoints.h"

extern "C" {
    extern void *D_004E3180;

    void *func_186010(void *global);
    void func_204920(void *renderer, int zero, float x, float y);
    int func_123350(float val);
    void func_204910(void *target, int tx, int ty);

    /**
     * Waypoint visualizer step and ring buffer index coordinator.
     * VRAM: 0x307A00 - 0x307B80 (384 bytes slice, 376 bytes code).
     */
    void func_00307A00(WaypointActionManager *self);
}

#endif // TACTICAL_AI_WAYPOINT_STEP_H
