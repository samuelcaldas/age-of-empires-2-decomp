#include <assert.h>
#include <string.h>
#include "network_dplay_3380e0.h"

char D_01087ED0[4608];
char D_010890A0[16];

extern "C" {
    extern const char D_00492C50[] = "GUID_MOCK_16BYTE";
    extern const char D_004D20F0[] = "DirectPlay Compatible Interface";
    extern const char D_004D2110[] = "err! il_sendto(%d)\n";

    static int stub_339270_calls = 0;
    static int free_100670_calls = 0;
    static int rand_seq[4] = {0, 100, 200, 300};
    static int rand_idx = 0;
    static int send_checked_ret = 0;
    static int last_send_size = 0;
    static int log_calls = 0;

    void func_117CAC(void *dst, int val, int size) {
        memset(dst, val, size);
    }

    void func_117AF8(void *dst, const void *src, int size) {
        memcpy(dst, src, size);
    }

    void func_339270(void) {
        stub_339270_calls++;
    }

    void func_100670(void *ptr) {
        free_100670_calls++;
    }

    int func_1AAB30(void) {
        return rand_seq[rand_idx++];
    }

    int func_00337840(const void *payload, int size) {
        last_send_size = size;
        return send_checked_ret;
    }

    int func_118de0(const char *fmt, ...) {
        log_calls++;
        return 0;
    }
}

static int enum_cb_calls = 0;
static void *enum_cb_ctx = 0;
static int mock_enum_cb(const void *guid, const char *name, int major, int minor, void *ctx) {
    assert(guid == D_00492C50);
    assert(strcmp(name, "DirectPlay Compatible Interface") == 0);
    assert(major == 6);
    assert(minor == 0);
    enum_cb_calls++;
    enum_cb_ctx = ctx;
    return 1;
}

int main(void) {
    /* 1. func_003380E0: DirectPlayCreate */
    memset(D_01087ED0, 0xAA, sizeof(D_01087ED0));
    D_010890A0[0] = 0;
    void *iface = 0;
    assert(func_003380E0(0, &iface, 0) == 0);
    assert(iface == D_01087ED0);
    assert(D_010890A0[0] == 1);
    assert(*(int *)(D_01087ED0 + 1316) == 1);
    assert(func_003380E0(0, &iface, 0) == 0);
    assert(D_010890A0[0] == 2);

    /* 2. func_00338140: DirectPlayEnumerate */
    int dummy_ctx = 42;
    assert(func_00338140(mock_enum_cb, &dummy_ctx) == 0);
    assert(enum_cb_calls == 1);
    assert(enum_cb_ctx == &dummy_ctx);

    /* 3. func_00338230 & func_00338260: ctor and dtor */
    char obj[4608];
    memset(obj, 0xFF, sizeof(obj));
    assert(func_00338230(obj) == obj);
    assert(*(int *)(obj + 1308) == 0);
    assert(*(int *)(obj + 1316) == 1);

    stub_339270_calls = 0;
    free_100670_calls = 0;
    assert(func_00338260(obj, 1) == obj);
    assert(stub_339270_calls == 1);
    assert(free_100670_calls == 1);

    /* 4. func_003382D0 & func_00338310 & func_00338350: slot ops */
    func_003381A0(obj);
    DPlayPlayerSlot *s0 = func_003382D0(obj);
    assert(s0 == (DPlayPlayerSlot *)(obj + 4));
    s0->id = 100;
    DPlayPlayerSlot *s1 = func_003382D0(obj);
    assert(s1 == (DPlayPlayerSlot *)((char *)s0 + 136));
    assert(func_00338310(obj, 100) == s0);
    assert(func_00338310(obj, 999) == 0);

    rand_idx = 0; /* returns 0 (skipped), 100 (collision with s0->id), then 200 (unique!) */
    assert(func_00338350(obj) == 200);

    /* 5. func_003383B0: send packet with checksum */
    unsigned char payload[4] = {10, 20, 30, 40};
    /* Too large (> 1008 bytes -> size+16 > 1024) */
    assert(func_003383B0(obj, 1, 2, payload, 1009) == 0);
    /* Valid packet */
    send_checked_ret = 492;
    assert(func_003383B0(obj, 11, 22, payload, 4) == 492);
    int *pkt_hdr = (int *)(obj + 3388);
    assert(pkt_hdr[0] == 11);
    assert(pkt_hdr[1] == 22);
    assert(pkt_hdr[2] == 100); /* 10 + 20 + 30 + 40 */
    assert(pkt_hdr[3] == 4);
    assert(memcmp(obj + 3388 + 16, payload, 4) == 0);
    assert(last_send_size == 20);

    /* Error path (< 0) logs error */
    log_calls = 0;
    send_checked_ret = -2;
    assert(func_003383B0(obj, 11, 22, payload, 4) == -2);
    assert(log_calls == 1);

    return 0;
}
