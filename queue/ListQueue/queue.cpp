#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define MaxSize  100
typedef struct ss{
    ElemType data[MaxSize];
    int front,rear;   
}SqQueue;

void InitQueue(SqQueue* &q)
{ 
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}

void DestoryQueue(SqQueue* &q)
{
    free(q);
}

bool QueueEmpty(SqQueue* q)
{
    return (q->front==q->rear);
}

bool enQueue(SqQueue*& q,ElemType e)
{
    if(q->rear==MaxSize-1)
        return false;

    q->rear++;
    q->data[q->rear]=e;
    return true;

}

bool deQueue(SqQueue*& q,ElemType &e)
{
    if(q->rear==q->front)
        return false;
    q->front++;
    e=q->data[q->front];
    return true;    
}

int main()
{
    int i=0;
    ElemType a[]={"good"},e;
    SqQueue*l;
    InitQueue(l);

    for(i = 0;a[i] != '\0'; i++){
        enQueue(l,a[i]);
    }

    while(!QueueEmpty(l)){
        deQueue(l,e);
        printf("%c",e);
    }
    printf("\n");

    DestoryQueue(l);
    system("pause");
    return 0;


}