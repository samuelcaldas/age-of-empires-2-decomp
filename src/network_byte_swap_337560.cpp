#include "network_address_helpers.h"

unsigned int func_00337560(unsigned int value) {
    value &= 0xFFFFu;
    return ((value >> 8) & 0xFFu) | ((value << 8) & 0xFF00u);
}
