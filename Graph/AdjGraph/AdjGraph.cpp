#include "head.h"
///////////////////////////////////////////////////////////////////////////
//邻接表的链式存储结构及其基本操作
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;

    for (i = 0; i < n; i++)
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph *G) //输出邻接表G
{
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            if (p->weight != 2147483647) //2147483647
                printf("%3d[%d]→", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("∧\n");
    }
}

void DestroyAdj(AdjGraph *&G) //销毁邻接表
{
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) //扫描所有的单链表
    {
        pre = G->adjlist[i].firstarc; //p指向第i个单链表的首结点
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) //释放第i个单链表的所有边结点
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G); //释放头结点数组
}

/////////////////////////////////////////////////////////////////////
//遍历的两种算法巴拉巴拉巴拉
//邻接表的链式深度优先遍历算法
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) //为了把p的指向的下面节点全部遍历
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}
//邻接表的链式广度优先遍历算法
void BFS(AdjGraph *G, int v)
{
    int w, i;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];

    for (i = 0; i < G->n; i++)
        visited[i] = 0;

    printf("%2d", v);
    visited[v] = 1;

    enQueue(qu, v);

    while (!QueueEmpty(qu))
    {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                printf("%2d", p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////
//邻接表转化成邻接矩阵的函数
//该函数也可以变成一个构造邻接矩阵的函数
void ListToMat(AdjGraph *G, MatGraph &g)
{
    int i;
    ArcNode *p;

    for (i = 0; i < G->n; i++) //扫描每一个头节点顶点
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL) //找到后接着寻找头节点的后继边节点
        {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
    g.n = G->n;
    g.e = G->e;
}

//输出邻接矩阵的函数
void DispMat(MatGraph g)
{
    int i, j;
    printf("\n该图的顶点数%d，边数是%d\n\n", g.n, g.e);
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            if (i == j)
                printf(" (%d, %d)的权值为0 \n", i, j);
            else if (g.edges[i][j] == INF)
                printf(" (%d, %d)的权值为INF \n", i, j);
            else
                printf(" (%d, %d)的权值为%d \n", i, j, g.edges[i][j]);
        }
}

//邻接矩阵转换成邻接表
void MatToList(MatGraph g, AdjGraph *&G)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < g.n; i++)
        G->adjlist[i].firstarc = NULL;

    for (i = 0; i < g.n; i++)
        for (j = g.n - 1; j >= 0; j--)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) //&& g.edges[i][j] != -1
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = g.edges[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
    G->n = g.n;
    G->e = g.e;
}

////////////////////////////////////////////////////////////////////////////
//以下是构造最小生成树的两种算法，可参考教材p279

//Prim 算法构造生成树
void Prim(MatGraph g, int v)
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV], i, j, k;

    for (i = 0; i < g.n; i++)
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for (i = 1; i < g.n; i++)
    {
        MIN = INF;
        for (j = 0; j < g.n; j++)
            if (lowcost[j] != 0 && lowcost[j] < MIN)
            {
                MIN = lowcost[j];
                k = j; //记录最近的节点的编号
            }
        printf("边(%d,%d)权为：%d\n", closest[k], k, MIN);
        lowcost[k] = 0;

        for (j = 0; j < g.n; j++)
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
    }
}

// 插入排序法
void InsertSort(Edge arr[MAXV], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j;
        if (arr[i].w < arr[i - 1].w)
        {
            int temp = arr[i].w;
            Edge Temp = arr[i];
            for (j = i - 1; j >= 0 && temp < arr[j].w; j--) //找到相对不符合的就往前放
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = Temp;
        }
    }
}
////////////////////////////
//克鲁什卡尔算法构造最小生成树
void Kruskal(MatGraph g)
{
    int i, j, ul, vl, sn1, sn2, k;
    int vset[MAXV];
    Edge E[MaxSize]; //存放图中的所有的边的信息
    k = 0;           //e的数组的下标从0开始

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++) //for (j = 0; j <= i; j++) ||注意|| 这是在有向带权图的算法，无向图需要适当修改如注释
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }

    InsertSort(E, g.e); //插入法排序

    for (i = 0; i < g.n; i++) //构造辅助数组
        vset[i] = i;          //好烦好烦
    k = 1;
    j = 0;

    while (k < g.n)
    {
        ul = E[j].u;
        vl = E[j].v;
        sn1 = vset[ul];
        sn2 = vset[vl];

        if (sn1 != sn2)
        {
            printf(" (%d,%d): %d\n", ul, vl, E[j].w);
            k++;
            for (i = 0; i < g.n; i++) //防止被重复读入，这样设置后就会出现sn1=sn2的情况，避免被重复读入
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }
        j++;
    }
}

///////////////////////////////////////////////////////////////////////////
//以下是最短路径的基本算法
///可参考教材p290

//狄克斯特拉算法如下（v为源点编号）：
void Dijkstra(MatGraph g, int v)
{
    int dist[MAXV], path[MAXV];
    int s[MAXV]; //s[i]=1表示顶点i在s中，s
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i]; //距离初始化
        s[i] = 0;                //s[]置空
        if (g.edges[v][i] < INF) //路径初始化
            path[i] = v;         //顶点v到i有边时
        else
            path[i] = -1; //顶点v到i没边时
    }
    s[v] = 1; //源点v放入S中
    path[v] = 0;
    for (i = 0; i < g.n - 1; i++) //循环n-1次
    {
        mindis = INF;
        for (j = 0; j < g.n; j++)
            if (s[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        s[u] = 1;                 //顶点u加入S中
        for (j = 0; j < g.n; j++) //修改不在s中的顶点的距离
            if (s[j] == 0)
                if (g.edges[u][j] < INF &&
                    dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    //Dispath(dist, path, s, g.n, v); //输出最短路径
    Dispath(g, dist, path, s, v);
}
//输出从顶点v出发的所有最短的路径
void Dispath(MatGraph g, int dist[], int path[], int s[], int v)
{
    int i, j, k;
    int apath[MAXV], d;

    for (i = 0; i < g.n; i++)
        if (s[i] == 1 && i != v)
        {
            printf("从顶点%d到顶点%d的路径长度为：%d\t路径为：", v, i, dist[i]);
            d = 0;
            apath[d] = i;
            k = path[i];

            if (k == -1)
                printf("无路径\n");
            else
            {
                while (k != v)
                {
                    d++;
                    apath[d] = k;
                    k = path[k];
                }
                d++;
                apath[d] = v;
                printf("%d", apath[d]);
                for (j = d - 1; j > 0; j--)
                    printf(".%d", apath[j]);
                printf("\n");
            }
        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//弗洛伊德算法
//每对顶点之间的最短路径
//问题描述：对于一个各边权值均大于零的有向图，对每一对顶点i≠j，求出顶点i与顶点j之间的最短路径和最短路径长度。
/*（1）用二维数组A存储最短路径长度：
   Ak[i][j]表示考虑顶点0~k后得出的i?j的最短路径长度。
   An-1[i][j]表示最终的i?j的最短路径长度。

//（2）用二维数组path存放最短路径
pathk[i][j]表示考虑顶点0~k后得出的i?j的最短路径。
pathn-1[i][j]表示最终i?j的最短路径。
*/
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
//////////////////////////////////////////////////////////////////////////////
//拓扑排序算法
void TopSort(AdjGraph *G) //拓扑排序算法
{
    int i, j;
    int St[MAXV], top = -1; //栈St的指针为top
    ArcNode *p;
    for (i = 0; i < G->n; i++) //入度置初值0
        G->adjlist[i].count = 0;
    for (i = 0; i < G->n; i++) //求所有顶点的入度
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            G->adjlist[p->adjvex].count++;
            p = p->nextarc;
        }
    }
    for (i = 0; i < G->n; i++) //将入度为0的顶点进栈
        if (G->adjlist[i].count == 0)
        {
            top++;
            St[top] = i;
        }
    while (top > -1) //栈不空循环
    {
        i = St[top];
        top--;                      //出栈一个顶点i
        printf("%d ", i);           //输出该顶点
        p = G->adjlist[i].firstarc; //找第一个邻接点
        while (p != NULL)           //将顶点i的出边邻接点的入度减1
        {
            j = p->adjvex;
            G->adjlist[j].count--;
            if (G->adjlist[j].count == 0) //将入度为0的邻接点进栈
            {
                top++;
                St[top] = j;
            }
            p = p->nextarc; //找下一个邻接点
        }
    }
}