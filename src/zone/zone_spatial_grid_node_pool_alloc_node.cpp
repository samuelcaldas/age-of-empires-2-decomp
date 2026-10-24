#pragma exceptions off
#include "zone_spatial_grid_node_pool_alloc_node.h"

struct NodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void **table_138814;
    int count_138818;
    int field_13881C;
    void *field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" void *func_001F2320(NodePool *self) {
    if (self->field_138830 == 0) {
        func_1F21E0(self, self->capacity_138834);
    }
    if (self->field_138820 != 0) {
        void *node = self->field_138820;
        self->field_138820 = *(void **)((char *)node + 12);
        self->field_138830--;
        return node;
    }
    char *node = (char *)self->table_138810[self->field_138824];
    node += self->field_138828 * 64;
    self->field_138830--;
    self->field_138828++;
    if (self->field_138828 == (int)(long)self->table_138814[self->field_138824]) {
        self->field_138824++;
        self->field_138828 = 0;
        if (self->field_138824 == self->count_138818) {
            self->field_138824 = -1;
        }
    }
    return node;
}
