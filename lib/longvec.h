#ifndef __LONG_VECTOR_H__
#define __LONG_VECTOR_H__

#include <stdlib.h>
#include <stdio.h>

struct Vector
{
    long cur_size;
    long max_size;
    long *start;
};

struct Vector *lv_new();

long lv_push(struct Vector *vec, long elem);

long lv_pop(struct Vector *vec);

long lv_peek(struct Vector *vec);

long lv_remove_idx(struct Vector *vec, long idx);

void lv_dbg(struct Vector *vec);

long long lv_sum(struct Vector *vec);

#endif