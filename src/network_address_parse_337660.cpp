#include "network_address_helpers.h"

#pragma optimization_level 1

extern "C" {
extern const signed char D_0048E101[];
extern const char D_004D1EA0[];
int func_11A510(const char *text, const char *format, ...);
}

int func_00337660(const char *text) {
    const char *cursor = text;
    int count = 0;
    char c;
    while ((c = *cursor) != 0) {
        int sc = (signed char)c;
        if (sc == 46) {
            count++;
        }
        if (!(D_0048E101[(signed char)c] & 4) && sc != 46) {
            return -1;
        }
        cursor++;
    }
    if (count > 3) {
        return -1;
    }
    int parts[4];
    int *p1 = &parts[1];
    int *p2 = &parts[2];
    int *p3 = &parts[3];
    if (func_11A510(text, D_004D1EA0, &parts[0], p1, p2, p3) != 4) {
        return -1;
    }
    for (count = 0; count < 4; count++) {
        if ((unsigned int)parts[count] > 255) {
            return -1;
        }
    }
    count = (*p3 << 24) | ((*p2 << 16) | (parts[0] | (*p1 << 8)));
    return count;
}
