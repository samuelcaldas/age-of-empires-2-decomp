#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_12C388(int lba, int num_sectors, void *target_buffer, int *out_status);
void *func_117AF8(void *dst, const void *src, int len);

extern int D_004E32E0;
extern char D_01E98000[];

int func_0021BDD0() {
    return 0x175E9;
}

void func_0021BDE0(int val) {
    D_004E32E0 = val;
}

static void ReadSectorsBlocking(int lba, int num_sectors, void *target_buffer) {
    int status = 0;
    while (!func_12C388(lba, num_sectors, target_buffer, &status) || status != 1) {
    }
}

static void CopyStagedData(char **dest_ptr, const char *src_buffer, int intra_sector_offset, int chunk_size, int *remaining_count) {
    int available = chunk_size - intra_sector_offset;
    int to_copy = *remaining_count;
    if (available < to_copy) {
        to_copy = available;
    }
    func_117AF8(*dest_ptr, src_buffer + intra_sector_offset, to_copy);
    *remaining_count -= to_copy;
    *dest_ptr += to_copy;
}

static int CalculateTotalRounded(int count, int intra_sector_offset) {
    int total = count + intra_sector_offset;
    if ((total & 0x7FF) == 0) {
        return total;
    }
    return (total & ~0x7FF) + 0x800;
}

static int DetermineStaging(int direct_flag, int intra_sector_offset, int count) {
    if (direct_flag != 0) {
        return 0;
    }
    if (intra_sector_offset != 0) {
        return 1;
    }
    if ((count & 0x7FF) != 0) {
        return 1;
    }
    return 0;
}

int func_0021BC30(void *stream_info, void *dest, int offset, int count, int direct_flag) {
    char *stream = (char *)stream_info;
    int sector_base = *(int *)(stream + 4);
    int intra_sector_offset = 0;

    if (offset != 0) {
        sector_base += offset >> 11;
        intra_sector_offset = offset & 0x7FF;
    }

    if (count == 0) {
        count = *(int *)stream;
    }

    int remaining_total = CalculateTotalRounded(count, intra_sector_offset);
    int use_staging = DetermineStaging(direct_flag, intra_sector_offset, count);

    char *target_buffer = (char *)dest;
    if (use_staging != 0) {
        target_buffer = D_01E98000;
    }

    char *dest_ptr = (char *)dest;

    while (remaining_total != 0) {
        int chunk_size = remaining_total;
        if (use_staging != 0 && chunk_size > 0x100000) {
            chunk_size = 0x100000;
        }

        if (D_004E32E0 == 0) {
            int num_sectors = chunk_size >> 11;
            ReadSectorsBlocking(sector_base + 0xC350, num_sectors, target_buffer);
        }

        if (use_staging != 0) {
            CopyStagedData(&dest_ptr, target_buffer, intra_sector_offset, chunk_size, &count);
        }

        int sectors_done = chunk_size >> 11;
        remaining_total -= chunk_size;
        sector_base += sectors_done;
        intra_sector_offset = 0;
    }

    return 1;
}
}
