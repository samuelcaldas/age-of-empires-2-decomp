#include "network_address_helpers.h"

#pragma optimization_level 1

unsigned int func_00337520(unsigned int value) {
    return ((value >> 24) & 0x000000FFu)
         | ((value >> 8) & 0x0000FF00u)
         | ((value << 8) & 0x00FF0000u)
         | ((value << 24) & 0xFF000000u);
}
