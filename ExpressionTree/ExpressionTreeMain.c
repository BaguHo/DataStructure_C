#include<stdio.h>
#include "ExpressionTree.h"

int main(){
    char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);
	
	printf("중위 표기법의 수식: ");
	ShowInfrxTypeExp(eTree); printf("\n");
	
	printf("연산의 결과: %d \n", EvaluatreExpTree(eTree));
	
	return 0;

}
