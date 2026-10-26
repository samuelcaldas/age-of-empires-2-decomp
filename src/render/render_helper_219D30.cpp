#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00116F68(void *ptr);
void func_100670(void *ptr);
void func_00217B50(void *self, int arg1);

typedef void (*VMethod28)(void *, int);

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    void *val_c;
    char byte_10;
    char pad_11[3];
    void *val_14;
    void *val_18;
    void *val_1c;
    void *val_20;
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

static void free_sub_list(void *sub) {
    while (sub != 0) {
        void *next_sub = *(void **)((char *)sub + 0x8);
        func_100670(sub);
        sub = next_sub;
    }
}

static void free_action_item(ActionListItem *item) {
    if (item->text != 0) {
        func_00116F68(item->text);
    }
    if (item->extra_text != 0) {
        func_00116F68(item->extra_text);
    }
    free_sub_list(item->val_c);
    func_00116F68(item);
}

void func_00219D30(void *self) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);

    if (curr != 0) {
        while (curr != 0) {
            ActionListItem *next = curr->next;
            free_action_item(curr);
            curr = next;
        }
        *(ActionListItem **)(self_bytes + 0x11C) = 0;
    }

    *(short *)(self_bytes + 0x120) = 0;
    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    VMethod28 method28 = (VMethod28)*(void **)((char *)vtable + 0x28);
    method28(self, 1);
}
}
