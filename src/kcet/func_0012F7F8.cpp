#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

struct sceMcTblGetDir {
    u8 pad0;
    u8 create_sec;    // 1
    u8 create_min;    // 2
    u8 create_hour;   // 3
    u8 create_day;    // 4
    u8 create_month;  // 5
    u16 create_year;  // 6
    u8 pad8;          // 8
    u8 modify_sec;    // 9
    u8 modify_min;    // 0xa
    u8 modify_hour;   // 0xb
    u8 modify_day;    // 0xc
    u8 modify_month;  // 0xd
    u16 modify_year;  // 0xe
    u32 file_size;    // 0x10
    u16 attr_file;    // 0x14
    u8 pad16[0x20 - 0x16];
    char name[0x20];  // 0x20
};

extern const char D_004902F0[];
extern const char D_00490300[];
extern const char D_00490360[];
void func_118de0(const char *fmt, ...);

#if defined(__mips__)
asm void func_0012F7F8(sceMcTblGetDir *a0, s32 a1) {
    .word 0x27bdff50
    .word 0xffb20060
    .word 0x0080902d
    .word 0xffb40080
    .word 0x3c040049
    .word 0x00a0a02d
    .word 0xffbf00a0
    .word 0x248402f0
    .word 0xffb50090
    .word 0xffb30070
    .word 0xffb10050
    .word 0x0c046378
    .word 0xffb00040
    .word 0x12800025
    .word 0x3c040049
    .word 0x1a80002d
    .word 0x0000982d
    .word 0x3c150049
    .word 0x924f000a
    .word 0x00000000
    .word 0x26510020
    .word 0x9250000b
    .word 0x26a40300
    .word 0x924e000c
    .word 0x26730001
    .word 0x9242000d
    .word 0x9643000e
    .word 0x8e4c0010
    .word 0x964d0014
    .word 0x92450001
    .word 0x92460002
    .word 0x92470003
    .word 0x92480004
    .word 0x92490005
    .word 0x964a0006
    .word 0x924b0009
    .word 0xafaf0000
    .word 0x26520040
    .word 0xafb00008
    .word 0xafae0010
    .word 0xafa20018
    .word 0xafa30020
    .word 0xafac0028
    .word 0xafad0030
    .word 0x0c046378
    .word 0xafb10038
    .word 0x0274182a
    .word 0x5460ffe4
    .word 0x924f000a
    .word 0x1000000c
    .word 0xdfbf00a0
    .word 0xdfbf00a0
    .word 0xdfb50090
    .word 0x24840360
    .word 0xdfb40080
    .word 0xdfb30070
    .word 0xdfb20060
    .word 0xdfb10050
    .word 0xdfb00040
    .word 0x08046378
    .word 0x27bd00b0
    .word 0xdfbf00a0
    .word 0xdfb50090
    .word 0xdfb40080
    .word 0xdfb30070
    .word 0xdfb20060
    .word 0xdfb10050
    .word 0xdfb00040
    .word 0x03e00008
    .word 0x27bd00b0
}
#else
void func_0012F7F8(sceMcTblGetDir *tbl, s32 count) {
    func_118de0(D_004902F0);
    if (count == 0) {
        func_118de0(D_00490360);
        return;
    }
    for (s32 i = 0; i < count; i++) {
        func_118de0(
            D_00490300,
            tbl->create_sec,
            tbl->create_min,
            tbl->create_hour,
            tbl->create_day,
            tbl->create_month,
            tbl->create_year,
            tbl->modify_sec,
            tbl->modify_min,
            tbl->modify_hour,
            tbl->modify_day,
            tbl->modify_month,
            tbl->modify_year,
            tbl->file_size,
            tbl->attr_file,
            tbl->name
        );
        tbl++;
    }
}
#endif

}
