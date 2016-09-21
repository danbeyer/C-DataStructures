/* CS261- Assignment 1 - Q. 0*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: In main function, int x is declared, address of x is printed,
 * address of x is passed to function void fooA. In fooA, the value of the pointer is printed,
 * the address of the pointer is printed, and the address of the pointer is printed.
 */

#include <stdio.h>
#include <stdlib.h>

/********************************************************************
** Function: fooA
** Description: Prints value of int, address of int, and address of pointer
** Parameters: int *ptr
** Pre-Conditions: Int has been initialized
** Post-Conditions: Prints value and address of int, and prints address of pointer
**********************************************************************/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("Value pointed to by *iptr: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("Address pointed to by *iptr: %p\n", iptr);

     /*Print the address of iptr itself*/
     printf("Address of iptr itself: %p\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 10;

    /*print the address of x*/
    printf("Address of x: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of x: %d\n", x);

    return 0;
}
