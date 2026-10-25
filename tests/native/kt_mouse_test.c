#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "kt_mouse.h"

/* Global variables defined in BSS/rodata for kt_mouse */
char D_509F00[0x160];
KT_MOUSE_WORK D_50A060;
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
void func_107C38(MouseDevice_DA0 *dev, unsigned int cmd, int flag) {}
int func_107E08(MouseDevice_DA0 *dev, int cmd, int opt, int *req, int req_sz, void *buf, int buf_sz, int a, int b) {
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
    assert(D_50A060.count == 2);
    assert(D_50A060.handle == -1);
    assert(D_50A060.buffer == D_509F00);

    KT_MOUSE_PORT *port0 = (KT_MOUSE_PORT *)D_509F00;
    KT_MOUSE_PORT *port1 = (KT_MOUSE_PORT *)(D_509F00 + 0xB0);
    assert(port0->port_id == 0);
    assert(port0->state == -1);
    assert(port0->queue_cap == 4);
    assert(port1->port_id == 1);
    assert(port1->state == -1);
    assert(port1->queue_cap == 4);

    func_00134F20();
    assert(D_50A060.handle == 42);
    func_00134F90();
    func_00134FB8();
    func_00134F50();
    assert(D_50A060.handle == -1);
}

static void test_mouse_ports_and_events(void) {
    func_00134E50(2);

    /* Allocate port for device type 1 */
    int port_id = func_001355D0(1);
    assert(port_id == 0);
    assert(func_001351B8(0) == 0); /* state is 0 */
    assert(func_00135258(0) == 1); /* type is 1 */

    /* Set port state to active (1) */
    assert(func_001356E8(0, 1) == 0);
    assert(func_001351B8(0) == 1);

    /* Set payload */
    char test_payload[4] = {0x11, 0x22, 0x33, 0x44};
    assert(func_00135798(0, test_payload, 4) == 0);

    int read_out[4] = {0};
    int plen = func_001352D8(0, read_out);
    assert(plen == 4);
    assert(read_out[0] == 1); /* device type */
    char *bytes = (char *)(read_out + 1);
    assert(bytes[0] == 0x11 && bytes[1] == 0x22 && bytes[2] == 0x33 && bytes[3] == 0x44);

    /* Enqueue mouse motion/button event */
    assert(func_00135870(0, 10, -5, 1, 0) == 0);

    /* Dequeue packet */
    int pkt[4] = {0};
    assert(func_00135118(0, pkt) == 1);
    assert(pkt[0] == 10);
    assert(pkt[1] == -5);
    assert(pkt[2] == 1);
    assert(pkt[3] == 0);

    /* Queue should now be empty */
    assert(func_00135118(0, pkt) == 0);

    /* Reset ports */
    assert(func_001353C0(1) == 2);
    assert(func_001351B8(0) == -1);
}

int main(int argc, char **argv) {
    test_mouse_dispatch_wrapper();
    test_mouse_init_work();
    test_mouse_ports_and_events();
    printf("All native kt_mouse tests passed successfully.\n");
    return 0;
}
