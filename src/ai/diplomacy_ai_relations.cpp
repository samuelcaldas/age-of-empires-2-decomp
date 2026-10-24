#include "sub_list.h"

#pragma exceptions off

class OtherPlayerBase {
  public:
    char pad_00[0x1B30];
};

class OtherPlayer : public OtherPlayerBase {
  public:
    virtual void *v0();
    virtual void *v1();
    virtual void *v2();
    virtual void *v3();
    virtual void *v4();
    virtual void *v5();
    virtual void *v6();
    virtual void *v7();
    virtual void *v8();
    virtual int CheckRelation(int self_id);
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
    char pad_BA4[0xBD8 - 0xBA4];
    unsigned char *m_stances;
};

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
};

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    TribeAI *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {

int func_1401C0(DiplomacyAI *self, int player) {
    if (player > 0) {
        TribePlayer *tp = self->m_fieldAC->m_player;
        if (player <= tp->m_mgr->m_num_players && player != tp->m_player_id && tp->m_stances[player] == 3) {
            return 1;
        }
    }
    return 0;
}

int func_140220(DiplomacyAI *self, int player) {
    if (player > 0) {
        TribePlayer *tp = self->m_fieldAC->m_player;
        if (player <= tp->m_mgr->m_num_players && player != tp->m_player_id && tp->m_stances[player] == 1) {
            return 1;
        }
    }
    return 0;
}

int func_140280(DiplomacyAI *self, int player) {
    TribePlayer *tp = self->m_fieldAC->m_player;
    if (player == tp->m_player_id) {
        return 1;
    }
    if (player > 0) {
        if (player <= tp->m_mgr->m_num_players && tp->m_stances[player] == 0) {
            return 1;
        }
    }
    return 0;
}

int func_1402E0(DiplomacyAI *self, int player) {
    if (player <= 0 || player >= self->m_fieldAC->m_player->m_mgr->m_num_players) {
        return 0;
    }
    OtherPlayer *other = self->m_fieldAC->m_player->m_mgr->m_players[player];
    if (other && other->CheckRelation(self->m_fieldAC->m_player->m_player_id)) {
        return 1;
    }
    return 0;
}

/*
 * func_00140360:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00140360, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for section alignment / empty callback stub.
 */
void func_00140360() {}
}
