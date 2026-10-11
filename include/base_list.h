#ifndef BASE_LIST_H
#define BASE_LIST_H

extern "C" void __vec_ctor(void*);
extern void* __vt__8BaseList;

/**
 * BaseList - Container / list base class with virtual method table.
 */
class BaseList {
public:
    void *vtable;
    int m_capacity;
    int m_count;

    BaseList(int capacity);
    void Free();
    void Reset(int val);
    void Clear();
};

#endif // BASE_LIST_H
