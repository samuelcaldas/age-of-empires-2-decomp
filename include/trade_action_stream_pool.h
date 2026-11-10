#ifndef TRADE_ACTION_STREAM_POOL_H
#define TRADE_ACTION_STREAM_POOL_H

#ifdef __cplusplus
extern "C" {
#endif

struct AspPool {
    char nodes[120000];
    void *freelist;
};

void func_00183150(AspPool *pool);
void *func_001831B0(AspPool *pool);
void func_00183210(AspPool *pool, void *item);

#ifdef __cplusplus
}
#endif

#endif // TRADE_ACTION_STREAM_POOL_H
