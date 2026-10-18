#ifndef ZONE_SPATIAL_GRID_NODE_POOL_SETUP_H
#define ZONE_SPATIAL_GRID_NODE_POOL_SETUP_H

struct NodePool;

extern "C" {
int func_001F1ED0(NodePool *self, void *p1, int count);
int func_001F1EE0(NodePool *self, void *p1, int count);
void *func_118DE0(int format, int file, int line);
void func_1F20E0(NodePool *self, int val);
void func_1F21E0(NodePool *self, void *p1);
}

#endif
