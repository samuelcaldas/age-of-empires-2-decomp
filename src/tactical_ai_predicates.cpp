#include "sub_list.h"

extern "C" {
int func_144550(void *node, int a1, int a2, int a3, int t0);
void func_0013C580(void *obj, int a1, int a2, int a3, int t0);
}

struct TacticalNode24 {
    char data[24];
};

struct Obj12 {
    char data[12];
};

struct PredicateItem {
    short type;
    short op_or_node;
    int a1;
    int a2;
    int a3;
    int t0;
};

struct Rule {
    char pad_0[6];
    unsigned char cond_count;
    unsigned char action_count;
    PredicateItem items[1];
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0xC];
    TacticalNode24 *field_10;
    char pad_14[0x4];
    Obj12 *field_18;
};

extern "C" {

int func_00141A70(TacticalAI *self, Rule *rule, int *p_idx) {
    int idx = (*p_idx)++;
    PredicateItem *item = &rule->items[idx];
    if (item->type == 3) {
        return func_144550(&self->field_10[item->op_or_node], item->a1, item->a2, item->a3, item->t0);
    }

    if (item->op_or_node == 0) {
        return !func_00141A70(self, rule, p_idx);
    }

    int left = func_00141A70(self, rule, p_idx);
    int right = func_00141A70(self, rule, p_idx);

    switch (item->op_or_node) {
    case 1:
        return (left != 0 && right != 0);
    case 2:
        return ((left != 0) && !(right != 0)) || (!(left != 0) && (right != 0));
    case 3:
        return (left != 0 || right != 0);
    case 4:
        return !(left != 0 || right != 0);
    case 5:
        return ((left != 0 && right != 0) || (!(left != 0) && !(right != 0)));
    case 6:
        return !(left != 0 && right != 0);
    default:
        return 0;
    }
}

int func_00141C70(TacticalAI *self, Rule *rule) {
    int i = 0;
    while (i < rule->cond_count) {
        if (!func_00141A70(self, rule, &i)) {
            return 0;
        }
    }
    for (i = rule->cond_count; i < rule->action_count; i++) {
        PredicateItem *act = &rule->items[i];
        func_0013C580(&self->field_18[act->op_or_node], act->a1, act->a2, act->a3, act->t0);
    }
    return 1;
}

}
