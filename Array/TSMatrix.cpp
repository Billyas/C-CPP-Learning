# include <stdio.h>
# include <stdlib.h>
# define M 10
# define N 10
# define MaxSize 200
# define ElemType int
typedef struct 
{
    int r;//�к�
    int c;//�к�
    ElemType d;//Ԫ��ֵ
}TupNode;

typedef struct 
{
    int rows;//����
    int cols;//����
    int nums;//�������
    TupNode data[MaxSize];
}TSMatrix;

void CreateMat(TSMatrix &t, ElemType A[M][N])
//��һ����άϡ����󴴽���Ԫ���ʾ
{
    int i,j;
    t.rows=M; t.cols=N; t.nums=0;
    for(i = 0; i < M; i++ )
    {
        for(j = 0; j < N; j++)
            if(A[i][j]!=0)
            {
                t.data[t.nums].r=i; t.data[t.nums].c=j;
                t.data[t.nums].d=A[i][j]; t.nums++;
            }
    }
}

bool Value (TSMatrix &t, ElemType x, int i, int j)
//��Ԫ��ĸ�ֵ�������޸�ֵ�����ֵ
{
    int k=0,kl;
    if(i>t.rows||j>t.cols)
        return false;
    while(k<t.nums&&i>t.data[k].r) k++;   //����i�еķ���Ԫ��
    while(k<t.nums&&i==t.data[k].r&&j>t.data[k].c) k++;

    if(t.data[k].r==i&&t.data[k].c==j)
        t.data[k].d=x;
    else
    {
        for(kl=t.nums-1;kl>=k;kl--){
            t.data[kl+1].r=t.data[kl].r;
            t.data[kl+1].c=t.data[kl].c;
            t.data[kl+1].d=t.data[kl].d;
        }
        t.data[k].r=i; t.data[k].c=j; t.data[k].d=x;
        t.nums++;
    }
    return true;

}

bool Assign(TSMatrix t,ElemType &x,int i,int j)
{
    int k=0;
    if(i>t.rows||j>t.cols)
        return false;
    while(k<t.nums&&i>t.data[k].r) k++;   //����i�еķ���Ԫ��
    while(k<t.nums&&i==t.data[k].r&&j>t.data[k].c) k++;

    if(t.data[k].r==i&&t.data[k].c==j)
        x=t.data[k].d;
    else
        x=0;
    return true;
}

void DispMat(TSMatrix t)
{
    int k;
    if(t.nums<=0)
        return;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("\t--------------------------------\t\n");

    for(k=0; k<t.nums; k++)
        printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
}

int main ()
{
    int i=0,j=0,x;
    int a[10][10]={{1,1,1,1,1,1,1,1,1,1},
                {2,2,2,2,2,2,2,2,2,2},
                {3,3,3,3,3,3,3,3,3,3},
                {4,4,4,4,4,4,4,4,4,4},
                {5,5,5,5,5,5,5,5,5,5},
                {6,6,6,6,6,6,6,6,6,6},
                {7,7,7,7,7,7,7,7,7,7},
                {8,8,8,8,8,8,8,8,8,8},
                {9,9,9,9,9,9,9,9,9,9},
                {0,0,0,0,0,0,0,0,0,0}};

    TSMatrix t;
    CreateMat(t,a);
    DispMat(t);
    x=666;
    Value(t,x,9,9);
    DispMat(t);

    Assign(t,x,9,9);
    printf("\n��9��9��λ�õ�Ԫ����%d\n",x);

    system("pause");
    return 0;
}