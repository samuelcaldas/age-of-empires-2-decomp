#ifndef ZONE_SPATIAL_GRID_NODE_POOL_EXPAND_H
#define ZONE_SPATIAL_GRID_NODE_POOL_EXPAND_H

struct NodePool;

extern "C" {
void func_001F20E0(NodePool *self, int new_cap);
void *func_117CAC(void *dst, int val, int size);
void *func_118de0(const char *format, const char *file, int line, int max_val);
}

#endif
