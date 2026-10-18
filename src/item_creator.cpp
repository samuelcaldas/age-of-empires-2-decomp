#include "base_list.h"

extern "C" {
void func_118DE0(const char*);
void* func_366BC0(void*);
void* func_366BE0(void*);
void* func_366BF0(void*);
void* func_366C00(void*);
void* func_366C10(void*);
void* func_366C20(void*);
void* func_366C30(void*);
void func_347C80(void*, void*, int);
void func_34B730(void*, void*, int);
void func_34BC10(void*, void*, int);
void func_34E1B0(void*, void*, int);
void func_34E300(void*, void*, int);
void func_34E610(void*, void*, int);
void func_34FA10(void*, void*, int);
extern int D_4E35DC;
extern const char D_490AE0[];
}

// Dummy definition for native testing linkage of D_490AE0 string
extern "C" const char D_490AE0[] = "Tori(bird) ha Sonzai shitewa ikenai!!\n";

void* BaseList::CreateItem(void *stream, short type) {
    void *item;

    switch (type) {
    case 9:
        item = func_366BC0(&D_4E35DC);
        if (item) {
            func_347C80(item, stream, this->m_capacity);
        }
        return item;
    case 10:
        func_118DE0(D_490AE0);
        while (1) {}
    case 4:
        item = func_366BE0(&D_4E35DC);
        if (item) {
            func_34B730(item, stream, this->m_capacity);
        }
        return item;
    case 5:
        item = func_366BF0(&D_4E35DC);
        if (item) {
            func_34BC10(item, stream, this->m_capacity);
        }
        return item;
    case 8:
        item = func_366C20(&D_4E35DC);
        if (item) {
            func_34E610(item, stream, this->m_capacity);
        }
        return item;
    case 1:
        item = func_366C30(&D_4E35DC);
        if (item) {
            func_34FA10(item, stream, this->m_capacity);
        }
        return item;
    case 21:
        item = func_366C10(&D_4E35DC);
        if (item) {
            func_34E300(item, stream, this->m_capacity);
        }
        return item;
    case 13:
        item = func_366C00(&D_4E35DC);
        if (item) {
            func_34E1B0(item, stream, this->m_capacity);
        }
        return item;
    case 2:
        return 0;
    default:
        return 0;
    }
}
