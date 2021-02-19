#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "./ExpressionTree.h"
#include "./Stack/Stack.h"// 하위 폴더의 경로에 있는 파일을 어떻게 가져오느냐(2021.2.6)
#include "../BinaryTree/BinaryTree.h"

//1 2 + 7 *
//수식트리 구성 => 후위표기법으로 된 수식을 트리에 저장
BTreeNode * MakeExpTree(char exp[]){
	Stack stack;
	BTreeNode * pnode;
	
	int expLen = strlen(exp);
	int i;
	StackInit(&stack);
	
	for(i=0; i<expLen; i++){
		pnode = MakeBTree();
		
		if(isdigit(exp[i])){
		SetData(pnode, exp[i]);
		}
		else{
			MakeLeftSubNode(pnode, StackPop(&stack));
			MakeRightSubNode(pnode, StackPop(&stack));
			SetData(pnode, exp[i]);
		}
		
		StackPush(&stack, pnode->data);
	}
	
	return StackPop(&stack);
}


//수식트리 계산
int EvaluateExpTree(BTreeNode * bt){
	
}

void ShowNodeData(Data data){
	if(0<=data && data<= 9)
		printf("%d", data);
	else
		printf("%c", data);
}

//중위 표기법으로 출력
void ShowInfixTypeExp(BTreeNode * bt){
	InorderTraverse(bt, ShowNodeData);
}
