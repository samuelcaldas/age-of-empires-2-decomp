#include <cstdlib>
#include "unit_action_update_test_support.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_00268500();
        test_func_002683F0();
        test_func_00268410();
        test_func_00268200_dispatch();
        test_func_00268200_transitions();
        test_func_00268200_callbacks();
        return 0;
    }
    switch (std::atoi(argv[1])) {
        case 0: test_func_00268500(); break;
        case 1: test_func_002683F0(); break;
        case 2: test_func_00268410(); break;
        case 3: test_func_00268200_dispatch(); break;
        case 4: test_func_00268200_transitions(); break;
        case 5: test_func_00268200_callbacks(); break;
        default: return 1;
    }
    return 0;
}
