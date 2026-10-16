#ifndef UNIT_ACTION_LOS_FIXTURE_H
#define UNIT_ACTION_LOS_FIXTURE_H

#include <cstddef>
#include <cstring>
#include "unit_action_los.h"

extern int g_func_137AA0_called;
extern int g_func_137EA0_called;
extern int g_func_138040_called;
extern int g_func_138320_called;

extern int g_last_radius;
extern int g_last_arg4;
extern int g_last_diff;
extern short g_last_field24;

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

struct LosEntityMock {
    char pad_00[8];
    short m_field8;
    char pad_0A[18];
    float m_radius;
    float m_extent_x;
    float m_extent_y;
};

struct LosWorldMock {
    char pad_00[0xB94];
    void *m_zone;
    void *m_map;
    char pad_B9C[4];
    int m_val_ba0;
};

struct LosMapMock {
    char pad_00[0x98];
    short m_map_98;
};

#endif // UNIT_ACTION_LOS_FIXTURE_H
