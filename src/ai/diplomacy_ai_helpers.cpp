#include "sub_list.h"

#pragma exceptions off

struct PlayerMgr {
    char pad_00[0x50];
    short m_num_players;
};

struct TribePlayer {
    char pad_00[0xB98];
    PlayerMgr *m_mgr;
    char pad_B9C[4];
    int m_player_id;
};

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
};

struct AIObj {
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16(); virtual void* v17(); virtual void* v18(); virtual void* v19();
    virtual int GetFact(int id);
};

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    AIObj *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    unsigned char m_field100[10];
};

extern "C" {

void func_13FEF0(void*, int, int, int, int);

void func_0013FC80(DiplomacyAI *self, int player, int mode, int val) {
    if (player <= 0 || player >= ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_num_players) return;
    switch (mode) {
    case 0:
        self->m_fieldB0[player] = val;
        if (self->m_field100[player]) {
            if (self->m_fieldB0[player] < 0) self->m_fieldB0[player] = 0;
            else if (self->m_fieldB0[player] > 100) self->m_fieldB0[player] = 100;
        } else {
            if (self->m_fieldB0[player] < 50) self->m_fieldB0[player] = 50;
            else if (self->m_fieldB0[player] > 100) self->m_fieldB0[player] = 100;
        }
        break;
    case 1:
        break;
    case 2:
        self->m_fieldD8[player] = val;
        if (self->m_field100[player]) {
            if (self->m_fieldD8[player] < 0) self->m_fieldD8[player] = 0;
            else if (self->m_fieldD8[player] > 100) self->m_fieldD8[player] = 100;
        } else {
            if (self->m_fieldD8[player] < 0) self->m_fieldD8[player] = 0;
            else if (self->m_fieldD8[player] > 48) self->m_fieldD8[player] = 48;
        }
        break;
    }
}

int func_0013FDA0(DiplomacyAI *self, int player) {
    if (player > 0) {
        TribePlayer *tp = ((TribeAI*)self->m_fieldAC)->m_player;
        if (player < tp->m_mgr->m_num_players && self->m_field100[player] == 1) {
            return 1;
        }
    }
    return 0;
}

void func_0013FDF0(DiplomacyAI *self, int player, int val) {
    if (player > 0) {
        TribePlayer *tp = ((TribeAI*)self->m_fieldAC)->m_player;
        if (player < tp->m_mgr->m_num_players) {
            self->m_field100[player] = (unsigned char)val;
        }
    }
}

void func_0013FE30(DiplomacyAI *self) {
    self->m_fieldAC->GetFact(0x7C);
    int p1 = self->m_fieldAC->GetFact(0x80);
    int p2 = self->m_fieldAC->GetFact(0xBC);
    int p3 = self->m_fieldAC->GetFact(0xC3);
    func_13FEF0(self, p1, p2, p3, p3);
}

int func_0013FEE0() {
    return -1;
}

}
