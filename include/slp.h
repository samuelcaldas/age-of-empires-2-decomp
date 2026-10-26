#ifndef SLP_H
#define SLP_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SLP_VERSION_LEN 4
#define SLP_COMMENT_LEN 24

typedef struct SlpHeader {
    char version[SLP_VERSION_LEN];
    int num_frames;
    char comment[SLP_COMMENT_LEN];
} SlpHeader;

typedef struct SlpFrameHeader {
    unsigned int cmd_table_offset;
    unsigned int outline_offset;
    unsigned int palette_offset;
    unsigned int properties;
    int width;
    int height;
    int hotspot_x;
    int hotspot_y;
} SlpFrameHeader;

typedef struct SlpSubImageEntry {
    void *reserved;
    int index;
    unsigned int offset;
    unsigned int size;
    unsigned int flags;
} SlpSubImageEntry;

/* SLP Decoder & Relocation API */
int slp_validate_header(const SlpHeader *hdr);
void slp_relocate_subimage_offsets(SlpSubImageEntry *entries, int count, unsigned int base_offset);
void slp_relocate_row_edges(unsigned int *cmd_offsets, int count, unsigned int base_offset);
int slp_validate_frame_bounds(const SlpFrameHeader *frame, int max_w, int max_h);

#ifdef __cplusplus
}
#endif

#endif /* SLP_H */
