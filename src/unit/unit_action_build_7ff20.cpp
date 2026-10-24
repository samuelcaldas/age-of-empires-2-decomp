#pragma exceptions off
#include "unit_action_build_7ff20.h"

struct ActionManager {
    int field_0;
    int field_4;
};

struct ActionDesc {
    char padding[6];
    short code;
};

extern "C" {
    extern void *D_4E35DC;

    // Case 0x65
    void *func_366C60(void *factory);
    void func_352230(void *item, int field_4, void *desc, void *arg2);
    void func_3522E0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x68
    void *func_366C80(void *factory);
    void func_354AD0(void *item, int field_4, void *desc, void *arg2);
    void func_354B90(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x69
    void *func_366CD0(void *factory);
    void func_359670(void *item, int field_4, void *desc, void *arg2);
    void func_3596F0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x7B
    void *func_366CF0(void *factory);
    void func_35CA80(void *item, int field_4, int minus1);

    // Case 0x6B
    void *func_366C50(void *factory);
    void func_351190(void *item, int field_4, void *desc, void *arg2);
    void func_3511F0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x78
    void *func_366DB0(void *factory);
    void func_365FA0(void *item, int field_4);

    // Case 0x6C
    void *func_366CA0(void *factory);
    void func_356D10(void *item, int field_4, void *desc, void *arg2);
    void func_356D90(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x79
    void *func_366CB0(void *factory);
    void func_357260(void *item, int field_4, void *desc);

    // Case 0x7A
    void *func_366CC0(void *factory);
    void func_357540(void *item, int field_4, void *desc, void *arg2);

    // Case 0x95
    void *func_366D60(void *factory);
    void func_361370(void *item, int field_4, void *desc, void *arg2);

    // Case 0x6E
    void *func_366CE0(void *factory);
    void func_35A210(void *item, int field_4, void *desc, void *arg2);
    void func_35A2E0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x6A
    void *func_366D50(void *factory);
    void func_360080(void *item, int field_4, void *desc, void *arg2);
    void func_360110(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x6F
    void *func_366D80(void *factory);
    void func_363A00(void *item, int field_4, void *desc, void *arg2);
    void func_363AE0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x03
    void *func_366BD0(void *factory);
    void func_34A590(void *item, int field_4, void *desc, void *arg2);

    // Case 0x0C
    void *func_366C40(void *factory);
    void func_3505E0(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x83
    void *func_366D30(void *factory);
    void func_35EE90(void *item, int field_4, void *desc, float f1, float f2, float f3);

    // Case 0x84
    void *func_366D20(void *factory);
    void func_35E530(void *item, int field_4, void *desc, void *arg2);

    // Case 0x7D
    void *func_366D90(void *factory);
    void func_364E20(void *item, int field_4, void *arg2, int minus1, float f1, float f2);

    // Case 0x87
    void *func_366C70(void *factory);
    void func_353680(void *item, int field_4, void *arg2);

    // Case 0x88
    void *func_366D00(void *factory);
    void func_35CF40(void *item, int field_4, void *desc, void *arg2);

    // Fallback
    void *func_138F90(void *self, void *desc, void *arg2, float f1, float f2, float f3);
}

void *func_0027FF20(void *self, void *action_desc, void *arg2, float f1, float f2, float f3) {
    switch (((ActionDesc *)action_desc)->code) {
    case 0x65: {
        void *item = func_366C60(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_352230(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_3522E0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x68: {
        void *item = func_366C80(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_354AD0(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_354B90(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x69: {
        void *item = func_366CD0(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_359670(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_3596F0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x7b: {
        void *item = func_366CF0(&D_4E35DC);
        if (item != 0) {
            func_35CA80(item, ((ActionManager *)self)->field_4, -1);
        }
        return item;
    }

    case 0x6b: {
        void *item = func_366C50(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_351190(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_3511F0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x78: {
        void *item = func_366DB0(&D_4E35DC);
        if (item != 0) {
            func_365FA0(item, ((ActionManager *)self)->field_4);
        }
        return item;
    }

    case 0x6c: {
        void *item = func_366CA0(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_356D10(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_356D90(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x79: {
        void *item = func_366CB0(&D_4E35DC);
        if (item != 0) {
            func_357260(item, ((ActionManager *)self)->field_4, action_desc);
        }
        return item;
    }

    case 0x7a: {
        void *item = func_366CC0(&D_4E35DC);
        if (item != 0) {
            func_357540(item, ((ActionManager *)self)->field_4, action_desc, arg2);
        }
        return item;
    }

    case 0x95: {
        void *item = func_366D60(&D_4E35DC);
        if (item != 0) {
            func_361370(item, ((ActionManager *)self)->field_4, action_desc, arg2);
        }
        return item;
    }

    case 0x6e: {
        void *item = func_366CE0(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_35A210(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_35A2E0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x6a: {
        void *item = func_366D50(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_360080(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_360110(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x6f: {
        void *item = func_366D80(&D_4E35DC);
        if (arg2 != 0) {
            if (item != 0) {
                func_363A00(item, ((ActionManager *)self)->field_4, action_desc, arg2);
            }
        } else {
            if (item != 0) {
                func_363AE0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
            }
        }
        return item;
    }

    case 0x3: {
        void *item = func_366BD0(&D_4E35DC);
        if (item != 0) {
            func_34A590(item, ((ActionManager *)self)->field_4, action_desc, arg2);
        }
        return item;
    }

    case 0xc: {
        void *item = func_366C40(&D_4E35DC);
        if (item != 0) {
            func_3505E0(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
        }
        return item;
    }

    case 0x83: {
        void *item = func_366D30(&D_4E35DC);
        if (item != 0) {
            func_35EE90(item, ((ActionManager *)self)->field_4, action_desc, f1, f2, f3);
        }
        return item;
    }

    case 0x84: {
        void *item = func_366D20(&D_4E35DC);
        if (item != 0) {
            func_35E530(item, ((ActionManager *)self)->field_4, action_desc, arg2);
        }
        return item;
    }

    case 0x7d: {
        void *item = func_366D90(&D_4E35DC);
        if (item != 0) {
            func_364E20(item, ((ActionManager *)self)->field_4, arg2, -1, f1, f2);
        }
        return item;
    }

    case 0x87: {
        void *item = func_366C70(&D_4E35DC);
        if (item != 0) {
            func_353680(item, ((ActionManager *)self)->field_4, arg2);
        }
        return item;
    }

    case 0x88: {
        void *item = func_366D00(&D_4E35DC);
        if (item != 0) {
            func_35CF40(item, ((ActionManager *)self)->field_4, action_desc, arg2);
        }
        return item;
    }

    default:
        return func_138F90(self, action_desc, arg2, f1, f2, f3);
    }
}
