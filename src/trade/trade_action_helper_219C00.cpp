#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern char D_004E32D4;

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

int func_00219CE0(void *self, int index);

int func_00219C00(void *self, int index, void **loc120, void **loc124, void **loc128, void **loc12C, int selector = 0) {
    *loc120 = 0;
    *loc124 = 0;

    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    int idx = 0;

    while (curr != 0) {
        if (idx == index) {
            *loc120 = curr->text;
            *loc124 = curr->val_c;
            if (curr->byte_10 != 0 && loc128 != 0 && loc12C != 0) {
                if (selector != 0) {
                    *loc128 = curr->val_1c;
                    *loc12C = curr->val_20;
                }
                if (selector == 0) {
                    *loc128 = curr->val_14;
                    *loc12C = curr->val_18;
                }
            }
        }
        curr = curr->next;
        idx++;
    }
    return 0;
}

const char *func_00219C90(void *self, int index) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    int idx = 0;

    while (curr != 0) {
        if (idx == index) {
            return curr->extra_text;
        }
        curr = curr->next;
        idx++;
    }

    D_004E32D4 = '\0';
    return &D_004E32D4;
}

int func_00219CD0(void *self) {
    char *self_bytes = (char *)self;
    short cur_128 = *(short *)(self_bytes + 0x128);
    return func_00219CE0(self, (int)cur_128);
}

int func_00219CE0(void *self, int index) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    int idx = 0;

    while (curr != 0) {
        if (idx == index) {
            return curr->val_8;
        }
        curr = curr->next;
        idx++;
    }

    return -1;
}

void func_00219D20(void *self) {
    void **vtable = *(void ***)self;
    typedef void (*VMethod12C)(void *);
    VMethod12C method12C = (VMethod12C)*(void **)((char *)vtable + 0x12C);
    method12C(self);
}
}
