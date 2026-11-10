
#include <cassert>
#include <cstring>
#include <iostream>

class TargetObj {
public:
    virtual void vfn0() {}
    virtual void vfn1() {}
    virtual void vfn2() {}
    virtual void vfn3() {}
    virtual void vfn4() {}
    virtual void vfn5() {}
    virtual void vfn6() {}
    virtual void vfn7() {}
    virtual void vfn8() {}
    virtual void vfn9() {}
    virtual void vfn10() {}
    virtual void vfn11() {}
    virtual void vfn12() {}
    virtual void vfn13() {}
    virtual void vfn14() {}
    virtual void vfn15() {}
    virtual void vfn16() {}
    virtual void vfn17() {}
    virtual void vfn18() {}
    virtual void vfn19() {}
    virtual void vfn20() {}
    virtual void vfn21() {}
    virtual void vfn22() {}
    virtual void vfn23() {}
    virtual void vfn24() {}
    virtual void vfn25() {}
    virtual void vfn26() {}
    virtual void vfn27() {}
    virtual void vfn28() {}
    virtual void vfn29() {}
    virtual void vfn30() {}
    virtual void vfn31() {}
    virtual void vfn32() {}
    virtual void vfn33() {}
    virtual void vfn34() {}
    virtual void vfn35() {}
    virtual void vfn36() {}
    virtual void vfn37() {}
    virtual void vfn38() {}
    virtual void vfn39() {}
    virtual void vfn40() {}
    virtual void vfn41() {}
    virtual void vfn42() {}
    virtual void vfn43() {}
    virtual void vfn44() {}
    virtual void vfn45() {}
    virtual void vfn46() {}
    virtual void vfn47() {}
    virtual void vfn48() {}
    virtual void vfn49() {}
    virtual void vfn50() {}
    virtual void vfn51() {}
    virtual void vfn52() {}
    virtual void vfn53() {}
    virtual void vfn54() {}
    virtual void vfn55() {}
    virtual void vfn56() {}
    virtual void vfn57() {}
    virtual void vfn58() {}
    virtual void vfn59() {}
    virtual void vfn60() {}
    virtual void vfn61() {}
    virtual void vfn62() {}
    virtual void vfn63() {}
    virtual void vfn64() {}
    virtual void vfn65() {}
    virtual void vfn66() {}
    virtual void vfn67() {}
    virtual void vfn68() {}
    virtual void vfn69() {}
    virtual void vfn70() {}
    virtual void vfn71() {}
    virtual void vfn72() {}
    virtual void vfn73() {}
    virtual void vfn74() {}
    virtual void vfn75() {}
    virtual void vfn76() {}
    virtual void vfn77() {}
    virtual void vfn78() {}
    virtual void vfn79() {}
    virtual void vfn80() {}
    virtual void vfn81() {}
    virtual void vfn82() {}
    virtual void vfn83() {}
    virtual void vfn84() {}
    virtual void vfn85() {}
    virtual void vfn86() {}
    virtual void vfn87() {}
    virtual void vfn88() {}
    virtual void vfn89() {}
    virtual void vfn90() {}
    virtual void vfn91() {}
    virtual void vfn92() {}
    virtual void vfn93() {}
    virtual void vfn94() {}
    virtual int Method17C(float x, float y, float z, int a4, int a5) { return 1; }

    char pad_04[0x04];
    short m_action;        // 0x08
    char pad_0A[0x16];
    short m_timer_id;      // 0x20
    char pad_22[0x22];
    float pos_x;           // 0x44
    float pos_y;           // 0x48
    float pos_z;           // 0x4C
    char pad_50[0x10];
    void *m_world;         // 0x60
};

class TradeAction {
public:
    virtual void vfn0() {}
    virtual void vfn1() {}
    virtual void vfn2() {}
    virtual void vfn3() {}
    virtual void vfn4() {}
    virtual void vfn5() {}
    virtual void vfn6() {}
    virtual void vfn7() {}
    virtual void vfn8() {}
    virtual void vfn9() {}
    virtual void vfn10() {}
    virtual void vfn11() {}
    virtual void vfn12() {}
    virtual void vfn13() {}
    virtual void vfn14() {}
    virtual void vfn15() {}
    virtual void vfn16() {}
    virtual void vfn17() {}
    virtual void vfn18() {}
    virtual void vfn19() {}
    virtual void vfn20() {}
    virtual void Method5C(int a1) { m_method5C_called++; }

    char pad_04[0x2A];
    unsigned char m_state; // 0x2E
    char pad_2F[0x09];
    TargetObj *m_target;   // 0x38
    char pad_3C[0x08];
    short m_field44;       // 0x44
    char pad_46[0x02];
    short m_field48;       // 0x48
    char pad_4A[0x10A];
    float m_target_x;      // 0x154
    float m_target_y;      // 0x158

    int m_method5C_called;
};

extern const char D_4910C0[] = "stance_0";
extern const char D_4910D0[] = "stance_1";
extern const char D_4910D8[] = "stance_2";
extern const char D_4910E8[] = "stance_3";
extern const char D_4910F8[] = "stance_def";

extern "C" {
const char *func_0014C910(TradeAction *self, int stance) {
    switch (stance) {
    case 0:
        return D_4910C0;
    case 1:
        return D_4910D0;
    case 2:
        return D_4910D8;
    case 3:
        return D_4910E8;
    default:
        return D_4910F8;
    }
}
}

int main() {
    TradeAction action;
    memset(&action, 0, sizeof(action));
    assert(strcmp(func_0014C910(&action, 0), "stance_0") == 0);
    assert(strcmp(func_0014C910(&action, 1), "stance_1") == 0);
    assert(strcmp(func_0014C910(&action, 2), "stance_2") == 0);
    assert(strcmp(func_0014C910(&action, 3), "stance_3") == 0);
    assert(strcmp(func_0014C910(&action, -1), "stance_def") == 0);
    assert(strcmp(func_0014C910(&action, 4), "stance_def") == 0);
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
