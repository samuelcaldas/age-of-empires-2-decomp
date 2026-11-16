#include "common.h"
#include "kt_libpad.h"

extern "C" u32 func_00128850(PadSlot *p) {
    return p->flags = (p->flags | 0x40) ^ 0x40;
}
