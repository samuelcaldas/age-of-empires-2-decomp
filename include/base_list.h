#ifndef BASE_LIST_H
#define BASE_LIST_H

#ifndef NULL
#define NULL 0
#endif

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
    virtual int Action();
    virtual void Save(void *stream);
    virtual int v8();
    virtual void Method9(void *a = 0, void *b = 0, void *c = 0);
    virtual bool Method10();
    virtual void Method11();
    virtual bool Method12();
    virtual int Method13();
    virtual int Method14();
    virtual int Method15(void *other = 0, float x = 0.0f, float y = 0.0f, float z = 0.0f);
    virtual void v16();
    virtual void v17();
    virtual void Method18(int msg);
    virtual void Method19(int a, int b, int c);
    virtual void v20();
    virtual void* v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void Method26();

    int pad_04;
    void *m_field8;
    char pad_0C[36];
    int field_30;
};

struct WorldObj {
    char pad_00[57];
    unsigned char field_39;
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
    void *m_fieldCC;

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
    void AddHead(void *item);
    void AddTail(void *item);
    void DeleteHead();
    void* RemoveHead();
    void PushHead(void *item);
    int HasItems();
    int Contains(int type);
    int CallMethod13();
    int CallMethod14();
    int CallMethod15();
    void* GetHeadItem();
    void* FindItem(int type);
    int GetHeadItemField30();
    void Broadcast(int msg);
    void Broadcast4(int a, int b, int c);
    void Method7(char *out);
    void SetupSpatial(void *obj1, void *obj2, int flag, float x, float y, float z);
    void Setup(void *obj1, void *obj2, int flag);
    void Cleanup(int flag);
};

extern "C" void* memset(void*, int, unsigned int);
extern "C" void __vec_ctor(void*);
extern void* __vt__8BaseList;
extern "C" void func_139580(BaseList*);
extern "C" void func_226d90(void*, void*, int);
extern "C" void func_226f70(void*, void*, int);

#endif // BASE_LIST_H
