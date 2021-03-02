#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef int Data;

typedef struct __BinaryTreeNode {
  Data data;
  struct __BinaryTreeNode *left;
  struct __BinaryTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTree(void);
void MakeLeftSubNode(BTreeNode *main, BTreeNode *sub);
void MakeRightSubNode(BTreeNode *main, BTreeNode *sub);

Data GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, Data data);

typedef void (*VisitFuncPtr)(Data data); //함수포인터 용도를 잘 모르겠음
// Data deleteLeftBTreeNode(BTreeNode *bt);
// Data deleteRightBTreeNode(BTreeNode *bt);

void InorderTraverse(
    BTreeNode *bt,
    VisitFuncPtr action); // action이 int형 파라미터를 받는 다는건가?

void DeleteTree(BTreeNode *bt);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

#endif