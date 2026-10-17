#include <cassert>
#include <cstring>
#include "zone_spatial_grid_vector_destructor.h"
#include "zone_spatial_grid_vector_init.h"
#include "zone_spatial_grid_vector_reset.h"
#include "zone_spatial_grid_vector_is_full.h"
#include "zone_spatial_grid_vector_clear.h"
#include "zone_spatial_grid_vector_push_back.h"
#include "zone_spatial_grid_vector_swap_remove.h"

extern "C" {
void func_1EB9C0(void *self) {}
void func_100670(void *ptr) {}
void *func_1EB8D0(int cap) { return new int[cap]; }
void *func_117CAC(void *dst, int val, unsigned int size) { return memset(dst, val, size); }
void func_1EBA20(void *self) {}
void func_367470(void *elem) {}
int func_1EBA00(void *self) { return 1; }
}

int main() {
    struct FastVector {
        void *buffer;
        short count;
        short cap;
        char flag;
    } vec;
    vec.count = 5;
    vec.cap = 10;
    assert(func_001EBA10(&vec) == 0);
    vec.count = 10;
    assert(func_001EBA10(&vec) == 1);
    return 0;
}
