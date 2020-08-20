#ifndef _HEAD_H
#define _HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 20002
typedef int KeyType;
typedef int InfoType;
typedef struct SS
{
    KeyType key;   //关键字项
    InfoType data; //其他数据项
} RecType;         //排序的元素的类型

typedef struct SSS
{
    char name[30]; //排序名称
    int com;  //比较的次数
    int mov;  //移动的次数
}Analysis;    //存储分析效率的4数据


//交换函数
void swap(RecType &a, RecType &b)
{
    RecType c;
    c = a;
    a = b;
    b = c;
}
int compare = 0 , move = 0;  //关键字比较和移动的次数
Analysis Analy[5];             //五种算法的分析数据
//直接插入排序算法
//时间复杂度O(n^2)
void InsertSort(RecType R[], int n);
//折半插入排序法 
//把无序区插入到有序区里，由于前面的插入排序法实现了有序，所以直接在
//有序区利用折半查找来寻找的改进算法
void BinInsertSort(RecType R[], int n);
//希尔排序算法
void ShellSort(RecType R[], int n);
//冒泡排序算法
void BubbleSort(RecType R[], int n);
/*快速排序算法*/
int partition(RecType R[], int s, int t); //一趟划分
//对R[s..t]的元素进行快速排序
void QuickSort(RecType R[], int s, int t);
//菜单
void menu();
//调用直接插入排序的实现函数，即菜单1
void FirstFun(RecType a[], int n);
//菜单2
void SecondFun(RecType a[], int n);
//菜单3
void ThirdFun(RecType a[], int n);
//菜单4
void FourthFun(RecType a[], int n);
//菜单5
void FifthFun(RecType a[], int n);
//菜单6
void SixthFun(RecType a[], int n);
#endif

//五种常见的算法
///////////////////////////////////////////////
//直接插入排序算法
//时间复杂度O(n^2)
void InsertSort(RecType R[], int n)
{
    int i, j;
    RecType tmp;

    for (i = 1; i < n; i++)    //for循环内一定比较了n-1次，if判断语句
    {
        if (R[i].key < R[i - 1].key) //一旦出现了逆序的关键字，就进行插入
        {
            tmp = R[i];
            j = i - 1;
            compare++;
            do    //往后移动一个位置，腾空间给tmp；
            {
                R[j + 1] = R[j];
                move++;    //移动加一
                j--;
                compare++; //比较次数加一
            } while (j >= 0 && R[j].key > tmp.key);

            R[j + 1] = tmp; //最后把tmp放在对应的位置
            move+=2; //移动的temp
        }
    }
    
}
////////////////////////////////////////////////////
//折半插入排序法 
//把无序区插入到有序区里，由于前面的插入排序法实现了有序，所以直接在
//有序区利用折半查找来寻找的改进算法
void BinInsertSort(RecType R[], int n)
{
    int i, j, low, high, mid;
    RecType tmp;

    for (i = 1; i < n; i++)  //已经比较了n-1次
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            low = 0;
            high = i - 1;
            
            compare++;

            while (low <= high)  
            {
                compare++;  //while进入比较
                mid = (low + high) / 2;
                if (tmp.key < R[mid].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (j = i - 1; j >= high + 1; j--)
            {      
                R[j + 1] = R[j];
                move++;//移动次数加一
            }
            R[high + 1] = tmp;
            move += 2;//tmp交换
        }
    }

}
///////////////////////////////////////////////////
//希尔排序算法
void ShellSort(RecType R[], int n)
{
    int i, j, d;
    RecType tmp;
    d = n / 2;

    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            tmp = R[i];
            j = i - d;

            while (j >= 0 && tmp.key < R[j].key)
            {
                compare++;
                move++;
                R[j + d] = R[j];
                j = j - d;
            }
            R[j + d] = tmp;
            move += 2;//tmp进行两次操作
        }
        d = d / 2;
    }
}
///////////////////////////////////////////////////
//冒泡排序算法
void BubbleSort(RecType R[], int n)
{
    int i, j;
    bool exchange;
    RecType tmp;

    for (i = 0; i < n - 1; i++)
    {
        exchange = false;

        for (j = n - 1; j > i; j--)
            if (R[j].key < R[j - 1].key)
            {
                compare ++;
                move += 3;
                tmp = R[j - 1];
                R[j - 1] = R[j];
                R[j] = tmp;
                exchange = true;
            }

        if (!exchange)
            return;
    }
}
/////////////////////////////////////////////////////////
/*快速排序算法*/
int partition(RecType R[], int s, int t) //一趟划分
{
    int i = s, j = t;
    RecType tmp = R[i]; //以R[i]为基准
    while (i < j)       //从两端交替向中间扫描,直至i=j为止
    {
        while (j > i && R[j].key >= tmp.key)
        {
                j--;     //从右向左扫描,找一个小于tmp.key的R[j]
                compare++;//进行比较
        }
        R[i] = R[j]; //找到这样的R[j],放入R[i]处
        move++;      //移动+1
        while (i < j && R[i].key <= tmp.key)
        {    i++;      //从左向右扫描,找一个大于tmp.key的R[i]
             compare++;//比较加一
        }
        R[j] = R[i]; //找到这样的R[i],放入R[j]处
        move++;      //移动加一
    }
    R[i] = tmp;
    move+=2; //temp的交换
    return i;
}

void QuickSort(RecType R[], int s, int t)
//对R[s..t]的元素进行快速排序
{
    int i;
    if (s < t) //区间内至少存在两个元素的情况
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1); //对左区间递归排序
        QuickSort(R, i + 1, t); //对右区间递归排序
    }
}
/////////////////////////////////////////////////////

void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.直接插入排序法\n");
    printf("\t\t2.折半插入排序法\n");
    printf("\t\t3.希尔排序法\n");
    printf("\t\t4.冒泡排序法\n");
    printf("\t\t5.快速排序法\n");
    printf("\t\t6.效率比较\n");
    printf("\t\t7.退出\n");
    printf("***************************************************\n");
}


//调用直接插入排序的实现函数，即菜单1
void FirstFun(RecType a[], int n)
{
     int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);
    
    InsertSort(a, MAX);

    printf("\n\n\n利用直接插入排序后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\n直接插入排序法：\n一共比较了%d次，移动了%d次\n",compare,move);
    Analy[0].com = compare;
    Analy[0].mov = move;
    strcpy(Analy[0].name, "直接插入排序");
}
//菜单2
void SecondFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    BinInsertSort(a, MAX);

    printf("\n\n\n利用折半插入排序后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\n折半插入排序：\n一共比较了%d次，移动了%d次\n",compare,move);
    Analy[1].com = compare;
    Analy[1].mov = move;
    strcpy(Analy[1].name, "折半插入排序");
}

//菜单3
void ThirdFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    ShellSort(a,MAX);

        printf("\n\n\n利用希尔排序算法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\n希尔排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);
    Analy[2].com = compare;
    Analy[2].mov = move;
    strcpy(Analy[2].name, "希尔排序算法");
}
//菜单4
void FourthFun(RecType a[], int n)
{
     int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    BubbleSort(a,MAX);

     printf("\n\n\n利用冒泡排序法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\n冒泡排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);
    Analy[3].com = compare;
    Analy[3].mov = move;
    strcpy(Analy[3].name, "冒泡排序算法");
}
//菜单5
void FifthFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);
    
    compare = 0;
    move = 0;
    QuickSort(a,0,MAX);
         printf("\n\n\n利用快速排序算法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');

    printf("\n\n快速排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);
    Analy[4].com = compare;
    Analy[4].mov = move;
    strcpy(Analy[4].name, "快速排序算法");
}
//菜单6
void SixthFun(RecType a[], int n)
{
    int i;
    printf("各种排序算法的比较于移动次数的对比：\n\n");
    //printf("   名称\t\t\t\t比较次数\t\t\t移动次数\n");
    printf("   名称          比较次数          移动次数\n");

    for(i = 0; i < 5; i++)
        printf("%-17s%-18d%d\n",Analy[i].name,Analy[i].com,Analy[i].mov);
}

int main ()
{
    RecType a[MAX];
    int i, k;
    srand((unsigned)time(NULL));
    menu();
    printf("请选择操作：");
    scanf("%d",&k);

    while(k!=7)
    {
        switch(k) {
            case 1:  FirstFun(a,MAX);  break;
            case 2:  SecondFun(a,MAX); break;
            case 3:  ThirdFun(a,MAX);  break;
            case 4:  FourthFun(a,MAX); break;
            case 5:  FifthFun(a,MAX);  break;
            case 6:  SixthFun(a,MAX);  break;
            default:   break;
        }
        
        system("pause");
        system("cls");
        menu();
        printf("请选择操作：");
        scanf("%d",&k);

    }


    system("pause");
    return 0;
}