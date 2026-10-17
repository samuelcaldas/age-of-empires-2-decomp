#pragma exceptions off

#include "render_manager_input_translate.h"

extern "C" {
int func_00185160(const EventMsg *event, const InputTableEntry **out_entry) {
    const InputTableEntry *entry = D_00391C30;
    int msg = event->message;

    if (msg == 0x100) {
        if (event->wParam == 0xD && event->lParam == 1) {
            return 0;
        }
    }

    for (unsigned int i = 0; i < 13; i++, entry++) {
        if (entry->id == msg) {
            if (entry->field_8 == 0 || entry->field_8 == event->wParam) {
                *out_entry = entry;
                return 1;
            }
        }
        if (entry->field_4 == msg) {
            if (entry->field_8 == 0 || entry->field_8 == event->wParam) {
                *out_entry = entry;
                return -1;
            }
        }
    }

    *out_entry = 0;
    return 0;
}
}
