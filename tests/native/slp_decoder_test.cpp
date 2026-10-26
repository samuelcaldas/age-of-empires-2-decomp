#include "slp.h"
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>

static void test_validate_header_valid(void) {
    SlpHeader hdr;
    std::memcpy(hdr.version, "2.0N", 4);
    hdr.num_frames = 15;
    std::memcpy(hdr.comment, "ArtHeader 1.000", 16);

    assert(slp_validate_header(&hdr) == 1);
}

static void test_validate_header_invalid(void) {
    SlpHeader hdr;
    std::memcpy(hdr.version, "1.00", 4);
    hdr.num_frames = 15;

    assert(slp_validate_header(&hdr) == 0);
    assert(slp_validate_header(NULL) == 0);

    std::memcpy(hdr.version, "2.0N", 4);
    hdr.num_frames = 0;
    assert(slp_validate_header(&hdr) == 0);

    hdr.num_frames = -5;
    assert(slp_validate_header(&hdr) == 0);
}

static void test_relocate_subimage_offsets(void) {
    SlpSubImageEntry entries[3];
    std::memset(entries, 0, sizeof(entries));

    entries[0].offset = 0x100;
    entries[0].flags = 1;
    entries[1].offset = 0x200;
    entries[1].flags = 0;
    entries[2].offset = 0x400;
    entries[2].flags = 1;

    slp_relocate_subimage_offsets(entries, 3, 0x1000);

    /* Flags with bit 0 set should be relocated */
    assert(entries[0].offset == 0x1100);
    assert(entries[0].size == 0x1108); /* 8-byte subheader offset adjustment */
    assert(entries[1].offset == 0x200); /* not relocated when flag 0 */
    assert(entries[2].offset == 0x1400);
    assert(entries[2].size == 0x1408);
}

static void test_relocate_row_edges(void) {
    unsigned int cmd_offsets[4] = { 0x10, 0x50, 0x90, 0xD0 };

    slp_relocate_row_edges(cmd_offsets, 4, 0x8000);

    assert(cmd_offsets[0] == 0x8010);
    assert(cmd_offsets[1] == 0x8050);
    assert(cmd_offsets[2] == 0x8090);
    assert(cmd_offsets[3] == 0x80D0);
}

static void test_validate_frame_bounds(void) {
    SlpFrameHeader frame;
    frame.width = 64;
    frame.height = 64;
    frame.hotspot_x = 32;
    frame.hotspot_y = 32;

    assert(slp_validate_frame_bounds(&frame, 256, 256) == 1);
    assert(slp_validate_frame_bounds(&frame, 32, 64) == 0);
    assert(slp_validate_frame_bounds(&frame, 64, 32) == 0);

    frame.width = -1;
    assert(slp_validate_frame_bounds(&frame, 256, 256) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: slp_decoder_test <case_number>" << std::endl;
        return 1;
    }
    int c = std::atoi(argv[1]);
    switch (c) {
        case 0:
            test_validate_header_valid();
            test_validate_header_invalid();
            break;
        case 1:
            test_relocate_subimage_offsets();
            break;
        case 2:
            test_relocate_row_edges();
            break;
        case 3:
            test_validate_frame_bounds();
            break;
        default:
            std::cerr << "Unknown case: " << c << std::endl;
            return 2;
    }
    return 0;
}
