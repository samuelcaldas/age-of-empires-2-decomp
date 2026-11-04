#include <cassert>
#include <cstring>
#include <vector>
#include "trade_action_load.h"

// Mock state and tracking
static std::vector<unsigned char> s_stream_data;
static size_t s_stream_offset = 0;

static int s_func_00150770_called = 0;
static int s_func_001508F0_called = 0;
static int s_func_00150CC0_called = 0;
static int s_func_001FC6C0_called = 0;
static int s_func_001FDCC0_called = 0;

static void *s_last_stream = NULL;
static void *s_last_obj = NULL;

extern "C" {

void func_00226D90(void *stream, void *data, int size) {
    s_last_stream = stream;
    assert(s_stream_offset + size <= s_stream_data.size());
    std::memcpy(data, &s_stream_data[s_stream_offset], size);
    s_stream_offset += size;
}

void func_00150770(TradeAction *self, int count) {
    (void)self;
    (void)count;
    s_func_00150770_called++;
}

void func_001508F0(TradeAction *self, void *item, int flag) {
    (void)self;
    (void)item;
    (void)flag;
    s_func_001508F0_called++;
}

void func_00150CC0(TradeAction *self, void *item) {
    (void)self;
    (void)item;
    s_func_00150CC0_called++;
}

static char s_dummy_obj[64];

void *func_001FC6C0() {
    s_func_001FC6C0_called++;
    return (void *)s_dummy_obj;
}

void func_001FDCC0(void *obj, void *stream) {
    s_last_obj = obj;
    (void)stream;
    s_func_001FDCC0_called++;
}

}

template <typename T>
static void append_data(const T &val) {
    const unsigned char *p = reinterpret_cast<const unsigned char *>(&val);
    s_stream_data.insert(s_stream_data.end(), p, p + sizeof(T));
}

static void append_bytes(const void *ptr, size_t size) {
    const unsigned char *p = reinterpret_cast<const unsigned char *>(ptr);
    s_stream_data.insert(s_stream_data.end(), p, p + size);
}

int main() {
    TradeAction action;
    std::memset(&action, 0, sizeof(action));
    short a4_buf[16] = {0};
    action.m_fieldA4 = a4_buf;
    ActionItem3 item3_buf[4] = {{0, 0}};
    action.m_field174 = item3_buf;

    s_stream_data.clear();
    s_stream_offset = 0;

    // Stream layout according to func_00146A40:
    // 1. ival (unused header/discard)
    int dummy = 42;
    append_data(dummy);

    // 2. m_field44
    int val_44 = 101;
    append_data(val_44);
    // 3. m_field46
    int val_46 = 102;
    append_data(val_46);
    // 4. m_field48
    int val_48 = 103;
    append_data(val_48);
    // 5. m_field4A
    int val_4A = 104;
    append_data(val_4A);
    // 6. m_field4C
    int val_4C = 105;
    append_data(val_4C);

    // 7. float50, float54, float58, float5C
    float f50 = 1.5f, f54 = 2.5f, f58 = 3.5f, f5C = 4.5f;
    append_data(f50);
    append_data(f54);
    append_data(f58);
    append_data(f5C);

    // 8. m_field62, m_field60, m_field64, m_field66
    int val_62 = 201;
    append_data(val_62);
    int val_60 = 202;
    append_data(val_60);
    int val_64 = 203;
    append_data(val_64);
    int val_66 = 204;
    append_data(val_66);

    // 9. field138, field13C, field144, field140, field148, field14C, field150
    int val_138 = 301, val_13C = 302, val_144 = 303, val_140 = 304;
    int val_148 = 305, val_14C = 306, val_150 = 307;
    append_data(val_138);
    append_data(val_13C);
    append_data(val_144);
    append_data(val_140);
    append_data(val_148);
    append_data(val_14C);
    append_data(val_150);

    // 10. m_field4E
    int val_4E = 106;
    append_data(val_4E);

    // 11. fval
    float dummy_f = 9.9f;
    append_data(dummy_f);

    // 12. vec (16 bytes)
    Vector16 dummy_vec = {1.0f, 2.0f, 3.0f, 4.0f};
    append_data(dummy_vec);

    // 13. count1
    int count1 = 2;
    append_data(count1);
    for (int i = 0; i < count1; i++) {
        ActionItem1Packed it1;
        std::memset(&it1, 0, sizeof(it1));
        it1.m_s0 = 10 + i;
        it1.m_f8 = 5.0f * i;
        append_data(it1);
    }

    // 14. count2
    int count2 = 1;
    append_data(count2);
    for (int j = 0; j < count2; j++) {
        ActionItem2Packed it2;
        std::memset(&it2, 0, sizeof(it2));
        it2.m_s0 = 20 + j;
        it2.m_i8 = 200 + j;
        append_data(it2);
    }

    // 15. ival2 (loop k)
    int count_k = 3;
    append_data(count_k);
    for (int k = 0; k < count_k; k++) {
        int a4_val = 50 + k;
        append_data(a4_val);
    }

    // 16. field2D, field2E
    char f2D = 12;
    char f2E = 13;
    append_data(f2D);
    append_data(f2E);

    // 17. float154, float158, field15C, field2F, field160
    float f154 = 7.7f, f158 = 8.8f;
    int f15C = 701;
    char f2F = 14;
    int f160 = 702;
    append_data(f154);
    append_data(f158);
    append_data(f15C);
    append_data(f2F);
    append_data(f160);

    // 18. has164 != 0
    int has164 = 1;
    append_data(has164);
    int f168 = 703;
    append_data(f168);

    // 19. dummy ival
    int dummy2 = 999;
    append_data(dummy2);

    // 20. field68, field6A
    int f68 = 308, f6A = 309;
    append_data(f68);
    append_data(f6A);

    // 21. field70, field74 (12 bytes)
    int f70 = 401;
    int f74[3] = {402, 403, 404};
    append_data(f70);
    append_bytes(f74, 12);

    // 22. field6C, field6E
    int f6C = 501, f6E = 502;
    append_data(f6C);
    append_data(f6E);

    // 23. field80 (12 bytes), field8C, field16C
    int f80[3] = {601, 602, 603};
    int f8C = 604, f16C = 605;
    append_bytes(f80, 12);
    append_data(f8C);
    append_data(f16C);

    // 24. count3
    int count3 = 2;
    append_data(count3);
    for (int m = 0; m < count3; m++) {
        int p1 = 801 + m;
        int p2 = 802 + m;
        append_data(p1);
        append_data(p2);
    }

    // 25. field170, field30
    int f170 = 901;
    char f30 = 99;
    append_data(f170);
    append_data(f30);

    // Execute load
    void *dummy_stream = (void *)0x1234;
    func_00146A40(&action, dummy_stream);

    // Verify fields
    assert(action.m_field44 == 101);
    assert(action.m_field46 == 102);
    assert(action.m_field48 == 103);
    assert(action.m_field4A == 104);
    assert(action.m_field4C == 105);
    assert(action.m_float50 == 1.5f);
    assert(action.m_float54 == 2.5f);
    assert(action.m_float58 == 3.5f);
    assert(action.m_float5C == 4.5f);
    assert(action.m_field62 == 201);
    assert(action.m_field60 == 202);
    assert(action.m_field64 == 203);
    assert(action.m_field66 == 204);
    assert(action.m_field138 == 301);
    assert(action.m_field13C == 302);
    assert(action.m_field144 == 303);
    assert(action.m_field140 == 304);
    assert(action.m_field148 == 305);
    assert(action.m_field14C == 306);
    assert(action.m_field150 == 307);
    assert(action.m_field4E == 106);

    assert(s_func_001508F0_called == 2);
    assert(s_func_00150CC0_called == 1);

    assert(action.m_fieldA4[0] == 50);
    assert(action.m_fieldA4[1] == 51);
    assert(action.m_fieldA4[2] == 52);

    assert(action.m_field2D == 12);
    assert(action.m_field2E == 13);
    assert(action.m_float154 == 7.7f);
    assert(action.m_float158 == 8.8f);
    assert(action.m_field15C == 701);
    assert(action.m_field2F == 14);
    assert(action.m_field160 == 702);

    assert(s_func_001FC6C0_called == 1);
    assert(s_func_001FDCC0_called == 1);
    assert(action.m_field164 == (void *)s_dummy_obj);
    assert(action.m_field168 == 703);

    assert(action.m_field68 == 308);
    assert(action.m_field6A == 309);
    assert(action.m_field70 == 401);
    assert(action.m_field74[0] == 402);
    assert(action.m_field74[1] == 403);
    assert(action.m_field74[2] == 404);
    assert(action.m_field6C == 501);
    assert(action.m_field6E == (unsigned char)502);
    assert(action.m_field80[0] == 601);
    assert(action.m_field80[1] == 602);
    assert(action.m_field80[2] == 603);
    assert(action.m_field8C == 604);
    assert(action.m_field16C == 605);

    assert(s_func_00150770_called == 2);
    assert(action.m_field174[0].m_p1 == 801);
    assert(action.m_field174[0].m_p2 == 802);
    assert(action.m_field174[1].m_p1 == 802);
    assert(action.m_field174[1].m_p2 == 803);

    assert(action.m_field170 == 901);
    assert(action.m_field30 == 99);

    return 0;
}
