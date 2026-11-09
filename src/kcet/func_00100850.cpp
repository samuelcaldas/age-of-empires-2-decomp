#pragma exceptions on

typedef signed char s8;
typedef unsigned int u32;

namespace std {
    class exception {
    public:
        virtual ~exception() throw();
        virtual const char* what() const throw();
    };
    class bad_alloc : public exception {
    public:
        virtual ~bad_alloc() throw();
    };
}

typedef void (*new_handler)(void);

extern "C" {

extern new_handler D_00389B60[3];
extern s8 D_00389B64[9];

void *func_00116F40(u32 size);

void *func_00100850(u32 size) {
    if (size == 0) {
        size = 1;
    }
    void *p;
    while ((p = func_00116F40(size)) == 0) {
        if (D_00389B60[0] != 0) {
            D_00389B60[0]();
        } else if (D_00389B64[0]) {
            throw std::bad_alloc();
        } else {
            return 0;
        }
    }
    return p;
}

}
