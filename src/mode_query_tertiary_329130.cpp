struct ModeQueryTertiaryContext {
    int m_field_0;
    int m_field_4;
    int m_field_8;
    int m_field_C;
    int m_field_10;
    int m_active;
    void *m_manager;
};

extern "C" {
    int func_00329130(ModeQueryTertiaryContext *self, int param_1, int param_2) {
        if (!self) return -1;
        if (self->m_active == 0) return 0;

        self->m_field_0 = param_1;
        self->m_field_4 = param_2;
        self->m_field_8 = param_1 + param_2;
        self->m_field_C = param_1 - param_2;
        self->m_field_10 = param_1 ^ param_2;
        int temp = param_1 * param_2;
        self->m_field_0 += temp;
        int temp2 = param_1 - param_2;
        self->m_field_4 += temp2;

        if (self->m_manager) {
            typedef int (*ManagerNotifyFn)(void *manager, int val, int extra);
            ManagerNotifyFn notify = *(ManagerNotifyFn *)((char *)self->m_manager + 0x18);
            if (notify) {
                notify(self->m_manager, param_1, param_2);
            }
        }

        return self->m_field_8 + self->m_field_C + self->m_field_10;
    }
}
