# include <stdio.h>
# include <stdlib.h>
# define M 4
# define N 4
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

TSMatrix A,B;

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

bool Assign(TSMatrix t,ElemType &x,int i,int j)  //i= ��  ��j=�У����Ҷ�Ӧλ�õ�Ԫ��
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

void TranTat(TSMatrix t, TSMatrix &tb)  //�����ת�ú�����tb��ת�ú�ľ���
{
    int k,k1=0,v; //k1��¼tb����Ԫ�صĸ���
    tb.rows=t.cols; tb.cols=t.rows; tb.nums=t.nums;

    if(t.nums!=0){
        for(v=0;v<t.cols;v++)  //ÿһ��ת��
            for(k=0; k<t.nums; k++)
                if(t.data[k].c==v)
                {
                    tb.data[k1].r=t.data[k].c;
                    tb.data[k1].c=t.data[k].r;
                    tb.data[k1].d=t.data[k].d;
                    k1++;
                }
    }
}

void r1()//����������Ԫ��
{
    int a[4][4]={1, 0, 3, 0,
                 0, 1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 1, 1};
    int b[4][4]={3, 0, 0, 0,
                 0, 4, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 2};
    CreateMat(A,a);
    CreateMat(B,b);
    printf("��һ����Ԫ�飺\n");
    DispMat(A);
    printf("\n�ڶ�����Ԫ�飺\n");

    DispMat(B);
}

void r2()
{
    TSMatrix go; //ת�ú�ľ���
    TranTat(A, go);
    printf("\n����A��ת�þ������£�\n");
    DispMat(go);
    TranTat(B,go);
    printf("\n����B��ת�þ������£�\n");
    DispMat(go);

}

void r3()
{
    TSMatrix p;
    int i, j, xa=0, xb=0, sum[M][N]={0};

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            Assign(A, xa, i, j);
            Assign(B, xb, i, j);

            if(xa&&xb)
                sum[i][j]=xa+xb;
            else if(xa!=0&&xb==0)
                sum[i][j]=xa;
            else if(xa==0&&xb!=0)
                sum[i][j]=xb;
                
        }

        CreateMat(p,sum);
        printf("����A+B�Ľ�����£�\n");
        DispMat(p);
             
}

void r4()
{
    TSMatrix l;
    int i, j, c, r, xa, xb, res[M][N], re=0;

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
             for(c=0; c<M; c++)   //A������г�B�������
             {
                 Assign(A,xa,i,c);
                 Assign(B,xb,c,j);
                 re += xa*xb;
             }
             res[i][j]=re;
             re=0;    //��������
        }

        CreateMat(l,res);
        printf(" \n�˷��Ľ�����£�\n");
        DispMat(l);
}

void InPut()
{
    int n, i, j,  a[M][N]={0}, b[M][N]={0};
    CreateMat(A,a); CreateMat(B,b);//��ʼ����Ԫ��
    printf("����������������N��");
    scanf("%d",&n);
    printf("\n\n�������һ�����󣨶�ά������ʽ����");
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

            printf("\n\n������ڶ������󣨶�ά������ʽ����");
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&b[i][j]);

    CreateMat(A,a);
    CreateMat(B,b);
    printf("\n\n��һ���������£�");
    DispMat(A);
    printf("\n\n�ڶ����������£�");
    DispMat(B);
}

void Menu()
{
    printf("*******************************\n");
    printf("       ϡ����������   \n");
    printf("*******************************\n\n");
    printf("        ���˵�               \n");
    printf("     1.��������ϡ�����       \n");
    printf("     2.������ת��           \n");
    printf("     3.�����ļӷ�           \n");
    printf("     4.�����ĳ˷�           \n");
    printf("     5.�˳�ϵͳ               \n");
    printf("-------------------------------\n");
}

int main ()
{
    int i=0,j,n;
    Menu();
    printf("���������ѡ��");
    scanf("%d",&j);

    while(j!=5)
    {
        switch(j) {
            case 1:   r1()        ; break;

            case 2:   r2()        ; break;

            case 3:   r3()        ; break;
            
            case 4:   r4()        ; break;

            default:  break;
        }
        
         printf("\n\n���������ѡ��"); 
         scanf("%d",&j);
    }
    


    system("pause");
    return 0;
}

/*
�������һ�����󣨶�ά������ʽ����
1 0 3 0
0 1 0 0
0 0 1 0
0 0 1 1


������ڶ������󣨶�ά������ʽ����
3 0 0 0
0 4 0 0
0 0 1 0
0 0 0 2
*/