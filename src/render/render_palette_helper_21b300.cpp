#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern unsigned short D_004E32DC;
extern char D_00C5C700;

int func_0021B440(void *ptr14, int a1, int a2, int a3, void *buf);
int func_0021B4C0(void *ptr14, int a1, int a2, int a3, void *buf, int coord0);

int func_0021B300(void *self, int arg1, const int *coords) {
    char *self_bytes = (char *)self;
    *(int *)(self_bytes + 0x70) = coords[0];
    *(int *)(self_bytes + 0x74) = coords[1];

    int mode = *(int *)(self_bytes + 0x1C);
    if (mode == 2) {
        return 1;
    }

    void *ptr14 = *(void **)(self_bytes + 0x14);
    if (mode != 0 && ptr14 == 0) {
        return 1;
    }

    *(int *)(self_bytes + 0x70) = coords[0];
    *(int *)(self_bytes + 0x74) = coords[1];

    char local_buf[1024];
    func_0021B440(ptr14, 0, 0, 256, local_buf);
    func_0021B4C0(ptr14, 0, 0, 256, local_buf, coords[0]);

    return 0;
}

int func_0021B3C0(void *arg0, void **arg1) {
    *arg1 = arg0;
    return 0;
}

int func_0021B3D0(void) {
    return 0;
}

void func_0021B3E0(void *self) {
    char *self_bytes = (char *)self;
    unsigned short counter = D_004E32DC;

    *(short *)(self_bytes + 0) = 0;
    *(short *)(self_bytes + 2) = (short)(counter << 4);
    *(void **)(self_bytes + 4) = &D_00C5C700 + ((int)counter << 10);

    D_004E32DC = counter + 1;
}

void func_0021B420(void *self) {
    *(short *)self = 0;
}

int func_0021B430(void *self) {
    *(short *)self = 0;
    return 0;
}
}
