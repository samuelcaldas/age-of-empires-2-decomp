#include "kt_gs_render_239e90.h"
#include <string.h>
#include <stdint.h>

class MockLanguageManager {
public:
    virtual void M0() {}
    virtual void M1() {}
    virtual void M2() {}
    virtual void M3() {}
    virtual void M4() {}
    virtual void M5() {}
    virtual void M6() {}
    virtual void M7() {}
    virtual char *GetString(int id, char *dest, int max_len) {
        if (id == 0xFAE) {
            strncpy(dest, "MockStringFAE", max_len);
        } else if (id == 0xFAF) {
            strncpy(dest, "MockStringFAF", max_len);
        } else {
            strncpy(dest, "Unknown", max_len);
        }
        dest[max_len - 1] = '\0';
        return dest;
    }
};

static MockLanguageManager s_mock_lang;
static void *s_heap[100];
static int s_heap_idx = 0;

static uint32_t mock_alloc(unsigned int size) {
    void *p = ::operator new(size);
    if (s_heap_idx < 100) {
        s_heap[s_heap_idx++] = p;
    }
    return (uint32_t)(uintptr_t)p;
}

extern "C" {

void func_00239E90(void *self) {
    char *base = (char *)self;
    char buf1[32];
    char buf2[32];
    s_mock_lang.GetString(0xFAE, buf1, 0x1E);
    s_mock_lang.GetString(0xFAF, buf2, 0x1E);

    *(uint32_t *)(base + 0x1054) = 0;
    *(uint32_t *)(base + 0x1058) = 0;
    *(uint32_t *)(base + 0x105C) = 0;
    *(uint32_t *)(base + 0x1060) = 0;
    *(uint32_t *)(base + 0x1064) = 0;

    uint32_t p0 = mock_alloc(0xE0);
    *(uint32_t *)(base + 0x1050) = p0;
    memset((void *)(uintptr_t)p0, 0, 0xE0);

    strcpy(base + 0x156C, buf1);
    strcpy(base + 0x164C, buf1);
    strcpy(base + 0x172C, buf1);
    strcpy(base + 0x180C, buf1);

    for (int i = 0; i < 16; i++) {
        uint32_t *s1 = (uint32_t *)(base + i * 4);
        s1[0x1970 / 4] = 0;
        s1[0x18F0 / 4] = 0;
        s1[0x1930 / 4] = 0;
        s1[0x1970 / 4] = 0;
        s1[0x19B0 / 4] = 0;

        uint32_t p1 = mock_alloc(0xE0);
        ((char *)(uintptr_t)p1)[0x10] = 0;
        *(uint32_t *)(base + 0x131C + i * 4) = p1;
        memset((void *)(uintptr_t)p1, 0, 0xE0);
        strcpy((char *)(uintptr_t)p1, buf2);

        uint32_t p2 = mock_alloc(0xE0);
        *(uint32_t *)(base + 0x135C + i * 4) = p2;
        memset((void *)(uintptr_t)p2, 0, 0xE0);
        strcpy((char *)(uintptr_t)p2, buf1);

        uint32_t p3 = mock_alloc(0xE0);
        *(uint32_t *)(base + 0x139C + i * 4) = p3;
        memset((void *)(uintptr_t)p3, 0, 0xE0);
        strcpy((char *)(uintptr_t)p3, "RandomGame");

        base[0x13DC + i] = 1;
        s1[0x13EC / 4] = 0;
        s1[0x142C / 4] = 0;
        s1[0x146C / 4] = 0;
        s1[0x14AC / 4] = 0;
        s1[0x14EC / 4] = 0;
        s1[0x152C / 4] = 0;
    }
}

}
