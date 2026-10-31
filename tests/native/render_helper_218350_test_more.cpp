#include <cassert>
#include <cstring>
#include <iostream>
#include "render_helper_218350_harness.h"

extern "C" {
void func_00218350(void *self);
}

static int alt_fn120_calls_limit = 0;
static void *saved_self_for_limit_mutation = nullptr;

static void mock_fn120_limit_mutator(void *self, void *a1, void *a2, void *a3, void *a4) {
    alt_fn120_calls_limit++;
    log_event(EV_FN120, self, 999, a1, a2, a3, a4);
    if (saved_self_for_limit_mutation != nullptr) {
        *reinterpret_cast<short *>((char *)saved_self_for_limit_mutation + 0x126) = 5;
    }
}

void test_case_218350_dynamic_mutation_during_loop() {
    reset_mocks();
    alt_fn120_calls_limit = 0;
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable[128];
    std::memset(vtable, 0, sizeof(vtable));
    *reinterpret_cast<void **>((char *)vtable + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable + 0x120) = (void *)mock_fn120_limit_mutator;
    *reinterpret_cast<void **>((char *)vtable + 0x34) = (void *)mock_fn34;
    vtable[10] = (void *)mock_fn30;
    vtable[11] = (void *)mock_fn34;
    vtable[70] = (void *)mock_fn120_limit_mutator;

    *reinterpret_cast<void **>(buf) = vtable;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;
    *reinterpret_cast<int *>(buf + 0x12C) = 10;
    *reinterpret_cast<short *>(buf + 0x124) = 5;
    *reinterpret_cast<short *>(buf + 0x126) = 10;
    *reinterpret_cast<int *>(buf + 0x8C) = 1;
    *reinterpret_cast<int *>(buf + 0x90) = 1;

    saved_self_for_limit_mutation = buf;

    func_00218350(buf);

    assert(event_log.size() == 9); // exactly 9 events for case 5
    assert(alt_fn120_calls_limit == 1);
    delete[] buf;
}

static int alt_fn120_calls = 0;
static int normal_fn120_calls = 0;
static void *saved_vtable2 = nullptr;

static void mock_fn120_alt(void *self, void *a1, void *a2, void *a3, void *a4) {
    alt_fn120_calls++;
    log_event(EV_FN120, self, 200, a1, a2, a3, a4);
}

static void mock_fn120_normal(void *self, void *a1, void *a2, void *a3, void *a4) {
    normal_fn120_calls++;
    log_event(EV_FN120, self, 100, a1, a2, a3, a4);
    if (saved_vtable2 != nullptr) {
        *reinterpret_cast<void **>(self) = saved_vtable2;
        *reinterpret_cast<int *>((char *)self + 0x8C) = 0;
        *reinterpret_cast<int *>((char *)self + 0x80) = 1;
    }
}

void test_case_218350_dynamic_vtable_and_flags_mutation() {
    reset_mocks();
    normal_fn120_calls = 0;
    alt_fn120_calls = 0;
    unsigned char *buf = new unsigned char[0x300];
    std::memset(buf, 0, 0x300);

    void *vtable1[128];
    void *vtable2[128];
    std::memset(vtable1, 0, sizeof(vtable1));
    std::memset(vtable2, 0, sizeof(vtable2));

    *reinterpret_cast<void **>((char *)vtable1 + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable1 + 0x120) = (void *)mock_fn120_normal;
    *reinterpret_cast<void **>((char *)vtable1 + 0x34) = (void *)mock_fn34;
    vtable1[10] = (void *)mock_fn30;
    vtable1[11] = (void *)mock_fn34;
    vtable1[70] = (void *)mock_fn120_normal;

    *reinterpret_cast<void **>((char *)vtable2 + 0x30) = (void *)mock_fn30;
    *reinterpret_cast<void **>((char *)vtable2 + 0x120) = (void *)mock_fn120_alt;
    *reinterpret_cast<void **>((char *)vtable2 + 0x34) = (void *)mock_fn34;
    vtable2[10] = (void *)mock_fn30;
    vtable2[11] = (void *)mock_fn34;
    vtable2[70] = (void *)mock_fn120_alt;

    *reinterpret_cast<void **>(buf) = vtable1;
    *reinterpret_cast<void **>(buf + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(buf + 0x88) = (void *)0x8888;
    *reinterpret_cast<void **>(buf + 0x84) = (void *)0x7777;
    *reinterpret_cast<int *>(buf + 0x12C) = 10;
    *reinterpret_cast<short *>(buf + 0x124) = 5;
    *reinterpret_cast<short *>(buf + 0x126) = 6;
    *reinterpret_cast<int *>(buf + 0x8C) = 1;
    *reinterpret_cast<int *>(buf + 0x90) = 1;

    saved_vtable2 = vtable2;

    func_00218350(buf);

    assert(normal_fn120_calls == 1);
    assert(alt_fn120_calls == 1);
    assert(event_log.size() == 10);
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
    assert(event_log[5].param4 == (void *)1); // alt path uses flag80 (param4 = 1)

    assert(event_log[7].type == EV_ABA70);
    assert(event_log[7].receiver == (void *)0x9999);
    assert(event_log[8].type == EV_218820);
    assert(event_log[9].type == EV_FN34);

    delete[] buf;
}

void test_case_218350_early_guards();
void test_case_218350_success_and_fn120_args();
void test_case_218350_flag80_single_iteration();
void test_case_218350_null_aba00();
void test_case_218350_manager_mutation();

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_218350_early_guards();
    else if (case_num == 1) test_case_218350_success_and_fn120_args();
    else if (case_num == 2) test_case_218350_flag80_single_iteration();
    else if (case_num == 3) test_case_218350_null_aba00();
    else if (case_num == 4) test_case_218350_manager_mutation();
    else if (case_num == 5) test_case_218350_dynamic_mutation_during_loop();
    else if (case_num == 6) test_case_218350_dynamic_vtable_and_flags_mutation();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
