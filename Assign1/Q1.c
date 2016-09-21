/* CS261- Assignment 1 - Q.1*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: Memory is allocated for an array, random IDs and scores
 * are generated and stored in the array, a function prints all the IDs and scores,
 * another function prints the min and max and average score of the 10 elements, and
 * a final function deallocates the allocated memory.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};
/*******************************************************************
** Function: allocate
** Description: Allocates memory for an array of structs
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory allocated and pointer returned
****************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *s = malloc(10*sizeof(struct student));

     /*return the pointer*/
     return s;
}

/**********************************************************************
** Function: generate
** Description: Generates random IDs and scores for each of the ten students and stores them int he array
** Parameters: Pointer to students
** Pre-Conditions: Students have been initialized
** Post-Conditions: Each student has stored an ID and score
*************************************************************************/
void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int i, a, same = 0;
     students[0].id = rand () % 10+1; //sets first student's random ID
     students[0].score = ((rand() %100)+1);

     for(i = 1; i<10; i++)
     {
        students[i].score = ((rand() %100)+1);
         while(same == 0)
         {
             students[i].id = ((rand()%10)+1);
             for(a = 0; a<i; a++)
             {
                 if(students[i].id == students[a].id)
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

}

/**************************************************************************
** Function: output
** Description: Prints IDs and scores for each student
** Parameters: Pointer to students
** Pre-Conditions: students and have been initialized
** Post-Conditions: IDs and scores printed to screen
**************************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for(i = 0; i<10; i++)
    {
        printf("ID: %d ", students[i].id);
        printf("Score: %d\n", students[i].score);
    }
}

/*******************************************************************************
** Function: summary
** Description: Prints min, max, and average of student scores
** Parameters: Pointer to students
** Pre-Conditions: students have been initialized
** Post-Conditions: Min, max, average scores printed to screen
**********************************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i, sum = 0;
    int min = students[0].score;
    int max = students[0].score;
    float avg;
    for(i = 0; i<10; i++)
    {
        sum += students[i].score;
    }
    avg = sum/10;

    for(i = 0; i<10; i++)
    {
        if(students[i].score<min)
        {
            min = students[i].score;
        }
    }
    for(i = 0; i<10; i++)
    {
        if(students[i].score>max)
        {
            max = students[i].score;
        }
    }

    printf("Minimum score: %d\n", min);
    printf("Maximum score: %d\n", max);
    printf("Average score: %g\n", avg);
}

/******************************************************************************************
** Function: deallocate
** Description: Deallocates memory
** Parameters: pointer to students
** Pre-Conditions: Students have been initialized
** Post-Conditions: Memory deallocated
**********************************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud)
        free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
