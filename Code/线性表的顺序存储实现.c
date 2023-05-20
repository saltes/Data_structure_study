//线性表的顺序存储实现
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct LNode *List;
struct LNode{
    int Data[MAXSIZE];
    int last;
};//建立线性表结构，Data存数据，last为最后一个元素的下标
struct LNode L;
List PtrL;

List MakeEmpty();//初始化一个空线性表L
int FindKth(int K,List L);//根据位序K，返回相应元素
int Find(int X,List L);//在线性表L中查找X的第一次出现位置
void Insert(int X,int i,List L);//在位序i前插入一个新元素X
void Delete(int I,List L);//删除指定位序i的元素
int Length(List L);//返回线性表L的长度n

int main()
{
    return 0;
}
List MakeEmpty(){
    List PrtL;
    PrtL=(List)malloc(sizeof(struct LNode));
    PrtL->last=-1;
    return PrtL;
}
int FindKth(int K,List L){
    return (L->Data[K-1]);
}
int Find(int X,List L){
    int i;
    for(i=0;L->Data[i]!=X&&i<=L->last;i++);
    if(i>L->last){
        return -1;
    } else {
        return i;
    }
}
void Insert(int X,int i,List L){
    int j;
    if(L->last==MAXSIZE-1){
        printf("表满");
        return;
    }
    if(i<1||i>L->last+1){
        printf("位置不合法");
        return;
    }
    for(j=L->last;j>i-2;j--){
        L->Data[j+1]=L->Data[j];
    }
    L->Data[i-1]=X;
    L->last++;
    return;
}
void Delete(int I,List L){
    int i;
    if(i<1||i>L->last+1){
        printf("位置不合法");
        return;
    }
    for(i=I;i<=L->last;i++){
        L->Data[i-1]=L->Data[i];
    }
    L->last--;
    return;
}
int Length(List L){
    return L->last+1;
}