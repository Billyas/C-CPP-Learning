#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MVNum 100
typedef int Status;
typedef char VerTexType;
typedef char OtherInfo;
int indegree[MVNum] = {0};
//����ջ
typedef struct StackNode
{
    int data;
    StackNode *next;
} StackNode, *StackList;
//��ջ����
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
//��ջ������
StackList Push(StackList S, int e)
{
    StackList p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return S;
}
//�ڽӱ�������ͼ��ʵ��
//�߽��
typedef struct ArcNode
{                     //������
    int adjvex;       //�ڽӱ�����������ʵ��
    ArcNode *nextarc; //ָ����һ���ߵ�ָ��
    OtherInfo info;   //�ͱ���ص���Ϣ
} ArcNode;

//������Ϣ
typedef struct VNode
{                        //ͷ���
    VerTexType data;     //������Ϣ
    ArcNode *firstarc;   //ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum]; //AdjList ��ʾ�ڽӱ�����

typedef struct
{
    AdjList vertices;   //�ڽӱ�ͷ�������
    int vexnum, arcnum; //ͼ�Ķ������ͻ���
} ALGraph;
//��������ͼ��

int LocateVex(ALGraph *G, VerTexType v) //G��������ͼ��vҪ��ͼ�ж�λ�Ķ���
{
    int i;
    for (i = 0; i < (G->vexnum); i++)
    {
        if (v == G->vertices[i].data)
            return i; //��������򷵻���ͷ��������е��±ꣻ���򷵻�
    }
}

void CreateUDG(ALGraph *G)
{
    int i, j, k;
    VerTexType v1, v2;
    ArcNode *p1;
    printf("�����ܽڵ����ͻ�����"); //G��������ͼ��vҪ��ͼ�ж�λ�Ķ���
    scanf("%d %d", &G->vexnum, &G->arcnum);
    fflush(stdin); //��������뻺������
    printf("��������ڵ��ֵ��");
    for (i = 0; i < G->vexnum; i++) //�ڽӱ��ʼ��

    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k = 0; k < G->arcnum; k++)
    {
        fflush(stdin); //��������뻺������
        printf("���ȵ������������ڵ㣺");
        scanf("%c %c", &v1, &v2);
        i = LocateVex(G, v1); //���������������ڶ��������е�λ��
        j = LocateVex(G, v2);
        p1 = (ArcNode *)malloc(sizeof(ArcNode)); //���ڽӱ�ָ�����ռ�
        p1->adjvex = j;                          //��ֵ��p->adjvexָ��Ķ�����
        p1->nextarc = G->vertices[i].firstarc;   //nextarcָ����ָ��i����firstarcָ����
        G->vertices[i].firstarc = p1;            //����i�ĵ�һ��ָ��ָ��
        indegree[j]++;                           //vi->vj, vj��ȼ�1
    }
}
//���������㷨
Status TopologicalSort(ALGraph G, int *topo)
{ //������ջָ��S��������ָ��NULL��������нڵ����Ƿ������Ϊ0�Ľڵ㣬����У����ջ��
    int i, m, k;
    StackList S; //������ջָ��S��������ָ��NULL��
    ArcNode *p;
    S = NULL;
    for (i = 0; i < G.vexnum; i++) //������нڵ����Ƿ������Ϊ0�Ľڵ㣬��������ջ��
    {
        if (!indegree[i]) //�����鲻Ϊ��ʱ
            S = Push(S, i);
    }         //���Ϊ��ȥ���
    m = 0;    //��¼topu�������
    while (S) //ջ��Ϊ�յ�ʱ���ȳ�ջ��ȡ��ջ��Ԫ�أ��������¼��topo[]������
    {
        S = Pop(S, &i);
        topo[m] = i;
        ++m;
        p = G.vertices[i].firstarc; //ָ��p ָ���һ���ߵĽڵ�
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k];
            if (indegree[k] == 0)
                S = Push(S, k);
            p = p->nextarc;
        }
    }
    topo[m] = -1;     // Ϊ-1ʱ����
    if (m < G.vexnum) // topo[]������Ԫ���Ƿ��Ѿ��ﵽ�ڵ�����
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
        printf("����ͼ���޻�\n    ������������Ϊ��");
        for (i = 0; topo[i] != -1; i++)
        {
            printf("%c ", G.vertices[topo[i]].data);
        }
    }
    else
        printf("�л�������������");
    printf("\n");
    system("pause");
    return 0;
}
