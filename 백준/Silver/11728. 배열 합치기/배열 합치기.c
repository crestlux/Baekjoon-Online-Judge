#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#define CVECTOR_LOGARITHMIC_GROWTH
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef CVECTOR_H_
#define CVECTOR_H_
#ifndef cvector_clib_free
#define cvector_clib_free free
#endif
#ifndef cvector_clib_malloc
#define cvector_clib_malloc malloc
#endif
#ifndef cvector_clib_calloc
#define cvector_clib_calloc calloc
#endif
#ifndef cvector_clib_realloc
#define cvector_clib_realloc realloc
#endif

#define cvector_vector_type(type) type *
#define cvector_capacity(vec) \
    ((vec) ? ((size_t *)(vec))[-1] : (size_t)0)
#define cvector_size(vec) \
    ((vec) ? ((size_t *)(vec))[-2] : (size_t)0)
#define cvector_empty(vec) \
    (cvector_size(vec) == 0)
#define cvector_reserve(vec, capacity)         \
    do {                                       \
        size_t cv_cap = cvector_capacity(vec); \
        if (cv_cap < (capacity)) {             \
            cvector_grow((vec), (capacity));   \
        }                                      \
    } while (0)
#define cvector_erase(vec, i)                                                              \
    do {                                                                                   \
        if ((vec)) {                                                                       \
            const size_t cv_sz = cvector_size(vec);                                        \
            if ((i) < cv_sz) {                                                             \
                cvector_set_size((vec), cv_sz - 1);                                        \
                memmove((vec) + (i), (vec) + (i) + 1, sizeof(*(vec)) * (cv_sz - 1 - (i))); \
            }                                                                              \
        }                                                                                  \
    } while (0)
#define cvector_free(vec)                        \
    do {                                         \
        if ((vec)) {                             \
            size_t *p1 = &((size_t *)(vec))[-2]; \
            cvector_clib_free(p1);               \
        }                                        \
    } while (0)
#define cvector_begin(vec) \
    (vec)
#define cvector_end(vec) \
    ((vec) ? &((vec)[cvector_size(vec)]) : NULL)
#ifdef CVECTOR_LOGARITHMIC_GROWTH
#define cvector_compute_next_grow(size) \
    ((size) ? ((size) << 1) : 1)

#else
#define cvector_compute_next_grow(size) \
    ((size) + 1)
#endif /* CVECTOR_LOGARITHMIC_GROWTH */
#define cvector_push_back(vec, value)                               \
    do {                                                            \
        size_t cv_cap = cvector_capacity(vec);                      \
        if (cv_cap <= cvector_size(vec)) {                          \
            cvector_grow((vec), cvector_compute_next_grow(cv_cap)); \
        }                                                           \
        vec[cvector_size(vec)] = (value);                           \
        cvector_set_size((vec), cvector_size(vec) + 1);             \
    } while (0)
#define cvector_insert(vec, pos, val)                                                                      \
    do {                                                                                                   \
        if (cvector_capacity(vec) <= cvector_size(vec) + 1) {                                              \
            cvector_grow((vec), cvector_compute_next_grow(cvector_capacity((vec))));                       \
        }                                                                                                  \
        if (pos < cvector_size(vec)) {                                                                     \
            memmove((vec) + (pos) + 1, (vec) + (pos), sizeof(*(vec)) * ((cvector_size(vec) + 1) - (pos))); \
        }                                                                                                  \
        (vec)[(pos)] = (val);                                                                              \
        cvector_set_size((vec), cvector_size(vec) + 1);                                                    \
    } while (0)
#define cvector_pop_back(vec)                           \
    do {                                                \
        cvector_set_size((vec), cvector_size(vec) - 1); \
    } while (0)
#define cvector_copy(from, to)                                          \
    do {                                                                \
        if ((from)) {                                                   \
            cvector_grow(to, cvector_size(from));                       \
            cvector_set_size(to, cvector_size(from));                   \
            memcpy((to), (from), cvector_size(from) * sizeof(*(from))); \
        }                                                               \
    } while (0)
#define cvector_set_capacity(vec, size)     \
    do {                                    \
        if ((vec)) {                        \
            ((size_t *)(vec))[-1] = (size); \
        }                                   \
    } while (0)
#define cvector_set_size(vec, size)         \
    do {                                    \
        if ((vec)) {                        \
            ((size_t *)(vec))[-2] = (size); \
        }                                   \
    } while (0)
#define cvector_grow(vec, count)                                              \
    do {                                                                      \
        const size_t cv_sz = (count) * sizeof(*(vec)) + (sizeof(size_t) * 2); \
        if ((vec)) {                                                          \
            size_t *cv_p1 = &((size_t *)(vec))[-2];                           \
            size_t *cv_p2 = cvector_clib_realloc(cv_p1, (cv_sz));             \
            assert(cv_p2);                                                    \
            (vec) = (void *)(&cv_p2[2]);                                      \
            cvector_set_capacity((vec), (count));                             \
        } else {                                                              \
            size_t *cv_p = cvector_clib_malloc(cv_sz);                        \
            assert(cv_p);                                                     \
            (vec) = (void *)(&cv_p[2]);                                       \
            cvector_set_capacity((vec), (count));                             \
            cvector_set_size((vec), 0);                                       \
        }                                                                     \
    } while (0)

#endif /* CVECTOR_H_ */
int compare(const void *a, const void *b) {
    int n1 = *(int *)a, n2 = *(int *)b;
    if (n1 < n2) return -1;
    if (n1 > n2) return 1;
    return 0;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    cvector_vector_type(int) v = NULL;
    cvector_set_capacity(v, N + M);
    for (int i = 0; i < N; i++) {
        int p;
        scanf("%d", &p);
        cvector_push_back(v, p);
    }
    for (int i = 0; i < M; i++) {
        int p;
        scanf("%d", &p);
        cvector_push_back(v, p);
    }
    qsort(v, N + M, sizeof(int), compare);
    for (int i = 0; i < cvector_size(v); i++) {
        printf("%d ", v[i]);
    }
    return 0;
}