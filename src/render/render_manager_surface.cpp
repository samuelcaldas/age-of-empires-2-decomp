#pragma exceptions off
#include "render_manager_surface.h"

extern "C" {

int func_001889a0(RenderManagerSurface *self) {
    self->field_106C = func_1AE480(&D_00598DA0);
    if (self->field_106C == 0) {
        return 0;
    }
    if (func_1AB7E0(self->field_106C, self->field_6C, 0x18A, 0xC6, 0, 0, (int)0x01FC2800) == 0) {
        func_1AE510(&D_00598DA0, self->field_106C);
        self->field_106C = 0;
        return 0;
    }
    return 1;
}

/*
 * func_00188a30:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00188A30, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00188a30() {}

void func_00188a40(RenderManagerSurface *self) {
    self->field_408 = 1;
    func_1F34E0((void *)func_00A80BB0);
}

int func_00188a60() {
    return 0;
}

int func_00188a70(RenderManagerSurface *self) {
    return self->field_1AC ? self->field_1AC->field_10E0 : -1;
}

void func_00188a90(char code) {
    switch (code) {
    case 1: func_25D060(0x1013); break;
    case 7: func_25D060(0x1014); break;
    case 13: func_25D060(0x1015); break;
    case 6: func_25D060(0x1016); break;
    case 2: func_25D060(0x1017); break;
    case 3: func_25D060(0x1018); break;
    case 5: func_25D060(0x1019); break;
    case 12: func_25D060(0x101A); break;
    case 8: func_25D060(0x101B); break;
    case 9: func_25D060(0x101C); break;
    case 4: func_25D060(0x1018); break;
    case 10: func_25D060(0x101D); break;
    case 11: func_25D060(0x101E); break;
    default: break;
    }
}

int func_00188ba0() {
    return 0;
}

int func_00188bb0() {
    return 0;
}

/*
 * func_00188bc0:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00188BC0, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00188bc0() {}

/*
 * func_00188bd0:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00188BD0, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00188bd0() {}

int func_00188be0() {
    return 0;
}

int func_00188bf0() {
    return 1;
}

}
