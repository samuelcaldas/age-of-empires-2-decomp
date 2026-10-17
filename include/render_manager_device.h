#ifndef RENDER_MANAGER_DEVICE_H
#define RENDER_MANAGER_DEVICE_H

class RenderManagerDevice {
public:
    virtual void reserved_00();
    virtual void reserved_01();
    virtual void reserved_02();
    virtual void reserved_03();
    virtual void reserved_04();
    virtual void reserved_05();
    virtual void reserved_06();
    virtual void reserved_07();
    virtual void reserved_08();
    virtual void reserved_09();
    virtual void reserved_10();
    virtual void reserved_11();
    virtual void reserved_12();
    virtual void reserved_13();
    virtual int restore_stream(int stream);
    char reserved_data_04[0x20];
    void *device;
};

extern "C" {
void func_00185030(RenderManagerDevice *self);
void func_00185060(RenderManagerDevice *self, int *out1, int *out2, int *out3);
int func_001850d0(RenderManagerDevice *self, int unused, int arg2, int arg3);
int func_00185150(RenderManagerDevice *self);
}

#endif
