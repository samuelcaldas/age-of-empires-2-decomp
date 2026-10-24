#ifndef KT_HD_H
#define KT_HD_H

#include "common.h"

/* Key-value pair for table lookup (8 bytes) */
typedef struct HdMapEntry {
    s32 key;
    s32 val;
} HdMapEntry;
_Static_assert(sizeof(HdMapEntry) == 8, "HdMapEntry size");
_Static_assert(offsetof(HdMapEntry, key) == 0, "HdMapEntry key offset");
_Static_assert(offsetof(HdMapEntry, val) == 4, "HdMapEntry val offset");

int func_00128BA8(int a0, int a1, int a2, int a3);
int func_00128CF0(int a0, int a1, int a2, int a3);
int func_00128D10(const char *name, void *buf, int size, int offset);
int func_00128D30(const char *name, void *buf, int size, int offset);
int func_00128D50(const char *name, void *buf, int size, int offset);
int func_00128D70(const char *name, void *buf, int size, int offset);
int func_00128D90(const char *name, void *buf, int size, int offset, int a4);
int func_00128DC0(const char *name, void *buf, int size, int offset, int a4);
int func_00128EC8(const char *name);
int func_00128F40(int flag);
int func_00128F68(void);
int func_00128F70(const char *name, int flag, int mode);
int func_00129108(const char *name, void *buf, int size, int flag);
int func_00129248(const char *name);
void func_00129348(void);
void func_00129388(void);
void func_001293A8(void);
void func_001293E0(void);
int func_00129428(int flag);
void func_001294A0(void);
int func_001294C0(void);
void func_001294E0(void);
void func_001294E8(int flag);
void func_00129538(int val);
int func_00129548(void);
int func_00129560(int (*func)(void *), void *arg);
int func_00129588(int *table, int count, int key);

#endif /* KT_HD_H */
