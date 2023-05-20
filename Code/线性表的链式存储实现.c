//线性表的链式存储实现
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct LNode *List;
struct LNode{
    int Data;
    List Next;

};//建立线性表结构，Data存数据
struct LNode L;
List PtrL;

List MakeEmpty();//初始化一个空线性表L
List FindKth(int K,List L);//根据位序K，返回相应元素
List Find(int X,List L);//在线性表L中查找X的第一次出现位置
List Insert(int X,int i,List L);//在位序i前插入一个新元素X
List Delete(int I,List L);//删除指定位序i的元素
int Length(List L);//返回线性表L的长度n

int main()
{
    return 0;
}
List MakeEmpty(){
    List L;
    L=(List) malloc(sizeof(struct LNode));
    L->Next=NULL;
    return L;
}
List FindKth(int K,List L){
    List p=L;
    int i;
    for(i=0;i<K&&p!=NULL;i++){
        p=p->Next;
    }
    if(i==K){
        return p;
    } else {
        return NULL;
    }
}
List Find(int X,List L){
    List p=L;
    while (p->Data!=X&&p!=NULL){
        p=p->Next;
    }
    return p;
}
List Insert(int X,int i,List L){
    int j;
    List p,s;
    if(i==1){
        s=(List) malloc(sizeof (struct LNode));
        s->Next=L;
        s->Data=X;
        return s;
    } else{
        p=FindKth(i-1,L);
        if(p==NULL){
            return p;
        }else{
            s=(List) malloc(sizeof (struct LNode));
            s->Data=X;
            s->Next=p->Next;
            p->Next=s;
            return L;
        }
    }
}
List Delete(int I,List L){
    List p,s;
    if(I==1){
        s=L;
        if(L!=NULL) {
            p = L->Next;
            free(s);
            return p;
        }else{
            return NULL;
        }
    } else {
        p = FindKth(I - 1, L);
        if (p == NULL){
            return NULL;
        } else if(p->Next==NULL){
            return NULL;
        } else{
            s = p->Next;
            p->Next = s->Next;
            free(s);
            return L;
        }
    }
}
int Length(List L){
    int i=0;
    List p;
    while (p){
        p=p->Next;
        i++;
    }
    return i;
}