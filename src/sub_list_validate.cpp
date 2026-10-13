#include "sub_list.h"

static inline void validate_targets(SubList *self) {
    if (self->m_field10 != 0 && ((unsigned char*)self->m_field10)[0x39] >= 7) {
        self->v21(0);
    }
    if (self->m_field14 != 0 && ((unsigned char*)self->m_field14)[0x39] >= 7) {
        self->v22(0);
    }
}

extern "C" {

int func_0013BD90(SubList *self) {
    validate_targets(self);
    return 1;
}

int func_0013BE10(SubList *self) {
    validate_targets(self);
    return 1;
}

}
