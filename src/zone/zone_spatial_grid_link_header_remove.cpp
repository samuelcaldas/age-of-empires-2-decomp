#pragma exceptions off
#include "zone_spatial_grid_link_header_remove.h"

extern "C" {
void func_116F68(void *ptr);
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

extern "C" void func_001ECA40(void *self_ptr, void *elem, void *node_ptr) {
    LinkHeader *self = (LinkHeader *)self_ptr;
    Node *node = self->head;
    if (node == 0) {
        return;
    }
    if (node_ptr != 0) {
        goto found;
    }
    while (node->data != elem) {
        node = node->next;
        if (node == 0) {
            return;
        }
    }
    goto found2;

found:
    node = (Node *)node_ptr;

found2:
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        self->head = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    func_116F68(node);
    self->count--;
}
