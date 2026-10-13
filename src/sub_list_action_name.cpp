#include "sub_list.h"

extern "C" {
    void func_0011ABBC(void *dest, const char *str);
}

extern "C" void func_0013C260(SubList *self, void *param1) {
    switch (self->m_fieldC) {
    case 0:
        func_0011ABBC(param1, "None");
        return;
    case 1:
        func_0011ABBC(param1, "Done");
        break;
    case 2:
        func_0011ABBC(param1, "Wait");
        break;
    case 3:
        func_0011ABBC(param1, "Search");
        break;
    case 4:
        func_0011ABBC(param1, "Goto");
        break;
    case 5:
        func_0011ABBC(param1, "Goto2");
        break;
    case 6:
        func_0011ABBC(param1, "Work");
        break;
    case 7:
        func_0011ABBC(param1, "Work2");
        break;
    case 8:
        func_0011ABBC(param1, "Return");
        break;
    case 9:
        func_0011ABBC(param1, "Turn");
        break;
    case 10:
        func_0011ABBC(param1, "Delay");
        break;
    case 11:
        func_0011ABBC(param1, "Move");
        break;
    case 12:
        func_0011ABBC(param1, "Attack");
        break;
    case 13:
        func_0011ABBC(param1, "Failed");
        break;
    case 14:
        func_0011ABBC(param1, "Invalidated");
        break;
    case 15:
        func_0011ABBC(param1, "MoveNoSearch");
        break;
    default:
        func_0011ABBC(param1, "Unknown");
        break;
    }
}
