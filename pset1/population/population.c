#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float pop, endpop, leftl;
    int  newl, passl, years = 0;
    // Prompt for start size
    do
    {
        pop = get_float("Start size: ");
    }
    while (pop < 9);

    // TODO: Prompt for end size
    do
    {
        endpop = get_float("End size: ");
    }
    while (endpop < pop);



    // Calculate number of years until we reach threshold
    for (leftl = pop; leftl < endpop ; years++)
    {
        newl = leftl / 3;
        passl = leftl / 4;
        leftl = leftl + newl - passl;
    }

    // Print number of years
    printf("Years: %i\n", years);
}