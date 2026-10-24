#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_gpu.h"

const char D_48F1B8[] = "kt_gpu.c";
const char D_48F1C8[] = "kind < 29";

#if defined(__mips__)
typedef unsigned int u128 __attribute__((mode(TI)));
#else
typedef struct { u64 lo, hi; } u128;
#endif
typedef void (*FuncPtr)(void *, void *);

const u128 D_38C730 = {0, 0};

static int s_dispatched_kind = -1;
static void mock_handler(void *p, void *cmd) {
    s_dispatched_kind = *(u8 *)cmd;
}

FuncPtr D_38C740[29] = {
    mock_handler, mock_handler, mock_handler, mock_handler, mock_handler
};

void func_1045E8(void *p, u128 q) {}
int func_123A70(void *p) { return 0; }
void func_1046A8(void *p, int reg, u64 val) {}
void func_114320(const char *file, int line, const char *expr) {}
void func_104448(void *p, int a, int b, int c) {}
void func_104600(void *p) {}
void func_134500(int a) {}
void func_134440(int a) {}
void func_10D8B0(int a, int b, void *c) {}
int func_10D0F8(int a, int b) { return 0; }
int func_10CE90(void) { return 1; }
void func_116F68(int a) {}
void func_1344C0(int a) {}

static void test_gpu_dispatcher(void) {
    u8 cmd[4] = {3, 0, 0, 0};
    func_001259C8(NULL, cmd, 1);
    assert(s_dispatched_kind == 3);
}

int main(void) {
    test_gpu_dispatcher();
    printf("All native kt_gpu tests passed successfully.\n");
    return 0;
}
