//#pragma warning(disable:4996)
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#define ElemType char
#define ElemTypel double
#define maxsize 100

typedef struct {
    ElemType data[maxsize];
    int top;
}SqStack;

typedef struct {
    ElemTypel data[maxsize];
    int top;
}SqStackl;

void InitStack(SqStack*& s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
  if(s!=NULL) s->top = -1;
}

void InitStackl(SqStackl*& s)
{
    s = (SqStackl*)malloc(sizeof(SqStackl));
  if(s!=NULL) s->top = -1;
}

void DestroyStack(SqStack*& s)
{
    free(s);
}

void DestroyStackl(SqStackl*& s)
{
    free(s);
}

bool StackEmpty(SqStack*& s)
{
    return (s->top == -1);
}
bool StackEmptyl(SqStackl*& s)
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

bool Pushl(SqStackl*& s, ElemTypel e)
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

bool Popl(SqStackl*& s, ElemTypel &e)
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

bool GetTopl(SqStackl* s, ElemTypel &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    return true;
}

void trans(char *exp,char postexp[])  //转换为后缀表达式 
{
    char e;
    SqStack *Optr;
    InitStack(Optr);
    int i=0;

    while(*exp!='\0')
    {
        switch (*exp)
        {
            case '(':
                    Push(Optr,'(');
                    exp++;
                    break;
            case ')':
                Pop(Optr,e);//判断是不是负号，是的话进post
                while(e!='(')
                {
                    postexp[i++]=e;
                    Pop(Optr,e);
                }
                exp++;
                break;
            case '+':
            case '-': 
                 while(!StackEmpty(Optr))
                 {
                     GetTop(Optr,e);
                     if(e!='(')//&&postexp[i]=='#'
                     {
                         postexp[i++]=e;//加减已经是最低层次的运算了
                         Pop(Optr,e);   
                     }else 
                         break;
                 }
                 Push(Optr,*exp);
                 exp++;
                 break;  
            case '*': 
            case '/': 
                while(!StackEmpty(Optr))
                {
                    GetTop(Optr,e);
                    if(e=='*'||e=='/'||e=='^')
                    {
                        postexp[i++]=e;
                        Pop(Optr,e);
                    }else
                         break;
                }
                Push(Optr,*exp);
                exp++;
                break;
            case '^': 
                while(!StackEmpty(Optr))
                {
                    GetTop(Optr,e);
                    if(e=='^')
                    {
                        postexp[i++]=e;
                        Pop(Optr,e);
                    }else
                         break;
                }
                Push(Optr,*exp);
                exp++;
                break;
            case ' ':
                exp++;
                break;
            default: 
                while(*exp>='0' && *exp<='9')
                {
                    postexp[i++]= *exp;
                    exp++;
                }
                postexp[i++]='#';
                break;
                     
        }  
    }

    while(!StackEmpty(Optr))
    {
        Pop(Optr,e);
        postexp[i++]=e;
    }
    postexp[i] = '\0';
    DestroyStack(Optr);
}

double compvalue(char *postexp)
{
    ElemTypel d,a,b,c,e;
    SqStackl * Opnd;
    InitStackl(Opnd);

    while(*postexp!='\0')
    {   
        switch( *postexp)
        {
            case '+': 
                  Popl(Opnd,a);
                  Popl(Opnd,b);
                  c = a + b;
                  Pushl(Opnd,c);
                  break;
            case '-':
                  Popl(Opnd,a);
                  Popl(Opnd,b);
                  c = b - a;
                  Pushl(Opnd,c);
                  break;
            case '*':
                  Popl(Opnd,a);
                  Popl(Opnd,b);
                  c = a * b;
                  Pushl(Opnd,c);
                  break;
            case '/': 
                  Popl(Opnd,a);
                  Popl(Opnd,b);
                  if(a!=0)
                  {  c = b / a;
                     Pushl(Opnd,c);
                     break;
                  }else
                  {  printf("\n\t除零错误！\n");
                     exit(0);
                  }
                  break;
            case '^': 
                  Popl(Opnd,a);
                  Popl(Opnd,b);
                  c = pow(b,a);
                  Pushl(Opnd,c);
                  break;
            default: 
                d = 0;
                while(*postexp>='0'&& *postexp<='9')
                {
                    d=10*d + *postexp-'0';
                    postexp++;
                }
                Pushl(Opnd,d);
                break;
        }
        postexp++;
     
    }
    GetTopl(Opnd,e);
    DestroyStackl(Opnd);
    return e;
}

int main()
{
    int i=0,m;
    double e;
    char exp[660],postexp[660];
 //   scanf("%d\n",&m);
   //   scanf("%s",exp);  
 //   for(i=0;i<m;i++){
        // gets(exp);////////////////////////////////////////////////////////////
    trans(exp,postexp);
        
 //   }

//    scanf("%s",exp);


    while(postexp[i]!='\0'){
        printf("%c",postexp[i++]);
    }
    e=compvalue(postexp);
    printf("结果是%.0f\n",e);
    system("pause");

    return 0;

}

//31 * ( 5 - ( -3 + 25 ) ) + 70 ^ 2