#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021B130(void *self, const int *rect1, void *target, const int *rect3, int flags_t0, void *arg5);
}

void test_case_fill_rect() {
    unsigned char self_obj[0x100];
    std::memset(self_obj, 0, sizeof(self_obj));

    char self_surface[16 * 16];
    std::memset(self_surface, 0x00, sizeof(self_surface));

    *(int *)(self_obj + 0x40) = 16; // pitch = 16
    *(char **)(self_obj + 0x54) = self_surface;

    unsigned char arg5_obj[0x100];
    std::memset(arg5_obj, 0, sizeof(arg5_obj));
    *(unsigned char *)(arg5_obj + 0x50) = 0xEE; // fill byte

    int rect1[4] = {2, 3, 6, 7}; // width = 4, height = 4

    func_0021B130(self_obj, rect1, nullptr, nullptr, 0x400, arg5_obj);

    // Verify filled region
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            unsigned char b = (unsigned char)self_surface[y * 16 + x];
            if (x >= 2 && x < 6 && y >= 3 && y < 7) {
                assert(b == 0xEE);
            } else {
                assert(b == 0x00);
            }
        }
    }
}

void test_case_transparent_blit() {
    unsigned char self_obj[0x100];
    unsigned char target_obj[0x100];
    std::memset(self_obj, 0, sizeof(self_obj));
    std::memset(target_obj, 0, sizeof(target_obj));

    char self_surf[10 * 10];
    char target_surf[10 * 10];
    std::memset(self_surf, 0x11, sizeof(self_surf)); // background 0x11
    std::memset(target_surf, 0x00, sizeof(target_surf));

    target_surf[0] = 0x77; // opaque pixel
    target_surf[1] = 0xFF; // transparent key

    *(int *)(self_obj + 0x40) = 10;
    *(char **)(self_obj + 0x54) = self_surf;

    *(int *)(target_obj + 0x40) = 10;
    *(char **)(target_obj + 0x54) = target_surf;

    unsigned char arg5_obj[0x100];
    std::memset(arg5_obj, 0, sizeof(arg5_obj));
    *(int *)(arg5_obj + 0x5C) = 0xFF; // trans key = 0xFF

    int rect1[4] = {0, 0, 2, 1};
    int rect3[4] = {0, 0, 2, 1};

    func_0021B130(self_obj, rect1, target_obj, rect3, 0x8000, arg5_obj);

    assert((unsigned char)self_surf[0] == 0x77); // written
    assert((unsigned char)self_surf[1] == 0x11); // preserved background
}

void test_case_opaque_blit() {
    unsigned char self_obj[0x100];
    unsigned char target_obj[0x100];
    std::memset(self_obj, 0, sizeof(self_obj));
    std::memset(target_obj, 0, sizeof(target_obj));

    char self_surf[8 * 8];
    char target_surf[8 * 8];
    std::memset(self_surf, 0, sizeof(self_surf));
    std::memset(target_surf, 0x42, sizeof(target_surf));

    *(int *)(self_obj + 0x40) = 8;
    *(char **)(self_obj + 0x54) = self_surf;
    *(int *)(target_obj + 0x40) = 8;
    *(char **)(target_obj + 0x54) = target_surf;

    int rect1[4] = {1, 1, 3, 3}; // 2x2
    int rect3[4] = {0, 0, 2, 2};

    func_0021B130(self_obj, rect1, target_obj, rect3, 0, nullptr);

    assert(self_surf[1 * 8 + 1] == 0x42);
    assert(self_surf[1 * 8 + 2] == 0x42);
    assert(self_surf[2 * 8 + 1] == 0x42);
    assert(self_surf[2 * 8 + 2] == 0x42);
    assert(self_surf[0] == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_fill_rect();
    else if (c == 1) test_case_transparent_blit();
    else if (c == 2) test_case_opaque_blit();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
