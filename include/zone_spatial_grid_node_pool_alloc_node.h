#ifndef ZONE_SPATIAL_GRID_NODE_POOL_ALLOC_NODE_H
#define ZONE_SPATIAL_GRID_NODE_POOL_ALLOC_NODE_H

struct NodePool;

extern "C" {
void *func_001F2320(NodePool *self);
void func_1F21E0(NodePool *self, int num_items);
}

#endif
