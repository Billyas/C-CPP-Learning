# include <stdio.h>
# include <stdlib.h>
#define ElemType char
#define maxsize 100
typedef struct{
    ElemType data[maxsize];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *& s)
{
    return (s->top==-1);
}

bool Push(SqStack *&s,ElemType e)
{
    if(s->top==maxsize-1)
        return false;
    
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
        return false;

    e=s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack * s,ElemType &e)
{
    if(s->top==-1)
        return false;

    e=s->data[s->top];
    return true;    
}

int main()
{
    int i=0;
    SqStack *s;

    char a[16]={"Hello World!!!!"},e;
    
    InitStack(s);
    s->top=0;
    for(i = 0; i < 15; i++){
         Push(s,a[i]);
    }



    for(i = 0;i < 15; i++){
        Pop(s,e);
        printf("%c ",e);
    }
    printf("\n");
    system("pause");
    return 0;
}