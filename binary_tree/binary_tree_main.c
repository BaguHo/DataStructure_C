#include<stdio.h>
#include "binary_tree.h"

int main(){
    BTreeNode * nd = MakeBTree();
    //BinaryTreeMain.c:(.text+0x22): undefined reference to `MakeBTree'
    ///usr/bin/ld: BinaryTreeMain.c:(.text+0x33): undefined reference to `SetData'
    SetData(nd, 100);
    printf("%d \n", nd->data);
}