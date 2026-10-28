#pragma exceptions off
#include "kt_thread_sema.h"

extern "C" {
int func_104B70(int id);
int func_104B30(int id);
int func_104D20(struct SemaParam *param);
int func_104D90(int id, struct SemaParam *status);
int func_118DE0(const char *fmt, ...);

extern const char D_00492C90[];
extern const char D_00492CC0[];
extern const char D_00492CE0[];
extern const char D_00492D00[];

int func_00220280(int thread_id) {
    int s = func_104B70(thread_id);
    if (s != thread_id) {
        func_118DE0(D_00492C90, thread_id);
    }
    int d = func_104B30(thread_id);
    if (d != thread_id) {
        func_118DE0(D_00492CC0, thread_id);
    } else {
        func_118DE0(D_00492CE0, thread_id);
    }
    return thread_id;
}

int func_00220300(struct SemaContainer *sema, int max_count, int init_count, int option) {
    sema->param.max_count = max_count;
    sema->param.init_count = init_count;
    sema->param.option = option;
    int id = func_104D20(&sema->param);
    sema->id = id;
    struct SemaParam status;
    func_104D90(id, &status);
    func_118DE0(D_00492D00, id, status.current_count, status.max_count, status.init_count, status.wait_threads, status.attr);
    return id;
}
}
