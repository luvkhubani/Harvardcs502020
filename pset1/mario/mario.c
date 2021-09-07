#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, a, b, c;
    int x, y, z;
    do
    {
        n = get_int("no of bricks: \n"); // no. of level of height needed

    }
    while (n < 1 || n > 8);

    for (x = 0; x < n; x++)
    {
        for (y = n - 1; y >= 0; y--)
        {
            if (y <= x)
            {
                printf("#"); // for printing first pyramid
                if (y == 0)
                {
                    printf("  ");
                    for (b = 0; b <= x; b++) // for printing second pyramid
                    {
                        printf("#");
                    }
                }

            }
            else
            {
                printf(" "); // for printing space until brick of pyramid is needed.

            }
        }
        printf("\n");
    }


}
