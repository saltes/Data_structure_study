/*
 * 最短路径问题_Floyd算法
 */
#include <bits/stdc++.h>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#define VertexType char
#define EdgeType int
#define error -1
typedef struct {
    VertexType Vex[MaxVertexNum];//顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//边
    int vexnum,arcnum;
}MGraph;
void Floyd_MIN_Distance(MGraph G,int Dist[],int **Path);//Floyd算法
void Path_Print(MGraph G,int x,int y,int **Path,int Print[],int &len);//求从x到y的最短路径的值，和路径结点
int main(){

}
void Floyd_MIN_Distance(MGraph G,int** Path){
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++) {
            Path[i][j] = -1;
        }
    }
    for(int k=0;k<G.vexnum;k++){
        for(int i=0;i<G.vexnum;i++){
            for(int j=0;j<G.vexnum;j++){
                if(G.Edge[i][j]>G.Edge[i][k]+G.Edge[k][j]){
                    G.Edge[i][j]=G.Edge[i][k]+G.Edge[k][j];
                    Path[i][j]=k;
                }
            }
        }
    }
}
void Path_Print(MGraph G,int x,int y,int **Path,int Print[],int &len){
    len=0;
    //如果x,y不在图中返回
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum){
        return;
    }
    //如果x，y之间没有边返回
    if(G.Edge[x][y]==INT_MAX){
        return;
    }
    //如果x，y之间有直接的边把x，y加入print数组中并更新len
    if(Path[x][y]==-1){
        Print[len++]=x;
        Print[len++]=y;
        return;
    }
    //如果x，y之间没有直接的边，递归打印x到k和k到y直接的路径，其中k是Path[x][y]
    int k=Path[x][y];
    Path_Print(G,x,k,Path,Print,len);
    len--;//这段代码的作用是为了避免在Print数组中重复打印相同的顶点。例如，如果x到y的路径是x->k->l->y，那么在递归地打印x到k和k到l的路径时，会把k打印两次，一次是在Print[len] = k; len++;，另一次是在Print[len] = k; len++;。为了避免这种情况，我们在打印k到l的路径之前，把len减一，这样就可以覆盖掉上一次打印的k，只保留一次
    Path_Print(G,k,y,Path,Print,len);
}