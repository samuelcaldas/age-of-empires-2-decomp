#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define func_00226D90 mock_func_00226D90
#define func_00100630 mock_func_00100630
#define func_00100730 mock_func_00100730
#define D_938AC0 mock_D_938AC0
#define D_938CC0 mock_D_938CC0

static int g_stream_read_offset = 0;
static char g_stream_data[1024];

static int g_freed_count = 0;
static int g_alloc_count = 0;

extern "C" {
int mock_D_938AC0[128];
short *mock_D_938CC0[128];

void mock_func_00226D90(void *stream, void *data, int size) {
    memcpy(data, g_stream_data + g_stream_read_offset, size);
    g_stream_read_offset += size;
}

void mock_func_00100630(void *ptr) {
    g_freed_count++;
    free(ptr);
}

void *mock_func_00100730(unsigned int size) {
    g_alloc_count++;
    return malloc(size);
}
}

#include "../../src/zone/zone_raster_deserialize.cpp"

int main() {
    ZoneLayout *layout = (ZoneLayout *)calloc(1, sizeof(ZoneLayout));
    assert(layout != NULL);

    // Prepare stream data:
    // f_8ED0 (count) = 1
    // f_8ED4 = 100 (< 128, should clamp to 128)
    // f_8ED8 data: int value = 42
    // pt_count = 2
    // pts: short[4] = { 10, 20, 30, 40 }
    int *pInt = (int *)g_stream_data;
    pInt[0] = 1;   // count
    pInt[1] = 100; // f_8ED4
    pInt[2] = 42;  // data for f_8ED8[0]
    pInt[3] = 2;   // pt_count
    short *pPts = (short *)&pInt[4];
    pPts[0] = 10;
    pPts[1] = 20;
    pPts[2] = 30;
    pPts[3] = 40;

    func_001CAD90(layout, g_stream_data);

    assert(layout->f_8ED0 == 1);
    assert(layout->f_8ED4 == 128); // clamped
    assert(layout->f_8ED8[0] == 42);
    assert(layout->f_8EDC[0] != NULL);
    assert(layout->f_8EDC[0][0] == 2);
    assert(layout->f_8EDC[0][1] == 3);
    assert(layout->f_8EDC[0][2] == 10);
    assert(layout->f_8EDC[0][3] == 20);
    assert(layout->f_8EDC[0][4] == 30);
    assert(layout->f_8EDC[0][5] == 40);

    // Call again to verify freeing of previous allocated buffer
    g_stream_read_offset = 0;
    func_001CAD90(layout, g_stream_data);
    assert(g_freed_count == 1);

    free(layout->f_8EDC[0]);
    free(layout);
    printf("zone_raster_deserialize_test passed\n");
    return 0;
}
