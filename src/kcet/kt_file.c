#include "common.h"
#include "kt_file.h"

extern const char D_48FE38[];
extern const char D_48FE70[];
extern const char D_48FEA0[];
extern const char D_48FEB0[];
extern const char D_48FEC8[];
extern const char D_48FED8[];
extern const char D_48FF08[];
extern const char D_48FF28[];
extern const char D_48FF40[];

extern void *D_38C7F8[];
extern void *D_38C808[];
extern void *D_38C818[];
extern void *D_38C828[];
extern void *D_38C838[];
extern void *D_38C880[];

/* Forward declarations */
int func_0012CAC0(void *);
int func_0012CAD0(void *);
int func_0012CAE0(void);
int func_0012CAF0(void);
int func_0012CB00(void *);
int func_0012CB08(void *);
int func_0012CB10(int);
int func_0012CB20(void *);
int func_0012CB38(void);
int func_0012CB60(void *);
int func_0012CB90(void *);
int func_0012CBF8(void *);
int func_0012CC20(void *);
int func_0012CC48(void *);
void func_114320(const char *, int, const char *);
int func_118de0(const char *, ...);
int func_104FA0(void *);
int func_1075C8(int);
int func_107C38(void *);
int func_107E08(int, int, int, int, int, int, int, int);
int func_10E170(void);
int func_10E518(void);
int func_10EA20(int);
int func_10ECA0(void *);
int func_10EF80(int);
int func_10F178(void *);
int func_10F240(void);
int func_10F308(void);
int func_10F368(int, int, int, int);
int func_10F548(void);
int func_10F7D8(void);
int func_10F8A8(void);
int func_10F958(void);
int func_10FA08(void);
int func_10FAB8(void);
int func_10FB50(void);
int func_10FBE8(void);
int func_10FCA0(void);
int func_10FD58(void);
char *strcpy(char *, const char *);
int strcmp(const char *, const char *);

/* Function prototypes */
void *func_0012CCE8(char *table);
void *func_0012CDE0(char *table);
int func_0012CEA0(void *arg);
void *func_0012CF00(int kind);
int func_0012CF58(void *arg);
int func_0012CFC8(void *arg);
int func_0012D038(void *arg);
int func_0012D060(void *arg);
int func_0012D0D0(int arg);
int func_0012D0D8(void);
int func_0012D0E0(void *arg);
int func_0012D128(int a0, void *table, int count);
int func_0012D1F0(void *arg);
int func_0012D218(int arg);
int func_0012D220(void);
int func_0012D228(void *arg);
int func_0012D2D8(int arg);
int func_0012D2E0(void *arg);
int func_0012D308(void);
int func_0012D310(void *arg);
int func_0012D400(void *arg);
int func_0012D470(void *arg);
int func_0012D4A0(void *arg);
int func_0012D4C8(void);
int func_0012D4D0(void *arg);
int func_0012D540(void *arg);
int func_0012D5F0(void *a0, void *a1);
int func_0012D648(void);
int func_0012D7E0(const char *name);
int func_0012D840(int arg);
int func_0012D888(void);
int func_0012D8D8(int a0, int a1, int a2, int a3);
int func_0012D988(void);
int func_0012D990(void);
int func_0012DA00(void);
int func_0012DA38(void);
int func_0012DA88(void);
int func_0012DAC8(void);
int func_0012DB08(void);
int func_0012DB48(void);
int func_0012DB80(void);
int func_0012DBA0(void);
int func_0012DBC0(void);
int func_0012DBE0(void);
int func_0012DC00(void);
int func_0012DC20(void);
int func_0012DC60(void);
int func_0012DC80(void);
int func_0012DCA0(void);
int func_0012DCC0(void);

/* func_0012CCE8 */
void *func_0012CCE8(char *table) {
    void *old_table;
    int count = 0;
    int min_val = 0x7FFFFFFF;
    char *p;
    int i;

    if (table != 0) {
        old_table = (void *)D_4F1508.record_table;
        if (*(short *)table != 0) {
            do {
                count++;
            } while (*(short *)(table + (count << 3)) != 0);
        }
        if (count > 0) {
            p = table;
            for (i = count; i != 0; i--) {
                int val = func_0012CB60(p);
                if (val < min_val) {
                    min_val = val;
                }
                p += 8;
            }
        }
    }
    D_4F1508.record_table = (GuestAddr)(u32)table;
    D_4F1508.min_val = min_val;
    func_118de0(D_48FE38, table, count, min_val);
    D_4F1508.record_count = count;
    return old_table;
}

/* func_0012CDE0 */
void *func_0012CDE0(char *table) {
    void *old_table;
    int count = 0;
    int offset = 0;

    if (table != 0) {
        old_table = (void *)D_4F1508.entry_table;
        while (func_0012CBF8(table + offset) != 0) {
            count++;
            offset += func_0012CC20(table + offset);
        }
    }
    D_4F1508.entry_count = count;
    func_118de0(D_48FE70, table, count);
    D_4F1508.entry_table = (GuestAddr)(u32)table;
    return old_table;
}

/* func_0012CEA0 */
int func_0012CEA0(void *arg) {
    if (arg == 0) {
        return 3;
    }
    if (func_0012CB00(arg) != 0) {
        return 0;
    }
    if (func_0012CB00((void *)(int)*(unsigned short *)arg) != 0) {
        return 2;
    }
    if (*(unsigned short *)arg != 0x40) {
        return 2;
    }
    return 1;
}

/* func_0012CF00 */
void *func_0012CF00(int kind) {
    if ((unsigned int)kind >= 4) {
        func_114320(D_48FEA0, 0x16A, D_48FEB0);
    }
    return D_38C7F8[kind];
}

/* func_0012CF58 */
typedef int (*DispatchFn)(void *);
int func_0012CF58(void *arg) {
    int kind = func_0012CEA0(arg);
    if ((unsigned int)kind >= 4) {
        func_114320(D_48FEA0, 0x183, D_48FEB0);
    }
    return ((DispatchFn)D_38C808[kind])(arg);
}

/* func_0012CFC8 */
int func_0012CFC8(void *arg) {
    int kind = func_0012CEA0(arg);
    if ((unsigned int)kind >= 4) {
        func_114320(D_48FEA0, 0x19B, D_48FEB0);
    }
    return ((DispatchFn)D_38C818[kind])(arg);
}

/* func_0012D038 */
int func_0012D038(void *arg) {
    return func_0012CC48((void *)func_0012CFC8(arg));
}

/* func_0012D060 */
int func_0012D060(void *arg) {
    int kind = func_0012CEA0(arg);
    if ((unsigned int)kind >= 4) {
        func_114320(D_48FEA0, 0x1BA, D_48FEB0);
    }
    return ((DispatchFn)D_38C828[kind])(arg);
}

/* func_0012D0D0 */
int func_0012D0D0(int arg) {
    return arg;
}

/* func_0012D0D8 */
int func_0012D0D8(void) {
    return 0;
}

/* func_0012D0E0 */
int func_0012D0E0(void *arg) {
    int count = func_0012CAC0(arg);
    void *table = (void *)func_0012CAD0(arg);
    return func_0012D128((int)arg, table, count);
}

/* func_0012D128 */
int func_0012D128(int key, void *table, int count) {
    int low = 0;
    int high = count;
    FileRecord *entry;
    int mid;

    if (table != NULL && count > 0) {
        do {
            mid = (low + high) / 2;
            entry = (FileRecord *)table + mid;
            if (key < func_0012CB10(entry->id)) {
                high = mid;
            } else {
                if (func_0012CB10(entry->id) >= key) {
                    return (int)entry;
                }
                low = mid + 1;
            }
        } while (low < high);
    }
    return 0;
}

/* func_0012D1F0 */
int func_0012D1F0(void *arg) {
    return func_0012D0E0((void *)func_0012D310(arg));
}

/* func_0012D218 */
int func_0012D218(int arg) {
    return arg;
}

/* func_0012D220 */
int func_0012D220(void) {
    return 0;
}

/* func_0012D228 */
int func_0012D228(void *arg) {
    int count = func_0012CAE0();
    char *table = (char *)func_0012CAF0();
    int offset = 0;
    int i;
    char *entry;

    if (table == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        entry = table + offset;
        if (func_0012CBF8(entry) == (int)arg) {
            return (int)entry;
        }
        offset += func_0012CC20(entry);
    }
    return 0;
}

/* func_0012D2D8 */
int func_0012D2D8(int arg) {
    return arg;
}

/* func_0012D2E0 */
int func_0012D2E0(void *arg) {
    return func_0012D228((void *)func_0012CB38());
}

/* func_0012D308 */
int func_0012D308(void) {
    return 0;
}

/* func_0012D310 */
int func_0012D310(void *arg) {
    int count = func_0012CAE0();
    char *table = (char *)func_0012CAF0();
    int offset = 0;
    int i;
    char *entry;

    if (table == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        entry = table + offset;
        if (strcmp((char *)arg + 4, entry + 4) == 0) {
            return (int)entry;
        }
        offset += func_0012CC20(entry);
    }
    return 0;
}

/* func_0012D400 */
int func_0012D400(void *arg) {
    int res = func_0012D0E0(arg);
    if (res != 0) {
        return func_0012CB20((void *)res);
    }
    res = func_0012D228(arg);
    if (res != 0) {
        return func_0012CB08((void *)func_0012CBF8((void *)res));
    }
    return 0;
}

/* func_0012D470 */
int func_0012D470(void *arg) {
    return func_0012CB08((void *)func_0012CB20((void *)func_0012D1F0(arg)));
}

/* func_0012D4A0 */
int func_0012D4A0(void *arg) {
    return func_0012CB08((void *)func_0012CB20(arg));
}

/* func_0012D4C8 */
int func_0012D4C8(void) {
    return 0;
}

/* func_0012D4D0 */
int func_0012D4D0(void *arg) {
    int kind = func_0012CEA0(arg);
    if ((unsigned int)kind >= 4) {
        func_114320(D_48FEA0, 0x2B1, D_48FEB0);
    }
    return ((DispatchFn)D_38C838[kind])(arg);
}

/* func_0012D540 */
int func_0012D540(void *arg) {
    func_0012CF00(func_0012CEA0(arg));
    func_0012D060(arg);
    func_0012CF58(arg);
    func_0012CFC8(arg);
    func_0012CB60(arg);
    func_0012CB90(arg);
    return func_0012CC48(arg);
}

/* func_0012D5F0 */
int func_0012D5F0(void *a0, void *a1) {
    int res = 1;
    if (func_10ECA0(a0) != 0) {
        func_10F178(a1);
    }
    return res;
}

/* func_0012D648 */
int func_0012D648(void) {
    int i;
    for (i = 0; i <= 0xFFFFF; i++) {
    }
    func_1075C8(0);
    return 0;
}

/* func_0012D7E0 */
int func_0012D7E0(const char *name) {
    strcpy(D_4F1540, name);
    return func_107E08((int)D_4F1640, 0x10, 0, (int)D_4F1540, 0x100, 0, 0, 0);
}

/* func_0012D840 */
int func_0012D840(int arg) {
    return func_107E08((int)D_4F1680, arg & 0xFF, 0, 0, 0, (int)D_38C880, 0x30, 0);
}

/* func_0012D888 */
int func_0012D888(void) {
    func_107E08((int)D_4F1680, 3, 0, 0, 0, (int)D_38C880, 1, 0);
    return *(unsigned char *)((char *)D_38C880 - 0x3780);
}

/* func_0012D8D8 */
int func_0012D8D8(int a0, int a1, int a2, int a3) {
    if (func_10EF80(1) == 2) {
        if (func_10F368(a0, a1, a2, a3) == 0) {
            func_10FCA0();
        }
    }
    return 0;
}

/* func_0012D988 */
int func_0012D988(void) {
    return 0;
}

/* func_0012D990 */
int func_0012D990(void) {
    return func_10EA20(1);
}

/* func_0012DA00 */
int func_0012DA00(void) {
    if (D_4F16C0.active != 0) {
        return D_4F16C0.bytes_remaining >> 11;
    }
    return 0;
}

/* func_0012DA38 */
int func_0012DA38(void) {
    int res = func_10FBE8();
    if (res != -1 && (res & 6) == 0) {
        res |= 6;
    }
    return res;
}

/* func_0012DA88 */
int func_0012DA88(void) {
    return func_10F958();
}

/* func_0012DAC8 */
int func_0012DAC8(void) {
    return func_10FA08();
}

/* func_0012DB08 */
int func_0012DB08(void) {
    return func_10F8A8();
}

/* func_0012DB48 */
int func_0012DB48(void) {
    return func_10FCA0();
}

/* func_0012DB80 */
int func_0012DB80(void) {
    return func_10EF80(0);
}

/* func_0012DBA0 */
int func_0012DBA0(void) {
    return func_10FB50();
}

/* func_0012DBC0 */
int func_0012DBC0(void) {
    return func_10FAB8();
}

/* func_0012DBE0 */
int func_0012DBE0(void) {
    return func_10F548();
}

/* func_0012DC00 */
int func_0012DC00(void) {
    return func_10E518();
}

/* func_0012DC20 */
int func_0012DC20(void) {
    return func_10F7D8();
}

/* func_0012DC60 */
int func_0012DC60(void) {
    return func_10E170();
}

/* func_0012DC80 */
int func_0012DC80(void) {
    return func_10F240();
}

/* func_0012DCA0 */
int func_0012DCA0(void) {
    return func_10F308();
}

/* func_0012DCC0 */
int func_0012DCC0(void) {
    return func_10FD58();
}
