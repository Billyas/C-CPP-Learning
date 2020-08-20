/** 
 * 2020/5/21
 * 暴雨
 * 多文件操作时要注意不要被重复定义
 * 最好是对应的函数只有一个head的头文件
 * 其他用函数形式放在头文件里面
**/
/**
 * 2020/5/26
 * 重新添加并调试了prim算法
 * 修改了邻接矩阵的初始化值为INF
 * 加入了最小路径狄克斯特拉算法
 * 加入了krustal算法和其在有向带权图的适用性
 * 阴雨
*/

#include "head.h"
#include "SqQueue.cpp"
#include "AdjGraph.cpp"

int main()
{
    AdjGraph *G;
    MatGraph g;

    int n = 5, e = 6, i, j;
    int A[10][MAXV] = ////有向带权的连通图
        {{0, 6, INF, INF, INF},
         {INF, 0, 1, INF, INF},
         {INF, INF, 0, 3, 2},
         {INF, INF, INF, 0, INF},
         {5, INF, INF, 2, 0}};

    CreateAdj(G, A, n, e); //创建图的邻接表
    printf("G的邻接表:\n");
    DispAdj(G);

    printf("邻接表的深度优先遍历算法:\n");
    DFS(G, 4);

    printf("\n邻接表的广度优先遍历算法\n");
    BFS(G, 4);

    for (i = 0; i < 5; i++) //初始化邻接矩阵，防止异常
        for (j = 0; j < 5; j++)
            g.edges[i][j] = INF;

    printf("利用邻接表生成邻接矩阵\n");
    ListToMat(G, g);
    DispMat(g);

    printf("利用邻接矩阵生成邻接表\n");
    AdjGraph *H;
    MatToList(g, H);
    DispAdj(H);

    printf("\nPrim 算法构造生成树\n");
    Prim(g, 0);

    printf("\nKruskal 算法构造生成树\n");
    Kruskal(g);

    printf("\n狄克斯特拉算法寻找最小路径\n");
    Dijkstra(g, 0);

    printf("\nfloyd算法求每对顶点之间的最短路径\n");
    Floyd(g);

    printf("\n拓扑排序算法\n");
    TopSort(G); //拓扑排序算法
    //DispAdj(G);

    printf("\n销毁图G的邻接表\n");
    DestroyAdj(G);
    system("pause");
    return 0;
}

/////////////////////////////////////////////////////////////
//测试Kruskal算法在有向带权图下的适用性
//在实现有向图时需要修改对应的语句，具体见代码Kruskal函数
/* Edge E[maxsize];
    int k = 0;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
    InsertSort(E, g.e);
    for (i = 0; i < g.e; i++)
        printf("(%d,%d):%d\n", E[i].u, E[i].v, E[i].w);*/
////////////////////////////////////////////////////////////