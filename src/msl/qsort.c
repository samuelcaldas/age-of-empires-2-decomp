#include <stddef.h>

typedef int (*cmp_fn)(const void *, const void *);

#ifdef __MWERKS__
typedef unsigned long ulong_t;
#else
typedef unsigned long long ulong_t;
#endif

static void swapfunc(char *a, char *b, size_t n, int swaptype) {
    if (swaptype <= 1) {
        ulong_t *pa = (ulong_t *)a;
        ulong_t *pb = (ulong_t *)b;
        size_t count = n / sizeof(ulong_t);
        do {
            ulong_t t = *pa;
            *pa++ = *pb;
            *pb++ = t;
        } while (--count > 0);
    } else {
        char *pa = a;
        char *pb = b;
        do {
            char t = *pa;
            *pa++ = *pb;
            *pb++ = t;
        } while (--n > 0);
    }
}

#define swap(a, b) do { \
    if (swaptype == 0) { \
        ulong_t t = *(ulong_t *)(a); \
        *(ulong_t *)(a) = *(ulong_t *)(b); \
        *(ulong_t *)(b) = t; \
    } else { \
        swapfunc(a, b, es, swaptype); \
    } \
} while (0)

#define vecswap(a, b, n) if ((n) > 0) swapfunc(a, b, n, swaptype)

static char *med3(char *a, char *b, char *c, cmp_fn cmp) {
    return cmp(a, b) < 0 ?
           (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a)) :
           (cmp(b, c) > 0 ? b : (cmp(a, c) > 0 ? c : a));
}

void qsort(void *a, size_t n, size_t es, cmp_fn cmp) {
    char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
    size_t d, r;
    int cmp_result;
    int swaptype;

loop:
    swaptype = ((char *)a - (char *)0) % sizeof(ulong_t) ||
               es % sizeof(ulong_t) ? 2 : es == sizeof(ulong_t) ? 0 : 1;
    if (n < 7) {
        for (pm = (char *)a + es; pm < (char *)a + n * es; pm += es) {
            for (pl = pm; pl > (char *)a && cmp(pl - es, pl) > 0; pl -= es) {
                swap(pl, pl - es);
            }
        }
        return;
    }
    pm = (char *)a + (n / 2) * es;
    if (n > 7) {
        pl = (char *)a;
        pn = (char *)a + (n - 1) * es;
        if (n > 40) {
            d = (n / 8) * es;
            pl = med3(pl, pl + d, pl + 2 * d, cmp);
            pm = med3(pm - d, pm, pm + d, cmp);
            pn = med3(pn - 2 * d, pn - d, pn, cmp);
        }
        pm = med3(pl, pm, pn, cmp);
    }
    swap((char *)a, pm);
    pa = pb = (char *)a + es;
    pc = pd = (char *)a + (n - 1) * es;
    for (;;) {
        while (pb <= pc && (cmp_result = cmp(pb, a)) <= 0) {
            if (cmp_result == 0) {
                swap(pa, pb);
                pa += es;
            }
            pb += es;
        }
        while (pb <= pc && (cmp_result = cmp(pc, a)) >= 0) {
            if (cmp_result == 0) {
                swap(pc, pd);
                pd -= es;
            }
            pc -= es;
        }
        if (pb > pc) break;
        swap(pb, pc);
        pb += es;
        pc -= es;
    }
    pn = (char *)a + n * es;
    r = (size_t)(pa - (char *)a) < (size_t)(pb - pa) ? (size_t)(pa - (char *)a) : (size_t)(pb - pa);
    vecswap((char *)a, pb - r, r);
    r = (size_t)(pd - pc) < (size_t)(pn - pd - es) ? (size_t)(pd - pc) : (size_t)(pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = (size_t)(pb - pa)) > es)
        qsort(a, r / es, es, cmp);
    if ((r = (size_t)(pd - pc)) > es) {
        a = pn - r;
        n = r / es;
        goto loop;
    }
}

void msl_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *)) {
    qsort(base, num, size, compar);
}
