#pragma exceptions off

#include "render_manager_stream.h"

extern "C" {
int func_3449B0(void *device);
int func_226D40(int stream, void *destination, int size);
void func_226D90(int stream, void *destination, int size);
void *func_116F40(int size);
void func_116F68(void *buffer);
int func_226BF0(int stream);
void *func_100850(int size);
void func_239410(void *context, void *parent, int flag);
int func_3448E0(void *device);

int func_00184ed0(RenderManagerStream *self, void *unused, int open_device_stream) {
    (void)unused;
    // The original leaves this handle undefined for zero; both direct callers pass one.
    int stream;
    if (open_device_stream != 0) stream = func_3449B0(self->device);
    int header, size, trailer;
    func_226D40(stream, &header, 4);
    func_226D40(stream, &size, 4);
    if (size > 0) {
        void *buffer = func_116F40(size);
        if (buffer == 0) {
            func_226BF0(stream);
            return 0;
        }
        func_226D40(stream, buffer, size);
        func_116F68(buffer);
    }
    func_226D90(stream, &trailer, 4);
    int result = self->restore_stream(stream);
    func_226BF0(stream);
    return result;
}

void *func_00184fb0(void *self, void *parent) {
    (void)self;
    void *context;
    if ((context = func_100850(0x19F4)) != 0) func_239410(context, parent, 0);
    return context;
}

int func_00185000(RenderManagerStream *self) {
    void *device = self->device;
    if (device == 0) return 0;
    return func_3448E0(device);
}
}
