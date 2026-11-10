#pragma exceptions off

extern "C" {
int func_0021E350(int val) {
    int base = 0x7C000;
    base += (val & 0x1F0) << 4;
    return base;
}
}
