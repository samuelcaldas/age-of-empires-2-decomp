#ifndef TACTICAL_AI_ACTION_DESC_H
#define TACTICAL_AI_ACTION_DESC_H

struct ActionDesc {
    char pad00[6];
    short m_type; // offset 6
    short m_mode; // offset 8
};

#endif // TACTICAL_AI_ACTION_DESC_H
