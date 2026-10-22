#include "network_address_helpers.h"

extern "C" {
extern const signed char D_0049E101[];
extern const char D_004D1EA0[];
int func_11A510(const char *text, const char *format, ...);
}

int func_00337660(const char *text) {
    const unsigned char *cursor = (const unsigned char *)text;
    int dots = 0;
    while (*cursor != 0) {
        int character = (signed char)*cursor;
        if (character == '.') {
            ++dots;
        }
        if ((D_0049E101[character] & 4) == 0 && character != '.') {
            return -1;
        }
        ++cursor;
    }
    if (dots >= 4) {
        return -1;
    }
    int first;
    int second;
    int third;
    int fourth;
    int count = func_11A510(text, D_004D1EA0, &first, &second, &third, &fourth);
    if (count != 4 || (unsigned int)first >= 256 || (unsigned int)second >= 256
        || (unsigned int)third >= 256 || (unsigned int)fourth >= 256) {
        return -1;
    }
    return (fourth << 24) | (third << 16) | (second << 8) | first;
}
