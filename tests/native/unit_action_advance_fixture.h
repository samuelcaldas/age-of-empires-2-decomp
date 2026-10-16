#ifndef UNIT_ACTION_ADVANCE_FIXTURE_H
#define UNIT_ACTION_ADVANCE_FIXTURE_H

#include <cstddef>
#include <cstring>
#include "unit_action_advance.h"

extern int g_func_26A540_called;
extern int g_func_1AAB30_called;
extern int g_func_26A700_called;
extern int g_func_25F6E0_called;
extern int g_func_1AAB70_called;
extern int g_func_26A680_called;
extern unsigned char g_last_frame;

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    int m_field20;
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;

    ActionMock();
};

extern float mock_method32_ret;
void init_mock_vtable();

#endif // UNIT_ACTION_ADVANCE_FIXTURE_H
