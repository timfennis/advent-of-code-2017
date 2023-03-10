#include <stdio.h>
#include <stdlib.h>
#include "lib/aoc.h"

int main()
{
    char *buf;
    int size;
    FILE *fp;
    if ((fp = fopen("./inputs/day1.txt", "r")))
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) + 1; // needs 1 extra byte for \0

        if (size > 1024 * 1024 * 1024)
        {
            fprintf(stderr, "file size is kinda sus");
            fclose(fp);
            return 1;
        }
        else
        {
            fseek(fp, 0, SEEK_SET); // seek back to beginning of file
            buf = (char *)malloc(size);
            fgets(buf, size, fp);
        }
        fclose(fp);
    }
    else
    {
        fprintf(stderr, "unable to read file");
        return 1;
    }

    int len = size - 1, sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < len; i++)
    {
        int digit = as_digit(buf[i], 10);
        if (buf[i] == buf[(i + (len / 2)) % len])
        {
            sum_2 += digit;
        }
        if (buf[i] == buf[(i + 1) % len])
        {
            sum_1 += digit;
        }
    }

    free(buf);

    printf("part 1 = %d\npart 2 = %d\n", sum_1, sum_2);
    return 0;
}
