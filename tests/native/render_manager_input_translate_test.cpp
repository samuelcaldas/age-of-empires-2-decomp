#include "render_manager_input_translate.h"
#include <cassert>
#include <cstdlib>

const InputTableEntry D_00391C30[13] = {
    {0x0509, 0x0515, 0x0000},
    {0x0508, 0x0514, 0x0000},
    {0x050a, 0x0517, 0x0000},
    {0x050b, 0x0516, 0x0000},
    {0x0201, 0x0202, 0x0000},
    {0x0203, 0x0000, 0x0000},
    {0x0207, 0x0208, 0x0000},
    {0x0209, 0x0000, 0x0000},
    {0x0204, 0x0205, 0x0000},
    {0x0206, 0x0000, 0x0000},
    {0x0100, 0x0101, 0x000d},
    {0x0100, 0x0101, 0x001b},
    {0x0100, 0x0101, 0x0020},
};

static void test_ignored_return_key() {
    EventMsg ev = {{0}, 0x100, 0x0D, 1};
    const InputTableEntry *out = (const InputTableEntry *)0x1234;
    int res = func_00185160(&ev, &out);
    assert(res == 0 && out == (const InputTableEntry *)0x1234);
}

static void test_primary_match() {
    EventMsg ev = {{0}, 0x0509, 0, 0};
    const InputTableEntry *out = 0;
    int res = func_00185160(&ev, &out);
    assert(res == 1 && out == &D_00391C30[0]);
}

static void test_primary_with_param() {
    EventMsg ev = {{0}, 0x0100, 0x1B, 0};
    const InputTableEntry *out = 0;
    int res = func_00185160(&ev, &out);
    assert(res == 1 && out == &D_00391C30[11]);
}

static void test_secondary_match() {
    EventMsg ev = {{0}, 0x0515, 0, 0};
    const InputTableEntry *out = 0;
    int res = func_00185160(&ev, &out);
    assert(res == -1 && out == &D_00391C30[0]);
}

static void test_secondary_with_param() {
    EventMsg ev = {{0}, 0x0101, 0x20, 0};
    const InputTableEntry *out = 0;
    int res = func_00185160(&ev, &out);
    assert(res == -1 && out == &D_00391C30[12]);
}

static void test_no_match() {
    EventMsg ev = {{0}, 0x9999, 0, 0};
    const InputTableEntry *out = (const InputTableEntry *)0x1234;
    int res = func_00185160(&ev, &out);
    assert(res == 0 && out == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_ignored_return_key(); return 0;
    case 1: test_primary_match(); return 0;
    case 2: test_primary_with_param(); return 0;
    case 3: test_secondary_match(); return 0;
    case 4: test_secondary_with_param(); return 0;
    case 5: test_no_match(); return 0;
    default: return 1;
    }
}
