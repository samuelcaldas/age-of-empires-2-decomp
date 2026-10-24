#pragma exceptions off
#include "render_manager_setters.h"

extern "C" {

void func_00188260(RenderManagerSetters *self, const char *src) {
    func_11B170(self->field_911, src, 0x80);
    self->field_990 = 0;
}

void func_00188290(RenderManagerSetters *self, int val) {
    self->field_9BC = val;
}

void func_001882a0(RenderManagerSetters *self, int val) {
    self->field_9C0 = val;
}

void func_001882b0(RenderManagerSetters *self, unsigned char val) {
    self->field_991 = val;
    self->field_992 = !val;
}

void func_001882d0(RenderManagerSetters *self, unsigned char val) {
    self->field_992 = val;
    self->field_991 = !val;
}

void func_001882f0(RenderManagerSetters *self, unsigned char a, unsigned char b, unsigned char c) {
    self->field_993 = a;
    self->field_994 = b;
    self->field_995 = c;
}

void func_00188300(RenderManagerSetters *self, unsigned char val) {
    self->field_996 = val;
}

void func_00188310(RenderManagerSetters *self, unsigned char val) {
    self->field_998 = val;
}

void func_00188320(RenderManagerSetters *self, unsigned char val) {
    self->field_9B8 = val;
}

void func_00188330(RenderManagerSetters *self, unsigned char val) {
    self->field_999 = val;
}

void func_00188340(RenderManagerSetters *self, unsigned char val) {
    self->field_99A = val;
}

void func_00188350(RenderManagerSetters *self, unsigned char val) {
    self->field_99B = val;
}

void func_00188360(RenderManagerSetters *self) {
    self->field_99C = 0;
}

void func_00188370(RenderManagerSetters *self, int idx, unsigned char val) {
    unsigned char *base = self->field_99D;
    unsigned char *ptr = idx + base;
    *ptr = (*ptr & 0xFE) | val;
}

void func_00188390(RenderManagerSetters *self, int idx, unsigned char val) {
    self->field_99D[idx] = (self->field_99D[idx] & 1) | (val << 1);
}

void func_001883b0(RenderManagerSetters *self, int idx, unsigned char val) {
    self->field_99D[idx] = val;
}

void func_001883c0(RenderManagerSetters *self, unsigned char val) {
    self->field_9A6 = val;
}

void func_001883d0(RenderManagerSetters *self, int idx, unsigned char val) {
    self->field_9A8[idx] = val;
}

void func_001883e0(RenderManagerSetters *self, unsigned char val) {
    self->field_1060 = val;
}

void func_001883f0(RenderManagerSetters *self, unsigned char val) {
    self->field_997 = val;
}

void func_00188400(RenderManagerSetters *self) {
    if (self->field_404 != 0) {
        func_32F190(self->field_404);
    }
}

void func_00188430(RenderManagerSetters *self) {
    if (self->field_404 != 0) {
        func_32F1C0(self->field_404);
    }
}

void func_00188460(RenderManagerSetters *self) {
    self->field_404->Method68();
}

void func_00188480(RenderManagerSetters *self) {
    func_3449B0(self->field_24);
}

void func_00188490(RenderManagerSetters *self, float val) {
    self->field_9B4 = val;
}

void func_001884a0(RenderManagerSetters *self, float val) {
    self->field_1058 = val;
}

void func_001884b0(RenderManagerSetters *self) {
    self->field_9B1 = 1;
}

void func_001884c0(RenderManagerSetters *self) {
    self->field_9B2 = 1;
}

float func_001884d0(RenderManagerSetters *self) {
    return self->field_1058;
}

float func_001884e0(RenderManagerSetters *self) {
    return self->field_9B4;
}

void func_001884f0(RenderManagerSetters *self) {
    self->field_9B1 = 0;
}

void func_00188500(RenderManagerSetters *self) {
    self->field_9B2 = 0;
}

unsigned char func_00188510(RenderManagerSetters *self) {
    return self->field_9B1;
}

unsigned char func_00188520(RenderManagerSetters *self) {
    return self->field_9B2;
}

void func_00188530(RenderManagerSetters *self, int val) {
    if (val != 0) {
        func_001884b0(self);
    } else {
        func_001884f0(self);
    }
}

void func_00188560(RenderManagerSetters *self, int val) {
    if (val != 0) {
        func_001884c0(self);
    } else {
        func_00188500(self);
    }
}

}
