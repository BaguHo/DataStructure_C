#include<stdio.h>
#include "stack.h"

int main(){
    Stack *nd;
    StackInit(nd);

    StackPush(nd, 200);
    StackPush(nd, 300);
    StackPush(nd, 400);
    StackPush(nd, 500);

    Stack *temp;
    StackPop(temp);
    printf("%d", temp->top->data);
    StackPop(temp);
    printf("%d", temp->top->data);
    StackPop(temp);
    printf("%d", temp->top->data);
    StackPop(temp);
    printf("%d", temp->top->data);
    
    //result => Segmentation fault(메모리 ERROR)
}