#include "longvec.h"

struct Vector *lv_new()
{
    struct Vector *vec = malloc(sizeof(struct Vector));
    vec->cur_size = 0;
    vec->max_size = 10;
    vec->start = (long *)malloc(sizeof(long) * 10);

    return vec;
}

long lv_push(struct Vector *vec, long elem)
{
    // If the vector is full double it's size
    if (vec->cur_size == vec->max_size)
    {
        long *new_start = (long *)malloc(sizeof(long) * (vec->max_size * 2));
        for (long i = 0; i < vec->cur_size; i++)
        {
            new_start[i] = vec->start[i];
        }
        free(vec->start);
        vec->start = new_start;
        vec->max_size = (vec->max_size * 2);
    }

    // Add the element
    vec->start[vec->cur_size++] = elem;

    return vec->cur_size;
}

long lv_pop(struct Vector *vec)
{
    vec->cur_size--;

    return lv_peek(vec);
}

long lv_peek(struct Vector *vec)
{
    return vec->start[vec->cur_size - 1];
}

long lv_remove_idx(struct Vector *vec, long idx)
{
    if (idx > vec->cur_size)
    {
        return -1;
    }

    // copy all elements following the current one, one step ahead
    for (long i = idx; i < (vec->cur_size - 1); i++)
    {
        vec->start[i] = vec->start[i + 1];
    }

    return vec->cur_size--;
}

void lv_dbg(struct Vector *vec)
{
    printf("Vec(size=%ld, max_size=%ld, elements=[", vec->cur_size, vec->max_size);
    for (long i = 0; i < vec->cur_size; i++)
    {
        printf("%ld", vec->start[i]);
        if (i < vec->cur_size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

long long lv_sum(struct Vector *vec)
{
    long long sum = 0;
    for (int i = 0; i < vec->cur_size; i++)
    {
        sum += vec->start[i];
    }

    return sum;
}