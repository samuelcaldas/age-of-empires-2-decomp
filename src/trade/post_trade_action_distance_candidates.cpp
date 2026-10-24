#pragma exceptions off

extern "C" {
void *func_332e60(void *root, int item_id);
int func_00147170(int entity_id);
float func_00269190(float x, float y, float z, void *item);
}

struct Manager {
    char pad[172];
    void *m_group;
};

struct Group {
    char pad[2968];
    void *m_root;
};

struct TradeActionState {
    char pad_0[176];
    Manager *m_mgr;               // 176
    int *m_pool;                  // 180
    int m_pool_count;             // 184
    char pad_188[192 - 188];
    int m_pool_capacity;          // 192
    char pad_196[3184 - 196];
    int *m_excl_pool;             // 3184
    int m_excl_count;             // 3188
    char pad_3192[3196 - 3192];
    int m_excl_capacity;          // 3196
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

static inline int in_exclusion_pool(TradeActionState *self, const int &item_id) {
    int count = self->m_excl_count;
    for (int i = 0; i < count && i < self->m_excl_capacity; ++i) {
        if (item_id == self->m_excl_pool[i]) {
            return 1;
        }
    }
    return 0;
}

static inline int &get_pool_item(TradeActionState *self, int index) {
    if (index > self->m_pool_capacity - 1) {
        return self->m_pool[0];
    }
    return self->m_pool[index];
}

extern "C" int func_002B8E30(TradeActionState *self, int *coords) {
    int best_item = -1;
    float best_dist = 0.0f;

    for (int idx = 0; idx < self->m_pool_count; ++idx) {
        if (in_exclusion_pool(self, get_pool_item(self, idx))) {
            continue;
        }

        int item_id = get_pool_item(self, idx);
        Group *group = (Group*)self->m_mgr->m_group;
        Entity *item = (Entity*)func_332e60(group->m_root, item_id);
        if (!item || !item->get_id()) {
            continue;
        }

        short field8 = *(short*)(*(char**)((char*)item + 4) + 8);
        if (field8 == 259 || field8 == 214) {
            continue;
        }

        if (*(float*)((char*)item + 64) > 7.0f) {
            continue;
        }

        if (func_00147170(*item->get_id()) == 702) {
            continue;
        }
        if (func_00147170(*item->get_id()) == 718) {
            continue;
        }
        if (func_00147170(*item->get_id()) == 700) {
            continue;
        }
        if (func_00147170(*item->get_id()) == 717) {
            continue;
        }

        float dist = func_00269190((float)coords[0], (float)coords[1], *(float*)((char*)item + 76), item);
        if (best_item == -1) {
            best_item = *(short*)((char*)item + 36);
            best_dist = dist;
        } else {
            if (best_dist <= dist) {
                continue;
            }
            best_item = *(short*)((char*)item + 36);
            best_dist = dist;
        }
    }

    return best_item;
}
