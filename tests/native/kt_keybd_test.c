#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "kt_keybd.h"

/* Global BSS and rodata symbols for kt_keybd */
KeybdWork D_50A338;
char D_50A2C0[0x100];
char D_50A380[0x18];
char D_50A38C[0x30];
char D_50A3C0[0x80];
char D_50A440[0x80];
char D_50A4C0[0x80];

const char D_490888[] = "n_keybd <= KT_KEYBD_MAX_NUM";
const char D_4908A8[] = "kt_keybd.c";
const char D_4908B8[] = "ktKeybdInit";
const char D_4908C8[] = "keybd_number < W->n_keybd";
const char D_4908E8[] = "ktKeybdGetState";
const char D_490900[] = "ktKeybdGetType";
const char D_490910[] = "ktKeybdGetInfo";
const char D_490928[] = "ktKeybdSetRepeat";
const char D_490938[] = "ktKeybdSetLed";
const char D_490950[] = "number < W->n_keybd";
const char D_490968[] = "ktKeybdFreePort";
const char D_490980[] = "ktKeybdSetState";
const char D_490998[] = "ktKeybdSetLocation";
const char D_4909B0[] = "ktKeybdEnqueue";
const char D_4909D0[] = "size < KT_KEYBD_KEY_MAX";
const char D_4909F0[] = "ktKeybdGetRepeatReq";
const char D_490A08[] = "ktKeybdClearRepeatReq";
const char D_490A20[] = "ktKeybdGetLedReq";
const char D_490A40[] = "ktKeybdClearLedReq";

static int assert_triggered = 0;

void func_123790(const char *cond, const char *file, int line, const char *func) {
    assert_triggered++;
}

void func_1143C0(void *ptr, int size) {
    memset(ptr, 0, size);
}

void func_117AF8(void *dst, const void *src, int n) {
    memcpy(dst, src, n);
}

void func_117CAC(void *dst, int val, int n) {
    memset(dst, val, n);
}

int func_134210(int a, int b, int c) {
    return 77;
}

void func_1344C0(int h) {}
void func_134500(int h) {}
void func_134440(int h) {}
void func_1348A8(int h) {}
void func_134A20(void) {}

int func_00137208(void) { return 0; }
int func_00137250(void *info) { return 0; }
int func_001372C0(int a0, void *data) { return -1; }
int func_00137340(int a0, void *location) { return 0; }
int func_001373C0(int a0, int a1) { return 0; }
int func_00137420(int a0, int a1) { return 0; }

static void test_keybd_init_and_alloc(void) {
    func_00135EC0(1);
    assert(D_50A338.count == 1);
    assert(D_50A338.handle == -1);
    assert(D_50A338.buffer == D_50A2C0);

    func_00135F98();
    assert(D_50A338.handle == 77);

    /* Allocate a port for device type 1 */
    int port_id = func_00136730(1);
    assert(port_id == 0);
    assert(func_001362D8(0) == 1);
    assert(func_00136230(0) == 0);

    /* Set state active */
    assert(func_00136850(0, 1) == 0);
    assert(func_00136230(0) == 1);
}

static void test_keybd_queue_and_requests(void) {
    func_00135EC0(1);
    int port_id = func_00136730(1);
    assert(port_id == 0);

    /* Enqueue key packet (modifiers=0x02, led=0x01, 2 keys: 0x04, 0x05) */
    unsigned char keys[2] = {0x04, 0x05};
    assert(func_001369E8(0, 0x02, 0x01, keys, 2) == 0);

    /* Dequeue key packet */
    KeybdData16 out;
    memset(&out, 0xFF, sizeof(out));
    assert(func_00136190(0, &out) == 1);
    assert((unsigned char)out.data[0] == 0x02);
    assert((unsigned char)out.data[1] == 0x01);
    assert((unsigned char)out.data[2] == 0x04);
    assert((unsigned char)out.data[3] == 0x05);
    assert((unsigned char)out.data[4] == 0x00); /* zero-padded by func_117CAC */

    /* Queue should now be empty */
    assert(func_00136190(0, &out) == 0);

    /* Repeat and LED requests set high bit 0x80000000 */
    func_00136508(0, 0x25);
    assert((unsigned int)func_00136B50(0) == 0x80000025U);
    func_00136BE0(0, 0x25);
    assert(func_00136B50(0) == 0x25);

    func_00136598(0, 0x03);
    assert((unsigned int)func_00136C90(0) == 0x80000003U);
    func_00136D20(0, 0x03);
    assert(func_00136C90(0) == 0x03);
}

int main(void) {
    test_keybd_init_and_alloc();
    test_keybd_queue_and_requests();
    printf("All native kt_keybd tests passed successfully.\n");
    return 0;
}
