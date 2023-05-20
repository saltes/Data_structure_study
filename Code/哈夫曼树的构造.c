//哈夫曼树的构造
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error -1
typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left,Right;
};
typedef struct HNode *MinHeap;
struct HNode{
    int *Data;
    int Size;
    int capacity;
};
HuffmanTree Huffman(MinHeap H);
MinHeap Create(int MaxSize);
bool IsFull(MinHeap H);
void insert(MinHeap H,int item);
bool IsEmpty(MinHeap H);
HuffmanTree DeleteMin(MinHeap H);
void Insert(MinHeap H,HuffmanTree T);
int main()
{
    return 0;
}
HuffmanTree Huffman(MinHeap H){
    int i;HuffmanTree T;
    for(i=0;i<H->Size;i++){//做H->Size-1次合并
        T=(HuffmanTree) malloc(sizeof (struct TreeNode));
        T->Left=DeleteMin(H);
        T->Right= DeleteMin(H);
        T->Weight=T->Left->Weight+T->Right->Weight;
        Insert(H,T);//将新T插入最小堆
    }
    T= DeleteMin(H);
    return T;
}