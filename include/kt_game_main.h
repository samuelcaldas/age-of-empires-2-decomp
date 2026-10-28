#ifndef KT_GAME_MAIN_H
#define KT_GAME_MAIN_H

#include "kt_thread_sema.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ThreadContainer {
    int id;
    char unk[0x38];
};

extern struct SemaContainer D_00C5F330;
extern struct ThreadContainer D_00C5F350;

void func_00220530(void);

#ifdef __cplusplus
}
#endif

#endif // KT_GAME_MAIN_H
