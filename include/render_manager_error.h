#ifndef RENDER_MANAGER_ERROR_H
#define RENDER_MANAGER_ERROR_H

class RenderManagerError {
public:
    void *device;
    int error_code;

    RenderManagerError(void *dev);
    ~RenderManagerError();
    int format_error(int res_id, int arg);
    void translate_error(int hr);
};

extern "C" {
int func_2265E0(void *device, int capacity, int res_id, int arg);
void func_100670(void *ptr);

RenderManagerError *func_00189830(RenderManagerError *self, void *device);
int func_00189840(RenderManagerError *self, int res_id, int arg);
RenderManagerError *func_00189860(RenderManagerError *self, int flags);
void func_001898b0(RenderManagerError *self, int hr);
}

#endif
