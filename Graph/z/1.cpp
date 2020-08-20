/**
 * 发现并解决了一个小bug
 * 阴天
 * 2020/5/19
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ElemType int
#define InfoType int
#define MAXV 100
#define INF INFINITY // 注意infinite必须再浮点数下才正确，否则再int下回出现int的最大值，导致错误

typedef struct ANode
{
    int adjvex;            //next node number
    struct ANode *nextarc; //next line
    float weight;          //the weght
} ArcNode;

typedef struct Vnode
{
    InfoType info;     //the next node number
    ArcNode *firstarc; //the next line point
} VNode;

typedef struct
{
    VNode adjlist[MAXV]; //top node array
    int n, e;            //top nodenumber line number
} AdjGraph;

void CreateAdj(AdjGraph *&G, float A[MAXV][MAXV], int n, int e)
//创建图的邻接表
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) //给邻接表中所有头结点的指针域置初值
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++) //检查邻接矩阵中每个元素
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF) //存在一条边
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个结点p
                p->adjvex = j;                          //存放邻接点
                p->weight = A[i][j];                    //存放权
                p->nextarc = G->adjlist[i].firstarc;    //采用头插法插入结点p
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
            //if (p->weight != 2147483647) //2147483647
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

int main()
{
    AdjGraph *G;
    int n = 5, e = 6;
    float A[MAXV][MAXV] =
        {{0, 6, INF, INF, INF},
         {INF, 0, 1, INF, INF},
         {INF, INF, 0, 3, 2},
         {INF, INF, INF, 0, INF},
         {5, INF, INF, 2, 0}};
    CreateAdj(G, A, n, e); //创建图的邻接表
    printf("G的邻接表:\n");
    DispAdj(G);
    printf("销毁图G的邻接表\n");
    DestroyAdj(G);

    system("pause");
}
