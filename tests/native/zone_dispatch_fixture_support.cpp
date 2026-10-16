#include "zone_dispatch_fixture_common.h"

std::vector<void *> g_eba_calls;
std::vector<std::string> g_seq_log;
std::vector<void *> g_de30_items;
void *g_expected_zm = nullptr;
void *g_c9fa0_self = nullptr;
int g_c9fa0_calls = 0;
int g_c9fa0_x0 = -1, g_c9fa0_y0 = -1, g_c9fa0_x1 = -1, g_c9fa0_y1 = -1;
void *g_3273e0_self = nullptr;
int g_3273e0_count = -1, g_3273e0_flag = -1;
int g_d0430_calls = 0;
int g_1387c0_calls = 0, g_1387c0_width = -1, g_1387c0_height = -1;

char D_81D120[0x111700];
char D_92E820[0x9C40];
char D_938460[0x400];
char D_938790[0x400];
void *D_6F1AF0 = reinterpret_cast<void *>(0x6F1AF0);
void *D_5E90B0 = reinterpret_cast<void *>(0x5E90B0);
void *D_6F1B50 = reinterpret_cast<void *>(0x6F1B50);
void *D_6101D0 = reinterpret_cast<void *>(0x6101D0);
void *D_4E2DF0 = reinterpret_cast<void *>(0x4E2DF0);
void *D_4E2DE8 = reinterpret_cast<void *>(0x4E2DE8);
void *D_4E2DEC = reinterpret_cast<void *>(0x4E2DEC);
void *D_4E2DF4 = reinterpret_cast<void *>(0x4E2DF4);
void *D_4E3244 = reinterpret_cast<void *>(0x4E3244);

void func_1EBA20(void *elem) {
    assert(elem != nullptr);
    g_eba_calls.push_back(elem);
}

void func_1D16D0(void *self) {
    assert(self == g_expected_zm);
    g_seq_log.push_back("1D16D0");
}

void func_25DE30(void *item, int a1) {
    assert(item != nullptr);
    assert(a1 == 1);
    g_de30_items.push_back(item);
    g_seq_log.push_back("25DE30");
}

void func_1D06A0(void *self) {
    assert(self == g_expected_zm);
    g_seq_log.push_back("1D06A0");
}

void func_001C9FA0(void *self, int a1, int a2, int a3, int a4) {
    g_c9fa0_calls++;
    g_c9fa0_self = self;
    g_c9fa0_x0 = a1; g_c9fa0_y0 = a2; g_c9fa0_x1 = a3; g_c9fa0_y1 = a4;
}

void func_335560(void *) {}
void func_335550(void *, void *) {}
void func_001387C0(void *, int width, int height) {
    g_1387c0_calls++;
    g_1387c0_width = width;
    g_1387c0_height = height;
}
void func_001389F0(void *) {}
void func_327590(void *) {}
void func_3273E0(void *self, int a1, int a2) {
    g_3273e0_self = self;
    g_3273e0_count = a1;
    g_3273e0_flag = a2;
}
void func_1ED830(void *) {}
void func_1ED150(void *) {}
void func_1ED3C0(void *, void *) {}
void func_1D0430(void *self) {
    assert(self == g_expected_zm);
    g_d0430_calls++;
}
