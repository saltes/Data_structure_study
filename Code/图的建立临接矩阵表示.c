//图的建立临接矩阵表示
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error -1
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;//定义点的类型
typedef int WeightType;//定义权重
typedef char DataType;//顶点数据类型
//定义边
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;//点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
MGraph CreateGraph( int VertexNum );//初始化一个有VertexNum个顶点但没有边的图
void InsertEdge( MGraph Graph, Edge E );//将边插入图
MGraph BuildGraph();
int main()
{
    return 0;
}
MGraph CreateGraph( int VertexNum ){
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph) malloc(sizeof (struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for (V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W]=INFINITY;
         }
    }
    return Graph;
}
void InsertEdge( MGraph Graph, Edge E ){
    Graph->G[E->V1][E->V2]=E->Weight;
    Graph->G[E->V2][E->V1]=E->Weight;
}
MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    scanf("%d",&Nv);
    Graph= CreateGraph((Nv));
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge) malloc(sizeof(struct ENode));
    }
    for (i=0;i<Graph->Ne;i++) {
        scanf("%d %d %d",&E->V1,&E->V2,E->Weight);
        InsertEdge(Graph,E);
    }
    for (V=0;V<Graph->Nv;V++){
        scanf("%c",&(Graph->Data[V]));
    }
    return Graph;
}