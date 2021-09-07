#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int A = 0, n = 0; // A IS FOR NO. OF DIGITS IN PLAINTXT


    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return true;

        }
        string cipherinput = argv[1]; //

        for (int h = 0; h < 26; h++) // to check if there is no duplicate characters in the cypher text.
        {
            for (int j = h + 1; j < 26; j++)
            {
                if (cipherinput[h] == cipherinput[j])
                {
                    return true;
                }
            }

        }
        for (int k = 0; k < 26; k++)
        {
            if (cipherinput[k] < 'A' || (cipherinput[k] > 'Z' && cipherinput[k] < 'a') || cipherinput[k] > 'z') // for checking if any input is out of alphabets
            {
                return true;

            }

        }

        string plaintxt = get_string("plaintext:  "); // to get the plain text from usee
        A = strlen(plaintxt);
        char cipheroutput; // for cypher output
        printf("ciphertext: ");
        for (int j = 0 ; j < A ; j++)
        {
            if (plaintxt[j] >= 'a' && plaintxt[j] <= 'z') // if the user input is in lowercase then take the cypher text change to lower case ad print cypher text
            {

                cipheroutput = tolower(cipherinput[(int)plaintxt[j] - 97]);
                printf("%c", cipheroutput);

            }

            else if (plaintxt[j] >= 'A' && plaintxt[j] <= 'Z') // if the user input is in uppercase then take the cypher text change to upper case ad print cypher text
            {

                cipheroutput = toupper(cipherinput[(int)plaintxt[j] - 65]);
                printf("%c", cipheroutput);
            }
            else
            {
                cipheroutput = plaintxt[j]; // to print if there is any other character then alphabets and print it as same
                printf("%c", cipheroutput);
            }

        }
        printf("\n");
        return false;

    }




    else if (argc == 1)
    {
        printf("./substitution key\n");
        return true;
    }


}
