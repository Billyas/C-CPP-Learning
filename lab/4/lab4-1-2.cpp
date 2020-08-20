# include <stdio.h>
# include <stdlib.h>
#define ElemType Box
#define maxsize 100

#define M 4   //行数
#define N 4     //列数
#define MaxSize    100     //栈最多元素个数
int mg[M+2][N+2]={      //一个迷宫，其四周要加上均为1的外框
    {1,1,1,1,1,1},
    {1,0,0,0,0,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1}
};

typedef struct U{
    int i;
    int j;
    int di;
}Box;

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

bool mgpath(int xi, int yi, int xe, int ye)
{
    Box path[maxsize], e;
    int i,j,di,il,jl,k,l=1,flag=0,p=1;
    bool find;
   
    SqStack *st;
    InitStack(st);
    e.i=xi; e.j=yi; e.di=-1;
    Push(st,e);

    mg[xi][yi]=-1;

    while(!StackEmpty(st))
    {
        GetTop(st,e);
        i=e.i; j=e.j; di=e.di;

        if(i==xe&&j==ye)
        {
            flag=1;
            printf("M %d: ",l++);
            k=0;

            while(!StackEmpty(st))
            {
                Pop(st,e);
                path[k++]=e;
            }

            while(k>=1)
            {
                k--;
                printf("\t(%d,%d)",path[k].i,path[k].j);
                if((k+2)%5==0)
                    printf("\n");
            }

            printf("\n");
           // DestroyStack(st);
            //return true;
          /*
            e.i=xi; e.j=yi; e.di=-1;
            Push(st,e);

            mg[xi][yi]=-1;
           mg[xe][ye]=0;
            Pop(st,e);
            Pop(st,e);
            il=e.i, jl=e.j; di=e.di;*/
        }

        find=false;

        while(di<4 &&!find)
        {
            di++;
            switch(di)
            {
                case 0: il=i-1; jl=j;   break;
                case 1: il=i;   jl=j+1; break;
                case 2: il=i+1; jl=j;   break;
                case 3: il=i;   jl=j-i; break;
            }
            if(mg[il][jl]==0) find=true;
        }

        if(find)
        {
            st->data[st->top].di=di;
            e.i=il; e.j=jl; e.di=-1;
            Push(st,e);
            mg[il][jl]=-1;
        }else
        {
            Pop(st,e);
            
            
            mg[e.i][e.j]=0;
        }
        

    }
    DestroyStack(st);

    if(flag) return true;
    return false;

    
}

int main ()
{
    if(!mgpath(1,1,M,N))
          printf("无解\n");

          for(int i=0;i<6;i++)
          {
              for(int j=0;j<6;j++)
              {
                  printf("%d ",mg[i][j]);
              }printf("\n");
          }
    system("pause");
    return 1;
}