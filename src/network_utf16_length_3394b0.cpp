#include "network_utf16_length_3394b0.h"

int func_003394B0(const unsigned short *text) {
    int length = 0;
    if (*text == 0) {
        return length;
    }
    do {
        ++length;
        ++text;
    } while (*text != 0);
    return length;
}
