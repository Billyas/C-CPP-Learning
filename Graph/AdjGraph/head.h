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
#define INF 214748364 ///一定不要设成int的最大值，因为后面的floyd算法会进行加法运算，会导致结果溢出变成负值，int_max=2147483647
#define INFINITE INF
/////////////////////////////////////////////////
//邻接表的结构体定义
typedef struct ANode
{
    int adjvex;            //该边的邻接点的编号，即有向边指向的顶点编号
    struct ANode *nextarc; //指向下一条边的指针
    int weight;            //边的相关的信息，如权值
} ArcNode;                 //边节点的类型

typedef struct Vnode
{
    InfoType info;     //顶点的其他信息
    int count;         //存放顶点入度
    ArcNode *firstarc; //指向第一个边节点
} VNode;               //邻接表的头节点的结构体类型

typedef struct
{
    VNode adjlist[MAXV]; //头节点的数组
    int n, e;            //图的顶点数和边数
} AdjGraph;              //整个邻接表的数据结构体类型
//////////////////////////////////////////////////
//邻接矩阵的结构体
typedef struct S
{
    int no;        //顶点的编号
    InfoType info; //顶点的其他信息
} VertexType;      //顶点的类型

typedef struct SS
{
    int edges[MAXV][MAXV]; //邻接矩阵的数组
    int n, e;              //图的顶点数和边数
    VertexType vexs[MAXV]; //存放顶点信息
} MatGraph;
///////////////////////////////////////////////////
typedef struct SSS
{
    ElemType data[maxsize];
    int front;
    int rear;
} SqQueue; //队列的结构体
////////////////////////////////
//Kruskal算法需要的简化图的结构体
typedef struct head
{
    int u; //边的起始顶点
    int v; //边的终止顶点
    int w; //边的权值
} Edge;
///////////////////////////////

int visited[MAXV] = {0};
///////////////////////////////
//队列的操作函数集合
//由于队列的函数在另一个文件
//所以需要声明一下
void InitQueue(SqQueue *&q);
void DestoryQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, ElemType e);
bool deQueue(SqQueue *&q, ElemType &e);
/////////////////////////////////////////////////////////////////
void Dispath(MatGraph g, int dist[], int path[], int s[], int v);
void DispathFloyd(MatGraph g, int A[][MAXV], int path[][MAXV]);
#endif