#include "network_address_helpers.h"

unsigned int func_00337520(unsigned int value) {
    return (value >> 24) | ((value >> 8) & 0x0000FF00u)
        | ((value << 8) & 0x00FF0000u) | (value << 24);
}
