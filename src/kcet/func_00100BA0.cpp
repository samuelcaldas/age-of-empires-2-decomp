#pragma exceptions on

typedef void (*terminate_handler)(void);

extern "C" {

extern terminate_handler D_00389B68[3];

/* 0x00100BA0: std::terminate() */
void func_00100BA0(void) {
    D_00389B68[0]();
}

}
