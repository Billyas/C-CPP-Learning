#pragma once
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ElemType int 
#define MaxSize 100
typedef struct SSS {          //定义一个链式结构体
	ElemType data;            //存放对应指数的数据
	ElemType index;          //存放指数
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



