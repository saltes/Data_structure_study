//最大堆的存储实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxDate 999999
#define error -1
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
    int *Elements;
    int size;
    int Capacity;
};
MaxHeap Create(int MaxSize);//创建一个空的最大堆
bool IsFull(MaxHeap H);//判断最大堆H是否已满
void insert(MaxHeap H,int item);//将元素item插入最大堆H
bool IsEmpty(MaxHeap H);//判断最大堆H是否为空
int DeleteMax(MaxHeap H);//返回H中最大元素（高优先级）
int main()
{
    return 0;
}
MaxHeap Create(int MaxSize){
    MaxHeap H;
    H=(MaxHeap) malloc(MaxSize*sizeof(struct HeapStruct));
    H->Capacity=MaxSize;
    H->size=0;
    H->Elements[0]=MaxDate;//定义哨兵
    return H;
}
bool IsFull(MaxHeap H){
    return (H->Capacity==H->size);
}
void insert(MaxHeap H,int item){
    if(IsFull(H)){
        printf("error");
    } else{
        int i;
        i=++H->size;//i指向下个元素
        for(;H->Elements[i/2]<H->Elements[i];i=i/2){
            H->Elements[i]=H->Elements[i/2];
        }
        H->Elements[i]=item;
    }
}
bool IsEmpty(MaxHeap H){
    return (H->size==0);
}
int DeleteMax(MaxHeap H){
    int Parent,Child;
    int MaxItem,temp;
    if(IsEmpty(H)){
        return error;
    } else {
        MaxItem = H->Elements[1];//将最大值保存下来
        temp=H->Elements[H->size--];//用temp保存最后结点的值并删去
        //将最后结点的值放在头结点上，并排序
        for(Parent=1;Parent*2<=H->size;Parent=Child){
            Child=Parent*2;
            //找去左子结点和右子结点较大的一个
            if(Child!=H->size&&H->Elements[Child]<H->Elements[Child+1]){
                Child++;
            }
            if(H->Elements[Child]>H->Elements[Parent]){
                H->Elements[Parent]=H->Elements[Child];
            }
        }//整个循环是在找一个Parent将temp放到合适的位置上
        H->Elements[Parent]=temp;
        return MaxItem;
    }
}