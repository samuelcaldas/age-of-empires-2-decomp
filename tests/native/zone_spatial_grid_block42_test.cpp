#include <cassert>
#include <cstring>
#include "zone_spatial_grid_buffer_manager_remove.h"
#include "zone_spatial_grid_buffer_manager_sync_tables.h"
#include "zone_spatial_grid_single_list_init.h"
#include "zone_spatial_grid_single_list_destructor.h"
#include "zone_spatial_grid_single_list_prepend.h"

extern "C" {
void func_100670(void *ptr) {}
void func_116F68(void *ptr) { delete[] (char *)ptr; }
void *func_1143F8(int count, int elem_size) { return new char[count * elem_size]; }
int func_332E60(void *p0, short p1) { return 0; }
int func_1EBA00(void *p0) { return 0; }
int func_202B10(void *p0) { return 0; }
void func_1ECD00(void *p0, void *p1) {}
}

int main() {
    // 1. Single list init & prepend
    struct SingleList {
        void *head;
    } list;
    func_001ECFD0(&list);
    assert(list.head == nullptr);

    void *elem1 = (void *)0x1111;
    void *elem2 = (void *)0x2222;
    void *node1 = func_001ED060(&list, elem1, 1, 10.0f, 20.0f);
    assert(node1 != nullptr);
    assert(list.head == node1);

    void *node2 = func_001ED060(&list, elem2, 2, 30.0f, 40.0f);
    assert(node2 != nullptr);
    assert(list.head == node2);

    func_001ECFE0(&list, 0);

    // 2. Buffer manager remove
    struct SpatialGridBufferManager {
        void *buffer;
        void *items[200];
        int table_324[200];
        int table_644[200];
        short cap;
        short count;
    } mgr;
    mgr.count = 2;
    mgr.cap = 200;
    mgr.items[0] = elem1;
    mgr.items[1] = elem2;
    mgr.table_324[0] = 10;
    mgr.table_324[1] = 20;
    mgr.table_644[0] = 100;
    mgr.table_644[1] = 200;

    int res = func_001ECD10(&mgr, elem1);
    assert(res == 1);
    assert(mgr.count == 1);
    assert(mgr.items[0] == elem2);
    assert(mgr.table_324[0] == 20);
    assert(mgr.table_644[0] == 200);

    int not_found = func_001ECD10(&mgr, (void *)0x9999);
    assert(not_found == 0);
    assert(mgr.count == 1);

    return 0;
}
