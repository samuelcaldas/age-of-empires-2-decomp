#pragma exceptions off
#include "render_manager_config.h"

extern "C" {

void func_00187ca0(RenderManagerConfigSnapshot *self) {
    if (self->field_1AC != 0) {
        int size = 0;
        void *data = func_192BF0(self->field_1AC, &size);
        if (data != 0 && size == 0xB0) {
            func_00187d00(self, (const unsigned char *)data);
        }
    }
}

void func_00187d00(void *self, const unsigned char *data) {
    func_188250(self, *(const float *)(data + 0));
    func_188240(self, data[4]);
    func_188260(self, data + 5);
    func_1882B0(self, data[0x85]);
    func_1882D0(self, data[0x86]);
    func_1882F0(self, data[0x87], data[0x88], data[0x89]);
    func_188300(self, data[0x8A]);
    func_188310(self, data[0x8C]);
    func_188320(self, data[0xAC]);
    func_188330(self, data[0x8D]);
    func_188340(self, data[0x8E]);
    func_188350(self, data[0x8F]);
    func_188360(self, data[0x90]);
    func_1883C0(self, data[0x9A]);
    func_1883F0(self, data[0x8B]);
    func_188020(self, data[0x9B]);
    func_188490(self, *(const float *)(data + 0xA8));

    if (data[0xA5] != 0) {
        func_1884B0(self);
    } else {
        func_1884F0(self);
    }

    if (data[0xA6] != 0) {
        func_1884C0(self);
    } else {
        func_188500(self);
    }

    for (int i = 0; i < 9; i++) {
        func_1883B0(self, i, data[0x91 + i]);
        func_1883D0(self, i, data[0x9C + i]);
    }
}

void func_00187ea0(void *self, unsigned char *data) {
    *(float *)(data + 0) = func_188060(self);
    data[4] = func_188070(self);
    func_11ABBC((char *)(data + 5), func_1880C0(self));
    data[0x85] = func_1880D0(self);
    data[0x86] = func_1880E0(self);
    data[0x87] = func_1880F0(self);
    data[0x88] = func_188100(self);
    data[0x89] = func_188110(self);
    data[0x8A] = func_188120(self);
    data[0x8C] = func_188130(self);
    data[0xAC] = func_188140(self);
    data[0x8D] = func_188150(self);
    data[0x8E] = func_188160(self);
    data[0x8F] = func_1881D0(self);
    data[0x90] = func_188170(self);
    data[0x9A] = func_1881C0(self);
    data[0x8B] = func_188220(self);
    data[0x9B] = func_188050(self);
    *(float *)(data + 0xA8) = func_1884E0(self);
    data[0xA5] = func_188510(self);
    data[0xA6] = func_188520(self);

    for (int i = 0; i < 9; i++) {
        data[0x91 + i] = func_1881B0(self, i);
        data[0x9C + i] = func_1881E0(self, i);
    }
}

}
