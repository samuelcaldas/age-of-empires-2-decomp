#include "kt_usbkeybd_drv.h"

extern UsbKeybdDevice D_50A540;
extern int D_50A580[];
extern const char D_490A60[];
extern const char D_490A78[];
extern const char D_490A98[];
extern const char D_490AB8[];

void func_1075C8(int);
void func_107C38(UsbKeybdDevice *, unsigned int, int);
void func_114320(const char *, int, const char *);
int func_107E08(UsbKeybdDevice *, int, int, void *, int, void *, int, int, int);

int func_00137208(void) {
    func_1075C8(0);
    func_107C38(&D_50A540, 0x80000211, 0);
    return D_50A540.status < 1;
}

int func_00137250(void *info) {
    if ((unsigned int)info & 63) {
        func_114320(D_490A60, 0x4F, D_490A78);
    }
    return func_107E08(&D_50A540, 1, 0, D_50A580, 0x20, info, 0x20, 0, 0);
}

int func_001372C0(int a0, void *data) {
    D_50A580[0] = a0;
    if ((unsigned int)data & 63) {
        func_114320(D_490A60, 0x7B, D_490A98);
    }
    return func_107E08(&D_50A540, 2, 0, D_50A580, 0x20, data, 0x20, 0, 0);
}

int func_00137340(int a0, void *location) {
    D_50A580[0] = a0;
    if ((unsigned int)location & 63) {
        func_114320(D_490A60, 0x99, D_490AB8);
    }
    return func_107E08(&D_50A540, 3, 0, D_50A580, 0x20, location, 0x20, 0, 0);
}

int func_001373C0(unsigned char a0, unsigned char a1) {
    unsigned char *buf = (unsigned char *)D_50A580;
    int res;

    buf[0] = a0;
    buf[1] = a1;
    res = func_107E08(&D_50A540, 4, 0, buf, 0x20, buf, 0x20, 0, 0);
    return (res != 0) ? res : buf[0];
}

int func_00137420(unsigned char a0, unsigned char a1) {
    unsigned char *buf = (unsigned char *)D_50A580;
    int res;

    buf[0] = a0;
    buf[1] = a1;
    res = func_107E08(&D_50A540, 5, 0, buf, 0x20, buf, 0x20, 0, 0);
    return (res != 0) ? res : buf[0];
}
