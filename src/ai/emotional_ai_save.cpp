#include "sub_list.h"

struct EmotionalAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[6];
    char m_buf1[30];
    char m_buf2[30];
    char m_buf3[30];
    char m_buf4[30];
    char m_buf5[30];
    char m_buf6[30];

    int Save(void *stream);
};

extern "C" {
void func_00226F70(void *stream, void *src, int size);

int EmotionalAI::Save(void *stream) {
    for (int i = 0; i < 6; i++) {
        func_00226F70(stream, &this->m_fieldB0[i], 4);
    }
    return 1;
}

void func_00140670(EmotionalAI *self, int personality) {
    switch (personality) {
        case 0:
            self->m_fieldB0[0] = 100;
            self->m_fieldB0[4] = 10;
            self->m_fieldB0[1] = 10;
            self->m_fieldB0[3] = 10;
            self->m_fieldB0[2] = 0;
            self->m_fieldB0[5] = 70;
            break;
        case 4:
            self->m_fieldB0[0] = 20;
            self->m_fieldB0[4] = 100;
            self->m_fieldB0[1] = 70;
            self->m_fieldB0[3] = 50;
            self->m_fieldB0[2] = 60;
            self->m_fieldB0[5] = 0;
            break;
        case 1:
            self->m_fieldB0[0] = 10;
            self->m_fieldB0[4] = 50;
            self->m_fieldB0[1] = 100;
            self->m_fieldB0[3] = 80;
            self->m_fieldB0[2] = 50;
            self->m_fieldB0[5] = 0;
            break;
        case 3:
            self->m_fieldB0[0] = 10;
            self->m_fieldB0[4] = 50;
            self->m_fieldB0[1] = 70;
            self->m_fieldB0[3] = 100;
            self->m_fieldB0[2] = 50;
            self->m_fieldB0[5] = 20;
            break;
        case 2:
            self->m_fieldB0[0] = 20;
            self->m_fieldB0[4] = 60;
            self->m_fieldB0[1] = 50;
            self->m_fieldB0[3] = 50;
            self->m_fieldB0[2] = 100;
            self->m_fieldB0[5] = 10;
            break;
        case 5:
            self->m_fieldB0[0] = 90;
            self->m_fieldB0[4] = 10;
            self->m_fieldB0[1] = 0;
            self->m_fieldB0[3] = 30;
            self->m_fieldB0[2] = 50;
            self->m_fieldB0[5] = 100;
            break;
    }
}
}
