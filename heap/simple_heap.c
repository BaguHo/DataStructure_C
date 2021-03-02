#include<stdio.h>

#include "simple_heap.h"
void HeapInit(Heap * ph){
    ph->numOfData = 0;
}

int HeapIsEmpty(Heap * ph){
    if( ph->numOfData == 0)
        return 1;
    else
        return 0;
}

void HeapInsert(Heap * ph, HeapData data);
HeapData HeapDelete(Heap * ph);