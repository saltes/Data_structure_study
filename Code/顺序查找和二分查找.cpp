#include<bits/stdc++.h>
typedef struct{
    int *elem;//元素存储空间基址，建表分配
    int Tablelen;//表长
}SSTable;
int Search_Seq(SSTable ST,int key);//顺序查找
int Binary_Search(SSTable ST,int key);//折半查找
int main(){
    return 0;
}
int Search_Seq(SSTable ST,int key){
    int i;
    ST.elem[0]=key;
    for(i=ST.Tablelen;ST.elem[i]!=key;i--);
    return i;
}
int Binary_Search(SSTable ST,int key){
    int low=0,high=ST.Tablelen-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(ST.elem[mid]==key){
            return mid;
        }else if(ST.elem[mid]>key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}