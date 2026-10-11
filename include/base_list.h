#ifndef BASE_LIST_H
#define BASE_LIST_H

extern "C" void __vec_ctor(void*);

/**
 * BaseList - Container / list base class with virtual method table.
 */
class BaseList {
public:
    virtual void DummyVirtual();
    int m_capacity;
    int m_count;

    BaseList(int capacity);
    void Free();
    virtual void Reset(int val);
    virtual void Clear();
};

#endif // BASE_LIST_H
