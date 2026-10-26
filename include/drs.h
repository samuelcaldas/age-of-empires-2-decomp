#ifndef DRS_H
#define DRS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DRS_HEADER_COPYRIGHT_LEN 40
#define DRS_HEADER_VERSION_LEN 4
#define DRS_HEADER_TYPE_LEN 12

#define DRS_TAG_SLP 0x20706C73  /* 'slp ' in little-endian */
#define DRS_TAG_PAL 0x206C6170  /* 'pal ' in little-endian */
#define DRS_TAG_WAV 0x20766177  /* 'wav ' in little-endian */
#define DRS_TAG_BIN 0x616E6962  /* 'bina' in little-endian */

typedef struct DrsHeader {
    char copyright[DRS_HEADER_COPYRIGHT_LEN];
    char version[DRS_HEADER_VERSION_LEN];
    char file_type[DRS_HEADER_TYPE_LEN];
    unsigned int table_count;
    unsigned int first_table_offset;
} DrsHeader;

typedef struct DrsTableRecord {
    unsigned int resource_type;
    unsigned int offset;
    unsigned int count;
} DrsTableRecord;

typedef struct DrsResourceRecord {
    unsigned int id;
    unsigned int offset;
    unsigned int size;
} DrsResourceRecord;

/* DRS Parser API */
int drs_validate_header(const DrsHeader *hdr);
const DrsTableRecord *drs_find_table(const DrsHeader *hdr, const DrsTableRecord *tables, unsigned int type);
const DrsResourceRecord *drs_find_resource(const DrsResourceRecord *records, unsigned int count, unsigned int resource_id);
int drs_calculate_aligned_size(unsigned int size, unsigned int alignment);

#ifdef __cplusplus
}
#endif

#endif /* DRS_H */
