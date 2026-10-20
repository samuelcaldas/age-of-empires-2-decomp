#ifndef ZONE_SPATIAL_GRID_BLOCK63_LAYOUT_H
#define ZONE_SPATIAL_GRID_BLOCK63_LAYOUT_H

struct ListNodeLayout {
    void *reserved;
    void **element;
    ListNodeLayout *next;
};

struct SpatialGridLayout {
    void *vtable;
    int prefix[4];
    ListNodeLayout *head;
    int remaining_prefix[2];
    void *tables[10];
    unsigned char buckets[10][256];
    int counts[10];
    int metadata[10];
    int suffix[7];
};

#endif
