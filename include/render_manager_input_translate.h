#ifndef RENDER_MANAGER_INPUT_TRANSLATE_H
#define RENDER_MANAGER_INPUT_TRANSLATE_H

struct InputTableEntry {
    int id;
    int field_4;
    int field_8;
};

struct EventMsg {
    char pad_0[4];
    int message;
    int wParam;
    int lParam;
};

extern const InputTableEntry D_00391C30[13];

extern "C" {
int func_00185160(const EventMsg *event, const InputTableEntry **out_entry);
}

#endif
