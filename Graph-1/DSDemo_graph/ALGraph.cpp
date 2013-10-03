#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define	MAX	10000
#define DEBUG

int visit[MAX_VERTEX_NUM];
static char path[MAX_VERTEX_NUM];
static char path_idx = 0;

int InitALG(ALGraph *G)
{
    ;
}

int CreateALG(ALGraph *G, FILE *fp)
{

    int from, to;
    int i;
    fscanf(fp, "%d\t%d\n", &G->vexnum, &G->arcnum);

    for (i = 0; i < G->vexnum; i++){
        G->vertics[i].data.data = 'A' + i;
        G->vertics[i].firstarc = NULL;
    }

    while(fscanf(fp, "%d\t%d\n", &from, &to) != EOF){
        ArcNode	*node;
        node = (ArcNode *)malloc (sizeof (ArcNode));
        node->adjvex	= to;
        node->next	= G->vertics[from].firstarc;
        G->vertics[from].firstarc = node;
    }

    return 0;
}

int ALGraph_Add_Node (ALGraph *G, int x, int y)
{
    G->vertics[G->vexnum].data.data = 'A' + G->vexnum;
    G->vertics[G->vexnum].x = x;
    G->vertics[G->vexnum].y = y;
    G->vertics[G->vexnum].firstarc = NULL;
    G->vexnum++;
}

int ALGraph_Add_Arc (ALGraph *G, int i, int j, int d)
{
    ArcNode	*node;
    node = (ArcNode *)malloc (sizeof (ArcNode));
    node->adjvex	= j;
    node->next	= G->vertics[i].firstarc;
    G->vertics[i].firstarc = node;
    G->arcnum++;
}

int ALGraph_LocateVertex(ALGraph *G, VertexType v)
{
    int i;
    for (i=0; i<G->vexnum; i++)
        if (G->vertics[i].data.data == v.data)
            return i;
    return -1;
}

void PrintALG(ALGraph *G)
{
    int i;

    printf ("Node num:%d\nArc  num:%d\n", G->vexnum, G->arcnum);

    printf ("Arc info mation:\n");
    for (i = 0; i < G->vexnum; i++){
        ArcNode	*node;
        node = G->vertics[i].firstarc;
        while(node){
            printf("%2d---->%-2d\n", i, node->adjvex);
            node = node->next;
        }
    }

}

void DFS(ALGraph *G, int v)
{
    ArcNode	*node;
    int w;
    visit[v] = 1;
    if (G->print){
        stringstream output;
        output << "Visit " << G->vertics[v].data.data;
        G->print(output.str());
    } else
        printf("Visit %c\n",G->vertics[v].data.data);
    node = G->vertics[v].firstarc;
    while(node){
        w =  node->adjvex;
        if (!visit[w])
            DFS(G, w);
        node = node->next;
    }
}

void DFSTraverse(ALGraph *G)
{
    int i;

    for (i = 0; i < G->vexnum; i++){
        visit[i] = 0;
    }
    for (i = 0; i < G->vexnum; i++){
        if (!visit[i])
            DFS(G, i);
    }
}

void BFSTraverse(ALGraph *G)
{
    int	Q[MAX_VERTEX_NUM] = {-1};
    int front = 0, end = 0;

    int v;
    for (v = 0; v < G->vexnum; v++){
        visit[v] = 0;
    }

    for (v = 0; v < G->vexnum; v++){
        if (!visit[v]){
            Q[end++] = v;
            if (G->print){
                stringstream output;
                output <<"Visit " << G->vertics[v].data.data;
                G->print(output.str());
            } else
                printf("Visit %c\n",G->vertics[v].data.data);
            visit[v] = 1;
            while(front != end){
                ArcNode	*node;
                int w = Q[front++];
                node = G->vertics[w].firstarc;
                while(node){
                    w =  node->adjvex;
                    if (!visit[w]){
                        Q[end++] = w;
                        if (G->print){
                            stringstream output;
                            output <<"Visit " << G->vertics[w].data.data;
                            G->print(output.str());
                        } else
                            printf("Visit %c\n",G->vertics[w].data.data);
                        visit[w] = 1;
                    }
                    node = node->next;
                }
            }

        }
    }

}


int ALGraph_exist_path_DFS(ALGraph *G,int i, int j)
{
    ArcNode	*node;
    int w;
    stringstream output;
    if (i == j){
        stringstream output;
        output << "从" << path[0] << "到" << G->vertics[j].data.data << "的详细路径是";
        for (int t = 0; t < path_idx; t++)
            output << G->vertics[t].data.data << "-->";
        output << G->vertics[i].data.data;

        if (G->print){
            G->print(output.str());
        } else
            cout << output.str();
        return 1;
    }

    path[path_idx++] = G->vertics[i].data.data;
    visit[i] = 1;
    node = G->vertics[i].firstarc;
    while(node){
        w =  node->adjvex;
        if (!visit[w] && ALGraph_exist_path_DFS(G, w, j))
            return 1;
        node = node->next;
    }

    //回溯
    path_idx--;
    visit[i] = 0;

    return 0;
}

int exist_path_BFS(ALGraph *G,int i, int j)
{	
    int	Q[MAX_VERTEX_NUM] = {-1};
    int front = 0, end = 0;

    int v;
    for (v = 0; v < G->vexnum; v++){
        visit[v] = 0;
    }
    Q[end++] = i;
    //printf("Visit V%d\n",v + 1); 
    visit[v] = 1;
    while(front != end){
        ArcNode	*node;
        int w = Q[front++];
        node = G->vertics[w].firstarc;
        while(node){
            w =  node->adjvex;
            if (w == j) {
                printf("Exist Path ...:=)\n");
                return 1;
            }
            if (!visit[w]){
                Q[end++] = w;
                //printf("Visit V%d\n",w + 1);
                visit[w] = 1;
            }
            node = node->next;
        }
    }

}

int exist_Path_len(ALGraph *G,int u,int v,int k)//求有向图G中顶点u到v之间的所有简单路径,k表示当前路径长度
{
    int i;
    int l;
    ArcNode	*p;

    path[k]= G->vertics[u].data.data; //加入当前路径中
    visit[u]=1;
    if(u == v&&k == 0) {//找到了一条简单路径
        printf("Found one path!\n");
        for(i = 0; path[i]; i++) 
            printf("%c", path[i]); //打印输出
        printf("\n");
        return 1;
    } else
        for(p = G->vertics[u].firstarc; p; p = p->next) {
            l = p->adjvex;
            if(!visit[l]) 
                exist_Path_len(G,l,v,k - 1); //继续寻找
        }
    visit[u]=0;
    path[k]=0; //继续寻找
    return 0;
}

int Find_All_Path(ALGraph *G,int u,int v,int k)//求有向图G中顶点u到v之间的所有简单路径,k表示当前路径长度
{
    int i;
    int l;
    ArcNode	*p;

    path[k]= G->vertics[u].data.data;   //加入当前路径中
    visit[u]=1;
    if(u==v) {                          //找到了一条简单路径
        printf("Found one path!\n");
        for(i=0;path[i];i++) 
            printf("%c",path[i]); //打印输出
        printf("\n");
    } else
        for(p = G->vertics[u].firstarc; p; p = p->next) {
            l = p->adjvex;
            if(!visit[l]) 
                Find_All_Path(G,l,v,k+1); //继续寻找
        }
    visit[u]=0;
    path[k]=0; //回溯
}//Find_All_Path 


void freeALGraph(ALGraph *G)
{
    int n = G->vexnum;
    int i;
    for (i = 0; i < n; i++){
        ArcNode *node, *p;
        node = G->vertics[i].firstarc;
        G->vertics[i].firstarc = NULL;
        while(node){
            p = node->next;
            free(node);
            node = p;
        }
    }
}
