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
    unsigned int func_2261C0();
    extern const char D_004D1F18[];
    extern const char D_004D1F10[];
}

int func_00338CE0(void *directplay, const void *session, int flags) {
    unsigned char *object = static_cast<unsigned char *>(directplay);
    const unsigned char *input = static_cast<const unsigned char *>(session);
    int result = 0;
    if ((flags & 2) != 0) {
        int one = 1;
        func_117af8(object + 1092, input + 48, 80);
        func_11b170(object + 1172, *reinterpret_cast<const void * const *>(input + 48), 128);
        object[1299] = 0;
        *reinterpret_cast<unsigned char **>(object + 1140) = object + 1172;
        *reinterpret_cast<int *>(object + 1144) = 0;
        *reinterpret_cast<int *>(object + 1308) = one;
        return 0;
    }
    if ((flags & 1) == 0) return 0;
    *reinterpret_cast<int *>(object + 1312) = 0;
    if (D_004E352C != 1) {
        result = static_cast<int>(0x8877000A);
        return result;
    }
    unsigned char *request = object + 3388;
    D_0108AFA0[0] = 0;
    *reinterpret_cast<int *>(request) = 0;
    *reinterpret_cast<int *>(request + 4) = 0;
    *reinterpret_cast<int *>(request + 8) = 0;
    *reinterpret_cast<int *>(request + 12) = 0;
    func_11abbc(reinterpret_cast<char *>(request + 16), D_004D1F18);
    func_337840(request, 24);
    unsigned int start = func_2261C0();
    while (1) {
        func_103358(0);
        unsigned int now = func_2261C0();
        if (now - start > 5000) {
            result = static_cast<int>(0x8877000A);
            break;
        }
        if (func_11acd0(reinterpret_cast<const char *>(D_0108AFA0)) != 0) break;
    }
    if (result != 0) return result;
    unsigned char reply[512];
    func_117af8(reply, D_0108AFA0, 512);
    func_117af8(object + 1092, reply + 8, 216);
    *reinterpret_cast<unsigned char **>(object + 1140) = object + 1172;
    float *session_fields = reinterpret_cast<float *>(object + 1116);
    float *player_fields = reinterpret_cast<float *>(object + 1100);
    session_fields[0] = D_00492C60[0];
    session_fields[1] = D_00492C60[1];
    session_fields[2] = D_00492C60[2];
    session_fields[3] = D_00492C60[3];
    player_fields[0] = D_00492C60[0];
    player_fields[1] = D_00492C60[1];
    player_fields[2] = D_00492C60[2];
    player_fields[3] = D_00492C60[3];
    func_11abbc(reinterpret_cast<char *>(request + 16), D_004D1F10);
    D_0108AFA0[0] = 0;
    func_337840(request, 24);
    start = func_2261C0();
    while (1) {
        func_103358(0);
        unsigned int now = func_2261C0();
        if (now - start > 5000) {
            result = static_cast<int>(0x8877000A);
            break;
        }
        if (func_11acd0(reinterpret_cast<const char *>(D_0108AFA0)) != 0) break;
    }
    if (result != 0) return result;
    func_117af8(reply, D_0108AFA0, 512);
    for (int index = 0; index < 8; ++index) {
        unsigned char *slot = object + 4 + index * 136;
        unsigned char *source = reply + 8 + index * 112;
        if (index < 4) func_117af8(slot, source, 112);
        else func_117cac(slot, 0, 112);
        *reinterpret_cast<void **>(slot + 16) = slot + 24;
        *reinterpret_cast<void **>(slot + 20) = slot + 40;
    }
    *reinterpret_cast<int *>(object + 1308) = 1;
    return result;
}
