#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_1143C0(void *ptr, int size);
int func_0021AE90(void *self, const int *local_rect, void *arg3, const int *rect_t0, int arg5, int zero);
void func_0021ACD0(void *arg0, void *self);
void func_0021AD70(void *self);
int func_0021A960(void *self, const int *local_rect, void *arg3, const int *rect_t0, int arg5, void *buffer);

int func_0021A850(void *self, int x, int y, void *arg3, const int *rect_t0, int arg5) {
    char *self_bytes = (char *)self;
    char buffer[100];
    func_1143C0(buffer, sizeof(buffer));

    int local_rect[4];
    local_rect[0] = x;
    local_rect[1] = y;
    local_rect[2] = x + (rect_t0[2] - rect_t0[0]);
    local_rect[3] = y + (rect_t0[3] - rect_t0[1]);

    unsigned int flags = *(unsigned int *)(self_bytes + 0x98);
    if ((flags & 0x800) != 0) {
        return func_0021AE90(self, local_rect, arg3, rect_t0, arg5, 0);
    }

    if (arg3 != 0) {
        func_0021ACD0(arg3, self);
    }
    func_0021AD70(self);

    return func_0021A960(self, local_rect, arg3, rect_t0, arg5, buffer);
}
}
