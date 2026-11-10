#pragma exceptions off
#include "unit_action_build_child_iterate.h"

void func_0026F910(ActionRebind *self, int a1, int a2) {
    func_278590(self, a1, a2);

    if ((unsigned char)a2) {
        int i = func_00268530(self) - 1;
        while (i >= 0) {
            ActionRebind *child = func_00268590(self, i);
            if (*(int*)((char*)child->m_world + 2976) == a1) {
                float val = -1.0f;
                func_0026F590(self, child, val, val);
                if (child->m_field1C != 0) {
                    child->Method58();
                    child->v29();
                }
            }
            i--;
        }
    }
}
