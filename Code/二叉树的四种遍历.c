//二叉树的四种遍历
#include <stdio.h>
#include <stdlib.h>
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree right;
};
void PreorderTraversal(BinTree BT);//先序遍历
void InorderTraversal(BinTree BT);//中序遍历
void PostorderTraversal(BinTree BT);//后序遍历
void LevelorderTraversal (BinTree BT);//层序遍历
int main()
{
    return 0;
}
void PreorderTraversal(BinTree BT){
    printf("%d",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->right);
}
void InorderTraversal(BinTree BT){
    InorderTraversal(BT->Left);
    printf("%d",BT->Data);
    InorderTraversal(BT->right);
}
void PostorderTraversal(BinTree BT){
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->right);
    printf("%d",BT->Data);
}
void LevelorderTraversal (BinTree BT){
    Queue Q;
    BinTree T;
    if(!BT){
        return;
    } else{
        Q=createQueue(MaxSize);
        Add(Q,BT);
        while (!IsEmptyQ(Q)){
            T=Delete(Q);
            printf("%d",T->Data);
            if(T->Left){
                Add(Q,T->Left);
            }
            if(T->right){
                Add(Q,T->right)
            }
        }
    }
}