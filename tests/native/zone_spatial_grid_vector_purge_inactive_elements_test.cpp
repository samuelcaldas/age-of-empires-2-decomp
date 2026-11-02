#include <cassert>
#include <iostream>

class MockItem {
public:
    virtual void dummy0() {}
    virtual void dummy1() {}
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void dummy5() {}
    virtual void dummy6() {}
    virtual void dummy7() {}
    virtual void dummy8() {}
    virtual void dummy9() {}
    virtual int is_active() {
        return m_active;
    }

    int m_active;
    MockItem(int active) : m_active(active) {}
};

struct FastVector {
    MockItem **buffer;
    short count;
    short cap;
};

static int s_purged_count = 0;
static int s_callback_called = 0;

void *D_004E3108 = (void *)0x1234;

extern "C" {
void func_367470(void *elem) {
    s_purged_count++;
}

void func_00194760(void *param) {
    assert(param == (void *)0x1234);
    s_callback_called++;
}

void func_001EBFE0(void *self_ptr);
}

int main() {
    MockItem item1(1);
    MockItem item2(0);
    MockItem item3(1);
    MockItem *items[] = {&item1, &item2, &item3};

    FastVector vec;
    vec.buffer = items;
    vec.count = 3;
    vec.cap = 3;

    // Make item1 active (purged), item2 inactive, item3 active (purged)
    // Note that when item1 is purged, s0 decrements, but loop semantics in func_001EBFE0:
    // If item->is_active(), calls func_367470 and decrements s0, but does not remove it from buffer itself.
    // If not removed by test harness, it would infinite loop if item1 remains active.
    // Let's make items change state when purged in mock:
    struct MockPurgeable : public MockItem {
        MockPurgeable(int a) : MockItem(a) {}
    };

    // To prevent infinite loop in test, make is_active toggle after purge:
    struct SelfPurgingItem : public MockItem {
        SelfPurgingItem(int a) : MockItem(a) {}
        virtual int is_active() {
            if (m_active) {
                m_active = 0;
                return 1;
            }
            return 0;
        }
    };

    SelfPurgingItem p1(1), p2(0), p3(1);
    MockItem *pitems[] = {&p1, &p2, &p3};
    vec.buffer = pitems;

    func_001EBFE0(&vec);

    assert(s_purged_count == 2);
    assert(s_callback_called == 0); // Didn't reach 91 items

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
