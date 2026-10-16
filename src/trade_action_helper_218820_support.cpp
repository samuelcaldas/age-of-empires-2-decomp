#include <cassert>
#include <cstring>

extern "C" {
void func_00218820(void *self);

int ab8f0_calls = 0;
int acdf0_calls = 0;
int ad940_calls = 0;
int ada70_calls = 0;
int adc00_calls = 0;
int ab9d0_calls = 0;
int return_ab8f0_val = 1;
void *last_manager = nullptr;
void *cleanup_manager = nullptr;
int active_state = 0;
void *mutated_manager_val = nullptr;

int func_001AB8F0(void *arg0, int arg1) {
    ab8f0_calls++;
    char *self = (char *)arg0 - 0x20; // assuming self is passed or derived
    if (mutated_manager_val != nullptr) {
        // Mutate manager pointer at self + 0x20
        // arg0 is manager, so self + 0x20 is manager location
        // Here we simulate mutation if needed
    }
    return return_ab8f0_val;
}

int func_001ACDF0(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5) {
    acdf0_calls++;
    last_manager = arg0;
    return 1;
}

int func_001AD940(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6) {
    ad940_calls++;
    last_manager = arg0;
    return 1;
}

int func_001ADA70(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    ada70_calls++;
    last_manager = arg0;
    return 1;
}

int func_001ADC00(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10) {
    adc00_calls++;
    last_manager = arg0;
    return 1;
}

int func_001AB9D0(void *arg0) {
    ab9d0_calls++;
    cleanup_manager = arg0;
    return 1;
}
}

void reset_mocks() {
    ab8f0_calls = 0;
    acdf0_calls = 0;
    ad940_calls = 0;
    ada70_calls = 0;
    adc00_calls = 0;
    ab9d0_calls = 0;
    return_ab8f0_val = 1;
    last_manager = nullptr;
    cleanup_manager = nullptr;
    active_state = 0;
    mutated_manager_val = nullptr;
}
