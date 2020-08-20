#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20002
typedef int KeyType;
typedef int InfoType;
typedef struct SS
{
    KeyType key;   //关键字项
    InfoType data; //其他数据项
} RecType;         //排序的元素的类型

//交换函数
void swap(RecType &a, RecType &b)
{
    RecType c;
    c = a;
    a = b;
    b = c;
}
int compare = 0 , move = 0;  //关键字比较和移动的次数
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

            do    //往后移动一个位置，腾空间给tmp；
            {
                R[j + 1] = R[j];
                move++;    //移动加一
                j--;
                compare++; //比较次数加一
            } while (j >= 0 && R[j].key > tmp.key);

            R[j + 1] = tmp; //最后把tmp放在对应的位置
        }
    }
    compare += n-1;
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
        }
    }

    compare+=n-1;
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
                compare++;
        }
        R[i] = R[j]; //找到这样的R[j],放入R[i]处
        move++;
        while (i < j && R[i].key <= tmp.key)
        {    i++;     //从左向右扫描,找一个大于tmp.key的R[i]
             compare++;
        }
        R[j] = R[i]; //找到这样的R[i],放入R[j]处
        move++;
    }
    R[i] = tmp;
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

int main()
{
    RecType a[MAX];
    int i;
    srand((unsigned)time(NULL));

    for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("伪随机数生成的20002个随机数：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    /*直接插入排序法的排序过程*/
    /*InsertSort(a, MAX);

    printf("\n\n\n利用直接插入排序后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');

    printf("\n\n直接插入排序法：\n一共比较了%d次，移动了%d次\n",compare,move);*/
    //一共比较了98240531次，移动了98220530次
///////////////////////////////////////////////////////////////////////////////
    /*折半插入排序法的排序过程*/
    /*   compare = 0;
       move = 0;
    BinInsertSort(a, MAX);

    printf("\n\n\n利用折半插入排序后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\n折半插入排序：\n一共比较了%d次，移动了%d次\n",compare,move);*/
    //一共比较了275449次，移动了98319559次
//////////////////////////////////////////////////////////////////////////////
    /*希尔排序算法*/
    /*compare = 0;
    move = 0;
    ShellSort(a,MAX);

        printf("\n\n\n利用希尔排序算法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\n希尔排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);*/
    //一共比较了215214次，移动了215214次
/////////////////////////////////////////////////////////////////////////////
    /*冒泡排序法*/
   /* compare = 0;
    move = 0;
    BubbleSort(a,MAX);

     printf("\n\n\n利用冒泡排序法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\n冒泡排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);*/
    //一共比较了99118844次，移动了297356532次
//////////////////////////////////////////////////////////////////////////    
    /*快速排序算法*/
    compare = 0;
    move = 0;
    QuickSort(a,0,MAX);
         printf("\n\n\n利用快速排序算法后的数列如下：\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');

    printf("\n\n快速排序算法：\n一共比较了%d次，移动了%d次\n",compare,move);
    //一共比较了1939776次，移动了86186次
///////////////////////////////////////////////////////////////////////////
    system("pause");
    return 0;
}