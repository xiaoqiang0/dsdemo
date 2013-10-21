#include "graph.h"

int main()
{

    int v;
    ALGraph ALG;
    ALG.print = NULL;
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
    ALGraph_exist_path_DFS(&ALG, 0, 4);
    cout <<endl;
    exist_path_BFS(&ALG, 0, 7);
    if (circle_check(&ALG)) {
        printf("circle exist:");
        for (int i = 0; i < ALG_path_idx; i++)
            printf ("%c->", ALG_path[i]);
        printf("%c\n", ALG_path[0]);
    }
    
    if (!topologicalSort(&ALG)) {
        printf ("Topological order:");
        for (int i = 0; i < ALG_path_idx; i++)
            printf ("%c->", ALG_path[i]);
        printf("\n");
    }

    freeALGraph(&ALG);

    return 0;
}
