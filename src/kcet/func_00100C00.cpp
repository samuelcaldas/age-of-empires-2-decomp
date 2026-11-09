#pragma exceptions on

extern "C" {

// 0x001142E8: abort()
void func_001142E8(void);

/* 0x00100C00: std::dthandler() - default terminate handler, calls abort() */
void func_00100C00(void) {
    func_001142E8();
}

}
