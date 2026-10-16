#pragma once
#pragma exceptions off

#include "zone_raster_deserialize.h"

struct ZoneLayout {
    char pad_0[0x8ED0];     // 0x0..0x8ECF
    int f_8ED0;             // 0x8ED0 (-28976)
    int f_8ED4;             // 0x8ED4 (-28972)
    int *f_8ED8;            // 0x8ED8 (-28968)
    short **f_8EDC;         // 0x8EDC (-28964)
};

extern "C" {
void func_00226D90(void *stream, void *data, int size);
void func_00100630(void *ptr);
void *func_00100730(unsigned int size);
void *memset(void *ptr, int val, unsigned int size);
extern int D_938AC0[];
extern short *D_938CC0[];
}

extern "C" void func_001CAD90(void *self, void *stream) {
    ZoneLayout *zm = (ZoneLayout *)self;

    int old_count = zm->f_8ED0;
    if (old_count > 0 && zm->f_8EDC != 0) {
        for (int i = 0; i < old_count; i++) {
            func_00100630(zm->f_8EDC[i]);
        }
    }

    zm->f_8EDC = 0;
    zm->f_8ED8 = 0;

    func_00226D90(stream, &zm->f_8ED0, 4);
    func_00226D90(stream, &zm->f_8ED4, 4);

    if (zm->f_8ED4 < 128) {
        zm->f_8ED4 = 128;
    }

    zm->f_8ED8 = (int *)memset((void *)D_938AC0, 0, 512);
    zm->f_8EDC = (short **)memset((void *)D_938CC0, 0, 512);

    int count = zm->f_8ED0;
    if (count > 0) {
        func_00226D90(stream, zm->f_8ED8, count * 4);

        for (int i = 0; i < count; i++) {
            int pt_count = 0;
            func_00226D90(stream, &pt_count, 4);
            short *buf = (short *)func_00100730((unsigned int)((pt_count + 2) << 2));
            zm->f_8EDC[i] = buf;
            buf[0] = (short)pt_count;
            buf[1] = (short)(pt_count + 1);
            func_00226D90(stream, &buf[2], pt_count * 4);
        }
    }
}
