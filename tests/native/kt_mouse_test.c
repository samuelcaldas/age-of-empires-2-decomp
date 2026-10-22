#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Global variables defined in BSS/rodata for kt_mouse */
char D_509F00[0x160];
typedef struct {
    int handle;
    int count;
    char *buffer;
    int flag;
} MouseWork;

MouseWork D_50A060;
int D_50A06C = 0;
char D_50A080[0x18];
char D_50A08C[0x40];
char D_50A0C0[0x40];
char D_50A140[0x40];
signed char D_50A1C0[0x40];
typedef struct {
    char pad[0x24];
    unsigned int status;
} MouseDevice_DA0;
MouseDevice_DA0 D_50A240;
int D_50A280[0x20];

const char D_490820[] = "kt_mouse.c";
const char D_490830[] = "n_mouse <= KT_MOUSE_MAX_NUM";
const char D_490850[] = "mouse_number < W->n_mouse";
const char D_490870[] = "number < W->n_mouse";

/* Test harness doubles for kt_mouse functions */
int func_00134DE8(int a0, int a1);
void func_00134E50(int n_mouse);
void func_00134F18(void);
void func_00134F20(void);
void func_00134F50(void);
void func_00134F90(void);
void func_00134FB8(void);
int func_00134FE0(int a0, int a1);
void func_00135008(int a0);
int *func_00135058(int a0);
void func_00135090(int a0);
int *func_001350E0(int a0);
int func_00135118(int a0, int *out);
short func_001351B0(short *ptr);
short func_001351B8(int a0);
int func_00135238(short *ptr);
int func_00135258(int a0);
int func_001352D8(int a0, int *out);
int func_001353C0(int a0);
void func_00135478(void);
void func_001354A0(void);
int func_00135870(int a0, int a1, int a2, int a3, int a4);

/* Test mock states */
static int mock_status_flag = 0;
static int mock_handler_result = 0;
static int mock_notified = 0;

int func_105748(int a0) {
    return mock_status_flag;
}

int func_104A20(int a0, int a1) {
    return mock_handler_result;
}

void func_1057B0(int a0) {
    mock_notified++;
}

void func_114320(const char *file, int line, const char *msg) {
    /* Assert mock */
}

void func_1143C0(void *ptr, int size) {
    memset(ptr, 0, size);
}

int func_134210(int a, int b, int c) {
    return 42; /* simulated sema handle */
}

void func_1344C0(int h) {}
void func_134500(int h) {}
void func_134440(int h) {}
void func_1348A8(int h) {}
void func_117AF8(void *dst, const void *src, int n) {
    memcpy(dst, src, n);
}
void func_134A20(void) {}
void func_1075C8(int x) {}
void func_107C38(void *a, unsigned int b, int c) {}
int func_107E08(void *a, int b, int c, int *d, int e, void *f, int g, int h, int i) {
    return 0;
}

static void test_mouse_dispatch_wrapper(void) {
    mock_status_flag = 0;
    mock_handler_result = 1;
    mock_notified = 0;
    assert(func_00134DE8(1, 2) == 1);
    assert(mock_notified == 0);

    mock_status_flag = 1;
    mock_handler_result = 1;
    mock_notified = 0;
    assert(func_00134DE8(1, 2) == 1);
    assert(mock_notified == 1);

    mock_status_flag = 1;
    mock_handler_result = 0;
    mock_notified = 0;
    assert(func_00134DE8(1, 2) == 0);
    assert(mock_notified == 0);
}

static void test_mouse_init_work(void) {
    func_00134E50(2);
    /* verify handle init */
    func_00134F20();
    func_00134F90();
    func_00134FB8();
    func_00134F50();
}

static void test_mouse_buffer_math(void) {
    func_00134E50(2);
    /* buffer index 0 modulo advance */
    assert(func_00134FE0(0, 0) == 1);
    assert(func_00134FE0(0, 3) == 0);

    /* Post event into queue */
    int res = func_00135870(0, 10, 20, 30, 40);
    /* Dequeue */
    int out[4] = {0};
    int ok = func_00135118(0, out);
}

int main(int argc, char **argv) {
    test_mouse_dispatch_wrapper();
    test_mouse_init_work();
    test_mouse_buffer_math();
    printf("All native kt_mouse tests passed successfully.\n");
    return 0;
}
