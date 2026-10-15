#pragma exceptions off
#include "unit_action_core.h"

ActionNodeItem* func_00266780(Action *self) {
    short idx = self->m_field4->m_field3C;
    if (idx >= 0) {
        ActionNodeItem *node = (ActionNodeItem*)self->m_world->m_items[idx];
        if (node != 0) {
            if (func_208260() != 0) {
                ActionNodeItem *result = (ActionNodeItem*)node->m_fieldA0->Method34(node, self->m_world, self->m_x, self->m_y, self->m_z);
                if (!result) {
                    func_2082A0(self->m_world);
                } else {
                    result->m_field62 = 1;
                }
                return result;
            }
        }
    }
    return 0;
}

void func_00266840(Action *self) {
    self->Method17(self->m_x, self->m_y, self->m_z);
    int field1C = self->m_field1C;
    if (field1C != 0) {
        self->m_field1C = 0;
        void *target = func_002668C0(self, field1C - 1);
        if (target != 0) {
            self->Method57(target, 1);
        }
    }
}

void* func_002668C0(void *self, int param) {
    return func_332e60(((Action*)self)->m_world->m_fieldB98, param);
}

void* func_002668D0(void *self, short idx) {
    void *result = 0;
    if (idx >= 0) {
        void *container = ((Action*)self)->m_world->m_fieldB98;
        if (idx < *(short*)((char*)container + 0x48)) {
            result = (*(void***)((char*)container + 0x4C))[idx];
        }
    }
    return result;
}

void func_00266920(Action *self, void *stream) {
    func_00226F70(stream, &self->m_field38, 1);
    func_00226F70(stream, (char*)self->m_world + 0xBA0, 1);
    func_00226F70(stream, &self->m_field4->m_field8, 2);

    short target_id;
    if (self->m_target != 0) {
        target_id = self->m_target->m_id;
    } else {
        target_id = -1;
    }
    func_00226F70(stream, &target_id, 2);

    int target_owner;
    if (self->m_field1C != 0) {
        target_owner = *(short*)((char*)self->m_field1C + 0x24);
    } else {
        target_owner = -1;
    }
    func_00226F70(stream, &target_owner, 4);

    func_00226F70(stream, &self->m_field30, 4);
    func_00226F70(stream, &self->m_field39, 1);

    char flag1 = func_26AD20(self, 1);
    func_00226F70(stream, &flag1, 1);

    char flag4 = func_26AD20(self, 4);
    func_00226F70(stream, &flag4, 1);

    char flag2 = func_26AD20(self, 2);
    func_00226F70(stream, &flag2, 1);

    char flag3 = func_26AD20(self, 3);
    func_00226F70(stream, &flag3, 1);

    int field24 = self->m_field24;
    func_00226F70(stream, &field24, 4);

    func_00226F70(stream, &self->m_field35, 1);
    func_00226F70(stream, &self->m_x, 4);
    func_00226F70(stream, &self->m_y, 4);
    func_00226F70(stream, &self->m_z, 4);

    func_00226F70(stream, &self->m_field28, 2);
    func_00226F70(stream, &self->m_field2A, 2);
    func_00226F70(stream, &self->m_field2C, 2);
    func_00226F70(stream, &self->m_field2E, 2);

    func_00226F70(stream, &self->m_field37, 1);
    func_00226F70(stream, &self->m_field3C, 2);
    func_00226F70(stream, &self->m_field40, 4);
    func_00226F70(stream, &self->m_field3A, 1);
    func_00226F70(stream, &self->m_field34, 1);
    func_00226F70(stream, &self->m_field3B, 1);

    char flag10 = func_26AD20(self, 0x10);
    func_00226F70(stream, &flag10, 1);

    int count = self->m_field5C;
    func_00226F70(stream, &count, 4);

    for (int i = 0; i < self->m_field5C; i++) {
        int item = self->m_field58[i];
        func_00226F70(stream, &item, 4);
    }

    func_00226F70(stream, &self->m_field64, 4);

    char flag8 = func_26AD20(self, 8);
    func_00226F70(stream, &flag8, 1);

    char hasFieldC;
    if (self->m_fieldC == 0) {
        hasFieldC = 0;
    } else {
        hasFieldC = 1;
    }
    func_00226F70(stream, &hasFieldC, 1);

    if (self->m_fieldC != 0) {
        func_1823E0(self->m_fieldC, stream);
    }
}
