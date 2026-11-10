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
    virtual void dummy10() {}
    virtual void dummy11() {}
    virtual void update() {
        m_updated++;
    }

    int m_updated;
    MockItem() : m_updated(0) {}
};

struct FastVector {
    MockItem **buffer;
    short count;
    short cap;
};

extern "C" void func_001EBF70(void *self_ptr);

int main() {
    MockItem item1, item2, item3;
    MockItem *items[] = {&item1, &item2, &item3};

    FastVector vec;
    vec.buffer = items;
    vec.count = 3;
    vec.cap = 4;

    func_001EBF70(&vec);

    assert(item1.m_updated == 1);
    assert(item2.m_updated == 1);
    assert(item3.m_updated == 1);

    // Test with count = 0
    vec.count = 0;
    func_001EBF70(&vec);
    assert(item1.m_updated == 1);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
