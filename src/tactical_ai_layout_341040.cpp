#pragma exceptions off
#include "tactical_ai_layout_341040.h"

extern "C" {
void func_33A730();

typedef void (*VFunc_104)(void *self, int a);
typedef void (*VFunc_36)(void *self, int a, int b, int c, int d);
typedef void (*VFunc_28)(void *self, int a);

void func_00341040(TacticalObj_341040 *self) {
    if (!self) return;

    TacticalSubObj *sub828 = self->field_828;
    if (sub828) {
        ((VFunc_104)(*(void***)sub828)[65])(sub828, 0);
    }

    TacticalSubObj *sub82C = self->field_82C;
    if (sub82C) {
        ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0);
        ((VFunc_36)(*(void***)sub82C)[9])(sub82C, 0, 0, 320, 220);
    }

    TacticalSubObj *sub830 = self->field_830;
    if (sub830) {
        ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
        ((VFunc_36)(*(void***)sub830)[9])(sub830, 29, 172, 114, 26);
        *(int*)((char*)sub830 + 552) = 0;
    }

    TacticalSubObj *sub834 = self->field_834;
    if (sub834) {
        ((VFunc_28)(*(void***)sub834)[7])(sub834, 1);
        *(int*)((char*)sub834 + 552) = 0;
    }

    TacticalSubObj *sub838 = self->field_838;
    if (sub838) {
        ((VFunc_28)(*(void***)sub838)[7])(sub838, 0);
    }

    func_33A730();
    if (self->vtable) {
        ((VFunc_28)(*(void***)self)[7])(self, 1);
    }

    switch (self->field_84C) {
    case 12:
    case 13:
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3be);
        }
        break;
    default:
        break;
    }
}
}
