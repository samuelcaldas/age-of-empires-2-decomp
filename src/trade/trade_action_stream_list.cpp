#pragma exceptions off

extern "C" {
void func_00100670(void *ptr);
int func_00226D90(void *stream, void *buf, int count);
void func_00226F70(void *stream, void *buf, int count);
void *func_001831B0(void *pool);
void func_00183210(void *pool, void *item);
void *func_00184140(void *factory, void *stream, int param);
void *func_00184280(void *factory, void *stream, int param);
void func_001833A0(void *ptr, void *stream, void *out);
void func_00183930(void *ptr, void *stream, void *out);
int func_00183740(void *ptr);
void func_00183380(void *ptr);
void func_00183920(void *ptr);
void func_0026A460();
void func_001234E0(int arg);
void func_00100190(int a0, int a1);

void *func_001820d0(void *this_ptr, void *param) {
    *(void **)((char *)this_ptr + 8) = (void *)0x4D7D70;
    *(void **)((char *)this_ptr + 0) = 0;
    *(void **)((char *)this_ptr + 4) = param;
    return this_ptr;
}

void func_001824a0(void *this_ptr) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *next = *(void **)((char *)item + 4);
        if (func_00183740(*(void **)item) != 0) {
            void *field4 = *(void **)((char *)this_ptr + 4);
            if (field4 != 0) {
                func_0026A460();
            }
        }
        if (*(unsigned char *)((char *)item + 8) == 0) {
            func_00183380(*(void **)item);
        } else {
            func_00183920(*(void **)item);
        }
        func_00183210((void *)0x514E30, item);
        item = next;
    }
    *(void **)this_ptr = 0;
}

void *func_001820f0(void *this_ptr, short flag) {
    if (this_ptr != 0) {
        *(void **)((char *)this_ptr + 8) = (void *)0x4D7D70;
        func_001824a0(this_ptr);
        *(int *)((char *)this_ptr + 0) = 0;
        *(int *)((char *)this_ptr + 4) = 0;
        if ((int)flag > 0) {
            func_00100670(this_ptr);
        }
    }
    return this_ptr;
}

void func_00182150(void *this_ptr, void *stream, int param) {
    char ch;
    while (func_00226D90(stream, &ch, 1) != 0) {
        void ***vt = *(void ****)((char *)this_ptr + 8);
        int (*method)(void *, void *, char, int) = (int (*)(void *, void *, char, int))vt[14];
        if (method(this_ptr, stream, ch, param) == 0) break;
    }
    void *v1 = 0;
    void *a1 = *(void **)this_ptr;
    while (a1 != 0) {
        void *a0 = *(void **)((char *)a1 + 4);
        *(void **)((char *)a1 + 4) = v1;
        v1 = *(void **)this_ptr;
        *(void **)this_ptr = a0;
        a1 = *(void **)this_ptr;
    }
    *(void **)this_ptr = v1;
}

int func_001821f0(void *this_ptr, void *stream, int opcode, int param) {
    int mode = opcode & 0xFF;
    if (mode == 0) return 0;
    if (mode == 1) {
        void *node = func_001831B0((void *)0x514E30);
        if (node == 0) return 0;
        void *ret = func_00184140((void *)0x532300, stream, param);
        *(void **)node = ret;
        if (ret == 0) {
            func_00183210((void *)0x514E30, node);
            return 0;
        }
        *(void **)((char *)node + 4) = *(void **)this_ptr;
        *(void **)this_ptr = node;
        func_001234E0(-30876);
        func_00100190(0, 0);
        return 1;
    }
    if (mode == 2) {
        void *node = func_001831B0((void *)0x514E30);
        if (node == 0) return 0;
        void *ret = func_00184280((void *)0x532300, stream, param);
        *(void **)node = ret;
        if (ret == 0) {
            func_00183210((void *)0x514E30, node);
            return 0;
        }
        *(void **)((char *)node + 4) = *(void **)this_ptr;
        *(void **)this_ptr = node;
        return 1;
    }
    return 1;
}

void func_001823e0(void *this_ptr, void *stream) {
    char zero_byte = 0;
    void *item = *(void **)this_ptr;
    while (item != 0) {
        if (*(unsigned char *)((char *)item + 8) == 0) {
            func_001833A0(*(void **)item, stream, (char *)item + 9);
        } else {
            func_00183930(*(void **)item, stream, (char *)item + 9);
        }
        func_00226F70(stream, (char *)item + 9, 1);
        func_00226F70(stream, (char *)item + 10, 1);
        func_00226F70(stream, (char *)item + 11, 1);
        item = *(void **)((char *)item + 4);
    }
    func_00226F70(stream, &zero_byte, 1);
}
}
