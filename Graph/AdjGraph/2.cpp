/**
 * floyd算法的实现
 * 解决了溢出的问题
 * 将INF设置为一个较小的数字
 * 晴
 * 2020/5/31
*/

#include "head.h"

void Floyd(MatGraph g) //求每对顶点之间的最短路径
{
    int A[MAXV][MAXV];    //建立A数组
    int path[MAXV][MAXV]; //建立path数组
    int i, j, k;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF)
                path[i][j] = i; //i和j顶点之间有一条边时
            else                //i和j顶点之间没有一条边时
                path[i][j] = -1;
        }

    for (k = 0; k < g.n; k++) //求Ak[i][j]
    {
        for (i = 0; i < g.n; i++)
            for (j = 0; j < g.n; j++)
                if (A[i][j] > A[i][k] + A[k][j]) //找到更短路径
                {
                    A[i][j] = A[i][k] + A[k][j]; //修改路径长度
                    path[i][j] = path[k][j];     //修改最短路径为经过顶点k
                }
    }

    DispathFloyd(g, A, path);
}

void DispathFloyd(MatGraph g, int A[][MAXV], int path[][MAXV])
{
    int i, j, k, s;
    int apath[MAXV], d;

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            if (A[i][j] != INF && i != j)
            {
                printf("从%d到%d的路径是：", i, j);
                k = path[i][j];
                d = 0;
                apath[d] = j;
                while (k != -1 && k != i)
                {
                    d++;
                    apath[d] = k;
                    k = path[i][k];
                }
                d++;
                apath[d] = i;
                printf("%d", apath[d]);

                for (s = d - 1; s >= 0; s--)
                    printf(",%d", apath[s]);
                printf("\t路径长度为:%d\n", A[i][j]);
            }
        }
}

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
    int B[4][4] = {
        {0, 5, INF, 7},
        {INF, 0, 4, 2},
        {3, 3, 0, 2},
        {INF, INF, 1, 0}};

    for (i = 0; i < 4; i++) //初始化邻接矩阵，防止异常
        for (j = 0; j < 4; j++)
            g.edges[i][j] = B[i][j];
    g.e = 8;
    g.n = 4;

    for (i = 0; i < g.n; i++) //邻接矩阵
        for (j = 0; j < g.n; j++)
            printf("%d %d :%d \n", i, j, g.edges[i][j]);

    printf("\nfloyd算法求每对顶点之间的最短路径\n");
    Floyd(g);

    system("pause");
    return 0;
}
