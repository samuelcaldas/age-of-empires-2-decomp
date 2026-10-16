#pragma once
#pragma exceptions off

#include "zone_raster_serialize.h"

struct ZoneLayout {
    char pad_0[0x8ED0];     // 0x0..0x8ECF
    int f_8ED0;             // 0x8ED0
    int f_8ED4;             // 0x8ED4
    int *f_8ED8;            // 0x8ED8
    short **f_8EDC;         // 0x8EDC
};

extern "C" {
void func_00226F70(void *stream, void *data, int size);
}

extern "C" void func_001CAC90(void *self, void *stream) {
    ZoneLayout *zm = (ZoneLayout *)self;

    func_00226F70(stream, &zm->f_8ED0, 4);
    func_00226F70(stream, &zm->f_8ED4, 4);

    int count = zm->f_8ED0;
    if (count > 0) {
        func_00226F70(stream, zm->f_8ED8, count * 4);

        for (int i = 0; i < count; i++) {
            short *buf = zm->f_8EDC[i];
            int pt_count = (int)buf[0];
            func_00226F70(stream, &pt_count, 4);
            func_00226F70(stream, &buf[2], pt_count * 4);
        }
    }
}
