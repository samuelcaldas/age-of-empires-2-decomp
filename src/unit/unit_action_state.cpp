#pragma exceptions off
#include "unit_action_state.h"

int func_00268530(ActionRebind *self) {
    if (func_00268500(self) == 0) {
        return 0;
    }
    int count = 0;
    ActionRebind *curr = *(ActionRebind**)((char*)self + 0x20);
    while (curr != 0) {
        count++;
        curr = *(ActionRebind**)((char*)curr + 0x20);
    }
    return count;
}

ActionRebind* func_00268590(ActionRebind *self, int target_index) {
    int index = 0;
    ActionRebind *curr = *(ActionRebind**)((char*)self + 0x20);
    while (curr != 0) {
        if (index == target_index) {
            return curr;
        }
        index++;
        curr = *(ActionRebind**)((char*)curr + 0x20);
    }
    return 0;
}

void func_002685C0(ActionRebind *self) {
    if (func_00268500(self)) {
        ActionRebind *child;
        while ((child = *(ActionRebind**)((char*)self + 0x20)) != 0) {
            child->Method58();
        }
    }
}

int func_00268610(ActionRebind *self, int filter_state, int filter_fieldE, int filter_field8, int min_x, int min_y, int max_x, int max_y, int filter_field74, ActionRebind **out_actions) {
    if (func_00268500(self) == 0) {
        return 0;
    }

    int count = 0;
    ActionRebind *curr = self;
    while ((curr = *(ActionRebind**)((char*)curr + 0x20)) != 0) {
        if (filter_field8 >= 0) {
            if ((int)curr->m_field39 != filter_field8) {
                continue;
            }
        }

        void *curr_f4 = curr->m_field4;
        if (filter_state >= 0) {
            if ((int)*(short*)((char*)curr_f4 + 8) != filter_state) {
                continue;
            }
        } else if (filter_fieldE >= 0) {
            if ((int)*(short*)((char*)curr_f4 + 14) != filter_fieldE) {
                continue;
            }
        } else if (filter_field74 >= 0) {
            if ((int)*(unsigned char*)((char*)curr_f4 + 0x74) != filter_field74) {
                continue;
            }
        }

        if (min_x >= 0) {
            int tx = func_123350(curr->m_x);
            if (tx < min_x) {
                continue;
            }
            int ty = func_123350(curr->m_y);
            if (ty < min_y) {
                continue;
            }
            tx = func_123350(curr->m_x);
            if (tx > max_x) {
                continue;
            }
            ty = func_123350(curr->m_y);
            if (ty > max_y) {
                continue;
            }
        }

        if (out_actions != 0) {
            out_actions[count] = curr;
        }
        count++;
    }

    return count;
}

int func_002687C0(ActionRebind *self) {
    int count = func_00268530(self);
    void *f4 = self->m_field4;
    unsigned char capacity = *(unsigned char*)((char*)f4 + 1);
    return count < (int)capacity;
}
