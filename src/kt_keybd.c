#include "common.h"

typedef struct {
    int handle;
    int count;
    char *buffer;
} KeybdWork;

typedef struct {
    int f0;
    int f4;
    int f8;
} KeybdBlock;

extern KeybdWork D_50A338;
extern char D_50A2C0[];
extern char D_50A380[];
extern char D_50A38C[];
extern char D_50A3C0[];
extern char D_50A440[];
extern char D_50A4C0[];

extern const char D_490888[];
extern const char D_4908A8[];
extern const char D_4908B8[];
extern const char D_4908C8[];
extern const char D_4908E8[];
extern const char D_490900[];
extern const char D_490910[];
extern const char D_490928[];
extern const char D_490938[];
extern const char D_490950[];
extern const char D_490968[];
extern const char D_490980[];
extern const char D_490998[];
extern const char D_4909B0[];
extern const char D_4909D0[];
extern const char D_4909F0[];
extern const char D_490A08[];
extern const char D_490A20[];
extern const char D_490A40[];

void func_123790(const char *, const char *, int, const char *);
void func_1143C0(void *, int);
int func_134210(int, int, int);
void func_1344C0(int);
void func_134500(int);
void func_134440(int);
void func_1348A8(int);
void func_134A20(void);
void func_117AF8(void *, const void *, int);
void func_117CAC(void *, int, int);

void func_001371C8(int);
void func_00137200(void);
int func_00137208(void);
int func_00137250(void *);
int func_001372C0(int, void *);
int func_00137340(int, void *);
int func_001373C0(int, int);
int func_00137420(int, int);

void func_00135EC0(int n_keybd) {
    int i;
    char *ptr;

    if (n_keybd >= 2) {
        func_123790(D_490888, D_4908A8, 0x66, D_4908B8);
    }
    func_1143C0(&D_50A338, 0xC);
    D_50A338.handle = -1;
    D_50A338.count = n_keybd;
    func_1143C0(D_50A2C0, 0x78);
    D_50A338.buffer = D_50A2C0;
    i = 0;
    if (n_keybd > 0) {
        ptr = D_50A2C0;
        do {
            *(short *)(ptr + 0) = i;
            *(short *)(ptr + 2) = -1;
            *(int *)(ptr + 0x1C) = 4;
            i++;
            ptr += 0x78;
        } while (i < n_keybd);
    }
}

void func_00135F90(void) {
}

void func_00135F98(void) {
    D_50A338.handle = func_134210(1, 1, 0);
}

void func_00135FC8(void) {
    if (D_50A338.handle != -1) {
        func_1344C0(D_50A338.handle);
        D_50A338.handle = -1;
    }
}

void func_00136008(void) {
    if (D_50A338.handle != -1) {
        func_134500(D_50A338.handle);
    }
}

void func_00136030(void) {
    if (D_50A338.handle != -1) {
        func_134440(D_50A338.handle);
    }
}

int func_00136058(int a0, int a1) {
    int next = a1 + 1;
    if (next < *(int *)(D_50A338.buffer + (a0 * 0x78) + 0x1C)) {
        return next;
    }
    return 0;
}

void func_00136080(int a0) {
    char *base = (char *)(a0 * 0x78);
    *(int *)(base + (int)D_50A338.buffer + 0x24) = func_00136058(a0, *(int *)(base + (int)D_50A338.buffer + 0x24));
}

int *func_001360D0(int a0) {
    int idx;
    a0 = a0 * 0x78 + (int)D_50A338.buffer;
    idx = *(int *)(a0 + 0x24);
    a0 += 0x28;
    if (a0 != 0) {
        a0 += idx * 0x14;
    }
    return (int *)a0;
}

void func_00136108(int a0) {
    char *base = (char *)(a0 * 0x78);
    *(int *)(base + (int)D_50A338.buffer + 0x20) = func_00136058(a0, *(int *)(base + (int)D_50A338.buffer + 0x20));
}

int *func_00136158(int a0) {
    int idx;
    a0 = a0 * 0x78 + (int)D_50A338.buffer;
    idx = *(int *)(a0 + 0x20);
    a0 += 0x28;
    if (a0 != 0) {
        a0 += idx * 0x14;
    }
    return (int *)a0;
}

typedef struct {
    char data[16];
} KeybdData16;

int func_00136190(int a0, KeybdData16 *out) {
    int *entry;
    int res = 0;

    func_00136008();
    entry = func_00136158(a0);
    if (entry != 0 && *entry != 0) {
        *out = *(KeybdData16 *)(entry + 1);
        res = 1;
        *entry = 0;
        func_00136108(a0);
    }
    func_00136030();
    return res;
}

short func_00136228(short *ptr) {
    return ptr[1];
}

short func_00136230(int a0) {
    short res;

    if (D_50A338.count <= a0) {
        func_123790(D_4908C8, D_4908A8, 0x114, D_4908E8);
    }
    func_00136008();
    res = func_00136228((short *)(D_50A338.buffer + (a0 * 0x78)));
    func_00136030();
    return res;
}

int func_001362B8(short *ptr) {
    int res = 0;
    if (ptr[1] != -1) {
        res = *(int *)(ptr + 2);
    }
    return res;
}

int func_001362D8(int a0) {
    short *ptr;
    int res;

    if (D_50A338.count <= a0) {
        func_123790(D_4908C8, D_4908A8, 0x130, D_490900);
    }
    ptr = (short *)(D_50A338.buffer + (a0 * 0x78));
    func_00136008();
    res = func_001362B8(ptr);
    func_00136030();
    return res;
}

int func_00136360(int a0, int *out) {
    char *ptr;
    int type;
    int len = 0;
    int i;

    if (out != 0) {
        if (D_50A338.count <= a0) {
            func_123790(D_4908C8, D_4908A8, 0x145, D_490910);
        }
        ptr = D_50A338.buffer + (a0 * 0x78);
        func_00136008();
        type = func_001362B8((short *)ptr);
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
        func_00136030();
    }
    return len;
}

int func_00136450(int a0) {
    int res = 0;
    int count = D_50A338.count;
    int i;

    func_00136008();
    for (i = 0; i < count; i++) {
        char *port = D_50A338.buffer + i * 0x78;
        int ret = func_00136228((short *)port);

        if (a0 != 0 || ret == 0) {
            *(short *)(port + 2) = -1;
            res++;
        }
    }
    func_00136030();
    return res;
}

void func_00136508(int a0, int a1) {
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_4908C8, D_4908A8, 0x183, D_490928);
    }
    func_00136008();
    port = D_50A338.buffer + (a0 * 0x78);
    *(int *)(port + 0x14) = a1 | 0x80000000;
    func_00136030();
}

void func_00136598(int a0, int a1) {
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_4908C8, D_4908A8, 0x192, D_490938);
    }
    func_00136008();
    port = D_50A338.buffer + (a0 * 0x78);
    *(int *)(port + 0x18) = a1 | 0x80000000;
    func_00136030();
}

void func_00136628(int a0) {
    func_1348A8(2);
    func_00135EC0(a0);
    func_00135F98();
    func_001371C8(a0);
}

void func_00136668(void) {
    func_00137200();
    func_00135F90();
    func_00135FC8();
}

void *func_00136690(void) {
    int i;
    char *res = 0;
    int count = D_50A338.count;
    char *buffer = D_50A338.buffer;

    for (i = 0; i < count; i++) {
        if (*(short *)(buffer + i * 0x78 + 2) == -1) {
            res = buffer + i * 0x78;
            break;
        }
    }
    return res;
}

void func_001366F8(int *ptr) {
    if (ptr != 0) {
        func_1143C0((char *)ptr + 0xC, 0x50);
        ptr[1] = 0;
        ptr[2] = 0;
    }
}

int func_00136730(int a0) {
    int res = -1;
    short *port;

    func_00136008();
    port = (short *)func_00136690();
    if (port != 0) {
        *(int *)(port + 2) = a0;
        port[1] = 0;
        func_001366F8((int *)(port + 14));
        res = port[0];
    }
    func_00136030();
    return res;
}

void func_00136798(int a0, int a1) {
    short *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x1F9, D_490968);
    }
    func_00136008();
    port = (short *)(D_50A338.buffer + (a0 * 0x78));
    if (func_001362B8(port) == a1) {
        *(int *)(port + 2) = 0;
        port[1] = -1;
        func_001366F8((int *)(port + 14));
    }
    func_00136030();
}

int func_00136840(short *ptr) {
    return ptr[1] != -1;
}

int func_00136850(int a0, int a1) {
    int res = -1;
    short *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x217, D_490980);
    }
    if (a0 >= 0) {
        func_00136008();
        port = (short *)(D_50A338.buffer + (a0 * 0x78));
        if (func_00136840(port) != 0) {
            port[1] = a1;
            res = 0;
        }
        func_00136030();
    }
    return res;
}

int func_00136908(int a0, const void *a1, int a2) {
    int res = -1;
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x234, D_490998);
    }
    if (a0 >= 0) {
        func_00136008();
        port = D_50A338.buffer + (a0 * 0x78);
        if (func_00136840((short *)port) != 0) {
            if ((unsigned int)a2 >= 9) {
                a2 = 8;
            }
            func_117AF8(port + 0xC, a1, a2);
            res = 0;
            *(int *)(port + 8) = a2;
        }
        func_00136030();
    }
    return res;
}

int func_001369E8(int a0, unsigned char a1, unsigned char a2, const void *a3, int a4) {
    int res = -1;
    int *entry;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x251, D_4909B0);
    }
    if (a4 >= 0xE) {
        func_123790(D_4909D0, D_4908A8, 0x252, D_4909B0);
    }
    if (a0 >= 0) {
        func_00136008();
        if (func_00136840((short *)(D_50A338.buffer + (a0 * 0x78))) != 0) {
            entry = func_001360D0(a0);
            if (entry != 0 && *entry == 0) {
                unsigned char *data = (unsigned char *)(entry + 1);
                *entry = 1;
                data[0] = a1;
                data[1] = a2;
                func_117AF8(data + 2, a3, a4);
                if (a4 < 0xE) {
                    int rem = 0xE - a4;
                    func_117CAC(data + (a4 + 2), 0, rem);
                }
                func_00136080(a0);
            }
            res = 0;
        }
        func_00136030();
    }
    return res;
}

int func_00136B50(int a0) {
    int res = 0;
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x280, D_4909F0);
    }
    if (a0 >= 0) {
        port = D_50A338.buffer + (a0 * 0x78);
        if (func_00136840((short *)port) != 0) {
            res = *(int *)(port + 0x14);
        }
    }
    return res;
}

void func_00136BE0(int a0, int a1) {
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x28F, D_490A08);
    }
    if (a0 >= 0) {
        port = D_50A338.buffer + (a0 * 0x78);
        if (func_00136840((short *)port) != 0) {
            func_00136008();
            *(int *)(port + 0x14) = a1;
            func_00136030();
        }
    }
}

int func_00136C90(int a0) {
    int res = 0;
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x2A4, D_490A20);
    }
    if (a0 >= 0) {
        port = D_50A338.buffer + (a0 * 0x78);
        if (func_00136840((short *)port) != 0) {
            res = *(int *)(port + 0x18);
        }
    }
    return res;
}

void func_00136D20(int a0, int a1) {
    char *port;

    if (D_50A338.count <= a0) {
        func_123790(D_490950, D_4908A8, 0x2B3, D_490A40);
    }
    if (a0 >= 0) {
        port = D_50A338.buffer + (a0 * 0x78);
        if (func_00136840((short *)port) != 0) {
            func_00136008();
            *(int *)(port + 0x18) = a1;
            func_00136030();
        }
    }
}

void func_00136DD0(KeybdBlock *ptr, int val) {
    ptr->f4 = val;
    ptr->f0 = -1;
    ptr->f8 = -1;
}

void func_00136DE8(char *ptr, int count, int stride) {
    int i;
    for (i = 0; i < count; i++) {
        func_00136DD0((KeybdBlock *)ptr, i);
        ptr += stride;
    }
}

void func_00136E50(char *ptr, int count, int stride, int a3) {
    if (count > 0) {
        int n = count;
        do {
            int f8 = *(int *)(ptr + 8);
            int f4 = *(int *)(ptr + 4);
            if (f8 >= 0) {
                if (a3 != func_001362D8(f8)) {
                    func_00136DD0((KeybdBlock *)ptr, f4);
                }
            }
            ptr += stride;
        } while (--n);
    }
}

void func_00136ED0(char *ptr, int count, int stride, int a3, char *buf) {
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
                    val = func_00136730(a3);
                    *(int *)(ptr + 8) = val;
                }
                func_00136850(val, 1);
                *(int *)(ptr + 0) = 1;
            } else {
                func_00136850(val, 0);
                *(int *)(ptr + 0) = 0;
            }
            i++;
            ptr += stride;
        } while (i < n);
    }
}

void func_00136FA0(int a0) {
    if (a0 >= 2) {
        a0 = 1;
    }
    func_1143C0(D_50A380, 0x18);
    *(int *)(D_50A380 + 8) = a0;
    *(int *)(D_50A380 + 4) = -1;
    func_00136DE8(D_50A380 + 0xC, 1, 0xC);
}

void func_00137000(void) {
    KeybdBlock *entry_arr = (KeybdBlock *)D_50A38C;
    int count = *(int *)((char *)entry_arr - 4);
    int i;
    int keybd_id;

    if (func_00137250(D_50A3C0) != 0) {
        return;
    }
    func_00136E50((char *)entry_arr, count, 0xC, 1);
    func_00136ED0((char *)entry_arr, count, 0xC, 1, D_50A3C0);
    for (i = 0; i < count; i++) {
        int req;
        keybd_id = entry_arr[i].f8;
        req = func_00136B50(keybd_id);
        if (req < 0) {
            req &= 0xFF;
            if (func_001373C0(i, req) == 0) {
                func_00136BE0(keybd_id, req);
            }
        }
        req = func_00136C90(keybd_id);
        if (req < 0) {
            req &= 0xFF;
            if (func_00137420(i, req) == 0) {
                func_00136D20(keybd_id, req);
            }
        }
        if ((unsigned char)D_50A3C0[i + 2] == 0) {
            continue;
        }
        if (func_00137340(i, D_50A440) == 0) {
            func_00136908(keybd_id, D_50A440, 7);
            while (func_001372C0(i, D_50A4C0) == 0) {
                if (D_50A4C0[1] == 0) {
                    break;
                }
                func_001369E8(keybd_id, (unsigned char)D_50A4C0[0], (unsigned char)D_50A4C0[2], D_50A4C0 + 4, (unsigned char)D_50A4C0[1]);
                D_50A4C0[1] = 0;
            }
        }
    }
}

void func_001371C8(int a0) {
    func_00136FA0(a0);
    while (func_00137208()) {
        func_134A20();
    }
}

void func_00137200(void) {
}
