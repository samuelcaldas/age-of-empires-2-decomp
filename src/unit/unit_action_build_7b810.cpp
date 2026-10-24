#pragma exceptions off
#include "unit_action_build_7b810.h"

void *func_0027B810(void *self, int type) {
    void *current = *(void **)((char *)self + 0x1E0);
    unsigned char target_type = (unsigned char)type;
    while (current != 0) {
        if (*(unsigned char *)((char *)current + 0x0) == target_type) {
            return current;
        }
        current = *(void **)((char *)current + 0x18);
    }
    return 0;
}

int func_0027B850(void *self, int target_index, void **out_entry) {
    void *current = *(void **)((char *)self + 0x1E0);
    int index = 1;
    while (current != 0) {
        if (index == target_index) {
            *out_entry = current;
            return 1;
        }
        current = *(void **)((char *)current + 0x18);
        index++;
    }
    *out_entry = 0;
    return 0;
}

int func_0027B890(void *self, int target_count, void **out_entry) {
    void *current = *(void **)((char *)self + 0x1E0);
    while (current != 0) {
        if (*(int *)((char *)current + 0x4) == target_count) {
            *out_entry = current;
            return 1;
        }
        current = *(void **)((char *)current + 0x18);
    }
    *out_entry = 0;
    return 0;
}

int func_0027B8D0(void *self, int target_count, int *out_pos, char *out_match_count) {
    void *current = *(void **)((char *)self + 0x1E0);
    int pos = 1;
    int match_found = 0;
    int first_recorded = 0;
    char match_count = 0;

    while (current != 0) {
        if (*(int *)((char *)current + 0x4) == target_count) {
            match_found = 1;
            if (first_recorded == 0) {
                *out_pos = pos;
                first_recorded = 1;
            }
            match_count++;
        }
        current = *(void **)((char *)current + 0x18);
        pos++;
    }

    if (match_found != 0) {
        *out_match_count = match_count;
    } else {
        *out_pos = -1;
        *out_match_count = -1;
    }
    return 0;
}
