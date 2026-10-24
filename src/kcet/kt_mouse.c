#include "common.h"

int func_105748(int);
int func_104A20(int, int);
void func_1057B0(int);

int func_00134DE8(int a0, int a1) {
    int flag = func_105748(a0);
    int res = func_104A20(a0, a1);
    if (res != 0) {
        if (flag != 0) {
            func_1057B0(a0);
        }
    }
    return res;
}

typedef struct {
    int handle;
    int count;
    char *buffer;
    int flag;
} MouseWork;

extern MouseWork D_50A060;
extern char D_509F00[];
extern const char D_490820[];
extern const char D_490830[];
extern const char D_490870[];

void func_114320(const char *, int, const char *);
void func_1143C0(void *, int);

void func_00134E50(int n_mouse) {
    int i;
    char *ptr;

    if (n_mouse > 2) {
        func_114320(D_490820, 100, D_490830);
    }
    func_1143C0(&D_50A060, 0x10);
    D_50A060.handle = -1;
    D_50A060.count = n_mouse;
    func_1143C0(D_509F00, 0x160);
    D_50A060.buffer = D_509F00;
    i = 0;
    if (n_mouse > 0) {
        ptr = D_509F00;
        do {
            *(short *)(ptr + 0) = i;
            *(short *)(ptr + 2) = -1;
            *(int *)(ptr + 0x14) = 4;
            i++;
            ptr += 0xB0;
        } while (i < n_mouse);
    }
}

int func_134210(int, int, int);
void func_1344C0(int);
void func_134500(int);
void func_134440(int);
void func_1348A8(int);
void func_00135D60(int);
void func_00135D98(void);
void func_117AF8(void *, const void *, int);
void *func_00135530(void);
int *func_001350E0(int);
int func_00135258(int);

/*
 * func_00134F18:
 * Section padding / alignment function.
 * In the original AOK.ELF binary (VRAM 0x00134F18, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for section alignment between mouse work routines.
 */
void func_00134F18(void) {}

void func_00134F20(void) {
    D_50A060.handle = func_134210(1, 1, 0);
}

void func_00134F50(void) {
    if (D_50A060.handle != -1) {
        func_1344C0(D_50A060.handle);
        D_50A060.handle = -1;
    }
}

void func_00134F90(void) {
    if (D_50A060.handle != -1) {
        func_134500(D_50A060.handle);
    }
}

void func_00134FB8(void) {
    if (D_50A060.handle != -1) {
        func_134440(D_50A060.handle);
    }
}

int func_00134FE0(int a0, int a1) {
    int next = a1 + 1;
    if (next < *(int *)(D_50A060.buffer + (a0 * 0xB0) + 0x14)) {
        return next;
    }
    return 0;
}

void func_00135008(int a0) {
    char *base = (char *)(a0 * 0xB0);
    *(int *)(base + (int)D_50A060.buffer + 0x1C) = func_00134FE0(a0, *(int *)(base + (int)D_50A060.buffer + 0x1C));
}

int *func_00135058(int a0) {
    int idx;
    a0 = a0 * 0xB0 + (int)D_50A060.buffer;
    idx = *(int *)(a0 + 0x1C);
    a0 += 0x20;
    if (a0 != 0) {
        a0 += idx * 0x24;
    }
    return (int *)a0;
}

void func_00135090(int a0) {
    char *base = (char *)(a0 * 0xB0);
    *(int *)(base + (int)D_50A060.buffer + 0x18) = func_00134FE0(a0, *(int *)(base + (int)D_50A060.buffer + 0x18));
}

int *func_001350E0(int a0) {
    int idx;
    a0 = a0 * 0xB0 + (int)D_50A060.buffer;
    idx = *(int *)(a0 + 0x18);
    a0 += 0x20;
    if (a0 != 0) {
        a0 += idx * 0x24;
    }
    return (int *)a0;
}

int func_00135118(int a0, int *out) {
    int *entry;
    int res = 0;

    func_00134F90();
    entry = func_001350E0(a0);
    if (entry != 0 && *entry != 0) {
        int *data = entry + 1;
        res = 1;
        out[0] = data[0];
        out[1] = data[1];
        out[2] = data[2];
        out[3] = data[3];
        *entry = 0;
        func_00135090(a0);
    }
    func_00134FB8();
    return res;
}

short func_001351B0(short *ptr) {
    return ptr[1];
}

extern const char D_490850[];

short func_001351B8(int a0) {
    short res;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x16B, D_490850);
    }
    func_00134F90();
    res = func_001351B0((short *)(D_50A060.buffer + (a0 * 0xB0)));
    func_00134FB8();
    return res;
}

int func_00135238(short *ptr) {
    int res = 0;
    if (ptr[1] != -1) {
        res = *(int *)(ptr + 2);
    }
    return res;
}

int func_00135258(int a0) {
    short *ptr;
    int res;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x188, D_490850);
    }
    ptr = (short *)(D_50A060.buffer + (a0 * 0xB0));
    func_00134F90();
    res = func_00135238(ptr);
    func_00134FB8();
    return res;
}

int func_001352D8(int a0, int *out) {
    char *ptr;
    int type;
    int len = 0;
    int i;
    char *src;
    char *dst;

    if (out != 0) {
        if (D_50A060.count <= a0) {
            func_114320(D_490820, 0x19D, D_490850);
        }
        ptr = D_50A060.buffer + (a0 * 0xB0);
        func_00134F90();
        type = func_00135238((short *)ptr);
        if ((unsigned int)(type - 1) < 3) {
            len = *(int *)(ptr + 8);
            i = 0;
            if (len > 0) {
                char *src = ptr + 0xC;
                char *dst = (char *)(out + 1);
                do {
                    dst[i] = src[i];
                    i++;
                } while (i < len);
            }
        }
        *out = type;
        func_00134FB8();
    }
    return len;
}

int func_001353C0(int a0) {
    int res = 0;
    int count = D_50A060.count;
    int i;

    func_00134F90();
    for (i = 0; i < count; i++) {
        char *port = D_50A060.buffer + i * 0xB0;
        int ret = func_001351B0((short *)port);

        if (a0 != 0 || ret == 0) {
            *(short *)(port + 2) = -1;
            res++;
        }
    }
    func_00134FB8();
    return res;
}

extern int D_50A06C;

void func_00135478(void) {
    func_00134F90();
    D_50A06C = 1;
    func_00134FB8();
}

void func_001354A0(void) {
    func_00134F90();
    D_50A06C = 0;
    func_00134FB8();
}

void func_001354C8(int a0) {
    func_1348A8(2);
    func_00134E50(a0);
    func_00134F20();
    func_00135D60(a0);
}

void func_00135508(void) {
    func_00135D98();
    func_00134F18();
    func_00134F50();
}

void *func_00135530(void) {
    int i;
    char *res = 0;
    int count = D_50A060.count;
    char *buffer = D_50A060.buffer;

    for (i = 0; i < count; i++) {
        if (*(short *)(buffer + i * 0xB0 + 2) == -1) {
            res = buffer + i * 0xB0;
            break;
        }
    }
    return res;
}

void func_00135598(int *ptr) {
    if (ptr != 0) {
        func_1143C0((char *)ptr + 0xC, 0x90);
        ptr[1] = 0;
        ptr[2] = 0;
    }
}

int func_001355D0(int a0) {
    short res;
    short *ptr;

    func_00134F90();
    res = -1;
    ptr = (short *)func_00135530();
    if (ptr != 0) {
        *(int *)(ptr + 2) = a0;
        ptr[1] = 0;
        func_00135598((int *)(ptr + 10));
        res = ptr[0];
    }
    func_00134FB8();
    return res;
}

void func_00135638(int a0, int a1) {
    char *ptr;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x23B, D_490870);
    }
    func_00134F90();
    ptr = D_50A060.buffer + (a0 * 0xB0);
    if (func_00135238((short *)ptr) == a1) {
        *(int *)(ptr + 4) = 0;
        *(short *)(ptr + 2) = -1;
        func_00135598((int *)(ptr + 0x14));
    }
    func_00134FB8();
}

int func_001356D8(short *ptr) {
    return ptr[1] != -1;
}

int func_001356E8(int a0, int a1) {
    int res = -1;
    char *port;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x259, D_490870);
    }
    if (a0 >= 0) {
        func_00134F90();
        port = D_50A060.buffer + (a0 * 0xB0);
        if (func_001356D8((short *)port) != 0) {
            *(short *)(port + 2) = a1;
            res = 0;
        }
        func_00134FB8();
    }
    return res;
}

int func_00135798(int a0, void *a1, int a2) {
    int res = -1;
    char *port;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x276, D_490870);
    }
    if (a0 >= 0) {
        func_00134F90();
        port = D_50A060.buffer + (a0 * 0xB0);
        if (func_001356D8((short *)port) != 0) {
            if ((unsigned int)a2 >= 9) {
                a2 = 8;
            }
            func_117AF8(port + 0xC, a1, a2);
            res = 0;
            *(int *)(port + 8) = a2;
        }
        func_00134FB8();
    }
    return res;
}

int func_00135870(int a0, int a1, int a2, int a3, int a4) {
    int res = -1;
    char *port;
    int *entry;
    int *data;

    if (D_50A060.count <= a0) {
        func_114320(D_490820, 0x293, D_490870);
    }
    if (a0 >= 0) {
        func_00134F90();
        port = D_50A060.buffer + (a0 * 0xB0);
        if (func_001356D8((short *)port) != 0) {
            entry = func_00135058(a0);
            if (entry != 0 && *entry == 0) {
                data = entry + 1;
                *entry = 1;
                data[0] = a1;
                data[1] = a2;
                data[2] = a3;
                data[3] = a4;
                func_00135008(a0);
            }
            res = 0;
        }
        func_00134FB8();
    }
    return res;
}

int func_00135980(void) {
    int res;

    func_00134F90();
    res = D_50A06C;
    func_00134FB8();
    return res;
}

typedef struct {
    int f0;
    int f4;
    int f8;
} MouseBlock_9B8;

void func_001359B8(MouseBlock_9B8 *ptr, int val) {
    ptr->f4 = val;
    ptr->f0 = -1;
    ptr->f8 = -1;
}

void func_001359D0(char *ptr, int count, int stride) {
    int i;
    for (i = 0; i < count; i++) {
        func_001359B8((MouseBlock_9B8 *)ptr, i);
        ptr += stride;
    }
}

void func_00135A38(char *ptr, int count, int stride, int a3) {
    if (count > 0) {
        int n = count;
        do {
            int f8 = *(int *)(ptr + 8);
            int f4 = *(int *)(ptr + 4);
            if (f8 >= 0) {
                if (a3 != func_00135258(f8)) {
                    func_001359B8((MouseBlock_9B8 *)ptr, f4);
                }
            }
            ptr += stride;
        } while (--n);
    }
}

void func_00135AB8(char *ptr, int count, int stride, int a3, char *buf) {
    int i = 0;
    int n = count;
    if (buf[0] < n) {
        n = buf[0];
    }
    if (n > 0) {
        do {
            int val = *(int *)(ptr + 8);
            if (buf[i + 2] != 0) {
                if (val < 0) {
                    val = func_001355D0(a3);
                    *(int *)(ptr + 8) = val;
                }
                func_001356E8(val, 1);
                *(int *)(ptr + 0) = 1;
            } else {
                func_001356E8(val, 0);
                *(int *)(ptr + 0) = 0;
            }
            i++;
            ptr += stride;
        } while (i < n);
    }
}

extern char D_50A080[];
void func_001359D0(char *, int, int);

void func_00135B88(int a0) {
    if (a0 >= 2) {
        a0 = 1;
    }
    func_1143C0(D_50A080, 0x18);
    *(int *)(D_50A080 + 8) = a0;
    *(int *)(D_50A080 + 4) = -1;
    func_001359D0(D_50A080 + 0xC, 1, 0xC);
}

void func_134A20(void);
void func_00135BE8(void) {
    func_134A20();
}

extern char D_50A08C[];
extern char D_50A0C0[];
extern char D_50A140[];
extern signed char D_50A1C0[];
int func_00135DE8(void *);
int func_00135E30(int, void *);
int func_00135E78(int, void *);

void func_00135BF0(void) {
    MouseBlock_9B8 *entry_arr = (MouseBlock_9B8 *)D_50A08C;
    int count = *(int *)((char *)entry_arr - 4);
    int i;
    int mouse_id;

    if (func_00135DE8(D_50A0C0) != 0) {
        return;
    }
    func_00135A38((char *)entry_arr, count, 0xC, 1);
    func_00135AB8((char *)entry_arr, count, 0xC, 1, D_50A0C0);
    for (i = 0; i < count; i++) {
        mouse_id = entry_arr[i].f8;
        if ((unsigned char)D_50A0C0[i + 2] == 0) {
            continue;
        }
        if (func_00135E78(i, D_50A140) == 0) {
            func_00135798(mouse_id, D_50A140, 7);
            while (func_00135E30(i, D_50A1C0) == 0) {
                if (D_50A1C0[0] == 0) {
                    break;
                }
                func_00135870(mouse_id, D_50A1C0[1], D_50A1C0[2], D_50A1C0[3], (D_50A1C0[0] < 4) ? 0 : D_50A1C0[4]);
                D_50A1C0[0] = 0;
            }
        }
    }
}

int func_00135DA0(void);

void func_00135D60(int a0) {
    func_00135B88(a0);
    while (func_00135DA0()) {
        func_00135BE8();
    }
}

/*
 * func_00135D98:
 * Section padding / alignment function.
 * In the original AOK.ELF binary (VRAM 0x00135D98, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for section alignment between mouse device routines.
 */
void func_00135D98(void) {}

typedef struct {
    char pad[0x24];
    unsigned int status;
} MouseDevice_DA0;

extern MouseDevice_DA0 D_50A240;
void func_1075C8(int);
void func_107C38(MouseDevice_DA0 *, unsigned int, int);

int func_00135DA0(void) {
    func_1075C8(0);
    func_107C38(&D_50A240, 0x80000210, 0);
    return D_50A240.status < 1;
}

extern int D_50A280[];
int func_107E08(MouseDevice_DA0 *, int, int, int *, int, void *, int, int, int);

int func_00135DE8(void *a0) {
    return func_107E08(&D_50A240, 1, 0, D_50A280, 0x20, a0, 0x20, 0, 0);
}

int func_00135E30(int a0, void *a1) {
    D_50A280[0] = a0;
    return func_107E08(&D_50A240, 2, 0, D_50A280, 0x20, a1, 0x20, 0, 0);
}

int func_00135E78(int a0, void *a1) {
    D_50A280[0] = a0;
    return func_107E08(&D_50A240, 3, 0, D_50A280, 0x20, a1, 0x20, 0, 0);
}
