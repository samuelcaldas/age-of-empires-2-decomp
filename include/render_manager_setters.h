#ifndef RENDER_MANAGER_SETTERS_H
#define RENDER_MANAGER_SETTERS_H

struct SubObj404 {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void M20() = 0, M21() = 0, M22() = 0, M23() = 0;
    virtual void Method68() = 0;
};

struct RenderManagerSetters {
    char pad_00[0x24];
    void *field_24;
    char pad_28[0x3DC];
    SubObj404 *field_404;
    char pad_408[0x509];
    char field_911[0x7F];
    char field_990;
    unsigned char field_991;
    unsigned char field_992;
    unsigned char field_993;
    unsigned char field_994;
    unsigned char field_995;
    unsigned char field_996;
    unsigned char field_997;
    unsigned char field_998;
    unsigned char field_999;
    unsigned char field_99A;
    unsigned char field_99B;
    unsigned char field_99C;
    unsigned char field_99D[9];
    unsigned char field_9A6;
    unsigned char field_9A7;
    unsigned char field_9A8[9];
    unsigned char field_9B1;
    unsigned char field_9B2;
    char pad_9B3;
    float field_9B4;
    unsigned char field_9B8;
    char pad_9B9[3];
    int field_9BC;
    int field_9C0;
    char pad_9C4[0x694];
    float field_1058;
    char pad_105C[4];
    unsigned char field_1060;
};

extern "C" {
char *func_11B170(char *dst, const char *src, int n);
void func_32F190(void *obj);
void func_32F1C0(void *obj);
void func_3449B0(void *obj);
void func_1884B0(void *self);
void func_1884F0(void *self);
void func_1884C0(void *self);
void func_188500(void *self);

void func_00188260(RenderManagerSetters *self, const char *src);
void func_00188290(RenderManagerSetters *self, int val);
void func_001882a0(RenderManagerSetters *self, int val);
void func_001882b0(RenderManagerSetters *self, unsigned char val);
void func_001882d0(RenderManagerSetters *self, unsigned char val);
void func_001882f0(RenderManagerSetters *self, unsigned char a, unsigned char b, unsigned char c);
void func_00188300(RenderManagerSetters *self, unsigned char val);
void func_00188310(RenderManagerSetters *self, unsigned char val);
void func_00188320(RenderManagerSetters *self, unsigned char val);
void func_00188330(RenderManagerSetters *self, unsigned char val);
void func_00188340(RenderManagerSetters *self, unsigned char val);
void func_00188350(RenderManagerSetters *self, unsigned char val);
void func_00188360(RenderManagerSetters *self);
void func_00188370(RenderManagerSetters *self, int idx, unsigned char val);
void func_00188390(RenderManagerSetters *self, int idx, unsigned char val);
void func_001883b0(RenderManagerSetters *self, int idx, unsigned char val);
void func_001883c0(RenderManagerSetters *self, unsigned char val);
void func_001883d0(RenderManagerSetters *self, int idx, unsigned char val);
void func_001883e0(RenderManagerSetters *self, unsigned char val);
void func_001883f0(RenderManagerSetters *self, unsigned char val);
void func_00188400(RenderManagerSetters *self);
void func_00188430(RenderManagerSetters *self);
void func_00188460(RenderManagerSetters *self);
void func_00188480(RenderManagerSetters *self);
void func_00188490(RenderManagerSetters *self, float val);
void func_001884a0(RenderManagerSetters *self, float val);
void func_001884b0(RenderManagerSetters *self);
void func_001884c0(RenderManagerSetters *self);
float func_001884d0(RenderManagerSetters *self);
float func_001884e0(RenderManagerSetters *self);
void func_001884f0(RenderManagerSetters *self);
void func_00188500(RenderManagerSetters *self);
unsigned char func_00188510(RenderManagerSetters *self);
unsigned char func_00188520(RenderManagerSetters *self);
void func_00188530(RenderManagerSetters *self, int val);
void func_00188560(RenderManagerSetters *self, int val);
}

#endif // RENDER_MANAGER_SETTERS_H
