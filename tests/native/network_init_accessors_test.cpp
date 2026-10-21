#include <cassert>
#include "network_init_3377d0.h"
#include "network_state_set_337820.h"
#include "network_state_get_337830.h"

int D_004E3568;
int D_004E3530;
static int calls;
static int argument;
static int flag_seen_by_call[4];

extern "C" int func_003379F0(int value) {
    argument = value;
    flag_seen_by_call[calls++] = D_004E3568;
    return 0;
}

static void reset() {
    calls = 0;
    argument = -1;
}

int main() {
    // zero: three calls with argument 0, the flag keeps its old value until the loop ends
    reset();
    D_004E3568 = 99;
    func_003377D0(0);
    assert(calls == 3);
    assert(argument == 0);
    assert(flag_seen_by_call[0] == 99 && flag_seen_by_call[2] == 99);
    assert(D_004E3568 == 0);

    // any non-zero value: no calls, value stored as given
    int values[] = {1, 7, -1, 0x7FFFFFFF, (int)0x80000000};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        reset();
        D_004E3568 = 55;
        func_003377D0(values[i]);
        assert(calls == 0);
        assert(D_004E3568 == values[i]);
    }

    // state accessors round-trip the full word and touch nothing else
    D_004E3568 = 11;
    func_00337820(0x12345678);
    assert(D_004E3530 == 0x12345678);
    assert(func_00337830() == 0x12345678);
    func_00337820(-1);
    assert(func_00337830() == -1);
    func_00337820(0);
    assert(func_00337830() == 0);
    assert(D_004E3568 == 11);
    return 0;
}
