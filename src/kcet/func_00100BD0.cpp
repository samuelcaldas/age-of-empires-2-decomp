#pragma exceptions on

typedef void (*terminate_handler)(void);

extern "C" {

extern terminate_handler D_00389B68[3];

void func_00100BD0(void) {
    D_00389B68[0]();
}

}
