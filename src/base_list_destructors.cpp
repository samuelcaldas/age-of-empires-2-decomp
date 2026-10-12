extern "C" {
void func_2639D0(void*, int);
void __vec_ctor(void*);
extern char D_4D7A90[];
extern char D_4D7230[];
void Cleanup__8BaseListFi(void*, int);
void func_1DC100(void*, int);

void* func_00139BB0(void *self, int flag);
void* func_00139C10(void *self, int flag);
}

void* func_00139BB0(void *self, int flag) {
    if (self) {
        *(void**)self = D_4D7A90;
        func_2639D0(self, 0);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

void* func_00139C10(void *self, int flag) {
    if (self) {
        *(void**)self = D_4D7230;
        Cleanup__8BaseListFi(self, 0);
        func_1DC100(self, 0);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}
