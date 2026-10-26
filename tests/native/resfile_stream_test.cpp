#include "resfile_stream.h"
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>

static void test_resfile_context_init(void) {
    ResfileContext ctx;
    ctx.stream_count = 5;
    ctx.error_code = 123;
    resfile_context_init(&ctx);

    assert(ctx.stream_count == 0);
    assert(ctx.error_code == 0);
    assert(ctx.total_bytes_streamed == 0);
}

static void test_resfile_register_and_find_stream(void) {
    ResfileContext ctx;
    char buffer[2048];
    resfile_context_init(&ctx);

    int idx = resfile_register_stream(&ctx, 1, 100, 0, 2048, buffer);
    assert(idx == 0);
    assert(ctx.stream_count == 1);

    int found = resfile_find_stream(&ctx, 1);
    assert(found == 0);

    int not_found = resfile_find_stream(&ctx, 2);
    assert(not_found == -1);
}

static void test_resfile_load_resource_success(void) {
    ResfileContext ctx;
    char stream_buf[4096];
    char dest_buf[1024];

    resfile_context_init(&ctx);
    std::memset(stream_buf, 0xAB, sizeof(stream_buf));
    std::memset(dest_buf, 0, sizeof(dest_buf));

    resfile_register_stream(&ctx, 1, 100, 0, sizeof(stream_buf), stream_buf);

    DrsResourceRecord record;
    record.id = 50000;
    record.offset = 512;
    record.size = 256;

    int res = resfile_load_resource(&ctx, 1, 50000, &record, dest_buf, sizeof(dest_buf));
    assert(res == 256);
    assert((unsigned char)dest_buf[0] == 0xAB);
    assert((unsigned char)dest_buf[255] == 0xAB);
    assert(ctx.total_bytes_streamed == 256);
}

static void test_resfile_load_resource_overflow_check(void) {
    ResfileContext ctx;
    char stream_buf[2048];
    char dest_buf[128];

    resfile_context_init(&ctx);
    resfile_register_stream(&ctx, 1, 100, 0, sizeof(stream_buf), stream_buf);

    DrsResourceRecord record;
    record.id = 50001;
    record.offset = 0;
    record.size = 512; /* Exceeds dest_buf capacity */

    int res = resfile_load_resource(&ctx, 1, 50001, &record, dest_buf, sizeof(dest_buf));
    assert(res == -1); /* Overflow error */
    assert(ctx.error_code == -2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: resfile_stream_test <case_number>" << std::endl;
        return 1;
    }
    int c = std::atoi(argv[1]);
    switch (c) {
        case 0:
            test_resfile_context_init();
            break;
        case 1:
            test_resfile_register_and_find_stream();
            break;
        case 2:
            test_resfile_load_resource_success();
            break;
        case 3:
            test_resfile_load_resource_overflow_check();
            break;
        default:
            std::cerr << "Unknown case: " << c << std::endl;
            return 2;
    }
    return 0;
}
