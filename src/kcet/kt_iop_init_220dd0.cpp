#pragma exceptions off
#include "kt_iop_init.h"

extern "C" {
int func_388710(const char *img, void *param, int a2, int a3);
int func_388690(void *tbl, int count, void *param, int a3);
void func_111710(void);
void func_102828(void);
void func_103948(int a0);
int func_102688(int a0, int a1, int a2, int a3);
void func_1237E8(void);
int func_123888(int a0, int a1, void *a2, void *a3);
void func_25D060(int a0);
void func_25D320(int a0, int a1);
void func_12D648(void);
void func_1296D8(int a0, int a1);
void func_129FE0(int a0);
void func_129F68(int a0);
void func_12A058(int a0);
void func_12A0E8(int a0);
void func_21BDE0(int a0);
void func_388000(int a0, int a1);

void func_00220DD0(void) {
    func_388710(D_00492EE0, D_00492DE0, 2, 1);
    func_388690(D_00392BF0, 7, D_00492DE0, 2);
    func_111710();
    func_102828();
    func_103948(1);
    func_102688(0, 1, 2, 1);
    func_1237E8();
    func_123888(0, 0x10000, (char *)D_00C82510, (char *)D_00C82510);
    func_123888(1, 0x800, (char *)D_00C92510, (char *)D_00C92510);
}

void func_00220E90(void) {
    func_388690(D_00392C50, 4, D_00492DE0, 2);
    func_388690(D_00392C80, 3, D_00492DE0, 2);
    func_25D060(0x1000);
    func_25D320(0x1E00, 0x7F);
    func_25D320(0x1F00, 0x7F);
    func_25D320(0x1E80, 0x1B);
    func_25D320(0x1F80, 0x1B);
    func_12D648();
    func_25D060(0x100B);
    func_1296D8(0, 1);
    func_129FE0(0);
    func_129F68(1);
    func_12A058(0);
    func_12A0E8(0);
    func_21BDE0(0);
    func_388000(0, 0);
}
}
