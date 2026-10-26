#include "drs.h"
#include <string.h>

extern "C" {

int drs_validate_header(const DrsHeader *hdr) {
    if (hdr == NULL) {
        return 0;
    }
    if (memcmp(hdr->version, "1.00", 4) != 0) {
        return 0;
    }
    if (memcmp(hdr->file_type, "tribe", 5) != 0) {
        return 0;
    }
    return 1;
}

const DrsTableRecord *drs_find_table(const DrsHeader *hdr, const DrsTableRecord *tables, unsigned int type) {
    unsigned int i;
    if (hdr == NULL || tables == NULL) {
        return NULL;
    }
    for (i = 0; i < hdr->table_count; ++i) {
        if (tables[i].resource_type == type) {
            return &tables[i];
        }
    }
    return NULL;
}

const DrsResourceRecord *drs_find_resource(const DrsResourceRecord *records, unsigned int count, unsigned int resource_id) {
    int left;
    int right;
    if (records == NULL || count == 0) {
        return NULL;
    }
    left = 0;
    right = (int)count - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (records[mid].id == resource_id) {
            return &records[mid];
        }
        if (records[mid].id < resource_id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

int drs_calculate_aligned_size(unsigned int size, unsigned int alignment) {
    unsigned int mask;
    if (alignment == 0) {
        return (int)size;
    }
    mask = alignment - 1;
    return (int)((size + mask) & ~mask);
}

}
