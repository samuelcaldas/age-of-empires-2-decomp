#pragma exceptions off

#include "zone_rebind_table2.h"

extern "C" {
void func_1EB780(void **out_str, void *src_str, const char *ext);
void *func_25F2B0(int size);
void func_25D6D0(void *item, void *parsed_str, void *a8);
void func_116F68(void *ptr);

extern const char D_00492518[];
}

extern "C" void func_001CDE30(void *self) {
    void *temp_buf = 0;

    for (int i = 15; i >= 0; i--) {
        char *entry = (char *)self + i * 1440;
        unsigned char *active_ptr = (unsigned char *)(entry + 0x348C);

        if (*active_ptr != 0) {
            func_1EB780(&temp_buf, entry + 0x349B, D_00492518);
            void *item = func_25F2B0(0x14);
            if (item != 0) {
                func_25D6D0(item, temp_buf, *(void **)(entry + 0x34A8));
            }
            *(void **)(entry + 0x34AC) = item;

            void *cur_item = *(void **)(entry + 0x34AC);
            unsigned char flags = *(unsigned char *)((char *)cur_item + 0x13);
            if (!((flags >> 1) & 1)) {
                *active_ptr = 0;
            }
            *(int *)(entry + 0x34B0) = 0;
        }
    }

    if (temp_buf != 0) {
        func_116F68(temp_buf);
    }
}
