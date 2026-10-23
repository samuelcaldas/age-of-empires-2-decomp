#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_kernel.h"

/* Global arrays defined in BSS/rodata for kt_kernel */
int D_38CEC0[4] = {-1, -1, -1, -1};
int D_38CED0[4] = {-1, -1, -1, -1};
int D_4EA7C0 = 0;

/* String constants referenced by kt_kernel */
const char D_4905C0[] = "ThreadID=%d, already DORMANT.\n";
const char D_4905E0[] = "ThreadID=%d, can't delete\n";
const char D_490600[] = "kt_kernel.c";
const char D_490610[] = "check_id == id";
const char D_490620[] = "SemaphoreID=%d CancelCount = %d\n";
const char D_490648[] = "SignalSema( %d ) failed\n";
const char D_490678[] = "iSignalSema( %d ) failed\n";
const char D_490698[] = "DeleteSeme( %d ) failed\n";
const char D_4906B8[] = "ktWaitSyncV: failed\n";
const char D_4906D0[] = "Thread   : id=%d status=%s entry=%xH stack=%xH size=%xH gpReg=%xH init=%d current=%d attr=%d\n";
const KtThreadStatusEntry D_490740[6] = {{1, "RUN"}, {2, "READY"}, {3, "WAIT"}, {4, "SUSPEND"}, {5, "DORMANT"}, {0, NULL}};
const char D_490770[] = "ThreadID %d:%s entry=%xH stack=%xH size=%xH gpReg=%xH init=%d current=%d attr=%d option=%d WType=%d WId=%d WupCount=%d\n";
const char D_4907E8[] = "SemaId %d: cur=%d ini=%d max=%d wait=%d option=%d\n";
const char D_4E2D68[] = "id >= 0";
const char D_4E2D70[] = "(null)";

/* Mock state */
static int mock_current_thid = 1;
static int mock_thread_priority = 32;
static int mock_sema_counter = 10;
static int mock_poll_drain_count = 3;
static int mock_intc_enabled = 0;
static int mock_assert_tripped = 0;
static int mock_intc_handlers_installed = 0;

/* Mock implementations of Sony EE kernel functions */
int func_104C10(void) {
    return mock_current_thid;
}

int func_104C20(int thid, KtThreadParam *param) {
    memset(param, 0, sizeof(*param));
    param->status = 1; /* RUN */
    param->init_priority = 32;
    param->current_priority = mock_thread_priority;
    return thid;
}

int func_104BB0(int thid, int prio) {
    (void)thid;
    int old = mock_thread_priority;
    mock_thread_priority = prio;
    return old;
}

int func_104B70(int thid) {
    return thid; /* TerminateThread success */
}

int func_104B30(int thid) {
    return thid; /* DeleteThread success */
}

int func_104B20(KtThreadParam *param) {
    (void)param;
    return ++mock_current_thid;
}

int func_104B40(int thid, void *arg) {
    (void)arg;
    return thid;
}

int func_104D20(KtSemaParam *param) {
    (void)param;
    return ++mock_sema_counter;
}

int func_104D30(int sem_id) {
    return sem_id;
}

int func_104D40(int sem_id) {
    return sem_id;
}

int func_104D50(int sem_id) {
    return sem_id;
}

int func_104D60(int sem_id) {
    return sem_id;
}

int func_104D70(int sem_id) {
    (void)sem_id;
    if (mock_poll_drain_count > 0) {
        mock_poll_drain_count--;
        return 1;
    }
    return 0;
}

int func_104D80(int sem_id) {
    (void)sem_id;
    return -1;
}

int func_104D90(int sem_id, KtSemaParam *param) {
    memset(param, 0, sizeof(*param));
    param->current_count = 1;
    param->max_count = 1;
    return sem_id;
}

int func_104DA0(int sem_id, KtSemaParam *param) {
    memset(param, 0, sizeof(*param));
    param->current_count = 1;
    param->max_count = 1;
    return sem_id;
}

int func_104A00(int intc, int (*handler)(void), int flag) {
    (void)intc;
    (void)handler;
    (void)flag;
    mock_intc_handlers_installed++;
    return mock_intc_handlers_installed;
}

int func_104A50(int intc) {
    (void)intc;
    mock_intc_enabled = 1;
    return 0;
}

void func_1057B0(int a0) {
    (void)a0;
}

int func_105818(int a0) {
    (void)a0;
    return 1;
}

int func_105880(int a0) {
    (void)a0;
    return 0;
}

int func_00134DE8(int a0, int a1) {
    (void)a0;
    (void)a1;
    return 0;
}

void func_114320(const char *file, int line, const char *expr) {
    (void)file;
    (void)line;
    (void)expr;
    mock_assert_tripped++;
}

void func_001143C0(void *ptr, int size) {
    memset(ptr, 0, size);
}

void func_118de0(const char *fmt, ...) {
    (void)fmt;
}

void func_106E20(const char *fmt, ...) {
    (void)fmt;
}

/* Test Cases */
static void test_thread_priority(void) {
    mock_thread_priority = 40;
    int p = func_00134140();
    assert(p == 40);

    func_00134188(20);
    assert(mock_thread_priority == 20);
    assert(func_00134140() == 20);
}

static void test_semaphore_lifecycle(void) {
    int sem = func_00134210(0, 1, 0);
    assert(sem > 0);

    mock_poll_drain_count = 5;
    int drained = func_001343F8(sem);
    assert(drained == 5);

    int cleared = func_001343A8(sem);
    assert(cleared == 0);

    assert(func_00134440(sem) == sem);
    assert(func_00134480(sem) == sem);
    assert(func_00134500(sem) == sem);
    assert(func_001344C0(sem) == sem);
}

static void test_sync_v_getters_and_wait(void) {
    D_38CEC0[0] = 101;
    D_38CEC0[1] = 102;
    D_38CEC0[2] = 103;
    D_38CEC0[3] = 104;

    assert(func_00134528() == 101);
    assert(func_00134538() == 102);
    assert(func_00134548() == 103);
    assert(func_00134558() == 104);

    /* Test wait sync V */
    assert(func_00134970(101, 102) == 102);
    assert(func_001349E8() == 102);
    assert(func_00134A20() == 104);
}

static void test_thread_status_strings(void) {
    const char *s1 = func_00134AF0(1);
    assert(s1 != NULL && strcmp(s1, "RUN") == 0);

    const char *s2 = func_00134AF0(2);
    assert(s2 != NULL && strcmp(s2, "READY") == 0);

    const char *s5 = func_00134AF0(5);
    assert(s5 != NULL && strcmp(s5, "DORMANT") == 0);
}

int main(void) {
    test_thread_priority();
    test_semaphore_lifecycle();
    test_sync_v_getters_and_wait();
    test_thread_status_strings();
    printf("All native kt_kernel tests passed successfully.\n");
    return 0;
}
