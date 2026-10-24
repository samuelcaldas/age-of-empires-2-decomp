#pragma exceptions off
#include "sub_list.h"

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
    virtual void vfn73();
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
    virtual float Method15C(); // 0x15C
    virtual void vfn86();
    virtual int Method164();   // 0x164

    void *m_field4;        // 0x4
    void *m_game;          // 0x8
    char m_padC[0x18];     // 0xC
    short m_field24;       // 0x24
    char m_pad26[0x13];    // 0x26
    unsigned char m_state; // 0x39
    char m_pad3A[0x2A];    // 0x3A
    int m_field64;         // 0x64
};

struct GameBase {
    char pad[0x1B30];
};

struct GameObj : public GameBase {
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
    virtual void Method118(short a1, short a2, int a3, int t0, int t1, int t2); // 0x118
};

struct RouteData {
    char m_data[0x28];
};

struct TradeAction {
    void *m_vtable;        // 0x0
    RouteData m_route;     // 0x4 to 0x2B
    unsigned char m_field2C; // 0x2C
    char m_field2D;        // 0x2D
    char m_field2E;        // 0x2E
    char m_field2F;        // 0x2F
    char m_pad30[0x8];     // 0x30 to 0x37
    TargetObj *m_target;   // 0x38
    void *m_buf3C;         // 0x3C
    void *m_buf40;         // 0x40
    short m_field44;       // 0x44
    short m_field46;       // 0x46
    short m_field48;       // 0x48
    short m_field4A;       // 0x4A
    short m_field4C;       // 0x4C
    short m_field4E;       // 0x4E
    float m_float50;       // 0x50
    float m_float54;       // 0x54
    float m_float58;       // 0x58
    float m_float5C;       // 0x5C
    char pad_60[0xFC];     // 0x60 to 0x15B
    float m_float15C;      // 0x15C

    RouteData *GetRoute() {
        return &m_route;
    }
};

extern "C" {

extern unsigned char D_004E305C;
extern int D_004E3060;
extern void *D_004E3510;
extern int D_00F99940[];

void* func_333b30(void *timer, int field64);
void func_1BCE20(void *entity, short field24, int a2, short a3, int t0, int t1);
void* func_1AAB30();
void func_1AAB70(void *token);
TargetObj* func_1510D0(TradeAction *self, short field4E);
int func_123350(float val);
int func_327A30(void *a0, int a1, int a2, int a3, void *t0, void *t1, unsigned char t2, void *t3);

void func_00147CD0(TradeAction *self, short *param1) {
    if (self->m_target->m_field64 == -1) {
        return;
    }

    void *timer = *(void **)((char *)self->m_target->m_game + 0xB98);
    void *entity = func_333b30(timer, self->m_target->m_field64);
    if (!entity) {
        return;
    }

    switch (param1[2]) {
    case 0x20F:
    case 0x1F4:
        func_1BCE20(entity, self->m_target->m_field24, 0, param1[0], 0, 0);
        break;
    }
}

void func_00147D70(TradeAction *self, float f12, float f13, int param1) {
    void *token = func_1AAB30();
    if (D_004E305C != 1) {
        D_004E305C = 1;

        if (!self->GetRoute()) {
            goto exit_action;
        }

        if (self->m_field44 == 0x2BD && self->m_field4E != -1) {
            TargetObj *s4 = func_1510D0(self, self->m_field4E);
            if (s4 && s4->Method164()) {
                int s3 = func_123350(*(float *)((char *)s4 + 0x44));
                param1 = func_123350(*(float *)((char *)s4 + 0x48));
                void *v0 = s4->m_field4;
                int a3 = func_123350(*(float *)((char *)v0 + 0x1C));
                void *game_s4 = s4->m_game;
                TargetObj *v1 = self->m_target;
                unsigned char f2c = self->m_field2C;
                RouteData *route = self->GetRoute();
                void *t0 = *(void **)((char *)game_s4 + 0xBA0);
                void *t3 = (char *)v1->m_game + 0xBDC;
                D_004E3060 = func_327A30(D_004E3510, s3, param1, a3, t0, route, f2c, t3);
                goto exit_action;
            }
        }

        float f0 = self->m_target->Method15C();
        int limit = func_123350(f0);
        TargetObj *target = self->m_target;
        void *t_f4 = target->m_field4;
        int min_limit = func_123350(*(float *)((char *)t_f4 + 0x1C)) + 1;
        if (limit < min_limit) {
            limit = min_limit;
        }

        GameObj *game = (GameObj *)target->m_game;
        int s3 = func_123350(f12);
        int a2 = func_123350(f13);
        void *t0 = *(void **)((char *)game + 0xBA0);
        void *t3 = (char *)game + 0xBDC;
        D_004E3060 = func_327A30(D_004E3510, s3, a2, limit, t0, self->GetRoute(), self->m_field2C, t3);

        if (D_00F99940[0] > 0) {
            self->m_field2F = 1;
            if ((param1 & 0xFF) == 1) {
                if (self->m_float15C > 10.0f) {
                    GameObj *game_obj = (GameObj *)self->m_target->m_game;
                    short id = self->m_target->m_field24;
                    game_obj->Method118(id, id, 0x210, 0, 0, 0);
                }
                self->m_float15C = 0.0f;
            }
        } else {
            self->m_field2F = 0;
        }
    }

exit_action:
    func_1AAB70(token);
}

}
