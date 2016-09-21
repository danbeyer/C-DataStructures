/*	stack.c: Stack application. */
/* CS261- Assignment 2 - stack.c: Stack application.*/
/* Name: Daniel Beyer
 * Date: 07/05/16
 * Solution description: Using stack implementation to check whether an expression
 * has balanced parentheses, braces, and brackets.
 */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
    DynArr *stack = newDynArr(10);

    if(s == NULL) return 1;
    char c = nextChar(s);
    char top;

    while(c != '\0')
    {
        if(!isEmptyDynArr(stack))
        {
        top = topDynArr(stack);
        }
        if(c == '(' || c == '[' || c == '{')
            {
                pushDynArr(stack, c);
            }
        if(c == ')' && top == '(')
            popDynArr(stack);
        if(c == ']' && top == '[')
            popDynArr(stack);
        if(c == '}' && top == '{')
            popDynArr(stack);

        c = nextChar(s);
    }
    if(!isEmptyDynArr(stack)) {
        deleteDynArr(stack);
        return 0;
        /* stack still has opening parenthesis */
    }

    else {
        deleteDynArr(stack);
        return 1;
    }

}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

