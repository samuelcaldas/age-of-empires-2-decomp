#pragma exceptions off
#include "memory_card_dialog.h"
#include "memory_card_screen.h"

extern "C" {
void func_20BAF0(void *self, const void *res);
void func_1F6DF0(void *self);
void func_1F7B70(void *self, int a);
void func_1F8B70(void *self, int a, int b);
void func_1F8B80(void *self, int a);
void func_215A00(void *self, int a, const char *res, int c, int d);

extern const void *D_4DF3F0;
extern const char D_4D54F0[];
}

extern "C" {

void func_00340490(MemoryCardDialog *self, MemoryCardScreen *screen, int a2, int mode) {
    func_20BAF0(self, (void*)D_4D54F0);
    self->vtable = (TacticalSubObj*)&D_4DF3F0;
    self->pad_848[0] = ((char*)screen)[124];
    ((char*)screen)[124] = 1;
    ((char*)self)[124] = 1;
    self->field_844 = screen;
    self->field_828 = 0;
    self->field_82C = 0;
    self->field_830 = 0;
    self->field_834 = 0;
    self->field_838 = 0;
    self->field_83C = a2;
    self->field_840 = mode;
    self->field_84C = -1;
    self->field_854 = 0;
    func_1F6DF0(self);
}

}
