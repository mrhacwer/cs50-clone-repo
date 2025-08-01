#include <cs50.h>
#include <stdio.h>

void ask_population();

long long population_start = 0;
long long population_end = 0;

int main(void)
{
    int years = 0;
    ask_population();
    for (long long i = population_start; i < population_end; i += (i / 3) - (i / 4))
    {
        years++;
    }
    printf("Years: %i\n", years);
}

void ask_population()
{
    string prompt_id[] = {
    "Population Starting Size: ",
    "Population Ending Size: ",
    };
    do
    {
            population_start = get_long_long("%s", prompt_id[0]);
    }
    while (population_start < 9);
    do
    {
            population_end = get_long_long("%s", prompt_id[1]);
    }
    while (population_end < population_start);
}
