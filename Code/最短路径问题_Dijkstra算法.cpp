/*
 * 最短路径问题_Dijkstra算法
 */
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#define VertexType int
#define error -1
typedef struct ArcNode
{                         // 边表节点
    int adjvex;           // 该弧所指向的顶点位置
    struct ArcNode *Next; // 指向下一条弧的指针
    int info;             // 网的边权值
} ArcNode;
typedef struct VNode
{                    // 顶点表的结点
    VertexType data; // 顶点信息
    ArcNode *first;  // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph;              // ALGragh是以邻接表为顶点的图类型
int FirstNeighbor(ALGraph G, int x);                  // 求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在x，则返回error
int NextNeighbor(ALGraph G, int x, int y);            // 假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号
int Get_edge_value(ALGraph G,int x,int y);//获得图G中边<x,y>对应的权值
int FindMinDist(ALGraph G,int dist[],bool final[]);//返回收录顶点中dist最小者
void Dijkstra_MIN_Distance(ALGraph G,bool final[],int dist[],int path[],VertexType X);//
int main() {
    return 0;
}
int FindMinDist(ALGraph G,int dist[],bool final[]){
    int Min=INT_MAX;
    int MinV;
    for(int i=0;i<G.vexnum;i++){
        if(dist[i]<Min&&!final[i]){
            Min=dist[i];
            MinV=i;
        }
    }
    if(Min<INT_MAX) {
        return MinV;
    }else{
        return error;
    }
}
void Dijkstra_MIN_Distance(ALGraph G,bool final[],int dist[],int path[],VertexType X){
    //初始化
    for(int i=0;i<G.vexnum;i++){
        dist[i]=INT_MAX;
        final[i]= false;
        ArcNode *P=G.vertices[i].first;
        while (P){
            if(P->adjvex==path[i]){
                path[i]=i;
                break;
            } else{
                path[i]=-1;
            }
            P=P->Next;
        }
    }
    dist[X]=0;
    for (int i = FirstNeighbor(G, X); i > 0; i = NextNeighbor(G, X, i)){
        dist[i]= Get_edge_value(G,X,i);
    }
        int m=INT_MAX;
    while (m!=error) {
        m = FindMinDist(G, dist, final);
        final[m] = true;
        for (int i = FirstNeighbor(G, m); i > 0; i = NextNeighbor(G, m, i)) {
            if (dist[m] + Get_edge_value(G, m, i) < dist[i]) {
                dist[i] = dist[m] + Get_edge_value(G, m, i);
                path[i]=m;
            }
        }
    }
}