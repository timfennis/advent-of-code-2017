#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/aoc.h"

int solve(int target)
{
    if (target == 2) return 1;
    if (target == 3) return 2;

    int side = (int)sqrt((double)target);
    return (side / 2) + abs((side / 2) - ((target - (side + 1)) % side));
}

int main(int argc, char *argv[])
{
    int target;
    if (argc == 2)
        target = atoi(argv[1]);
    else
        target = 368078;

    printf("%d\n", solve(target));
}