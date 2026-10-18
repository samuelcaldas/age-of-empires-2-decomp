#ifndef ZONE_SPATIAL_GRID_NODE_POOL_ADD_ZONE_H
#define ZONE_SPATIAL_GRID_NODE_POOL_ADD_ZONE_H

struct NodePool;

extern "C" {
void func_001F21E0(NodePool *self, int num_items);
void *func_117CAC(void *dst, int val, int size);
void *func_118de0(const char *format, const char *file, int line, int max_zones);
}

#endif
