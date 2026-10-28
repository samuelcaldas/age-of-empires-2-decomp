#pragma exceptions off
#include "kt_game_main.h"

extern "C" {
void func_2215D0(void);
void func_1001C0(void);
int func_104C10(void);
int func_104BB0(int id, int prio);
void func_220DD0(void);
void func_21EA10(void);
void func_36AC20(void);
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option);
int func_2205E0(void *arg);
int func_104D60(int sema_id);
int func_220280(int thread_id);
void func_111710(void);
void func_102828(void);
void func_103948(int a0);

void func_00220530(void) {
    func_2215D0();
    func_1001C0();
    func_104BB0(func_104C10(), 10);
    func_220DD0();
    func_21EA10();
    func_36AC20();
    func_220300(&D_00C5F330, 1, 0, 0);
    while (1) {
        func_2205E0((void *)func_104C10());
        func_104D60(D_00C5F330.id);
        func_220280(D_00C5F350.id);
        func_111710();
        func_102828();
        func_103948(1);
    }
}
}
