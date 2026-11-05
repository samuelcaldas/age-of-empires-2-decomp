#include "kt_gs_render_224310.h"

extern "C" {
void *func_00123908(int);
int func_00223F70(void);
int func_0021E370(void *, void *, void *, void *);
void func_0021C990(void *, void *, void *, void *, void *);
void func_0021F8F0(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00224310(void) {
    .word 0x3C0100CA
    .word 0x8C2817E0
    .word 0x3C030048
    .word 0x2464BF00
    .word 0x3C0300C6
    .word 0x2465E850
    .word 0x3C0100C6
    .word 0x8C27E850
    .word 0x00081840
    .word 0x00681821
    .word 0x00031840
    .word 0x00834821
    .word 0x3C0100C6
    .word 0x8C26E854
    .word 0x3C0300C6
    .word 0x81280004
    .word 0x2464E840
    .word 0x3C0100CA
    .word 0x00E81823
    .word 0xAC2317E4
    .word 0x81230005
    .word 0x3C0100CA
    .word 0x00C31823
    .word 0xAC2317E8
    .word 0xDCA30000
    .word 0xC4A00008
    .word 0xFC830000
    .word 0x03E00008
    .word 0xE4800008
}

asm void func_00224390(void *p0) {
    .word 0x27BDFF70
    .word 0x7FBF0050
    .word 0x7FB30040
    .word 0x70809E28
    .word 0x7FB20030
    .word 0x7FB10020
    .word 0x24040001
    jal func_00123908
    .word 0x7FB00010
    jal func_00223F70
    .word 0x70408628
    .word 0x3C0100CA
    .word 0x8C3117E4
    .word 0x3C0300CA
    .word 0x246617E0
    .word 0xDF8386C8
    .word 0x27A40088
    .word 0x3C0100CA
    .word 0x8C3217E8
    .word 0xFC830000
    .word 0x3C0100CA
    .word 0x802317EC
    .word 0x00031EFC
    .word 0x00031FFF
    .word 0x14600031
    .word 0x70402E28
    .word 0x1660002F
    .word 0x00000000
    .word 0x80C3000C
    .word 0x00031F7C
    .word 0x00031FFF
    .word 0x1060002A
    .word 0x00000000
    .word 0x24060002
    .word 0x24070280
    .word 0x24080200
    .word 0x72002628
    .word 0x3C090005
    .word 0x70005628
    jal func_0021E370
    .word 0x70005E28
    .word 0x24020007
    .word 0x001218C0
    .word 0x0062001A
    .word 0x14400002
    .word 0xA7B10060
    .word 0x000001CD
    .word 0x00001812
    .word 0x26220080
    .word 0xA7A30062
    .word 0xA7A20068
    .word 0xA7A3006A
    .word 0x24630080
    .word 0xA7B10070
    .word 0xA7A30072
    .word 0xA7A20078
    .word 0x3C022000
    .word 0xA7A3007A
    .word 0x34420006
    .word 0x0002183C
    .word 0x3402A820
    .word 0x00021438
    .word 0x34429E80
    .word 0x00432825
    .word 0x3C028080
    .word 0x27A80088
    .word 0x27A90060
    .word 0x240A6000
    .word 0x72002628
    .word 0x70003628
    .word 0x34478080
    .word 0x70005E28
    jal func_0021C990
    .word 0xFFA00000
    .word 0x7BBF0050
    .word 0x7BB30040
    .word 0x7BB20030
    .word 0x7BB10020
    .word 0x7BB00010
    .word 0x03E00008
    .word 0x27BD0090
}

asm int func_002244E0(void *p0) {
    .word 0x27BDFFF0
    .word 0x3C0200CA
    .word 0x244617E0
    .word 0x7FBF0000
    .word 0x3C0100CA
    .word 0x802217EC
    .word 0x000216BC
    .word 0x000217FF
    .word 0x1040000D
    .word 0x00000000
    .word 0x1480000B
    .word 0x00000000
    .word 0x3C0200C6
    .word 0x2445E840
    .word 0xDCA30000
    .word 0xC4A00008
    .word 0x3C0200C6
    .word 0x2444E850
    .word 0x70001628
    .word 0xFC830000
    .word 0x10000012
    .word 0xE4800008
    .word 0x80C5000C
    .word 0x30020001
    .word 0x00021940
    .word 0x2402FFDF
    .word 0x00A21024
    .word 0x00431025
    .word 0xA0C2000C
    .word 0x80C2000C
    .word 0x000216FC
    .word 0x000217FF
    .word 0x10400003
    .word 0x00000000
    .word 0x10000004
    .word 0x70001628
    jal func_0021F8F0
    .word 0x00000000
    .word 0x24020001
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00224310(void) {
}

void func_00224390(void *p0) {
}

int func_002244E0(void *p0) {
    return 0;
}
#endif
}
