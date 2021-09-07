#include <stdio.h>
#include <cs50.h>
#include <math.h>

int checkcard(int counter, long copy1); // for checking the rule
int count = 0;

int main(void)
{
    long cardnum = 0;
    cardnum = get_long("Number: ");

    for (long i = cardnum ; i > 0 ; count++)
    {
        i = i / 10; // to check the count of numbers in card
    }


    if (count == 15 || count == 16 || count == 13)
    {
        int right = checkcard(count, cardnum); // for executing the rule.

        long w = cardnum;
        for (int i = count - 2 ; i > 0 ; i--) // to check the type of card
        {
            w = w / 10;
        }

        if ((w == 34 || w == 37) && right == 0) // to check amex
        {
            printf("AMEX\n");
        }
        else if ((w == 51 || w == 52 || w == 53 || w == 54 || w == 55) && right == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            w = w / 10 ;
            if (w == 4 && right == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }


    }
    else
    {
        printf("INVALID\n");
    }
}

int checkcard(int counter, long copy1) //to check the rule.
{
    long copy = copy1;
    int  two = 0, one = 0, sum = 0;  //to check the rule
    for (int j = counter ; j > 0 ; j -= 2)
    {
        one += copy % 10;
        copy = copy / 10;
        int twocopy = copy % 10 * 2;
        if (twocopy > 9)
        {
            two += twocopy % 10;
            twocopy = twocopy / 10;
            two += twocopy % 10;
            copy = copy / 10;
        }
        else
        {
            two += copy % 10 * 2; // for storing the digit and multiplying correponding by 2
            copy = copy / 10; // for shortening the number by 1 digit.
        }

    }
    sum = one + two;

    if (sum % 10 == 0)
    {
        return sum % 10;
    }
    else
    {
        printf("EOF\n");
        return 1;
    }

}