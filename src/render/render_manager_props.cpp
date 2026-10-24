#pragma exceptions off
#include "render_manager_props.h"

extern "C" {

void func_00188020(RenderManagerProps *self, unsigned char val) {
    self->field_9A7 = val;
}

void func_00188030(RenderManagerProps *self, int val) {
    self->field_B28 = val;
}

int func_00188040(RenderManagerProps *self) {
    return self->field_B28;
}

unsigned char func_00188050(RenderManagerProps *self) {
    return self->field_9A7;
}

float func_00188060(RenderManagerProps *self) {
    return self->field_90C;
}

unsigned char func_00188070(RenderManagerProps *self) {
    return self->field_910;
}

unsigned char func_00188080(RenderManagerProps *self) {
    int v = !self->field_910;
    return (unsigned char)v;
}

int func_001880a0(RenderManagerProps *self) {
    return self->field_9BC;
}

int func_001880b0(RenderManagerProps *self) {
    return self->field_9C0;
}

const char *func_001880c0(RenderManagerProps *self) {
    return self->field_911;
}

unsigned char func_001880d0(RenderManagerProps *self) {
    return self->field_991;
}

unsigned char func_001880e0(RenderManagerProps *self) {
    return self->field_992;
}

unsigned char func_001880f0(RenderManagerProps *self) {
    return self->field_993;
}

unsigned char func_00188100(RenderManagerProps *self) {
    return self->field_994;
}

unsigned char func_00188110(RenderManagerProps *self) {
    return self->field_995;
}

unsigned char func_00188120(RenderManagerProps *self) {
    return self->field_996;
}

unsigned char func_00188130(RenderManagerProps *self) {
    return self->field_998;
}

unsigned char func_00188140(RenderManagerProps *self) {
    return self->field_9B8;
}

unsigned char func_00188150(RenderManagerProps *self) {
    return self->field_999;
}

unsigned char func_00188160(RenderManagerProps *self) {
    return self->field_99A;
}

unsigned char func_00188170(RenderManagerProps *self) {
    return self->field_99C;
}

unsigned char func_00188180(RenderManagerProps *self, int idx) {
    return self->field_99D[idx] & 1;
}

unsigned char func_00188190(RenderManagerProps *self, int idx) {
    return (self->field_99D[idx] & 0xFE) >> 1;
}

unsigned char func_001881b0(RenderManagerProps *self, int idx) {
    return self->field_99D[idx];
}

unsigned char func_001881c0(RenderManagerProps *self) {
    return self->field_9A6;
}

unsigned char func_001881d0(RenderManagerProps *self) {
    return self->field_99B;
}

unsigned char func_001881e0(RenderManagerProps *self, int idx) {
    if (idx >= 9) {
        return 1;
    }
    return self->field_9A8[idx];
}

unsigned char func_00188210(RenderManagerProps *self) {
    return self->field_1060;
}

unsigned char func_00188220(RenderManagerProps *self) {
    return self->field_997;
}

void func_00188230(RenderManagerProps *self) {
    func_3444E0(self->field_24);
}

void func_00188240(RenderManagerProps *self, unsigned char val) {
    self->field_910 = val;
}

void func_00188250(RenderManagerProps *self, float val) {
    self->field_90C = val;
}

}
