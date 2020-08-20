# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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

bool Match(char exp[],int n)
{ 
    SqStack *ls;

    InitStack(ls);
    int i=0;
    ElemType e;
    bool flag=true;
    while (i<n && flag)
    {   if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            Push(ls,exp[i]); //遇到'('、'['或'{',则将其进栈
        if (exp[i]==')') //遇到')',若栈顶是'(',则继续处理,否则以不配对返回
        { if (GetTop(ls,e))
                { if (e=='(') Pop(ls,e);
                 else flag=false;
                }
            else flag=false;
        }
        if (exp[i]==']') //遇到']',若栈顶是'[',则继续处理,否则以不配对返回
        { if (GetTop(ls,e))
                { if (e=='[') Pop(ls,e);
                  else flag=false;
                }
            else flag=false;
        }
        if (exp[i]=='}') //遇到'}',若栈顶是'{',则继续处理,否则以不配对返回
        { if (GetTop(ls,e))
            { if (e=='{') Pop(ls,e);
              else flag=false;
            }
        else flag=false;
        }
        i++;
    }
   
   if (!StackEmpty(ls)) flag=false; //若栈不空,则不配对
    DestroyStack(ls);
    return flag;
}

int main ()
{
    SqStack*s;
    int i=0;
    char a[100],e;
    scanf("%s",a);

    InitStack(s);
 /*   for(i = 0; a[i] != '\0' ; i++)
    {
        if( a[i]=='{'||a[i]=='('||a[i]=='[')
            Push(s,a[i]);
        else if(a[i]==')'&&GetTop(s,e)&&e=='(')
            Pop(s,e);
        else if(a[i]==']'&&GetTop(s,e)&&e=='[')
            Pop(s,e);
        else if(a[i]=='}'&&GetTop(s,e)&&e=='{')
            Pop(s,e);

         
    }
    if(!StackEmpty(s)){
        GetTop(s,e);
        if(e=='{'||e=='['||e=='(')
          printf("Extra left brackets");
        else if(e=='}'||e==']'||e==')')
          printf("Extra right brackets");
        else  
          printf("Brackets not match");
    }
        
    else if(StackEmpty(s))
        printf("Brackets match");
*/     if(Match(a,strlen(a)))
            printf("Brackets match");
       else printf("Brackets not match");
        

        system("pause");
        return 0;
}
//{{{{)))
//{([)]}