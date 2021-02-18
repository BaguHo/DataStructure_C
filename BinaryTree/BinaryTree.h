#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int BTData;

typedef struct __BinaryTreeNode{
	BTData data;
	struct __BinaryTreeNode * left;
	struct __BinaryTreeNode * right;	
}BTreeNode;

BTreeNode * MakeBTree(void); 
void MakeLeftSubNode(BTreeNode * main, BTreeNode * sub);
void MakeRightSubNode(BTreeNode *main, BTreeNode *sub);

BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

typedef void (*VisitFuncPtr)(BTData data); //함수포인터 용도를 잘 모르겠음
// BTData deleteLeftBTreeNode(BTreeNode *bt);
// BTData deleteRightBTreeNode(BTreeNode *bt);

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action); //action이 int형 파라미터를 받는 다는건가?

void DeleteTree(BTreeNode * bt);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

#endif