#ifndef KT_KERNEL_H
#define KT_KERNEL_H

#include "common.h"

/* Sony EE Kernel Types */
typedef struct {
    int status;             /* 0x00 */
    void *entry;            /* 0x04 */
    void *stack;            /* 0x08 */
    int stack_size;         /* 0x0C */
    void *gp_reg;           /* 0x10 */
    int init_priority;      /* 0x14 */
    int current_priority;   /* 0x18 */
    unsigned int attr;      /* 0x1C */
    unsigned int option;    /* 0x20 */
    unsigned int wait_type; /* 0x24 */
    int wait_id;            /* 0x28 */
    int wakeup_count;       /* 0x2C */
} KtThreadParam;

typedef struct {
    int current_count;   /* 0x00 */
    int max_count;       /* 0x04 */
    int init_count;      /* 0x08 */
    int wait_threads;    /* 0x0C */
    unsigned int attr;   /* 0x10 */
    unsigned int option; /* 0x14 */
} KtSemaParam;

typedef struct {
    int status_id;
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

#endif /* KT_KERNEL_H */
