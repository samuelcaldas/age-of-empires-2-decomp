#pragma exceptions off

#include "zone_rebind_table1.h"

extern "C" {
void func_1EB780(void **out_str, void *src_str, const char *ext);
void *func_25F2B0(int size);
void func_25D6D0(void *item, void *parsed_str, void *a8);
void func_116F68(void *ptr);

extern const char D_00492518[];
}

extern "C" void func_001CDD00(void *self, void *entity_id_array) {
    void *temp_buf = 0;

    for (int i = 31; i >= 0; i--) {
        char *entry = (char *)self + i * 416;

        if (*(unsigned char *)(entry + 0x8C) != 0) {
            func_1EB780(&temp_buf, entry + 0x9B, D_00492518);
            void *item = func_25F2B0(0x14);
            if (item != 0) {
                func_25D6D0(item, temp_buf, *(void **)(entry + 0xA8));
            }
            *(void **)(entry + 0xAC) = item;

            void *cur_item = *(void **)(entry + 0xAC);
            if (cur_item != 0) {
                unsigned char flags = *(unsigned char *)((char *)cur_item + 0x13);
                if (!((flags >> 1) & 1)) {
                    *(unsigned char *)(entry + 0x8C) = 0;
                }
            }
        }

        int id = *(int *)(entry + 0xB0);
        if (id >= 0) {
            *(void **)(entry + 0xB0) = ((void **)entity_id_array)[id];
        } else {
            *(void **)(entry + 0xB0) = 0;
        }
    }

    if (temp_buf != 0) {
        func_116F68(temp_buf);
    }
}
