#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "../binary_tree/binary_tree.h"

BTreeNode *MakeExpTree(char exp[]);  //수식 트리 구성
Data EvaluateExpTree(BTreeNode *bt); // 수식 트리 계산

void ShowPostfixTypeExp(BTreeNode *bt);

#endif