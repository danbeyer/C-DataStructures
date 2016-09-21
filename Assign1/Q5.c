/* CS261- Assignment 1 - Q.5*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: This program converts a user-generated word into sticky caps
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/***************************************************************
** Function: sticky
** Description: Converts a user provided word into sticky caps
** Parameters: char* word
** Pre-Conditions: valid word provided
** Post-Conditions: word converted to sticky caps
**********************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
     int i;
     int length = 0;
     for(i = 0; word[i] != '\0'; i++)
     {
         length++;
     }

     for(i = 0; i< length; i++)
     {
         if(i%2 ==0)
         {
             if(word[i] >= 'a' && word[i] <= 'z')
             {
                 word[i] = toUpperCase(word[i]);
             }
         }
         else
         {
             if(word[i] >= 'A' && word[i] <= 'Z')
             {
                 word[i] = toLowerCase(word[i]);
             }
         }
     }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char str[100];
    printf("Enter a word: ");
    scanf("%s", str);

    /*Call sticky*/
    sticky(str);

    /*Print the new word*/
    printf("%s\n", str);

    return 0;
}
