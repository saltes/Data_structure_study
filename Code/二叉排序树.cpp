/*
 *二叉排序树
 */
#include <bits/stdc++.h>
using namespace std;
typedef struct BSTNode{
    int key;
    struct BSTNode *lchird, *rchird;
} BSTNode, *BSTree;
BSTNode *BST_Search(BSTree T, int key);        // 在二叉排序树中查找关键字为key的结点
bool BST_Insert(BSTree &T, int key);           // 在二叉排序树中插入关键字为key的新结点
void Creat_BST(BSTree &T, int str[], int len); // 按照str[]中的关键字序列建立二叉排序树
void BST_Delete(BSTree &T, int key);            // 在二叉树中删除关键字为key的结点
BSTree FindMin(BSTree T);
int main(){
    return 0;
}
BSTNode *BST_Search(BSTree T, int key){
    while (T!=NULL&T->key!=key){
        if (T->key < key){
            T = T->rchird;
        }else{
            T = T->lchird;
        }
    }
    return T;
}
bool BST_Insert(BSTree &T, int key){
    if(T==NULL){
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=key;
        T->lchird=T->rchird=NULL;
        return true;
    }else{
           if(key==T->key){
                return false;
            }else if(key<T->key){
            BST_Insert(T->lchird,key);
            }else{
               BST_Insert(T->rchird,key);
           }
        }
    }
}
void Creat_BST(BSTree &T, int str[], int len){
    T=NULL;
    for(int i=0;i<len;i++){
        BST_Insert(T,str[i]);
    }
}
BSTree FindMin(BSTree T){
    BSTree P=T;
    while (P->lchird){
         P=P->lchird;
    }
    return p;
}
void BST_Delete(BSTree &T, int key){
    BSTree P;
    if(!BST){
        printf("error");
    }else{
        if(key<T->key){
            BST_Delete(T->lchird,key);
        }else if(key>T->key){
            BST_Delete(T->rchird,key);
        }else{
            if(T->lchird&&T->rchird){
                P=FindMin(T->rchird);
                T->key=P->key;
                BST_Delete(T->rchird,T->key);
            }else{
                P=T;
                if(!T->lchird){
                    T=T->rchird;
                }else if(!T->rchird){
                    T=T->lchird;
                }
                    free(P);
            }
        }
    }
}