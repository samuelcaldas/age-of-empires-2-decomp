extern "C" {

#if defined(__mips__)
asm char *func_00128A20(char *str, int ch) {
    .word 0x00052e00
    .word 0x80830000
    .word 0x00052e03
    .word 0x1060000c
    .word 0x0000102d
    .word 0x54650004
    .word 0x24840001
    .word 0x03e00008
    .word 0x0080102d
    .word 0x00000000
    .word 0x80830000
    .word 0x10600004
    .word 0x00000000
    .word 0x5465fffc
    .word 0x24840001
    .word 0x0080102d
    .word 0x03e00008
    .word 0x00000000
}
#else
char *func_00128A20(char *str, int ch) {
    char target = (char)ch;
    while (*str != 0) {
        if (*str == target) {
            return str;
        }
        str++;
    }
    return 0;
}
#endif

}
