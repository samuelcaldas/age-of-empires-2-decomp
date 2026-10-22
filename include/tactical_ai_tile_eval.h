#ifndef TACTICAL_AI_TILE_EVAL_H
#define TACTICAL_AI_TILE_EVAL_H

#include "tactical_ai_waypoint_cost.h"

extern "C" {
    extern void *D_50A5A0;

    void func_1aca60(void *field20, int x1, int y1, int x2, int y2, int mark);

    /**
     * Tactical AI tile visibility and entity evaluator.
     * VRAM: 0x308C20 - 0x309310 (1,776 bytes slice, 1,768 bytes code).
     */
    void func_00308C20(WaypointCostManager *self, int x, int y, int mark, int radius);
}

#endif // TACTICAL_AI_TILE_EVAL_H
