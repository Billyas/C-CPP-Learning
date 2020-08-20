#include"标头.h"

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

	for (i = 1; i <= n; i++) {
		if (a[i] != 0) {
			s = (ListNode*)malloc(sizeof(ListNode));
			s->data = a[i];
			s->index = i;
			r->next = s;
			r = s;
		}
	}
	r->next = NULL;
	//链表的逻辑顺序跟数组相同
}

bool ListEmpty(ListNode* L)  //判线性表是否为空表
{
	return(L->next == NULL);
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

int Input(ListNode*& l, ListNode*& j)
{
	int flag = 0;
	InitList(l);
	InitList(j);
	int a[MaxSize] = { 0 }, b[MaxSize] = { 0 },in[MaxSize], m = 0, n = 0;
	printf("请输入第一个多项式：");
	scanf("%d\n", &n);
	m = n*2;
	
	for (int i = 0; i < m; i++) {
		if (i == m - 1) scanf("%d", &in[i]);
		else scanf("%d ", &in[i]);
	}
	//printf("yes");



	for (int i = 1; i <  m; i++) {
		
		a[in[i]] = in[i - 1];
	    i++;
	}	

    CreatListTail(l, a, n);

	printf("请输入第二个多项式：");
	scanf("%d\n", &n);
	m = n * 2;

	for (int i = 0; i < m; i++) {
		if (i == m - 1) scanf("%d", &in[i]);
		else scanf("%d ", &in[i]);
	}
	//printf("yes");



	for (int i = 1; i < m; i++) {

		b[in[i]] = in[i - 1];
		i++;
	}


	CreatListTail(j, b, n);

	if (m > n) flag = 1;


	if (!ListEmpty(l) && !ListEmpty(j)) {
		printf("success\n");
	}
	else {
		printf("error\n");
	}
	Put(l);
	printf("\n");
	Put(j);
	return flag;
}



ListNode* Plus(ListNode* l, ListNode* j,int flag)
{
	ListNode* h,*p=l->next,*q=j->next;
	InitList(h);


		while (p != NULL||q != NULL) {
			if (p->index = q->index) {
				h = h->next;
				h = (ListNode*)malloc(sizeof(ListNode));
				h->data = p->data + q->data;
				h->index = p->index;
			}
			else if (p->index < q->index) {
				h = h->next;
				h = (ListNode*)malloc(sizeof(ListNode));
				h->data = q->data;
				h->index = q->index;
			}
			else {
				h = h->next;
				h = (ListNode*)malloc(sizeof(ListNode));
				h->data = p->data;
				h->index = p->index;
			}
		}

	return h;
}

void Put(ListNode* l)
{
	l = l->next;
	while (l != NULL) {
		printf("%dx^%d+", l->data, l->index);
		l = l->next;
	}
}


int main()
{
	int i = 0,n=0,k=0,flag=0;
	ListNode* l,*j,*p,*s;
	InitList(l), InitList(j);

	/*printf("********************\n1.输入两个多项式\n2.加法\n3.乘法\n4.退出\n********************\n");
	scanf("%d", &k);
	while (1) {
		switch (k){
		    case 1: flag=Input(l, j);    break;
			case 2: p=Plus(l, j, flag); break;
			case 3: s=Seck(l, j,flag); break;
			case 4: return 0;   break;
		}
		scanf("%d", &k);
	}

*/
	Input(l, j);
	return 0;
}