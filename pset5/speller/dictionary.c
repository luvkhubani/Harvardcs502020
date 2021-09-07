// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;
// Hash table
node *table[N];
int count = 0; // to keep the word count.

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int length =strlen(word);
    char copy[length+1]; // take a byte extra for NTC
    copy[length] = '\0'; // necessary to add the ntc after allocating space to it

// not converting gave errors to :) handles min length (1-char) words
//:) handles max length (45-char) words
//:) handles words with apostrophes properly
//:) spell-checking is case-insensitive

 for (int i = 0; i < length; i++) // we take the word and LC and save that into copy
    {
        copy[i] = tolower(word[i]);
    }

    int index = hash(copy);
    node *tmp;
    tmp = table[index];
    if(tmp==NULL) // if tmp points to null return
       {
           return false;
       }

       while(tmp!=NULL) // do it until the ll ends
       {
           if(strcasecmp(tmp->word,copy)==0) // check case insesnitive for word in node to our word(copy)
           {
               return true; // if found
           }

                tmp=tmp->next; // else move to next node, traverse the ll
        }

       return false; // if not found copy until end
}



// Hashes word to a number

// Hashes word to a number
//  stackoverflow
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/ this was for a prior one that I altered later to ^

unsigned int hash(const char *word)
{
   unsigned long hash = 5381;

    int c = *word;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary , "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(file , "%s" , word) != EOF) // to add nodes until the file is at end
    {

        node *n = malloc(sizeof(node));

        if(n == NULL)
        {
         free(n);
         fclose(file);
         return false;
        }
        else
        {

            strcpy(n->word , word ); // to copy the word we have taken to the temporary variable.
            n->next = NULL;

            unsigned int index = 0;
            index = hash(word); // to find the corresponding index

             n->next=table[index]; // this is done to avoid orphaning rest of the ll
               table[index]=n; // it gets inserted in beginning of ll

           count++; // increment the word count until eof
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int n = 0 ; n < N ; n++)
    {
        node *tmp1=table[n]; // initially tmp1 points to 1st node
    while(tmp1!=NULL) // until end of ll
        {
           node *tmp2 = tmp1; // tmp2 points to what tmp1 points
            tmp1 = tmp1 -> next; // tmp1 points to next node
            free(tmp2); // tmp2 frees the prior node
        }

    }
    return true;
}
