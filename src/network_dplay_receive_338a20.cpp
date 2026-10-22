#include "network_dplay_3380e0.h"

extern int D_004E3560[2];

extern "C" {
    int func_104D60(int semaphore);
    int func_104D40(int semaphore);
    int func_117AF8(void *destination, const void *source, int size);
}

extern "C" int func_00338A20(void *self, int *from_id, int *to_id, int flags, void *data, int *size) {
    (void)flags;
    int *fields = static_cast<int *>(self);
    func_104D60(D_004E3560[1]);
    if (fields[844] >= 2048) {
        fields[844] = 0;
    }
    if (fields[843] <= 0) {
        fields[844] = 0;
        fields[846] = 0;
        fields[845] = 0;
        fields[843] = 0;
        func_104D40(D_004E3560[1]);
        return static_cast<int>(0x887700BEu);
    }
    char *entry = static_cast<char *>(self) + fields[844] + 1324;
    if (reinterpret_cast<int>(entry) & 3) {
        func_104D40(D_004E3560[1]);
        return static_cast<int>(0x887700BEu);
    }
    int *hdr = reinterpret_cast<int *>(entry);
    *from_id = hdr[1];
    *to_id = hdr[0];
    int payload_size = hdr[3] & 0x7FFFFFFF;
    *size = payload_size;
    if (!data) {
        func_104D40(D_004E3560[1]);
        return 0;
    }
    func_117AF8(data, entry + 16, payload_size);
    --fields[843];
    if (hdr[3] & static_cast<int>(0x80000000u)) {
        hdr[3] &= 0x7FFFFFFF;
        fields[844] = 0;
    } else {
        fields[844] += ((payload_size + 3) & -4) + 16;
    }
    func_104D40(D_004E3560[1]);
    return 0;
}
