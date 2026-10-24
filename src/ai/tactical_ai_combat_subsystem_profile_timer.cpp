#include "tactical_ai_combat_subsystem_profile_timer.h"

void func_00328F80(void *self) {
    int start_time = func_2261C0();
    func_1A3640(self);
    int end_time = func_2261C0();
    func_184B60(D_004E3180, 7, end_time - start_time);
}
