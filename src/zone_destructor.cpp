#pragma exceptions off
#include "sub_list.h"
#include "zone_destructor.h"

extern char D_4D9270[];
extern void *D_4E35DC;
extern char D_938AC0[];
extern char D_938CC0[];
extern char D_81D120[];
extern char D_92E820[];
extern char D_938460[];
extern char D_938790[];

extern "C" {

void func_335560(void *allocator, void *ptr);
void func_00100670(void *ptr); // operator delete
void func_00100630(void *ptr);
void func_1D16D0(void *self);
void func_25DE30(void *ptr, int flag);
void *memset(void *dst, int val, unsigned int size);
void func_001389F0(void *allocator);
void func_327590(void *allocator);
void func_1ED830(void *self);
void func_1D06A0(void *self);

struct ZoneMap {
    void *vptr;              // 0x0
    int m_field4;            // 0x4
    int m_field8;            // 0x8
    int m_fieldC;            // 0xC
    char pad_10[0x8E7C];     // 0x10 to 0x8E8C
    void **m_field8E8C;      // 0x8E8C (-0x7174)
    char pad_8E90[0x34];     // 0x8E90 to 0x8EC4
    int m_field8EC4;         // 0x8EC4 (-0x713C)
    int m_field8EC8;         // 0x8EC8 (-0x7138)
    char pad_8ECC[0x4];      // 0x8ECC to 0x8ED0
    int m_field8ED0;         // 0x8ED0 (-0x7130)
    int m_field8ED4;         // 0x8ED4 (-0x712C)
    void *m_field8ED8;       // 0x8ED8 (-0x7128)
    void **m_field8EDC;      // 0x8EDC (-0x7124)
    void *m_field8EE0;       // 0x8EE0 (-0x7120)
    void *m_field8EE4;       // 0x8EE4 (-0x711C)
    void *m_world;           // 0x8EE8 (-0x7118)
    void *m_field8EEC;       // 0x8EEC (-0x7114)
    void *m_field8EF0;       // 0x8EF0 (-0x7110)
    void *m_field8EF4;       // 0x8EF4 (-0x710C)
};

class DestructibleObject {
public:
    virtual void Method0();
    virtual void Method1();
    virtual void Destroy(int flag);
};

void *func_001C8FF0(void *self, int flag) {
    if (!self) {
        return 0;
    }

    ZoneMap *zm = (ZoneMap *)self;
    zm->vptr = D_4D9270;

    if (zm->m_field8EEC) {
        func_335560(D_4E35DC, zm->m_field8EEC);
    }

    if (zm->m_field8EE4) {
        ((DestructibleObject *)zm->m_field8EE4)->Destroy(1);
    }

    func_1D16D0(self);

    if (zm->m_field4) {
        for (int s0 = 0; s0 < zm->m_fieldC; s0++) {
            for (int s1 = 0; s1 < zm->m_field8; s1++) {
                char *cell = (char *)zm->m_field8E8C[s0] + s1 * 28;
                void *sub_item = *(void **)(cell + 0x10);
                if (sub_item) {
                    func_25DE30(sub_item, 1);
                }
            }
        }
        memset(D_81D120, 0, 0x111700);
        zm->m_field4 = 0;
    }

    if (zm->m_field8EC4) {
        memset(D_92E820, 0, 0x9C40);
        zm->m_field8EC4 = 0;
    }

    if (zm->m_field8E8C) {
        memset(D_938460, 0, 0x324);
        zm->m_field8E8C = 0;
    }

    if (zm->m_field8EC8) {
        memset(D_938790, 0, 0x324);
        zm->m_field8EC8 = 0;
    }

    for (int s0 = 31; s0 >= 0; s0--) {
        char *elem = (char *)self + s0 * 416;
        void *item = *(void **)(elem + 0xAC);
        if (item) {
            func_25DE30(item, 1);
            *(void **)(elem + 0xAC) = 0;
        }
    }

    for (int s0 = 15; s0 >= 0; s0--) {
        char *elem = (char *)self + s0 * 480;
        void *item = *(void **)(elem + 0x34AC);
        if (item) {
            func_25DE30(item, 1);
            *(void **)(elem + 0x34AC) = 0;
        }
    }

    if (zm->m_field8EF0) {
        func_001389F0(D_4E35DC);
        zm->m_field8EF0 = 0;
    }

    if (zm->m_field8EF4) {
        func_327590(D_4E35DC);
        zm->m_field8EF4 = 0;
    }

    if (zm->m_field8ED0 > 0) {
        if (zm->m_field8EDC) {
            for (int s0 = 0; s0 < zm->m_field8ED0; s0++) {
                func_00100630(zm->m_field8EDC[s0]);
            }
        }
    }

    if (zm->m_field8EDC) {
        memset(D_938CC0, 0, 0x200);
        zm->m_field8EDC = 0;
    }

    if (zm->m_field8ED8) {
        memset(D_938AC0, 0, 0x200);
        zm->m_field8ED8 = 0;
    }

    if (zm->m_field8EE0) {
        func_1ED830(self);
    }

    func_1D06A0(self);

    if ((short)flag > 0) {
        func_00100670(self);
    }

    return self;
}

}
