#pragma exceptions off

#include "zone_bind_render_item.h"

extern "C" {
void *func_25F2B0(int size);
void func_25DBF0(void *item, void *template_item);
void func_25DE30(void *item, int flag);
int func_1F6DD0(void *camera);
int func_1F6DE0(void *camera);
}

static inline void append_active_node(char *zm, int offset, void **node) {
    void **head_ptr = (void **)(zm + offset + 0x9048);
    void **tail_ptr = (void **)(zm + offset + 0x908C);
    if (*head_ptr != 0) {
        void **tail = (void **)*tail_ptr;
        tail[1] = node;
        *tail_ptr = node;
    } else {
        *head_ptr = node;
        *tail_ptr = node;
    }
}

extern "C" void func_001D17A0(void *self, void *item) {
    char *zm = (char *)self;
    char *item_ptr = (char *)item;
    unsigned char slot = *(unsigned char *)(item_ptr + 4);

    void *template_src = *(void **)(zm + 0x9038);
    if (template_src == 0) {
        *(void **)(item_ptr + 0x10) = *(void **)(zm + 0x9114 + slot * 4);
        return;
    }

    int offset = slot * 4;
    void **free_head_ptr = (void **)(zm + offset + 0x90D0);
    void **node = (void **)*free_head_ptr;

    if (node != 0) {
        *free_head_ptr = (void **)node[1];
        *(void **)(item_ptr + 0x10) = node[0];
        node[0] = item;
        node[1] = 0;
        append_active_node(zm, offset, node);
        return;
    }

    int count = *(int *)(zm + 0x9044);
    int capacity = *(int *)(zm + 0x9040);

    if (count < capacity) {
        void *sub_item = func_25F2B0(0x14);
        if (sub_item != 0) {
            void *tmpl = *(void **)(*(char **)(zm + 0x9034) + 0x26F4 + slot * 4);
            func_25DBF0(sub_item, tmpl);
        }
        *(void **)(item_ptr + 0x10) = sub_item;

        char *items_buf = *(char **)(zm + 0x903C);
        node = (void **)(items_buf + count * 8);
        node[0] = item;
        node[1] = 0;
        append_active_node(zm, offset, node);
        *(int *)(zm + 0x9044) = count + 1;
        return;
    }

    char *camera = *(char **)(zm + 0x9034);
    int cam_x = *(int *)(camera + 0x11C);
    int cam_y = *(int *)(camera + 0x120);

    int s7 = cam_x - 0x78;
    int s0 = func_1F6DD0(camera) - 0x3C;
    int s1 = func_1F6DE0(camera) + 0x3C;
    int v1 = cam_y + 0x1E;

    while (true) {
        void **curr = *(void ***)(zm + offset + 0x9048);
        while (curr != 0) {
            char *entry_item = (char *)curr[0];
            short ex = *(short *)(entry_item + 0);
            short ey = *(short *)(entry_item + 2);
            if (ex < s7 || ex > s1 || ey < s0 || ey > v1) {
                *(void **)(item_ptr + 0x10) = *(void **)(entry_item + 0x10);
                *(void **)(entry_item + 0x10) = 0;
                curr[0] = item;
                return;
            }
            curr = (void **)curr[1];
        }

        for (int other_slot = 0; other_slot < 17; other_slot++) {
            if (other_slot == slot) {
                continue;
            }
            void **other_free_ptr = (void **)(zm + other_slot * 4 + 0x90D0);
            if (*other_free_ptr != 0) {
                void **stolen_node = (void **)*other_free_ptr;
                *other_free_ptr = (void **)stolen_node[1];

                func_25DE30(stolen_node[0], 1);
                void *sub_item = func_25F2B0(0x14);
                if (sub_item != 0) {
                    void *tmpl = *(void **)(*(char **)(zm + 0x9034) + 0x26F4 + slot * 4);
                    func_25DBF0(sub_item, tmpl);
                }
                *(void **)(item_ptr + 0x10) = sub_item;
                stolen_node[0] = item;
                stolen_node[1] = 0;
                append_active_node(zm, offset, stolen_node);
                return;
            }
        }

        for (int other_slot = 0; other_slot < 17; other_slot++) {
            if (other_slot == slot) {
                continue;
            }
            void **prev = 0;
            void **s4 = *(void ***)(zm + other_slot * 4 + 0x9048);
            while (s4 != 0) {
                char *entry_item = (char *)s4[0];
                short ex = *(short *)(entry_item + 0);
                short ey = *(short *)(entry_item + 2);
                if (ex < s7 || ex > s1 || ey < s0 || ey > v1) {
                    func_25DE30(*(void **)(entry_item + 0x10), 1);
                    *(void **)(entry_item + 0x10) = 0;

                    if (prev != 0) {
                        prev[1] = s4[1];
                    } else {
                        *(void ***)(zm + other_slot * 4 + 0x9048) = (void **)s4[1];
                    }

                    void **other_tail_ptr = (void **)(zm + other_slot * 4 + 0x908C);
                    if (*other_tail_ptr == s4) {
                        *other_tail_ptr = prev;
                    }

                    void *sub_item = func_25F2B0(0x14);
                    if (sub_item != 0) {
                        void *tmpl = *(void **)(*(char **)(zm + 0x9034) + 0x26F4 + slot * 4);
                        func_25DBF0(sub_item, tmpl);
                    }
                    *(void **)(item_ptr + 0x10) = sub_item;
                    s4[0] = item;
                    s4[1] = 0;
                    append_active_node(zm, offset, s4);
                    return;
                }
                prev = s4;
                s4 = (void **)s4[1];
            }
        }

        s7 += 0x3C;
        s1 -= 0x3C;
        s0 += 0x1E;
        v1 -= 0x1E;
    }
}
