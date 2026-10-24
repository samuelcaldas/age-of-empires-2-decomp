#include "network_session_request_338ce0.h"

extern int D_004E352C;
extern unsigned char D_0108AFA0[];
extern const float D_00492C60[];

extern "C" {
    int func_117af8(void *, const void *, int);
    int func_117cac(void *, int, int);
    char *func_11abbc(char *, const char *);
    int func_11acd0(const char *);
    int func_11b170(void *, const void *, int);
    int func_337840(const void *, int);
    int func_103358(int);
    unsigned int func_2261C0(void);
    extern const char D_004D1F18[];
    extern const char D_004D1F10[];
}

struct GUID_Copy {
    float f[4];
};

extern "C" int func_00338CE0(void *directplay, const void *session, int flags) {
    int result;
    const char *sess;
    char *request;
    char *slot;
    char *source;
    char *dp = static_cast<char *>(directplay);
    char reply[1024];
    unsigned int start;
    int index;

    sess = static_cast<const char *>(session);
    result = 0;

    if (flags & 2) {
        *reinterpret_cast<int *>(dp + 1312) = 1;
        func_117af8(dp + 1092, sess, 80);
        func_11b170(dp + 1172, *reinterpret_cast<const void * const *>(sess + 48), 128);
        dp[1299] = 0;
        *reinterpret_cast<char **>(dp + 1140) = dp + 1172;
        *reinterpret_cast<int *>(dp + 1144) = 0;
        *reinterpret_cast<int *>(dp + 1308) = 1;
        goto exit;
    }

    if (flags & 1) {
        *reinterpret_cast<int *>(dp + 1312) = 0;
        request = dp + 3388;
        slot = dp + 4;
        if (D_004E352C != 1) {
            result = static_cast<int>(0x8877000A);
            goto exit;
        }

        D_0108AFA0[0] = 0;
        *reinterpret_cast<int *>(request + 12) = 0;
        *reinterpret_cast<int *>(request) = 0;
        *reinterpret_cast<int *>(request + 4) = 0;
        *reinterpret_cast<int *>(request + 8) = 0;
        func_11abbc(request + 16, D_004D1F18);
        func_337840(request, 24);

        start = func_2261C0();
        while (func_11acd0(reinterpret_cast<const char *>(D_0108AFA0)) == 0) {
            func_103358(0);
            if (func_2261C0() - start > 5000) {
                result = static_cast<int>(0x8877000A);
                goto exit;
            }
        }

        func_117af8(reply, D_0108AFA0, 512);
        source = reply + 8;
        func_117af8(dp + 1092, source, 216);
        *reinterpret_cast<char **>(dp + 1140) = dp + 1172;

        *reinterpret_cast<GUID_Copy *>(dp + 1116) = *reinterpret_cast<const GUID_Copy *>(D_00492C60);
        *reinterpret_cast<GUID_Copy *>(dp + 1100) = *reinterpret_cast<const GUID_Copy *>(D_00492C60);
        func_11abbc(request + 16, D_004D1F10);

        D_0108AFA0[0] = 0;
        func_337840(dp + 3388, 24);

        start = func_2261C0();
        while (func_11acd0(reinterpret_cast<const char *>(D_0108AFA0)) == 0) {
            func_103358(0);
            if (func_2261C0() - start > 5000) {
                result = static_cast<int>(0x8877000A);
                goto exit;
            }
        }

        func_117af8(reply, D_0108AFA0, 512);

        for (index = 0; index < 8; ++index, slot += 136, source += 112) {
            if (index < 4) {
                func_117af8(slot, source, 112);
            } else {
                func_117cac(slot, 0, 112);
            }
            *reinterpret_cast<char **>(slot + 16) = slot + 24;
            *reinterpret_cast<char **>(slot + 20) = slot + 40;
        }

        *reinterpret_cast<int *>(dp + 1308) = 1;
    }

exit:
    return result;
}
