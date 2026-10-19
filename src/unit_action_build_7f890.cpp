#pragma exceptions off
#include "unit_action_build_7f890.h"

struct ActionArg {
    int field_0;
    int field_4;
};

extern "C" {
    extern void *D_4E35DC;

    void *func_366C60(void *factory);
    void func_3521C0(void *item, void *self, int field_4);

    void *func_366D10(void *factory);
    void func_35D6F0(void *item, void *self, int field_4);

    void *func_366D70(void *factory);
    void func_3633B0(void *item, void *self, int field_4);

    void *func_366C80(void *factory);
    void func_354990(void *item, void *self, int field_4);

    void *func_366CD0(void *factory);
    void func_359640(void *item, void *self, int field_4);

    void *func_366CF0(void *factory);
    void func_35CA30(void *item, void *self, int field_4);

    void *func_366C50(void *factory);
    void func_351160(void *item, void *self, int field_4);

    void *func_366DB0(void *factory);
    void func_365F00(void *item, void *self, int field_4);

    void *func_366CA0(void *factory);
    void func_356C90(void *item, void *self, int field_4);

    void *func_366CB0(void *factory);
    void func_357230(void *item, void *self, int field_4);

    void *func_366CC0(void *factory);
    void func_3574F0(void *item, void *self, int field_4);

    void *func_366CE0(void *factory);
    void func_35A140(void *item, void *self, int field_4);

    void *func_366D50(void *factory);
    void func_360000(void *item, void *self, int field_4, int arg4);

    void *func_366D80(void *factory);
    void func_363940(void *item, void *self, int field_4);

    void *func_366C40(void *factory);
    void func_3505B0(void *item, void *self, int field_4);

    void *func_366BD0(void *factory);
    void func_34A520(void *item, void *self, int field_4);

    void *func_366D30(void *factory);
    void func_35EE30(void *item, void *self, int field_4);

    void *func_366D20(void *factory);
    void func_35E4A0(void *item, void *self, int field_4);

    void *func_366C90(void *factory);
    void func_3566C0(void *item, void *self, int field_4);

    void *func_366D40(void *factory);
    void func_35F9E0(void *item, void *self, int field_4);

    void *func_366D90(void *factory);
    void func_364D70(void *item, void *self, int field_4);

    void *func_366DA0(void *factory);
    void func_3656F0(void *item, void *self, int field_4);

    void *func_366C70(void *factory);
    void func_353650(void *item, void *self, int field_4);

    void *func_366D60(void *factory);
    void func_3612E0(void *item, void *self, int field_4);

    void *func_366D00(void *factory);
    void func_35CEB0(void *item, void *self, int field_4);

    void *func_138D50(void *self, void *arg1, short code);
}

void *func_0027F890(void *self, void *arg1, short code) {
    register void *r_self = self;
    register ActionArg *r_arg1 = (ActionArg *)arg1;

    switch (code) {
    case 0x65: {
        void *item = func_366C60(&D_4E35DC);
        if (item != 0) {
            func_3521C0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x66: {
        void *item = func_366D10(&D_4E35DC);
        if (item != 0) {
            func_35D6F0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x67: {
        void *item = func_366D70(&D_4E35DC);
        if (item != 0) {
            func_3633B0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x68: {
        void *item = func_366C80(&D_4E35DC);
        if (item != 0) {
            func_354990(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x69: {
        void *item = func_366CD0(&D_4E35DC);
        if (item != 0) {
            func_359640(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x7b: {
        void *item = func_366CF0(&D_4E35DC);
        if (item != 0) {
            func_35CA30(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x6b: {
        void *item = func_366C50(&D_4E35DC);
        if (item != 0) {
            func_351160(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x78: {
        void *item = func_366DB0(&D_4E35DC);
        if (item != 0) {
            func_355F00: // wait, func_365F00!
            func_365F00(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x6c: {
        void *item = func_366CA0(&D_4E35DC);
        if (item != 0) {
            func_356C90(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x79: {
        void *item = func_366CB0(&D_4E35DC);
        if (item != 0) {
            func_357230(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x7a: {
        void *item = func_366CC0(&D_4E35DC);
        if (item != 0) {
            func_3574F0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x6e: {
        void *item = func_366CE0(&D_4E35DC);
        if (item != 0) {
            func_35A140(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x6a: {
        void *item = func_366D50(&D_4E35DC);
        if (item != 0) {
            func_360000(item, r_self, r_arg1->field_4, 1);
        }
        return item;
    }

    case 0x6f: {
        void *item = func_366D80(&D_4E35DC);
        if (item != 0) {
            func_363940(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0xc: {
        void *item = func_366C40(&D_4E35DC);
        if (item != 0) {
            func_3505B0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x3: {
        void *item = func_366BD0(&D_4E35DC);
        if (item != 0) {
            func_34A520(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x83: {
        void *item = func_366D30(&D_4E35DC);
        if (item != 0) {
            func_35EE30(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x84: {
        void *item = func_366D20(&D_4E35DC);
        if (item != 0) {
            func_35E4A0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x85: {
        void *item = func_366C90(&D_4E35DC);
        if (item != 0) {
            func_3566C0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x7c: {
        void *item = func_366D40(&D_4E35DC);
        if (item != 0) {
            func_35F9E0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x7d: {
        void *item = func_366D90(&D_4E35DC);
        if (item != 0) {
            func_364D70(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x86: {
        void *item = func_366DA0(&D_4E35DC);
        if (item != 0) {
            func_3656F0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x87: {
        void *item = func_366C70(&D_4E35DC);
        if (item != 0) {
            func_353650(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x95: {
        void *item = func_366D60(&D_4E35DC);
        if (item != 0) {
            func_3612E0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    case 0x88: {
        void *item = func_366D00(&D_4E35DC);
        if (item != 0) {
            func_35CEB0(item, r_self, r_arg1->field_4);
        }
        return item;
    }

    default:
        return func_138D50(r_self, (void *)r_arg1, code);
    }
}
