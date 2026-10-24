#pragma exceptions off
#include "unit_action_build_80680.h"

struct ListNode {
    void *item;       // offset 0
    ListNode *next;   // offset 4
};

class Action {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int GetStatus(); // slot 10 -> offset 10 * 4 + 8 = 0x30
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Cleanup();  // slot 24 -> offset 24 * 4 + 8 = 0x68
};

struct ActionManager {
    void *vtable;     // offset 0
    int field_4;      // offset 4
    ListNode *action_list_head; // offset 8
};

extern "C" {
    extern void *D_4E35DC;
    void func_366AF0(void *factory, void *item);
    void func_138B50(void *self, void *node);
}

int func_00280680(void *self) {
    register int active_count;
    register ListNode *curr = ((ActionManager *)self)->action_list_head;
    register ActionManager *mgr = (ActionManager *)self;
    active_count = 0;
    if (curr == 0) {
        return 0;
    }

    ListNode *prev = 0;

    while (curr != 0) {
        int status = ((Action *)curr->item)->GetStatus();
        unsigned char st = (unsigned char)status;
        if (st == 1 || st == 3) {
            ListNode *next = curr->next;
            if (prev == 0) {
                mgr->action_list_head = next;
            } else {
                prev->next = next;
            }
            func_366AF0(&D_4E35DC, curr->item);
            ((Action *)curr->item)->Cleanup();
            func_138B50(mgr, curr);
            curr = next;
        } else {
            prev = curr;
            curr = curr->next;
            active_count++;
        }
    }

    return active_count;
}
