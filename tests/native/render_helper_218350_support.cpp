#include "render_helper_218350_harness.h"

extern "C" {
int func_001ABA00(void *arg0) {
    log_event(EV_ABA00, arg0);
    if (mutation_target_self != nullptr) {
        *reinterpret_cast<void **>((char *)mutation_target_self + 0x20) = mutated_manager_val;
    }
    return aba00_return_val;
}

int func_002257A0(void *arg0, int arg1) {
    log_event(EV_2257A0, arg0, arg1);
    return arg1 + 1;
}

int func_001ABA70(void *arg0) {
    log_event(EV_ABA70, arg0);
    return 1;
}

void func_002184D0(void *self) {
    log_event(EV_2184D0, self);
}

void func_00218820(void *self) {
    log_event(EV_218820, self);
}
}

void mock_fn30(void *self, void *val) {
    log_event(EV_FN30, self, (int)(long)val);
}

void mock_fn120(void *self, void *a1, void *a2, void *a3, void *a4) {
    log_event(EV_FN120, self, 0, a1, a2, a3, a4);
}

void mock_fn34(void *self) {
    log_event(EV_FN34, self);
}
