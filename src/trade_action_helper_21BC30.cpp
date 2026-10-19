#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_12C388(int lba, int num_sectors, void *target_buffer, int *out_status);
void *func_117AF8(void *dst, const void *src, int len);

extern int D_004E32E0;
extern char D_01E98000[];

int func_0021BC30(void *stream_info, void *dest, int offset, int count, int direct_flag) {
    char *stream = (char *)stream_info;
    int sector_base = *(int *)(stream + 4);
    int intra = offset;

    if (offset != 0) {
        sector_base += offset >> 11;
        intra = offset & 0x7FF;
    }

    if (count == 0) {
        count = *(int *)stream;
    }

    int total = count + intra;
    if (total & 0x7FF) {
        total = (total & ~0x7FF) + 0x800;
    }

    int use_staging = 0;
    char *target_buf = (char *)dest;
    if (direct_flag == 0) {
        if (intra != 0 || (count & 0x7FF) != 0) {
            use_staging = 1;
            target_buf = D_01E98000;
        }
    }

    char *dst_ptr = (char *)dest;

    while (total != 0) {
        int chunk = total;
        if (use_staging != 0 && chunk > 0x100000) {
            chunk = 0x100000;
        }

        if (D_004E32E0 == 0) {
            int num_sec = chunk >> 11;
            int status;
            while (!func_12C388(sector_base + 0xC350, num_sec, target_buf, &status) || status != 1) {
            }
        }

        if (use_staging != 0) {
            char *src = target_buf + intra;
            int avail = chunk - intra;
            int to_copy = count;
            if (count < avail) {
                to_copy = count;
            } else {
                to_copy = avail;
            }
            func_117AF8(dst_ptr, src, to_copy);
            count -= to_copy;
            dst_ptr += to_copy;
        }

        sector_base += chunk >> 11;
        total -= chunk;
        intra = 0;
    }

    return 1;
}

int func_0021BDD0() {
    return 0x175E9;
}

void func_0021BDE0(int val) {
    D_004E32E0 = val;
}
}
