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

struct SpatialObj2 {
    char pad_00[0x24];
    short f24;
    char pad_26[0x1e];
    float f44;
    float f48;
    float f4C;
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

class WorldObj {
public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34();
    virtual void* v35();
    virtual void* v36();
    virtual void* v37();
    virtual void* v38();
    virtual void* v39();
    virtual void* v40();
    virtual void* v41();
    virtual void* v42();
    virtual void* v43();
    virtual void* v44();
    virtual void* v45();
    virtual void* v46();
    virtual void* v47();
    virtual void* v48();
    virtual void* v49();
    virtual void* v50();
    virtual void* v51();
    virtual void* v52();
    virtual void* v53();
    virtual void* v54();
    virtual void* v55();
    virtual void* v56();
    virtual void* v57();
    virtual void* v58();
    virtual void* v59();
    virtual void* v60();
    virtual void* v61();
    virtual void* v62();
    virtual void* v63();
    virtual void* v64();
    virtual void* v65();
    virtual void* v66();
    virtual void* v67();
    virtual void* v68();
    virtual void* v69();
    virtual void* v70();
    virtual void* v71();
    virtual void* v72();
    virtual void* v73();
    virtual void* v74();
    virtual void* v75();
    virtual void* v76();
    virtual void* v77();
    virtual void* v78();
    virtual void* v79();
    virtual void* v80();
    virtual void* v81();
    virtual void* v82();
    virtual void* v83();
    virtual void* v84();
    virtual void* v85();
    virtual void* v86();
    virtual void* v87();

    SubWorld *field_4;
};

extern "C" {
void func_118DE0(const char*);
void func_1471B0(void*, int);
void func_14BD20(void*, int, float, float, float);
void* func_366BC0(void*);
void* func_366BE0(void*);
void* func_366BF0(void*);
void* func_366C00(void*);
void* func_366C10(void*);
void func_347DE0(void*, void*, void*, int, int, int, float, float, short, short);
void func_348000(void*, void*, int, int, int, float, float, float, float, float, short, short);
void func_34B760(void*, void*, void*, float, float, float);
void func_34BCE0(void*, void*, void*, void*);
void func_34BE60(void*, void*, void*, float, float, float);
void func_34E370(void*, void*, void*);
void func_34E1E0(void*, void*, void*);

extern int D_4E35DC;
extern const char D_490B10[];
}

void* BaseList::CreateItem(void *a1, float x, void *a2, float y, float z) {
    void *item;

    switch (((SpatialObj1*)a1)->type) {
    case 10:
        func_118DE0(D_490B10);
        while (1) {}
    case 7:
        if (((WorldObj*)this->m_field4)->v87()) {
            func_1471B0(*(void**)((WorldObj*)this->m_field4)->v87(), 0x258);
            if (a2) {
                func_14BD20(*(void**)((WorldObj*)this->m_field4)->v87(), ((SpatialObj2*)a2)->f24, ((SpatialObj2*)a2)->f44, ((SpatialObj2*)a2)->f48, ((SpatialObj2*)a2)->f4C);
            } else {
                func_14BD20(*(void**)((WorldObj*)this->m_field4)->v87(), -1, x, y, z);
            }
        }
        item = func_366BC0(&D_4E35DC);
        if (a2) {
            if (item) {
                SubWorld *sub = ((WorldObj*)this->m_field4)->field_4;
                func_347DE0(item, this->m_field4, a2, ((SpatialObj1*)a1)->f34, ((SpatialObj1*)a1)->f38, 0, ((SpatialObj1*)a1)->f24, sub->f118, sub->f104, sub->f108);
            }
        } else if (item) {
            SubWorld *sub = ((WorldObj*)this->m_field4)->field_4;
            func_348000(item, this->m_field4, ((SpatialObj1*)a1)->f34, ((SpatialObj1*)a1)->f38, 0, x, y, z, ((SpatialObj1*)a1)->f24, sub->f118, sub->f104, sub->f108);
        }
        return item;
    case 4:
        item = func_366BE0(&D_4E35DC);
        if (item) {
            func_34B760(item, this->m_field4, a1, x, y, z);
        }
        return item;
    case 5:
        item = func_366BF0(&D_4E35DC);
        if (a2) {
            if (item) {
                func_34BCE0(item, this->m_field4, a1, a2);
            }
        } else if (item) {
            func_34BE60(item, this->m_field4, a1, x, y, z);
        }
        return item;
    case 21:
        item = func_366C10(&D_4E35DC);
        if (item) {
            func_34E370(item, this->m_field4, a1);
        }
        return item;
    case 13:
        item = func_366C00(&D_4E35DC);
        if (item) {
            func_34E1E0(item, this->m_field4, a2);
        }
        return item;
    }
    return 0;
}

int BaseList::GetFieldC8() {
    return this->m_fieldC8;
}
