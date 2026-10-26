#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "kt_sound.h"

/* Mock state for testing */
static int s_sdcd_bind_called = 0;
static int s_sdd_bind_called = 0;
static int s_last_call_rpc_client = 0;
static int s_last_call_rpc_fno = 0;
static const void *s_last_send_buf = NULL;
static int s_last_send_size = 0;
static void *s_last_recv_buf = NULL;
static int s_last_recv_size = 0;

static u8 s_mock_sdd_status = 1;
static int s_mock_status_queries_count = 0;
static int s_vsync_sync_count = 0;
static int s_dispatched_cmds[16];
static int s_dispatched_cmd_count = 0;

/* SIF RPC Mocks */
int sceSifInitRpc(int mode) {
    (void)mode;
    return 0;
}

int sceSifBindRpc(SifRpcClientData *client, int dev, int mode) {
    (void)mode;
    if (dev == KT_SOUND_SIF_SDCD_DEV) {
        s_sdcd_bind_called = 1;
        client->serve = (void *)0x1234;
        return 0;
    }
    if (dev == KT_SOUND_SIF_SDD_DEV) {
        s_sdd_bind_called = 1;
        client->serve = (void *)0x5678;
        return 0;
    }
    return -1;
}

int sceSifCallRpc(SifRpcClientData *client, int fno, int mode,
                  void *send, int send_size,
                  void *recv, int recv_size,
                  void *end_func, void *end_para) {
    (void)mode;
    (void)end_func;
    (void)end_para;
    s_last_call_rpc_fno = fno;
    s_last_send_buf = send;
    s_last_send_size = send_size;
    s_last_recv_buf = recv;
    s_last_recv_size = recv_size;

    if (fno == 3 && recv && recv_size >= 1) {
        s_mock_status_queries_count++;
        /* Transition from BUSY (1) to READY (4) on second query */
        if (s_mock_sdd_status == SDD_STATUS_BUSY && s_mock_status_queries_count >= 2) {
            *(u8 *)recv = SDD_STATUS_READY;
        } else {
            *(u8 *)recv = s_mock_sdd_status;
        }
    }
    return 0;
}

int sceGsSyncV(int mode) {
    (void)mode;
    s_vsync_sync_count++;
    return 0;
}

void test_kt_sound_init_binds_services(void) {
    s_sdcd_bind_called = 0;
    s_sdd_bind_called = 0;

    int res = func_0012D648();
    assert(res == 0);
    assert(s_sdcd_bind_called == 1);
    assert(s_sdd_bind_called == 1);
    printf("PASS: test_kt_sound_init_binds_services\n");
}

void test_kt_sound_stream_open(void) {
    s_last_call_rpc_fno = -1;
    s_last_send_size = 0;

    int res = func_0012D7E0("test_track");
    assert(res == 0);
    assert(s_last_call_rpc_fno == 0x10);
    assert(s_last_send_size == 256);
    assert(strcmp((const char *)s_last_send_buf, "test_track") == 0);
    printf("PASS: test_kt_sound_stream_open\n");
}

void test_kt_sound_status_query(void) {
    s_mock_sdd_status = SDD_STATUS_READY;
    s_mock_status_queries_count = 0;
    int status = func_0012D888();
    assert(status == SDD_STATUS_READY);
    assert(s_last_call_rpc_fno == 3);
    assert(s_last_recv_size == 1);

    s_mock_sdd_status = SDD_STATUS_BUSY;
    s_mock_status_queries_count = 0;
    status = func_0012D888();
    assert(status == SDD_STATUS_BUSY);
    printf("PASS: test_kt_sound_status_query\n");
}

void test_kt_sound_vsync_wait_loop(void) {
    s_mock_sdd_status = SDD_STATUS_BUSY;
    s_mock_status_queries_count = 0;
    s_vsync_sync_count = 0;

    /* func_00220F70 should wait until status == 4 */
    int res = func_00220F70();
    assert(res == 0);
    assert(s_mock_status_queries_count >= 2);
    assert(s_vsync_sync_count >= 2);
    printf("PASS: test_kt_sound_vsync_wait_loop\n");
}

void test_kt_sound_multi_stage_init(void) {
    s_mock_sdd_status = SDD_STATUS_READY;
    s_mock_status_queries_count = 0;
    s_vsync_sync_count = 0;

    int res = func_00220FF0();
    assert(res == 0);
    printf("PASS: test_kt_sound_multi_stage_init\n");
}

int main(void) {
    test_kt_sound_init_binds_services();
    test_kt_sound_stream_open();
    test_kt_sound_status_query();
    test_kt_sound_vsync_wait_loop();
    test_kt_sound_multi_stage_init();
    printf("All kt_sound tests passed!\n");
    return 0;
}
