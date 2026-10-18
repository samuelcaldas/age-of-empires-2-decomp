#ifndef RENDER_MANAGER_CHAT_INIT_H
#define RENDER_MANAGER_CHAT_INIT_H

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
void *func_117CAC(void *dst, int c, int n);
void func_00189160(ChatLog *self, int idx, int val);

ChatLog *func_00188df0(ChatLog *self, int a1);
}

#endif // RENDER_MANAGER_CHAT_INIT_H
