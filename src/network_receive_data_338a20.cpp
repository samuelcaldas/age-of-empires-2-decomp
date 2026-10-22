#include "network_receive_data_338a20.h"

extern int D_004E3564;
extern "C" {
int func_104D60(int semaphore);
int func_104D40(int semaphore);
int func_117AF8(void *destination, const void *source, int size);
}

int func_00338A20(void *object, void *out_player, void *out_type,
                  void *buffer, int *out_size, int copy) {
    char *base = (char *)object;
    func_104D60(D_004E3564);
    int offset = *(int *)(base + 3376);
    if (offset >= 2048) {
        *(int *)(base + 3376) = 0;
    }
    int count = *(int *)(base + 3372);
    if (count <= 0) {
        *(int *)(base + 3376) = 0;
        *(int *)(base + 3384) = 0;
        *(int *)(base + 3380) = 0;
        *(int *)(base + 3372) = 0;
        func_104D40(D_004E3564);
        return (int)0x887700BE;
    }
    offset = *(int *)(base + 3376);
    char *entry = base + 1324 + offset;
    if (((unsigned int)entry & 3) != 0) {
        func_104D40(D_004E3564);
        return (int)0x887700BE;
    }
    *(int *)out_player = *(int *)(entry + 4);
    *(int *)out_type = *(int *)(entry + 0);
    int length = *(int *)(entry + 12) & 0x7fffffff;
    *out_size = length;
    if (copy) {
        func_117AF8(buffer, entry + 16, length);
    }
    --*(int *)(base + 3372);
    if (*(unsigned int *)(entry + 12) & 0x80000000u) {
        *(int *)(entry + 12) = length;
        *(int *)(base + 3376) = 0;
    } else {
        *(int *)(base + 3376) = offset + 16 + ((length + 3) & ~3);
    }
    func_104D40(D_004E3564);
    return 0;
}
