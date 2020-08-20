#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int InforType;
typedef struct head
{
    KeyType key;    //存放关键字
    InforType data; //其他数据项
} RecType;          //查找元素类型

//////////////////////////////////////////////////
//二分法或者折半查找法
int BinSearch(RecType R[], int n, KeyType k)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key == k)
            return mid + 1;
        if (R[mid].key > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////
int main()
{
    int i = 0;
    RecType k[100];

    for (i = 0; i < 100; i++) //给结构体赋值
        k[i].key = i + 1;

    printf("折半法查找---顺序表中4所在的位置是%d\n", BinSearch(k, 100, 4));
    system("pause");
    return 0;
}