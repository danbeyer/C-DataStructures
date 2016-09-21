/****************************************************************
** Program Filename: printPrime.c
** Author: Daniel Beyer
** Date: 06/25/16
** Description: This program prints out integer prime numbers to the screen until stopped by the user
** Input: User enters any key to continue after each prime, or "q" to quit.
** Output: Integer prime numbers
******************************************************************/

#include<stdio.h>

int main()
{
int i=3, count, c;
char a = 'b';

printf("Press q to quit\n");
printf("2\n");
while (a != 'q')
{
    /* Generates the infinite loop beginning at 2*/
    for(count=2; count>0;)
    {
        for(c=2; c<=i-1; c++)
        {
            if(i%c == 0)
                break;
        }
        /* If prime number, prints to screen and user enters char to continue */
        if(c==i)
        {
            printf("%d", i);
            count++;
            a = getchar();
            if(a == 'q')
                break;
        }
        i++;
    }
}

return 0;
}
