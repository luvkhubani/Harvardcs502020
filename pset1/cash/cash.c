#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar=0;
    do
    {
        dollar = get_float("change owned in dollars: "); //to get the change amt in dollars
    }while(dollar<0);
    
    int q,d,n,p,t=0;
    int pen = round(dollar*100); // dollars into pennies
    
    for(q=25;pen>=q; pen-=25) //this is the code for counting quarters
    {
        
        t++;
    }
        for(d=10;pen>=d; pen-=10) //this is the code for counting demises
    {
        
        t++;
    }
        for(n=5;pen>=n; pen-=5) //this is the code for counting nickels
    {
        
        t++;
    }
        for(p=1;pen>=p; pen-=1) //this is the code for counting pennies
    {
        
        t++;
    }
    
    printf("\nno. of coins: %d \n", t ); // to print total no. of coins
}