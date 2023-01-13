#include "aoc.h"

int as_digit(const char c, const int radix)
{
    int n = c - '0';
    if (n > radix || radix > 10)
    {
        return -1;
    }
    else
    {
        return n;
    }
}

