//队列的顺序存储实现
#include <stdio.h>
#include <stdlib.h>
#define error -1
#define position int
typedef struct QNode *Queue;
struct QNode{
    int *Data;
    position rear,front;
    int MaxSize;
};
Queue CreatQueue(int MaxSize);//生成长度为MaxSize的空队列
int IsFullQ(Queue Q);//判断队列Q是否已满
void AddQ(Queue Q,int item);//将数据元素item插入队列Q中
int IsEmptyQ(Queue Q);//判断队列Q是否为空
int DeleteQ(Queue Q);//将队头数据元素从队列中删除并返回
int main(){
    return 0;
}
Queue CreatQueue(int MaxSize){
    Queue p;
    p=(Queue) malloc(sizeof(struct QNode));
    p->Data=(int*) malloc(MaxSize*sizeof(int));
    p->MaxSize=MaxSize;
    p->front=0;
    p->rear=0;
    return p;
}
int IsFullQ(Queue Q){
    return ((Q->rear+1)%Q->MaxSize==Q->front);
}
void AddQ(Queue Q,int item){
    if(IsFullQ(Q)){
        return;
    } else{
        Q->rear=(Q->rear+1)%(Q->MaxSize);
        Q->Data[Q->rear]=item;
    }
}
int IsEmptyQ(Queue Q){
    return (Q->front==Q->rear);
}
int DeleteQ(Queue Q){
    if(IsEmptyQ(Q)){
        return error;
    } else{
        Q->front=(Q->front+1)%(Q->MaxSize);
        return Q->Data[Q->front];
    }
}