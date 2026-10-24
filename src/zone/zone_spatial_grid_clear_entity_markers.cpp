#pragma exceptions off
#include "zone_spatial_grid_clear_entity_markers.h"

struct Node {
    char pad_00[0xC];
    Node *next;
};

struct Entity {
    char pad_00[0x54];
    Node *marker_list;
};

extern "C" int func_001EE730(SpatialGrid *self, Entity *entity) {
    Node *curr = entity->marker_list;
    while (curr != 0) {
        Node *next = curr->next;
        func_1EE780(self, curr);
        curr = next;
    }
    entity->marker_list = 0;
    return 1;
}
