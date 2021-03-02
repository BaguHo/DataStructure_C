#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

// min_heap
// heap은 머부분 배열을 기반으로 만들어진다.
#define TRUE    1
#define FLASE   0

#define HEAP_LEN    100

typedef char HeapData;
typedef int  Priority;

typedef struct _heapElem{
    Priority pr;
    HeapData data;
} HeapElem;

typedef struct _heap{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);

int HeapIsEmpty(Heap * ph);

void HeapInsert(Heap * ph, HeapData data);
HeapData HeapDelete(Heap * ph);

#endif