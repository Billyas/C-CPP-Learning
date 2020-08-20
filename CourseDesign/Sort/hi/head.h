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