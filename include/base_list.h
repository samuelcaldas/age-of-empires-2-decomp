#ifndef BASE_LIST_H
#define BASE_LIST_H

#define NULL 0

struct ListNode {
    void *item;
    ListNode *next;
};

extern ListNode s_node_pool[];

class ListItem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Action();
    virtual void Save(void *stream);
};

class BaseItemCreator {
public:
    virtual void v0();
    virtual void* CreateItem(void *stream, short count);
};

/**
 * BaseList - Ensemble Studios container linked list class.
 */
class BaseList {
public:
    void *vtable;
    int m_capacity;
    ListNode *m_head;

    BaseList(int capacity);
    void Reset(int val);
    void Clear();
    ListNode* AllocNode();
    void FreeNode(ListNode *node);
    void Load(void *stream);
    void Action();
    void Save(void *stream);
    void Free();
};

extern "C" void* memset(void*, int, unsigned int);
extern "C" void __vec_ctor(void*);
extern void* __vt__8BaseList;
extern "C" void func_139580(BaseList*);
extern "C" void func_226d90(void*, void*, int);
extern "C" void func_226f70(void*, void*, int);

#endif // BASE_LIST_H
