#include <cassert>
#include <cstdio>
#include <vector>
#include <cstring>

struct MockStream {
    std::vector<unsigned char> data;
};

static MockStream g_stream;

extern "C" {
void func_00226F70(void *stream, void *data, int size) {
    MockStream *ms = (MockStream *)stream;
    unsigned char *p = (unsigned char *)data;
    for (int i = 0; i < size; ++i) {
        ms->data.push_back(p[i]);
    }
}

void func_1FDBA0(void *obj, void *stream) {
    int marker = 0x12345678;
    func_00226F70(stream, &marker, 4);
}
}

#include "../../src/trade/trade_action_save.cpp"

extern "C" {
Vector16 D_38FB00 = {10, 20, 30, 40};
}

int main() {
    TradeAction action;
    std::memset(&action, 0, sizeof(action));
    action.m_field44 = 44;
    action.m_field46 = 46;
    action.m_field48 = 48;
    action.m_field4A = 50;
    action.m_field4C = 52;
    action.m_float50 = 1.5f;
    action.m_float54 = 2.5f;
    action.m_float58 = 3.5f;
    action.m_float5C = 4.5f;
    action.m_field31 = 1;
    action.m_buf3C = new ActionItem1[1];
    action.m_buf3C[0].m_s0 = 100;
    action.m_buf3C[0].m_f8 = 5.0f;
    action.m_field32 = 0;
    action.m_buf40 = 0;
    action.m_fieldA8 = 2;
    action.m_fieldB0 = 1;
    short a4_vals[2] = {111, 222};
    action.m_fieldA4 = a4_vals;
    action.m_field164 = (void *)0x999;

    func_00146400(&action, &g_stream);

    assert(g_stream.data.size() > 0);
    // Verify first written word is -1
    int first_word = *(int *)(g_stream.data.data());
    assert(first_word == -1);

    // Verify second written word is m_field44 (44)
    int second_word = *(int *)(g_stream.data.data() + 4);
    assert(second_word == 44);

    delete[] action.m_buf3C;
    std::printf("All tests passed!\n");
    return 0;
}
