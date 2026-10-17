#pragma exceptions off

class ScreenManager {
public:
    virtual void M0();
    virtual void M1();
    virtual void M2();
    virtual void M3();
    virtual void M4();
    virtual void M5();
    virtual void M6();
    virtual void M7();
    virtual void M8();
    virtual void M9();
    virtual void GetString(int id, char *dest, int max_len);
};

extern "C" {
void func_00184ce0(ScreenManager *self, int mode, int msg_id, int a3, char *dest, int max_len) {
    (void)a3;
    if (mode == 1) {
        goto do_switch;
    }
    if (mode == 2) {
        self->GetString(msg_id, dest, max_len);
        return;
    }
    dest[0] = 0;
    dest[max_len - 1] = 0;
    return;

do_switch:
    switch (msg_id) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 14:
        case 15:
            self->GetString(0x7D2, dest, max_len);
            return;
        case 3:
            self->GetString(0x7E0, dest, max_len);
            return;
        case 7:
        case 8:
        case 11:
        case 13:
        case 17:
            self->GetString(0x7D3, dest, max_len);
            return;
        case 9:
        case 16:
            self->GetString(0x7D5, dest, max_len);
            return;
        case 10:
        case 12:
            self->GetString(0x7D4, dest, max_len);
            return;
        case 18:
            self->GetString(0x7DC, dest, max_len);
            return;
        case 19:
            self->GetString(0x7DB, dest, max_len);
            return;
        case 20:
            self->GetString(0x7DD, dest, max_len);
            return;
        case 21:
            self->GetString(0x7DE, dest, max_len);
            return;
        case 22:
            self->GetString(0x7DF, dest, max_len);
            return;
        case 23:
            self->GetString(0x7E1, dest, max_len);
            return;
        default:
            dest[0] = 0;
            dest[max_len - 1] = 0;
            return;
    }
}
}
