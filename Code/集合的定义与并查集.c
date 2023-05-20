//集合的定义与并查操作
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error -1/* 集合最大元素个数 */
#define MaxSize 100
typedef int SetName;/* 默认用根结点的下标作为集合名称 */
typedef struct {
    int Data;
    int Parent;
}SetType;
void Union( SetType S[], SetName X1, SetName X2 );//
SetName Find( SetType S[], int X );//查找某个元素所在的集合用根结点表示
int main()
{
    return 0;
}
SetName Find( SetType S[], int X ){
    int i;
    for (i=0;S[i].Data!=X&&i<MaxSize;i++);//找到这个元素
    for(;S[i].Parent>0;i=S[i].Parent);//由这个元素找到其根结点
    return i;
}
void Union( SetType S[], SetName X1, SetName X2 ){
    int Root1,Root2;
    Root1= Find(S,X1);//找X1的根结点
    Root2= Find(S,X2);//找X2的根结点
    if(Root1!=Root2){
        S[Root2].Parent=Root1;//将Root2接到Root1上
    }
}