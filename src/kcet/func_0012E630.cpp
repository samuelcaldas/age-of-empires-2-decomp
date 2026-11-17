#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { s32 v[4]; } S_bgCol;
typedef struct { float v[4]; } S_vec4;
typedef struct { S_vec4 v[3]; } S_vec4_3;
typedef struct { S_bgCol v[4]; } S_bgCol_4;

typedef struct {
    u8 head[4];
    u16 type;
    u16 nlOffset;
    u32 unknown2;
    u32 trans;
    S_bgCol_4 bgCol;
    S_vec4_3 lightDir;
    S_vec4_3 lightCol;
    S_vec4 lightAmbient;
    u16 title[34];
    u8 view[64];
    u8 copy[64];
    u8 del[64];
    u8 unknown3[512];
} mcIcon;

extern "C" {

#if defined(__mips__)
asm void func_0012E630(void) {
    .word 0x27bdffb0 // 0x12E630
    .word 0x24070044 // 0x12E634
    .word 0xffb00000 // 0x12E638
    .word 0x24080058 // 0x12E63C
    .word 0x0080802d // 0x12E640
    .word 0xffb30030 // 0x12E644
    .word 0xffb20020 // 0x12E648
    .word 0x24020050 // 0x12E64C
    .word 0xffb10010 // 0x12E650
    .word 0x24030053 // 0x12E654
    .word 0xffbf0040 // 0x12E658
    .word 0x24040032 // 0x12E65C
    .word 0xa2020000 // 0x12E660
    .word 0x3c090039 // 0x12E664
    .word 0xa2030001 // 0x12E668
    .word 0x3c020039 // 0x12E66C
    .word 0xa2040002 // 0x12E670
    .word 0x3c030039 // 0x12E674
    .word 0xa2070003 // 0x12E678
    .word 0x3c0a0039 // 0x12E67C
    .word 0xa6060006 // 0x12E680
    .word 0x260400c0 // 0x12E684
    .word 0xae08000c // 0x12E688
    .word 0x26110104 // 0x12E68C
    .word 0x252bc8c0 // 0x12E690
    .word 0x69660007 // 0x12E694
    .word 0x6d660000 // 0x12E698
    .word 0x6967000f // 0x12E69C
    .word 0x6d670008 // 0x12E6A0
    .word 0x69680017 // 0x12E6A4
    .word 0x6d680010 // 0x12E6A8
    .word 0xb2060017 // 0x12E6AC
    .word 0xb6060010 // 0x12E6B0
    .word 0xb207001f // 0x12E6B4
    .word 0xb6070018 // 0x12E6B8
    .word 0xb2080027 // 0x12E6BC
    .word 0xb6080020 // 0x12E6C0
    .word 0x6966001f // 0x12E6C4
    .word 0x6d660018 // 0x12E6C8
    .word 0x69670027 // 0x12E6CC
    .word 0x6d670020 // 0x12E6D0
    .word 0x6968002f // 0x12E6D4
    .word 0x6d680028 // 0x12E6D8
    .word 0xb206002f // 0x12E6DC
    .word 0xb6060028 // 0x12E6E0
    .word 0xb2070037 // 0x12E6E4
    .word 0xb6070030 // 0x12E6E8
    .word 0xb208003f // 0x12E6EC
    .word 0xb6080038 // 0x12E6F0
    .word 0x69660037 // 0x12E6F4
    .word 0x6d660030 // 0x12E6F8
    .word 0x6967003f // 0x12E6FC
    .word 0x6d670038 // 0x12E700
    .word 0xb2060047 // 0x12E704
    .word 0xb6060040 // 0x12E708
    .word 0xb207004f // 0x12E70C
    .word 0xb6070048 // 0x12E710
    .word 0x26120144 // 0x12E714
    .word 0x2449c900 // 0x12E718
    .word 0x69260007 // 0x12E71C
    .word 0x6d260000 // 0x12E720
    .word 0x6927000f // 0x12E724
    .word 0x6d270008 // 0x12E728
    .word 0x69280017 // 0x12E72C
    .word 0x6d280010 // 0x12E730
    .word 0xb2060057 // 0x12E734
    .word 0xb6060050 // 0x12E738
    .word 0xb207005f // 0x12E73C
    .word 0xb6070058 // 0x12E740
    .word 0xb2080067 // 0x12E744
    .word 0xb6080060 // 0x12E748
    .word 0x6926001f // 0x12E74C
    .word 0x6d260018 // 0x12E750
    .word 0x69270027 // 0x12E754
    .word 0x6d270020 // 0x12E758
    .word 0x6928002f // 0x12E75C
    .word 0x6d280028 // 0x12E760
    .word 0xb206006f // 0x12E764
    .word 0xb6060068 // 0x12E768
    .word 0xb2070077 // 0x12E76C
    .word 0xb6070070 // 0x12E770
    .word 0xb208007f // 0x12E774
    .word 0xb6080078 // 0x12E778
    .word 0x2467c930 // 0x12E77C
    .word 0x68eb0007 // 0x12E780
    .word 0x6ceb0000 // 0x12E784
    .word 0x68e2000f // 0x12E788
    .word 0x6ce20008 // 0x12E78C
    .word 0x68e60017 // 0x12E790
    .word 0x6ce60010 // 0x12E794
    .word 0xb20b0087 // 0x12E798
    .word 0xb60b0080 // 0x12E79C
    .word 0xb202008f // 0x12E7A0
    .word 0xb6020088 // 0x12E7A4
    .word 0xb2060097 // 0x12E7A8
    .word 0xb6060090 // 0x12E7AC
    .word 0x68eb001f // 0x12E7B0
    .word 0x6ceb0018 // 0x12E7B4
    .word 0x68e20027 // 0x12E7B8
    .word 0x6ce20020 // 0x12E7BC
    .word 0x68e6002f // 0x12E7C0
    .word 0x6ce60028 // 0x12E7C4
    .word 0xb20b009f // 0x12E7C8
    .word 0xb60b0098 // 0x12E7CC
    .word 0xb20200a7 // 0x12E7D0
    .word 0xb60200a0 // 0x12E7D4
    .word 0xb20600af // 0x12E7D8
    .word 0xb60600a8 // 0x12E7DC
    .word 0x2542c960 // 0x12E7E0
    .word 0x68480007 // 0x12E7E4
    .word 0x6c480000 // 0x12E7E8
    .word 0x6849000f // 0x12E7EC
    .word 0x6c490008 // 0x12E7F0
    .word 0xb20800b7 // 0x12E7F4
    .word 0xb60800b0 // 0x12E7F8
    .word 0xb20900bf // 0x12E7FC
    .word 0xb60900b8 // 0x12E800
    .word 0x0c046aef // 0x12E804
    .word 0x26130184 // 0x12E808
    .word 0x0c04bb2a // 0x12E80C
    .word 0x24040002 // 0x12E810
    .word 0x0220202d // 0x12E814
    .word 0x0c046aef // 0x12E818
    .word 0x0040282d // 0x12E81C
    .word 0x0c04bb2a // 0x12E820
    .word 0x24040003 // 0x12E824
    .word 0x0240202d // 0x12E828
    .word 0x0c046aef // 0x12E82C
    .word 0x0040282d // 0x12E830
    .word 0x0c04bb2a // 0x12E834
    .word 0x24040004 // 0x12E838
    .word 0x0260202d // 0x12E83C
    .word 0x0c046aef // 0x12E840
    .word 0x0040282d // 0x12E844
    .word 0x26040004 // 0x12E848
    .word 0x0c0450f0 // 0x12E84C
    .word 0x24050002 // 0x12E850
    .word 0x26040008 // 0x12E854
    .word 0x0c0450f0 // 0x12E858
    .word 0x24050004 // 0x12E85C
    .word 0x260401c4 // 0x12E860
    .word 0xdfbf0040 // 0x12E864
    .word 0xdfb30030 // 0x12E868
    .word 0x24050200 // 0x12E86C
    .word 0xdfb20020 // 0x12E870
    .word 0xdfb10010 // 0x12E874
    .word 0xdfb00000 // 0x12E878
    .word 0x080450f0 // 0x12E87C
    .word 0x27bd0050 // 0x12E880
}
#else

char *strcpy(char *dest, const char *src);
void func_001143C0(void *ptr, s32 size);
const char *func_0012ECA8(s32 type);

extern const S_bgCol_4 D_38C8C0;
extern const S_vec4_3 D_38C900;
extern const S_vec4_3 D_38C930;
extern const S_vec4 D_38C960;

void func_0012E630(mcIcon *icon, const char *title, u16 nlOffset) {
    icon->head[0] = 'P';
    icon->head[1] = 'S';
    icon->head[2] = '2';
    icon->head[3] = 'D';
    icon->nlOffset = nlOffset;
    icon->trans = 0x58;

    icon->bgCol = D_38C8C0;
    icon->lightDir = D_38C900;
    icon->lightCol = D_38C930;
    icon->lightAmbient = D_38C960;

    strcpy((char *)icon->title, title);
    strcpy((char *)icon->view, func_0012ECA8(2));
    strcpy((char *)icon->copy, func_0012ECA8(3));
    strcpy((char *)icon->del, func_0012ECA8(4));

    func_001143C0(&icon->type, 2);
    func_001143C0(&icon->unknown2, 4);
    func_001143C0(icon->unknown3, 0x200);
}

#endif

}
