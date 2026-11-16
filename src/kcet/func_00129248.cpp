/* Function: func_00129248 (0x00129248 - 0x00129348)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129248(void) {
    .word 0x27bdffd0
    .word 0xffb00000
    .word 0xffbf0020
    .word 0x0080802d
    .word 0x12000034
    .word 0xffb10010
    .word 0x0c046b34
    .word 0x00000000
    .word 0x24420009
    .word 0x28420040
    .word 0x14400008
    .word 0x3c02004f
    .word 0x3c04004e
    .word 0x3c060049
    .word 0x24842bf0
    .word 0x24c6f4b0
    .word 0x0c0450c8
    .word 0x240502af
    .word 0x3c02004f
    .word 0x3c03004e
    .word 0x2451c1c0
    .word 0x0200282d
    .word 0x24692c10
    .word 0x2448c1c0
    .word 0x69260007
    .word 0x6d260000
    .word 0xb1060007
    .word 0xb5060000
    .word 0x0c0469ef
    .word 0x0220202d
    .word 0x0200202d
    .word 0x0c04a288
    .word 0x2405002c
    .word 0x14400006
    .word 0x3c05004e
    .word 0x0220202d
    .word 0x0c0469ef
    .word 0x24a52c18
    .word 0x10000013
    .word 0x24020002
    .word 0x0c046b34
    .word 0x0200202d
    .word 0x1040000c
    .word 0x02021021
    .word 0x2403002c
    .word 0x8044ffff
    .word 0x10830008
    .word 0x2402002f
    .word 0x10820006
    .word 0x2402005c
    .word 0x10820004
    .word 0x3c05004e
    .word 0x0220202d
    .word 0x0c0469ef
    .word 0x24a52c20
    .word 0x10000002
    .word 0x24020002
    .word 0x8f82883c
    .word 0xaf828838
    .word 0xdfbf0020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0030
}
#else
extern const char D_4E2BF0[];
extern const char D_48F4B0[];
extern const char D_4E2C10[];
extern const char D_4E2C18[];
extern const char D_4E2C20[];
extern char D_4EC1C0[64];
extern int s_hd_flag77c8;
extern int s_hd_flag77c4;

void func_114320(const char *, int, const char *);
int func_0011ACD0(const char *);
char *func_00128A20(char *, int);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);

int func_00129248(const char *name) {
    if (name != 0) {
        int len = func_0011ACD0(name);
        if (len + 9 >= 0x40) {
            func_114320(D_4E2BF0, 0x2af, D_48F4B0);
        }
        strcpy(D_4EC1C0, D_4E2C10);
        strcat(D_4EC1C0, name);
        if (func_00128A20((char *)name, 0x2c) == 0) {
            strcat(D_4EC1C0, D_4E2C18);
        } else {
            len = func_0011ACD0(name);
            if (len != 0) {
                char last = name[len - 1];
                if (last != 0x2c && last != 0x2f && last != 0x5c) {
                    strcat(D_4EC1C0, D_4E2C20);
                }
            }
        }
        s_hd_flag77c8 = 2;
    } else {
        s_hd_flag77c8 = s_hd_flag77c4;
    }
    return s_hd_flag77c8;
}
#endif

}
