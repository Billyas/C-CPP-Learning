/**
 * 凌少平
 * 2020/4/9
 **/
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
int count=1; 
int min=maxsize;
typedef struct U{      
    int i;
    int j;
    int di;
}Box;                //存储方块的坐标信息和已经走的方向

typedef struct {
    ElemType data[maxsize];
    int top;
}SqStack;           //栈的结构体

void InitStack(SqStack*& s);

void DestroyStack(SqStack*& s);

bool StackEmpty(SqStack*& s);

bool Push(SqStack*& s, ElemType e);

bool Pop(SqStack*& s, ElemType &e);

bool GetTop(SqStack* s, ElemType &e);   //以上是栈的基本操作

void mgpath();                          //计算并判断可行的步数

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

void mgpath()
{
    int i , j , di, k,find;
    Box e,path[maxsize];
    e.i=1; e.j=1; e.di=-1;
    SqStack* s;
    InitStack(s);

    Push(s,e);
    mg[1][1]=-1;

    while(s->top>-1)
    {
        GetTop(s,e);
         i=e.i;j=e.j;di=e.di;

         if(i==M && j==N){       //找到了出口，输出路径
            printf("M:  %d  ",count++);
            for(k=0;k<=s->top;k++){
                printf("(%d,%d)  ",s->data[k].i,s->data[k].j);
                if((k+1)%5==0)      //输出时每5个结点换一行
                    printf("\n\t");
            }
            printf("\n\n");

            if(s->top+1<min){       //比较输出最短路径
                for(k=0;k<=s->top;k++)
                    path[k]=s->data[k];
                min=s->top+1;
            }
            Pop(s,e);
            mg[e.i][e.j]=0;  //让该位置变为其他路径的可走结点
            GetTop(s,e);
            i=e.i;j=e.j;di=e.di;
        }

          find=0;
          GetTop(s,e);
        while(di<4 && find==0){     //找下一个可走结点
            di++;
            switch(di){
                case 0:i=e.i-1;j=e.j;break;   //上面
                case 1:i=e.i;j=e.j+1;break;   //右边
                case 2:i=e.i+1;j=e.j;break;   //下面
                case 3:i=e.i;j=e.j-1;break;   //左边
            }
            if(mg[i][j]==0)
                find=1;
        }

         if(find == 1){      //找到了下一个可走结点
            s->data[s->top].di=di;   //修改原栈顶元素的di值
            e.i=i; e.j=j; e.di=-1;  //下一个可走结点进栈
            Push(s,e);
            mg[i][j]=-1;        //避免重复走到该结点
        }else{
            Pop(s,e);         //让该位置变为其他路径的可走结点
            mg[e.i][e.j]=0;   //即回溯的过程，随着一个个的回溯，回到起点
        }

    
    }

        printf("最短路径如下:\n");
    printf("长度:  %d\n",min);
    printf("路径:  ");
    for(k=0;k<min;k++){
        printf("(%d,%d)  ",path[k].i,path[k].j);
        if((k+1)%5==0)      //输出时每5个结点换一行
            printf("\n\t");
    }
    printf("\n");

}

int main(){
    printf("迷宫所有路径如下:\n");
    mgpath();
    system("pause");
    return 0;
}