#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_hd.h"

/* Strings and constants needed by kt_hd.c */
const char D_4E2BF0[] = "kt_hd.c";
const char D_48F448[] = "prio > 0";
const char D_48F458[] = "start_id == id";
const char D_4E2C08[] = "name";
const char D_48F478[] = "strlen(name) < MAX_NAME_LENGTH - strlen( head[0])";
const char D_48F4B0[] = "len < KT_HD_HOSTNAME_LENGTH";
const char D_4E2C10[] = "atfile:";
const char D_4E2C18[] = ",";
const char D_4E2C20[] = "/";

static char mock_head0[64] = "host0:";
static char mock_head1[64] = "sim:";
char D_4EC1C0[64] = "";

char *D_48F468[3] = {
    mock_head0,
    mock_head1,
    D_4EC1C0
};

int D_4EA180[4] = {0, 0, 0, 0};
void *D_4EA1C0 = NULL;
int D_4EA7C0[16] = {0};
int D_4ED300[64] = {0};

/* Mock functions */
static int mock_assert_calls = 0;
void func_114320(const char *file, int line, const char *expr) {
    (void)file;
    (void)line;
    (void)expr;
    mock_assert_calls++;
}

int func_00128B18(void) { return 1; }
int func_00128B68(int *p) { (void)p; return 0; }
int func_104C10(void *p) { (void)p; return 0; }
int func_104C20(void *p1, void *p2) { (void)p1; (void)p2; return 0; }
int func_104B20(void *p) { (void)p; return 1; }
int func_104B40(int th, void *arg) { (void)arg; return th; }

int func_108D38(const char *path, int flags) { (void)path; (void)flags; return 3; }
int func_108FC0(int fd) { (void)fd; return 0; }
int func_109140(int fd, int off, int whence) { (void)fd; (void)off; (void)whence; return 100; }
int func_109378(int fd, void *buf, int n) { (void)fd; (void)buf; return n; }
int func_1095E8(int fd, void *buf, int n) { (void)fd; (void)buf; return n; }

int func_0011ACD0(const char *s) {
    return (int)strlen(s);
}

char *func_00128A20(char *s, int c) {
    return strchr(s, c);
}

int func_11AFB8(const char *s1, const char *s2, int n) {
    return strncmp(s1, s2, n);
}

static int mock_sema_val = 42;
static int mock_sema_wait(int sem) {
    return sem;
}
static int mock_sema_poll(int sem) {
    return sem;
}

int (*D_4E2C28[2])(int) = {
    mock_sema_poll,
    mock_sema_wait
};

int func_134210(int init, int max, int opt) {
    (void)init;
    (void)max;
    (void)opt;
    return mock_sema_val;
}

int func_134440(int sem) {
    return sem;
}

int func_1344C0(int sem) {
    return sem;
}

static int mock_loop_count = 0;
int func_12D990(void) {
    if (mock_loop_count > 0) {
        mock_loop_count--;
        return 1;
    }
    return 0;
}

void func_12D988(void) {}
void func_103358(int x) { (void)x; }

static int dummy_cb(void *arg) {
    return *(int *)arg * 2;
}

int main(void) {
    printf("Starting native kt_hd tests...\n");

    /* Test 1: Flag accessors */
    assert(func_00128F40(1) == 1);
    assert(func_00128F68() == 1);
    assert(func_00128F40(0) == 0);
    assert(func_00128F68() == 0);
    assert(func_00128F40(5) == 0);

    /* Test 2: Table lookup */
    {
        int table[] = {10, 100, 20, 200, 30, 300};
        assert(func_00129588(table, 3, 20) == 200);
        assert(func_00129588(table, 3, 10) == 100);
        assert(func_00129588(table, 3, 30) == 300);
        assert(func_00129588(table, 3, 999) == 0);
        assert(func_00129588(table, 0, 10) == 0);
        assert(func_00129588(table, -1, 10) == 0);
    }

    /* Test 3: Callback invocation */
    {
        int val = 21;
        assert(func_00129560(dummy_cb, &val) == 42);
        assert(func_00129560(NULL, &val) == 0);
    }

    /* Test 4: Hardware/D_4ED300 register read-and-clear */
    {
        D_4ED300[0x16] = 0x12345678;
        assert(func_00129548() == 0x12345678);
        assert(D_4ED300[0x16] == 0);
        assert(func_00129548() == 0);
    }

    /* Test 5: Semaphore lifecycle */
    {
        func_00129348();
        assert(func_00129428(1) == 1);
        assert(func_00129428(0) == 1);
        assert(func_001294C0() == 1);
        func_001294A0();
        func_001294E0();
        func_00129388();
    }

    /* Test 6: Hostname / path formatting */
    {
        func_00129248("myhost");
        assert(strcmp(D_4EC1C0, "atfile:myhost,") == 0);
        assert(func_00128F68() == 2);

        func_00129248("myhost,dir");
        assert(strcmp(D_4EC1C0, "atfile:myhost,dir/") == 0);

        func_00129248(NULL);
    }

    /* Test 7: Loop test */
    {
        mock_loop_count = 3;
        func_001294E8(0);
        assert(mock_loop_count == 0);

        mock_loop_count = 3;
        func_001294E8(1);
        assert(mock_loop_count == 2);
    }

    printf("All native kt_hd tests passed successfully.\n");
    return 0;
}
