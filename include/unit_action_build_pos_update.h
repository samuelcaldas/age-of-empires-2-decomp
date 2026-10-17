#ifndef UNIT_ACTION_BUILD_POS_UPDATE_H
#define UNIT_ACTION_BUILD_POS_UPDATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates building action spatial footprint on map grid during movement.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param x Target coordinate X.
 * @param y Target coordinate Y.
 * @param z Target coordinate Z.
 * @return Result returned by movement function func_197E40.
 */
float func_0026F9E0(ActionRebind *self, float x, float y, float z);

int func_123350(float val);
float func_197E40(void *action, float x, float y, float z);
float func_00197E40(void *action, float x, float y, float z);
void func_1CA430(void *map, int min_x, int min_y, int max_x, int max_y);
void func_001CA430(void *map, int min_x, int min_y, int max_x, int max_y);
void func_1CA180(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y);
void func_001CA180(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y);
char func_1CA7F0(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y);
char func_001CA7F0(void *map, int tile_x, int tile_y, int min_x, int min_y, int max_x, int max_y);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_POS_UPDATE_H
