#include "network_object_lifecycle_3380e0.h"
extern "C" void func_003381A0(void *);
void *func_00338230(void *object) {
    *(int *)((unsigned char *)object + 1308) = 0;
    func_003381A0(object);
    return object;
}
