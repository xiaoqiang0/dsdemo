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
    exist_path_DFS(&ALG, 0, 7);
    exist_path_BFS(&ALG, 0, 7);

    freeALGraph(&ALG);

    return 0;
}
