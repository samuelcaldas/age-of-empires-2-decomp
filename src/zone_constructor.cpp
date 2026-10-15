#pragma exceptions off
#include "sub_list.h"
#include "zone_constructor.h"

extern char D_4D9270[];
extern void *D_004E3180;
extern char D_938AC0[];
extern char D_938CC0[];

extern "C" {
int func_00226D90(void *stream, void *dst, int size);
void func_1CDD00(void *self, void *arg);
void func_1CDE30(void *self, void *arg);
void *memset(void *dst, int val, unsigned int size);

struct ZoneMap {
    void *vptr;              // 0x0
    int m_field4;            // 0x4
    char pad_8[0x8E84];      // 0x8 to 0x8E8C
    int m_field8E8C;         // 0x8E8C (-0x7174)
    char pad_8E90[0x34];     // 0x8E90 to 0x8EC4
    int m_field8EC4;         // 0x8EC4 (-0x713C)
    int m_field8EC8;         // 0x8EC8 (-0x7138)
    char pad_8ECC[0x4];      // 0x8ECC to 0x8ED0
    int m_field8ED0;         // 0x8ED0 (-0x7130)
    int m_field8ED4;         // 0x8ED4 (-0x712C)
    void *m_field8ED8;       // 0x8ED8 (-0x7128)
    void *m_field8EDC;       // 0x8EDC (-0x7124)
    int m_field8EE0;         // 0x8EE0 (-0x7120)
    char pad_8EE4[0x4];      // 0x8EE4 to 0x8EE8
    void *m_world;           // 0x8EE8 (-0x7118)
    int m_field8EEC;         // 0x8EEC (-0x7114)
    char pad_8EF0[0xC];      // 0x8EF0 to 0x8EFC
    int m_field8EFC;         // 0x8EFC (-0x7104)
    int m_field8F00;         // 0x8F00 (-0x7100)
    char pad_8F04[0x130];    // 0x8F04 to 0x9034
    int m_field9034;         // 0x9034 (-0x6FCC)
    int m_field9038;         // 0x9038 (-0x6FC8)
    int m_field903C;         // 0x903C (-0x6FC4)
    int m_field9040;         // 0x9040 (-0x6FC0)
    int m_field9044;         // 0x9044 (-0x6FBC)
    int m_table1[17];        // 0x9048 to 0x908C (-0x6FB8)
    int m_table2[17];        // 0x908C to 0x90D0 (-0x6F74)
    int m_table3[17];        // 0x90D0 to 0x9114 (-0x6F30)
    int m_table4[17];        // 0x9114 to 0x9158 (-0x6EEC)
};

void *func_001C8CA0(void *self, void *stream, void *arg2) {
    register void *st = stream;
    ZoneMap *zm = (ZoneMap *)self;
    zm->vptr = D_4D9270;
    zm->m_field8EEC = 0;

    int header;
    func_00226D90(st, &header, 4);
    func_00226D90(st, (char *)self + 4, 0x9154);

    for (int t8 = 0; t8 < 32; t8++) {
        char *elem = (char *)self + t8 * 416;
        switch (t8) {
        default:
            *(short *)(elem + 0x14E) = 1;
            *(short *)(elem + 0x150) = 1;
            break;
        case 11:
        case 10:
        case 24:
        case 25:
        case 22:
        case 23:
        case 1:
            *(short *)(elem + 0x14E) = 2;
            *(short *)(elem + 0x150) = 2;
            break;
        case 4:
        case 13:
            *(short *)(elem + 0x14E) = 3;
            *(short *)(elem + 0x150) = 3;
            break;
        case 6:
            *(short *)(elem + 0x14E) = 4;
            *(short *)(elem + 0x150) = 4;
            break;
        case 0:
        case 12:
        case 9:
        case 3:
            *(short *)(elem + 0x14E) = 5;
            *(short *)(elem + 0x150) = 5;
            break;
        }
    }

    void *world = *(void **)((char *)D_004E3180 + 0x404);
    zm->m_world = world;

    zm->m_field4 = 0;
    zm->m_field8EC4 = 0;
    zm->m_field8E8C = 0;
    zm->m_field8EC8 = 0;
    zm->m_field8EE0 = 0;
    zm->m_field8EFC = 0;
    zm->m_field8F00 = 0;

    func_1CDD00(self, arg2);
    func_1CDE30(self, arg2);

    typedef void (*VirtualMethod)(void *);
    VirtualMethod slot12 = *(VirtualMethod *)(*(char **)self + 0x30);
    slot12(self);

    zm->m_field8ED0 = 0;
    zm->m_field8ED4 = 0x80;

    zm->m_field8ED8 = memset(D_938AC0, 0, 0x200);
    zm->m_field8EDC = memset(D_938CC0, 0, 0x200);

    zm->m_field903C = 0;
    zm->m_field9040 = 0;
    zm->m_field9044 = 0;
    zm->m_field9038 = 0;

    for (int v1 = 0; v1 < 17; v1++) {
        zm->m_table4[v1] = 0;
        zm->m_table1[v1] = 0;
        zm->m_table2[v1] = 0;
        zm->m_table3[v1] = 0;
    }

    zm->m_field9034 = 0;

    return self;
}

}
