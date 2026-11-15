#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct PadSlot {
    u8 pad[0x34];
    u32 unk_34;
};

extern "C" {

void func_001143C0(void *ptr, int size);

// Target: func_00125DD8 (0x00125DD8, size: 0xC)
void func_00125DD8(PadSlot *p) {
    func_001143C0(&p->unk_34, 4);
}

}

