#ifndef  _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <iostream>
#include <sstream>
#define  MAX_VERTEX_NUM 9

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

struct VertexType
{
    char data;
};

typedef struct {
    struct VertexType  vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    void (*print)(string);

}MGraph;

/*-------------------------------------------------------*/
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
    char *ArcInfo;
}ArcNode;

typedef struct Vnode
{
    struct VertexType  data;
    int x,y;
    ArcNode *firstarc;
}Vnode, AdjList[MAX_VERTEX_NUM];

typedef struct 
{
    AdjList vertics;
    int vexnum, arcnum;
    void (*print)(string);
}ALGraph;

int CreateALG(ALGraph *G, FILE *fp);
int ALGraph_Add_Node (ALGraph *G, int x, int y);
int ALGraph_Add_Arc (ALGraph *G, int i, int j, int d);
int ALGraph_LocateVertex(ALGraph *G, VertexType v);
void PrintALG(ALGraph *G);
void DFS(ALGraph *G, int v);
void DFSTraverse(ALGraph *G);
void BFSTraverse(ALGraph *G);
int ALGraph_exist_path_DFS(ALGraph *G,int i, int j);
int _ALGraph_exist_path_DFS(ALGraph *G,int i, int j);
int exist_path_BFS(ALGraph *G,int i, int j);
int exist_Path_len(ALGraph *G,int u,int v,int k); //求有向图G中顶点u到v之间的所有简单路径,k表示当前路径长度
int Find_All_Path(ALGraph *G,int u,int v,int k); //求有向图G中顶点u到v之间的所有简单路径,k表示当前路径长度
void freeALGraph(ALGraph *G);

int CreateMG(MGraph *G, FILE *fp);
int MGraph_Add_Node (MGraph *G);
int MGraph_Add_Arc (MGraph *G, int i, int j, int d);
int Get_Path(MGraph *G,int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM],int i, int j, stringstream & path);
void ShortestPath_FLOYD(MGraph *G);
void ShortestPath_DIJ(MGraph * G, int v0);
void MG_Prim_MST(MGraph * G, int v0);
void MG_Kruskal_MST(MGraph *G);
extern int visit[MAX_VERTEX_NUM];
extern char ALG_path[MAX_VERTEX_NUM];
extern char ALG_path_idx;

typedef struct Arc
{
    int start, end;
    int d;
}Arc;

typedef struct DS
{
    int i;
    int rank;
    struct DS *p;
}DS;

#endif
