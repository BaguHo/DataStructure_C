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

/*
어떻게 top을 지우지..? => temp에 top을 저장시키고 top을 지우고 top->prev를 top으로 바꿔준다.
1. return을 stack 타입으로 한다.
2. 필요할 때마다 stack을 만들어서 StackPop의 return 값을 저장시킨다.
2번이 괜찮아 보임 => 서브노드를 만들 때마다 새로운 stack을 선언하는 것보다
아에 return 값을 stack으로 하는게 더 효율적이라고 생각
*********** 책에서는 Data타입으로 return 함*********** => 이 방법으로 해 봄
*/
Data StackPop(Stack * stack){	

	if(stack->top == NULL){
		return stack->top->data;
	}
	
    Data data_temp = stack->top->data;
    Node *node_temp = stack->top;
	stack->top = stack->top->prev;
	
	free(node_temp);
    return data_temp;

}

Data Peek(Stack * stack){
	return stack->top->data;
}

Bool IsStackEmpty(Stack * stack){
	if(stack->top == NULL)
		return FLASE;
	else
		return TRUE;
}
