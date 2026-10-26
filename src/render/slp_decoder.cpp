#include "slp.h"
#include <string.h>

extern "C" {

int slp_validate_header(const SlpHeader *hdr) {
    if (hdr == NULL) {
        return 0;
    }
    if (memcmp(hdr->version, "2.0N", 4) != 0) {
        return 0;
    }
    if (hdr->num_frames <= 0) {
        return 0;
    }
    return 1;
}

void slp_relocate_subimage_offsets(SlpSubImageEntry *entries, int count, unsigned int base_offset) {
    int i;
    if (entries == NULL || count <= 0) {
        return;
    }
    for (i = 0; i < count; ++i) {
        if ((entries[i].flags & 1) != 0) {
            entries[i].offset += base_offset;
            entries[i].size = entries[i].offset + 8;
        }
    }
}

void slp_relocate_row_edges(unsigned int *cmd_offsets, int count, unsigned int base_offset) {
    int i;
    if (cmd_offsets == NULL || count <= 0) {
        return;
    }
    for (i = 0; i < count; ++i) {
        cmd_offsets[i] += base_offset;
    }
}

int slp_validate_frame_bounds(const SlpFrameHeader *frame, int max_w, int max_h) {
    if (frame == NULL) {
        return 0;
    }
    if (frame->width <= 0 || frame->height <= 0) {
        return 0;
    }
    if (frame->width > max_w || frame->height > max_h) {
        return 0;
    }
    return 1;
}

}
