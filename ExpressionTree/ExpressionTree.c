#include "./ExpressionTree.h"
#include "../BinaryTree/BinaryTree.h"
#include "../Stack/Stack.h" // 하위 폴더의 경로에 있는 파일을 어떻게 가져오느냐(2021.2.6)
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input: 1 2 + 7 *
//수식트리 구성 => 후위표기법으로 된 수식을 트리에 저장
BTreeNode *MakeExpTree(char exp[]) {
  Stack stack;
  BTreeNode *pnode;
  BTreeNode *temp = MakeBTree();
  int expLen = strlen(exp);
  int i;
  StackInit(&stack);

  // 1. 하나의 이진트리는 만들겠지만 그 이진트리를 자식노드로 하는 부모격의
  // 이진트리를 만들지 못함
  // 2. 하나의 이진트리가 만들어졌을 때 그 pnode를 다음 StackPop에서 부모격의
  // 이진트리로 어떻게 연결시켜야 하는지
  // -> pnode가 for문이 한 번 끝나면 다시 MakeBTree()를 하는데 StackPop을 사용해
  // 이진트리를 만들어도 다시 빈(NULL) 이진트리가 만들어지는 거 아닌가?
  // 만들어졌던 완전이진트리는 사용 못하는 거 아닌가?
  // => 그렇다면 그 완전이진트리의 pnode를 다른 곳에 저장시켜둬야 한다.
  for (i = 0; i < expLen; i++) {
    // 여기에서 계속 pnode는 left, right 모두 NULL값을 가진 이진트리가 된다.

    if (isdigit(exp[i])) { // 숫자면 push
      StackPush(&stack, exp[i]);
    } else { // 문자(연산자)일 경우
      pnode = MakeBTree();
      SetData(pnode, exp[i]);

      // Q: left_node, right_node를 굳이 따로 써야하나? 하나의 node로 해결할 수
      // 있는 방법은 없을까? 먼저 pop한 값이 오른쪽으로 가야한다.
      BTreeNode *right_node = MakeBTree();
      SetData(right_node, StackPop(&stack));
      MakeRightSubNode(pnode, right_node);

      if (IsStackEmpty(&stack)) { // temp를 pnode의 부모노드로 만들어서 temp를
                                  // return 시킨다
        MakeLeftSubNode(temp, pnode);
        return pnode;
      }
      BTreeNode *left_node = MakeBTree();
      SetData(left_node, StackPop(&stack));
      MakeLeftSubNode(pnode, left_node);

      temp = pnode;
    }
  }
  return temp;
}

// 수식트리 계산
Data EvaluateExpTree(BTreeNode *bt) {
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) {
        return GetData(bt);
    }

    int op1 = EvaluateExpTree(bt->left);
    int op2 = EvaluateExpTree(bt->right);

    switch (GetData(bt)) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return 0;
}

void ShowNodeData(Data data) {
    if (0 <= data && data <= 9)
        printf("%d", data);
    else
        printf("%c", data);
}

// 중위 표기법으로 출력
void ShowInfixTypeExp(BTreeNode *bt) {
    if (bt == NULL){
        return;
    }
    if(bt->left != NULL || bt->right != NULL){
        printf("(");
    }
    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);
    if(bt->left != NULL || bt->right != NULL){
        printf(")");
    }
}
