#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define maxsize 100

typedef struct SSS{
    ElemType data[maxsize];
    int front;
    int rear;
}SqQueue;

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

int main ()
{
    int i=0;
    ElemType e,m=' ';


    SqQueue *L;
    InitQueue(L);

    if(QueueEmpty(L)) printf("yes\n");
    else          printf("no\n");

    while((e=getchar())!='\n'){
          enQueue(L,e);
    } 

    enQueue(L,m);
 
    deQueue(L,e);
    printf("%c\n",e);

    while((e=getchar())!='\n'){
        enQueue(L,e);
    }

    while(!QueueEmpty(L)){
        deQueue(L,e);
        putchar(e);
    }
    DestoryQueue(L);
    putchar(10);
    system("pause");
      return 0;
} 


 /*do{
        if(e!='\n')
        { getchar();
          enQueue(L,e);
        }else
             break;
        e=getchar();
    }while(1);
*/
   /* while(*p!='\0'){
        enQueue(L,*p++);
    }*/    /*     e=getchar();
    do{
        if(e!='\n')
        { getchar();
          enQueue(L,e);
        }else
             break;
        e=getchar();
    }while(1);*/
