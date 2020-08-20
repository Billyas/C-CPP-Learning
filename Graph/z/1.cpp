/**
 * ���ֲ������һ��Сbug
 * ����
 * 2020/5/19
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ElemType int
#define InfoType int
#define MAXV 100
#define INF INFINITY // ע��infinite�����ٸ������²���ȷ��������int�»س���int�����ֵ�����´���

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
//����ͼ���ڽӱ�
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) //���ڽӱ�������ͷ����ָ�����ó�ֵ
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++) //����ڽӾ�����ÿ��Ԫ��
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF) //����һ����
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //����һ�����p
                p->adjvex = j;                          //����ڽӵ�
                p->weight = A[i][j];                    //���Ȩ
                p->nextarc = G->adjlist[i].firstarc;    //����ͷ�巨������p
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
            //if (p->weight != 2147483647) //2147483647
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
    CreateAdj(G, A, n, e); //����ͼ���ڽӱ�
    printf("G���ڽӱ�:\n");
    DispAdj(G);
    printf("����ͼG���ڽӱ�\n");
    DestroyAdj(G);

    system("pause");
}
