#pragma exceptions off
#include "zone_spatial_grid_set_string.h"

extern "C" {
int func_11ACD0(const char *str);
void *func_1143F8(int count, int elem_size);
void func_116F68(void *ptr);
char *func_117AF8(char *dst, const char *src);
}

struct StringContainer {
    char *str;
};

extern "C" void func_001EB850(void *self_ptr, const char *new_str) {
    StringContainer *self = (StringContainer *)self_ptr;
    if (self->str != 0) {
        func_116F68(self->str);
        self->str = 0;
    }
    if (new_str != 0) {
        int len = func_11ACD0(new_str) + 1;
        self->str = (char *)func_1143F8(len, 1);
        func_117AF8(self->str, new_str);
    }
}
