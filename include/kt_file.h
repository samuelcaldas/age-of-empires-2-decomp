/* KCET File I/O Subsystem (kt_file.h) */
#ifndef KT_FILE_H
#define KT_FILE_H

#include "common.h"

/* 8-byte sorted record in record table */
typedef struct FileRecord {
    u16 id;
    u16 aux;
    GuestAddr payload;
} FileRecord;
_Static_assert(sizeof(FileRecord) == 8, "FileRecord size");
_Static_assert(offsetof(FileRecord, id) == 0, "FileRecord id offset");
_Static_assert(offsetof(FileRecord, aux) == 2, "FileRecord aux offset");
_Static_assert(offsetof(FileRecord, payload) == 4, "FileRecord payload offset");

/* CD/File subsystem global state (D_4F1508) */
typedef struct CdServerState {
    GuestAddr record_table;  /* 0x00: pointer/address of sorted FileRecord array */
    s32 record_count;        /* 0x04: number of records */
    s32 min_val;             /* 0x08: minimum value in table */
    GuestAddr entry_table;   /* 0x0C: pointer/address of named entry table */
    s32 entry_count;         /* 0x10: number of named entries */
} CdServerState;
_Static_assert(sizeof(CdServerState) == 20, "CdServerState size");
_Static_assert(offsetof(CdServerState, record_table) == 0, "CdServerState record_table offset");
_Static_assert(offsetof(CdServerState, record_count) == 4, "CdServerState record_count offset");
_Static_assert(offsetof(CdServerState, min_val) == 8, "CdServerState min_val offset");
_Static_assert(offsetof(CdServerState, entry_table) == 12, "CdServerState entry_table offset");
_Static_assert(offsetof(CdServerState, entry_count) == 16, "CdServerState entry_count offset");

/* CD Stream status structure (D_4F16C0) */
typedef struct CdStreamStatus {
    s32 field0;              /* 0x00 */
    s32 active;              /* 0x04: active stream indicator */
    s32 bytes_remaining;     /* 0x08: remaining bytes (>> 11 = sector count) */
} CdStreamStatus;
_Static_assert(sizeof(CdStreamStatus) == 12, "CdStreamStatus size");
_Static_assert(offsetof(CdStreamStatus, field0) == 0, "CdStreamStatus field0 offset");
_Static_assert(offsetof(CdStreamStatus, active) == 4, "CdStreamStatus active offset");
_Static_assert(offsetof(CdStreamStatus, bytes_remaining) == 8, "CdStreamStatus bytes_remaining offset");

/* Kinds / Dispatch categories */
typedef enum KtFileKind {
    KT_FILE_KIND_0 = 0,
    KT_FILE_KIND_1 = 1,
    KT_FILE_KIND_2 = 2,
    KT_FILE_KIND_3 = 3,
    KT_FILE_KIND_MAX = 4
} KtFileKind;

/* Status codes */
typedef enum KtFileStatus {
    KT_FILE_OK = 0,
    KT_FILE_ERR = -1
} KtFileStatus;

/* Global state variables */
extern CdServerState D_4F1508;
extern char D_4F1540[];
extern char D_4F1640[];
extern char D_4F1680[];
extern CdStreamStatus D_4F16C0;

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
int func_0012D128(int key, void *table, int count);
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

#endif /* KT_FILE_H */
