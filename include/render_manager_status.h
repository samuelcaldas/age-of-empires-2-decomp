#ifndef RENDER_MANAGER_STATUS_H
#define RENDER_MANAGER_STATUS_H

class LanguageManager {
public:
    virtual void M0() = 0;
    virtual void M1() = 0;
    virtual void M2() = 0;
    virtual void M3() = 0;
    virtual void M4() = 0;
    virtual void M5() = 0;
    virtual void M6() = 0;
    virtual void M7() = 0;
    virtual char *GetString(int id, char *dest, int max_len) = 0;
};

struct RenderManagerStatus {
    char pad_00[0x10C8];
    unsigned int field_10C8;
    char pad_10CC[0x534];
    void *field_1600;
    char pad_1604[0xA34];
    unsigned int field_2038[1];
};

extern "C" {
extern LanguageManager *D_004E3180;
extern char D_00568560[32];
extern const char D_00491BA8[];

int func_191050(void *self, int a1);
int func_190FF0(void *self, int a1);
int func_11A498(char *dst, const char *fmt, ...);
void func_19A1E0(void *p, int a1);
void func_19A1D0(void *p, int a1);
void func_19A1F0(void *p);

char *func_00189c80(RenderManagerStatus *self, int a1);
void func_00189e00(RenderManagerStatus *self, int a1);
void func_00189e40(RenderManagerStatus *self);
void func_00189e50();
void func_00189e60();
}

#endif
