#pragma exceptions off
#include "zone_spatial_grid_link_header_clear.h"

extern "C" {
void func_116F68(void *ptr);
}

struct Node {
    char pad_04[0x4];
    Node *next;
};

struct LinkHeader {
    short count;
    char pad_02[2];
    Node *head;
};

extern "C" void func_001EC9F0(void *self_ptr) {
    LinkHeader *self = (LinkHeader *)self_ptr;
    Node *curr = self->head;
    while (curr != 0) {
        Node *next = curr->next;
        func_116F68(curr);
        curr = next;
    }
    self->head = 0;
    self->count = 0;
}
