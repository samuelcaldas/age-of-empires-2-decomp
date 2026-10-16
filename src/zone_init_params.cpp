#pragma exceptions off

#include "zone_init_params.h"

struct ZoneInitLayout {
    char pad_base[0x8EAE];
    short f_8EAE;
    short f_8EB0;
    short f_8EB2;
    short f_8EB4;
    short f_8EB6;
};

extern "C" void func_1CEA30(void *self, int index, short a2, short a3, signed char t0);

extern "C" void func_001C93C0(void *self) {
    ZoneInitLayout *layout = (ZoneInitLayout *)self;
    layout->f_8EAE = 60;
    layout->f_8EB0 = 30;
    layout->f_8EB4 = 30;
    layout->f_8EB2 = 15;
    layout->f_8EB6 = 15;

    register ZoneInitLayout *s0 = layout;

    func_1CEA30(s0, 0, s0->f_8EAE, s0->f_8EB0, 0);
    func_1CEA30(s0, 1, s0->f_8EAE, s0->f_8EB6, -7);
    func_1CEA30(s0, 2, s0->f_8EAE, (short)(s0->f_8EB0 + s0->f_8EB6), 7);
    func_1CEA30(s0, 3, s0->f_8EAE, s0->f_8EB0, -7);
    func_1CEA30(s0, 4, s0->f_8EAE, s0->f_8EB0, -7);
    func_1CEA30(s0, 5, s0->f_8EAE, s0->f_8EB6, -7);
    func_1CEA30(s0, 6, s0->f_8EAE, (short)(s0->f_8EB0 + s0->f_8EB6), 7);
    func_1CEA30(s0, 7, s0->f_8EAE, s0->f_8EB6, -7);
    func_1CEA30(s0, 8, s0->f_8EAE, (short)(s0->f_8EB0 + s0->f_8EB6), 7);
    func_1CEA30(s0, 9, s0->f_8EAE, s0->f_8EB6, -7);
    func_1CEA30(s0, 10, s0->f_8EAE, (short)(s0->f_8EB0 + s0->f_8EB6), 7);
    func_1CEA30(s0, 11, s0->f_8EAE, s0->f_8EB0, -7);
    func_1CEA30(s0, 12, s0->f_8EAE, s0->f_8EB0, -7);
    func_1CEA30(s0, 13, s0->f_8EAE, s0->f_8EB6, -7);
    func_1CEA30(s0, 14, s0->f_8EAE, (short)(s0->f_8EB0 + s0->f_8EB6), 7);
    func_1CEA30(s0, 15, s0->f_8EAE, s0->f_8EB0, 7);
    func_1CEA30(s0, 16, s0->f_8EAE, s0->f_8EB0, 7);
    func_1CEA30(s0, 17, s0->f_8EB4, s0->f_8EB0, 0);
    func_1CEA30(s0, 18, s0->f_8EB4, s0->f_8EB0, 0);
}
