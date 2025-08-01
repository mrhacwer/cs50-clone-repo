#include <cs50.h>
#include <stdio.h>

int askheight(void);

int main(void)
{
    int height = askheight();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i < j)
                printf(" ");
        }
        for (int k = 0; k < height; k++)
        {
            if (i + 1 > k)
                printf("#");
        }
        printf("\n");
    }
}

int askheight()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

// Faz uma pirâmide de altura especificada pelo usuário para a esquerda.

/*int askheight(void);

int main(void)
{
    int height = askheight();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (j > i)
            printf(" ");
            else
            printf("#");
        }
    printf("\n");
    }
}

int askheight()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}*/
