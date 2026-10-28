#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_iop_init.h"

static std::vector<std::string> g_call_order;

const char D_00492EE0[] = "ioprp23.img";
void *D_00492DE0[8] = {nullptr};
void *D_00392BF0[8] = {nullptr};
void *D_00392C50[8] = {nullptr};
void *D_00392C80[8] = {nullptr};
void *D_00C82510[8] = {nullptr};
void *D_00C92510[8] = {nullptr};

extern "C" {
int func_388710(const char *img, void *param, int a2, int a3) {
    assert(img == D_00492EE0);
    assert(param == D_00492DE0);
    assert(a2 == 2);
    assert(a3 == 1);
    g_call_order.push_back("func_388710");
    return 0;
}

int func_388690(void *tbl, int count, void *param, int a3) {
    if (tbl == D_00392BF0) {
        assert(count == 7);
        assert(param == D_00492DE0);
        assert(a3 == 2);
        g_call_order.push_back("func_388690:BF0");
    } else if (tbl == D_00392C50) {
        assert(count == 4);
        assert(param == D_00492DE0);
        assert(a3 == 2);
        g_call_order.push_back("func_388690:C50");
    } else if (tbl == D_00392C80) {
        assert(count == 3);
        assert(param == D_00492DE0);
        assert(a3 == 2);
        g_call_order.push_back("func_388690:C80");
    }
    return 0;
}

void func_111710(void) { g_call_order.push_back("func_111710"); }
void func_102828(void) { g_call_order.push_back("func_102828"); }
void func_103948(int a0) { assert(a0 == 1); g_call_order.push_back("func_103948"); }
int func_102688(int a0, int a1, int a2, int a3) {
    assert(a0 == 0);
    assert(a1 == 1);
    assert(a2 == 2);
    assert(a3 == 1);
    g_call_order.push_back("func_102688");
    return 0;
}
void func_1237E8(void) { g_call_order.push_back("func_1237E8"); }
int func_123888(int a0, int a1, void *a2, void *a3) {
    if (a0 == 0) {
        assert(a1 == 0x10000);
        assert(a2 == D_00C82510);
        assert(a3 == D_00C82510);
        g_call_order.push_back("func_123888:C8");
    } else if (a0 == 1) {
        assert(a1 == 0x800);
        assert(a2 == D_00C92510);
        assert(a3 == D_00C92510);
        g_call_order.push_back("func_123888:C9");
    }
    return 0;
}

void func_25D060(int a0) {
    g_call_order.push_back("func_25D060:" + std::to_string(a0));
}
void func_25D320(int a0, int a1) {
    g_call_order.push_back("func_25D320:" + std::to_string(a0) + ":" + std::to_string(a1));
}
void func_12D648(void) { g_call_order.push_back("func_12D648"); }
void func_1296D8(int a0, int a1) {
    assert(a0 == 0);
    assert(a1 == 1);
    g_call_order.push_back("func_1296D8");
}
void func_129FE0(int a0) { assert(a0 == 0); g_call_order.push_back("func_129FE0"); }
void func_129F68(int a0) { assert(a0 == 1); g_call_order.push_back("func_129F68"); }
void func_12A058(int a0) { assert(a0 == 0); g_call_order.push_back("func_12A058"); }
void func_12A0E8(int a0) { assert(a0 == 0); g_call_order.push_back("func_12A0E8"); }
void func_21BDE0(int a0) { assert(a0 == 0); g_call_order.push_back("func_21BDE0"); }
void func_388000(int a0, int a1) {
    assert(a0 == 0);
    assert(a1 == 0);
    g_call_order.push_back("func_388000");
}
}

static void test_case_0_reboot_and_primary_modules() {
    g_call_order.clear();
    func_00220DD0();

    assert(g_call_order.size() == 9);
    assert(g_call_order[0] == "func_388710");
    assert(g_call_order[1] == "func_388690:BF0");
    assert(g_call_order[2] == "func_111710");
    assert(g_call_order[3] == "func_102828");
    assert(g_call_order[4] == "func_103948");
    assert(g_call_order[5] == "func_102688");
    assert(g_call_order[6] == "func_1237E8");
    assert(g_call_order[7] == "func_123888:C8");
    assert(g_call_order[8] == "func_123888:C9");

    std::cout << "PASS: case 0 reboot and primary modules" << std::endl;
}

static void test_case_1_secondary_modules_and_audio() {
    g_call_order.clear();
    func_00220E90();

    assert(g_call_order.size() == 16);
    assert(g_call_order[0] == "func_388690:C50");
    assert(g_call_order[1] == "func_388690:C80");
    assert(g_call_order[2] == "func_25D060:4096");
    assert(g_call_order[3] == "func_25D320:7680:127");
    assert(g_call_order[4] == "func_25D320:7936:127");
    assert(g_call_order[5] == "func_25D320:7808:27");
    assert(g_call_order[6] == "func_25D320:8064:27");
    assert(g_call_order[7] == "func_12D648");
    assert(g_call_order[8] == "func_25D060:4107");
    assert(g_call_order[9] == "func_1296D8");
    assert(g_call_order[10] == "func_129FE0");
    assert(g_call_order[11] == "func_129F68");
    assert(g_call_order[12] == "func_12A058");
    assert(g_call_order[13] == "func_12A0E8");
    assert(g_call_order[14] == "func_21BDE0");
    assert(g_call_order[15] == "func_388000");

    std::cout << "PASS: case 1 secondary modules and audio" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_reboot_and_primary_modules();
        test_case_1_secondary_modules_and_audio();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_reboot_and_primary_modules();
        break;
    case '1':
        test_case_1_secondary_modules_and_audio();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
