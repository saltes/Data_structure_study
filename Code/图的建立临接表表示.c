//图的建立临接表表示
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define error -1
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;//定义点的类型
typedef int WeightType;//定义权重
typedef char DataType;//顶点数据类型
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
typedef struct AdjVNode *PtrToAdjVNode;
typedef struct AdjVNode{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Date;
}AdList[MaxVertexNum];
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph( int VertexNum );
void InsertEdge( LGraph Graph, Edge E );
LGraph BuildGraph();
int main() {
    return 0;
}
LGraph CreateGraph( int VertexNum ){
    Vertex V;
    LGraph Graph;
    Graph=(LGraph) malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++){
            Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}
void InsertEdge( LGraph Graph, Edge E ){
    PtrToAdjVNode NewNode;
    NewNode=(PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;//头插
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}
LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    int Nv,i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    for (i=0;i<Graph->Ne;i++){
        scanf("%d %d %d",E->V1,E->V2,E->Weight);
        InsertEdge(Graph,E);
    }
    for(i=0;i<Graph->Nv;i++){
        scanf("%c",&Graph->G[i].Date);
    }
    return Graph;
}