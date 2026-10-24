#pragma exceptions off
#include "unit_action_build_62f0.h"

extern "C" {
    extern void *D_4E35DC;
    void *func_332E60(void *owner_b98, void *arg1, int arg2);
    int HasItems__8BaseListFv(void *list);
    void *GetHeadItem__8BaseListFv(void *list);
    void Free__8BaseListFv(void *list);
    void *func_366C80(void *pool);
    void func_354AD0(void *item, void *self, void *sub_obj, void *res);
}

typedef void *(*VtableItemTypeFn)(void *item);
typedef short (*VtableItemIdFn)(void *item);
typedef void (*VtableUpdatePosFn)(void *item, void *res, float x, float y, float z);
typedef void *(*VtableCreateSubFn)(void *self, void *res, int flag, float x, float y, float z);
typedef void (*VtableSetSubFn)(void *self, void *item);

#if defined(__LP64__) || defined(_LP64)
#define SELF_OWNER_OFFSET 0x10
#define SELF_LIST_OFFSET  0x198
#define OWNER_B98_OFFSET  0x1730
#else
#define SELF_OWNER_OFFSET 0x8
#define SELF_LIST_OFFSET  0xCC
#define OWNER_B98_OFFSET  0xB98
#endif

static bool check_existing_item(void *list, void *res) {
    if (HasItems__8BaseListFv(list) == 0) {
        return false;
    }
    void *item = GetHeadItem__8BaseListFv(list);
    void **vtbl = *(void ***)item;
    VtableItemTypeFn type_fn = (VtableItemTypeFn)vtbl[21];
    if (type_fn(item) != res) {
        return false;
    }
    VtableItemIdFn id_fn = (VtableItemIdFn)vtbl[8];
    return id_fn(item) == 0x68;
}

static bool update_existing_item(void *list, void *res) {
    if (HasItems__8BaseListFv(list) == 0) {
        return false;
    }
    void *item = GetHeadItem__8BaseListFv(list);
    void **vtbl = *(void ***)item;
    VtableItemIdFn id_fn = (VtableItemIdFn)vtbl[8];
    if (id_fn(item) != 0x68) {
        return false;
    }
    float x = *(float *)((char *)res + 0x44);
    float y = *(float *)((char *)res + 0x48);
    float z = *(float *)((char *)res + 0x4C);
    VtableUpdatePosFn update_fn = (VtableUpdatePosFn)vtbl[15];
    update_fn(item, res, x, y, z);
    return true;
}

static int create_sub_item(void *self, void *list, void *res) {
    float x = *(float *)((char *)res + 0x44);
    float y = *(float *)((char *)res + 0x48);
    float z = *(float *)((char *)res + 0x4C);

    void **self_vtbl = *(void ***)self;
    VtableCreateSubFn create_fn = (VtableCreateSubFn)self_vtbl[198];
    void *sub_obj = create_fn(self, res, -1, x, y, z);
    if (sub_obj == 0) {
        return 0;
    }

    void *item = func_366C80(&D_4E35DC);
    if (item == 0) {
        return 0;
    }

    func_354AD0(item, self, sub_obj, res);
    Free__8BaseListFv(list);

    VtableSetSubFn set_fn = (VtableSetSubFn)self_vtbl[196];
    set_fn(self, item);
    return 1;
}

int func_2762F0(void *self, void *arg1, int arg2) {
    void *owner = *(void **)((char *)self + SELF_OWNER_OFFSET);
    void *owner_b98 = *(void **)((char *)owner + OWNER_B98_OFFSET);

    void *res = func_332E60(owner_b98, arg1, arg2);
    if (res == 0) {
        return 0;
    }

    void *list = *(void **)((char *)self + SELF_LIST_OFFSET);
    if (arg2 == 0) {
        if (check_existing_item(list, res)) {
            return 1;
        }
        return create_sub_item(self, list, res);
    }

    if (update_existing_item(list, res)) {
        return 1;
    }
    return create_sub_item(self, list, res);
}
