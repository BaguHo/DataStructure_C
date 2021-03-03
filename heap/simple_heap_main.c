#include<stdio.h>
#include "./simple_heap.h"

int main(){
    Heap ph;
    HeapInit(&ph);

    HeapInsert(&ph, 10);
    HeapInsert(&ph, 20);
    HeapInsert(&ph, 30);
    HeapInsert(&ph, 40);
    HeapInsert(&ph, 50);

    for(int i=0; i<5; i++){
        printf("%d \n", HeapDelete(&ph));
    }

}