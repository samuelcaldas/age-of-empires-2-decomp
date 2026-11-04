#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_deserialize_child_entries.h"

static std::vector<char> s_stream_data;
static size_t s_stream_pos = 0;
static int s_method10_calls = 0;

extern "C" {
int func_226D90(void *stream, void *dst, int size) {
    (void)stream;
    assert(s_stream_pos + size <= s_stream_data.size());
    std::memcpy(dst, &s_stream_data[s_stream_pos], size);
    s_stream_pos += size;
    return size;
}

void *func_36C3F0(int size) {
    return std::malloc(size);
}
}

class MockChildCallback {
public:
    virtual void vfn0() {}
    virtual void vfn1() {}
    virtual void vfn2() {}
    virtual void vfn3() {}
    virtual void Method10(void *stream, unsigned char flag, void *p2, void *p3, int idx) {
        (void)stream; (void)flag; (void)p2; (void)p3; (void)idx;
        s_method10_calls++;
    }
};

struct ChildContainerMock {
    char pad_00[0x14];
    short count;
    char pad_16[2];
    void **items;
    char pad_1C[0x10];
    MockChildCallback *cb;
};

int main() {
    // Case 1: count <= 0
    {
        s_stream_data.clear();
        s_stream_pos = 0;
        short count = 0;
        s_stream_data.push_back(((char *)&count)[0]);
        s_stream_data.push_back(((char *)&count)[1]);

        ChildContainerMock mock;
        std::memset(&mock, 0, sizeof(mock));
        mock.items = (void **)0x1234;

        func_001EB440(&mock, (void *)0x100, NULL, NULL);
        assert(mock.items == NULL);
    }

    // Case 2: count = 2, one non-null item
    {
        s_stream_data.clear();
        s_stream_pos = 0;
        s_method10_calls = 0;

        short count = 2;
        s_stream_data.push_back(((char *)&count)[0]);
        s_stream_data.push_back(((char *)&count)[1]);

        // items data: [0x11111111, 0x00000000]
        void *items_data[2] = {(void *)0x11111111, NULL};
        for (size_t i = 0; i < sizeof(items_data); ++i) {
            s_stream_data.push_back(((char *)items_data)[i]);
        }
        // flag byte for item 0
        s_stream_data.push_back(0x42);

        MockChildCallback cb;

        ChildContainerMock mock;
        std::memset(&mock, 0, sizeof(mock));
        mock.cb = &cb;

        func_001EB440(&mock, (void *)0x100, NULL, NULL);
        assert(mock.items != NULL);
        assert(s_method10_calls == 1);

        std::free(mock.items);
    }

    return 0;
}
