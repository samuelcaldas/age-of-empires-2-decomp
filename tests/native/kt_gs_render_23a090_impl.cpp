#include "kt_gs_render_23a090.h"
#include <string.h>
#include <stdio.h>
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
static int s_mock_mode = 7;

extern "C" {

char *func_0023A090(void *self, int a1, int a2) {
    char *base = (char *)self;
    if (s_mock_mode == 7) {
        uint32_t ptr = *(uint32_t *)(base + 0x131C + a1 * 4);
        return (char *)(uintptr_t)ptr;
    }

    char buf_faf[64];
    char buf_fae[64];
    s_mock_lang.GetString(0xFAF, buf_faf, 0x32);
    s_mock_lang.GetString(0xFAE, buf_fae, 0x32);

    if (a2 == 1) {
        uint32_t ptr = *(uint32_t *)(base + 0x131C + a1 * 4);
        char *str = (char *)(uintptr_t)ptr;
        if (strcmp(str, buf_fae) == 0 && strcmp(str, buf_faf) != 0) {
            sprintf(base + 0x107C, "%s", str);
        }
    }

    return base + 0x107C;
}

}
