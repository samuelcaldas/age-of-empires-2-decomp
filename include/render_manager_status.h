#ifndef RENDER_MANAGER_STATUS_H
#define RENDER_MANAGER_STATUS_H

class ErrorManager {
public:
    virtual void dummy0() {}
    virtual void dummy1() {}
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void dummy5() {}
    virtual void dummy6() {}
    virtual void dummy7() {}
    virtual void LogError(int line, char *buf, int size) = 0;
};

extern "C" {
extern ErrorManager *D_004E3180;
extern char D_568560[];
extern const char D_491BA8[];

int func_00191050(void *self, int arg1);
int func_00190FF0(void *self, int arg1);
int func_11A498(char *dst, const char *fmt, ...);

const char *func_00189c80(void *self, int arg1);
}

#endif
