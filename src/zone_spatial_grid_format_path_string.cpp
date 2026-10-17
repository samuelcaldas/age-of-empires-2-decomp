#pragma exceptions off
#include "zone_spatial_grid_format_path_string.h"

extern "C" {
int func_11ACD0(const char *str);
void *func_1143F8(int count, int elem_size);
char *func_117AF8(char *dst, const char *src);
char *func_117AA0(char *dst, const char *src);
}

struct PathContainer {
    char *path;
};

extern "C" void func_001EB790(void *self_ptr, const char *prefix, const char *suffix) {
    PathContainer *self = (PathContainer *)self_ptr;
    int len1 = func_11ACD0(prefix);
    int len2 = func_11ACD0(suffix);
    char *buf = (char *)func_1143F8(len1 + len2 + 1, 1);
    func_117AF8(buf, prefix);
    func_117AA0(buf, suffix);
    self->path = buf;
}
