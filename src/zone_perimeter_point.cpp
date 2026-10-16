#pragma once
#pragma exceptions off

#include "zone_perimeter_point.h"

extern "C" void func_001CAC00(void *self, short *buffer, short dx, short dy) {
    (void)self;
    if (dx == 0 && dy == 0) {
        return;
    }
    if (buffer == 0) {
        return;
    }

    short count = buffer[0];
    short capacity = buffer[1];
    if (!(count < capacity)) {
        return;
    }

    for (int i = 1; i <= count; i++) {
        if (buffer[i * 2] == dx && buffer[i * 2 + 1] == dy) {
            return;
        }
    }

    count++;
    buffer[count * 2] = dx;
    buffer[count * 2 + 1] = dy;
    buffer[0] = count;
}
