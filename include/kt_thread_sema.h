#ifndef KT_THREAD_SEMA_H
#define KT_THREAD_SEMA_H

#ifdef __cplusplus
extern "C" {
#endif

struct SemaParam {
    int current_count;
    int max_count;
    int init_count;
    int wait_threads;
    int attr;
    int option;
};

struct SemaContainer {
    int id;
    struct SemaParam param;
};

int func_00220280(int thread_id);
int func_00220300(struct SemaContainer *sema, int max_count, int init_count, int option);

#ifdef __cplusplus
}
#endif

#endif // KT_THREAD_SEMA_H
