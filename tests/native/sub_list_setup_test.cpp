#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

float D_4E2F24 = 10.0f;

static int func_226d90_called = 0;
static int func_2668d0_called = 0;
static void *func_2668d0_player = 0;
static short func_2668d0_id = 0;
static int base_list_load_called = 0;
static void *base_list_load_stream = 0;

static int sub_list_v3_called = 0;
static void *sub_list_v3_player = 0;
static void *sub_list_v3_ret = (void*)0x99887766;

static int stream_read_step = 0;
static short stream_id_value = -1;

extern "C" {
    int func_0013B8A0(SubList *self, void *stream, void *player);
    int func_0013BA60(SubList *self, void *player);

    void func_226d90(void *stream, void *dst, int size) {
        (void)stream;
        func_226d90_called++;
        if (!dst || size <= 0) return;

        if (size == 1) {
            *(char*)dst = (char)0x42;
        } else if (size == 2) {
            *(short*)dst = stream_id_value;
        } else if (size == 4) {
            *(int*)dst = 100;
        }
    }

    void* func_2668d0(void *player, short id) {
        func_2668d0_called++;
        func_2668d0_player = player;
        func_2668d0_id = id;
        return (void*)0x55443322;
    }

    void func_00138BA0(void *base_list, void *stream) {
        (void)base_list;
        base_list_load_called++;
        base_list_load_stream = stream;
    }
}

void BaseList::Load(void *stream) {
    base_list_load_called++;
    base_list_load_stream = stream;
}

#define DEF_V10(base) \
    void* SubList::v##base##0() { return 0; } void* SubList::v##base##1() { return 0; } \
    void* SubList::v##base##2() { return 0; } void* SubList::v##base##3() { return 0; } \
    void* SubList::v##base##4() { return 0; } void* SubList::v##base##5() { return 0; } \
    void* SubList::v##base##6() { return 0; } void* SubList::v##base##7() { return 0; } \
    void* SubList::v##base##8() { return 0; } void* SubList::v##base##9() { return 0; }

void* SubList::v0() { return 0; }
void* SubList::v1() { return 0; }
void* SubList::v2() { return 0; }
void* SubList::v3(void *player) {
    sub_list_v3_called++;
    sub_list_v3_player = player;
    return sub_list_v3_ret;
}
void* SubList::v4() { return 0; }
void* SubList::v5() { return 0; }
void* SubList::v6() { return 0; }
void* SubList::v7() { return 0; }
void* SubList::v8() { return 0; }
void* SubList::v9() { return 0; }
void* SubList::v10() { return 0; }
void* SubList::v11() { return 0; }
void* SubList::v12() { return 0; }
void* SubList::v13() { return 0; }
void* SubList::v14() { return 0; }
void* SubList::v15() { return 0; }
void* SubList::v16() { return 0; }
void* SubList::v17(void*, void*, void*) { return 0; }
void* SubList::v18() { return 0; }
void* SubList::v19() { return 0; }
void* SubList::v20() { return 0; }
void* SubList::v21(int) { return 0; }
void* SubList::v22(void*) { return 0; }
void* SubList::v23() { return 0; }
void* SubList::v24(void*) { return 0; }
void* SubList::v25() { return 0; }
void* SubList::v26(void*) { return 0; }
void* SubList::v27() { return 0; }
void* SubList::v28() { return 0; }
void* SubList::v29() { return 0; }

DEF_V10(3)
void* SubList::v40() { return 0; }
void* SubList::v41() { return 0; }
void* SubList::v42(void*, float, float, float) { return 0; }
void* SubList::v43() { return 0; }
void* SubList::v44() { return 0; }
void* SubList::v45() { return 0; }
void* SubList::v46() { return 0; }
void* SubList::v47() { return 0; }
void* SubList::v48() { return 0; }
void* SubList::v49() { return 0; }
DEF_V10(5)
DEF_V10(6)
void* SubList::v70() { return 0; }
float SubList::GetRange() { return 0.0f; }
void* SubList::v72() { return 0; }
void* SubList::v73() { return 0; }
void* SubList::v74() { return 0; }
void* SubList::v75() { return 0; }
void* SubList::v76() { return 0; }
void* SubList::v77() { return 0; }
void* SubList::v78() { return 0; }
void* SubList::v79() { return 0; }
DEF_V10(8)
DEF_V10(9)
DEF_V10(10)
DEF_V10(11)
DEF_V10(12)
void* SubList::v130() { return 0; }
void* SubList::v131() { return 0; }
void* SubList::v132() { return 0; }
void* SubList::v133() { return 0; }
void* SubList::v134() { return 0; }
void* SubList::v135() { return 0; }
Vec3 SubList::v136() { Vec3 v; v.x = 0; v.y = 0; v.z = 0; return v; }
void* SubList::v137() { return 0; }
void* SubList::v138() { return 0; }
void* SubList::v139() { return 0; }
DEF_V10(14)
DEF_V10(15)
DEF_V10(16)
DEF_V10(17)
DEF_V10(18)

void* SubList::v190(void*, int, int) { return 0; }
void* SubList::v193(short) { return 0; }
void* SubList::v194(void*) { return 0; }
void* SubList::v195() { return 0; }
void* SubList::v196(void*) { return 0; }
void* SubList::v197() { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199(short, void*, float, float, float) { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void test_sub_list_setup_ba60() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0xFF, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    sub_list_v3_called = 0;
    void *player = (void*)0x12345678;

    int res = func_0013BA60(self, player);
    assert(res == 1);
    assert(self->m_field4_short == 0);
    assert(self->m_field8 == (WorldContainer*)player);
    assert(self->m_fieldC == 0);
    assert(self->m_field10 == 0);
    assert(self->m_field14 == 0);
    assert(self->m_field20 == 0);
    assert(self->m_field24 == 0);
    assert(self->m_field28 == 0);
    assert(self->m_field2C == 0);
    assert(self->m_field30 == 0);
    assert(self->m_field34 == (ListItem*)sub_list_v3_ret);
    assert(self->m_field38 == 0);
    assert(self->m_field3C == 0);
    assert(self->m_field3D == 0);
    assert(sub_list_v3_called == 1);
    assert(sub_list_v3_player == player);
    printf("SUB_LIST_SETUP_TEST_0_BA60_PASSED\n");
}

static void test_sub_list_setup_b8a0_id_minus1() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0xFF, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    sub_list_v3_called = 0;
    func_226d90_called = 0;
    base_list_load_called = 0;
    func_2668d0_called = 0;
    stream_id_value = -1;
    D_4E2F24 = 10.0f;

    void *stream = (void*)0x11112222;
    void *player = (void*)0x33334444;

    int res = func_0013B8A0(self, stream, player);
    assert(res == 1);
    assert(self->m_field4_short == 0);
    assert(self->m_field8 == (WorldContainer*)player);
    assert(self->m_field30 == 0);
    assert(base_list_load_called == 1);
    assert(base_list_load_stream == stream);
    assert(func_2668d0_called == 1);
    assert(func_2668d0_player == player);
    assert(self->m_field38 == (void*)0x55443322);
    printf("SUB_LIST_SETUP_TEST_1_B8A0_ID_MINUS1_PASSED\n");
}

static void test_sub_list_setup_b8a0_id_master() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0xFF, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    // Set up mock masters structure
    void *masters[4] = {0, (void*)0xAA, (void*)0xBB, (void*)0xCC};
    char obj_c8[0xD0];
    *(void***)(obj_c8 + 4) = masters;
    char obj_4[0xD0];
    *(char**)(obj_4 + 0xC8) = obj_c8;
    char player_buf[16];
    *(char**)(player_buf + 4) = obj_4;

    stream_id_value = 2;
    D_4E2F24 = 10.0f;
    void *stream = (void*)0x11112222;

    int res = func_0013B8A0(self, stream, player_buf);
    assert(res == 1);
    assert(self->m_field30 == (void*)0xBB);
    printf("SUB_LIST_SETUP_TEST_2_B8A0_ID_MASTER_PASSED\n");
}

static void test_sub_list_setup_b8a0_version_check() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0xFF, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    stream_id_value = -1;
    void *stream = (void*)0x11112222;
    void *player = (void*)0x33334444;

    D_4E2F24 = 9.95f; // >= 9.92f
    func_226d90_called = 0;
    func_0013B8A0(self, stream, player);
    int calls_v995 = func_226d90_called;

    D_4E2F24 = 9.0f; // < 9.92f
    func_226d90_called = 0;
    func_0013B8A0(self, stream, player);
    int calls_v90 = func_226d90_called;

    // When version >= 9.92, an extra 1-byte read is performed for m_field3D
    assert(calls_v995 == calls_v90 + 1);
    printf("SUB_LIST_SETUP_TEST_3_B8A0_VERSION_CHECK_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-3)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_setup_ba60();
    else if (mode == 1) test_sub_list_setup_b8a0_id_minus1();
    else if (mode == 2) test_sub_list_setup_b8a0_id_master();
    else if (mode == 3) test_sub_list_setup_b8a0_version_check();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
