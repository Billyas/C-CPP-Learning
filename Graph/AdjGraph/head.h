#ifndef _HEAD_H
#define _HEAD_H
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
void Dispath(MatGraph g, int dist[], int path[], int s[], int v);
void DispathFloyd(MatGraph g, int A[][MAXV], int path[][MAXV]);
#endif