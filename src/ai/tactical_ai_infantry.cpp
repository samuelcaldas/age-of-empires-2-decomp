#include "sub_list.h"

#pragma exceptions off

extern "C" {
    extern void* D_4D7780[];
    extern void* D_4D77D0[];
    extern void* D_4D7898[];
    extern void* D_490FA0;

    void* func_100730(unsigned int size);
    void func_00100630(void *ptr);
    void func_00100670(void *ptr);
    void func_001452B0(void *self, void *param, int a2, int a3, int a4);
    void func_00145350(void *self, int a1);
    int func_00226D90(void *stream, void *buf, int size);
    int func_00226F70(void *stream, void *buf, int size);
    void* func_332e60(void *container, int id);
    int func_1471A0(void *ptr);
    int func_1471C0(void *ptr);
    int func_1471D0(void *ptr);

    void func_001446EC() {}

    void* func_001446F0(void *self, int a1) {
        if (!self) return 0;
        *(void**)self = D_4D7780;
        func_00145350(self, 0);
        if ((short)a1 > 0) {
            func_00100670(self);
        }
        return self;
    }

    void* func_00144750(void *self, int a1, int a2, int a3) {
        func_001452B0(self, &D_490FA0, 1000, a2, a1);
        *(void**)self = D_4D77D0;
        *(int*)((char*)self + 0xAC) = a3;
        *(int*)((char*)self + 0xB0) = 0;
        *(int*)((char*)self + 0xB4) = 0;
        *(int*)((char*)self + 0xB8) = 0;
        *(int*)((char*)self + 0xBC) = 300;
        *(void**)((char*)self + 0xB0) = func_100730(1200);
        return self;
    }

    void* func_001447E0(void *self, int a1, int a2, int a3) {
        func_001452B0(self, &D_490FA0, 1000, a1, 0);
        *(void**)self = D_4D77D0;
        *(int*)((char*)self + 0xAC) = a2;
        *(int*)((char*)self + 0xB0) = 0;
        *(int*)((char*)self + 0xB4) = 0;
        *(int*)((char*)self + 0xB8) = 0;
        *(int*)((char*)self + 0xBC) = 300;
        *(void**)((char*)self + 0xB0) = func_100730(1200);

        int count;
        func_00226D90((void*)a3, &count, 4);
        for (int i = 0; i < count; i++) {
            int id;
            func_00226D90((void*)a3, &id, 4);
            int cur_count = *(int*)((char*)self + 0xB4);
            int cap = *(int*)((char*)self + 0xBC);
            int *arr = *(int**)((char*)self + 0xB0);
            int exists = 0;
            for (int j = 0; j < cur_count && j < cap; j++) {
                if (arr[j] == id) {
                    exists = 1;
                    break;
                }
            }
            if (!exists && cur_count < cap - 1) {
                arr[cur_count] = id;
                *(int*)((char*)self + 0xB4) = cur_count + 1;
            }
        }
        return self;
    }

    void* func_00144950(void *self, int a1) {
        if (!self) return 0;
        *(void**)self = D_4D77D0;
        *(int*)((char*)self + 0xAC) = 0;
        void *p = *(void**)((char*)self + 0xB0);
        if (p) {
            func_00100630(p);
            *(int*)((char*)self + 0xB0) = 0;
        }
        *(int*)((char*)self + 0xB4) = 0;
        *(int*)((char*)self + 0xB8) = 0;
        *(int*)((char*)self + 0xBC) = 0;
        func_00145350(self, 0);
        if ((short)a1 > 0) {
            func_00100670(self);
        }
        return self;
    }

    void func_001449F0() {}

    int func_00144A00(void *self, void *stream) {
        int count = *(int*)((char*)self + 0xB4);
        int cap = *(int*)((char*)self + 0xBC);
        int *arr = *(int**)((char*)self + 0xB0);
        func_00226F70(stream, &count, 4);
        for (int i = 0; i < count; i++) {
            int val = (i >= cap - 1) ? *(int*)((char*)self + 0xB0) : arr[i];
            func_00226F70(stream, &val, 4);
        }
        return 1;
    }

    int func_00144AB0(void *self, void *item) {
        if (!item) return 0;
        short id = *(short*)((char*)item + 0x24);
        int count = *(int*)((char*)self + 0xB4);
        int cap = *(int*)((char*)self + 0xBC);
        int *arr = *(int**)((char*)self + 0xB0);
        int exists = 0;
        for (int i = 0; i < count && i < cap; i++) {
            if (arr[i] == (int)id) {
                exists = 1;
                break;
            }
        }
        if (!exists && count < cap - 1) {
            arr[count] = (int)id;
            *(int*)((char*)self + 0xB4) = count + 1;
        }
        return 1;
    }

    int func_00144B60(void *self, int id) {
        int cap = *(int*)((char*)self + 0xBC);
        int *arr = *(int**)((char*)self + 0xB0);
        int i = 0;
        while (i < cap && arr[i] != id) {
            i++;
        }
        if (i < cap) {
            while (i < cap - 1) {
                arr[i] = arr[i + 1];
                i++;
            }
            int count = *(int*)((char*)self + 0xB4) - 1;
            *(int*)((char*)self + 0xB4) = count;
            if (count < 0) {
                *(int*)((char*)self + 0xB4) = 0;
            }
            return 1;
        }
        return 0;
    }

    int func_00144C00(void *self, int target_type) {
        int count = *(int*)((char*)self + 0xB4);
        int cap = *(int*)((char*)self + 0xBC);
        int *arr = *(int**)((char*)self + 0xB0);
        void *obj = *(void**)((char*)self + 0xAC);
        void *container = *(void**)((char*)obj + 0xB98);
        int matches = 0;
        for (int i = 0; i < count; i++) {
            int id = (i >= cap - 1) ? *(int*)((char*)obj + 0xAC) : arr[i];
            void *entity = func_332e60(container, id);
            if (entity) {
                typedef int (*Fn)(void*);
                Fn fn = *(Fn*)(*(char**)entity + 0x164);
                if (fn(entity) && func_1471A0(*(void**)fn(entity)) == target_type) {
                    matches++;
                }
            }
        }
        return matches;
    }

    int func_00144CF0() { return 0; }

    void* func_00144D00(void *self) {
        void *obj = *(void**)((char*)self + 0xAC);
        void *container = *(void**)((char*)obj + 0xB98);
        return func_332e60(container, (int)container);
    }

    void* func_00144D10(void *self, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int sp_b8, int sp_c0, int sp_c8, int sp_d0, int sp_d8) {
        int count = *(int*)((char*)self + 0xB4);
        int cap = *(int*)((char*)self + 0xBC);
        int *arr = *(int**)((char*)self + 0xB0);
        void *obj = *(void**)((char*)self + 0xAC);
        void *container = *(void**)((char*)obj + 0xB98);

        for (int i = 0; i < count; i++) {
            int id = (i >= cap - 1) ? *(int*)((char*)obj + 0xAC) : arr[i];
            void *entity = func_332e60(container, id);
            if (!entity) continue;
            typedef int (*Fn)(void*);
            Fn fn = *(Fn*)(*(char**)entity + 0x164);
            if (!fn(entity)) continue;
            if (a1 != -1 && (int)*(short*)((char*)entity + 0x24) != a1) continue;
            if (a2 != -1) {
                void *sub = *(void**)((char*)entity + 4);
                if ((int)*(short*)((char*)sub + 8) != a2) continue;
            }
            if (a3 != -1) {
                void *sub = *(void**)((char*)entity + 4);
                if ((int)*(short*)((char*)sub + 0xE) != a3) continue;
            }
            if (t0 != -1 && func_1471A0(*(void**)fn(entity)) != t0) continue;
            return entity;
        }
        return 0;
    }

    void* func_00144F90(void *self) { return self; }
    void* func_00144FC0() { return 0; }
    void* func_00144FD0(void *self) { return self; }
    void func_001451E0() {}
    void func_001451F0() {}
    void func_00145200() {}
    void func_00145250() {}
    void func_00145260() {}
    void func_001452A0() {}
    void func_00145340() {}
    void func_001453B0() {}
    void func_00145400() {}
    void func_00145410() {}
    void func_00145420() {}
    int func_00145430(void *self) { return *(int*)((char*)self + 0x64); }
    void func_00145440(void *self, int val) { *(int*)((char*)self + 0x64) = val; }
    void func_00145450() {}
    void func_00145460() {}
    int func_00145470() { return 0; }
    int func_00145480() { return 0; }
    void func_00145490() {}
    int func_001454A0() { return 0; }
    void func_001454B0() {}

    void* func_001454F0(void *self, int a1) {
        *(void**)self = D_4D7898;
        *(int*)((char*)self + 4) = 0;
        *(int*)((char*)self + 8) = 0;
        *(int*)((char*)self + 0x6C) = a1;
        for (int i = 0; i < a1 && i < 8; i++) {
            char *entry = (char*)self + i * 4;
            *(int*)(entry + 0xC) = 0;
            *(int*)(entry + 0x2C) = -1;
            *(int*)(entry + 0x4C) = -1;
        }
        for (int i = a1; i < 8; i++) {
            char *entry = (char*)self + i * 4;
            *(int*)(entry + 0xC) = -1;
            *(int*)(entry + 0x2C) = -1;
            *(int*)(entry + 0x4C) = -1;
        }
        return self;
    }

    void* func_00145580(void *self, int a1) {
        if (!self) return 0;
        *(void**)self = D_4D7898;
        *(int*)((char*)self + 8) = 0;
        *(int*)((char*)self + 4) = 0;
        if ((short)a1 > 0) {
            func_00100670(self);
        }
        return self;
    }

    int func_001455E0(void *self, int a1) {
        if (a1 < 0 || a1 >= *(int*)((char*)self + 0x6C)) {
            return -1;
        }
        return *(int*)((char*)self + 0xC + a1 * 4);
    }

    void func_00145620(void *self, int a1, int a2) {
        if (a1 >= 0 && a1 < *(int*)((char*)self + 0x6C)) {
            *(int*)((char*)self + 0xC + a1 * 4) += a2;
        }
    }

    int func_00145660(void *self) { return *(int*)((char*)self + 0x6C); }

    void func_00145670(void *self) {
        short *s = (short*)self;
        s[0] = -1;
        s[1] = -1;
        char *c = (char*)self;
        c[4] = 0;
        c[5] = 0;
        c[6] = 0;
        c[7] = 0;
        for (int i = 0; i < 16; i++) {
            char *entry = c + 8 + i * 20;
            *(short*)(entry + 0) = 0;
            *(short*)(entry + 2) = -1;
            *(int*)(entry + 4) = 0;
            *(int*)(entry + 8) = 0;
            *(int*)(entry + 12) = 0;
            *(int*)(entry + 16) = 0;
        }
    }
}
