#ifndef ZONE_SPATIAL_GRID_FREE_SUB_CONTAINER_H
#define ZONE_SPATIAL_GRID_FREE_SUB_CONTAINER_H

struct SubContainerItem {
    void *buffer;
    ~SubContainerItem();
};

#endif // ZONE_SPATIAL_GRID_FREE_SUB_CONTAINER_H
