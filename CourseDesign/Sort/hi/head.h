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
    KeyType key;   //�ؼ�����
    InfoType data; //����������
} RecType;         //�����Ԫ�ص�����

typedef struct SSS
{
    char name[30]; //��������
    int com;  //�ȽϵĴ���
    int mov;  //�ƶ��Ĵ���
}Analysis;    //�洢����Ч�ʵ�4����


//��������
void swap(RecType &a, RecType &b)
{
    RecType c;
    c = a;
    a = b;
    b = c;
}
int compare = 0 , move = 0;  //�ؼ��ֱȽϺ��ƶ��Ĵ���
Analysis Analy[5];             //�����㷨�ķ�������
//ֱ�Ӳ��������㷨
//ʱ�临�Ӷ�O(n^2)
void InsertSort(RecType R[], int n);
//�۰�������� 
//�����������뵽�����������ǰ��Ĳ�������ʵ������������ֱ����
//�����������۰������Ѱ�ҵĸĽ��㷨
void BinInsertSort(RecType R[], int n);
//ϣ�������㷨
void ShellSort(RecType R[], int n);
//ð�������㷨
void BubbleSort(RecType R[], int n);
/*���������㷨*/
int partition(RecType R[], int s, int t); //һ�˻���
//��R[s..t]��Ԫ�ؽ��п�������
void QuickSort(RecType R[], int s, int t);
//�˵�
void menu();
//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void FirstFun(RecType a[], int n);
//�˵�2
void SecondFun(RecType a[], int n);
//�˵�3
void ThirdFun(RecType a[], int n);
//�˵�4
void FourthFun(RecType a[], int n);
//�˵�5
void FifthFun(RecType a[], int n);
//�˵�6
void SixthFun(RecType a[], int n);
#endif