#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>



int main(void)
{
    float sen = 0, ch = 1, n = 0, wor = 1;
    string txt = get_string("Text: \n");
    n = strlen(txt); // to get the lenght of whole text.
    for (int i = 0; i < n ; i++)
    {

        if (txt[i] == ' ') //For counting words by looking for spaces
        {
            wor++;
        }


        if (txt[i] == '!' || txt[i] == '?' || txt[i] == '.') //for counting sentences
        {

                sen++;
        }

    }

    ch = n - (wor + sen); // to get no. of characters
    float L = 0, S = 0;
    L = (ch / wor) * 100;
    S = (sen / wor) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8; // formula to get grade

    if (index >= 8 && index < 9)
    {
        printf("Grade 8\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}