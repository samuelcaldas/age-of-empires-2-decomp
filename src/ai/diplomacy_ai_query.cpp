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

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    TribeAI *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    unsigned char m_field100[10];
};

extern "C" {

int func_0013FA90(DiplomacyAI *self, int player, int mode) {
    if (player <= 0 || !(player < self->m_fieldAC->m_player->m_mgr->m_num_players))
        return -1;
    switch (mode) {
        case 0:
            return self->m_fieldB0[player];
        case 1: {
            int d1 = 49 - self->m_fieldB0[player];
            if (d1 < 0)
                d1 = -d1;
            int d2 = 49 - self->m_fieldD8[player];
            if (d2 < 0)
                d2 = -d2;
            int score = 100 - d1 - d2;
            if (score < 0)
                score = 0;
            return score;
        }
        case 2:
            return self->m_fieldD8[player];
        default:
            return -1;
    }
}

void func_13FB50(DiplomacyAI *self, int player, int mode, int val) {
    if (player <= 0 || !(player < self->m_fieldAC->m_player->m_mgr->m_num_players))
        return;

    switch (mode) {
        case 0:
            self->m_fieldB0[player] += val;
            if (self->m_field100[player]) {
                if (self->m_fieldB0[player] < 0)
                    self->m_fieldB0[player] = 0;
                else if (self->m_fieldB0[player] > 100)
                    self->m_fieldB0[player] = 100;
            } else {
                if (self->m_fieldB0[player] < 50)
                    self->m_fieldB0[player] = 50;
                else if (self->m_fieldB0[player] > 100)
                    self->m_fieldB0[player] = 100;
            }
            break;
        case 1:
            break;
        case 2:
            self->m_fieldD8[player] += val;
            if (self->m_field100[player]) {
                if (self->m_fieldD8[player] < 0)
                    self->m_fieldD8[player] = 0;
                else if (self->m_fieldD8[player] > 100)
                    self->m_fieldD8[player] = 100;
            } else {
                if (self->m_fieldD8[player] < 0)
                    self->m_fieldD8[player] = 0;
                else if (self->m_fieldD8[player] > 48)
                    self->m_fieldD8[player] = 48;
            }
            break;
    }
}
}
