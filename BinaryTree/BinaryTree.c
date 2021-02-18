#include<stdio.h>
#include<stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTree(){
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
//BTreeNode => void 로 바꾸어야 하는거 아닌가? 반환하는게 없는데 굳이 BTreeNode타입으로 return 해야하나?
//MakeLeftSubNode, MakeRightSubNode, 
void MakeLeftSubNode(BTreeNode * main, BTreeNode * sub){
	if(main->left != NULL) // 순회 필요!!
		free(main->left);
	
	main->left = sub;
}
void MakeRightSubNode(BTreeNode *main, BTreeNode *sub){
	if(main->right != NULL) // 순회 필요!!
		free(main->right);
	
	main->right = sub;
}

BTData GetData(BTreeNode *bt){
	return bt->data;
}

void SetData(BTreeNode *bt, BTData data){
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt){
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt){
	return bt->right;
}

//중위 순회
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action){
	if(bt == NULL){
		return;
	}
	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void DeleteTree(BTreeNode * bt){
	if(bt == NULL)
		return;
	
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	
	printf("del tree data: %d \n", bt->data);
	free(bt);	
}