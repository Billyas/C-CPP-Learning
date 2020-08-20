#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define ElemType char

typedef struct snode
{
    char data;
    struct snode *next;
}LinkStrNode;

void StrAssign(LinkStrNode *& s, char cstr[])
{
    int i=0;
    LinkStrNode *r ,*p;
    s=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    r=s;

    for(i=0;cstr[i]!='\0';i++){
        p=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        p->data=cstr[i];
        r->next=p; r=p;
    }

    r->next=NULL;
}

void DestoryStr(LinkStrNode *& s)
{
    LinkStrNode * pre=s, * p=s->next;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

void StrCopy(LinkStrNode *& s,LinkStrNode *& t)
{
    LinkStrNode * p=t->next, * q, * r;
    s=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    r=s;
    while(p!=NULL){
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }
}

bool StrEqual(LinkStrNode *s,LinkStrNode *t)
{
    LinkStrNode *p=s->next, *q=t->next;
    while(p!=NULL&&q!=NULL&&q->data==p->data){
        p=p->next;
        q=q->next;
    }
    if(p==NULL&&q==NULL) return true;
    else                 return false;
}

int StrLength(LinkStrNode *s)
{
    int i=0;
    LinkStrNode *p=s->next;
    while(p!=NULL){
        i++;
        p=p->next;
    }
    return i;
}

LinkStrNode *Concat(LinkStrNode *s,LinkStrNode *t)
{
    LinkStrNode *str, *p=s->next, *q, *r;
    str=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    r=str;
    while(p!=NULL)
    {
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;  r=q;
        p=p->next;
        
    }

    p=t->next;
    while(p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;

}

LinkStrNode* SubStr(LinkStrNode *s,int i,int j)
{
    int k;
    LinkStrNode*str, *p=s->next, *q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0 || i>StrLength(s) ||j<0 || i+j-1>StrLength(s))
        return str;
    
    for(k=1;k<i;k++)
        p=p->next;
    
    for(k=1;k<=j;k++)
    {
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }

    r->next=NULL;
    return str;
}

LinkStrNode *InsStr(LinkStrNode*s,int i,LinkStrNode *t)
{
    int k;
    LinkStrNode *str, *p=s->next, *p1=t->next,*q,*r;
    str=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    
    if(i<=0|| i>StrLength(s)+1)
        return str;
    for(k=1;k<=i;k++)
    {
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }

    while(p1!=NULL){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p1->data;
        r->next=q; r=q;
        p1=p1->next;
    }

    while(p!=NULL)
    {
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode* DelStr(LinkStrNode *s,int i,int j)
{
    int k;
    LinkStrNode *str, *p=s->next,*q, *r;
    str=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0 || i>StrLength(s) ||j<0||i+j-1>StrLength(s))
       return str;
    
    for(k=1;k<i;k++){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }

    for(k=0;k<j;k++)
        p=p->next;

    while(p!=NULL){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q; r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LinkStrNode *RepStr(LinkStrNode *s,int i,int j,LinkStrNode *t)
{
    int k;
    LinkStrNode *str, *p=s->next, *pl=t->next,*q, *r;
    str=(LinkStrNode*)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;

    if(i<=0 || i>StrLength(s) || j<0 || i+j-1> StrLength(s))
        return str;

    for(k=0; k< i-1;k++){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data; q->next=NULL;
        r->next=q; r=q;
        p=p->next;
    }

    for(k=0;k<j;k++)
       p=p->next;

    while(pl!=NULL){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=pl->data; q->next=NULL;
        r->next=q; r=q;
        pl=pl->next;
    }

    while(p!=NULL){
        q=(LinkStrNode*)malloc(sizeof(LinkStrNode));
        q->data=p->data; q->next=NULL;
        r->next=q; r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

void DispStr(LinkStrNode *s)
{
    LinkStrNode *p=s->next;
    while(p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

int main ()
{
    int i=0;
    char a[]={"luck  dog"},b[]={"you"};
    LinkStrNode* s,*p;
    StrAssign(s,a);
    StrAssign(p,b);
    DispStr(s);
    DispStr(p);

    if(StrEqual(s,p)) printf("yes");
    else printf("no\n");

    printf("%d\n",StrLength(s));
    
        DispStr(Concat(s,p));

        DispStr(SubStr(s,6,3));

        DispStr(InsStr(s,6,p));

        DispStr(DelStr(s,6,4));

        DispStr(RepStr(s,7,3,p));
   // StrCopy(s,p);


    system("pause");
    return 0;
}