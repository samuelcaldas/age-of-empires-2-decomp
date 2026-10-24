#include "common.h"
#include "kt_kernel.h"

extern int D_38CEC0[];
extern int D_38CED0[];
extern int D_4EA7C0;

extern const char D_4905C0[];
extern const char D_4905E0[];
extern const char D_490600[];
extern const char D_490610[];
extern const char D_490620[];
extern const char D_490648[];
extern const char D_490678[];
extern const char D_490698[];
extern const char D_4906B8[];
extern const char D_4906D0[];
extern const KtThreadStatusEntry D_490740[];
extern const char D_490770[];
extern const char D_4907E8[];
extern const char D_4E2D68[];
extern const char D_4E2D70[];

/* Kernel syscall wrappers and external runtime functions */
int func_104C10(void);
int func_104C20(int thid, KtThreadParam *param);
int func_104BB0(int thid, int prio);
int func_104B70(int thid);
int func_104B30(int thid);
int func_104B20(KtThreadParam *param);
int func_104B40(int thid, void *arg);
int func_104D20(KtSemaParam *param);
int func_104D30(int sem_id);
int func_104D40(int sem_id);
int func_104D50(int sem_id);
int func_104D60(int sem_id);
int func_104D70(int sem_id);
int func_104D80(int sem_id);
int func_104D90(int sem_id, KtSemaParam *param);
int func_104DA0(int sem_id, KtSemaParam *param);
int func_104A00(int intc, int (*handler)(void), int flag);
int func_104A50(int intc);
void func_1057B0(int a0);
int func_105818(int a0);
int func_105880(int a0);
int func_00134DE8(int a0, int a1);
void func_114320(const char *file, int line, const char *expr);
void func_001143C0(void *ptr, int size);
void func_118de0(const char *fmt, ...);
void func_106E20(const char *fmt, ...);

static int s_vblank_s_initialized = 0;
static int s_vblank_e_initialized = 0;

/* func_00134140: Get current thread priority */
int func_00134140(void) {
    return func_00134168(func_104C10());
}

/* func_00134168: Get specific thread priority */
int func_00134168(int thid) {
    KtThreadParam status;
    func_104C20(thid, &status);
    return status.current_priority;
}

/* func_00134188: Change current thread priority */
int func_00134188(int priority) {
    return func_104BB0(func_104C10(), priority);
}

/* func_001341B8: Terminate and delete thread */
int func_001341B8(int thid) {
    if (func_104B70(thid) != thid) {
        func_118de0(D_4905C0, thid);
    }
    if (func_104B30(thid) != thid) {
        func_118de0(D_4905E0, thid);
    }
    return thid;
}

/* func_00134210: Create semaphore */
int func_00134210(int init_count, int max_count, int option) {
    KtSemaParam sema;
    int id;

    func_001143C0(&sema, sizeof(sema));
    sema.max_count = max_count;
    sema.init_count = init_count;
    sema.option = option;

    id = func_104D20(&sema);
    if (id < 0) {
        func_114320(D_490600, 0x74, D_4E2D68);
    }
    return id;
}

/* func_00134290: Create thread */
int func_00134290(void *entry, void *stack, int stack_size, int priority, int option) {
    KtThreadParam th;
    int id;

    func_001143C0(&th, sizeof(th));
    th.entry = entry;
    th.stack = stack;
    th.stack_size = stack_size;
    th.init_priority = priority;
    th.gp_reg = &D_4EA7C0;
    th.option = option;

    id = func_104B20(&th);
    if (id < 0) {
        func_114320(D_490600, 0x93, D_4E2D68);
    }
    return id;
}

/* func_00134330: Start thread */
int func_00134330(int thid, void *arg) {
    int check_id = func_104B40(thid, arg);
    if (check_id != thid) {
        func_114320(D_490600, 0xA8, D_490610);
    }
    return thid;
}

/* func_00134378: Create and start thread */
int func_00134378(void *entry, void *stack, int stack_size, int priority, void *arg, int option) {
    int id = func_00134290(entry, stack, stack_size, priority, option);
    func_00134330(id, arg);
    return id;
}

/* func_001343A8: Drain semaphore and print cancel count */
int func_001343A8(int sem_id) {
    int count = func_001343F8(sem_id);
    if (count > 0) {
        func_118de0(D_490620, sem_id, count);
    }
    return count;
}

/* func_001343F8: Drain semaphore count via polling */
int func_001343F8(int sem_id) {
    int count = 0;
    while (func_104D70(sem_id) > 0) {
        count++;
    }
    return count;
}

/* func_00134440: Signal semaphore */
int func_00134440(int sem_id) {
    int res = func_104D40(sem_id);
    if (res != sem_id) {
        func_118de0(D_490648, sem_id);
    }
    return res;
}

/* func_00134480: Signal semaphore (interrupt context) */
int func_00134480(int sem_id) {
    int res = func_104D50(sem_id);
    if (res != sem_id) {
        func_106E20(D_490678, sem_id);
    }
    return res;
}

/* func_001344C0: Delete semaphore */
int func_001344C0(int sem_id) {
    int res = func_104D30(sem_id);
    if (res != sem_id) {
        func_106E20(D_490698, sem_id);
    }
    return res;
}

/* func_00134500: Wait semaphore */
int func_00134500(int sem_id) {
    return func_104D60(sem_id);
}

/* func_00134528: Get SyncV sema 0 */
int func_00134528(void) {
    return D_38CEC0[0];
}

/* func_00134538: Get SyncV sema 1 */
int func_00134538(void) {
    return D_38CEC0[1];
}

/* func_00134548: Get SyncV sema 2 */
int func_00134548(void) {
    return D_38CEC0[2];
}

/* func_00134558: Get SyncV sema 3 */
int func_00134558(void) {
    return D_38CEC0[3];
}

/* func_00134568: VBLANK_S interrupt callback */
int func_00134568(void) {
    int sem0 = func_00134528();
    int sem1 = func_00134538();
    if (sem0 >= 0) {
        while (func_104D80(sem0) == sem0) {
            func_104D50(sem1);
        }
    }
#if defined(__mips__)
    __asm__ volatile("sync\n\tei");
#endif
    return 0;
}

/* func_001345D0: VBLANK_E interrupt callback */
int func_001345D0(void) {
    int sem2 = func_00134548();
    int sem3 = func_00134558();
    if (sem2 >= 0) {
        while (func_104D80(sem2) == sem2) {
            func_104D50(sem3);
        }
    }
#if defined(__mips__)
    __asm__ volatile("sync\n\tei");
#endif
    return 0;
}

/* func_00134638: Remove V-Sync interrupt handlers */
void func_00134638(void) {
    int i;
    for (i = 0; i < 2; i++) {
        int handler_id = D_38CED0[i * 2 + 1];
        int intr = D_38CED0[i * 2];
        if (handler_id >= 0) {
            func_00134DE8(intr, handler_id);
            D_38CED0[i * 2] = -1;
            D_38CED0[i * 2 + 1] = -1;
        }
    }
}

/* func_001346A8: Delete all SyncV semaphores */
void func_001346A8(void) {
    int i;
    for (i = 0; i < 4; i++) {
        int sem = D_38CEC0[i];
        if (sem >= 0) {
            func_104D30(sem);
            D_38CEC0[i] = -1;
        }
    }
}

/* func_00134710: Initialize range of SyncV semaphores */
int func_00134710(int start_idx, int end_idx) {
    int i;
    int id = -1;
    for (i = start_idx; i < end_idx; i++) {
        id = func_00134210(0, 0, 0);
        if (id >= 0) {
            D_38CEC0[i] = id;
        } else {
            break;
        }
    }
    if (id < 0) {
        func_001346A8();
    }
    return id;
}

/* func_001347A8: Register VBLANK_S INTC handler */
int func_001347A8(void) {
    int res = 0;
    if (s_vblank_s_initialized == 0) {
        s_vblank_s_initialized = 1;
        res = func_00134710(0, 2);
        if (res >= 0) {
            res = func_104A00(2, func_00134568, -1);
            D_38CED0[0] = 2;
            D_38CED0[1] = res;
            func_1057B0(2);
        }
    }
    return res;
}

/* func_00134828: Register VBLANK_E INTC handler */
int func_00134828(void) {
    int res = 0;
    if (s_vblank_e_initialized == 0) {
        s_vblank_e_initialized = 1;
        res = func_00134710(2, 4);
        if (res >= 0) {
            res = func_104A00(3, func_001345D0, -1);
            D_38CED0[2] = 3;
            D_38CED0[3] = res;
            func_1057B0(3);
        }
    }
    return res;
}

/* func_001348A8: Initialize V-Sync subsystem */
int func_001348A8(int mode) {
    int res;
    if (mode == 1) {
        res = func_001347A8();
    } else if (mode == 2) {
        res = func_00134828();
    } else {
        res = func_001347A8();
        if (res >= 0) {
            res = func_00134828();
        }
    }
    return res;
}

/* func_00134928: Shutdown V-Sync subsystem */
void func_00134928(void) {
    func_00134638();
    func_001346A8();
    s_vblank_s_initialized = 0;
    s_vblank_e_initialized = 0;
}

/* func_00134970: Wait for V-Sync signal/wait pair */
int func_00134970(int sem0, int sem1) {
    if (sem0 < 0 || sem1 < 0) {
        func_118de0(D_4906B8);
        return 0;
    }
    if (func_104D40(sem0) == sem0) {
        return func_104D60(sem1);
    }
    return 0;
}

/* func_001349E8: Wait for VBLANK_S */
int func_001349E8(void) {
    return func_00134970(func_00134528(), func_00134538());
}

/* func_00134A20: Wait for VBLANK_E */
int func_00134A20(void) {
    return func_00134970(func_00134548(), func_00134558());
}

/* func_00134A58: Get thread status */
int func_00134A58(int thid) {
    KtThreadParam param;
    func_104C20(thid, &param);
    return param.status;
}

/* func_00134A78: Dump thread details */
void func_00134A78(int thid) {
    KtThreadParam param;
    const char *status_str;

    func_104C20(thid, &param);
    status_str = func_00134AF0(param.status);
    if (status_str == 0) {
        status_str = D_4E2D70;
    }
    func_118de0(D_4906D0, thid, status_str, param.entry, param.stack, param.stack_size, param.gp_reg, param.init_priority, param.current_priority,
                param.attr);
}

/* func_00134AF0: Convert thread status ID to string */
const char *func_00134AF0(int status) {
    KtThreadStatusEntry table[6];
    int i;

    /* Copy static entry table into local stack as original did */
    const KtThreadStatusEntry *src = D_490740;
    for (i = 0; i < 6; i++) {
        table[i] = src[i];
    }

    if (status == table[0].status_id) {
        return table[0].status_str;
    }
    for (i = 1; i < 6; i++) {
        if (status == table[i].status_id) {
            return table[i].status_str;
        }
    }
    return 0;
}

/* func_00134BB0: Dump all active threads */
void func_00134BB0(void) {
    int thid;
    for (thid = 1; thid < 0x41; thid++) {
        KtThreadParam param;
        const char *status_str;
        func_104C20(thid, &param);
        status_str = func_00134AF0(param.status);
        if (status_str != 0) {
            func_118de0(D_490770, thid, status_str, param.entry, param.stack, param.stack_size, param.gp_reg, param.init_priority,
                        param.current_priority, param.attr, param.option, param.wait_type, param.wait_id, param.wakeup_count);
        }
    }
}

/* func_00134C60: Dump semaphore status (interrupt context) */
void func_00134C60(int sem_id) {
    KtSemaParam param;
    if (func_104DA0(sem_id, &param) == sem_id) {
        func_106E20(D_4907E8, sem_id, param.current_count, param.init_count, param.max_count, param.wait_threads, param.option);
    }
}

/* func_00134CB8: Dump all semaphores (interrupt context) */
void func_00134CB8(void) {
    int i;
    for (i = 1; i < 0x81; i++) {
        func_00134C60(i);
    }
}

/* func_00134CF0: Dump semaphore status (thread context) */
void func_00134CF0(int sem_id) {
    KtSemaParam param;
    if (func_104D90(sem_id, &param) == sem_id) {
        func_118de0(D_4907E8, sem_id, param.current_count, param.init_count, param.max_count, param.wait_threads, param.option);
    }
}

/* func_00134D48: Dump all semaphores (thread context) */
void func_00134D48(void) {
    int i;
    for (i = 1; i < 0x81; i++) {
        func_00134CF0(i);
    }
}

/* func_00134D80: Enable INTC cause with interrupt lock */
int func_00134D80(int intc_cause, int flag) {
    int lock = func_105818(flag);
    int res = func_104A50(intc_cause);
    if (res != 0 && lock != 0) {
        func_105880(intc_cause);
    }
    return res;
}
