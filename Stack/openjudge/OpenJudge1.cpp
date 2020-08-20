# include <stdio.h>
# include <stdlib.h>
#define ElemType char
#define maxsize 100
typedef struct {
    ElemType data[maxsize];
    int top;
}SqStack;
void InitStack(SqStack*& s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
  if(s!=NULL) s->top = -1;
}

void DestroyStack(SqStack*& s)
{
    free(s);
}

bool StackEmpty(SqStack*& s)
{
    return (s->top == -1);
}

bool Push(SqStack*& s, ElemType e)
{
    if (s->top == maxsize - 1)
        return false;

    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack*& s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack* s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    return true;
}

int main()
{
    int i=0,m,k=0;
    SqStack*s;
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

    printf("%d\n",s->top+1);

    for(i = m-1;i >= 0; i--){
       if(i!=0) printf("%c ",s->data[i]);
       else      printf("%c",s->data[i]);   
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

    DestroyStack(s);

    system("pause");
    return 0;

}