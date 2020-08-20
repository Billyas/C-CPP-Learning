/**
 * ����ƽ
 * 2020/4/9
 **/
# include <stdio.h>
# include <stdlib.h>
#define ElemType Box
#define maxsize 100
#define M 4   //����
#define N 4     //����
#define MaxSize    100     //ջ���Ԫ�ظ���
int mg[M+2][N+2]={      //һ���Թ���������Ҫ���Ͼ�Ϊ1�����
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
}Box;                //�洢�����������Ϣ���Ѿ��ߵķ���

typedef struct {
    ElemType data[maxsize];
    int top;
}SqStack;           //ջ�Ľṹ��

void InitStack(SqStack*& s);

void DestroyStack(SqStack*& s);

bool StackEmpty(SqStack*& s);

bool Push(SqStack*& s, ElemType e);

bool Pop(SqStack*& s, ElemType &e);

bool GetTop(SqStack* s, ElemType &e);   //������ջ�Ļ�������

void mgpath();                          //���㲢�жϿ��еĲ���

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

         if(i==M && j==N){       //�ҵ��˳��ڣ����·��
            printf("M:  %d  ",count++);
            for(k=0;k<=s->top;k++){
                printf("(%d,%d)  ",s->data[k].i,s->data[k].j);
                if((k+1)%5==0)      //���ʱÿ5����㻻һ��
                    printf("\n\t");
            }
            printf("\n\n");

            if(s->top+1<min){       //�Ƚ�������·��
                for(k=0;k<=s->top;k++)
                    path[k]=s->data[k];
                min=s->top+1;
            }
            Pop(s,e);
            mg[e.i][e.j]=0;  //�ø�λ�ñ�Ϊ����·���Ŀ��߽��
            GetTop(s,e);
            i=e.i;j=e.j;di=e.di;
        }

          find=0;
          GetTop(s,e);
        while(di<4 && find==0){     //����һ�����߽��
            di++;
            switch(di){
                case 0:i=e.i-1;j=e.j;break;   //����
                case 1:i=e.i;j=e.j+1;break;   //�ұ�
                case 2:i=e.i+1;j=e.j;break;   //����
                case 3:i=e.i;j=e.j-1;break;   //���
            }
            if(mg[i][j]==0)
                find=1;
        }

         if(find == 1){      //�ҵ�����һ�����߽��
            s->data[s->top].di=di;   //�޸�ԭջ��Ԫ�ص�diֵ
            e.i=i; e.j=j; e.di=-1;  //��һ�����߽���ջ
            Push(s,e);
            mg[i][j]=-1;        //�����ظ��ߵ��ý��
        }else{
            Pop(s,e);         //�ø�λ�ñ�Ϊ����·���Ŀ��߽��
            mg[e.i][e.j]=0;   //�����ݵĹ��̣�����һ�����Ļ��ݣ��ص����
        }

    
    }

        printf("���·������:\n");
    printf("����:  %d\n",min);
    printf("·��:  ");
    for(k=0;k<min;k++){
        printf("(%d,%d)  ",path[k].i,path[k].j);
        if((k+1)%5==0)      //���ʱÿ5����㻻һ��
            printf("\n\t");
    }
    printf("\n");

}

int main(){
    printf("�Թ�����·������:\n");
    mgpath();
    system("pause");
    return 0;
}