#pragma exceptions off
#include "zone_spatial_grid_single_list_destructor.h"

extern "C" {
void func_116F68(void *ptr);
void func_100670(void *ptr);
}

struct Node {
    char pad_04[0x4];
    Node *next;
};

struct SingleList {
    Node *head;
};

extern "C" void *func_001ECFE0(void *self_ptr, int flag) {
    SingleList *self = (SingleList *)self_ptr;
    if (self == 0) {
        return 0;
    }
    while (self->head != 0) {
        Node *next = self->head->next;
        func_116F68(self->head);
        self->head = next;
    }
    if (flag > 0) {
        func_100670(self);
    }
    return self;
}
