#pragma exceptions off

#include "zone_cursor_controller_get_field_30.h"

struct CursorController {
    char pad[0x30];
    int f30;
};

extern "C" int func_001DB670(CursorController *self) {
    return self->f30;
}
