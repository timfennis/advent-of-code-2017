#include "aoc.h"

int as_digit(char c, int radix)
{
    int n = c - '0';
    if (n > radix)
    {
        return -1;
    }
    else
    {
        return n;
    }
}