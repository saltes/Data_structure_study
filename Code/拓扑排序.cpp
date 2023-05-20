/*
 * 最短路径问题_Floyd算法
 */
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#define VertexType char
#define EdgeType int
#define error -1
typedef struct ArcNode{//边表节点
    int adjvex;//该弧所指向的顶点位置
    struct  ArcNode *Next;//指向下一条弧的指针
    int info;//网的边权值
}ArcNode;
typedef struct VNode{//顶点表的结点
    VertexType data;//顶点信息
    ArcNode *first;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;//邻接表
    int vexnum,arcnum;//图的顶点数和弧数
}ALGraph;//ALGragh是以邻接表为顶点的图类型
int FirstNeighbor(ALGraph G,int x);//求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在x，则返回error
int NextNeighbor(ALGraph G,int x,int y);//假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回error
bool TopologicalSort(ALGraph G,int indegree[],int print[]);//拓扑排序
int main(){

}
bool TopologicalSort(ALGraph G,int indegree[],int print[]){
    stack<int> S;
    int count=0;
    for(int i=0;i<G.vexnum;i++){
        if(!indegree[i]){
            S.push(i);
        }
    }
    while (!S.empty()) {
        print[count++] = S.top();
        S.pop();
        for (int i = FirstNeighbor(G, print[count - 1]); i > 0; i = NextNeighbor(G, print[count - 1], i)) {
            if (!(--indegree[i])) {
                S.push(i);
            }
        }
    }
    if(count==G.vexnum){
        return true;
    }else{
        return false;
    }
}
