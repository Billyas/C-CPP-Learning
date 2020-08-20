#include "head.h"

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    if (s != NULL)
        s->top = -1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *&s)
{
    return (s->top == -1);
}

bool Push(SqStack *&s, ElemType e)
{
    if (s->top == maxsize - 1)
        return false;

    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    return true;
}
//在栈数组中寻找离开停车场的车辆
int ElemEmpty(SqStack *s, char str[])
{
    int i;
    for (i = 0; i <= s->top; i++)
    {
        if (strcmp(s->data[i].a, str) == 0)
            return (i + 1);
    }
    return 0;
}