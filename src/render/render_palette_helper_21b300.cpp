#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern volatile unsigned short D_004E32DC;
extern char D_00C5C700[];

int func_0021B440(void *ptr14, int a1, int a2, int a3, void *buf);
int func_0021B4C0(void *ptr14, int a1, int a2, int a3, void *buf, int coord0);

struct Coord2f {
    float x;
    float y;
};

int func_0021B300(void *self, int arg1, const int *coords) {
    int coord0;
    char *self_bytes = (char *)self;
    *(Coord2f *)(self_bytes + 0x70) = *(const Coord2f *)coords;

    int mode = *(int *)(self_bytes + 0x1C);
    if (mode == 2 || mode == 0) {
        return 1;
    }

    if (*(void **)(self_bytes + 0x14) == 0) {
        return 1;
    }

    *(int *)(self_bytes + 0x70) = coords[0];
    *(int *)(self_bytes + 0x74) = coords[1];

    char local_buf[1024];
    coord0 = *(int *)(self_bytes + 0x70);
    func_0021B440(*(void **)(self_bytes + 0x14), 0, 0, 256, local_buf);
    func_0021B4C0(*(void **)(self_bytes + 0x14), 0, 0, 256, local_buf, coord0);

    return 0;
}

int func_0021B3C0(void *arg0, void **arg1) {
    *arg1 = arg0;
    return 0;
}

int func_0021B3D0(void) {
    return 0;
}

void *func_0021B3E0(void *self) {
    char *self_bytes = (char *)self;

    *(unsigned short *)(self_bytes + 2) = (unsigned short)(D_004E32DC << 4);
    *(void **)(self_bytes + 4) = (char *)&D_00C5C700 + ((int)D_004E32DC << 10);
    D_004E32DC = D_004E32DC + 1;
    *(short *)(self_bytes + 0) = 0;
    return self;
}

void func_0021B420(void *self) {
    *(short *)self = 0;
}

int func_0021B430(void *self) {
    *(short *)self = 0;
    return 0;
}
}
