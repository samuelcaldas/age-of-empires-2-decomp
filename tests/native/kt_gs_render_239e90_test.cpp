#include <cassert>
#include <cstring>
#include <vector>
#include <stdint.h>
#include "kt_gs_render_239e90.h"

int main() {
    std::vector<char> buffer(0x2000, 0xFF);
    func_00239E90(buffer.data());

    // Check fields cleared
    assert(*(uint32_t *)(buffer.data() + 0x1054) == 0);
    assert(*(uint32_t *)(buffer.data() + 0x1058) == 0);
    assert(*(uint32_t *)(buffer.data() + 0x105C) == 0);
    assert(*(uint32_t *)(buffer.data() + 0x1060) == 0);
    assert(*(uint32_t *)(buffer.data() + 0x1064) == 0);

    // Check pointers allocated
    uint32_t p0 = *(uint32_t *)(buffer.data() + 0x1050);
    assert(p0 != 0);

    // Check copied string in field_156C
    assert(strcmp(buffer.data() + 0x156C, "MockStringFAE") == 0);
    assert(strcmp(buffer.data() + 0x164C, "MockStringFAE") == 0);
    assert(strcmp(buffer.data() + 0x172C, "MockStringFAE") == 0);
    assert(strcmp(buffer.data() + 0x180C, "MockStringFAE") == 0);

    // Check loop items
    for (int i = 0; i < 16; i++) {
        assert(buffer[0x13DC + i] == 1);
        uint32_t p1 = *(uint32_t *)(buffer.data() + 0x131C + i * 4);
        assert(p1 != 0);
        assert(strcmp((char *)(uintptr_t)p1, "MockStringFAF") == 0);

        uint32_t p2 = *(uint32_t *)(buffer.data() + 0x135C + i * 4);
        assert(p2 != 0);
        assert(strcmp((char *)(uintptr_t)p2, "MockStringFAE") == 0);

        uint32_t p3 = *(uint32_t *)(buffer.data() + 0x139C + i * 4);
        assert(p3 != 0);
        assert(strcmp((char *)(uintptr_t)p3, "RandomGame") == 0);
    }

    return 0;
}
