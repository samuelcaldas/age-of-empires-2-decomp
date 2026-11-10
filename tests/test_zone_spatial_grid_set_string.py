import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_spatial_grid_set_string_native(tmp_path):
    test_src = """
#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_set_string.h"

static int g_free_count = 0;
static int g_alloc_count = 0;

extern "C" {
int func_0011ACD0(const char *str) {
    return std::strlen(str);
}
int func_11ACD0(const char *str) {
    return std::strlen(str);
}
void *func_1143F8(int count, int elem_size) {
    g_alloc_count++;
    return std::malloc(count * elem_size);
}
void func_116F68(void *ptr) {
    g_free_count++;
    std::free(ptr);
}
char *func_117AF8(char *dst, const char *src) {
    return std::strcpy(dst, src);
}
}

struct StringContainer {
    char *str;
};

int main() {
    StringContainer container;
    container.str = 0;

    // Set new string
    func_001EB850(&container, "Hello World");
    assert(container.str != 0);
    assert(std::strcmp(container.str, "Hello World") == 0);
    assert(g_alloc_count == 1);
    assert(g_free_count == 0);

    // Overwrite string
    func_001EB850(&container, "New String");
    assert(container.str != 0);
    assert(std::strcmp(container.str, "New String") == 0);
    assert(g_alloc_count == 2);
    assert(g_free_count == 1);

    // Set NULL -> frees existing string
    func_001EB850(&container, 0);
    assert(container.str == 0);
    assert(g_free_count == 2);

    return 0;
}
"""
    native_cpp = tmp_path / "test.cpp"
    native_cpp.write_text(test_src)
    bin_path = tmp_path / "test_bin"

    cmd = [
        "g++", "-m32", "-O2",
        f"-I{os.path.join(PROJECT_ROOT, 'include')}",
        str(native_cpp),
        os.path.join(PROJECT_ROOT, "src/zone/zone_spatial_grid_set_string.cpp"),
        "-o", str(bin_path)
    ]
    subprocess.run(cmd, check=True)
    subprocess.run([str(bin_path)], check=True)
