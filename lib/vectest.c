#include "longvec.h"

int main()
{
    struct Vector* my_vec = lv_new();

    lv_dbg(my_vec);
    for (int i = 0; i < 15; i++) 
    {
        lv_push(my_vec, i);
    }

    lv_dbg(my_vec);

    lv_remove_idx(my_vec, 4);

    lv_dbg(my_vec);

    long pop = lv_pop(my_vec);

    lv_dbg(my_vec);

    printf("sum = %lld\n", lv_sum(my_vec));
}
