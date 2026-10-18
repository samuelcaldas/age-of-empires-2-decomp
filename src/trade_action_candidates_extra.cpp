#pragma exceptions off
#include "trade_action_candidates_extra.h"
#include "trade_action_candidates_exclusion.h"
#include "trade_action_candidates_selector.h"
#include "trade_action_candidates_distance.h"

using namespace trade_action_candidates;

extern "C" {
int func_001471a0(int entity_id);
int func_001471c0(int entity_id);
void *func_00144d10(void *mgr, int idx);
int func_001880d0(void *gp_obj);
int func_00123350(float val);
extern void *D_004E3180;
}

namespace trade_action_candidates {

static void sort_rates_indices(void *self) {
    for (int i = 0; i < 4; ++i) {
        store_integer(self, 3200 + i * 4, i);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx_i = integer_at(self, 3200 + i * 4);
            int idx_j = integer_at(self, 3200 + j * 4);
            int rate_i = integer_at(self, 3232 + idx_i * 4);
            int rate_j = integer_at(self, 3232 + idx_j * 4);
            if (rate_i < rate_j) {
                store_integer(self, 3200 + i * 4, idx_j);
                store_integer(self, 3200 + j * 4, idx_i);
            }
        }
    }
}

static void calculate_rate_slots(void *self, float count_float) {
    const int offsets_a[4] = {2612, 2608, 2616, 2604};
    const int offsets_b[4] = {2768, 2772, 2764, 2760};
    const int target_offsets[4] = {3240, 3244, 3236, 3232};

    for (int k = 0; k < 4; ++k) {
        float sum = static_cast<float>(integer_at(self, offsets_a[k]) + integer_at(self, offsets_b[k]));
        float div = (count_float * sum) / 100.0f;
        int rate = func_00123350(0.5f + div);
        store_integer(self, target_offsets[k], rate);
    }
}

static void adjust_rate_totals(void *self) {
    int sum = 0;
    for (int k = 0; k < 4; ++k) {
        sum += integer_at(self, 3232 + k * 4);
    }
    int diff = integer_at(self, 3096) - sum;
    if (diff > 0) {
        float diff_float = static_cast<float>(diff);
        const int offsets_a[4] = {2612, 2608, 2616, 2604};
        const int offsets_b[4] = {2768, 2772, 2764, 2760};
        const int target_offsets[4] = {3240, 3244, 3236, 3232};

        for (int k = 0; k < 4; ++k) {
            float sum_k = static_cast<float>(integer_at(self, offsets_a[k]) + integer_at(self, offsets_b[k]));
            float div = (diff_float * sum_k) / 100.0f;
            int add = func_00123350(0.5f + div);
            store_integer(self, target_offsets[k], integer_at(self, target_offsets[k]) + add);
        }
    }
}

static void evaluate_plan_item(void *self, void *sub_obj, int &matched_count) {
    void *item = func_00144d10(pointer_at(self, 176), integer_at(sub_obj, 356));
    if (!item) {
        return;
    }

    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred(item)) {
        return;
    }

    int type = func_001471a0(pred(item));
    int slot = integer_at(sub_obj, 360);
    store_integer(sub_obj, 372, func_001471c0(pred(item)));

    if (func_001880d0(D_004E3180) == 1) {
        if (type == 609) {
            short field8 = short_at(pointer_at(item, 4), 8);
            if ((field8 == 259 || field8 == 214) && slot && is_excluded(self, short_at(item, 36))) {
                store_integer(sub_obj, 360, 0);
            }
        }
        short field8 = short_at(pointer_at(item, 4), 8);
        if (field8 == 118 || field8 == 212) {
            typedef void *(*SubPred)(void *);
            SubPred sub_pred = reinterpret_cast<SubPred>(*reinterpret_cast<void **>(bytes(*reinterpret_cast<void ***>(item)) + 220));
            void *sub_res = sub_pred(item);
            if (sub_res && short_at(pointer_at(sub_res, 4), 8) == 50 && slot) {
                store_integer(sub_obj, 360, 0);
            }
        }
    }

    if (slot >= 0 && slot < 4) {
        if (type == 609) {
            matched_count++;
            store_integer(self, 3216 + slot * 4, integer_at(self, 3216 + slot * 4) + 1);
        } else if (type == 613) {
            store_integer(self, 3216 + slot * 4, integer_at(self, 3216 + slot * 4) + 1);
        } else if (is_excluded(self, integer_at(sub_obj, 356))) {
            store_integer(self, 3216 + slot * 4, integer_at(self, 3216 + slot * 4) + 1);
        }
    }
}

} // namespace trade_action_candidates

extern "C" {
int func_002B8560(void *self, int mode) {
    int total_items = integer_at(self, 184);
    for (int index = 0; index < total_items; ++index) {
        int item_id = get_pool_item_id(self, index);
        void *item = func_00332e60(manager_entity_root(self), item_id);
        if (!item) {
            continue;
        }

        typedef int (*Predicate)(void *);
        void **vtable = *reinterpret_cast<void ***>(item);
        Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
        if (!pred(item)) {
            continue;
        }

        if (!check_mode_predicate(self, item_id, mode)) {
            continue;
        }

        short sub_id = short_at(item, 36);
        if ((func_002bfcd0(self, sub_id) & 0xFF) == 1) {
            return sub_id;
        }
    }
    return -1;
}

int func_002B8980(void *self, int *coords, int mode, int flag) {
    return scan_distance_candidates(self, coords, mode, flag);
}

int func_002B90A0(void *self, int target_type, int item_id) {
    void *item = func_00332e60(manager_entity_root(self), item_id);
    if (!item) {
        return 0;
    }

    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred(item)) {
        return 0;
    }

    return func_001471a0(pred(item)) == target_type ? 1 : 0;
}

int func_002B9140(void *self) {
    for (int i = 0; i < 4; ++i) {
        store_integer(self, 3216 + i * 4, 0);
    }

    int matched_count = 0;
    int limit = integer_at(self, 3092);
    for (int index = 0; index < limit; ++index) {
        void *sub_obj = bytes(self) + index * 24;
        evaluate_plan_item(self, sub_obj, matched_count);
    }

    for (int i = 0; i < 4; ++i) {
        store_integer(self, 3232 + i * 4, 0);
    }
    store_integer(self, 3316, 0);

    float count_float = static_cast<float>(matched_count);
    calculate_rate_slots(self, count_float);
    adjust_rate_totals(self);
    sort_rates_indices(self);

    return 0;
}
}
