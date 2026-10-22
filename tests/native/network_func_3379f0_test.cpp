#include <assert.h>
#include <string.h>
#include "network_func_3379f0.h"

int D_004E3568 = 0;
int D_004E356C = 0;
int D_004E352C = 0;
int D_004E3530 = 0;
int D_004E3560 = 55;
int D_004E3538 = 88;
int D_004E3534 = 99;

extern "C" {
    extern const char D_004D1EE8[] = "ilhost";
    extern const char D_004D1EF0[] = "ilconnect";
    extern const char D_004D1F00[] = "ilbroadcast";

    static int wait_sema_calls = 0;
    static int sig_sema_calls = 0;
    static int send_calls = 0;
    static int last_socket = -1;
    static char last_payload[512];
    static int send_results[8];
    static int send_result_idx = 0;

    char *func_11ABBC(char *dst, const char *src) {
        return strcpy(dst, src);
    }

    int func_104D60(int sema) {
        assert(sema == D_004E3560);
        wait_sema_calls++;
        return 0;
    }

    int func_104D40(int sema) {
        assert(sema == D_004E3560);
        sig_sema_calls++;
        return 0;
    }

    int func_388D60(int socket, const void *buf, int len, int flags) {
        assert(len == 492);
        assert(flags == 0);
        last_socket = socket;
        memcpy(last_payload, buf, 32);
        send_calls++;
        return send_results[send_result_idx++];
    }
}

static void reset_mocks(void) {
    wait_sema_calls = 0;
    sig_sema_calls = 0;
    send_calls = 0;
    last_socket = -1;
    memset(last_payload, 0, sizeof(last_payload));
    memset(send_results, 0, sizeof(send_results));
    send_result_idx = 0;
}

int main(void) {
    /* Case 1: Disabled (D_004E3568 == 0) returns 0 without incrementing D_004E356C */
    reset_mocks();
    D_004E3568 = 0;
    D_004E356C = 10;
    assert(func_003379F0() == 0);
    assert(D_004E356C == 10);
    assert(send_calls == 0);

    /* Case 2: Connected (D_004E352C == 1), host (D_004E3530 == 1), succeeds on 1st try (492) */
    reset_mocks();
    D_004E3568 = 1;
    D_004E356C = 10;
    D_004E352C = 1;
    D_004E3530 = 1;
    send_results[0] = 492;
    assert(func_003379F0() == 0);
    assert(D_004E356C == 11);
    assert(send_calls == 1);
    assert(last_socket == 88);
    assert(strcmp(last_payload, "ilhost") == 0);
    assert(wait_sema_calls == 1 && sig_sema_calls == 1);

    /* Case 3: Connected (D_004E352C == 1), client (D_004E3530 == 2), retries once then gets -1026 */
    reset_mocks();
    D_004E3568 = 1;
    D_004E352C = 1;
    D_004E3530 = 2;
    send_results[0] = -1;
    send_results[1] = -1026;
    assert(func_003379F0() == 0);
    assert(send_calls == 2);
    assert(strcmp(last_payload, "ilconnect") == 0);

    /* Case 4: Connected (D_004E352C == 1), all 6 retries fail -> returns 1 */
    reset_mocks();
    D_004E3568 = 1;
    D_004E352C = 1;
    D_004E3530 = 2;
    for (int i = 0; i < 6; ++i) send_results[i] = -5;
    assert(func_003379F0() == 1);
    assert(send_calls == 6);

    /* Case 5: Unconnected (D_004E352C == 0), broadcast (D_004E3530 == 0), sends once on D_004E3534 */
    reset_mocks();
    D_004E3568 = 1;
    D_004E352C = 0;
    D_004E3530 = 0;
    send_results[0] = 492;
    assert(func_003379F0() == 0);
    assert(send_calls == 1);
    assert(last_socket == 99);
    assert(strcmp(last_payload, "ilbroadcast") == 0);

    return 0;
}
