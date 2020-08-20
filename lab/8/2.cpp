#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define ElemType int
#define maxsize 100
#define InfoType int
#define MAXV 100
#define MaxSize 100
#define INF 214748364 ///һ����Ҫ���int�����ֵ����Ϊ�����floyd�㷨����мӷ����㣬�ᵼ�½�������ɸ�ֵ��int_max=2147483647
#define INFINITE INF
/////////////////////////////////////////////////
//�ڽӱ�Ľṹ�嶨��
typedef struct ANode
{
    int adjvex;            //�ñߵ��ڽӵ�ı�ţ��������ָ��Ķ�����
    struct ANode *nextarc; //ָ����һ���ߵ�ָ��
    int weight;            //�ߵ���ص���Ϣ����Ȩֵ
} ArcNode;                 //�߽ڵ������

typedef struct Vnode
{
    InfoType info;     //�����������Ϣ
    int count;         //��Ŷ������
    ArcNode *firstarc; //ָ���һ���߽ڵ�
} VNode;               //�ڽӱ��ͷ�ڵ�Ľṹ������

typedef struct
{
    VNode adjlist[MAXV]; //ͷ�ڵ������
    int n, e;            //ͼ�Ķ������ͱ���
} AdjGraph;              //�����ڽӱ�����ݽṹ������
//////////////////////////////////////////////////
//�ڽӾ���Ľṹ��
typedef struct S
{
    int no;        //����ı��
    InfoType info; //�����������Ϣ
} VertexType;      //���������

typedef struct SS
{
    int edges[MAXV][MAXV]; //�ڽӾ��������
    int n, e;              //ͼ�Ķ������ͱ���
    VertexType vexs[MAXV]; //��Ŷ�����Ϣ
} MatGraph;
///////////////////////////////////////////////////
typedef struct SSS
{
    ElemType data[maxsize];
    int front;
    int rear;
} SqQueue; //���еĽṹ��
////////////////////////////////
//Kruskal�㷨��Ҫ�ļ�ͼ�Ľṹ��
typedef struct head
{
    int u; //�ߵ���ʼ����
    int v; //�ߵ���ֹ����
    int w; //�ߵ�Ȩֵ
} Edge;
///////////////////////////////
///������������������
int visited[MAXV] = {0};
///////////////////////////////
//���еĲ�����������
//���ڶ��еĺ�������һ���ļ�
//������Ҫ����һ��
void InitQueue(SqQueue *&q);
void DestoryQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, ElemType e);
bool deQueue(SqQueue *&q, ElemType &e);
/////////////////////////////////////////////////////////////////
//���������Ҫ��һЩ���еĻ�������
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestoryQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
    if ((q->rear + 1) % maxsize == q->front)
        return false;
    q->rear = (q->rear + 1) % maxsize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
        return false;

    q->front = (q->front + 1) % maxsize;
    e = q->data[q->front];

    return true;
}
/////////////////////////////////////////////////////////////////
void Dispath(MatGraph g, int dist[], int path[], int s[], int v);
void DispathFloyd(MatGraph g, int A[][MAXV], int path[][MAXV]);

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

void DispAdj(AdjGraph *G) //����ڽӱ�G
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
                printf("%3d[%d]��", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("��\n");
    }
}

void DestroyAdj(AdjGraph *&G) //�����ڽӱ�
{
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) //ɨ�����еĵ�����
    {
        pre = G->adjlist[i].firstarc; //pָ���i����������׽��
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) //�ͷŵ�i������������б߽��
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G); //�ͷ�ͷ�������
}

/////////////////////////////////////////////////////////////////////
//�����������㷨������������
//�ڽӱ����ʽ������ȱ����㷨
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) //Ϊ�˰�p��ָ�������ڵ�ȫ������
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}
//�ڽӱ����ʽ������ȱ����㷨
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
//�ڽӱ�ת�����ڽӾ���ĺ���
//�ú���Ҳ���Ա��һ�������ڽӾ���ĺ���
void ListToMat(AdjGraph *G, MatGraph &g)
{
    int i;
    ArcNode *p;

    for (i = 0; i < G->n; i++) //ɨ��ÿһ��ͷ�ڵ㶥��
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL) //�ҵ������Ѱ��ͷ�ڵ�ĺ�̱߽ڵ�
        {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
    g.n = G->n;
    g.e = G->e;
}

//����ڽӾ���ĺ���
void DispMat(MatGraph g)
{
    int i, j;
    printf("\n��ͼ�Ķ�����%d��������%d\n\n", g.n, g.e);
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            if (i == j)
                printf(" (%d, %d)��ȨֵΪ0 \n", i, j);
            else if (g.edges[i][j] == INF)
                printf(" (%d, %d)��ȨֵΪINF \n", i, j);
            else
                printf(" (%d, %d)��ȨֵΪ%d \n", i, j, g.edges[i][j]);
        }
}
//////////////////////////////////////////////////////////////////////////////
//����������ȱ����㷨��Ӧ��
//��Ҫ��Ӧ����Ѱ�Ҽ�·���ĺ��ض��ĳ��ȵļ�·����Ӧ����
//////////////////////////////////////////////
//����Ӧu��v��ȫ����·���������㲻�ظ���·����
void FindAllPath(AdjGraph *G, int u, int v, int path[], int d)
//d��ʾpath����·�����ȣ���ʼֵ��Ϊ-1
{
    int w, i;
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if (u == v && d >= 0)
    {
        for (i = 0; i <= d; i++)
            printf("%2d", path[i]);
        printf("\n");
    }

    p = G->adjlist[u].firstarc;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
            FindAllPath(G, w, v, path, d);
        p = p->nextarc;
    }
    visited[u] = 0;
}
/////////////////////////////////////
//Ѱ�Ҵ�u��v������·������Ϊl�ļ�·��
void PathlenAll(AdjGraph *G, int u, int v, int l, int path[], int d)
{
    int w, i;
    ArcNode *p;
    visited[u] = 1;
    d++;
    path[d] = u;

    if (u == v && d == l)
    {
        printf(" ");
        for (i = 0; i <= d; i++)
            printf("%2d", path[i]);
        printf("\n");
    }

    p = G->adjlist[u].firstarc;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
            PathlenAll(G, w, v, l, path, d);
        p = p->nextarc;
    }
    visited[u] = 0;
}

//////////////////////////////////////////////////////////////////////////////

int main()
{
    AdjGraph *G;
    MatGraph g;

    int n = 5, e = 6, i, j;
    int path[10];
    int A[10][MAXV] = ////�����Ȩ����ͨͼ
        {{0, 6, INF, INF, INF},
         {INF, 0, 1, INF, INF},
         {INF, INF, 0, 3, 2},
         {INF, INF, INF, 0, INF},
         {5, INF, INF, 2, 0}};

    int B[6][MAXV] = {
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 0}};

    CreateAdj(G, B, 6, 12); //����ͼ���ڽӱ�
    printf("G���ڽӱ�:\n");
    DispAdj(G);

    for (i = 0; i < 6; i++) //��ʼ���ڽӾ��󣬷�ֹ�쳣
        for (j = 0; j < 6; j++)
            g.edges[i][j] = 0;

    printf("�����ڽӱ������ڽӾ���\n");
    ListToMat(G, g);
    for (i = 0; i < 6; i++)
    { //��ʼ���ڽӾ��󣬷�ֹ�쳣
        for (j = 0; j < 6; j++)
            printf("(%d,%d) = %d     ", i, j, g.edges[i][j]);
        printf("\n");
    }
    // DispMat(g);
    printf("�ڽӱ��0��ʼ��������ȱ����㷨:\n");
    DFS(G, 0);

    printf("\n�ڽӱ��0��ʼ�Ĺ�����ȱ����㷨:\n");
    BFS(G, 0);

    for (int i = 0; i < 6; i++)
        visited[i] = 0;
    printf("\n ��5 ��2 ��ȫ���ļ�·�� \n");
    FindAllPath(G, 5, 2, path, -1);

    printf("\n ���5 ��2 �ĳ���Ϊ3��·�� \n");
    PathlenAll(G, 5, 2, 3, path, -1);

    printf("\n����ͼG���ڽӱ�\n");
    DestroyAdj(G);
    system("pause");
    return 0;
}