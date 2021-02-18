#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "../BinaryTree/BinaryTree.h"

BTreeNode *MakeExpTree(char exp[]); //수식 트리 구성
int EvaluateExpTree(BTreeNode * bt); // 수식 트리 계산

void ShowPostfixTypeExp(BTreeNode * bt);

#endif