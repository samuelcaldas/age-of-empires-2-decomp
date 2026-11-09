#pragma exceptions off

typedef void (*InitFunc)(void);

extern "C" {

extern InitFunc D_004D7150[];
extern InitFunc D_004D71C4[];
extern char D_004E27C0[];

void func_00100C50(InitFunc *start, InitFunc *end, void *seg_start, void *seg_end);

void func_001001C0(void) {
    func_00100C50(D_004D7150, D_004D71C4, D_004E27C0, D_004E27C0);
}

}
