#pragma once

#include "tactical_ai_layout_341040.h"

class MemoryCardDialog;

class MemoryCardScreen {
public:
    TacticalSubObj *vtable;           // 0x000: vtable at 0x4DEF10 ("scr_sl")
    char pad_4[8];                    // 0x004
    int field_C;                      // 0x00C: X coordinate
    int field_10;                     // 0x010: Y coordinate
    char pad_14[0x7F0];               // 0x014 to 0x804
    int field_804;                    // 0x804: action code / state dispatcher (states 1-12)
    int field_808;                    // 0x808: mode (0=load, 1=save, etc.)
    int field_80C;                    // 0x80C: tick counter / enabled flag (>0 active)
    int field_810;                    // 0x810
    int field_814;                    // 0x814
    TacticalSubObj *field_818;        // 0x818: card status label (0xC3BD + 0xC3E3/0xC3E2)
    int field_81C;                    // 0x81C
    TacticalSubObj *field_820;        // 0x820: base UI panel container
    TacticalSubObj *field_824;        // 0x824: save slots list table (0x340090)
    TacticalSubObj *field_828;        // 0x828
    TacticalSubObj *field_82C;        // 0x82C: Cancel / Back button (hotkey 0x1B / Triangle / ESC)
    TacticalSubObj *field_830;        // 0x830: Load / Save action button (0x23FE / 0x240F)
    TacticalSubObj *field_834;        // 0x834
    TacticalSubObj *field_838;        // 0x838
    int field_83C;                    // 0x83C
    int field_840;                    // 0x840
    int field_844;                    // 0x844
    int field_848;                    // 0x848: slot count / selected slot index
    char pad_84C[0x54];               // 0x84C to 0x8A0
    MemoryCardDialog *field_8A0;      // 0x8A0: owned child dialog (MemoryCardDialog)
};

extern "C" {
void func_0033DAF0(MemoryCardScreen *self, int mode);
int func_0033E590(MemoryCardScreen *self, void *control, int action, int a3, int a4);
void func_0033E7B0(MemoryCardScreen *self);
void func_0033EA30(MemoryCardScreen *self);
int func_0033EC50(MemoryCardScreen *self);
void func_0033EC70(MemoryCardScreen *self, int a1);
void func_0033ECE0(MemoryCardScreen *self);
int func_0033F280(MemoryCardScreen *self, int has_card);
void func_0033F480(MemoryCardScreen *self);
void func_0033F540(MemoryCardScreen *self);
void func_0033F660(MemoryCardScreen *self);
}
