#ifndef RENDER_MANAGER_CHAT_METHODS_H
#define RENDER_MANAGER_CHAT_METHODS_H

struct ChatLog {
    int field_0;
    int field_4[10];
    int field_2C[10];
    void *field_54[51];
    int field_120;
    int field_124;
    int field_128;
};

extern "C" {
void func_116F68(void *ptr);

void *func_001890a0(ChatLog *self, int idx);
void func_001890e0(ChatLog *self);
void func_00189150(ChatLog *self, int val);
void func_00189160(ChatLog *self, int idx, int val);
int func_00189190(ChatLog *self, int idx);
int func_001891d0(ChatLog *self, int idx);
void func_00189210();
int func_00189220();
int func_00189230(ChatLog *self);
int func_00189240();
int func_00189250(ChatLog *self);
}

#endif // RENDER_MANAGER_CHAT_METHODS_H
