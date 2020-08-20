#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ElemType char
#define maxsize 100
typedef struct slinknode{
    ElemType data;
    struct slinknode* next;
}LinkStNode;

void InitStack(LinkStNode*&s)//初始化栈
{
    s=(LinkStNode*)malloc(sizeof(LinkStNode));
    s->next=NULL;
}

int DataLink(LinkStNode*s)
{
    int i=0;
    LinkStNode*p=s->next;
    while(p!=NULL){
         i++;
         p=p->next;
    }
    return i;
}

void DestoryStack(LinkStNode*&s)
{
    LinkStNode * pre=s, * p= s->next;

    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}

bool StackEmpty(LinkStNode*& s)
{
    return(s->next==NULL);
}

void Push(LinkStNode*& s,ElemType e)//类似于头插法
{
    LinkStNode*p;
    p=(LinkStNode*)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=s->next;
    s->next=p;
}

bool Pop(LinkStNode*& s,ElemType &e)
{
    LinkStNode* p;
    if(s->next==NULL)
        return false;

    p=s->next;
    e=p->data;
    s->next=p->next;
    
    free(p);
    return true;    
 
}

bool GetTop(LinkStNode*& s,ElemType &e)
{
    if(s->next==NULL)
        return false;

    e=s->next->data;
    return true;    
}
/*
int main()
{
    char a[]={"this is a stack which via by linknode ok"},e;
    int i=0;
    LinkStNode*s,*p;
    InitStack(s);

    for(i = 0; a[i] != '\0'; i++ ){
        Push(s,a[i]);
    }
    
    GetTop(s,e);
    printf("%c\n",e);
  system("pause");
}*/
int main()
{
    int i=0,m,k=0;

    LinkStNode*s;
    InitStack(s);
    char a[maxsize],e;
    scanf("%d\n",&m);

    for(i = 0;i < m; i++){
       if(i!=m-1) scanf("%c ",&a[i]);
       else scanf("%c",&a[i]);
    }


    
    if(StackEmpty(s)){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    
    for(i = 0;i < m; i++){
        Push(s,a[i]);
    }

    if(StackEmpty(s)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    printf("%d\n",DataLink(s));

    for(i = m-1;i >= 0; i--){
       if(i!=0) printf("%c ",a[i]);
       else      printf("%c",a[i]);   
    }

    printf("\n");

    for(i = 0;i < m; i++){
        Pop(s,e);
      if(i!=m-1)  printf("%c ",e);
      else printf("%c",e);
    }
    printf("\n");

    if(StackEmpty(s)) printf("yes\n");
    else printf("no\n");

    DestoryStack(s);

    system("pause");
    return 0;
}