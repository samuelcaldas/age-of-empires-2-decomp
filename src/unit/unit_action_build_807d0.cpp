#pragma exceptions off
#include "unit_action_build_807d0.h"

struct Table1 {
    char pad_0[80];
    short count;          // 0x50
    char pad_52[2];
    void **items;         // 0x54
};

struct Table2 {
    char pad_0[2976];
    int active_id;        // 0xBA0
};

extern "C" {
extern void *D_4E3418;
extern void *D_4E3420;
int func_202B10(void *item);
int func_205920(void *table, int index);
}

void func_002807D0(int code, ActionCallback callback, void *param) {
    switch (code) {
    case -101: {
        register int i;
        register unsigned short match;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (((Table2 *)D_4E3420)->active_id != i) {
                if ((unsigned char)func_205920(D_4E3420, i) == 0) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -102: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            if (func_202B10(((Table1 *)D_4E3418)->items[i])) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -103: {
        register unsigned short match;
        register unsigned short c1;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            c1 = 0;
            if (((Table2 *)D_4E3420)->active_id != i) {
                if (func_202B10(((Table1 *)D_4E3418)->items[i])) {
                    c1 = 1;
                }
            }
            if (c1) {
                if ((unsigned char)func_205920(D_4E3420, i) == 0) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -104: {
        register unsigned short match;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (func_202B10(((Table1 *)D_4E3418)->items[i])) {
                if ((unsigned char)func_205920(D_4E3420, i) == 3) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -105: {
        register unsigned short match;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (func_202B10(((Table1 *)D_4E3418)->items[i])) {
                if ((unsigned char)func_205920(D_4E3420, i) == 1) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -106: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = ((unsigned char)func_205920(D_4E3420, i) == 3);
            if (match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -107: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = !func_202B10(((Table1 *)D_4E3418)->items[i]);
            if (match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -108: {
        register unsigned short match;
        register unsigned short c1;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            c1 = 0;
            if (((Table2 *)D_4E3420)->active_id != i) {
                if (((unsigned int)func_202B10(((Table1 *)D_4E3418)->items[i]) > 0) ^ 1) {
                    c1 = 1;
                }
            }
            if (c1) {
                if ((unsigned char)func_205920(D_4E3420, i) == 0) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -109: {
        register unsigned short match;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (((unsigned int)func_202B10(((Table1 *)D_4E3418)->items[i]) > 0) ^ 1) {
                if ((unsigned char)func_205920(D_4E3420, i) == 3) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -110: {
        register unsigned short match;
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (((unsigned int)func_202B10(((Table1 *)D_4E3418)->items[i]) > 0) ^ 1) {
                if ((unsigned char)func_205920(D_4E3420, i) == 1) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -111: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = ((unsigned char)func_205920(D_4E3420, i) == 1);
            if (match) {
                callback(i, param);
                break;
            }
        }
        break;
    }
    case -201: {
        register int i;
        register unsigned short match;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            match = 0;
            if (((Table2 *)D_4E3420)->active_id != i) {
                if ((unsigned char)func_205920(D_4E3420, i) == 0) {
                    match = 1;
                }
            }
            if ((unsigned char)match) {
                callback(i, param);
            }
        }
        break;
    }
    case -202: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            if (func_202B10(((Table1 *)D_4E3418)->items[i])) {
                callback(i, param);
            }
        }
        break;
    }
    case -203: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = ((unsigned char)func_205920(D_4E3420, i) == 3);
            if (match) {
                callback(i, param);
            }
        }
        break;
    }
    case -204: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = !func_202B10(((Table1 *)D_4E3418)->items[i]);
            if (match) {
                callback(i, param);
            }
        }
        break;
    }
    case -205: {
        register int i;
        for (i = 1; i < ((Table1 *)D_4E3418)->count; i++) {
            unsigned char match = ((unsigned char)func_205920(D_4E3420, i) == 1);
            if (match) {
                callback(i, param);
            }
        }
        break;
    }
    default:
        break;
    }
}

void func_2807D0(int code, ActionCallback callback, void *param) {
    func_002807D0(code, callback, param);
}
