/*
 * 邻接矩阵存储 - Prim最小生成树算法
 */
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100//图中顶点数目的最大值
#define VertexType char
#define EdgeType int
#define WeightType int
#define error -1
typedef struct {
    VertexType Vex[MaxVertexNum];//顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//边
    int vexnum,arcnum;
}MGragh;
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
}LGraph;//ALGragh是以邻接表为顶点的图类型
VertexType FindMinDist(MGragh G,WeightType dist[]);//返回收录顶点中dist最小者
int prime(MGragh G,LGraph MST);//将最小生成树保存为邻接表存储的图MST,返回最小权重和
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
VertexType FindMinDist(MGragh G,WeightType dist[]){
    VertexType MinV,V;
    WeightType MinDist=INT_MAX;
//找到离MST距离最小的点
    for(V=0;V<G.vexnum;V++){
        if(dist[V]<MinDist&&dist[V]){
            MinDist=dist[V];
            MinV=V;
        }
    }
    if(V<INT_MAX){
        return MinV;
    }else{
        return error;
    }
}
int prime(MGragh G,LGraph MST){
    WeightType dist[MaxVertexNum],TotalWeight=0;
    VertexType parent[MaxVertexNum],V,W;
    int Vcount=0;//计数器
    for(V=0;V<G.vexnum;V++){
        dist[V]=G.Edge[0][V];
        parent[V]=-1;
    }
    //初始化MST
    for(V=0;V<MST.vexnum;V++) {
        MST.vertices[V].data=0;
    }
    MST.vexnum=G.vexnum;
    MST.arcnum=0;
    for(V=0;V<MST.vexnum;V++) {
        MST.vertices[V].first=NULL;
        MST.vertices[V].data=V;
    }
    //创建边E
    ArcNode* E=new ArcNode;
    dist[0]=0;
    Vcount++;
    parent[0]=-1;
    while (1){
        V= FindMinDist(G,dist);
        if(V==error){
            break;
        }
        E->info=dist[V];
        E->adjvex=V;
        //查入边
        if(parent[V]!=-1) {
            MST.vertices[parent[V]].first = E;
        }
        TotalWeight+=dist[V];
        dist[V]=0;
        Vcount++;
        for(W=0;W<G.vexnum;W++){
            //如果不在树里且有边进行检测更新
            if(dist[W]&&G.Edge[V][W]<INT_MAX){
                if(G.Edge[V][W]<dist[W]){
                    dist[W]=G.Edge[V][W];
                    parent[W]=V;
                }
            }
        }
    }
    if(Vcount<G.vexnum){
        TotalWeight=error;
    }
    return TotalWeight;
}

