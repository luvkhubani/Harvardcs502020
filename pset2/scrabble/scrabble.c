#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string alph = "abcdefghijklmnopqrstuvwxyz"; // for storing the alphabets.
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    // TODO: Print the winner
}

int compute_score(string word)
{
    int sum = 0; // to have sum of scarbble game
    // TODO: Compute and return score for string
    for (int i = 0, n = strlen(word); i < n ; i++)
    {

        char copy = tolower(word[i]); // to get the character and convert it to lower as there are same points for lower and upper case.

        for (int j = 0 ; j < 26 ; j++)
        {
            if (copy == alph[j])
            {
                sum += POINTS[j];
                break;
            }
        }
    }
    return sum;
}
