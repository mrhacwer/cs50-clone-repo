#include <cs50.h>
#include <stdio.h>

int askheight(void);

int main(void)
{
    int h = askheight();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j + 1 < h - i)
            printf(" ");
            else
            printf("#");
        }
    printf("  ");
        for (int k = 0; k < h; k++)
        {
            if (k - 1 < i)
            printf("#");
        }
    printf("\n");
    }
}

int askheight(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}
