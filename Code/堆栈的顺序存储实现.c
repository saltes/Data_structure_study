//堆栈的顺序存储实现
#include <stdio.h>
#include <stdlib.h>
#define error -1
typedef int Position;
typedef struct SNode *Stack;
struct SNode{
    int *Data;
    Position Top;
    int MaxSize;
};
Stack CreateStack(int MaxSize);//生成空堆栈，其最大长度为MaxSize
int IsFull(Stack S);//判断堆栈S是否已满
void Push(Stack S,int item);//将元素item压入堆栈
int IsEmpty(Stack S);//判断堆栈S是否为空
int Pop(Stack S);//删除并返回栈顶元素
int main() {
    return 0;
}
Stack CreateStack(int MaxSize){
    Stack p;
    p=(Stack)malloc(sizeof(struct SNode));
    p->Data=(int*) malloc(MaxSize* sizeof(int));
    p->MaxSize=MaxSize;
    p->Top=-1;
    return p;
}
int IsFull(Stack S){
    return (S->Top+1==S->MaxSize);
}
void Push(Stack S,int item){
    if(IsFull(S)){
        return;
    } else {
        S->Data[++(S->Top)]=item;
        return;
    }
}
int IsEmpty(Stack S){
    return (S->Top==-1);
}
int Pop(Stack S){
    if(IsEmpty(S)){
        printf("堆栈空");
        return error;
    } else{
        return (S->Data[(S->Top)--]);
    }
}