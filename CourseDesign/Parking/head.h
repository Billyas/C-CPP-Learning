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
    char a[20];    //���ƺ�
    int wait;      //�ں�����λ�ã�һ������ͣ������Ϊ-1
    int park;      //��ͣ������λ��,Ϊͣ����һֱ��-1
    time_t start;  //�洢����ͣ������ʱ��unixʱ���
    time_t finish; //�洢�뿪ͣ������ʱ��
    int price;     //ͣ������
} Car;             //������Ϣ�Ļ����洢�ṹ��

typedef struct SSS
{
    ElemType data[maxsize];
    int top;
} SqStack; //����ջ�Ľṹ��

typedef struct ss
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue; //���еĽṹ�壬���ں������Ƚ��ȳ�
/////////////////////////////////////////////
int Park_Num = 0;    //�Ѿ�ͣ�ĳ�λ��
int PrePark_Num = 0; //��λ����
int Price = 1;       //�����Զ���ÿСʱ�ķ���
/////////////////////////////////////////////
//��ʼ��ջ
void InitStack(SqStack *&s);
//�ݻ�ջ
void DestroyStack(SqStack *&s);
//�ж��Ƿ�Ϊ��
bool StackEmpty(SqStack *&s);
//��ջ--����ͣ����
bool Push(SqStack *&s, ElemType e);
//��ջ--�뿪ͣ����
bool Pop(SqStack *&s, ElemType &e);
//ȡջ��Ԫ��
bool GetTop(SqStack *s, ElemType &e);
//��ջ������Ѱ���뿪ͣ�����ĳ���
int ElemEmpty(SqStack *s, char str[]);
////////////////////////////////////////////
//��ʼ������
void InitQueue(SqQueue *&q);
//���ٶ���
void DestoryQueue(SqQueue *&q);
//���ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q);
//������---�������
bool enQueue(SqQueue *&q, ElemType e);
//������---������������ͣ����
bool deQueue(SqQueue *&q, ElemType &e);
////////////////////////////////////////////
//��ʾ�����ص�ǰʱ��
struct tm *ShowTime(void);
//�򳵵ǼǺ���
void Pre_Park(SqQueue *qu);
//����Unixʱ���
time_t UnixTime(void);
//Unixʱ���ת���ɱ���ʱ��str����ʾ
char *TransformTime(time_t t);
//�˳�ͣ��λ
void Exit(SqQueue *st);
//����ͣ�����Ǽ�
void Park(SqStack *st, SqQueue *qu);
//�򳵵ǼǺ���
void Pre_Park(SqQueue *qu);
////////////////////////////////////////////
/*
struct tm
{
    int tm_sec;  �룬������Χ0-59�� ��������61
    int tm_min;  ���ӣ�0-59
    int tm_hour; Сʱ�� 0-23
    int tm_mday; �գ���һ�����еĵڼ��죬1-31
    int tm_mon;  �£� ��һ������0-11  1+p->tm_mon;
    int tm_year; �꣬ ��1900�����Ѿ�������  1900�� p->tm_year;
    int tm_wday; ���ڣ�һ���еĵڼ��죬 ������������0-6
    int tm_yday; �ӽ���1��1�յ�Ŀǰ����������Χ0-365
    int tm_isdst; �չ��Լʱ������
};
*/
#endif