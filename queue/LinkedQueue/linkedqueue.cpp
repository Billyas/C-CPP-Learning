#include <stdio.h>
#include <stdlib.h>
#define ElemType char

typedef struct qnode{
    ElemType data;
    struct qnode *next;
}DataNode;

typedef struct
{
    DataNode* front;
    DataNode* rear;
}LinkQuNode;

void InitQueue(LinkQuNode*&q)
{
    q=(LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}

void DestoryQueue(LinkQuNode*& q)
{
    DataNode *pre=q->front, *p;
    
    if(pre!=NULL){
        p = pre->next;
        if(p!=NULL){
            free(pre);
            pre=p, p=p->next;
        }
        free(pre);
    }
    free(q);
}

bool QueueEmpty(LinkQuNode* q)
{
    return (q->rear==NULL);
}

void enQueue(LinkQuNode*& q, ElemType e)
{
    DataNode* p;
    p=(DataNode*)malloc(sizeof(DataNode));

    p->data=e;
    p->next=NULL;
    
    if(q->rear==NULL)
        q->front=q->rear=p;
    else{
        q->rear->next=p;
        q->rear=p;
    }
}

bool deQueue(LinkQuNode*&q,ElemType& e)
{
    DataNode*t;
    if(q->rear==NULL)
        return false;
    t=q->front;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
        q->front=q->front->next;

        e=t->data;
        free(t);

     return true;
}

int main ()
{
    int i=0;
    char a[]={"helloworld"},e;
    LinkQuNode*L;

    InitQueue(L);

    for(i = 0; a[i]!='\0'; i++){
        enQueue(L,a[i]);
    }

    for(i = 0; a[i]!='\0'; i++){
        deQueue(L,e);
        printf("%c",e);
    }

    printf("\n");
    DestoryQueue(L);
    putchar(10);
  //  putchar(13);
    system("pause");
    return 0;
}