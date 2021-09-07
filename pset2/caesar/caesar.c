#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{


    if( argc != 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

        string plain = get_string("plaintext:  ");
        printf("ciphertext: ");
        int key = atoi(argv[1]); // to convert string to
        if(key < 0)
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
        else
        {
        for(int i=0 , n = strlen(plain); i < n ; i++)
        {
                if isupper(plain[i])  // to print the upper case
                {
                    printf("%c", ((plain[i]-65 + key )%26) + 65 );
                }
                else if islower(plain[i])  // to print the lower case
                {
                    printf("%c", ((plain[i]-97 + key)%26) + 97);
                }
                else
                {
                printf("%c", plain[i]);
                }
        }
        printf("\n");
        return 0;

        }
}