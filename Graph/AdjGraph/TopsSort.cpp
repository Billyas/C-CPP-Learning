#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MVNum 100
typedef int Status;
typedef char VerTexType;
typedef char OtherInfo;
int indegree[MVNum] = {0};
//创建栈
typedef struct StackNode
{
    int data;
    StackNode *next;
} StackNode, *StackList;
//出栈函数
StackList Pop(StackList S, int *e)
{
    StackList p;
    p = S;
    if (!p)
        return ERROR;
    *e = p->data;
    S = S->next;
    free(p);
    return S;
}
//入栈函数：
StackList Push(StackList S, int e)
{
    StackList p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return S;
}
//邻接表创建有向图的实现
//边结点
typedef struct ArcNode
{                     //链表结点
    int adjvex;       //邻接表创建无向网的实现
    ArcNode *nextarc; //指向下一条边的指针
    OtherInfo info;   //和边相关的信息
} ArcNode;

//顶点信息
typedef struct VNode
{                        //头结点
    VerTexType data;     //顶点信息
    ArcNode *firstarc;   //指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; //AdjList 表示邻接表类型

typedef struct
{
    AdjList vertices;   //邻接表头结点数组
    int vexnum, arcnum; //图的顶点数和弧数
} ALGraph;
//创建有向图：

int LocateVex(ALGraph *G, VerTexType v) //G带操作的图；v要在图中定位的顶点
{
    int i;
    for (i = 0; i < (G->vexnum); i++)
    {
        if (v == G->vertices[i].data)
            return i; //顶点存在则返回在头结点数组中的下标；否则返回
    }
}

void CreateUDG(ALGraph *G)
{
    int i, j, k;
    VerTexType v1, v2;
    ArcNode *p1;
    printf("输入总节点数和弧数："); //G带操作的图；v要在图中定位的顶点
    scanf("%d %d", &G->vexnum, &G->arcnum);
    fflush(stdin); //是清空输入缓冲区的
    printf("输入各个节点的值：");
    for (i = 0; i < G->vexnum; i++) //邻接表初始化

    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k = 0; k < G->arcnum; k++)
    {
        fflush(stdin); //是清空输入缓冲区的
        printf("弧度的两个点两个节点：");
        scanf("%c %c", &v1, &v2);
        i = LocateVex(G, v1); //返回这两个顶点在顶点数组中的位置
        j = LocateVex(G, v2);
        p1 = (ArcNode *)malloc(sizeof(ArcNode)); //给邻接表指针分配空间
        p1->adjvex = j;                          //赋值给p->adjvex指向的顶点域
        p1->nextarc = G->vertices[i].firstarc;   //nextarc指针域指向i结点的firstarc指针域
        G->vertices[i].firstarc = p1;            //将点i的第一条指针指向
        indegree[j]++;                           //vi->vj, vj入度加1
    }
}
//拓扑排序算法
Status TopologicalSort(ALGraph G, int *topo)
{ //先声明栈指针S，并让其指向NULL。检查所有节点中是否有入度为0的节点，如果有，则进栈。
    int i, m, k;
    StackList S; //先声明栈指针S，并让其指向NULL。
    ArcNode *p;
    S = NULL;
    for (i = 0; i < G.vexnum; i++) //检查所有节点中是否有入度为0的节点，如果有则进栈。
    {
        if (!indegree[i]) //当数组不为零时
            S = Push(S, i);
    }         //入度为零去完后
    m = 0;    //记录topu数组的数
    while (S) //栈不为空的时候，先出栈，取出栈顶元素，并将其记录在topo[]数组中
    {
        S = Pop(S, &i);
        topo[m] = i;
        ++m;
        p = G.vertices[i].firstarc; //指针p 指向第一条边的节点
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k];
            if (indegree[k] == 0)
                S = Push(S, k);
            p = p->nextarc;
        }
    }
    topo[m] = -1;     // 为-1时结束
    if (m < G.vexnum) // topo[]数组中元素是否已经达到节点数，
        return ERROR;
    else
        return OK;
}

int main(void)
{
    ALGraph G;
    int i;
    int topo[99] = {0};
    CreateUDG(&G);
    if (TopologicalSort(G, topo))
    {
        printf("有向图，无环\n    拓扑排序序列为：");
        for (i = 0; topo[i] != -1; i++)
        {
            printf("%c ", G.vertices[topo[i]].data);
        }
    }
    else
        printf("有环，请重新输入");
    printf("\n");
    system("pause");
    return 0;
}
