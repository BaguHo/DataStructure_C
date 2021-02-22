#ifndef __STACK_H__
#define __STACK_H__

#define	TRUE	1
#define FLASE	0
//Stack 의 ADT? => StackInit(), StackPush, StackPop, GetData

typedef int Data;
typedef int Bool;

typedef struct __Node{
	Data data;
	struct __Node * prev;
}Node;

typedef struct Stack{
	Node * top;
}Stack;

void StackInit(Stack *stack);

void StackPush(Stack *stack, Data data);
Data StackPop(Stack *stack);

Data Peek(Stack *stack);

Bool IsEmpty(Stack *stack);

#endif