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
    void *vptr;
    char payload[0x8EE4];
    void *m_world;
    int m_field8EEC;
};

void *func_001C8CA0(void *self, void *stream, void *arg2) {
    ZoneMap *zm = (ZoneMap *)self;
    zm->vptr = D_4D9270;
    zm->m_field8EEC = 0;

    int header;
    func_00226D90(stream, &header, 4);
    func_00226D90(stream, (char *)self + 4, 0x9154);

    for (int t8 = 0; t8 < 32; t8++) {
        short cost = 1;
        if (t8 == 3 || t8 == 9 || t8 == 12 || t8 == 0) {
            cost = 5;
        } else if (t8 == 6) {
            cost = 4;
        } else if (t8 == 13 || t8 == 4) {
            cost = 3;
        } else if (t8 == 1 || t8 == 23 || t8 == 22 || t8 == 25 || t8 == 24 || t8 == 10 || t8 == 11) {
            cost = 2;
        }
        char *elem = (char *)self + t8 * 416;
        *(short *)(elem + 0x14E) = cost;
        *(short *)(elem + 0x150) = cost;
    }

    void *world = *(void **)((char *)D_004E3180 + 0x404);
    *(void **)((char *)self + 0x8EE8) = world;

    *(int *)((char *)self + 0x4) = 0;
    *(int *)((char *)self + 0x8EC4) = 0;
    *(int *)((char *)self + 0x8E8C) = 0;
    *(int *)((char *)self + 0x8EC8) = 0;
    *(int *)((char *)self + 0x8EE0) = 0;
    *(int *)((char *)self + 0x8EFC) = 0;
    *(int *)((char *)self + 0x8F00) = 0;

    func_1CDD00(self, arg2);
    func_1CDE30(self, arg2);

    typedef void (*VirtualMethod)(void *);
    VirtualMethod slot12 = *(VirtualMethod *)(*(char **)self + 0x30);
    slot12(self);

    *(int *)((char *)self + 0x8ED0) = 0;
    *(int *)((char *)self + 0x8ED4) = 0x80;

    memset(D_938AC0, 0, 0x200);
    *(void **)((char *)self + 0x8ED8) = D_938AC0;

    memset(D_938CC0, 0, 0x200);
    *(void **)((char *)self + 0x8EDC) = D_938CC0;

    *(int *)((char *)self + 0x903C) = 0;
    *(int *)((char *)self + 0x9040) = 0;
    *(int *)((char *)self + 0x9044) = 0;
    *(int *)((char *)self + 0x9038) = 0;

    for (int v1 = 0; v1 < 17; v1++) {
        char *base = (char *)self + v1 * 4;
        *(int *)(base + 0x9114) = 0;
        *(int *)(base + 0x9048) = 0;
        *(int *)(base + 0x908C) = 0;
        *(int *)(base + 0x90D0) = 0;
    }

    *(int *)((char *)self + 0x9034) = 0;

    return self;
}

}
