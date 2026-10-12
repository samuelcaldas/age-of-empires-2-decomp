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
    virtual void v8();
    virtual void v9();
    virtual bool Method10();
    virtual void Method11();
    virtual bool Method12();
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
    union {
        int m_capacity;
        void *m_field4;
    };
    ListNode *m_head;
    char pad_0c[0xbc];
    int m_fieldC8;

    BaseList(int capacity);
    void Reset(int val);
    void Clear();
    ListNode* AllocNode();
    void FreeNode(ListNode *node);
    void Load(void *stream);
    void Action();
    void Save(void *stream);
    void Free();
    void* CreateItem(void *stream, short type);
    void* CreateItem(void *obj1, float x, void *obj2, float y, float z);
    int GetFieldC8();
    int Update();
    int Update2();
};

extern "C" void* memset(void*, int, unsigned int);
extern "C" void __vec_ctor(void*);
extern void* __vt__8BaseList;
extern "C" void func_139580(BaseList*);
extern "C" void func_226d90(void*, void*, int);
extern "C" void func_226f70(void*, void*, int);

#endif // BASE_LIST_H
