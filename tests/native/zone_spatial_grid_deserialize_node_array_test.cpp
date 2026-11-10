#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_deserialize_node_array.h"

void *D_4D99B0[10];

static std::vector<char> s_stream_data;
static size_t s_stream_pos = 0;

static int s_func_1143F8_calls = 0;

extern "C" {
int func_226D90(void *stream, void *dst, int size) {
    (void)stream;
    assert(s_stream_pos + size <= s_stream_data.size());
    std::memcpy(dst, &s_stream_data[s_stream_pos], size);
    s_stream_pos += size;
    return size;
}

void *func_1143F8(int count, int elem_size) {
    s_func_1143F8_calls++;
    return std::malloc(count * elem_size);
}
}

struct NodeArrayHeaderMock {
    char pad_00[0x1C];
    short count;
    char pad_1E[2];
    void *buffer;
    char field_24;
    char pad_25[1];
    short field_26;
    short field_28;
    char pad_2A[2];
    void *vtable;
};

int main() {
    // Test Case 1: count > 0
    {
        s_stream_data.clear();
        s_stream_pos = 0;
        s_func_1143F8_calls = 0;

        // 0x14 bytes header
        for (int i = 0; i < 0x14; ++i) s_stream_data.push_back((char)i);
        // count = 3 (short)
        short count = 3;
        s_stream_data.push_back(((char *)&count)[0]);
        s_stream_data.push_back(((char *)&count)[1]);
        // field_26 = 0x1234
        short f26 = 0x1234;
        s_stream_data.push_back(((char *)&f26)[0]);
        s_stream_data.push_back(((char *)&f26)[1]);
        // field_28 = 0x5678
        short f28 = 0x5678;
        s_stream_data.push_back(((char *)&f28)[0]);
        s_stream_data.push_back(((char *)&f28)[1]);
        // buffer elements: count * 4 = 12 bytes
        int elements[3] = {111, 222, 333};
        for (size_t i = 0; i < sizeof(elements); ++i) {
            s_stream_data.push_back(((char *)elements)[i]);
        }
        // field_24 = 0x7F
        s_stream_data.push_back(0x7F);

        NodeArrayHeaderMock mock;
        std::memset(&mock, 0, sizeof(mock));

        void *ret = func_001EB2C0(&mock, (void *)0x1000);
        assert(ret == &mock);
        assert(mock.vtable == D_4D99B0);
        assert(mock.count == 3);
        assert(mock.field_26 == 0x1234);
        assert(mock.field_28 == 0x5678);
        assert(mock.field_24 == 0x7F);
        assert(mock.buffer != NULL);
        assert(s_func_1143F8_calls == 1);
        int *buf_ints = (int *)mock.buffer;
        assert(buf_ints[0] == 111);
        assert(buf_ints[1] == 222);
        assert(buf_ints[2] == 333);
        std::free(mock.buffer);
    }

    // Test Case 2: count <= 0
    {
        s_stream_data.clear();
        s_stream_pos = 0;
        s_func_1143F8_calls = 0;

        for (int i = 0; i < 0x14; ++i) s_stream_data.push_back(0);
        short count = 0;
        s_stream_data.push_back(0);
        s_stream_data.push_back(0);
        short f26 = 0;
        s_stream_data.push_back(0);
        s_stream_data.push_back(0);
        short f28 = 0;
        s_stream_data.push_back(0);
        s_stream_data.push_back(0);
        s_stream_data.push_back(0x42);

        NodeArrayHeaderMock mock;
        std::memset(&mock, 0, sizeof(mock));

        void *ret = func_001EB2C0(&mock, (void *)0x1000);
        assert(ret == &mock);
        assert(mock.vtable == D_4D99B0);
        assert(mock.count == 0);
        assert(mock.buffer == NULL);
        assert(mock.field_24 == 0x42);
        assert(s_func_1143F8_calls == 0);
    }

    return 0;
}
