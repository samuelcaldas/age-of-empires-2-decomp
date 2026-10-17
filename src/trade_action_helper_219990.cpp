#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00116F68(void *ptr);
void func_00217B50(void *self, int arg1);

typedef void (*VMethod28)(void *, int);

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    int val_c;
    char byte_10;
    char pad_11[0x13];
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

static ActionListItem *unlink_node(char *self_bytes, int index) {
    if (index == 0) {
        ActionListItem *node = *(ActionListItem **)(self_bytes + 0x11C);
        *(ActionListItem **)(self_bytes + 0x11C) = node->next;
        return node;
    }

    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    int idx = 0;
    int target = index - 1;
    while (idx != target) {
        curr = curr->next;
        idx++;
    }
    ActionListItem *node = curr->next;
    curr->next = node->next;
    return node;
}

static void free_node(ActionListItem *node) {
    if (node->text != 0) {
        func_00116F68(node->text);
    }
    if (node->extra_text != 0) {
        func_00116F68(node->extra_text);
    }
    func_00116F68(node);
}

int func_00219990(void *self, int index) {
    char *self_bytes = (char *)self;
    short count = *(short *)(self_bytes + 0x120);

    if (index < 0 || index >= (int)count) {
        return 0;
    }

    ActionListItem *node = unlink_node(self_bytes, index);
    if (node == 0) {
        return 0;
    }

    free_node(node);

    short new_count = *(short *)(self_bytes + 0x120) - 1;
    *(short *)(self_bytes + 0x120) = new_count;

    if (new_count == 0) {
        *(short *)(self_bytes + 0x128) = 0;
    }
    if (new_count != 0) {
        short cur_128 = *(short *)(self_bytes + 0x128);
        if (cur_128 >= new_count) {
            *(short *)(self_bytes + 0x128) = new_count - 1;
        }
    }

    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    VMethod28 method28 = (VMethod28)*(void **)((char *)vtable + 0x28);
    method28(self, 1);

    return 1;
}
}
