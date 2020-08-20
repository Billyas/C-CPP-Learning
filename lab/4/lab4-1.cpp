/**
 * 凌少平
 * 2020/4/9
 * */
#include<stdio.h>
#include<stdlib.h>
#define ElemType Box
#define MaxSize  100
int mg[6][6]=
{
    {1,1,1,1,1,1},
    {1,0,0,0,0,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1}
};
typedef struct kk{
    int i,j;
    int pre;
}Box;
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

void print(SqQueue *qu,int front)
{
    int k=front , j ,ns=0;
    printf("\n");
    do{
        j=k;
        k=qu->data[k].pre;
        qu->data[j].pre=-1;
    } while (k!=0);

    printf("这条迷宫的最短路径如下：\n");
    k=0;

    while(k<MaxSize)
    {
        if(qu->data[k].pre==-1)
        {
            ns++;
            printf("\t(%d,%d)",qu->data[k].i,qu->data[k].j);
            if(ns%5==0)  printf("\n");
        }
        k++;
    }
    printf("\n");
    printf("一共走的步数是%d\n",ns);
}


bool mgpath1(int xi,int yi,int xe,int ye)
{
    Box e;
    int i,j,di,il,jl;
    SqQueue *qu;
    InitQueue(qu);
    e.i=xi; e.j=yi; e.pre=-1;
    enQueue(qu,e);
    mg[xi][yi]=-1;

    while(!QueueEmpty(qu))
    {
        deQueue(qu,e);
        i=e.i; j=e.j;
        if(i==xe&&j==ye)
        {
            print(qu,qu->front);
            DestoryQueue(qu);
            return true;
        }

        for(di = 0;di < 4; di++)
        {
            switch (di)
            {
                case 0: il=i-1; jl=j;   break;
                case 1: il=i;   jl=j+1; break;
                case 2: il=i+1; jl=j;   break;
                case 3: il=i,   jl=j-1; break;
            }
            if(mg[il][jl]==0)
            {
                e.i=il; e.j=jl;
                e.pre=qu->front;
                enQueue(qu,e);
                mg[il][jl]=-1;
            }
        }
    }
    DestoryQueue(qu);

    return false;
}

int main ()
{
    if(!mgpath1(1,1,4,4))
        printf("没有解！\n");
        system("pause");
    return 1;
}