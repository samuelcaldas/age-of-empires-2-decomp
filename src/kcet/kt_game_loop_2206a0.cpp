#pragma exceptions off
#include "kt_game_loop.h"

extern "C" {
void func_220940(void);
void func_220BA0(void);
void func_220C60(void);
void func_221110(void);
void func_221410(void);
void func_103358(int a0);
void func_2208F0(void);
void func_222190(void);
void func_2263A0(int a0);
int func_2204D0(int id);
int func_104D40(int id);
int func_104D60(int id);
int func_226260(void);
int func_2204E0(int id);
void func_2207B0(void);
void func_221790(void);
void func_3379F0(int a0);
void func_221F40(void);
void func_36F800(int a0);
void func_221C00(void);
void func_224A10(void);

void func_002206A0(void) {
    func_220940();
    func_220BA0();
    func_220C60();
    func_221110();
    func_221410();
    func_103358(0);
    func_2208F0();
    func_222190();
    func_2263A0(1);

    while (1) {
        func_2204D0(D_00C6F390);
        func_104D40(D_00C6F3B0);
        func_104D60(D_00C6F390);

        *(volatile int *)0x10000000 = 0;
        D_00CA1550 = D_00CA1550 + 1;
        D_00CA1560 = D_00CA1560 + 1;
        func_226260();

        while (func_2204E0(D_00C6F3D0) == 0) {}

        func_2207B0();
        func_104D40(D_00C6F3D0);
        func_221790();
        func_3379F0(0);
        func_221F40();
        func_3379F0(0);
        func_36F800(0);
        func_221C00();
        func_224A10();
    }
}
}
