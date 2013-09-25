#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define	MAX	10000
//#define DEBUG

int CreateMG(MGraph *G, FILE *fp)
{
	int i,j;
	fscanf(fp, "%d\n", &G->vexnum);
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			fscanf(fp, "%d ",&G->arcs[i][j]);
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

int MGraph_Inc_Node (MGraph *G)
{
    G->vexs[G->vexnum].data = + G->vexnum;
    G->vexnum += 1;
}

int MGraph_Add_Arc (MGraph *G, int i, int j, int d)
{
    G->arcs[i][j] = d;
}
String Get_Path(MGraph *G,int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM],int i, int j, void (*print)(String))
{
	if (i == j){
		return IntToStr(G->vexs[i].data);

	}
	if (p[i][j] == -1)
		return ("No Path from" + IntToStr(G->vexs[i].data) + " to " + IntToStr(G->vexs[j].data));
	else{
		return Get_Path(G, p, i, p[i][j], print) + " -> "+ IntToStr(G->vexs[j].data);
	}
}

void ShortestPath_FLOYD(MGraph *G, void (*print)(String))
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
			if (d[i][j] >= 10000||i == j) continue;

			print ("Length " + IntToStr(i) + " -->" + IntToStr(j) + " is: " + IntToStr(d[i][j]) + "\n");
			print ("Path:" + Get_Path(G, P, i, j, print));
			//printf("\n\n");
		}
	}
	printf("\n");

	return ;
}

void ShortestPath_DIJ(MGraph * G, int v0)
{
	int i, n = G->vexnum;
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
		int w,v;
		for (w = 0; w < n; w++)
			if (!final[w])
				if (D[w] < min){
					v = w;
					min = D[w];
				}
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
		if (D[i] >= MAX || i == v0) continue;

		printf ("Length %d-->%d is %d:\n",v0, i, D[i]);
		printf ("Path:\t");
		printf("%c%s\n",G->vexs[v0].data,P[i]);
		printf("\n");
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
/*
int main()
{
	int i;
	CreateMG(&G,stdin);

	printf ("--------Compute Shortest Path using Floyd algorithm:-----------\n");
	ShortestPath_FLOYD(&G);
	
	printf ("--------Compute Shortest Path using Dijkstra algorithm:---------\n");
	for (i = 0; i < G.vexnum; i++)
		ShortestPath_DIJ(&G, i);
	
	return 0;
}*/
