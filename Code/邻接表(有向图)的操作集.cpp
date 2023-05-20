//邻接表(有向图)
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100//图中顶点数目的最大值
#define VertexType int
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

bool Adjacent(ALGraph G,int x,int y);//判断图G是否存在边<x,y>
bool Neighbors(ALGraph G,int x,int a[]);//列出图中于结点相邻的边
bool InsertVertex(ALGraph &G,VertexType x);//在图G中插入顶点x
VertexType DeleteVertex(ALGraph &G,int x);//在图G中删除顶点x,并返回顶点x的data
bool AddEdge(ALGraph &G,int x,int y);//若边<x,y>不存在，则向图G中添加该边
bool RemoveEdge(ALGraph &G,int x,int y);//若边<x,y>存在，则从图G中删除该边
int FirstNeighbor(ALGraph G,int x);//求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在x，则返回error
int NextNeighbor(ALGraph G,int x,int y);//假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回error
int Get_edge_value(ALGraph G,int x,int y);//获得图G中边<x,y>对应的权值
bool Set_edge_value(ALGraph &G,int x,int y,int v);//设置图G中边<x,y>对应的权值为v
void BFS(ALGraph G,int x,bool visited[]);
void BFSTraverse(ALGraph G,bool visited[]);//对图G进行广度优先遍历
void DFS(ALGraph G,int x,bool visited[]);
void DFSTraverse(ALGraph G,bool visited[]);//对图G进行深度优先遍历
void visit(int x);//想怎么访问就怎么访问
int main(){
    cout << "实现有向图的各项操作"<< endl;
    return 0;
}
bool Adjacent(ALGraph G,int x,int y){
    if(x>=G.vexnum||y>=G.vexnum){
        return false;
    }
    ArcNode *P;
    P=G.vertices[x].first;
    while(P){
        if(P->adjvex==y){
            return true;
        }
        P=P->Next;
    }
        return false;
}
bool Neighbors(ALGraph G,int x,int a[]){
    if(x>=G.vexnum){
        return false;
    }
    ArcNode *P=G.vertices[x].first;
    int count=0;
    while (P){
        a[count++]=P->adjvex;
        P=P->Next;
    }
    return count>0;
}
bool InsertVertex(ALGraph &G,VertexType x){
    if(G.vexnum>=MaxVertexNum){
        return false;
    }
    G.vertices[G.vexnum].data=x;
    G.vertices[G.vexnum].first=NULL;
    G.vexnum++;
    return true;
}
VertexType DeleteVertex(ALGraph &G,int x) {
    if (x >= G.vexnum) {
        return error;
    }
    //删除顶点x关联的边
    for(int i=0;i<G.vexnum;i++){
        if(i!=x){
            ArcNode *P=G.vertices[i].first;
            ArcNode *Pre=NULL;
            while (P){
                if(P->adjvex==x){
                    if(!Pre){
                        G.vertices[i].first=P->Next;
                    } else {
                        Pre->Next = P->Next;
                    }
                    delete P;
                    break;
                }
                Pre=P;
                P=P->Next;
            }
        }
    }
    //删除以X为邻接点的边
    ArcNode *P=G.vertices[x].first;
    while (P){
        ArcNode *del=P;
        delete del;
        P=P->Next;
        G.arcnum--;
    }
    G.vertices[x].first=NULL;
    //删除顶点X
    VertexType data=G.vertices[x].data;
    for(int i=x;i<G.vexnum-1;i++){
        G.vertices[i]=G.vertices[i+1];
    }
    G.vexnum--;
    return data;
}
bool AddEdge(ALGraph &G,int x,int y){
    if(x>G.vexnum||y>G.vexnum){
        return false;
    }
    if(Adjacent(G,x,y)){
        return true;
    }
    ArcNode *P=new ArcNode ;
    P->adjvex=y;
    P->Next=G.vertices[x].first;
    G.vertices[x].first=P;
    G.arcnum++;
    return true;
}
bool RemoveEdge(ALGraph &G,int x,int y){
    if(x>=G.vexnum||y>=G.vexnum){
        return false;
    }
    if(!Adjacent(G,x,y)){
        return true;
    }
    ArcNode *P=G.vertices[x].first;
    ArcNode *Pre=NULL;
    while (P){
        if(P->adjvex==y){
            if(!Pre){
                G.vertices[x].first=P->Next;
            }else{
                Pre->Next=P->Next;
            }
            delete P;
            break;
        }
        Pre=P;
        P=P->Next;
    }
    if(!P){
        return false;
    }
    G.arcnum--;
    return true;
}
int FirstNeighbor(ALGraph G,int x){
    if(x>=G.vexnum||!G.vertices[x].first){
        return error;
    }else {
        return G.vertices[x].first->adjvex;
    }
}
int NextNeighbor(ALGraph G,int x,int y){
    if(x>=G.vexnum||y>=G.vexnum){
        return error;
    }
    ArcNode *P=G.vertices[x].first;
    while (P){
        if(P->adjvex==y){
            break;
        }
        P=P->Next;
    }
    if(!P){
        return error;
    }
    if(!P->Next){
        return error;
    }
    return P->Next->adjvex;
}
int Get_edge_value(ALGraph G,int x,int y){
    if(x>=G.vexnum||y>=G.vexnum) {
        return error;   
    }
    ArcNode *P = G.vertices[x].first;
    while (P){
        if(P->adjvex==y){
            return P->info;
        }
        P=P->Next;
    }
    return error;
}
bool Set_edge_value(ALGraph &G,int x,int y,int v){
    if(x>=G.vexnum||y>=G.vexnum){
        return false;
    }
    ArcNode *P=G.vertices[x].first;
    while (P){
        if(P->adjvex==y){
            P->info=v;
            return true;
        }
        P=P->Next;
    }
    return false;
}
void BFS(ALGraph G,int x,bool visited[]){
    queue<int> Q;
    visit(x);
    visited[x]= true;
    Q.push(x);
    while (!Q.empty()){
        Q.pop();
        for(int i= FirstNeighbor(G,x);i>=0;i= NextNeighbor(G,x,i)){
            if(!visited[i]) {
                visit(i);
                visited[i]= true;
                Q.push(i);
            }
        }
    }
}
void BFSTraverse(ALGraph G,bool visited[]){
    for(int i=0;i<G.vexnum;i++){
        visited[i]= false;
    }
    for (int x=0;x<G.vexnum;x++) {
        if(!visited[x]){
            BFS(G,x,visited);
        }
    }
}
void DFS(ALGraph G,int x,bool visited[]){
    visit(x);
    visited[x]= true;
    for(int i= FirstNeighbor(G,x);i>=0;i= NextNeighbor(G,x,i)){
        if(!visited[i]){
            DFS(G,i,visited);
        }
    }
}
void DFSTraverse(ALGraph G,bool visited[]){
    for(int i=0;i<G.vexnum;i++){
        visited[i]= false;
    }
    for(int x=0;x<G.vexnum;x++){
        if(!visited[x]){
            DFS(G,x,visited);
        }
    }
}