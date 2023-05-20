//队列的链式存储实现
#include <stdio.h>
#include <stdlib.h>
#define error -1
typedef struct Node *position;
typedef struct Node *PtrToNodo;
struct Node{
    int Data;
    PtrToNodo Next;
};
struct QNode{
    position rear,front;
};//链队列结构
typedef struct QNode *Queue;
Queue PtrQ;
void CreatQueue(Queue Q);//生成空队列
void AddQ(Queue Q,int item);//将数据元素item插入队列Q中
int IsEmptyQ(Queue Q);//判断队列Q是否为空
int DeleteQ(Queue Q);//将队头数据元素从队列中删除并返回
int main()
{
    return 0;
}
void CreatQueue(Queue Q){
    Q->front=Q->rear=(PtrToNodo)malloc(struct Node);
    Q->front=Q->rear;
    Q->front->Next=NULL;
}
void AddQ(Queue Q,int item) {
    PtrToNodo p;
    p=(PtrToNodo) malloc(sizeof(struct Node));
    p->Data=item;
    p->Next=NULL;
    Q->rear->Next=p;
    Q->rear=p;
}
int IsEmptyQ(Queue Q){
    return (Q->front==NULL);
}
int DeleteQ(Queue Q){
    int t;
    Queue s=Q->front;
    if(IsEmptyQ(Q)){
        return error;
    } else{
        if(Q->front=Q->rear){
            Q->front=Q->rear=NULL;
        } else{
            Q->front=Q->front->Next;
        }
            t=Q->front->Data;
            free(s);
            return t;
    }
}