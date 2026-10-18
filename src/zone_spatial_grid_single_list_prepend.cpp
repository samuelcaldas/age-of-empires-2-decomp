#pragma exceptions off
#include "zone_spatial_grid_single_list_prepend.h"

extern "C" {
void *func_1143F8(int count, int elem_size);
}

struct Node {
    void *data;
    Node *next;
    float fx;
    float fy;
    char flag;
};

struct SingleList {
    Node *head;
};

extern "C" void *func_001ED060(void *self_ptr, void *data, char flag, float fx, float fy) {
    SingleList *self = (SingleList *)self_ptr;
    Node *node = (Node *)func_1143F8(1, sizeof(Node));
    if (node == 0) {
        return 0;
    }
    node->data = data;
    node->next = self->head;
    node->fx = fx;
    node->fy = fy;
    node->flag = flag;
    self->head = node;
    return node;
}
