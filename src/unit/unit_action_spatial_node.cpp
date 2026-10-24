#pragma exceptions off
#include "unit_action_spatial_node.h"

void func_00269FF0(void *node, float x, float y) {
    if (node == 0) {
        return;
    }
    short field60 = *(short*)((char*)node + 0x60);
    if (field60 == -1) {
        return;
    }
    void *f8 = *(void**)((char*)node + 8);
    void *f4 = *(void**)((char*)node + 4);
    func_003357B0(f4, field60);
    func_00335920(f8, field60);
    int ix = func_123350(x);
    int iy = func_123350(y);
    (void)iy;
    func_00334FC0(f4, (short)ix);
}

void func_0026A0C0(ActionRebind *self, float x, float y) {
    if (self == 0) {
        return;
    }
    (void)x; (void)y;
    int ix = func_123350(self->m_x);
    int iy = func_123350(self->m_y);
    void *f8 = *(void**)((char*)self + 8);
    void *f4 = *(void**)((char*)self + 4);
    func_003357B0(f4, (short)ix);
    func_00335920(f8, (short)iy);
    func_00335040(f4, (short)ix);
}

void func_0026A1B0(void *node, float x, float y) {
    if (node == 0) {
        return;
    }
    (void)x; (void)y;
    short field60 = *(short*)((char*)node + 0x60);
    if (field60 == -1) {
        return;
    }
    void *f8 = *(void**)((char*)node + 8);
    void *f4 = *(void**)((char*)node + 4);
    func_003357B0(f4, field60);
    func_00335920(f8, field60);
    func_003352B0(f4, field60);
}

void func_0026A2A0(void *node) {
    if (node == 0) {
        return;
    }
    int field64 = *(int*)((char*)node + 0x64);
    if (field64 == -1) {
        return;
    }
    void *f8 = *(void**)((char*)node + 8);
    func_333b30(f8, (void*)field64);
    *(int*)((char*)node + 0x64) = -1;
}

void func_0026A300(void *node, short count) {
    if (node == 0) {
        return;
    }
    short field5C = *(short*)((char*)node + 0x5C);
    if (field5C != 0) {
        void *f58 = *(void**)((char*)node + 0x58);
        if (f58 != 0) {
            delete (char*)f58;
        }
    }
    *(short*)((char*)node + 0x5C) = count;
    if (count > 0) {
        *(void**)((char*)node + 0x58) = (void*)new char[count * 4];
    } else {
        *(void**)((char*)node + 0x58) = 0;
    }
}

void func_0026A420(void *node) {
    if (node == 0) {
        return;
    }
    *(short*)((char*)node + 0x5C) = 0;
    void *f58 = *(void**)((char*)node + 0x58);
    if (f58 != 0) {
        delete (char*)f58;
        *(void**)((char*)node + 0x58) = 0;
    }
}
