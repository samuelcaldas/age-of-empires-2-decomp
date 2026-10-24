#pragma exceptions off

#include "render_manager_query_dispatch.h"

extern "C" {
int func_00186dc0(RenderManagerQueryDispatch *self, int a1, int a2, int a3, int a4) {
    (void)a1;
    (void)a2;
    return (self->MethodFC(a3, a4) != 0) ? 1 : 0;
}

int func_00186e00() {
    return 1;
}

int func_00186e10(RenderManagerQueryDispatch *self) {
    return (self->Method100() != 0) ? 1 : 0;
}

int func_00186e40() {
    return 1;
}
}
