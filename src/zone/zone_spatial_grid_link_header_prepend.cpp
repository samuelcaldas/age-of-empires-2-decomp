#pragma exceptions off
#include "zone_spatial_grid_link_header_prepend.h"

extern "C" {
void *func_1143F8(int count, int elem_size);
}

struct Node {
    void *data;
    Node *next;
    Node *prev;
};

struct LinkHeader {
    short count;
    char pad_02[2];
    Node *head;
};

extern "C" void *func_001ECAF0(void *self_ptr, void *elem) {
    LinkHeader *self = (LinkHeader *)self_ptr;
    Node *node = (Node *)func_1143F8(1, sizeof(Node));
    if (node == 0) {
        return 0;
    }
    node->data = elem;
    node->next = self->head;
    node->prev = 0;
    if (self->head != 0) {
        self->head->prev = node;
    }
    self->head = node;
    self->count++;
    return node;
}
