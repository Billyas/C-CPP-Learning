#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
#define INF = 1000

typedef struct struct_graph
{
    char vexs[MAXN];
    int vexnum;             //顶点数
    int edgnum;             //边数
    int matirx[MAXN][MAXN]; //邻接矩阵
} Graph;

int pathmatirx[MAXN][MAXN]; //记录对应点的最小路径的前驱点，例如p(1,3) = 2 说明顶点1到顶点3的最小路径要经过2
int shortPath[MAXN][MAXN];  //记录顶点间的最小路径值

void short_path_floyd(Graph G, int P[MAXN][MAXN], int D[MAXN][MAXN])
{
    int v, w, k;
    //初始化floyd算法的两个矩阵
    for (v = 0; v < G.vexnum; v++)
    {
        for (w = 0; w < G.vexnum; w++)
        {
            D[v][w] = G.matirx[v][w];
            P[v][w] = w;
        }
    }

    //这里是弗洛伊德算法的核心部分
    //k为中间点
    for (k = 0; k < G.vexnum; k++)
    {
        //v为起点
        for (v = 0; v < G.vexnum; v++)
        {
            //w为终点
            for (w = 0; w < G.vexnum; w++)
            {
                if (D[v][w] > (D[v][k] + D[k][w]))
                {
                    D[v][w] = D[v][k] + D[k][w]; //更新最小路径
                    P[v][w] = P[v][k];           //更新最小路径中间顶点
                }
            }
        }
    }

    printf("\n初始化的D矩阵\n");
    for (v = 0; v < G.vexnum; v++)
    {
        for (w = 0; w < G.vexnum; w++)
        {
            printf("%d ", D[v][w]);
        }
        printf("\n");
    }

    printf("\n初始化的P矩阵\n");
    for (v = 0; v < G.vexnum; v++)
    {
        for (w = 0; w < G.vexnum; w++)
        {
            printf("%d", P[v][w]);
        }
        printf("\n");
    }

    v = 0;
    w = 3;
    //求 0 到 3的最小路径
    printf("\n%d -> %d 的最小路径为：%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %d", v); //打印起点
    while (k != w)
    {
        printf("-> %d", k); //打印中间点
        k = P[k][w];
    }
    printf("-> %d\n", w);
}

int main()
{
    int v, w;
    Graph G;
    printf("请输入顶点数:\n");
    scanf("%d", &G.vexnum);
    printf("请输入初始矩阵值：\n");
    for (v = 0; v < G.vexnum; v++)
    {
        for (w = 0; w < G.vexnum; w++)
        {
            scanf("%d", &G.matirx[v][w]);
        }
    }
    printf("\n输入的矩阵值：\n");
    for (v = 0; v < G.vexnum; v++)
    {
        for (w = 0; w < G.vexnum; w++)
        {
            printf("%d ", G.matirx[v][w]);
        }
        printf("\n");
    }
    short_path_floyd(G, pathmatirx, shortPath);
}