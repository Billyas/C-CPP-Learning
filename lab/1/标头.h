#pragma once
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ElemType int 
#define MaxSize 100
typedef struct SSS {          //����һ����ʽ�ṹ��
	ElemType data;            //��Ŷ�Ӧָ��������
	ElemType index;          //���ָ��
	struct SSS* next;
}ListNode;

void InitList(ListNode*& L);

void CreatListTail(ListNode*& l, ElemType* a, int n);

bool ListEmpty(ListNode* L);

void DestoryList(ListNode*& l);

int Input(ListNode*& l, ListNode*& j);

ListNode* Plus(ListNode* l, ListNode* j,int flag);

ListNode* Seck(ListNode* l, ListNode* j,int flag);

void Put(ListNode* l);



