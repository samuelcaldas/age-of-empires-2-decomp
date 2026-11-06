#include "kt_gs_render_22b890.h"

int s_22b890_ran = 0;

extern "C" {

int func_00227B70(void* a0, void* a1) {
    s_22b890_ran++;
    return 0;
}

void* func_00227CA0(void* a0, void* a1, void* a2, void* a3) {
    s_22b890_ran++;
    return a0;
}

void func_0022B890(void* a0, void* a1, void* a2) {
    func_00227B70(a0, a1);
    func_00227CA0(a0, a1, a2, 0);
}

}
