#include "sub_list.h"

extern "C" {
    void* func_1c2680(void *container, short index);
    void* func_1c26d0(void *container, short id);
}

NodeItem* SubList::func_0013A700(void *other, float x, float y, float z) {
    if (other == (void*)this || this->m_field4->m_fieldCE == 0) {
        return this->m_field4;
    }
    if (this->m_field4->m_fieldC8->Method3(this, this->m_field4, other, x, y, z, -1, 0)) {
        return this->m_field4;
    }
    if (this->m_field4->m_fieldCE) {
        for (int i = 0; i < this->m_field8->m_count; i++) {
            NodeItem *item = this->m_field8->m_items[i];
            if (item && item->m_fieldE == this->m_field4->m_fieldE &&
                item->m_field0 == this->m_field4->m_field0 &&
                item->m_fieldCE == this->m_field4->m_fieldCE) {
                if (item->m_fieldC8->Method3(this, item, other, x, y, z, -1, 0)) {
                    return item;
                }
            }
        }
    }
    return this->m_field4;
}

void SubList::func_0013A870(short index) {
    SpatialObj1 *item = (SpatialObj1*)func_1c2680(this->m_field4, index);
    if (!item) {
        return;
    }
    if (this->m_fieldCC->Contains(item->type)) {
        return;
    }
    void *created = this->m_fieldCC->CreateItem(item, -1.0f, 0, -1.0f, -1.0f);
    if (created) {
        this->v196(created);
    }
}

void SubList::func_0013A910(short id) {
    SpatialObj1 *item = (SpatialObj1*)func_1c26d0(this->m_field4, id);
    if (!item) {
        return;
    }
    if (this->m_fieldCC->Contains(id)) {
        return;
    }
    void *created = this->m_fieldCC->CreateItem(item, -1.0f, 0, -1.0f, -1.0f);
    if (created) {
        this->v196(created);
    }
}

void SubList::func_0013A9B0(void *item) {
    if (item) {
        this->m_fieldCC->AddHead(item);
    }
}

void SubList::func_0013A9D0(void *item) {
    this->m_fieldCC->Free();
    if (item) {
        this->m_fieldCC->AddHead(item);
    }
}

void SubList::func_0013AA20(void *item) {
    if (item) {
        this->m_fieldCC->AddTail(item);
    }
}

void SubList::func_0013AA40() {
    if (!this->m_fieldCC->CallMethod13()) {
        this->m_fieldCC->Free();
    }
}
