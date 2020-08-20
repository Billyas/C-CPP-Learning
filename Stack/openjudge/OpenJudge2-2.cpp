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
    int i=0;
    SqStack*s;
    char a[100],e;
    InitStack(s);
    scanf("%s",a);
    
    while(a[i]){
        switch(a[i])
        {
            case '{':
            case '[':
            case '(': Push(s,a[i++]); break;
            case '}': {
                
            }; break;
            case ']':;break;

        }
    }

}

//{{{{)))
//{([)]}