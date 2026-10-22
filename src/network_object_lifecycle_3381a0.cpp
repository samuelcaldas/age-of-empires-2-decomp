#include "network_object_lifecycle_3380e0.h"
extern "C" {
void *func_00117CAC(void *, int, unsigned int);
void func_00338180(void *);
}
void func_003381A0(void *object) {
    unsigned char *bytes = (unsigned char *)object;
    func_00117CAC(bytes + 4, 0, 1088);
    func_00117CAC(bytes + 1092, 0, 216);
    func_00117CAC(bytes + 1324, 0, 2048);
    bytes[4412] = 0;
    *(int *)(bytes + 4540) = 0;
    *(int *)(bytes + 4544) = 0;
    *(int *)(bytes + 1312) = 0;
    *(int *)bytes = 0;
    *(int *)(bytes + 3372) = 0;
    *(int *)(bytes + 4552) = 0;
    *(int *)(bytes + 1316) = 1;
    bytes[4560] = 0;
    *(int *)(bytes + 3376) = 0;
    *(int *)(bytes + 3384) = 0;
    *(volatile int *)(bytes + 3380) = 0;
    func_00338180(object);
    *(int *)(bytes + 4556) = 0;
}
