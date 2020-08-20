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

int NumQueue(LinkQuNode*q)
{
    int i=1;
    DataNode* s=q->front;

        if(q->rear==NULL)
            return 0;
        if(q->front==q->rear)
           return 1;

    while(s!=q->rear){
        i++;
        s=s->next;
    }
    return i;
}
/*
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
}*/

int main ()
{
    int i=0,m,k;
    ElemType a[100],e;
    LinkQuNode *l;
    InitQueue(l);

    if(QueueEmpty(l)) printf("yes\n");
    else printf("no\n");

    scanf("%d\n",&m);
    for(i=0;i<m;i++)
    {
        if(i!=m-1) scanf("%c ",&e);
        else scanf("%c",&e);
         
        enQueue(l,e);    
    }

    deQueue(l,e);
    printf("%c\n",e);

    printf("%d\n",m-1);

    scanf("%d\n",&m);
    for(i=0;i<m;i++)
    {
        if(i!=m-1) scanf("%c ",&e);
        else scanf("%c",&e);
        enQueue(l,e);    
    }

    printf("%d\n",NumQueue(l));

    while(!QueueEmpty(l)){
        deQueue(l,e);
        printf("%c ",e);
    }

   DestoryQueue(l);
   system("pause");
   return 0;

}