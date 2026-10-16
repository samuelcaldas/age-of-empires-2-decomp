#ifndef TRADE_ACTION_HELPER_218350_HARNESS_H
#define TRADE_ACTION_HELPER_218350_HARNESS_H

#include <vector>

enum EventType {
    EV_FN30,
    EV_2184D0,
    EV_ABA00,
    EV_2257A0,
    EV_FN120,
    EV_ABA70,
    EV_218820,
    EV_FN34
};

struct Event {
    EventType type;
    void *receiver;
    int arg_val;
    void *param1;
    void *param2;
    void *param3;
    void *param4;
};

inline std::vector<Event> event_log;
inline int aba00_return_val = 0x9999;
inline void *mutation_target_self = nullptr;
inline void *mutated_manager_val = (void *)0xABCD;

inline void log_event(EventType type, void *receiver, int arg_val = 0, void *p1 = nullptr, void *p2 = nullptr, void *p3 = nullptr, void *p4 = nullptr) {
    event_log.push_back({type, receiver, arg_val, p1, p2, p3, p4});
}

inline void reset_mocks() {
    event_log.clear();
    aba00_return_val = 0x9999;
    mutation_target_self = nullptr;
    mutated_manager_val = (void *)0xABCD;
}

void mock_fn30(void *self, void *val);
void mock_fn120(void *self, void *a1, void *a2, void *a3, void *a4);
void mock_fn34(void *self);

#endif // TRADE_ACTION_HELPER_218350_HARNESS_H
