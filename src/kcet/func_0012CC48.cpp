struct Dummy {
    int pad;
    int data;
};

extern "C" Dummy* func_0012CC48(Dummy* p) {
    if (p == 0) {
        return 0;
    }
    return (Dummy*)((char*)p + 4);
}
