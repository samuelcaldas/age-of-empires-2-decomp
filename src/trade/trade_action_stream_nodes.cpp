#pragma exceptions off

extern "C" {
void func_001824a0(void *this_ptr);
void func_00182610(void *this_ptr, void *texture, int priority, short x, short y, int flags);
int func_002634A0(void *texture);
void func_0026A460();
void *func_001831B0(void *pool);
void func_00183210(void *pool, void *item);
void *func_001840D0(void *factory, void *texture, int priority, short x, short y, int flags);
int func_00183740(void *ptr);
void func_00183380(void *ptr);
void func_00183920(void *ptr);

void *func_00182550(void *this_ptr) {
    void *items = *(void **)this_ptr;
    *(void **)this_ptr = 0;
    void *it = items;
    while (it != 0) {
        void *v0 = *(void **)it;
        short a3 = *(short *)((char *)v0 + 4);
        short t0 = *(short *)((char *)v0 + 6);
        void *a1 = *(void **)v0;
        unsigned char a2 = *(unsigned char *)((char *)it + 9);
        func_00182610(this_ptr, a1, a2, a3, t0, 0);
        it = *(void **)((char *)it + 4);
    }
    *(void **)this_ptr = items;
    return items;
}

void func_001825d0(void *this_ptr, void *new_items) {
    func_001824a0(this_ptr);
    *(void **)this_ptr = new_items;
}

void func_00182610(void *this_ptr, void *texture, int priority, short x, short y, int flags) {
    if (texture == 0) return;
    if (func_002634A0(texture) != 0) {
        void *field4 = *(void **)((char *)this_ptr + 4);
        if (field4 != 0) {
            func_0026A460();
        }
    }
    void *cur = *(void **)this_ptr;
    while (cur != 0) {
        void *it_tex = *(void **)cur;
        if (it_tex != 0 && *(void **)it_tex == texture) {
            *(unsigned char *)((char *)cur + 11) += 1;
            return;
        }
        cur = *(void **)((char *)cur + 4);
    }
    void **prev_ptr = (void **)this_ptr;
    void *item = *(void **)this_ptr;
    int prio = priority & 0xFF;
    while (item != 0) {
        if ((int)*(unsigned char *)((char *)item + 9) < prio) break;
        prev_ptr = (void **)((char *)item + 4);
        item = *prev_ptr;
    }
    void *new_node = func_001831B0((void *)0x514E30);
    if (new_node == 0) return;
    void *entry = func_001840D0((void *)0x532300, texture, priority, x, y, flags);
    *(void **)new_node = entry;
    if (entry == 0) {
        func_00183210((void *)0x514E30, new_node);
        return;
    }
    *(unsigned char *)((char *)new_node + 8) = 0;
    *(unsigned char *)((char *)new_node + 9) = priority;
    *(unsigned char *)((char *)new_node + 10) = 0;
    *(unsigned char *)((char *)new_node + 11) = 0;
    *(void **)((char *)new_node + 4) = *prev_ptr;
    *prev_ptr = new_node;
}

void func_001827b0(void *this_ptr, void *texture) {
    void **prev_ptr = (void **)this_ptr;
    void *cur = *(void **)this_ptr;
    while (cur != 0) {
        void *it_tex = *(void **)cur;
        if (it_tex != 0 && *(void **)it_tex == texture) {
            unsigned char count = *(unsigned char *)((char *)cur + 11);
            if ((int)count > 0) {
                *(unsigned char *)((char *)cur + 11) = count - 1;
                return;
            }
            *prev_ptr = *(void **)((char *)cur + 4);
            if (func_00183740(*(void **)cur) != 0) {
                void *field4 = *(void **)((char *)this_ptr + 4);
                if (field4 != 0) {
                    func_0026A460();
                }
            }
            if (*(unsigned char *)((char *)cur + 8) == 0) {
                func_00183380(*(void **)cur);
            } else {
                func_00183920(*(void **)cur);
            }
            func_00183210((void *)0x514E30, cur);
            return;
        }
        prev_ptr = (void **)((char *)cur + 4);
        cur = *prev_ptr;
    }
}
}
