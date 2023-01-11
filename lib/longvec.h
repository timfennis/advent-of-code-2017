#ifndef __LONG_VECTOR_H__
#define __LONG_VECTOR_H__

#define VEC struct Vector
#include <stdlib.h>
#include <stdio.h>

struct Vector
{
    size_t cur_size;
    size_t max_size;
    long *start;
};

struct Vector *lv_new();

long lv_get(VEC *vec, size_t idx);

long lv_push(VEC *vec, long elem);

long lv_pop(VEC *vec);

long lv_peek(VEC *vec);

long lv_remove_idx(VEC *vec, size_t idx);

void lv_dbg(VEC *vec);

long long lv_sum(VEC *vec);

long lv_min(VEC *vec);

long lv_max(VEC *vec);

#endif