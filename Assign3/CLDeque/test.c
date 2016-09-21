#include "circularList.h"
#include <stdio.h>

int main(){
    struct CircularList* q = circularListCreate();
    circularListAddBack(q, (TYPE)1);
    circularListAddBack(q, (TYPE)2);
    circularListAddBack(q, (TYPE)3);
    circularListAddFront(q, (TYPE)4);
    circularListAddFront(q, (TYPE)5);
    circularListAddFront(q, (TYPE)6);
    circularListPrint(q);
    printf("%g\n", circularListFront(q));
    printf("%g\n", circularListBack(q));
    circularListRemoveFront(q);
    circularListRemoveBack(q);
    circularListPrint(q);
    circularListReverse(q);
    circularListPrint(q);

    return 0;
}
