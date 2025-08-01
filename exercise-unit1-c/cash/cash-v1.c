#include <cs50.h>
#include <stdio.h>

float ask_value(void);
int convert_to_coins(float value);

int main(void)
{
    float valuetotal = ask_value();
    int coins = convert_to_coins(valuetotal);
    printf("Return : %i\n", coins);
}

float ask_value(void)
{
    float value;
    do
    {
        value = get_float("$: ");
    }
    while (value < 0.00);
    return value;
}

int convert_to_coins(float value)
{
    float coins_values[] = {0.25, 0.10, 0.05, 0.01, 0.00};
    int coinid = 0;
    int coins = 0;
    do
    {
        for (float v = value; value >= coins_values[coinid]; value -= coins_values[coinid])
        {
            printf("$: %.2f - %.2f \n", value , coins_values[coinid]);
            coins++;
        }
        coinid++;
    }
    while (value > 0.00 && coinid < 5);
    return coins;
}

