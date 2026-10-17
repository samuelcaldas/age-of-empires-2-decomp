#ifndef RENDER_MANAGER_STREAM_H
#define RENDER_MANAGER_STREAM_H

class RenderManagerStream {
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
int func_00184ed0(RenderManagerStream *self, void *unused, int open_device_stream);
void *func_00184fb0(void *self, void *parent);
int func_00185000(RenderManagerStream *self);
}

#endif
