#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

//#define DEBUG

int MST_path[MAX_VERTEX_NUM * 2];
int MST_idx;

int CreateMG(MGraph *G, FILE *fp)
{
    int i,j;
    fscanf(fp, "%d\n", &G->vexnum);
    for (i = 0; i < G->vexnum; i++){
        for (j = 0; j < G->vexnum; j++){
            fscanf(fp, "%d ",&G->arcs[i][j]);
            if (G->arcs[i][j] != MAX) G->arcnum ++;
        }
    }

    for (i = 0; i < G->vexnum; i++){
        G->vexs[i].data = 'A' + i;
    }

#ifdef DEBUG
    printf ("Matrix of length:\n");
    for (i = 0; i < G->vexnum; i++){
        for (j = 0; j < G->vexnum; j++){
            printf("%d\t",G->arcs[i][j]);
        }
        printf("\n");
    }
    printf("\n");

#endif
    return 0;
}

int MGraph_Add_Node (MGraph *G)
{
    G->vexs[G->vexnum].data = G->vexnum + 'A';
    G->vexnum += 1;
}

int MGraph_Add_Arc (MGraph *G, int i, int j, int d)
{
    G->arcs[i][j] = d;
    G->arcnum++;
}

int Get_Path(MGraph *G,int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM],int i, int j, stringstream &path)
{
    if (i == j){
        path << G->vexs[i].data;
        return 0;

    }
    if (p[i][j] == -1){
        path <<"No Path from" << G->vexs[i].data << " to " << G->vexs[j].data;
        return -1;
    }else{
        Get_Path(G, p, i, p[i][j], path);
        path << "->" << G->vexs[j].data;
        return 0;
    }
}

void ShortestPath_FLOYD(MGraph *G)
{
    int d[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int P[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int n = G->vexnum;
    int i, j, k;

    for (i = 0; i < G->vexnum; i++){
        for (j = 0; j < G->vexnum; j++){
            d[i][j] = G->arcs[i][j];
        }
    }

    for (i = 0; i < G->vexnum; i++){
        for (j = 0; j < G->vexnum; j++){
            if (d[i][j] != 0 && d[i][j] < 10000)
                P[i][j] = i;
            else
                P[i][j] = -1;
        }
    }

    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    P[i][j] = P[k][j];
                }

            }
        }
    }
#ifdef DEBUG
    printf ("\nShortest value:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }

    printf ("\nPATH:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d\t",P[i][j]);
        }
        printf("\n");
    }
#endif

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            stringstream output;

            if (d[i][j] >= 10000||i == j) continue;

            output << "节点" <<  G->vexs[i].data << " 到节点" << G->vexs[j].data << " 的路径长度是: " << d[i][j] << "\r\n";
            output << "详细路径:" ;
            Get_Path(G, P, i, j, output);
            if (G->print)
                G->print (output.str());
            else
                cout << output.str() << endl;
        }
    }
    printf("\n");

    return ;
}

void ShortestPath_DIJ(MGraph * G, int v0)
{
    int i, j, n = G->vexnum;
    int *len;
    char **P;
    int *D ;
    int *final;

    /*----------------------------------------------*/
    len	= (int *) malloc(sizeof(int)   * n);
    P	= (char **)malloc(sizeof(char *) * n);
    for (i  = 0; i < n; i++)
        P[i] = (char *) malloc(sizeof(char) * n);
    D	= (int *) malloc(sizeof(int)   * n);
    final	= (int *) malloc(sizeof(int)   * n);
    /*----------------------------------------------*/


    for (i = 0; i < n; i++){
        D[i] = G->arcs[v0][i];
        memset(P[i], 0, 8);
        len[i] = 0;
        if (D[i] < MAX)
            P[i][len[i]++] = G->vexs[i].data;
        final[i] = 0;
    }

    D[v0] = 0;
    final[v0] = 1;
    for (i = 1 ;i < n; i++){
        int min = MAX;
        int w,v = -1;
        for (w = 0; w < n; w++)
            if (!final[w])
                if (D[w] < min){
                    v = w;
                    min = D[w];
                }

        if (v == -1)
            continue;

        final[v] = 1;
        for (w = 0; w < n; w ++){
            if (!final[w]&&(min + G->arcs[v][w] < D[w])){
                D[w] = min + G->arcs[v][w];
                memcpy(P[w],P[v],len[v]);
                len[w] = len[v];
                P[w][len[w]++] = G->vexs[w].data;
            }
        }

    }

    for (i = 0; i < n; i++){
        stringstream output;
        if (D[i] >= MAX || i == v0) continue;
        
        output << "节点" << G->vexs[v0].data << "到节点" << G->vexs[i].data << " 的路径长度是:" << D[i] << "\r\n";
        output << "详细路径: " << G->vexs[v0].data;
        for (j = 0; j < len[i]; j++) {
            output << "->" << P[i][j];
        }
        if (G->print)
            G->print (output.str());
        else
            cout << output.str() <<endl;
    }

    /*----------------------------------------------*/
    free(len);
    for (i  = 0; i < n; i++)
        free(P[i]);
    free(P);
    free(D);
    free(final);
    /*----------------------------------------------*/
    return ;
}

void MG_Prim_MST(MGraph *G, int v0)
{
    int i, j, k, l;
    MST_idx = 0;
    int key[MAX_VERTEX_NUM];
    int P[MAX_VERTEX_NUM];
    int vexnum = G->vexnum;

    for (i = 0; i < vexnum * 2; i++) {
        MST_path[i] = -1;
    }
    for (i = 0; i < vexnum; i++) {
        key[i] = MAX;
        P[i] = -1;
    }

    key[v0] = 0;
    
    for (i = 0; i < vexnum; i++) {
        int u, v;
        int cost = MAX;
        for (j = 0; j < vexnum; j ++) {
            if (key[j] < cost && key[j] != -10000) {
                cost = key[j];
                u = j;
            }
        }
        if (P[u] != -1)
            MST_path[MST_idx++] = P[u];
        else
            MST_path[MST_idx++] = -1;
        MST_path[MST_idx++] = u;
        key[u] = -10000;

        for(v = 0; v < vexnum; v++) {
            int selected = 0;
            if (G->arcs[u][v] == MAX) continue;
            for (k = 0; k < 2 * vexnum; k ++)
                if (MST_path[k] == v) {selected = 1; break;}
            if (!selected && G->arcs[u][v] < key[v]) {
                P[v] = u;
                key[v] = G->arcs[u][v];
            }
        }        
    }

    stringstream output;
    for (i = 1; i < vexnum; i++){
        output << G->vexs[MST_path[i*2]].data << "->" << G->vexs[MST_path[i*2 + 1]].data << "\r\n";
    }

    if (G->print)
        G->print (output.str());
    else
        cout << output.str() <<endl;
}

//============================disjoint-set operations =====================
/*
MAKE-SET(x)
1  p[x] ← x
2  rank[x] ← 0

UNION(x, y)
1  LINK(FIND-SET(x), FIND-SET(y))

LINK(x, y)
1  if rank[x] > rank[y]
2     then p[y] ← x
3     else p[x] ← y
4          if rank[x] = rank[y]
5             then rank[y] ← rank[y] + 1

The FIND-SET procedure with path compression is quite simple.

FIND-SET(x)
1  if x ≠ p[x]
2     then p[x] ← FIND-SET(p[x])
3  return p[x]
*/

DS ds[MAX_VERTEX_NUM];

void Make_Set(DS *x)
{
    x->rank = 0;
    x->p    = x;
}

DS * Find_Set(DS *x)
{
    if (x != x->p)
        x->p = Find_Set(x->p);
    return x->p;
}

void Link(DS *x, DS *y)
{
    if (x->rank > y->rank)
        y->p = x;
    else {
        x->p = y;
        if (x->rank == y->rank)
            y->rank = y->rank + 1;
    }
}
void Union(DS *x, DS *y)
{
    Link(Find_Set(x), Find_Set(y));
}
//---------------------------------------------Kruskal's algorithm-----------------------------

void MG_Kruskal_MST(MGraph *G)
{
    int i, j, k;
    int vexnum = G->vexnum;
    int arcnum = G->arcnum / 2;
    ARC *arcs;

    for (i = 0; i < vexnum * 2; i++) {
        MST_path[i] = -1;
    }

    for (i = 0; i < vexnum; i++) {
        Make_Set(&ds[i]);
    }
    arcs = (ARC *) malloc (sizeof (ARC) * arcnum);
    k = 0;
    for (i = 0; i < vexnum; i++)
        for (j = i+1; j < vexnum; j++) {
            if (G->arcs[i][j] == MAX ) continue;
            arcs[k].start = i;
            arcs[k].end = j;
            arcs[k].d = G->arcs[i][j];
            k++;
        }
    //Sort arcs list
    for (i = arcnum -1; i > 0; --i)
        for (j = 0; j < arcnum - 1; ++j) {
            if (arcs[j].d > arcs[j+1].d) {
                ARC tmp;
                tmp.start = arcs[j].start; tmp.end = arcs[j].end; tmp.d = arcs[j].d;
                arcs[j].start = arcs[j+1].start; arcs[j].end = arcs[j+1].end; arcs[j].d = arcs[j+1].d;
                arcs[j+1].start = tmp.start; arcs[j+1].end = tmp.end;arcs[j+1].d = tmp.d;
            }
        }

    MST_idx = 0;
    for (i = 0; i < arcnum; i++) {
        int u = arcs[i].start;
        int v = arcs[i].end;
        
        if (Find_Set(&ds[u]) == Find_Set(&ds[v])) continue;
        //Add u->v
        MST_path[MST_idx++] = u;
        MST_path[MST_idx++] = v;
        Union(&ds[u], &ds[v]);
    }

    free(arcs);

    stringstream output;
    for (i = 0; i < MST_idx / 2; i++){
        output << G->vexs[MST_path[i*2]].data << "->" << G->vexs[MST_path[i*2 + 1]].data << "\r\n";
    }

    if (G->print)
        G->print (output.str());
    else
        cout << output.str() <<endl;
}
