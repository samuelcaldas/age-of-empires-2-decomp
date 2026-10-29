#pragma exceptions off
#include "zone_spatial_grid_clear_active_markers.h"

struct MarkerNode {
    char pad_00[0xC];
    MarkerNode *next;
    char pad_10[8];
    unsigned int coord;
};

struct SpatialGrid {
    char pad_00[0x12B438];
    int **grid_table;
    int marker_count;
    char pad_after[0x12B5AC - 0x12B43C - 4];
    MarkerNode *marker_head;
};

extern "C" void func_001EE080(SpatialGrid *self) {
    MarkerNode *curr = self->marker_head;
    while (curr != 0) {
        unsigned char y = (unsigned char)curr->coord;
        unsigned int x = (curr->coord & 0xFF00) >> 8;
        self->grid_table[y][x] ^= 0x80;
        MarkerNode *next = curr->next;
        func_1EE780(self, curr);
        self->marker_count--;
        curr = next;
    }
    self->marker_head = 0;
}
