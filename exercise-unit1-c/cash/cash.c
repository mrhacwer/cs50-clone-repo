#include <cs50.h>
#include <math.h>
#include <stdio.h>

int ask_value(void);
int coin_count(int value);

int main(void)
{
    int value = ask_value();
    int coins = coin_count(value);
    printf("Coins to return: %i\n", coins);
}

int ask_value(void)
{
    float v;
    do
    {
        v = get_float("$: ") * 100;
        if (v != roundf(v))
        {
            printf("Enter an max of two decimal places.\n");
            v = -1;
        }
    }
    while (v < 0.00);
    return (int) (v);
}

int coin_count(int value)
{
    int total_value = value;
    int coins_values[] = {25, 10, 5, 1};
    int coin_id = 0;
    int max_coins = 0;
    int count_coins = 0;

    do
    {
        count_coins = 0;
        for (; total_value >= coins_values[coin_id]; total_value -= coins_values[coin_id])
        {
            // printf("%i - %i\n", float_to_int, coins_values[coin_id]);
            max_coins++;
            count_coins++;
        }
        if (coin_id >= 4)
        {
            printf("Error: coin_id out of bounds\n");
            break;
        }
        else
        {
            coin_id++;
            if (count_coins != 0)
            printf("%i¢ = %i\n", coins_values[coin_id - 1], count_coins);
        }
    }
    while (total_value > 0);

    return max_coins;
}
