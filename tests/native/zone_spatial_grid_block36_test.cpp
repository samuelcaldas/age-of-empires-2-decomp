#include <cassert>
#include <cstring>
#include "zone_spatial_grid_deserialize_child_polymorphic.h"
#include "zone_spatial_grid_format_path_string.h"
#include "zone_spatial_grid_set_string.h"
#include "zone_spatial_grid_reset_scratch_counter.h"
#include "zone_spatial_grid_alloc_scratch_bytes.h"
#include "zone_spatial_grid_init_entry_header.h"

extern "C" {
int D_008B0AD0 = 0;
int D_0093EBF0[1024];
int func_11ACD0(const char *str) { return strlen(str); }
void *func_1143F8(int count, int elem_size) { return new char[count * elem_size]; }
void func_116F68(void *ptr) { delete[] (char *)ptr; }
char *func_117AF8(char *dst, const char *src) { return strcpy(dst, src); }
char *func_117AA0(char *dst, const char *src) { return strcat(dst, src); }
}

int main() {
    func_001EB8D0();
    assert(D_008B0AD0 == 0);

    void *ptr = func_001EB8E0(10);
    assert(D_008B0AD0 == 10);
    assert(ptr == &D_0093EBF0[0]);

    struct DummyHeader {
        int id;
        short val1;
        short val2;
        char flag;
    } header;
    header.id = 5;
    header.val1 = 2;
    header.val2 = 3;
    header.flag = 1;

    void *res = func_001EB900(&header);
    assert(res == &header);
    assert(header.id == 0);
    assert(header.val1 == 0);
    assert(header.val2 == 0);
    assert(header.flag == 0);

    struct DummyStr {
        char *str;
    } str_cont = { nullptr };

    func_001EB850(&str_cont, "test_string");
    assert(str_cont.str != nullptr);
    assert(strcmp(str_cont.str, "test_string") == 0);
    func_001EB850(&str_cont, nullptr);
    assert(str_cont.str == nullptr);

    return 0;
}
