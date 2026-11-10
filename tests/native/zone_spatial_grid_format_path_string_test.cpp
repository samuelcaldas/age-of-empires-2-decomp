#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_format_path_string.h"

static int g_1143f8_called = 0;
static char g_mock_heap[256];

extern "C" {
int func_11ACD0(const char *str) {
    return (int)strlen(str);
}

void* func_1143F8(int count, int elem_size) {
    g_1143f8_called++;
    memset(g_mock_heap, 0, sizeof(g_mock_heap));
    return g_mock_heap;
}

char* func_117AF8(char *dst, const char *src) {
    return strcpy(dst, src);
}

char* func_117AA0(char *dst, const char *src) {
    return strcat(dst, src);
}
}

#include "../../src/zone/zone_spatial_grid_format_path_string.cpp"

int main() {
    PathContainer container;
    container.path = NULL;

    func_001EB790(&container, "path/to/", "file.txt");

    assert(g_1143f8_called == 1);
    assert(container.path == g_mock_heap);
    assert(strcmp(container.path, "path/to/file.txt") == 0);

    printf("zone_spatial_grid_format_path_string_test passed\n");
    return 0;
}
