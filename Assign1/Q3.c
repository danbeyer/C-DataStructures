/* CS261- Assignment 1 - Q.3*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: This program sorts an array of n integers in ascending order
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

/***************************************************************
** Function: sort
** Description: Sorts an array into ascending order
** Parameters: int* number, int n
** Pre-Conditions: array and int initialized
** Post-Conditions: sorts array
*******************************************************************/
void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int i, k, temp;

     for(i = n-1; i>0; i--)
     {
         for(k = 1; k<=i; k++)
         {
             if(number[k-1]>number[k])
             {
                 temp = number[k-1];
                 number[k-1] = number[k];
                 number[k] = temp;
             }
         }
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;

    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n*sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i<n; i++)
    {
        array[i] = (rand()%99);
    }

    /*Print the contents of the array.*/
    for(i=0;i<n;i++)
    {
        printf("%d\n", array[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the contents of the array.*/
    printf("Sorted array: \n");
        for(i=0;i<n;i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
