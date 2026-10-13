#include "sub_list.h"

struct MasterObjects {
    char pad_00[4];
    void **m_table;
    short m_count;
};

struct MasterStaticObject {
    char pad0[6];
    short id;
    char pad1[0x2C];
    int type1;
    int type2;
    int type3;
    int type4;
};

extern "C" {

void func_0013C0D0(SubList *self, void *param1) {
    int match = 0;
    if (self->m_field30 != 0) {
        MasterObjects *header = *(MasterObjects**)((char*)param1 + 0xC8);
        if (header != 0) {
            MasterStaticObject **table = (MasterStaticObject**)header->m_table;
            int i = header->m_count - 1;
            while (i >= 0) {
                if (*(short*)((char*)self->m_field30 + 6) == table[i]->id) {
                    break;
                }
                --i;
            }
            if (i < 0) {
                return;
            }

            MasterStaticObject **p = &table[i];
            PlayerContext *player = (PlayerContext*)self->m_field8;
            if (player->m_target_type == (*p)->type1) {
                match = (*p)->type1;
            } else if (player->m_target_type == (*p)->type2) {
                match = (*p)->type2;
            } else if (player->m_target_type == (*p)->type3) {
                match = (*p)->type3;
            } else if (player->m_target_type == (*p)->type4) {
                match = (*p)->type4;
            }

            if (match != 0) {
                player->Method17(match);
            }

            self->v17(param1, self->m_field30, *p);
            ((ListItem*)self->m_field34)->Method9(param1, self->m_field30, *p);
            self->m_field30 = *p;
            return;
        }
    }

    self->v17(param1, 0, 0);
    ((ListItem*)self->m_field34)->Method9(param1, 0, 0);
}

void func_0013C250(SubList *self) {
}

}
