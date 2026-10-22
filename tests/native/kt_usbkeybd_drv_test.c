#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "kt_usbkeybd_drv.h"

UsbKeybdDevice D_50A540;
int D_50A580[0x20];

const char D_490A60[] = "kt_usbkeybd_drv.c";
const char D_490A78[] = "!((unsigned int)info & 63)";
const char D_490A98[] = "!((unsigned int)data & 63)";
const char D_490AB8[] = "!((unsigned int)location & 63)";

static int mock_assert_count = 0;
static int mock_assert_line = 0;
static int mock_rpc_cmd = 0;
static int mock_rpc_ret = 0;

void func_1075C8(int a0) {}

void func_107C38(UsbKeybdDevice *dev, unsigned int code, int flags) {
    assert(code == 0x80000211);
}

void func_114320(const char *file, int line, const char *msg) {
    mock_assert_count++;
    mock_assert_line = line;
}

int func_107E08(UsbKeybdDevice *dev, int cmd, int a2, void *tx, int tx_len,
                void *rx, int rx_len, int a7, int a8) {
    mock_rpc_cmd = cmd;
    return mock_rpc_ret;
}

static void test_check_status(void) {
    D_50A540.status = 0;
    assert(func_00137208() == 1);
    D_50A540.status = 2;
    assert(func_00137208() == 0);
}

static void test_alignment_assertions(void) {
    char aligned_buf[128];
    char *aligned_ptr = (char *)(((unsigned int)aligned_buf + 63) & ~63);
    char *unaligned_ptr = aligned_ptr + 4;

    mock_assert_count = 0;
    func_00137250(aligned_ptr);
    assert(mock_assert_count == 0);
    assert(mock_rpc_cmd == 1);

    func_00137250(unaligned_ptr);
    assert(mock_assert_count == 1);
    assert(mock_assert_line == 0x4F);

    func_001372C0(7, unaligned_ptr);
    assert(mock_assert_count == 2);
    assert(mock_assert_line == 0x7B);
    assert(D_50A580[0] == 7);

    func_00137340(9, unaligned_ptr);
    assert(mock_assert_count == 3);
    assert(mock_assert_line == 0x99);
    assert(D_50A580[0] == 9);
}

static void test_led_and_caps_requests(void) {
    mock_rpc_ret = 0;
    int r1 = func_001373C0(1, 3);
    assert(mock_rpc_cmd == 4);
    assert(r1 == 1);

    mock_rpc_ret = -5;
    int r2 = func_00137420(2, 4);
    assert(mock_rpc_cmd == 5);
    assert(r2 == -5);
}

int main(void) {
    test_check_status();
    test_alignment_assertions();
    test_led_and_caps_requests();
    printf("All native kt_usbkeybd_drv tests passed.\n");
    return 0;
}
