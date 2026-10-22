#ifndef TACTICAL_AI_GRID_MARKER_H
#define TACTICAL_AI_GRID_MARKER_H

#include "tactical_ai_waypoint_cost.h"

extern "C" {
    void func_1acf10(void *field20, int x1, int y1, int x2, int y2, int mark);

    /**
     * Tactical AI grid tile marker / box plotter.
     * VRAM: 0x308A70 - 0x308C20 (432 bytes slice, 424 bytes code).
     */
    void func_00308A70(WaypointCostManager *self, int x, int y, int mark, int radius);
}

#endif // TACTICAL_AI_GRID_MARKER_H
