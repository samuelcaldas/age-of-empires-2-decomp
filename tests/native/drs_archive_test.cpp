#include "drs.h"
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>

static void test_validate_header_valid(void) {
    DrsHeader hdr;
    std::memset(&hdr, 0, sizeof(hdr));
    std::memcpy(hdr.copyright, "Copyright (c) 1997 Ensemble Studios.", 36);
    std::memcpy(hdr.version, "1.00", 4);
    std::memcpy(hdr.file_type, "tribe", 5);
    hdr.table_count = 3;
    hdr.first_table_offset = 64;

    assert(drs_validate_header(&hdr) == 1);
}

static void test_validate_header_invalid_magic(void) {
    DrsHeader hdr;
    std::memset(&hdr, 0, sizeof(hdr));
    std::memcpy(hdr.copyright, "Invalid copyright header", 24);
    std::memcpy(hdr.version, "2.00", 4);
    std::memcpy(hdr.file_type, "other", 5);
    hdr.table_count = 3;
    hdr.first_table_offset = 64;

    assert(drs_validate_header(&hdr) == 0);
}

static void test_validate_header_null(void) {
    assert(drs_validate_header(NULL) == 0);
}

static void test_find_table_found(void) {
    DrsHeader hdr;
    std::memset(&hdr, 0, sizeof(hdr));
    hdr.table_count = 3;

    DrsTableRecord tables[3] = {
        { DRS_TAG_PAL, 0x1000, 10 },
        { DRS_TAG_SLP, 0x2000, 50 },
        { DRS_TAG_WAV, 0x3000, 20 }
    };

    const DrsTableRecord *found = drs_find_table(&hdr, tables, DRS_TAG_SLP);
    assert(found != NULL);
    assert(found->resource_type == DRS_TAG_SLP);
    assert(found->offset == 0x2000);
    assert(found->count == 50);
}

static void test_find_table_not_found(void) {
    DrsHeader hdr;
    std::memset(&hdr, 0, sizeof(hdr));
    hdr.table_count = 2;

    DrsTableRecord tables[2] = {
        { DRS_TAG_PAL, 0x1000, 10 },
        { DRS_TAG_WAV, 0x3000, 20 }
    };

    const DrsTableRecord *found = drs_find_table(&hdr, tables, DRS_TAG_SLP);
    assert(found == NULL);
}

static void test_find_resource_binary_search(void) {
    DrsResourceRecord records[4] = {
        { 100, 0x10000, 500 },
        { 200, 0x10200, 1200 },
        { 300, 0x10700, 800 },
        { 50000, 0x20000, 4096 }
    };

    const DrsResourceRecord *res = drs_find_resource(records, 4, 300);
    assert(res != NULL);
    assert(res->id == 300);
    assert(res->offset == 0x10700);
    assert(res->size == 800);

    const DrsResourceRecord *res2 = drs_find_resource(records, 4, 50000);
    assert(res2 != NULL);
    assert(res2->id == 50000);
    assert(res2->offset == 0x20000);

    const DrsResourceRecord *missing = drs_find_resource(records, 4, 999);
    assert(missing == NULL);
}

static void test_calculate_aligned_size(void) {
    assert(drs_calculate_aligned_size(100, 16) == 112);
    assert(drs_calculate_aligned_size(128, 16) == 128);
    assert(drs_calculate_aligned_size(0, 16) == 0);
    assert(drs_calculate_aligned_size(2000, 2048) == 2048);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: drs_archive_test <case_number>" << std::endl;
        return 1;
    }
    int c = std::atoi(argv[1]);
    switch (c) {
        case 0:
            test_validate_header_valid();
            test_validate_header_invalid_magic();
            test_validate_header_null();
            break;
        case 1:
            test_find_table_found();
            test_find_table_not_found();
            break;
        case 2:
            test_find_resource_binary_search();
            break;
        case 3:
            test_calculate_aligned_size();
            break;
        default:
            std::cerr << "Unknown case: " << c << std::endl;
            return 2;
    }
    return 0;
}
