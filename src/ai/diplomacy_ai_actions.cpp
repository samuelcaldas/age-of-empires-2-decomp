#include "sub_list.h"

#pragma exceptions off

class OtherPlayer {
public:
    char pad_00[0x54];
    char pad_54[0xB90 - 0x54];
    void *m_fieldB90;
    char pad_B94[0xBA6 - 0xB94];
    unsigned char m_status;
};

struct PlayerMgr {
    char pad_00[0x50];
    short m_num_players;
    short pad_52;
    OtherPlayer **m_players;
};

struct TribePlayer {
    char pad_00[0xB98];
    PlayerMgr *m_mgr;
    char pad_B9C[4];
    int m_player_id;
};

struct AIObj {
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16(); virtual void* v17(); virtual void* v18(); virtual void* v19();
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23();
    virtual int Method24(int player);
};

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
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

int func_140280(void*, int);
int func_140220(void*, int);
int func_318280(void*);
int func_1401C0(void*, int);

int func_13FEF0(DiplomacyAI *self, int a1, int a2, int t0, int a3) {
    int best_player = -1;
    int best_score = best_player;

    for (int player = 1; player < ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_num_players; player++) {
        if (player == ((TribeAI*)self->m_fieldAC)->m_player->m_player_id) {
            continue;
        }
        if (((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player]->m_status == 2) {
            continue;
        }
        if (a1 > 0) {
            if (a2 == player && func_140280(self, player)) {
                continue;
            }
        }
        if (func_140280(self, player) == 1) {
            continue;
        }
        if (func_140220(self, player) == 1) {
            continue;
        }
        if (!self->m_fieldAC->Method24(player)) {
            continue;
        }
        int val = func_318280(((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player]->m_fieldB90);
        int score = self->m_fieldB0[player];
        if (a3 >= 2) {
            if (t0 == 1) {
                score += val / a3;
            } else {
                score -= val / a3;
            }
        }
        if (score > best_score) {
            best_score = score;
            best_player = player;
        }
    }
    return best_player;
}

int func_001400B0() {
    return 0;
}

int func_001400C0(DiplomacyAI *self, int a1, int a2) {
    int best_player = -1;
    int best_val = best_player;

    for (int player = 1; player < ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_num_players; player++) {
        if (player == ((TribeAI*)self->m_fieldAC)->m_player->m_player_id) {
            continue;
        }
        OtherPlayer *other = ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player];
        if (other->m_status == 2) {
            continue;
        }
        if (a1 > 0) {
            if (a2 == player && func_1401C0(self, player)) {
                continue;
            }
        }
        int val = self->m_fieldD8[player];
        if (val > best_val) {
            best_val = val;
            best_player = player;
        }
    }
    return best_player;
}

}
