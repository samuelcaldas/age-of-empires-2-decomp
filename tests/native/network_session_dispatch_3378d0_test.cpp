#include <cassert>
#include <cstring>

extern "C" {
    extern const char D_004D1EE8[];
    extern const char D_004D1EF0[];
    extern const char D_004D1F00[];
    extern const char D_004D1F10[];
    extern const char D_004D1F18[];
    int func_003378D0(const char *message);
    extern int D_004E3530;
    extern int D_004E352C;
    extern char D_0108AFA0[512];
    extern char D_01087ED0[];
    int func_117a64(const char *left, const char *right, int count);
    void func_117AF8(void *destination, const void *source, int count);
    int func_003385C0(void *destination, const char *message, int value, int flags);
}

static int calls[16];
static int call_count;
static int delegated_result;
static void *delegated_destination;
static const char *delegated_message;
static int delegated_value;
static int delegated_flags;

enum { CALL_COMPARE = 1, CALL_COPY = 2, CALL_DELEGATE = 3 };

extern "C" {
    extern const char D_004D1EE8[] = "ilhost";
    extern const char D_004D1EF0[] = "ilconnect";
    extern const char D_004D1F00[] = "ilbroadcast";
    extern const char D_004D1F10[] = "JOINED";
    extern const char D_004D1F18[] = "SESSION";
    int func_117a64(const char *left, const char *right, int count) {
        calls[call_count++] = CALL_COMPARE;
        return std::strncmp(left, right, count);
    }
    void func_117AF8(void *destination, const void *source, int count) {
        calls[call_count++] = CALL_COPY;
        std::memcpy(destination, source, count);
    }
    int func_003385C0(void *destination, const char *message, int value, int flags) {
        calls[call_count++] = CALL_DELEGATE;
        delegated_destination = destination;
        delegated_message = message;
        delegated_value = value;
        delegated_flags = flags;
        return delegated_result;
    }
}

int D_004E3530;
int D_004E352C;
char D_0108AFA0[512];
char D_01087ED0[512];

static void clear_state() {
    D_004E3530 = 0;
    D_004E352C = 0;
    call_count = 0;
    std::memset(D_0108AFA0, 0, sizeof(D_0108AFA0));
}

int main() {
    char message[512];
    std::memset(message, 0x5A, sizeof(message));
    std::memcpy(message, "ilhost", 7);
    clear_state();
    assert(func_003378D0(message) == 0);
    assert(D_004E3530 == 2);
    assert(D_004E352C == 0);
    assert(call_count == 1);
    assert(calls[0] == CALL_COMPARE);

    std::memcpy(message, "JOINED", 7);
    clear_state();
    assert(func_003378D0(message) == 1);
    assert(call_count == 5);
    assert(calls[0] == CALL_COMPARE);
    assert(calls[1] == CALL_COMPARE);
    assert(calls[2] == CALL_COMPARE);
    assert(calls[3] == CALL_COMPARE);
    assert(calls[4] == CALL_COPY);
    assert(std::memcmp(D_0108AFA0, message, sizeof(message)) == 0);

    std::memcpy(message, "ilconnect", 10);
    clear_state();
    D_004E3530 = 0;
    D_004E352C = 9;
    assert(func_003378D0(message) == 0);
    assert(D_004E3530 == 0);
    assert(D_004E352C == 0);

    std::memcpy(message, "other", 6);
    message[12] = 0x34;
    message[13] = 0x12;
    message[14] = 0;
    message[15] = 0;
    clear_state();
    assert(func_003378D0(message) == 0);
    assert(call_count == 6);
    assert(calls[4] == CALL_COMPARE);
    assert(calls[5] == CALL_DELEGATE);
    assert(delegated_destination == D_01087ED0);
    assert(delegated_message == message);
    assert(delegated_value == 0x1234);
    assert(delegated_flags == 0);

    return 0;
}
