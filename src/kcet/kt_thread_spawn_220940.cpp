#pragma exceptions off
#include "kt_thread_spawn_220940.h"

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option);
int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option);
int func_104B40(int thread_id, void *arg);
void func_2209B0(void);

void func_00220940(void) {
    func_220300(&D_00C7F430, 1, 0, 0);
    func_220380((struct ThreadContainer *)((char *)&D_00C6F3F0), (void *)func_2209B0, D_00C6F430, 0x10000, 11, 0);
    func_104B40(D_00C6F3F0.id, 0);
}
}
