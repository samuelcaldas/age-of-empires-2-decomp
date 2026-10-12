#include "sub_list.h"

void* SubList::func_0013AE00(void *other, int mode, float x, float y, float z) {
    void *s0 = this->m_field4->m_fieldC8->Method3(this, this->m_field4, other, x, y, z, mode, 0);
    if (s0) {
        return s0;
    }
    if (this->m_field4->m_fieldCE) {
        for (int i = 0; i < this->m_field8->m_count; i++) {
            NodeItem *item = this->m_field8->m_items[i];
            if (item && item->m_fieldE == this->m_field4->m_fieldE &&
                item->m_field0 == this->m_field4->m_field0 &&
                item->m_fieldCE == this->m_field4->m_fieldCE) {
                s0 = item->m_fieldC8->Method3(this, this->m_field4, other, x, y, z, -1, 0);
                if (s0) {
                    this->v26(item);
                    break;
                }
            }
        }
    }
    return s0;
}

int SubList::func_0013AF70() {
    if (!this->m_fieldCC->HasItems()) {
        return 0;
    }
    SpatialObj1 *item = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
    return item->m_fieldC;
}

float SubList::func_0013AFC0() {
    return this->m_field4->m_fieldD0;
}

int SubList::func_0013AFD0() {
    int s0 = 0;
    if (this->m_fieldCC != 0) {
        SpatialObj1 *v0 = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
        if (v0 != 0) {
            s0 = s0 + v0->m_field4;
            s0 = s0 + v0->m_fieldC;
        }
    }
    return s0;
}

int SubList::func_0013B020() {
    if (this->m_fieldCC != 0) {
        SpatialObj1 *item = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
        return item ? item->m_field4 : -1;
    }
    return -1;
}

int SubList::func_0013B070(int id) {
    if (this->m_fieldCC == 0) {
        return 0;
    }
    return this->m_fieldCC->Contains(id);
}
