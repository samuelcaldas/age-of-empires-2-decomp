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

    int D_004E3560[2] = {0, 777};
    static int sem_wait_calls = 0;
    static int sem_signal_calls = 0;
    int func_104D60(int sem) {
        assert(sem == 777);
        sem_wait_calls++;
        return 0;
    }
    int func_104D40(int sem) {
        assert(sem == 777);
        sem_signal_calls++;
        return 0;
    }

    int D_004E3530 = 1;
    char D_0108AFA0[512];
    extern const char D_00492C60[16] = "GUID_SESSION_16";
    extern const char D_004D1F10[] = "PLAYER";
    extern const char D_004D1F18[] = "SESSION";

    int func_117a64(const char *a, const char *b, int n) {
        return strncmp(a, b, n);
    }
    char *func_11ABBC(char *dst, const char *src) {
        return strcpy(dst, src);
    }
    char *func_11B170(char *dst, const char *src, int n) {
        return strncpy(dst, src, n);
    }
    int func_11ACD0(const char *s) {
        return (int)strlen(s);
    }
    void *func_00338470(void *state, const void *payload, int size) {
        int *fields = (int *)state;
        char *buf = (char *)state + 1324 + fields[845];
        memcpy(buf, payload, size);
        fields[843]++;
        fields[846] = fields[845];
        fields[845] += (size + 3) & -4;
        return buf;
    }
    static int cur_time_ms = 1000;
    int func_2261C0(void) {
        return cur_time_ms;
    }
    void func_103358(int arg) {
        cur_time_ms += 1000;
        if (cur_time_ms == 2000) {
            strcpy(D_0108AFA0, "SESSION");
        }
    }
    static int last_converted_id = 0;
    int func_335A20(void) {
        last_converted_id++;
        return 1100;
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
    DPlayPlayerSlot *s0 = func_003382D0(obj, 0);
    assert(s0 == (DPlayPlayerSlot *)(obj + 4));
    s0->id = 100;
    DPlayPlayerSlot *s1 = func_003382D0(obj, 0);
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

    /* 6. func_00338970: GetPlayerName */
    func_003381A0(obj);
    DPlayPlayerSlot *p0 = func_003382D0(obj, 0);
    p0->id = 55;
    int name_size = 0;
    assert(func_00338970(obj, 55, 0, &name_size) == 0);
    assert(name_size == 16);
    assert(func_00338970(obj, 999, payload, &name_size) == (int)0x88770096u);
    name_size = 8;
    assert(func_00338970(obj, 55, payload, &name_size) == (int)0x8877001Eu);
    name_size = 16;
    void *name_struct[4] = {0};
    assert(func_00338970(obj, 55, name_struct, &name_size) == 0);
    assert((int)(long)name_struct[0] == 16);
    assert(name_struct[1] == 0);
    assert(name_struct[2] == (char *)p0 + 24);
    assert(name_struct[3] == (char *)p0 + 40);

    /* 7. func_00338A10 & func_00338A20 & func_00339220: Receive & Queue ops */
    *(int *)(obj + 3372) = 3;
    int qcount = 0;
    assert(func_00338A10(obj, 0, &qcount, 0) == 0);
    assert(qcount == 3);
    assert(func_00339220(obj) == 0);
    assert(*(int *)(obj + 3372) == 0);

    /* Empty queue receive -> 0x887700BE */
    int rx_from = 0, rx_to = 0, rx_sz = 0;
    char rx_buf[64];
    assert(func_00338A20(obj, &rx_from, &rx_to, 0, rx_buf, &rx_sz) == (int)0x887700BEu);

    /* Enqueue one message manually into ring buffer at obj + 1324 */
    int *ring_entry = (int *)(obj + 1324);
    ring_entry[0] = 222; /* to */
    ring_entry[1] = 111; /* from */
    ring_entry[2] = 0;
    ring_entry[3] = 5;   /* size */
    memcpy(ring_entry + 4, "HELLO", 5);
    *(int *)(obj + 3372) = 1;
    *(int *)(obj + 3376) = 0;
    /* Peek size (data == NULL) */
    assert(func_00338A20(obj, &rx_from, &rx_to, 0, 0, &rx_sz) == 0);
    assert(rx_from == 111 && rx_to == 222 && rx_sz == 5);
    assert(*(int *)(obj + 3372) == 1);
    /* Dequeue payload */
    memset(rx_buf, 0, sizeof(rx_buf));
    assert(func_00338A20(obj, &rx_from, &rx_to, 0, rx_buf, &rx_sz) == 0);
    assert(memcmp(rx_buf, "HELLO", 5) == 0);
    assert(*(int *)(obj + 3372) == 0);
    assert(*(int *)(obj + 3376) == 24); /* 16 + ((5+3)&~3) = 24 */

    /* 8. func_00338B90: Send (direct & broadcast) */
    send_checked_ret = 20;
    last_send_size = 0;
    *(int *)(obj + 0) = 55; /* local player id = 55 */
    DPlayPlayerSlot *p1 = func_003382D0(obj, 0);
    p1->id = 66;
    /* Broadcast (to_id == 0) sends to p1 (66), skips p0 (55 == local id) */
    assert(func_00338B90(obj, 55, 0, 0, payload, 4) == 0);
    assert(*(int *)(obj + 3388 + 0) == 66);
    assert(*(int *)(obj + 3388 + 4) == 55);
    /* Direct (to_id == 77) */
    assert(func_00338B90(obj, 55, 77, 0, payload, 4) == 0);
    assert(*(int *)(obj + 3388 + 0) == 77);
    assert(*(int *)(obj + 3388 + 4) == 55);

    /* 9. func_00338C60, func_00338CB0, func_00338CC0: COM methods */
    assert(func_00338CB0(obj) == 0);
    void *q_iface = 0;
    obj[4560] = 1;
    assert(func_00338CC0(obj, 0, &q_iface) == 0);
    assert(q_iface == D_01087ED0);
    assert(obj[4560] == 2);
    assert(func_00338C60(obj) == 1);
    assert(func_00338C60(obj) == 0);

    /* 10. func_003390D0, func_00339140, func_003391E0: Caps & SessionDesc */
    func_003381A0(obj);
    p0 = func_003382D0(obj, 0);
    p0->id = 55;
    int pcaps[10] = {0};
    assert(func_003390D0(obj, 999, pcaps, 0) == (int)0x88770096u);
    assert(func_003390D0(obj, 55, pcaps, 0) == 0);
    assert(pcaps[1] == 64 && pcaps[4] == 8 && pcaps[9] == 6000);

    unsigned int sdesc_sz = 0;
    assert(func_00339140(obj, 0, &sdesc_sz) == 0);
    assert(sdesc_sz == 80);
    sdesc_sz = 40;
    char sdesc_buf[80];
    assert(func_00339140(obj, sdesc_buf, &sdesc_sz) == (int)0x8877001Eu);
    sdesc_sz = 80;
    assert(func_00339140(obj, sdesc_buf, &sdesc_sz) == 0);

    int dcaps[10] = {0};
    *(int *)(obj + 1312) = 1;
    assert(func_003391E0(obj, dcaps, 0) == 0);
    assert(dcaps[1] == 66 && dcaps[4] == 8 && dcaps[9] == 60);

    /* 11. func_00339270 & func_003392B0: Close & SendDestroyMsg */
    *(int *)(obj + 0) = 88;
    *(int *)(obj + 1136) = 4;
    *(int *)(obj + 1308) = 1;
    assert(func_00339270(obj) == 0);
    assert(*(int *)(obj + 1308) == 0);
    assert(*(int *)(obj + 1136) == 3);

    return 0;
}
