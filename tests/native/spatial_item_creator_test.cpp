#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "base_list.h"

struct SpatialObj1 {
    char pad_00[6];
    short type;
    char pad_08[0x1c];
    float f24;
    char pad_28[0x0c];
    int f34;
    int f38;
};

struct SubWorld {
    char pad_00[0x104];
    short f104;
    short pad_106;
    short f108;
    short pad_10a;
    char pad_10c[0x0c];
    float f118;
};

class SpatialWorldObj {
public:
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3();
    virtual void* v4(); virtual void* v5(); virtual void* v6(); virtual void* v7();
    virtual void* v8(); virtual void* v9(); virtual void* v10(); virtual void* v11();
    virtual void* v12(); virtual void* v13(); virtual void* v14(); virtual void* v15();
    virtual void* v16(); virtual void* v17(); virtual void* v18(); virtual void* v19();
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23();
    virtual void* v24(); virtual void* v25(); virtual void* v26(); virtual void* v27();
    virtual void* v28(); virtual void* v29(); virtual void* v30(); virtual void* v31();
    virtual void* v32(); virtual void* v33(); virtual void* v34(); virtual void* v35();
    virtual void* v36(); virtual void* v37(); virtual void* v38(); virtual void* v39();
    virtual void* v40(); virtual void* v41(); virtual void* v42(); virtual void* v43();
    virtual void* v44(); virtual void* v45(); virtual void* v46(); virtual void* v47();
    virtual void* v48(); virtual void* v49(); virtual void* v50(); virtual void* v51();
    virtual void* v52(); virtual void* v53(); virtual void* v54(); virtual void* v55();
    virtual void* v56(); virtual void* v57(); virtual void* v58(); virtual void* v59();
    virtual void* v60(); virtual void* v61(); virtual void* v62(); virtual void* v63();
    virtual void* v64(); virtual void* v65(); virtual void* v66(); virtual void* v67();
    virtual void* v68(); virtual void* v69(); virtual void* v70(); virtual void* v71();
    virtual void* v72(); virtual void* v73(); virtual void* v74(); virtual void* v75();
    virtual void* v76(); virtual void* v77(); virtual void* v78(); virtual void* v79();
    virtual void* v80(); virtual void* v81(); virtual void* v82(); virtual void* v83();
    virtual void* v84(); virtual void* v85(); virtual void* v86(); virtual void* v87();

    SubWorld *field_4;
};

ListNode s_node_pool[1000];
void *__vt__8BaseList = 0;
extern const char D_490B10[] = "ERR";

static void *last_item_ptr = (void*)0x9999;
static int factory_called = 0;
static int init_spatial_called = 0;
static char dummy_sub_obj[64] = {0};
static void *dummy_ptr = dummy_sub_obj;

class MockSpatialWorldObj : public SpatialWorldObj {
public:
    virtual void* v87() { return &dummy_ptr; }
};

extern "C" {
    int D_4E35DC = 0;

    void __vec_ctor(void *ptr) { (void)ptr; }
    void func_139580(BaseList *list) { (void)list; }
    void func_226d90(void *s, void *d, int sz) { (void)s; (void)d; (void)sz; }
    void func_226f70(void *s, void *d, int sz) { (void)s; (void)d; (void)sz; }

    void func_118DE0(const char *msg) { (void)msg; }
    void func_1471B0(void *a, int b) { (void)a; (void)b; }
    void func_14BD20(void *a, int b, float c, float d, float e) { (void)a; (void)b; (void)c; (void)d; (void)e; }

    void* func_366BC0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366BE0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366BF0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C00(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C10(void *arg) { (void)arg; factory_called++; return last_item_ptr; }

    void func_347DE0(void *item, void *w, void *a2, int f34, int f38, int unk, float f24, float f118, short f104, short f108) {
        (void)item; (void)w; (void)a2; (void)f34; (void)f38; (void)unk; (void)f24; (void)f118; (void)f104; (void)f108;
        init_spatial_called++;
    }
    void func_348000(void *item, void *w, int f34, int f38, int unk, float x, float y, float z, float f24, float f118, short f104, short f108) {
        (void)item; (void)w; (void)f34; (void)f38; (void)unk; (void)x; (void)y; (void)z; (void)f24; (void)f118; (void)f104; (void)f108;
        init_spatial_called++;
    }
    void func_34B760(void *item, void *w, void *a1, float x, float y, float z) { (void)item; (void)w; (void)a1; (void)x; (void)y; (void)z; init_spatial_called++; }
    void func_34BCE0(void *item, void *w, void *a1, void *a2) { (void)item; (void)w; (void)a1; (void)a2; init_spatial_called++; }
    void func_34BE60(void *item, void *w, void *a1, float x, float y, float z) { (void)item; (void)w; (void)a1; (void)x; (void)y; (void)z; init_spatial_called++; }
    void func_34E370(void *item, void *w, void *a1) { (void)item; (void)w; (void)a1; init_spatial_called++; }
    void func_34E1E0(void *item, void *w, void *a2) { (void)item; (void)w; (void)a2; init_spatial_called++; }
}

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() { return 0; }
void ListItem::Save(void *stream) { (void)stream; }
int ListItem::v8() { return 0; }
void ListItem::Method9(void *a, void *b, void *c) { (void)a; (void)b; (void)c; }
bool ListItem::Method10() { return false; }
void ListItem::Method11() {}
bool ListItem::Method12() { return false; }
int ListItem::Method13() { return 0; }
int ListItem::Method14() { return 0; }
int ListItem::Method15(void *other, float x, float y, float z) { (void)other; (void)x; (void)y; (void)z; return 0; }
void ListItem::v16() {}
void ListItem::v17() {}
void ListItem::Method18(int msg) { (void)msg; }
void ListItem::Method19(int a, int b, int c) { (void)a; (void)b; (void)c; }
void ListItem::v20() {}
void* ListItem::v21() { return 0; }
void ListItem::v22() {}
void ListItem::v23() {}
void ListItem::v24() {}
void ListItem::v25() {}
void ListItem::Method26() {}

void* SpatialWorldObj::v0() { return 0; } void* SpatialWorldObj::v1() { return 0; } void* SpatialWorldObj::v2() { return 0; } void* SpatialWorldObj::v3() { return 0; }
void* SpatialWorldObj::v4() { return 0; } void* SpatialWorldObj::v5() { return 0; } void* SpatialWorldObj::v6() { return 0; } void* SpatialWorldObj::v7() { return 0; }
void* SpatialWorldObj::v8() { return 0; } void* SpatialWorldObj::v9() { return 0; } void* SpatialWorldObj::v10() { return 0; } void* SpatialWorldObj::v11() { return 0; }
void* SpatialWorldObj::v12() { return 0; } void* SpatialWorldObj::v13() { return 0; } void* SpatialWorldObj::v14() { return 0; } void* SpatialWorldObj::v15() { return 0; }
void* SpatialWorldObj::v16() { return 0; } void* SpatialWorldObj::v17() { return 0; } void* SpatialWorldObj::v18() { return 0; } void* SpatialWorldObj::v19() { return 0; }
void* SpatialWorldObj::v20() { return 0; } void* SpatialWorldObj::v21() { return 0; } void* SpatialWorldObj::v22() { return 0; } void* SpatialWorldObj::v23() { return 0; }
void* SpatialWorldObj::v24() { return 0; } void* SpatialWorldObj::v25() { return 0; } void* SpatialWorldObj::v26() { return 0; } void* SpatialWorldObj::v27() { return 0; }
void* SpatialWorldObj::v28() { return 0; } void* SpatialWorldObj::v29() { return 0; } void* SpatialWorldObj::v30() { return 0; } void* SpatialWorldObj::v31() { return 0; }
void* SpatialWorldObj::v32() { return 0; } void* SpatialWorldObj::v33() { return 0; } void* SpatialWorldObj::v34() { return 0; } void* SpatialWorldObj::v35() { return 0; }
void* SpatialWorldObj::v36() { return 0; } void* SpatialWorldObj::v37() { return 0; } void* SpatialWorldObj::v38() { return 0; } void* SpatialWorldObj::v39() { return 0; }
void* SpatialWorldObj::v40() { return 0; } void* SpatialWorldObj::v41() { return 0; } void* SpatialWorldObj::v42() { return 0; } void* SpatialWorldObj::v43() { return 0; }
void* SpatialWorldObj::v44() { return 0; } void* SpatialWorldObj::v45() { return 0; } void* SpatialWorldObj::v46() { return 0; } void* SpatialWorldObj::v47() { return 0; }
void* SpatialWorldObj::v48() { return 0; } void* SpatialWorldObj::v49() { return 0; } void* SpatialWorldObj::v50() { return 0; } void* SpatialWorldObj::v51() { return 0; }
void* SpatialWorldObj::v52() { return 0; } void* SpatialWorldObj::v53() { return 0; } void* SpatialWorldObj::v54() { return 0; } void* SpatialWorldObj::v55() { return 0; }
void* SpatialWorldObj::v56() { return 0; } void* SpatialWorldObj::v57() { return 0; } void* SpatialWorldObj::v58() { return 0; } void* SpatialWorldObj::v59() { return 0; }
void* SpatialWorldObj::v60() { return 0; } void* SpatialWorldObj::v61() { return 0; } void* SpatialWorldObj::v62() { return 0; } void* SpatialWorldObj::v63() { return 0; }
void* SpatialWorldObj::v64() { return 0; } void* SpatialWorldObj::v65() { return 0; } void* SpatialWorldObj::v66() { return 0; } void* SpatialWorldObj::v67() { return 0; }
void* SpatialWorldObj::v68() { return 0; } void* SpatialWorldObj::v69() { return 0; } void* SpatialWorldObj::v70() { return 0; } void* SpatialWorldObj::v71() { return 0; }
void* SpatialWorldObj::v72() { return 0; } void* SpatialWorldObj::v73() { return 0; } void* SpatialWorldObj::v74() { return 0; } void* SpatialWorldObj::v75() { return 0; }
void* SpatialWorldObj::v76() { return 0; } void* SpatialWorldObj::v77() { return 0; } void* SpatialWorldObj::v78() { return 0; } void* SpatialWorldObj::v79() { return 0; }
void* SpatialWorldObj::v80() { return 0; } void* SpatialWorldObj::v81() { return 0; } void* SpatialWorldObj::v82() { return 0; } void* SpatialWorldObj::v83() { return 0; }
void* SpatialWorldObj::v84() { return 0; } void* SpatialWorldObj::v85() { return 0; } void* SpatialWorldObj::v86() { return 0; } void* SpatialWorldObj::v87() { return 0; }

static void test_create_spatial_item_type_7() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    MockSpatialWorldObj swo;
    SubWorld sw;
    memset(&sw, 0, sizeof(sw));
    sw.f118 = 1.0f;
    sw.f104 = 10;
    sw.f108 = 20;
    swo.field_4 = &sw;
    list->m_field4 = &swo;

    SpatialObj1 obj1;
    memset(&obj1, 0, sizeof(obj1));
    obj1.type = 7;
    obj1.f24 = 2.0f;
    obj1.f34 = 1;
    obj1.f38 = 2;

    factory_called = 0;
    init_spatial_called = 0;

    void *item = list->CreateItem(&obj1, 1.0f, 0, 2.0f, 3.0f);
    assert(item == last_item_ptr);
    assert(factory_called == 1);
    assert(init_spatial_called == 1);
    printf("SPATIAL_ITEM_CREATOR_TEST_0_TYPE7_PASSED\n");
}

static void test_create_spatial_item_type_4() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    MockSpatialWorldObj swo;
    list->m_field4 = &swo;

    SpatialObj1 obj1;
    memset(&obj1, 0, sizeof(obj1));
    obj1.type = 4;

    factory_called = 0;
    init_spatial_called = 0;

    void *item = list->CreateItem(&obj1, 1.0f, 0, 2.0f, 3.0f);
    assert(item == last_item_ptr);
    assert(factory_called == 1);
    assert(init_spatial_called == 1);
    printf("SPATIAL_ITEM_CREATOR_TEST_1_TYPE4_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-1)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_create_spatial_item_type_7();
    else if (mode == 1) test_create_spatial_item_type_4();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
