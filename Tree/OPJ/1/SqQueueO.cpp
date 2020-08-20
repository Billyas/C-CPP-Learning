# include "head.h"
//层次遍历时利用到的环状队列函数
void InitQueue(SqQueue *& q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

void DestoryQueue(SqQueue *& q)
{
    free(q);
}

bool QueueEmpty(SqQueue * q)
{
    return (q->front==q->rear);
}

bool enQueue (SqQueue *& q,ElemType e)
{
    if((q->rear+1)%maxsize==q->front)
        return false;
    q->rear=(q->rear+1)%maxsize;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *& q, ElemType &e)
{
    if(q->front==q->rear)
        return false;

     q->front=(q->front + 1)%maxsize;   
    e=q->data[q->front];

     return true;    
}
