﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define	MAX	10000
#define DEBUG

int visit[MAX_VERTEX_NUM];
//ALGraph ALG;

int CreateALG(ALGraph *G, FILE *fp)
{

	int from, to;
	int i;
	fscanf(fp, "%d\t%d\n", &G->vexnum, &G->arcnum);

	for (i = 0; i < G->vexnum; i++){
		G->vertics[i].data.data = 'A' + i;
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
	printf("Visit V%d\n",v + 1);
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
			printf("Visit V%d\n",v + 1);
			visit[v] = 1;
			while(front != end){
				ArcNode	*node;
				int w = Q[front++];
				node = G->vertics[w].firstarc;
				while(node){
					w =  node->adjvex;
					if (!visit[w]){
						Q[end++] = w;
						printf("Visit V%d\n",w + 1);
						visit[w] = 1;
					}
					node = node->next;
				}
			}
			
		}
	}

}


int exist_path_DFS(ALGraph *G,int i, int j)
{
	ArcNode	*node;
	int w;

	if (i == j){
		printf("Exist Path ...:=)\n");
		return 1;
	}
	visit[i] = 1;
	node = G->vertics[i].firstarc;
	while(node){
		w =  node->adjvex;
		if (!visit[w] && exist_path_DFS(G, w, j))
			return 1;
		node = node->next;
	}
	visit[i] = 0;//回溯
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

char path[MAX_VERTEX_NUM];

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
	path[k]=0; //回溯
	return 0;
}

int Find_All_Path(ALGraph *G,int u,int v,int k)//求有向图G中顶点u到v之间的所有简单路径,k表示当前路径长度
{
	int i;
	int l;
	ArcNode	*p;

	path[k]= G->vertics[u].data.data; //加入当前路径中
	visit[u]=1;
	if(u==v) {//找到了一条简单路径
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
/*
int main()
{

	int v;

	CreateALG(&ALG,stdin);
	PrintALG(&ALG);

	printf("Depth First Traverse:\n");
	DFSTraverse(&ALG);

	printf("\nBoard First Traverse:\n");
	BFSTraverse(&ALG);

	for (v = 0; v < MAX_VERTEX_NUM; v++){
		visit[v] = 0;
	}
	
	Find_All_Path(&ALG, 0, 7,0);

	for (v = 0; v < MAX_VERTEX_NUM; v++){
		visit[v] = 0;
	}

	exist_Path_len(&ALG, 0, 7, 4);
	exist_path_DFS(&ALG, 0, 7);
	exist_path_BFS(&ALG, 0, 7);
	
	freeALGraph(&ALG);

	return 0;
}
*/
