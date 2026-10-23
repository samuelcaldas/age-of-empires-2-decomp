#include "common.h"
#include "mo_ov_overlay.h"

#define MO_OV_BASE_ADDR ((void *)0x01ED7290)

void func_001003B0(void *addr, void *type_info, void *ctor, int elem_sz, int count);
void func_00100C20(void *addr, void *desc, void *hook);

/* mo_ov_func_01ED7000: Get Movie Overlay base memory pointer */
void *mo_ov_func_01ED7000(void) {
    return MO_OV_BASE_ADDR;
}

/* mo_ov_func_01ED700C: Initialize Movie Overlay component arrays */
void mo_ov_func_01ED700C(void) {
    char *base = (char *)MO_OV_BASE_ADDR;

    /* Initialize 7 PSS movie playback subsystem component arrays */
    func_001003B0(base + 0x00000, (void *)0x0037D310, (void *)0x001C6A70, 0x00A4, 0x002C);
    func_001003B0(base + 0x01C30, (void *)0x0037D2F0, (void *)0x001C2D50, 0x00A8, 0x0034);
    func_001003B0(base + 0x03E50, (void *)0x0037D2C0, (void *)0x001C55A0, 0x00C8, 0x01E0);
    func_001003B0(base + 0x1B550, (void *)0x0037D270, (void *)0x001C4D20, 0x0134, 0x0174);
    func_001003B0(base + 0x374E0, (void *)0x0037D240, (void *)0x001C4850, 0x00A8, 0x0004);
    func_001003B0(base + 0x37780, (void *)0x0037D1F0, (void *)0x002D7570, 0x0168, 0x02D0);
    func_001003B0(base + 0x76C00, (void *)0x0037D190, (void *)0x002D58E0, 0x01B8, 0x0274);

    /* Register overlay component descriptor */
    func_00100C20(base, (void *)0x0037CF60, (void *)0x01ED7280);
}

/* MO_OV_CD.BIN metadata table */
const void *const mo_ov_data[12] = {(void *)0x01ED7100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
