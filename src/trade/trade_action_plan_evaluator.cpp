#pragma exceptions off

extern "C" {
void *func_00144d10(void *mgr, int idx);
int func_001471a0(int entity_id);
int func_001471c0(int entity_id);
int func_001880d0(void *gp_obj);
int func_00123350(float val);
extern void *D_004E3180;
}

struct Entity {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void *v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual int *get_id();
};

struct TradeActionState {
    char pad_0[176];
    void *m_mgr;                  // 176
    char pad_180[2604 - 180];
    int m_val_2604;               // 2604
    int m_val_2608;               // 2608
    int m_val_2612;               // 2612
    int m_val_2616;               // 2616
    char pad_2620[2760 - 2620];
    int m_val_2760;               // 2760
    int m_val_2764;               // 2764
    int m_val_2768;               // 2768
    int m_val_2772;               // 2772
    char pad_2776[3092 - 2776];
    int m_limit;                  // 3092
    int m_total;                  // 3096
    char pad_3100[3184 - 3100];
    int *m_pool;                  // 3184
    int m_count;                  // 3188
    int m_pad_3192;               // 3192
    int m_capacity;               // 3196
    int m_indices[4];             // 3200
    int m_slots[4];               // 3216
    int m_rates[4];               // 3232
    char pad_3248[3316 - 3248];
    int m_field_3316;             // 3316
};

struct PlanItem {
    char pad_0[356];
    int m_id;                     // 356
    int m_slot;                   // 360
    char pad_364[8];
    int m_field_372;              // 372
};

static inline int in_pool(TradeActionState *self, const int &item_id) {
    int count = self->m_count;
    for (int i = 0; i < count && i < self->m_capacity; ++i) {
        if (item_id == self->m_pool[i]) {
            return 1;
        }
    }
    return 0;
}

extern "C" void func_002B9140(TradeActionState *self) {
    int matched_count = 0;
    for (int i = 0; i < 4; ++i) {
        self->m_slots[i] = 0;
    }
    Entity *item;
    int type;
    int slot;
    PlanItem *pi;
    int idx;
    for (idx = 0; idx < self->m_limit; ++idx) {
        pi = (PlanItem*)((char*)self + idx * 24);
        item = (Entity*)func_00144d10(self->m_mgr, pi->m_id);
        if (!item || !item->get_id()) {
            continue;
        }
        type = func_001471a0(*item->get_id());
        slot = pi->m_slot;
        int *slot_ptr = &pi->m_slot;
        pi->m_field_372 = func_001471c0(*item->get_id());

        if (func_001880d0(D_004E3180) == 1) {
            if (type == 609) {
                short field8 = *(short*)(*(char**)((char*)item + 4) + 8);
                if ((field8 == 259 || field8 == 214) && slot) {
                    if (!in_pool(self, *(short*)((char*)item + 36))) {
                        *slot_ptr = 0;
                    }
                }
            }
            short field8 = *(short*)(*(char**)((char*)item + 4) + 8);
            if (field8 == 118 || field8 == 212) {
                void *sub_res = item->v55();
                if (sub_res && *(short*)(*(char**)((char*)sub_res + 4) + 8) == 50 && slot) {
                    *slot_ptr = 0;
                }
            }
        }

        if (slot >= 0 && slot < 4) {
            matched_count++;
            if (type == 609) {
                self->m_slots[slot]++;
            } else if (type == 613) {
                self->m_slots[slot]++;
            } else if (in_pool(self, pi->m_id)) {
                self->m_slots[slot]++;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        self->m_rates[i] = 0;
    }
    self->m_field_3316 = 0;

    float f20 = (float)matched_count;
    self->m_rates[2] = func_00123350(0.5f + (f20 * (float)(self->m_val_2612 + self->m_val_2768)) / 100.0f);
    self->m_rates[3] = func_00123350(0.5f + (f20 * (float)(self->m_val_2608 + self->m_val_2772)) / 100.0f);
    self->m_rates[1] = func_00123350(0.5f + (f20 * (float)(self->m_val_2616 + self->m_val_2764)) / 100.0f);
    self->m_rates[0] = func_00123350(0.5f + (f20 * (float)(self->m_val_2604 + self->m_val_2760)) / 100.0f);

    int sum1 = 0;
    for (int i = 0; i < 4; ++i) {
        sum1 += self->m_rates[i];
    }
    int sum2 = 0;
    for (int i = 0; i < 4; ++i) {
        sum2 += self->m_rates[i];
    }

    int diff = self->m_total - sum2;
    if (diff > 0) {
        float f_diff = (float)diff;
        self->m_rates[2] += func_00123350(0.5f + (f_diff * (float)(self->m_val_2612 + self->m_val_2768)) / 100.0f);
        self->m_rates[3] += func_00123350(0.5f + (f_diff * (float)(self->m_val_2608 + self->m_val_2772)) / 100.0f);
        self->m_rates[1] += func_00123350(0.5f + (f_diff * (float)(self->m_val_2616 + self->m_val_2764)) / 100.0f);
        self->m_rates[0] += func_00123350(0.5f + (f_diff * (float)(self->m_val_2604 + self->m_val_2760)) / 100.0f);
    }

    for (int i = 0; i < 4; ++i) {
        self->m_indices[i] = i;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            int idx_i = self->m_indices[i];
            int idx_j = self->m_indices[j];
            if (self->m_rates[idx_i] < self->m_rates[idx_j]) {
                self->m_indices[i] = idx_j;
                self->m_indices[j] = idx_i;
            }
        }
    }

}
