#include "render_manager_status_test_support.h"
#include <cstdlib>

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_status_4b1_precedence(); return 0;
    case 1: test_status_4b2_precedence(); return 0;
    case 2: test_status_value_zero(); return 0;
    case 3: test_status_value_three(); return 0;
    case 4: test_status_value_four(); return 0;
    case 5: test_status_below_threshold(); return 0;
    case 6: test_status_equal_threshold(); return 0;
    case 7: test_status_above_threshold(); return 0;
    case 8: test_status_unsigned_high_value(); return 0;
    case 9: test_status_unsigned_high_threshold(); return 0;
    case 10: test_status_string_contract_and_shared_buffer(); return 0;
    case 11: test_status_dispatch_order_and_arguments(); return 0;
    case 12: test_status_dispatch_reloads_field_1600(); return 0;
    case 13: test_status_dispatch_forwards_null_field(); return 0;
    case 14: test_status_empty_stubs(); return 0;
    default: return 1;
    }
}
