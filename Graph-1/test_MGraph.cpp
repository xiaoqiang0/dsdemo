#include "graph.h"

int main()
{
    int i;
    MGraph G;

    G.print = NULL;

    CreateMG(&G,stdin);

    printf ("--------Compute Shortest Path using Floyd algorithm:-----------\n");
    ShortestPath_FLOYD(&G);

    printf ("--------Compute Shortest Path using Dijkstra algorithm:---------\n");
    for (i = 0; i < G.vexnum; i++)
        ShortestPath_DIJ(&G, i);

    return 0;
}
