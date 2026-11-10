#include <cassert>
#include <cstring>
#include <iostream>
#include "render_helper_218350_harness.h"

extern "C" {
void func_00218350(void *self);
}

void test_case_218350_early_guards() {
    reset_mocks();
    unsigned char *buf = new unsigned char[0x300];

    // 1. field20 == 0
    std::memset(buf, 0, 0x300);
    *reinterpret_cast<int *>(buf + 0x38) = 123;
    func_00218350(buf);
    assert(event_log.empty());
    assert(*reinterpret_cast<int *>(buf + 0x38) == 0);

    // 2. field88 == 0
    std::memset(buf, 0, 0x300);
    *reinterpret_cast<int *>(buf + 0x38) = 123;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    func_00218350(buf);
    assert(event_log.empty());
    assert(*reinterpret_cast<int *>(buf + 0x38) == 0);

    // 3. field84 == 0
    std::memset(buf, 0, 0x300);
    *reinterpret_cast<int *>(buf + 0x38) = 123;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    func_00218350(buf);
    assert(event_log.empty());
    assert(*reinterpret_cast<int *>(buf + 0x38) == 0);

    delete[] buf;
}

void test_case_218350_success_and_fn120_args() {
    reset_mocks();
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable[128];
    std::memset(vtable, 0, sizeof(vtable));
    *reinterpret_cast<void **>((char *)vtable + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable + 0x120) = (void *)mock_fn120;
    *reinterpret_cast<void **>((char *)vtable + 0x34) = (void *)mock_fn34;
    vtable[10] = (void *)mock_fn30;
    vtable[11] = (void *)mock_fn34;
    vtable[70] = (void *)mock_fn120;

    *reinterpret_cast<void **>(buf) = vtable;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;
    *reinterpret_cast<int *>(buf + 0x12C) = 10;
    *reinterpret_cast<short *>(buf + 0x124) = 5;
    *reinterpret_cast<short *>(buf + 0x126) = 6;
    *reinterpret_cast<int *>(buf + 0x8C) = 1;
    *reinterpret_cast<int *>(buf + 0x90) = 1;

    func_00218350(buf);

    assert(event_log.size() == 10);
    assert(event_log[0].type == EV_FN30);
    assert(event_log[0].receiver == buf);
    assert(event_log[0].arg_val == 0);

    assert(event_log[1].type == EV_2184D0);
    assert(event_log[1].receiver == buf);

    assert(event_log[2].type == EV_ABA00);
    assert(event_log[2].receiver == (void *)0x9999);

    assert(event_log[3].type == EV_2257A0);
    assert(event_log[3].receiver == (void *)0x9999);
    assert(event_log[3].arg_val == 10);

    assert(event_log[4].type == EV_FN120);
    assert(event_log[4].receiver == buf);
    assert(event_log[4].param1 == (void *)0x9999);
    assert(event_log[4].param2 == (void *)0);
    assert(event_log[4].param3 == (void *)5);
    assert(event_log[4].param4 == (void *)1);

    assert(event_log[5].type == EV_FN120);
    assert(event_log[5].receiver == buf);
    assert(event_log[5].param1 == (void *)0x9999);
    assert(event_log[5].param2 == (void *)1);
    assert(event_log[5].param3 == (void *)6);
    assert(event_log[5].param4 == (void *)1);

    assert(event_log[6].type == EV_2257A0);
    assert(event_log[6].receiver == (void *)0x9999);
    assert(event_log[6].arg_val == 11);

    assert(event_log[7].type == EV_ABA70);
    assert(event_log[7].receiver == (void *)0x9999);

    assert(event_log[8].type == EV_218820);
    assert(event_log[8].receiver == buf);

    assert(event_log[9].type == EV_FN34);
    assert(event_log[9].receiver == buf);

    assert(*reinterpret_cast<int *>(buf + 0x38) == 0);
    delete[] buf;
}

void test_case_218350_flag80_single_iteration() {
    reset_mocks();
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable[128];
    std::memset(vtable, 0, sizeof(vtable));
    *reinterpret_cast<void **>((char *)vtable + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable + 0x120) = (void *)mock_fn120;
    *reinterpret_cast<void **>((char *)vtable + 0x34) = (void *)mock_fn34;
    vtable[10] = (void *)mock_fn30;
    vtable[11] = (void *)mock_fn34;
    vtable[70] = (void *)mock_fn120;

    *reinterpret_cast<void **>(buf) = vtable;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;
    *reinterpret_cast<int *>(buf + 0x12C) = 10;
    *reinterpret_cast<short *>(buf + 0x124) = 2;
    *reinterpret_cast<short *>(buf + 0x126) = 2;
    *reinterpret_cast<int *>(buf + 0x80) = 1;

    func_00218350(buf);

    assert(event_log.size() == 9);
    assert(event_log[4].type == EV_FN120);
    assert(event_log[4].param4 == (void *)1);

    delete[] buf;
}
