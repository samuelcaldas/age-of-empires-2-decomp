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
    Node *node = (Node *)node_ptr;
    if (self->head == 0) {
        return;
    }
    if (node == 0) {
        node = self->head;
        while (node != 0) {
            if (node->data == elem) {
                break;
            }
            node = node->next;
        }
        if (node == 0) {
            return;
        }
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    if (node->prev == 0) {
        self->head = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    func_116F68(node);
    self->count--;
}
