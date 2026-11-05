#include "kt_gs_render_225160.h"

extern "C" {
void func_00117AF8(void);
int func_002253F0(int);
void func_0036DDF0(void);
int func_00225560(void *);
void func_0036DF30(void);
void func_001143C0(void);

#if defined(__MWERKS__) && defined(__MIPS__)
// func_00225160: 0x00225160 - 0x00225170 (0x010 bytes)
asm void func_00225160(int p0, int p1) {
    .word 0x70801628
    .word 0x70A02628
    j func_00117AF8
    .word 0x70402E28
}

// func_00225170: 0x00225170 - 0x002251C0 (0x050 bytes)
asm void *func_00225170(void *p0, void *p1) {
    .word 0x0085102B
    .word 0x54400004
    .word 0x24A5FFFF
    .word 0x1000000E
    .word 0x70001628
    .word 0x24A5FFFF
    .word 0x0085102B
    .word 0x1440000A
    .word 0x70A01628
    .word 0x90A3FFFF
    .word 0x28620080
    .word 0x14400005
    .word 0x00000000
    .word 0x286100A0
    .word 0x10200002
    .word 0x00000000
    .word 0x24A5FFFF
    .word 0x70A01628
    .word 0x03E00008
    .word 0x00000000
}

// func_002251C0: 0x002251C0 - 0x00225200 (0x040 bytes)
asm void *func_002251C0(void *p0) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x70808628
    jal func_002253F0
    .word 0x90840000
    .word 0x10400003
    .word 0x26020001
    .word 0x26100001
    .word 0x26020001
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
    .word 0x00000000
    .word 0x00000000
}

// func_00225200: 0x00225200 - 0x00225240 (0x040 bytes)
asm int func_00225200(void *p0) {
    .word 0x1000000A
    .word 0x70001628
    .word 0x28A30080
    .word 0x54600006
    .word 0x24420001
    .word 0x28A100A0
    .word 0x10200002
    .word 0x00000000
    .word 0x24840001
    .word 0x24420001
    .word 0x24840001
    .word 0x90850000
    .word 0x14A0FFF6
    .word 0x28A30080
    .word 0x03E00008
    .word 0x00000000
}

// func_00225240: 0x00225240 - 0x002252E0 (0x0A0 bytes)
asm void *func_00225240(void *p0, void *p1, int p2) {
    .word 0x10000002
    .word 0x70803E28
    .word 0x24E70001
    .word 0x90E20000
    .word 0x5440FFFE
    .word 0x24E70001
    .word 0x10000016
    .word 0x70001E28
    .word 0xA0E80000
    .word 0x90A80000
    .word 0x29020080
    .word 0x14400005
    .word 0x290200E0
    .word 0x290200A0
    .word 0x54400008
    .word 0x24A50001
    .word 0x290200E0
    .word 0x54400009
    .word 0x24630001
    .word 0x290100FF
    .word 0x10200005
    .word 0x00000000
    .word 0x24A50001
    .word 0x90A20000
    .word 0x24E70001
    .word 0xA0E20000
    .word 0x24630001
    .word 0x24E70001
    .word 0x24A50001
    .word 0x90A80000
    .word 0x11000004
    .word 0x00000000
    .word 0x0066102B
    .word 0x1440FFE6
    .word 0x00000000
    .word 0xA0E00000
    .word 0x03E00008
    .word 0x70801628
    .word 0x00000000
    .word 0x00000000
}

// func_002252E0: 0x002252E0 - 0x00225390 (0x0B0 bytes)
asm void *func_002252E0(void *p0, void *p1, int p2) {
    .word 0x27BDFFA0
    .word 0x7FBF0050
    .word 0x7FB40040
    .word 0x7FB30030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x7080A628
    .word 0x70C09E28
    .word 0x70A09628
    .word 0x72808E28
    .word 0x1000000D
    .word 0x70008628
    .word 0xA2230000
    jal func_002253F0
    .word 0x92440000
    .word 0x50400006
    .word 0x26100001
    .word 0x26520001
    .word 0x92420000
    .word 0x26310001
    .word 0xA2220000
    .word 0x26100001
    .word 0x26310001
    .word 0x26520001
    .word 0x92430000
    .word 0x10600004
    .word 0x00000000
    .word 0x0213102B
    .word 0x1440FFEF
    .word 0x00000000
    .word 0xA2200000
    .word 0x72801628
    .word 0x7BBF0050
    .word 0x7BB40040
    .word 0x7BB30030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0060
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_00225390: 0x00225390 - 0x002253F0 (0x060 bytes)
asm void *func_00225390(void *p0, int p1) {
    .word 0x14800004
    .word 0x70003628
    .word 0x10000012
    .word 0x70001628
    .word 0x70003628
    .word 0x1000000C
    .word 0x00C5102B
    .word 0x90830000
    .word 0x28620080
    .word 0x54400006
    .word 0x24840001
    .word 0x286100A0
    .word 0x10200002
    .word 0x00000000
    .word 0x24840001
    .word 0x24840001
    .word 0x24C60001
    .word 0x00C5102B
    .word 0x1440FFF4
    .word 0x00000000
    .word 0x70801628
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
}

// func_002253F0: 0x002253F0 - 0x00225440 (0x050 bytes)
asm int func_002253F0(int p0) {
    .word 0x308300FF
    .word 0x28620080
    .word 0x14400005
    .word 0x286200E0
    .word 0x286200A0
    .word 0x14400008
    .word 0x24020001
    .word 0x286200E0
    .word 0x14400008
    .word 0x70001628
    .word 0x286100FF
    .word 0x10200004
    .word 0x00000000
    .word 0x24020001
    .word 0x10000002
    .word 0x00000000
    .word 0x70001628
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
}

// func_00225440: 0x00225440 - 0x00225450 (0x010 bytes)
asm int func_00225440(void) {
    .word 0x03E00008
    .word 0x240201F4
    .word 0x00000000
    .word 0x00000000
}

// func_00225450: 0x00225450 - 0x00225470 (0x020 bytes)
asm int func_00225450(void *p0, void *p1) {
    .word 0xACA00000
    .word 0x24020280
    .word 0xACA00004
    .word 0xACA20008
    .word 0x240201C0
    .word 0xACA2000C
    .word 0x03E00008
    .word 0x24020001
}

// func_00225470: 0x00225470 - 0x002254D0 (0x060 bytes)
asm int func_00225470(int p0) {
    .word 0x24020015
    .word 0x1082000F
    .word 0x24020010
    .word 0x24020001
    .word 0x10820009
    .word 0x240201C0
    .word 0x10800004
    .word 0x24020280
    .word 0x1000000B
    .word 0x70001628
    .word 0x24020280
    .word 0x10000008
    .word 0x00000000
    .word 0x240201C0
    .word 0x10000005
    .word 0x00000000
    .word 0x24020010
    .word 0x10000002
    .word 0x00000000
    .word 0x70001628
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_002254D0: 0x002254D0 - 0x002254F0 (0x020 bytes)
asm int func_002254D0(void *p0, void *p1) {
    .word 0xACA00000
    .word 0x24020280
    .word 0xACA00004
    .word 0xACA20008
    .word 0x240201C0
    .word 0xACA2000C
    .word 0x03E00008
    .word 0x24020001
}

// func_002254F0: 0x002254F0 - 0x00225510 (0x020 bytes)
asm int func_002254F0(void *p0, int p1, int p2, int p3, int p4) {
    .word 0xAC850000
    .word 0xAC860004
    .word 0xAC870008
    .word 0x24020001
    .word 0x03E00008
    .word 0xAC88000C
    .word 0x00000000
    .word 0x00000000
}

// func_00225510: 0x00225510 - 0x00225520 (0x010 bytes)
asm int func_00225510(void) {
    .word 0x03E00008
    .word 0x24020001
    .word 0x00000000
    .word 0x00000000
}

// func_00225520: 0x00225520 - 0x00225560 (0x040 bytes)
asm int func_00225520(int p0) {
    .word 0x27BDFEE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x70808628
    jal func_0036DDF0
    .word 0x27A40020
    .word 0x021D1021
    .word 0x7BBF0010
    .word 0x90420020
    .word 0x7BB00000
    .word 0x28410002
    .word 0x24028000
    .word 0x27BD0120
    .word 0x03E00008
    .word 0x0001100B
    .word 0x00000000
}

// func_00225560: 0x00225560 - 0x00225590 (0x030 bytes)
asm int func_00225560(void *p0) {
    .word 0x3C0100C6
    .word 0x8C23E840
    .word 0x24020001
    .word 0xAC830000
    .word 0x3C0100C6
    .word 0x8C23E844
    .word 0x03E00008
    .word 0xAC830004
    j func_00225560
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_00225590: 0x00225590 - 0x002255C0 (0x030 bytes)
asm int func_00225590(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_0036DF30
    .word 0x00000000
    .word 0x7BBF0000
    .word 0x0002143C
    .word 0x0002143F
    .word 0x03E00008
    .word 0x27BD0010
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_002255C0: 0x002255C0 - 0x00225600 (0x040 bytes)
asm int func_002255C0(void *p0, int p1, void *p2) {
    .word 0x27BDFFF0
    .word 0x24020004
    .word 0x14A20003
    .word 0x7FBF0000
    .word 0x10000006
    .word 0x7BBF0000
    .word 0x24050018
    jal func_001143C0
    .word 0x70C02628
    .word 0x24020018
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

#else
void func_00225160(int p0, int p1) {}
void *func_00225170(void *p0, void *p1) { return 0; }
void *func_002251C0(void *p0) { return 0; }
int func_00225200(void *p0) { return 0; }
void *func_00225240(void *p0, void *p1, int p2) { return 0; }
void *func_002252E0(void *p0, void *p1, int p2) { return 0; }
void *func_00225390(void *p0, int p1) { return 0; }
int func_002253F0(int p0) { return 0; }
int func_00225440(void) { return 0; }
int func_00225450(void *p0, void *p1) { return 0; }
int func_00225470(int p0) { return 0; }
int func_002254D0(void *p0, void *p1) { return 0; }
int func_002254F0(void *p0, int p1, int p2, int p3, int p4) { return 0; }
int func_00225510(void) { return 0; }
int func_00225520(int p0) { return 0; }
int func_00225560(void *p0) { return 0; }
int func_00225590(void) { return 0; }
int func_002255C0(void *p0, int p1, void *p2) { return 0; }
#endif
}
