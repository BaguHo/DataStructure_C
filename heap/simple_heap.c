#include<stdio.h>

#include "simple_heap.h"

HeapData PeekData(Heap * ph){
    if(ph->numOfData == 0){
        return 0;
    }

    return ph->heapArr[1].data;
}

void HeapInit(Heap * ph){
    ph->numOfData = 0;
}

int HeapIsEmpty(Heap * ph){
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FLASE;
}

void HeapInsert(Heap * ph, HeapData data){
    ph->heapArr[ph->numOfData].data = data;
    ph->heapArr[ph->numOfData].pr = data;
}

HeapData HeapDelete(Heap * ph){
    if(ph->numOfData == 0){
        return 0;
    }

    HeapData temp = ph->heapArr[1].data;
    
    for(int i=1; i != ph->numOfData; i++){
        ph->heapArr[i] = ph->heapArr[i + 1];
    }
    // numOfData를 초기화 하는 부분이 마음에 안듦. 이렇게 하면 예외 상황이 생길 거 같음.
    ph->heapArr[ph->numOfData].data = 0;
    ph->heapArr[ph->numOfData].data = 0;
    ph->numOfData -= 1;

    return temp;
}