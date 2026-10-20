#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_destructor.h"
#include "zone_spatial_grid_block63_layout.h"

static SpatialGridLayout grid;
static ListNodeLayout nodes[3];
static void *wrappers[3][1];
static void *replacement_wrapper[1];
static bool replace_head;
static bool replace_element;
static std::vector<void *> released;
static std::vector<int> operations;

typedef void (*DestroyCallback)(void *, int);
struct ItemLayout { DestroyCallback *vtable; };
static ItemLayout item;

extern "C" {
void *D_004D9AD0[16] = {0};
}

extern "C" void func_001F34D0(ZoneSpatialGrid *self) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(&grid));
    assert(grid.vtable == D_004D9AD0);
    operations.push_back(1);
}

extern "C" void func_00116F68(void *pointer) {
    released.push_back(pointer);
    operations.push_back(3);
    if (replace_head && pointer == wrappers[2]) grid.head = &nodes[2];
}

extern "C" void func_0021B430(void *) {
    assert(false && "The list fixture has no allocated table entries");
}

extern "C" void func_001F32F0(ZoneSpatialGrid *self) {
    assert(self == reinterpret_cast<ZoneSpatialGrid *>(&grid));
    assert(grid.head == 0);
    operations.push_back(4);
}

extern "C" void func_100670(void *) {
    assert(false && "A zero flag must not delete the grid");
}

static void destroy_item(void *pointer, int /*flag*/) {
    assert(pointer == &item);
    operations.push_back(2);
    if (replace_element) nodes[0].element = replacement_wrapper;
}

static void unused_slot(void *, int) {
    assert(false && "Unexpected virtual slot");
}

// Slot 1 is Itanium ABI deleting destructor; slot 2 is MWCC PS2 deleting destructor.
static DestroyCallback item_vtable[] = {destroy_item, destroy_item, destroy_item};

static void initialize(unsigned count) {
    std::memset(&grid, 0, sizeof(grid));
    std::memset(wrappers, 0, sizeof(wrappers));
    for (unsigned index = 0; index <= count; ++index) {
        nodes[index].element = wrappers[index];
        nodes[index].next = &nodes[(index + 1) % (count + 1)];
    }
    grid.head = nodes;
    item.vtable = item_vtable;
    replace_head = false;
    replace_element = false;
    released.clear();
    operations.clear();
}

static void run_destructor() {
    ZoneSpatialGrid *pointer = reinterpret_cast<ZoneSpatialGrid *>(&grid);
    assert(func_001F2590(pointer, 0) == pointer);
    assert(grid.head == 0);
}

static void test_traversal(unsigned count) {
    initialize(count);
    run_destructor();
    std::vector<void *> expected;
    if (count == 2) expected.push_back(wrappers[2]);
    if (count != 0) expected.push_back(wrappers[0]);
    expected.push_back(nodes);
    assert(released == expected);
    assert(operations.front() == 1);
    assert(operations.back() == 4);
}

static void test_head_reload() {
    initialize(2);
    replace_head = true;
    run_destructor();
    std::vector<void *> expected;
    expected.push_back(wrappers[2]);
    expected.push_back(&nodes[2]);
    assert(released == expected);
}

static void test_element_reload() {
    initialize(1);
    wrappers[0][0] = &item;
    replace_element = true;
    run_destructor();
    std::vector<void *> expected;
    expected.push_back(replacement_wrapper);
    expected.push_back(nodes);
    assert(released == expected);
    const int expected_operations[] = {1, 2, 3, 3, 4};
    assert(operations == std::vector<int>(expected_operations, expected_operations + 5));
}

int main(int argc, char **argv) {
    assert(argc == 2);
    assert(sizeof(ListNodeLayout) == 12);
    assert(offsetof(ListNodeLayout, element) == 4);
    assert(offsetof(ListNodeLayout, next) == 8);
    if (std::strcmp(argv[1], "head-reload") == 0) {
        test_head_reload();
        return 0;
    }
    if (std::strcmp(argv[1], "element-reload") == 0) {
        test_element_reload();
        return 0;
    }
    test_traversal(static_cast<unsigned>(std::strtoul(argv[1], 0, 0)));
    return 0;
}
