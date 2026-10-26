#include <cassert>
#include <cstring>
#include <iostream>
#include "render_helper_218350_harness.h"

extern "C" {
void func_00218350(void *self);
}

void test_case_218350_null_aba00() {
    reset_mocks();
    aba00_return_val = 0;
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable[128];
    std::memset(vtable, 0, sizeof(vtable));
    *reinterpret_cast<void **>((char *)vtable + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable + 0x34) = (void *)mock_fn34;

    *reinterpret_cast<void **>(buf) = vtable;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;

    func_00218350(buf);

    assert(event_log.size() == 5);
    assert(event_log[0].type == EV_FN30);
    assert(event_log[1].type == EV_2184D0);
    assert(event_log[2].type == EV_ABA00);
    assert(event_log[3].type == EV_218820);
    assert(event_log[4].type == EV_FN34);

    delete[] buf;
}

void test_case_218350_manager_mutation() {
    reset_mocks();
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable[128];
    std::memset(vtable, 0, sizeof(vtable));
    *reinterpret_cast<void **>((char *)vtable + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable + 0x34) = (void *)mock_fn34;

    *reinterpret_cast<void **>(buf) = vtable;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;
    *reinterpret_cast<int *>(buf + 0x12C) = 10;
    *reinterpret_cast<short *>(buf + 0x124) = 0;
    *reinterpret_cast<short *>(buf + 0x126) = -1;

    mutation_target_self = buf;
    mutated_manager_val = (void *)0xABCD;

    func_00218350(buf);

    bool found_aba70_with_abcd = false;
    for (const auto &ev : event_log) {
        if (ev.type == EV_ABA70 && ev.receiver == (void *)0xABCD) {
            found_aba70_with_abcd = true;
        }
    }
    assert(found_aba70_with_abcd);

    delete[] buf;
}
