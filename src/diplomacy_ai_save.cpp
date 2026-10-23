#include "sub_list.h"

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
    char m_field100[10];

    int Save(void *stream);
};

extern "C" {
void func_00226F70(void *stream, void *src, int size);
int func_140280(void *self, int player);
int func_1402E0(void *self, int player);
void func_13FB50(void *self, int player, int a2, int a3);

int func_0013F910(DiplomacyAI *self) {
    for (int i = 1; i < self->m_fieldAC->m_player->m_mgr->m_num_players; i++) {
        if (i == self->m_fieldAC->m_player->m_player_id) {
            continue;
        }
        if (func_140280(self, i)) {
            if (!func_1402E0(self, i)) {
                func_13FB50(self, i, 0, 1);
            }
        }
        if (!func_140280(self, i) && func_1402E0(self, i)) {
            func_13FB50(self, i, 2, 1);
        }
    }
    return 1;
}

int DiplomacyAI::Save(void *stream) {
    for (int i = 0; i <= 9; i++) {
        func_00226F70(stream, &this->m_fieldB0[i], 4);
        func_00226F70(stream, &this->m_fieldD8[i], 4);
        func_00226F70(stream, &this->m_field100[i], 1);
    }
    return 1;
}
}
