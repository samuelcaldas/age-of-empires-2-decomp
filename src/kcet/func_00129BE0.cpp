extern "C" {

#if defined(__mips__)
asm void func_00129BE0(void) {
    .word 0x27bdffa0
    .word 0xffb40040
    .word 0xffb20020
    .word 0x00c0a02d
    .word 0xffb10010
    .word 0x00a0902d
    .word 0xffb00000
    .word 0x0080882d
    .word 0xffbf0050
    .word 0x00e0802d
    .word 0x11000004
    .word 0xffb30030
    .word 0x3c02004e
    .word 0x10000003
    .word 0x24532c48
    .word 0x3c02004e
    .word 0x24532c38
    .word 0x12400004
    .word 0x3c040049
    .word 0x56200008
    .word 0x0220202d
    .word 0x3c040049
    .word 0x3c060049
    .word 0x2484f500
    .word 0x24c6f890
    .word 0x0c0450c8
    .word 0x240502a4
    .word 0x0220202d
    .word 0x0c046aef
    .word 0x0260282d
    .word 0x0200282d
    .word 0x0c0469ef
    .word 0x0220202d
    .word 0x0c046b34
    .word 0x0220202d
    .word 0x02221021
    .word 0x2404005c
    .word 0x8043ffff
    .word 0x10640005
    .word 0x00000000
    .word 0x3c05004e
    .word 0x0220202d
    .word 0x0c0469ef
    .word 0x24a52c30
    .word 0x0c046b34
    .word 0x0280202d
    .word 0x0040802d
    .word 0x0280282d
    .word 0x0200302d
    .word 0x0c046bee
    .word 0x0240202d
    .word 0x02502821
    .word 0x0220202d
    .word 0x0c0469ef
    .word 0x0242280b
    .word 0x3c05004e
    .word 0x0220202d
    .word 0x0c0469ef
    .word 0x24a52c50
    .word 0x0c046b34
    .word 0x0220202d
    .word 0x0040802d
    .word 0x0c046b34
    .word 0x0260202d
    .word 0x0040482d
    .word 0x0130102a
    .word 0x10400014
    .word 0xdfbf0050
    .word 0x3c0a0049
    .word 0x00000000
    .word 0x02294021
    .word 0x2544e101
    .word 0x91050000
    .word 0x2406005c
    .word 0x25290001
    .word 0x00a42021
    .word 0x24a3ffe0
    .word 0x90820000
    .word 0x0130382a
    .word 0x30420002
    .word 0x00a2180a
    .word 0x306300ff
    .word 0x3862002f
    .word 0x0062300b
    .word 0x14e0fff1
    .word 0xa1060000
    .word 0xdfbf0050
    .word 0xdfb40040
    .word 0xdfb30030
    .word 0xdfb20020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0060
}
#else

void func_114320(const char *file, int line, const char *assertion);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int func_0011ACD0(const char *s);
int func_11AFB8(const char *s1, const char *s2, int n);

extern const char D_004E2C38[];
extern const char D_004E2C48[];
extern const char D_0048F500[];
extern const char D_0048F890[];
extern const char D_004E2C30[];
extern const char D_004E2C50[];
extern const char D_0048E101[];

void func_00129BE0(char *dest, const char *src, const char *prefix, const char *base, int use_cdrom) {
    const char *scheme;
    if (use_cdrom) {
        scheme = D_004E2C48;
    } else {
        scheme = D_004E2C38;
    }

    if (!src || !dest) {
        func_114320(D_0048F500, 0x2A4, D_0048F890);
    }

    strcpy(dest, scheme);
    strcat(dest, base);

    int len = func_0011ACD0(dest);
    if (dest[len - 1] != '\\') {
        strcat(dest, D_004E2C30);
    }

    int prefix_len = func_0011ACD0(prefix);
    const char *p = src;
    if (func_11AFB8(src, prefix, prefix_len) != 0) {
        p = src + prefix_len;
    }
    strcat(dest, p);
    strcat(dest, D_004E2C50);

    int dest_len = func_0011ACD0(dest);
    int scheme_len = func_0011ACD0(scheme);

    for (int i = scheme_len; i < dest_len; i++) {
        char c = dest[i];
        if (D_0048E101[(unsigned char)c] & 2) {
            c = c - 0x20;
        }
        if (c == '/') {
            c = '\\';
        }
        dest[i] = c;
    }
}

#endif

}
