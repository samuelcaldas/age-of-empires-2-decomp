#include "network_transport_init_337d40.h"

extern int D_004E3560, D_004E3564, D_004E353C, D_004E3538, D_004E3534;
extern unsigned int D_004E3548[2], D_004E3540[2];
extern TransportAddress D_010890B0, D_010890C0, D_010890D0;
extern TransportThread D_010931A0;
extern char D_0108B1A0[], _gp;
extern "C" {
extern const char D_004D1F60[], D_004D1F80[], D_004D1FC0[], D_004D2000[], D_004D2040[], D_004D2090[], D_004D20B0[];
int func_104D20(TransportSema *);
int func_389120(unsigned int *);
int func_388BA0(int, int, int);
int func_388C20(int, const TransportAddress *, int);
int func_388CC0(int, const TransportAddress *, int);
int func_104B20(TransportThread *);
int func_104B40(int, void *);
int func_118de0(const char *, ...);
void func_337B30();
}

int func_00337D40(void) {
    TransportSema sema;
    sema.init_count = 1;
    sema.max_count = 1;
    sema.option = 0;
    D_004E3560 = func_104D20(&sema);
    sema.init_count = 1;
    sema.max_count = 1;
    sema.option = 0;
    D_004E3564 = func_104D20(&sema);
    func_389120(D_004E3548);
    D_004E3540[0] = ((D_004E3548[0] >> 8) & 0xff00) | ((D_004E3548[0] & 0xff00) << 8) | (D_004E3548[0] << 24) | (D_004E3548[0] >> 24);
    D_004E3540[1] = ((D_004E3548[1] >> 8) & 0xff00) | ((D_004E3548[1] & 0xff00) << 8) | (D_004E3548[1] << 24) | (D_004E3548[1] >> 24);
    func_118de0(D_004D1F60, D_004E3540[0], D_004E3540[1]);
    func_118de0(D_004D1F60, D_004E3548[0], D_004E3548[1]);
    D_004E353C = func_388BA0(60, 2, 0);
    D_004E3538 = func_388BA0(60, 2, 0);
    D_004E3534 = func_388BA0(60, 2, 0);
    D_010890B0.len = 16;
    D_010890C0.len = 16;
    D_010890D0.len = 16;
    D_010890B0.family = 60;
    D_010890C0.family = 60;
    D_010890D0.family = 60;
    D_010890B0.port = 0x3412;
    D_010890B0.node[0] = 0;
    D_010890B0.node[1] = 0;
    D_010890C0.port = 0x3412;
    D_010890D0.port = 0x3412;
    D_010890D0.node[0] = ~0u;
    D_010890D0.node[1] = ~0u;
    int i, result = -1;
    for (i = 0; i < 5 && result != 0; ++i)
        result = func_388C20(D_004E353C, &D_010890B0, 16);
    if (i >= 5) func_118de0(D_004D1F80, 320, result);
    D_010890B0.port = 0;
    result = -1;
    for (i = 0; i < 5 && result != 0; ++i)
        result = func_388C20(D_004E3538, &D_010890B0, 16);
    if (i >= 5) func_118de0(D_004D1FC0, 328, result);
    result = -1;
    for (i = 0; i < 5 && result != 0; ++i)
        result = func_388C20(D_004E3534, &D_010890B0, 16);
    if (i >= 5) func_118de0(D_004D2000, 334, result);
    result = -1;
    for (i = 0; i < 5 && result != 0; ++i)
        result = func_388CC0(D_004E3534, &D_010890D0, 16);
    if (i >= 5) func_118de0(D_004D2040, 340, result);
    D_010931A0.entry = func_337B30;
    D_010931A0.stack = D_0108B1A0;
    D_010931A0.stack_size = 0x8000;
    D_010931A0.priority = 11;
    D_010931A0.gp = &_gp;
    int thread = func_104B20(&D_010931A0);
    if (thread >= 0) {
        func_104B40(thread, 0);
        return func_118de0(D_004D2090);
    }
    return func_118de0(D_004D20B0, 353);
}
