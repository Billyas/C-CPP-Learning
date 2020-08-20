#pragma warning(disable:4996)
# include <stdio.h>
# include <stdlib.h>
#define ElemType char

typedef struct SSS {          //定义一个链式结构体
	ElemType data;
	struct SSS* next;
}ListNode;

void InitList(ListNode*& L)
{
	L = (ListNode*)malloc(sizeof(ListNode));
	L->next = NULL;
}

void CreatListTail(ListNode*& l, ElemType* a, int n)//尾插法
{
	ListNode* s, * r; int i;
	l = (ListNode*)malloc(sizeof(ListNode));
	r = l;

	for (i = 0; i < n; i++) {
		s = (ListNode*)malloc(sizeof(ListNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	//链表的逻辑顺序跟数组相同
}

void Display(ListNode* l) {     //显示代码
	int i;
	ListNode* s = l->next;
	while (s != NULL) {
		printf("%c ", s->data);
		s = s->next;
	}
	printf("\n");
}

int LengthList(ListNode* L)
{
	int i = 0;
	ListNode* p = L->next;

	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

bool ListEmpty(ListNode* L)  //判线性表是否为空表
{
	return(L->next == NULL);
}

void PutListElem(ListNode* L)
{
	int i = 1;
	ListNode* p = L->next;
	while (p != NULL && i < 3) {
		i++;
		p = p->next;
	}
	if (p == NULL) printf("no");
	else printf("%c\n", p->data);
}

void PutLocatA(ListNode* L)
{
	int i = 1;
	ListNode* p = L->next;
	while (p != NULL && p->data != 'a') {
		i++;
		p = p->next;
	}

	if (p == NULL) printf("can't find it\n");
	else printf("%d\n", i);
}

bool InsertElem(ListNode* &L, int i, ElemType e)//插入元素
{
	int j = 0;
	ListNode* p = L, * s;

	if (j < 0) return false;

	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {
		s = (ListNode*)malloc(sizeof(ListNode));
		s->next = p->next;
		s->data = e;
		p->next = s;
	}

	return true;
}

bool DeleteElem(ListNode*& L, int i)
{
	int j = 0;
	ListNode* p = L, * s;

	while (j < i - 1 && p->next != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (ListNode*)malloc(sizeof(ListNode));
		s = p->next;
		p->next = p->next->next;
		free(s);
		return true;
	}

}
void DestoryList(ListNode*& l)
{
	ListNode* pre = l, * p = l->next;

	while (p != NULL) {

		free(pre);
		pre = p;
		p = pre->next;

	}
	free(pre);
}

int main()
{
	int i = 0,n=0;
	char a[100];
	ListNode* L;
	scanf("%d\n", &n);

	for (i = 0; i <n; i++) {
		if (i==n-1) scanf("%c", &a[i]);
		else scanf("%c ", &a[i]);
	}

/*	for (i = 0; i < n; i++) {
		printf("%c ", a[i]);
	}
	printf("\n");
*/
	InitList(L);
	printf("%d\n", L->next);
	
	CreatListTail(L, a, n);
	Display(L);

	printf("%d\n",LengthList(L));
	
	if (ListEmpty(L) == 0)
		printf("no\n");

	PutListElem(L);

	PutLocatA(L);

	char e = 'x';
	InsertElem(L, 4, e);
	Display(L);

	DeleteElem(L, 3);
	Display(L);

	DestoryList(L);

}
/*
5
a b c d e
*/