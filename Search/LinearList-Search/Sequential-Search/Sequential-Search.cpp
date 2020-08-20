#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int InforType;
typedef struct head
{
    KeyType key;    //存放关键字
    InforType data; //其他数据项
} RecType;          //查找元素类型

////////////////////////////////////////////////////////////
//顺序查找
int SeqSearch(RecType R[], int n, KeyType k)
{
    int i = 0;
    while (i < n && R[i].key != k)
        i++;

    if (i >= n)
        return 0; ////未找到返回0；
    else
        return i + 1; //逻辑上的序号
}

///改进版的顺序查找，减少了判断的过程
int SeqSearch1(RecType R[], int n, KeyType k)
{
    int i = 0;
    R[n].key = k;
    while (R[i].key != k)
        i++;

    if (i == n)
        return 0;
    else
        return i + 1;
}
/////////////////////////////////////////////////////////////
int main()
{
    int i = 0;
    RecType k[100];

    for (i = 0; i < 100; i++) //给结构体赋值
        k[i].key = i + 1;

    printf("在顺序表中9所在的位置是%d\n", SeqSearch(k, 100, 9));
    printf("改进后的在顺序表中4所在的位置是%d\n", SeqSearch1(k, 100, 4));
    return 0;
}