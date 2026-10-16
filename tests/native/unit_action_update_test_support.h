#ifndef UNIT_ACTION_UPDATE_TEST_SUPPORT_H
#define UNIT_ACTION_UPDATE_TEST_SUPPORT_H

#include <cstring>
#include "unit_action_update.h"

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

extern int g_func_2643C0_called;
extern int g_func_26AD20_ret;
extern int g_func_26A540_called;
extern int g_func_183070_called;
extern int g_func_262BA0_called;
extern int g_method29_called;
extern int g_method30_called;
extern int g_method61_called;
extern int g_method62_called;
extern void *g_last_m61_world;
extern void *g_last_m62_world;
extern int g_last_m61_a2;
extern int g_last_m61_a3;
extern int g_last_m61_a4;
extern int g_last_m62_a2;
extern int g_last_m62_a3;
extern int g_last_m62_a4;
void init_mock_vtable();
void test_func_00268500();
void test_func_002683F0();
void test_func_00268410();
void test_func_00268200_dispatch();
void test_func_00268200_transitions();
void test_func_00268200_callbacks();

#endif
