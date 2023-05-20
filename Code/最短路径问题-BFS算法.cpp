/*
 * 最短路径问题-BFS算法
 */
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#define VertexType int
#define error -1
typedef struct ArcNode{                         // 边表节点
    int adjvex;           // 该弧所指向的顶点位置
    struct ArcNode *Next; // 指向下一条弧的指针
    int info;             // 网的边权值
} ArcNode;
typedef struct VNode{                    // 顶点表的结点
    VertexType data; // 顶点信息
    ArcNode *first;  // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph;              // ALGragh是以邻接表为顶点的图类型
void BFS_MIN_Distance(ALGraph G,int U,bool visited[],int d[],int path[]);//求顶点U到其他顶点的最小路径,d[]为路径长度，path表示最短路径从哪个顶点过来的
int FirstNeighbor(ALGraph G, int x);                  // 求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在x，则返回error
int NextNeighbor(ALGraph G, int x, int y);            // 假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号
int main() {
    return 0;
}
//
void BFS_MIN_Distance(ALGraph G,int U,bool visited[],int d[],int path[]){
    //初始化
    for(int i=0;i<G.vexnum;i++){
        d[i]=INT_MAX;//初始化路径长度为无穷
        path[i]=-1;//初始化经过顶点
    }
    queue<int> Q;
    //先访问U
    d[U]=0;
    path[U]=-1;
    visited[U]= true;
    //将U入队，并进行BFS
    Q.push(U);
    while (!Q.empty()){
        U=Q.front();
        Q.pop();
        for(int i= FirstNeighbor(G,U);i>0;i= NextNeighbor(G,U,i)){
            if(visited[i]) {
                d[i]=d[U]+1;
                path[i] = U;
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}