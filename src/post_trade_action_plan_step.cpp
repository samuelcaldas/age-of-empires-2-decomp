#pragma exceptions off
#include "post_trade_action_plan_step.h"

extern "C" {
void *func_332e60(void *root, int item_id);
int func_002261C0(void *item);
int func_001471A0(int entity_id);
int func_00147170(int entity_id);
int func_00147190(int entity_id);
int func_002C1920(void *self, void *record, void *stack_arr, int mode);
int func_002BAA20(void *self, int item_id, int field_4, int mode, void *stack_arr);
}

struct Manager {
    char pad[172];
    void *m_group;
};

struct Group {
    char pad[2968];
    void *m_root;
};

struct PlanItem {
    int m_item_id;
    int m_field_4;
    int m_field_8;
    int m_field_c;
    int m_field_10;
    int m_field_14;
};

struct Entity {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86();
    virtual int *get_id();
};

struct TradeActionState {
    char pad_0[176];
    Manager *m_mgr;
    char pad_180[3092 - 180];
    int m_limit;
};

extern "C" {
int func_002B9B30(TradeActionState *self, int item_id, int mode) {
    int stack_arr[4];
    stack_arr[0] = 0;
    stack_arr[1] = 0;
    stack_arr[2] = 0;
    stack_arr[3] = 0;

    const int limit = self->m_limit;
    int idx = 0;
    while (idx < limit) {
        int val = *(int*)((char*)self + idx * 24 + 356);
        if (val == item_id) {
            break;
        }
        idx++;
    }

    if (idx >= limit) {
        return 0;
    }

    Group *group = (Group*)self->m_mgr->m_group;
    Entity *item = (Entity*)func_332e60(group->m_root, item_id);
    *(int*)((char*)self + idx * 24 + 376) = func_002261C0(item);

    PlanItem *rec = (PlanItem*)((char*)self + idx * 24 + 356);

    if (!item || !item->get_id()) {
        return 0;
    }

    if (func_001471A0(*item->get_id()) == 600) {
        return 1;
    }
    if (func_001471A0(*item->get_id()) == 602) {
        return 1;
    }
    if (func_001471A0(*item->get_id()) == 618) {
        return 1;
    }

    if (*(float*)((char*)item + 64) > 0.0f) {
        return 1;
    }

    if (func_00147170(*item->get_id()) == 710) {
        if (func_00147190(*item->get_id()) == 100) {
            return 1;
        }
    }

    if (func_00147170(*item->get_id()) == 702) {
        return 1;
    }

    if (rec->m_field_4 != -1) {
        int field_4 = rec->m_field_4;
        int *rates1 = (int*)((char*)self + 3216);
        int *rates2 = (int*)((char*)self + 3232);
        if (rates1[field_4] > rates2[field_4]) {
            if (func_001471A0(*item->get_id()) == -1) {
                if ((func_002C1920(self, rec, stack_arr, mode) & 0xFF) != 0) {
                    return 1;
                }
            }
        }
    }

    if (rec->m_field_8 > rec->m_field_c) {
        if (func_001471A0(*item->get_id()) != -1) {
            return 1;
        }
        if (func_002BAA20(self, rec->m_item_id, rec->m_field_4, mode, stack_arr) == 1) {
            return -1;
        }
        rec->m_field_4 = -1;
        rec->m_field_8 = -1;
        rec->m_field_c = -1;
        return 1;
    }

    // 4-category score computation and descending bubble sort
    int indices[4];
    int scores[4];
    int *rates1 = (int*)((char*)self + 3216);
    int *rates2 = (int*)((char*)self + 3232);

    for (int i = 0; i < 4; ++i) {
        indices[i] = i;
        int den = rates2[i];
        if (den == 0) {
            scores[i] = -100;
        } else {
            int num = rates1[i];
            scores[i] = ((den - num) * 100) / den;
        }
    }

    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            if (scores[k] < scores[k + 1]) {
                int tmp_score = scores[k];
                scores[k] = scores[k + 1];
                scores[k + 1] = tmp_score;

                int tmp_idx = indices[k];
                indices[k] = indices[k + 1];
                indices[k + 1] = tmp_idx;
            }
        }
    }

    for (int s = 0; s < 4; ++s) {
        int cat = indices[s];
        if (stack_arr[cat] == 1) {
            continue;
        }
        if (rates1[cat] >= rates2[cat]) {
            continue;
        }
        if (rec->m_field_4 == cat) {
            int act = func_001471A0(*item->get_id());
            if (act == 613 || act != 609) {
                return 1;
            }
        }
        stack_arr[cat] = 1;
        if (func_002BAA20(self, rec->m_item_id, cat, mode, stack_arr) == 1) {
            return -1;
        }
    }

    if (rec->m_field_4 == -1) {
        func_002BAA20(self, rec->m_item_id, -1, 1, stack_arr);
        return 1;
    }

    if (func_001471A0(*item->get_id()) == 613 || func_001471A0(*item->get_id()) != 609) {
        return 1;
    }

    return 1;
}
}
