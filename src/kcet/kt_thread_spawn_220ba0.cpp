#pragma exceptions off
#include "kt_thread_spawn_220ba0.h"

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option);
int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option);
int func_104B40(int thread_id, void *arg);
void func_220C10(void);

void func_00220BA0(void) {
    func_220300(&D_00C80490, 1, 0, 0);
    func_220380((struct ThreadContainer *)((char *)&D_00C7F450), (void *)func_220C10, D_00C7F490, 0x1000, 11, 0);
    func_104B40(D_00C7F450.id, 0);
}
}
