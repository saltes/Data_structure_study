//二叉搜索树
#include <stdio.h>
#include <stdlib.h>
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
};
Position Find(int item,BinTree T);//查找
Position FindMin(BinTree T);//找最小
Position FindMAX(BinTree T);//找最大
BinTree Insert(int item,BinTree T);//插入
BinTree Delete(int item,BinTree T);//删除
int main()
{
    return 0;
}
Position Find(int item,BinTree T){
    while (T){
        if(item>T->Data){
            T=T->Right;
        } else if(item<T->Data){
            T=T->Left;
        } else{
            return T;
        }
        return NULL;
    }
}
Position FindMin(BinTree T){
    if(T) {
        while (T->Left) {
            T = T->Left;
        }
        return T;
    }
}
Position FindMAX(BinTree T){
    if(!T){
        return NULL;
    } else if(!T->Right){
        return T;
    } else{
        FindMAX(T->Right);
    }
}
BinTree Insert(int item,BinTree T){
    if(!T){
        T=(BinTree) malloc(sizeof (struct TNode));
        T->Data=item;
        T->Left=T->Right=NULL;
    } else{
        if(item<T->Data){
            Insert(item,T->Left);
        } else if(item>T->Data){
            Insert(item,T->Right);
        } else {

        }//item已存在，开摆
    }
    return T;
}
BinTree Delete(int item,BinTree T){
    Position tmp;
    //如果是空，报错
    if(!T){
        printf("errror");
    } else{
        //如果小于根结点
        if(item<T->Data){
            Delete(item,T->Left);
            //如果大于
        } else if(item>T->Data){
            Delete(item,T->Left);
            //如果有两个子树，找右树的最小值，并赋值给T，递归删除找到右子树的最小值
        } else if(T->Left&&T->Right){
            tmp= FindMin(T->Right);
            T->Data=tmp->Data;
            T->Right= Delete(T->Data,T->Right);
        } else{
            tmp=T;
            //只有右子树或无子树
            if(!T->Left){
                T=T->Right;
                //只有左子树
            } else{
                T=T->Left;
            }
            free(tmp);
        }
    }
    return T;
}