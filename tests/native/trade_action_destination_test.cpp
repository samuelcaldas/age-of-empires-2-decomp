#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>

extern "C" {
int g_token = 0;
int g_token_call_count = 0;
int g_random_val = 100;

int func_001AAB30() {
    return g_random_val;
}

void func_001AAB70(int token) {
    g_token = token;
    g_token_call_count++;
}

int g_last_a1 = -1;
void func_00150F50(void *self, int a1) {
    g_last_a1 = a1;
}

void *func_00332E60(void *mgr, short id) {
    return NULL;
}

int func_00202B10(void *ptr) {
    return 0;
}

struct SearchItem {
    int id;
    int field_4;
};

SearchItem g_items[1] = {{1, 0}};
SearchItem *D_00F99910[5] = {g_items, g_items, g_items, g_items, g_items};
int D_00F99930[5] = {0, 0, 0, 0, 0};

class TargetObj {
public:
    char pad_00[0x8];
    void *m_game;
    char pad_0C[0x18];
    short m_field24;
    char pad_26[0x1E];
    float m_posX;
    float m_posY;
};

class TradeActionBase {
public:
    virtual void vfn0() {}
    virtual void vfn1() {}
    virtual void vfn2() {}
    virtual void vfn3() {}
    virtual void vfn4() {}
    virtual void vfn5() {}
    virtual void vfn6() {}
    virtual void vfn7() {}
    virtual void vfn8() {}
    virtual void Method2C(int a1, float f12, float f13) {}

    char pad_04[0x34];
    TargetObj *m_target;
    char pad_3C[0x104];
    unsigned int m_field140;
    unsigned int m_field144;
    char pad_148[4];
    int m_field14C;
    int m_field150;
    char pad_154[0x18];
    unsigned int m_field16C;
};

void func_0014BE10(TradeActionBase *self);
void func_0014BE70(TradeActionBase *self, unsigned int val);
void func_0014BEE0(void *self);
int func_0014BEF0();
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_num = std::atoi(argv[1]);

    if (case_num == 0) {
        assert(func_0014BEF0() == -1);
    } else if (case_num == 1) {
        char obj[16] = {0};
        func_0014BEE0(obj);
        assert(g_last_a1 == 0);
    } else if (case_num == 2) {
        TradeActionBase action;
        action.m_field144 = 1000;
        g_random_val = 123;
        func_0014BE10(&action);
        assert(action.m_field140 == 873);
    } else if (case_num == 3) {
        TradeActionBase action;
        g_random_val = 45;
        func_0014BE70(&action, 500);
        assert(action.m_field16C == 795);
    } else if (case_num == 4) {
        TradeActionBase action;
        g_random_val = 210;
        func_0014BE70(&action, 2000);
        assert(action.m_field16C == 1710);
    }

    return 0;
}
