#include "longvec.h"

int main()
{
    struct Vector *my_vec = lv_new();

    lv_dbg(my_vec);
    for (int i = 0; i < 15; i++)
    {
        lv_push(my_vec, i);
    }

    lv_dbg(my_vec);

    lv_remove_idx(my_vec, 4);

    lv_dbg(my_vec);

    lv_pop(my_vec);

    lv_dbg(my_vec);

    printf("sum = %lld\n", lv_sum(my_vec));

    printf("vec[0] %ld\n", lv_get(my_vec, 0));
    printf("vec[1] %ld\n", lv_get(my_vec, 1));
    printf("vec[2] %ld\n", lv_get(my_vec, 2));
    printf("vec[2] %ld\n", lv_get(my_vec, my_vec->cur_size - 1));

    printf("min %ld\n", lv_min(my_vec));
    printf("max %ld\n", lv_max(my_vec));
}
