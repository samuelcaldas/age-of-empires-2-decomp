#include "network_address_helpers.h"

#pragma optimization_level 1

unsigned int func_00337560(unsigned int value) {
    value &= 0xFFFFu;
    return ((((int)value >> 8) & 0x00FFu) | ((value << 8) & 0xFF00u)) & 0xFFFFu;
}
