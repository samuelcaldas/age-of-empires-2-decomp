#ifndef UNIT_ACTION_SPATIAL_NODE_H
#define UNIT_ACTION_SPATIAL_NODE_H

#include "unit_action_tile_node.h"

extern "C" {
    void func_00335040(void *arg0, short val);
    void func_003352B0(void *arg0, short val);
    void func_333b30(void *arg0, void *arg1);

    void func_00269FF0(void *node, float x, float y);
    void func_0026A0C0(ActionRebind *self, float x, float y);
    void func_0026A1B0(void *node, float x, float y);
    void func_0026A2A0(void *node);
    void func_0026A300(void *node, short count);
    void func_0026A420(void *node);
}

#endif // UNIT_ACTION_SPATIAL_NODE_H
