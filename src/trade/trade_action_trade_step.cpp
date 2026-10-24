#pragma exceptions off
#include "sub_list.h"

class TargetObj;

extern "C" {
int func_1AAB30();
void func_001471B0(void *self, int a1);
void func_14BD20(void *self, int a1, float x, float y, float z);
}

class TargetObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual int Method12C(float x, float y); // 0x12C
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual int Method17C(int a1, float x, float y, float z, float f15, int a2); // 0x17C
};

class TradeAction {
public:
    virtual void vfn0();
    char pad_04[0x34];
    TargetObj *m_target; // 0x38
    char pad_3C[0xC];
    short m_field48;     // 0x48
};

extern "C" {

int func_0014AB20(TradeAction *self, int a1, float x, float y, float z) {
    if (!a1 && self->m_field48 != -1) {
        return 0;
    }

    if (x < 0.0f) {
        x = 0.0f;
    } else {
        void *game = *(void **)((char *)self->m_target + 8);
        void *timer = *(void **)((char *)game + 0xB98);
        void *map = *(void **)((char *)timer + 0x3C);
        float width = (float)*(int *)((char *)map + 8);
        if (x >= width) {
            x = width - 1.0f;
        }
    }

    if (y < 0.0f) {
        y = 0.0f;
    } else {
        void *game = *(void **)((char *)self->m_target + 8);
        void *timer = *(void **)((char *)game + 0xB98);
        void *map = *(void **)((char *)timer + 0x3C);
        float height = (float)*(int *)((char *)map + 0xC);
        if (y >= height) {
            y = height - 1.0f;
        }
    }

    int s0 = 0;
    for (int s1 = 0; s1 < 5; s1++) {
        if (self->m_target->Method12C(x, y) == 1) {
            s0 = 1;
            break;
        }

        if (func_1AAB30() % 2) {
            x += (float)(func_1AAB30() % 4);
        } else {
            x -= (float)(func_1AAB30() % 4);
        }

        if (func_1AAB30() % 2) {
            y += (float)(func_1AAB30() % 4);
        } else {
            y -= (float)(func_1AAB30() % 4);
        }

        if (x < 0.0f) {
            x = 0.0f;
        } else {
            void *game = *(void **)((char *)self->m_target + 8);
            void *timer = *(void **)((char *)game + 0xB98);
            void *map = *(void **)((char *)timer + 0x3C);
            float width = (float)*(int *)((char *)map + 8);
            if (x >= width) {
                x = width - 1.0f;
            }
        }

        if (y < 0.0f) {
            y = 0.0f;
        } else {
            void *game = *(void **)((char *)self->m_target + 8);
            void *timer = *(void **)((char *)game + 0xB98);
            void *map = *(void **)((char *)timer + 0x3C);
            float height = (float)*(int *)((char *)map + 0xC);
            if (y >= height) {
                y = height - 1.0f;
            }
        }
    }

    if (!s0) {
        return 0;
    }

    if (self->m_target->Method17C(a1, x, y, z, 0.0f, 0) == 1) {
        func_001471B0(self, 0x262);
        func_14BD20(self, -1, x, y, z);
        return 1;
    }

    return 0;
}

int func_0014AEE0() {
    return 0;
}

}
