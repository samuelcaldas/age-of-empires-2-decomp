#ifndef TRADE_ACTION_HELPER_2184D0_SUPPORT_H
#define TRADE_ACTION_HELPER_2184D0_SUPPORT_H

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

namespace helper_2184d0_test {

struct CallbackState {
    unsigned char *self;
    unsigned char *manager;
    int begin_return;
    bool mutate_begin;
    bool mutate_clip;
    bool mutate_handler;
    bool mutate_y;
    int begin_calls;
    int clip_calls;
    int handler_calls;
    int cleanup_calls;
    int rectangle_calls;
    int virtual_calls;
    int break_code;
    void *virtual_receiver;
    void *virtual_argument;
    std::vector<int> events;
    std::vector<int> positions_x;
    std::vector<int> positions_y;
    std::vector<void *> handler_fields;
    std::vector<void *> handler_managers;
    void *handler_manager_replacement;
    void *begin_arguments[5];
    void *clip_arguments[2];
    void *cleanup_argument;
    void *rectangle_arguments[6];
};

extern CallbackState state;
void initialize(unsigned char *object, unsigned char *manager);
void mutate_manager(unsigned char *manager, int base);
void assert_manager(const unsigned char *manager, int base);
void run_extra_case(int test_case);
void virtual_slot_3c(void *receiver, void *argument);
void virtual_slot_44(void *receiver, void *argument);

inline void store(void *address, const void *value, size_t size) {
    std::memcpy(address, value, size);
}

template <typename Value>
void set_field(unsigned char *object, size_t offset, Value value) {
    store(object + offset, &value, sizeof(value));
}

template <typename Value>
Value get_field(const unsigned char *object, size_t offset) {
    Value value;
    std::memcpy(&value, object + offset, sizeof(value));
    return value;
}

}  // namespace helper_2184d0_test

extern "C" void func_002184D0(void *self);

#endif
