#pragma exceptions on

typedef void (*unexpected_handler)(void);

extern "C" {

extern unexpected_handler D_00389B6C[3];

/* 0x00100B70: std::unexpected() */
void func_00100B70(void) {
    D_00389B6C[0]();
}

}
