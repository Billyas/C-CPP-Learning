#ifndef _HEAD_H
#define _HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define maxsize 3
#define MaxSize 3
#define ElemType Car
typedef struct SS
{
    char a[20];    //车牌号
    int wait;      //在候车区的位置，一旦进入停车就置为-1
    int park;      //在停车区的位置,为停车则一直是-1
    time_t start;  //存储进入停车场的时间unix时间戳
    time_t finish; //存储离开停车场的时间
    int price;     //停车费用
} Car;             //车辆信息的基本存储结构体

typedef struct SSS
{
    ElemType data[maxsize];
    int top;
} SqStack; //数组栈的结构体

typedef struct ss
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue; //队列的结构体，用于候车区的先进先出
/////////////////////////////////////////////
int Park_Num = 0;    //已经停的车位数
int PrePark_Num = 0; //候车位数量
int Price = 1;       //可以自定义每小时的费用
/////////////////////////////////////////////
//初始化栈
void InitStack(SqStack *&s);
//摧毁栈
void DestroyStack(SqStack *&s);
//判断是否为空
bool StackEmpty(SqStack *&s);
//进栈--进入停车区
bool Push(SqStack *&s, ElemType e);
//出栈--离开停车场
bool Pop(SqStack *&s, ElemType &e);
//取栈顶元素
bool GetTop(SqStack *s, ElemType &e);
//在栈数组中寻找离开停车场的车辆
int ElemEmpty(SqStack *s, char str[]);
////////////////////////////////////////////
//初始化队列
void InitQueue(SqQueue *&q);
//销毁队列
void DestoryQueue(SqQueue *&q);
//判判断队列是否为空
bool QueueEmpty(SqQueue *q);
//进队列---进入候车区
bool enQueue(SqQueue *&q, ElemType e);
//出队列---出候车区，进入停车区
bool deQueue(SqQueue *&q, ElemType &e);
////////////////////////////////////////////
//显示并返回当前时间
struct tm *ShowTime(void);
//候车登记函数
void Pre_Park(SqQueue *qu);
//返回Unix时间戳
time_t UnixTime(void);
//Unix时间戳转换成本地时间str并显示
char *TransformTime(time_t t);
//退出停车位
void Exit(SqQueue *st);
//进入停车区登记
void Park(SqStack *st, SqQueue *qu);
//候车登记函数
void Pre_Park(SqQueue *qu);
////////////////////////////////////////////
/*
struct tm
{
    int tm_sec;  秒，正常范围0-59， 但允许至61
    int tm_min;  分钟，0-59
    int tm_hour; 小时， 0-23
    int tm_mday; 日，即一个月中的第几天，1-31
    int tm_mon;  月， 从一月算起，0-11  1+p->tm_mon;
    int tm_year; 年， 从1900至今已经多少年  1900＋ p->tm_year;
    int tm_wday; 星期，一周中的第几天， 从星期日算起，0-6
    int tm_yday; 从今年1月1日到目前的天数，范围0-365
    int tm_isdst; 日光节约时间的旗标
};
*/
#endif