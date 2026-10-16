#pragma exceptions off
#include "tactical_ai_action_items.h"

void func_00307220(void *self, ActionItem *item) {
    switch (item->m_type) {
    case 100:
        func_00307270((Manager *)self, item);
        break;
    default:
        func_316130(self, item);
        break;
    }
}

void func_00307270(Manager *self, ActionItem *item) {
    Player *player = self->m_player;
    if (player && item->m_field2E == 0) {
        short arg1 = *(short *)((char *)item + 32);
        int res = func_2d33e0(player->m_field1B34, arg1);
        if ((short)res == 3) {
            item->m_field2E = 2;
        }
    }
}

int func_003072D0(void *self, int arg1, int arg2) {
    ActionItem *item = func_316ea0(self, arg1, 0);
    if (item) {
        item->m_type = 100;
        item->m_arg2 = arg2;
        return 1;
    }
    return 0;
}
