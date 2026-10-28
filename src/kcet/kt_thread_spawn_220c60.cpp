#pragma exceptions off
#include "kt_thread_spawn.h"

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option);
int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option);
int func_104B40(int thread_id, void *arg);
void func_220CD0(void);

void func_00220C60(void) {
    func_220300(&D_00C824F0, 1, 0, 0);
    func_220380((struct ThreadContainer *)((char *)&D_00C804B0), (void *)func_220CD0, D_00C804F0, 0x2000, 12, 0);
    func_104B40(D_00C804B0.id, 0);
}
}
