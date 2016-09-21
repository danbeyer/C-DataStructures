/* CS261- Assignment 1 - Q.2*/
/* Name: Daniel Beyer
 * Date: 06/28/16
 * Solution description: Ints x,y, and z are declared in main() then passed
 * as arguments to foo(). Foo changes their values then returns the new values
 * to be printed to the screen.
 */

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
** Function: foo
** Description: Sets value of a to twice original value, sets value of b to half
** its original value, sets value of c to a+b.
** Parameters: int* a, int* b, int c
** Pre-Conditions: int a, b, c are initialized and defined
** Post-Conditions: int c is returned
************************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b/2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int a = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("Value from foo: %d\n", a);
    /*Print the values of x, y and z again*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    /*Is the return value different than the value of z?  Why?*/
    /* Yes the return value is different.  z is passed by value instead of by reference,
    so any changes made inside foo() do not carry over outside of that function. Because
    z was not passed by reference, foo() does not have access to its location in memory and so
    therefore cannot make any changes to its value.  c is given the value of z but it is a separate
    variable.  Therefore z remains the same when it called at the end of the program as it was at the
    beginning. */

    return 0;
}


