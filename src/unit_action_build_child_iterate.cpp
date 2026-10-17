#pragma exceptions off
#include "unit_action_build_child_iterate.h"

void func_0026F910(ActionRebind *self, int a1, int a2) {
    func_278590(self, a1, a2);

    if ((unsigned char)a2) {
        int i = func_00268530(self) - 1;
        while (i >= 0) {
            ActionRebind *child = func_00268590(self, i);
            if (*(int*)((char*)child->m_world + 2976) == a1) {
                func_0026F590(self, child, -1.0f, -1.0f);
                if (*(int*)((char*)child + 28) != 0) {
                    typedef void (*MethodFn)(void *c);
                    MethodFn m58 = *(MethodFn*)(*(char**)child + 232);
                    m58(child);
                    MethodFn m31 = *(MethodFn*)(*(char**)child + 124);
                    m31(child);
                }
            }
            i--;
        }
    }
}
