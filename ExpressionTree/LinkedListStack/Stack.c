#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void StackInit(Stack * stack){
	stack->top = NULL;
}

void StackPush(Stack * stack, Data data){
	Node * nd = (Node*)malloc(sizeof(Node)); 
	//꼭 동적할당을 해줘야 하나? => 동적할당을 안하면 함수가 끝나는 순간 Stack형태의 nd가 사라진다.
	nd->data = data;

	if(stack->top == NULL){
		stack->top = nd;
        return;
    }
   	nd->prev = stack->top;
    stack->top = nd;
}
//어떻게 top을 지우지..? => temp에 top을 저장시키고 top을 지우고 top->prev를 top으로 바꿔준다.
Data StackPop(Stack * stack){
	Node * temp;
	
	if(stack->top == NULL){
		return 0;
	}
	temp = stack->top;
	stack->top->prev = stack->top;
	
	free(stack->top);
	stack->top = temp->prev;
	
	return temp->data;
}

Data Peek(Stack * stack){
	return stack->top->data;
}

Bool IsEmpty(Stack * stack){
	if(stack->top == NULL)
		return FLASE;
	else
		return TRUE;
}
