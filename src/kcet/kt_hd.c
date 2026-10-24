#include "common.h"
#include "kt_hd.h"

#define NULL ((void *)0)

extern const char D_4E2BF0[]; /* "kt_hd.c" */
extern const char D_48F448[]; /* "prio > 0" */
extern const char D_48F458[]; /* "start_id == id" */
extern const char D_4E2C08[]; /* "name" */
extern const char D_48F478[]; /* "strlen(name) < MAX_NAME_LENGTH - strlen( head[0])" */
extern const char D_48F4B0[]; /* "len < KT_HD_HOSTNAME_LENGTH" */
extern const char D_4E2C10[]; /* "atfile:" */
extern const char D_4E2C18[]; /* "," */
extern const char D_4E2C20[]; /* "/" */

extern char *D_48F468[]; /* head strings table */
extern int (*D_4E2C28[])(int); /* {func_104D70, func_104D60} */

extern int D_4EA180[4];
extern void *D_4EA1C0;
extern int D_4EA7C0[];
extern char D_4EC1C0[64];
extern int D_4ED300[];

/* External functions */
int func_00128B18(void);
int func_00128B68(int *p);
int func_104C10(void *);
int func_104C20(void *, void *);
int func_104B20(void *);
int func_104B40(int, void *);
void func_114320(const char *, int, const char *);
int func_0011ACD0(const char *);
char *func_00128A20(char *, int);
int func_11AFB8(const char *, const char *, int);
int func_108D38(const char *, int);
int func_108FC0(int);
int func_109140(int, int, int);
int func_109378(int, void *, int);
int func_1095E8(int, void *, int);
int func_134210(int, int, int);
int func_134440(int);
int func_1344C0(int);
void func_12D988(void);
int func_12D990(void);
void func_103358(int);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);

/* GP / sdata variables */
static int s_hd_thread = 0;   /* -0x77d8 */
static int s_hd_state = 0;    /* -0x77d4 */
static int s_hd_var77d0 = 0;  /* -0x77d0 */
static int s_hd_var77cc = 0;  /* -0x77cc */
static int s_hd_flag77c8 = 0; /* -0x77c8 */
static int s_hd_flag77c4 = 0; /* -0x77c4 */
static int s_hd_init7bd4 = 0; /* -0x7bd4 */
static int s_hd_sema7bd8 = -1;/* -0x7bd8 */

/* Thread param struct for func_104B20 */
typedef struct {
    int unk0;
    int (*entry)(int *);
    void *stack;
    int stack_size;
    void *gp;
    int priority;
} ThreadParam;

/* Function 1: func_00128BA8 */
int func_00128BA8(int a0, int a1, int a2, int a3) {
    int status;
    ThreadParam param;
    int prio;
    int thid;

    status = func_00128B18();
    if (status != 1) {
        return 0;
    }

    func_104C10(&D_4EA1C0);
    func_104C20(&D_4EA1C0, &param);

    prio = param.priority;
    if (prio <= 0) {
        func_114320(D_4E2BF0, 0x115, D_48F448);
    }
    prio--;
    param.priority = prio;
    param.entry = func_00128B68;
    param.stack = (void *)&D_4EA1C0;
    param.stack_size = 0x2000;
    param.gp = (void *)D_4EA7C0;

    thid = func_104B20(&param);
    s_hd_thread = prio;
    s_hd_state = status;

    D_4EA180[0] = a0;
    D_4EA180[1] = a1;
    D_4EA180[2] = a2;
    D_4EA180[3] = a3;
    s_hd_var77cc = 0;
    s_hd_var77d0 = 0;

    if (func_104B40(thid, D_4EA180) != thid) {
        func_114320(D_4E2BF0, 0x131, D_48F458);
    }
    return a1;
}

/* Function 2: func_00128CF0 */
int func_00128CF0(int a0, int a1, int a2, int a3) {
    return func_00128BA8(a0, a1, a2, a3);
}

/* Function 3: func_00128D10 */
int func_00128D10(const char *name, void *buf, int size, int offset) {
    return func_00128DC0(name, buf, size, offset, 0);
}

/* Function 4: func_00128D30 */
int func_00128D30(const char *name, void *buf, int size, int offset) {
    return func_00128D90(name, buf, size, offset, 0);
}

/* Function 5: func_00128D50 */
int func_00128D50(const char *name, void *buf, int size, int offset) {
    return func_00128DC0(name, buf, size, offset, 1);
}

/* Function 6: func_00128D70 */
int func_00128D70(const char *name, void *buf, int size, int offset) {
    return func_00128D90(name, buf, size, offset, 1);
}

/* Function 7: func_00128D90 */
int func_00128D90(const char *name, void *buf, int size, int offset, int a4) {
    int res = func_00128DC0(name, buf, size, offset, a4);
    if (res == 0) {
        return size;
    }
    return 0;
}

/* Function 8: func_00128DC0 */
int func_00128DC0(const char *name, void *buf, int size, int offset, int a4) {
    int total_read = 0;
    int fd;
    int chunk_size;
    int bytes_left;

    if (!func_00129428(1)) {
        return 0;
    }

    fd = func_00128F70(name, 1, a4);
    if (fd >= 0) {
        int file_len = func_109140(fd, 0, 2);
        func_109140(fd, offset, 0);
        bytes_left = file_len - offset;
        if (size < bytes_left) {
            bytes_left = size;
        }
        if (bytes_left > 0) {
            chunk_size = (s_hd_flag77c8 == 2) ? bytes_left : 0x20000;
            while (bytes_left > 0) {
                int to_read = (chunk_size < bytes_left) ? chunk_size : bytes_left;
                int n = func_109378(fd, (char *)buf + total_read, to_read);
                total_read += n;
                bytes_left -= chunk_size;
            }
        }
        func_108FC0(fd);
    }
    func_001294A0();
    return total_read;
}

/* Function 9: func_00128EC8 */
int func_00128EC8(const char *name) {
    int len = 0;
    int fd;

    if (!func_00129428(1)) {
        return 0;
    }

    fd = func_00128F70(name, 1, 0);
    if (fd >= 0) {
        len = func_109140(fd, 0, 2);
        func_108FC0(fd);
    }
    func_001294A0();
    return len;
}

/* Function 10: func_00128F40 */
int func_00128F40(int flag) {
    if (flag == 0 || flag == 1) {
        s_hd_flag77c8 = flag;
    } else {
        s_hd_flag77c8 = 0;
    }
    s_hd_flag77c4 = s_hd_flag77c8;
    return s_hd_flag77c8;
}

/* Function 11: func_00128F68 */
int func_00128F68(void) {
    return s_hd_flag77c8;
}

/* Function 12: func_00128F70 */
int func_00128F70(const char *name, int flag, int mode) {
    char path[1024];
    const char *head[3];
    int i;
    int head_len = 0;
    const char *p;

    head[0] = D_48F468[0];
    head[1] = D_48F468[1];
    head[2] = D_48F468[2];

    if (name == NULL) {
        func_114320(D_4E2BF0, 0x224, D_4E2C08);
    }
    if ((u32)func_0011ACD0(name) >= (u32)(1024 - func_0011ACD0(head[0]))) {
        func_114320(D_4E2BF0, 0x225, D_48F478);
    }

    strcpy(path, head[s_hd_flag77c8]);

    for (i = 0; i < 3; i++) {
        head_len = func_0011ACD0(head[i]);
        if (func_11AFB8(name, head[i], head_len) == 0) {
            break;
        }
    }

    if (s_hd_flag77c8 == 2) {
        if (i >= 3) {
            head_len = 0;
        }
        p = name + head_len;
        if (*p == '/' || *p == '\\') {
            char *comma = func_00128A20(path, ',');
            if (comma != NULL) {
                comma[1] = '\0';
            }
        }
    } else {
        p = name + head_len;
    }

    strcat(path, p);
    return func_108D38(path, flag);
}

/* Function 13: func_00129108 */
int func_00129108(const char *name, void *buf, int size, int flag) {
    int fd;
    int written = 0;
    int bytes_left;
    int chunk_size;

    if (!func_00129428(1)) {
        return 0;
    }

    if (name == NULL || size == 0 || buf == NULL) {
        func_001294A0();
        return 0;
    }

    if (flag == 0) {
        fd = func_00128F70(name, 0x602, 0);
    } else if (flag == 1) {
        fd = func_00128F70(name, 0x202, 0);
        if (fd >= 0) {
            func_109140(fd, 0, 2);
        }
    } else {
        func_001294A0();
        return 0;
    }

    if (fd >= 0) {
        bytes_left = size;
        chunk_size = (s_hd_flag77c8 == 2) ? size : 0x20000;
        while (bytes_left > 0) {
            int to_write = (chunk_size < bytes_left) ? chunk_size : bytes_left;
            int n = func_1095E8(fd, (char *)buf + written, to_write);
            written += n;
            bytes_left -= chunk_size;
        }
        func_108FC0(fd);
        written = (int)(unsigned long)buf;
    } else {
        written = 0;
    }

    func_001294A0();
    return written;
}

/* Function 14: func_00129248 */
int func_00129248(const char *name) {
    if (name != NULL) {
        int len = func_0011ACD0(name);
        if (len + 9 >= 0x40) {
            func_114320(D_4E2BF0, 0x2AF, D_48F4B0);
        }
        strcpy(D_4EC1C0, D_4E2C10);
        strcat(D_4EC1C0, name);
        if (func_00128A20((char *)name, ',') == NULL) {
            strcat(D_4EC1C0, D_4E2C18);
        } else {
            len = func_0011ACD0(name);
            if (len != 0) {
                char last = name[len - 1];
                if (last != ',' && last != '/' && last != '\\') {
                    strcat(D_4EC1C0, D_4E2C20);
                }
            }
        }
        s_hd_flag77c8 = 2;
    } else {
        s_hd_flag77c8 = s_hd_flag77c4;
    }
    return s_hd_flag77c8;
}

/* Function 15: func_00129348 */
void func_00129348(void) {
    if (s_hd_init7bd4 == 0) {
        s_hd_state = 0;
        s_hd_var77d0 = 1;
        func_001293A8();
        s_hd_init7bd4 = 1;
    }
}

/* Function 16: func_00129388 */
void func_00129388(void) {
    func_001293E0();
    s_hd_init7bd4 = 0;
}

/* Function 17: func_001293A8 */
void func_001293A8(void) {
    if (s_hd_sema7bd8 == -1) {
        s_hd_sema7bd8 = func_134210(1, 1, 0);
    }
}

/* Function 18: func_001293E0 */
void func_001293E0(void) {
    if (s_hd_sema7bd8 != -1) {
        func_00129428(1);
        func_1344C0(s_hd_sema7bd8);
        s_hd_sema7bd8 = -1;
    }
}

/* Function 19: func_00129428 */
int func_00129428(int flag) {
    int (*fn)(int);
    if (s_hd_sema7bd8 == -1) {
        return 1;
    }
    fn = (flag != 0) ? D_4E2C28[1] : D_4E2C28[0];
    if (fn(s_hd_sema7bd8) == s_hd_sema7bd8) {
        return 1;
    }
    return 0;
}

/* Function 20: func_001294A0 */
void func_001294A0(void) {
    if (s_hd_sema7bd8 != -1) {
        func_134440(s_hd_sema7bd8);
    }
}

/* Function 21: func_001294C0 */
int func_001294C0(void) {
    return func_00129428(1);
}

/* Function 22: func_001294E0 */
void func_001294E0(void) {
    func_001294A0();
}

/* Function 23: func_001294E8 */
void func_001294E8(int flag) {
    while (func_12D990() != 0) {
        if (flag != 0) {
            break;
        }
        func_12D988();
        func_103358(0);
    }
}

/* Function 24: func_00129538 */
void func_00129538(int val) {
    *(volatile int *)0x4ED358 = val;
}

/* Function 25: func_00129548 */
int func_00129548(void) {
    int val = D_4ED300[0x16];
    D_4ED300[0x16] = 0;
    return val;
}

/* Function 26: func_00129560 */
int func_00129560(int (*func)(void *), void *arg) {
    if (func != NULL) {
        return func(arg);
    }
    return 0;
}

/* 0x00129588 : ktHdTableLookup */
int func_00129588(int *table, int count, int key) {
    int i;
    if (count <= 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        if (table[i * 2] == key) {
            return table[i * 2 + 1];
        }
    }
    return 0;
}
