/* CS261- Assignment 1 - Q.4*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: This program sorts are array of students based on their scores
 * in ascending order.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/******************************************************************
** Function: sort
** Description: sorts an array of structs based on score value into ascending order
** Parameters: pointer to students, int n
** Pre-Conditions: student array and int n are initialized
** Post-Conditions: Array is sorted
************************************************************************/
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i, k;
    struct student temp;

     for(i = 1; i<n-1; i++)
     {
         for(k = 0; k<n-i; k++)
         {
             if(students[k].score>students[k+1].score)
             {
                 temp = students[k];
                 students[k] = students[k+1];
                 students[k+1] = temp;
             }
         }
     }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *s = malloc(n*sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/

     int i, a, same = 0;
     s[0].id = rand () % 10+1; //sets first student's random ID
     s[0].score = ((rand() %100)+1);

     for(i = 1; i<10; i++)
     {
        s[i].score = ((rand() %100)+1);
         while(same == 0)
         {
             s[i].id = ((rand()%10)+1);
             for(a = 0; a<i; a++)
             {
                 if(s[i].id == s[a].id)
                 {
                     same = 0;
                     break;
                 }
                 else
                 {
                     same = 1;
                 }
             }
         }
         same = 0;

     }


    /*Print the contents of the array of n students.*/
    for(i=0;i<n; i++)
    {
        printf("ID:%d ", s[i].id);
        printf("Score:%d ", s[i].score);
        printf("\n");
    }

    /*Pass this array along with n to the sort() function*/
    sort(s, n);
    /*Print the contents of the array of n students.*/
    printf("Sorted array: \n");
        for(i=0;i<n; i++)
    {
        printf("ID:%d ", s[i].id);
        printf("Score:%d ", s[i].score);
        printf("\n");
    }
    return 0;
}
