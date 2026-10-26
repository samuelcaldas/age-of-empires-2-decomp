#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001F6E50(int arg0, int arg1, void *buffer, int buf_size);
int func_002195A0(void *self, short arg1, void *buffer, int arg3, int arg4);

int func_002198A0(void *self, short arg1, int arg2, int arg3, int arg4) {
    char buffer[256];
    func_001F6E50(0, arg2, buffer, sizeof(buffer));
    return func_002195A0(self, arg1, buffer, arg3, arg4);
}
}
