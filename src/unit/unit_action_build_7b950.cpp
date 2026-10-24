#pragma exceptions off
#include "unit_action_build_7b950.h"

extern "C" {
    void *func_117CAC(void *dest, int val, unsigned int size);
}

int func_0027B950(void *self, void *new_entry) {
    void *curr = *(void **)((char *)self + 0x1E0);
    int type_b_count = 0;

    while (curr != 0) {
        if (*(unsigned char *)((char *)curr + 0x0) == 0xB) {
            type_b_count++;
        }
        curr = *(void **)((char *)curr + 0x18);
    }

    if (type_b_count < 4) {
        *(float *)((char *)new_entry + 0x14) = 1.0f;
        return 1;
    }

    curr = *(void **)((char *)self + 0x1E0);
    void *prev = curr;
    void *best_prev = 0;
    void *best_curr = 0;
    float max_diff = 0.0f;
    int found_candidate = 0;
    int check_count = 0;

    float new_val2 = *(float *)((char *)new_entry + 0x10);

    while (curr != 0) {
        if (*(unsigned char *)((char *)curr + 0x0) == 0xB) {
            float curr_val2 = *(float *)((char *)curr + 0x10);
            if (curr_val2 < new_val2) {
                check_count++;
                float diff = new_val2 - curr_val2;
                if (diff > max_diff) {
                    max_diff = diff;
                    best_prev = prev;
                    best_curr = curr;
                    found_candidate = 1;
                }
            }
        }
        prev = curr;
        curr = *(void **)((char *)curr + 0x18);
        if (check_count >= 3) {
            break;
        }
    }

    if (found_candidate != 0) {
        void *next = *(void **)((char *)best_curr + 0x18);
        *(void **)((char *)best_prev + 0x18) = next;
        func_117CAC(best_curr, 0, 0x1C);
        return 1;
    }

    void *next = *(void **)((char *)new_entry + 0x18);
    *(void **)((char *)self + 0x1E0) = next;
    func_117CAC(new_entry, 0, 0x1C);
    return 0;
}

int func_27B950(void *self, void *new_entry) {
    return func_0027B950(self, new_entry);
}
