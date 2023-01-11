#include <stdio.h>
#include <stdlib.h>
#include "lib/aoc.h"

int main()
{
    char *buf;
    FILE *fp;
    fp = fopen("./inputs/day1.txt", "r");
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);

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

    int len = -1;
    for (int i = 0;; i++)
    {
        if (buf[i] == '\0')
        {
            len = i;
            break;
        }
    }

    int offset = len / 2;
    int sum_1 = 0;
    int sum_2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (buf[i] == buf[(i + offset) % len])
        {
            sum_2 += as_digit(buf[i], 10);
        }
        if (buf[i] == buf[(i + 1) % len])
        {
            sum_1 += as_digit(buf[i], 10);
        }
    }

    free(buf);

    printf("part 1 = %d\npart 2 = %d\n", sum_1, sum_2);
    return 0;
}
