#include <stdio.h>
#include <limits.h>
#include "lib/aoc.h"

int main()
{
    FILE *fp;
    int rows[16][16];

    if ((fp = fopen("inputs/day2.txt", "r")))
    {
        char c;
        int cur_val = 0, cur_row = 0, cur_col = 0;
        while ((c = fgetc(fp)) != -1)
        {
            switch (c)
            {
            case '\t':
                if (cur_val != 0)
                {
                    rows[cur_row][cur_col++] = cur_val;
                    cur_val = 0;
                }
                break;
            case '\n':
                if (cur_val != 0)
                {
                    rows[cur_row++][cur_col] = cur_val;
                    cur_col = 0;
                    cur_val = 0;
                }
                break;
            case '\0':
                break;
            default:
                cur_val *= 10;
                cur_val += as_digit(c, 10);
                break;
            }
        }
        int part1 = 0;
        for (int i = 0; i < 16; i++)
        {
            int low = INT_MAX, high = INT_MIN;
            for (int j = 0; j < 16; j++)
            {
                low = min(low, rows[i][j]);
                high = max(high, rows[i][j]);
            }
            part1 += (high - low);
        }

        printf("part 1 = %d\n", part1);

        int part2 = 0;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                for (int k = j + 1; k < 16; k++)
                {
                    int a = rows[i][j], b = rows[i][k];
                    if (a % b == 0)
                    {
                        part2 += a / b;
                    }
                    else if (b % a == 0)
                    {
                        part2 += b / a;
                    }
                }
            }
        }

        printf("part 2 = %d\n", part2);
    }
}
