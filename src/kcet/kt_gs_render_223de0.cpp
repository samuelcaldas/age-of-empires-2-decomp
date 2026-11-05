#include "kt_gs_render_223de0.h"

extern "C" {
void func_00222370(void);
void func_00223D80(void *, void *, void *);
void func_00222B00(void *);
int func_0021BC30(void *, void *, void *, void *);
int func_0021DE90(int, int, int, void *, void *, void *, int, int);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00223DE0(void *p0, void *p1, void *p2, void *p3) {
    .word 0x27BDFF70
    .word 0x70A01E28
    .word 0x70C01628
    .word 0x7FBF0050
    .word 0x7FB10040
    .word 0x7FB00030
    .word 0xFFA80000
    .word 0x70603628
    .word 0x70E01E28
    .word 0x70403E28
    .word 0x3C028080
    .word 0xFFA00008
    .word 0x34428080
    .word 0xFFA20010
    .word 0xFFAB0018
    .word 0x8FA20090
    .word 0x70802E28
    .word 0x71208E28
    .word 0x71408628
    .word 0x27A40060
    .word 0x70605E28
    .word 0x70004628
    .word 0x70004E28
    .word 0x70005628
    jal func_00222370
    .word 0xFFA20020
    .word 0x10400007
    .word 0x00000000
    .word 0x27A40060
    .word 0x72202E28
    jal func_00223D80
    .word 0x72003628
    jal func_00222B00
    .word 0x27A40060
    .word 0x7BBF0050
    .word 0x7BB10040
    .word 0x7BB00030
    .word 0x03E00008
    .word 0x27BD0090
}

asm void func_00223E80(void *p0, void *p1, void *p2, void *p3) {
    .word 0x27BDFF60
    .word 0x7FBF0060
    .word 0x7FB20050
    .word 0x7FB10040
    .word 0x7FB00030
    .word 0xFFA80000
    .word 0x70A01628
    .word 0x70C09628
    .word 0x70403628
    .word 0x3C028080
    .word 0xFFA00008
    .word 0x34428080
    .word 0xFFA20010
    .word 0xFFAB0018
    .word 0x8FA200A0
    .word 0x70802E28
    .word 0x71208E28
    .word 0x71408628
    .word 0x70E05E28
    .word 0x27A40070
    .word 0x72403E28
    .word 0x70004628
    .word 0x70004E28
    .word 0x70005628
    jal func_00222370
    .word 0xFFA20020
    .word 0x10400013
    .word 0x00000000
    .word 0x27A40070
    .word 0x72202E28
    jal func_00223D80
    .word 0x72003628
    jal func_00222B00
    .word 0x27A40070
    .word 0x3C030048
    .word 0x2464BDF2
    .word 0x00122940
    .word 0x00852821
    .word 0x8E230000
    .word 0x90A40000
    .word 0x00641821
    .word 0xAE230000
    .word 0x90A40000
    .word 0x8E030000
    .word 0x00641821
    .word 0xAE030000
    .word 0x7BBF0060
    .word 0x7BB20050
    .word 0x7BB10040
    .word 0x7BB00030
    .word 0x03E00008
    .word 0x27BD00A0
}

asm int func_00223F50(void) {
    .word 0x3C0100CA
    .word 0x8C241578
    .word 0x3C030002
    .word 0x70001628
    .word 0x34638000
    .word 0x03E00008
    .word 0x0064100A
}

asm int func_00223F70(void) {
    .word 0x3C0100CA
    .word 0x8C231578
    .word 0x3C020002
    .word 0x34428000
    .word 0x03E00008
    .word 0x0003100A
}

asm void *func_00223F90(void) {
    .word 0x3C0100CA
    .word 0x8C221574
    .word 0x10400004
    .word 0x27BDFFF0
    .word 0x3C0200CA
    .word 0x10000003
    .word 0x24421640
    .word 0x3C0200CA
    .word 0x24421730
    .word 0xDC420000
    .word 0x27A30008
    .word 0xFC620000
    .word 0xDFA20008
    .word 0x03E00008
    .word 0x27BD0010
}

asm void func_00223FD0(int p0, int p1) {
    .word 0x3C0100CA
    .word 0xAC241590
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xAC251594
}

asm int func_00223FF0(void) {
    .word 0x3C020039
    .word 0x24442AE8
    .word 0x27BDFFF0
    .word 0x3C0201E9
    .word 0x24080001
    .word 0x7FBF0000
    .word 0x34458000
    .word 0x70003628
    jal func_0021BC30
    .word 0x70003E28
    .word 0x1040001F
    .word 0x00000000
    .word 0x3C0201E9
    .word 0x24043000
    .word 0x24050013
    .word 0x24060010
    .word 0x240A0400
    .word 0x240B0200
    .word 0x34478000
    .word 0x70004628
    jal func_0021DE90
    .word 0x70004E28
    .word 0x3C020039
    .word 0x24442AF4
    .word 0x3C0201E9
    .word 0x24080001
    .word 0x34458000
    .word 0x70003628
    jal func_0021BC30
    .word 0x70003E28
    .word 0x1040000B
    .word 0x00000000
    .word 0x240A0400
    .word 0x3C0201E9
    .word 0x24043800
    .word 0x24050014
    .word 0x24060010
    .word 0x34478000
    .word 0x70004628
    .word 0x70004E28
    jal func_0021DE90
    .word 0x71405E28
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00223DE0(void *p0, void *p1, void *p2, void *p3) {
}

void func_00223E80(void *p0, void *p1, void *p2, void *p3) {
}

int func_00223F50(void) {
    return 0;
}

int func_00223F70(void) {
    return 0;
}

void *func_00223F90(void) {
    return (void *)0;
}

void func_00223FD0(int p0, int p1) {
}

int func_00223FF0(void) {
    return 0;
}
#endif
}
