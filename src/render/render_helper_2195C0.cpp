#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_001143F8(int n, int size);
void func_00116F68(void *ptr);
int func_0011ACD0(const char *str);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, unsigned int n);
int strcmp(const char *s1, const char *s2);
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

static ActionListItem *create_node(void *self, const char *str_s4, const char *str_s3, int val_s2, int val_s1) {
    ActionListItem *node = (ActionListItem *)func_001143F8(1, 0x2C);
    if (node == 0) {
        return 0;
    }

    char *self_bytes = (char *)self;
    short len_174 = *(short *)(self_bytes + 0x174);
    if (len_174 != 0) {
        node->text = (char *)func_001143F8(len_174 + 1, 1);
    } else if (str_s4 == 0) {
        node->text = (char *)func_001143F8(1, 1);
    } else {
        int len_s4 = func_0011ACD0(str_s4);
        node->text = (char *)func_001143F8(len_s4 + 1, 1);
    }

    if (node->text == 0) {
        func_00116F68(node);
        return 0;
    }

    if (str_s3 != 0) {
        int len_s3 = func_0011ACD0(str_s3);
        node->extra_text = (char *)func_001143F8(len_s3 + 1, 1);
        if (node->extra_text == 0) {
            func_00116F68(node->text);
            func_00116F68(node);
            return 0;
        }
    }

    if (str_s4 == 0) {
        node->text[0] = '\0';
    } else if (len_174 != 0) {
        memcpy(node->text, str_s4, len_174);
        node->text[len_174] = '\0';
    } else {
        strcpy(node->text, str_s4);
    }

    if (str_s3 != 0) {
        strcpy(node->extra_text, str_s3);
    }

    node->val_8 = val_s2;
    node->next = 0;
    node->val_c = val_s1;
    node->byte_10 = 0;
    node->byte_24 = 0;
    return node;
}

static void insert_sorted(void *self, ActionListItem *node) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    ActionListItem *prev = 0;

    while (curr != 0) {
        if (strcmp(curr->text, node->text) >= 0) {
            if (prev == 0) {
                node->next = curr;
                *(ActionListItem **)(self_bytes + 0x11C) = node;
            } else {
                node->next = curr;
                prev->next = node;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev != 0) {
        prev->next = node;
    }
}

static void insert_at_index(void *self, ActionListItem *node, int target_index) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);

    if (target_index == 0) {
        node->next = curr;
        *(ActionListItem **)(self_bytes + 0x11C) = node;
        return;
    }

    short total_count = *(short *)(self_bytes + 0x120);
    if (target_index < total_count) {
        int idx = 0;
        while (curr != 0) {
            if (idx == target_index - 1) {
                node->next = curr->next;
                curr->next = node;
                return;
            }
            curr = curr->next;
            idx++;
        }
    } else {
        while (curr->next != 0) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

int func_002195C0(void *self, int insert_pos, const char *str_s4, const char *str_s3, int val_s2, int val_s1) {
    ActionListItem *node = create_node(self, str_s4, str_s3, val_s2, val_s1);
    if (node == 0) {
        return 0;
    }

    char *self_bytes = (char *)self;
    ActionListItem *head = *(ActionListItem **)(self_bytes + 0x11C);

    if (head == 0) {
        *(ActionListItem **)(self_bytes + 0x11C) = node;
    } else if (*(int *)(self_bytes + 0x198) != 0) {
        insert_sorted(self, node);
    } else {
        insert_at_index(self, node, insert_pos);
    }

    short new_count = *(short *)(self_bytes + 0x120) + 1;
    *(short *)(self_bytes + 0x120) = new_count;
    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    VMethod28 method28 = (VMethod28)*(void **)((char *)vtable + 0x28);
    method28(self, 1);

    return 1;
}
}
