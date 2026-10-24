#ifndef KT_KERNEL_H
#define KT_KERNEL_H

#include "common.h"

/* Thread status enum */
typedef enum KtThreadStatus {
    KT_THREAD_STATUS_RUN     = 1,
    KT_THREAD_STATUS_READY   = 2,
    KT_THREAD_STATUS_WAIT    = 3,
    KT_THREAD_STATUS_SUSPEND = 4,
    KT_THREAD_STATUS_DORMANT = 5
} KtThreadStatus;

/* V-Sync init modes */
typedef enum KtVSyncMode {
    KT_VSYNC_MODE_VBLANK_S = 1,
    KT_VSYNC_MODE_VBLANK_E = 2,
    KT_VSYNC_MODE_BOTH     = 3
} KtVSyncMode;

/* INTC interrupt causes */
typedef enum KtIntcCause {
    KT_INTC_VBLANK_S = 2,
    KT_INTC_VBLANK_E = 3
} KtIntcCause;

/* Subsystem limits */
#define KT_MAX_THREADS       64
#define KT_MAX_SEMAPHORES    128
#define KT_SYNCV_SEMA_COUNT  4

/* Sony EE Kernel Types */
typedef struct {
    s32 status;             /* 0x00 */
    GuestAddr entry;        /* 0x04 */
    GuestAddr stack;        /* 0x08 */
    s32 stack_size;         /* 0x0C */
    GuestAddr gp_reg;       /* 0x10 */
    s32 init_priority;      /* 0x14 */
    s32 current_priority;   /* 0x18 */
    u32 attr;               /* 0x1C */
    u32 option;             /* 0x20 */
    u32 wait_type;          /* 0x24 */
    s32 wait_id;            /* 0x28 */
    s32 wakeup_count;       /* 0x2C */
} KtThreadParam;
_Static_assert(sizeof(KtThreadParam) == 48, "KtThreadParam size");
_Static_assert(offsetof(KtThreadParam, status) == 0, "KtThreadParam status offset");
_Static_assert(offsetof(KtThreadParam, entry) == 4, "KtThreadParam entry offset");
_Static_assert(offsetof(KtThreadParam, stack) == 8, "KtThreadParam stack offset");
_Static_assert(offsetof(KtThreadParam, stack_size) == 12, "KtThreadParam stack_size offset");
_Static_assert(offsetof(KtThreadParam, gp_reg) == 16, "KtThreadParam gp_reg offset");
_Static_assert(offsetof(KtThreadParam, init_priority) == 20, "KtThreadParam init_priority offset");
_Static_assert(offsetof(KtThreadParam, current_priority) == 24, "KtThreadParam current_priority offset");
_Static_assert(offsetof(KtThreadParam, attr) == 28, "KtThreadParam attr offset");
_Static_assert(offsetof(KtThreadParam, option) == 32, "KtThreadParam option offset");
_Static_assert(offsetof(KtThreadParam, wait_type) == 36, "KtThreadParam wait_type offset");
_Static_assert(offsetof(KtThreadParam, wait_id) == 40, "KtThreadParam wait_id offset");
_Static_assert(offsetof(KtThreadParam, wakeup_count) == 44, "KtThreadParam wakeup_count offset");

typedef struct {
    s32 current_count;   /* 0x00 */
    s32 max_count;       /* 0x04 */
    s32 init_count;      /* 0x08 */
    s32 wait_threads;    /* 0x0C */
    u32 attr;            /* 0x10 */
    u32 option;          /* 0x14 */
} KtSemaParam;
_Static_assert(sizeof(KtSemaParam) == 24, "KtSemaParam size");
_Static_assert(offsetof(KtSemaParam, current_count) == 0, "KtSemaParam current_count offset");
_Static_assert(offsetof(KtSemaParam, max_count) == 4, "KtSemaParam max_count offset");
_Static_assert(offsetof(KtSemaParam, init_count) == 8, "KtSemaParam init_count offset");
_Static_assert(offsetof(KtSemaParam, wait_threads) == 12, "KtSemaParam wait_threads offset");
_Static_assert(offsetof(KtSemaParam, attr) == 16, "KtSemaParam attr offset");
_Static_assert(offsetof(KtSemaParam, option) == 20, "KtSemaParam option offset");

typedef struct {
    s32 status_id;
    const char *status_str;
} KtThreadStatusEntry;

/* Forward declarations for kt_kernel functions */
int func_00134140(void);
int func_00134168(int thid);
int func_00134188(int priority);
int func_001341B8(int thid);
int func_00134210(int init_count, int max_count, int option);
int func_00134290(void *entry, void *stack, int stack_size, int priority, int option);
int func_00134330(int thid, void *arg);
int func_00134378(void *entry, void *stack, int stack_size, int priority, void *arg, int option);
int func_001343A8(int sem_id);
int func_001343F8(int sem_id);
int func_00134440(int sem_id);
int func_00134480(int sem_id);
int func_001344C0(int sem_id);
int func_00134500(int sem_id);
int func_00134528(void);
int func_00134538(void);
int func_00134548(void);
int func_00134558(void);
int func_00134568(void);
int func_001345D0(void);
void func_00134638(void);
void func_001346A8(void);
int func_00134710(int start_idx, int end_idx);
int func_001347A8(void);
int func_00134828(void);
int func_001348A8(int mode);
void func_00134928(void);
int func_00134970(int sem0, int sem1);
int func_001349E8(void);
int func_00134A20(void);
int func_00134A58(int thid);
void func_00134A78(int thid);
const char *func_00134AF0(int status);
void func_00134BB0(void);
void func_00134C60(int sem_id);
void func_00134CB8(void);
void func_00134CF0(int sem_id);
void func_00134D48(void);
int func_00134D80(int intc_cause, int flag);

/* Aliases / Macros for known function names */
#define ktKernelGetThreadPriority       func_00134140
#define ktKernelGetThreadPriorityById   func_00134168
#define ktKernelChangeThreadPriority    func_00134188
#define ktKernelTerminateThread         func_001341B8
#define ktKernelCreateSema              func_00134210
#define ktKernelCreateThread            func_00134290
#define ktKernelStartThread             func_00134330
#define ktKernelCreateAndStartThread    func_00134378
#define ktKernelDrainSema               func_001343A8
#define ktKernelPollSema                func_001343F8
#define ktKernelSignalSema              func_00134440
#define ktKernelSignalSemaInterrupt     func_00134480
#define ktKernelDeleteSemaDirect        func_001344C0
#define ktKernelWaitSema                func_00134500
#define ktKernelGetThreadStatusString   func_00134AF0

#endif /* KT_KERNEL_H */
