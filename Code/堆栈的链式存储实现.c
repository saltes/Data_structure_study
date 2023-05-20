//堆栈的链式存储实现
#include <stdio.h>
#include <stdlib.h>
#define error -1
typedef struct SNode *Stack;
struct SNode{
    int Data;
    Stack Next;
};
Stack CreateStack();//生成空堆栈
void Push(Stack S,int item);//将元素item压入堆栈
int IsEmpty(Stack S);//判断堆栈S是否为空
int Pop(Stack S);//删除并返回栈顶元素
int main() {
    return 0;
}
Stack CreateStack(){
    Stack p;
    p=(Stack)malloc(sizeof(struct SNode));
    p->Next==NULL;
    return p;
}
void Push(Stack S,int item){
        Stack p;
        p=(Stack)malloc(sizeof(struct SNode));
        p->Data=item;
        p->Next=S->Next;
        S->Next=p;
}
int IsEmpty(Stack S){
    return (S->Next==NULL);
}
int Pop(Stack S){
    Stack p;
    int t;
    if(IsEmpty(S)){
        printf("堆栈空");
        return error;
    } else{
        p=S->Next;
        t=p->Data;
        free(p);
        return t;
    }
}