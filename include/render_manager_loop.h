#ifndef RENDER_MANAGER_LOOP_H
#define RENDER_MANAGER_LOOP_H

struct MSG {
    void *hwnd;
    int message;
    int wParam;
    int lParam;
    int time;
    int pt_x;
    int pt_y;
};

struct InputTableEntry {
    int id;
    int field_4;
    int field_8;
};

class RenderManagerLoop {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual int PreTranslateMessage(MSG *msg);
    virtual void OnIdle();
    char pad_04[0x18];
    int field_1C;
    char pad_20[0x10];
};

extern const MSG D_00391CD0;
extern int D_004E89C4;
extern const InputTableEntry *D_004E89C8;

extern "C" {
int func_2265D0(MSG *msg, void *hwnd, int min, int max, int remove);
void func_226620(MSG *msg);
void func_226630(MSG *msg);
int func_185160(const MSG *event, const InputTableEntry **out_entry);
void func_388010();

int func_00185230(RenderManagerLoop *self);
}

#endif
