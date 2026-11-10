#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_deserialize_entity_factory.h"

struct MockEntity {
    virtual void v0() {}
    virtual void v1() {}
    virtual void deserialize(void *stream, void *p3, int flag) {
        deserialize_called = true;
        received_stream = stream;
        received_p3 = p3;
        received_flag = flag;
    }

    bool deserialize_called;
    void *received_stream;
    void *received_p3;
    int received_flag;

    MockEntity() : deserialize_called(false), received_stream(0), received_p3(0), received_flag(0) {}
};

static MockEntity g_mock_entity;
static int g_last_created_type = -1;
static bool g_factory_should_return_null = false;
static int g_func_3671F0_call_count = 0;
static int g_func_3671F0_ret_val = 1;

extern "C" {
void *func_00367230(int type) {
    g_last_created_type = type;
    if (g_factory_should_return_null) {
        return 0;
    }
    return &g_mock_entity;
}

int func_3671F0(void *entity) {
    assert(entity == &g_mock_entity);
    g_func_3671F0_call_count++;
    return g_func_3671F0_ret_val;
}
}

static void test_unknown_type_ignores() {
    g_last_created_type = -1;
    g_mock_entity = MockEntity();
    int stream = 42;
    int p3 = 99;

    func_001EBCD0(0, 0x01, &stream, &p3);
    assert(g_last_created_type == -1);
    assert(!g_mock_entity.deserialize_called);

    func_001EBCD0(0, 0x00, &stream, &p3);
    assert(g_last_created_type == -1);
    assert(!g_mock_entity.deserialize_called);
}

static void test_standard_types_dispatch() {
    int valid_types[] = {0x19, 0x3C, 0x14, 0x1E, 0x28, 0x32, 0x46, 0x50};
    int stream_dummy = 123;
    int p3_dummy = 456;

    for (size_t i = 0; i < sizeof(valid_types) / sizeof(valid_types[0]); i++) {
        g_last_created_type = -1;
        g_mock_entity = MockEntity();
        int t = valid_types[i];

        func_001EBCD0(0, t, &stream_dummy, &p3_dummy);

        assert(g_last_created_type == t);
        assert(g_mock_entity.deserialize_called);
        assert(g_mock_entity.received_stream == &stream_dummy);
        assert(g_mock_entity.received_p3 == &p3_dummy);
        assert(g_mock_entity.received_flag == 1);
    }
}

static void test_null_entity_safe() {
    g_last_created_type = -1;
    g_mock_entity = MockEntity();
    g_factory_should_return_null = true;
    int stream_dummy = 123;
    int p3_dummy = 456;

    func_001EBCD0(0, 0x19, &stream_dummy, &p3_dummy);
    assert(g_last_created_type == 0x19);
    assert(!g_mock_entity.deserialize_called);

    func_001EBCD0(0, 0x0A, &stream_dummy, &p3_dummy);
    assert(g_last_created_type == 0x0A);
    assert(!g_mock_entity.deserialize_called);

    g_factory_should_return_null = false;
}

static void test_type_0a_calls_func_3671F0() {
    g_last_created_type = -1;
    g_mock_entity = MockEntity();
    g_func_3671F0_call_count = 0;
    g_func_3671F0_ret_val = 1;
    int stream_dummy = 123;
    int p3_dummy = 456;

    func_001EBCD0(0, 0x0A, &stream_dummy, &p3_dummy);

    assert(g_last_created_type == 0x0A);
    assert(g_func_3671F0_call_count == 1);
    assert(g_mock_entity.deserialize_called);
    assert(g_mock_entity.received_stream == &stream_dummy);
    assert(g_mock_entity.received_p3 == &p3_dummy);
    assert(g_mock_entity.received_flag == 1);

    // Test with func_3671F0 returning 0
    g_mock_entity = MockEntity();
    g_func_3671F0_call_count = 0;
    g_func_3671F0_ret_val = 0;

    func_001EBCD0(0, 0x0A, &stream_dummy, &p3_dummy);

    assert(g_last_created_type == 0x0A);
    assert(g_func_3671F0_call_count == 1);
    assert(g_mock_entity.deserialize_called);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_unknown_type_ignores();
        test_standard_types_dispatch();
        test_null_entity_safe();
        test_type_0a_calls_func_3671F0();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_unknown_type_ignores();
        break;
    case 1:
        test_standard_types_dispatch();
        break;
    case 2:
        test_null_entity_safe();
        break;
    case 3:
        test_type_0a_calls_func_3671F0();
        break;
    default:
        return 1;
    }
    return 0;
}
