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

extern "C" void *func_001ECFE0(void *self_ptr, short flag) {
    if (self_ptr != 0) {
        SingleList *self = (SingleList *)self_ptr;
        while (self->head != 0) {
            Node *next = self->head->next;
            func_116F68(self->head);
            self->head = next;
        }
        if (flag > 0) {
            func_100670(self_ptr);
        }
    }
    return self_ptr;
}
