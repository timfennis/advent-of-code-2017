#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("./inputs/day1.txt", "r");
    char buf[4096];
    fgets(buf, 4096, fp);

    int len = -1;
    for (int i = 0; i < 4096; i++)
    {
        if (buf[i] == '\0')
        {
            len = i;
            break;
        }
        else
        {
            buf[i] -= '0';
        }
    }

    int offset = len / 2;
    int sum_1 = 0;
    int sum_2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (buf[i] == buf[(i + offset) % len])
        {
            sum_2 += buf[i];
        }
        if (buf[i] == buf[(i + 1) % len])
        {
            sum_1 += buf[i];
        }
    }

    printf("part 1 = %d\npart 2 = %d\n", sum_1, sum_2);
}
