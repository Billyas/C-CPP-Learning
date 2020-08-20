# include <stdio.h>
# include <stdlib.h>
# define M 4
# define N 4
# define MaxSize 200
# define ElemType int
typedef struct 
{
    int r;//行号
    int c;//列号
    ElemType d;//元素值
}TupNode;

typedef struct 
{
    int rows;//行数
    int cols;//列数
    int nums;//非零个数
    TupNode data[MaxSize];
}TSMatrix;

TSMatrix A,B;

void CreateMat(TSMatrix &t, ElemType A[M][N])
//从一个二维稀疏矩阵创建三元组表示
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
//三元组的赋值，包括修改值和添加值
{
    int k=0,kl;
    if(i>t.rows||j>t.cols)
        return false;
    while(k<t.nums&&i>t.data[k].r) k++;   //查找i行的非零元素
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

bool Assign(TSMatrix t,ElemType &x,int i,int j)  //i= 行  ，j=列，查找对应位置的元素
{
    int k=0;
    if(i>t.rows||j>t.cols)
        return false;
    while(k<t.nums&&i>t.data[k].r) k++;   //查找i行的非零元素
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

void TranTat(TSMatrix t, TSMatrix &tb)  //矩阵的转置函数，tb是转置后的矩阵
{
    int k,k1=0,v; //k1记录tb非零元素的个数
    tb.rows=t.cols; tb.cols=t.rows; tb.nums=t.nums;

    if(t.nums!=0){
        for(v=0;v<t.cols;v++)  //每一列转置
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

void r1()//创建两个三元组
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
    printf("第一个三元组：\n");
    DispMat(A);
    printf("\n第二个三元组：\n");

    DispMat(B);
}

void r2()
{
    TSMatrix go; //转置后的矩阵
    TranTat(A, go);
    printf("\n矩阵A的转置矩阵如下：\n");
    DispMat(go);
    TranTat(B,go);
    printf("\n矩阵B的转置矩阵如下：\n");
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
        printf("矩阵A+B的结果如下：\n");
        DispMat(p);
             
}

void r4()
{
    TSMatrix l;
    int i, j, c, r, xa, xb, res[M][N], re=0;

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
             for(c=0; c<M; c++)   //A矩阵的行乘B矩阵的列
             {
                 Assign(A,xa,i,c);
                 Assign(B,xb,c,j);
                 re += xa*xb;
             }
             res[i][j]=re;
             re=0;    //重新置零
        }

        CreateMat(l,res);
        printf(" \n乘法的结果如下：\n");
        DispMat(l);
}

void InPut()
{
    int n, i, j,  a[M][N]={0}, b[M][N]={0};
    CreateMat(A,a); CreateMat(B,b);//初始化三元组
    printf("请输入矩阵的行列数N：");
    scanf("%d",&n);
    printf("\n\n请输入第一个矩阵（二维数组形式）：");
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

            printf("\n\n请输入第二个矩阵（二维数组形式）：");
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&b[i][j]);

    CreateMat(A,a);
    CreateMat(B,b);
    printf("\n\n第一个矩阵如下：");
    DispMat(A);
    printf("\n\n第二个矩阵如下：");
    DispMat(B);
}

void Menu()
{
    printf("*******************************\n");
    printf("       稀疏矩阵的运算   \n");
    printf("*******************************\n\n");
    printf("        主菜单               \n");
    printf("     1.输入两个稀疏矩阵       \n");
    printf("     2.求矩阵的转置           \n");
    printf("     3.求矩阵的加法           \n");
    printf("     4.求矩阵的乘法           \n");
    printf("     5.退出系统               \n");
    printf("-------------------------------\n");
}

int main ()
{
    int i=0,j,n;
    Menu();
    printf("请输入你的选择：");
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
        
         printf("\n\n请输入你的选择："); 
         scanf("%d",&j);
    }
    


    system("pause");
    return 0;
}

/*
请输入第一个矩阵（二维数组形式）：
1 0 3 0
0 1 0 0
0 0 1 0
0 0 1 1


请输入第二个矩阵（二维数组形式）：
3 0 0 0
0 4 0 0
0 0 1 0
0 0 0 2
*/