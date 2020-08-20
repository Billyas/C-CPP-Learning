#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ElemType int 
#define MaxSize 100
typedef struct SSS {          //定义一个链式结构体
	ElemType data;            //存放对应指数的系数
	ElemType index;          //存放指数
	struct SSS* next;
}ListNode;
void InitList(ListNode*& L);     //初始化

void CreatListTail(ListNode*& l, ElemType* a, int n);//创建链表  

bool ListEmpty(ListNode* L);       //判断是否为空     

void DestoryList(ListNode*& l);   //删除链表

int Input(ListNode*& l, ListNode*& j);  //输入时直接按指数大小排序

ListNode* Plus(ListNode* l, ListNode* j);//加法的运算

ListNode* Seck(ListNode* l, ListNode* j);//乘法的运算

bool InsertElem(ListNode* &L, int i, ElemType e);

void Put(ListNode* l)
{
	l = l->next;
	while (l != NULL) {
		if(l->data!=0){ 
        if(l->next!=NULL&&l->next->data>0&&l->index!=0)
		    printf("%dx^%d+", l->data, l->index);

        else if(l->next!=NULL&&l->next->data<0&&l->index!=0)
		    printf("%dx^%d", l->data, l->index);
		else if(l->next!=NULL&&l->index==0&&l->next->data>0)
		    printf("%d+", l->data);
		else if(l->next!=NULL&&l->index==0&&l->next->data<0)
		    printf("%d",l->data);
		else if	(l->next!=NULL&&l->index==0&&l->next->data==0)
			printf("%d+",l->data);
		else 
            printf("%dx^%d",l->data, l->index);
		}
		l = l->next;
	}
    printf("\n");
}


void InitList(ListNode*& L)
{
	L = (ListNode*)malloc(sizeof(ListNode));
	L->next = NULL;
}

void CreatListTail(ListNode*& l, ElemType* a, int n)//尾插法
{
	ListNode* s, * r; int i;
//	l = (ListNode*)malloc(sizeof(ListNode));
	r = l;

	for (i = 0; i < MaxSize; i++) {
		if (a[i] != 0&&a[i]!='\0') {
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
	int a[MaxSize] = { 0 }, b[MaxSize] = { 0 };
	int in[MaxSize],in2[MaxSize], m = 0, n = 0;
	printf("请输入第一个多项式：");
	scanf("%d\n", &n);
	m = n*2;
	
	for (int i = 0; i < m; i++) {
		if (i == m - 1) scanf("%d", &in[i]);
		else scanf("%d ", &in[i]);
	}

	for (int i = 1; i <  m; i++) {		
		a[in[i]] = in[i - 1];
	    i++;
	}	

    CreatListTail(l, a, n);

	printf("请输入第二个多项式：");
	scanf("%d\n", &n);
	m = n * 2;
	for (int i = 0; i < m; i++) {
		if (i == m - 1) scanf("%d", &in2[i]);
		else scanf("%d ", &in2[i]);
	}

	for (int i = 1; i < m; i++) {
		b[in2[i]] = in2[i - 1];
		i++;
	}

	CreatListTail(j, b, n);

	if (!ListEmpty(l) && !ListEmpty(j)) {
		printf("success\n");
	}
	else {
		printf("error\n");
	}
	Put(l);
	Put(j);
	return flag;
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

ListNode* Plus(ListNode* l, ListNode* j)
{
	ListNode* h,*p=l->next,*q=j->next,*s,*r;
	InitList(h);
    s=h;


		while (p != NULL&&q != NULL) {
			if (p->index == q->index) {
				r = (ListNode*)malloc(sizeof(ListNode));
				r->data = p->data + q->data;
				r->index = p->index;
                s->next = r;
                s = r;
                p=p->next;
                q=q->next;
			}
			else if ( p->index < q->index ) {
				r = (ListNode*)malloc(sizeof(ListNode));
				r->data = p->data;
				r->index = p->index;
                s->next = r;
                s = r;
                p=p->next;
			}
			else if ( p->index > q->index ){
				r = (ListNode*)malloc(sizeof(ListNode));
				r->data = q->data;
				r->index = q->index;
                s->next = r;
                s = r;
                q=q->next;                
		    }
            
        }
		while(p!=NULL){
				r = (ListNode*)malloc(sizeof(ListNode));
				r->data = p->data;
				r->index = p->index;
                s->next = r;
                s = r;
                p=p->next;			
		}
		while(q!=NULL){
				r = (ListNode*)malloc(sizeof(ListNode));
				r->data = q->data;
				r->index = q->index;
                s->next = r;
                s = r;
                q=q->next;   			
		} s->next=NULL; 	return h;
}

ListNode* Seck(ListNode* l, ListNode* j)
{
	ListNode*p=l->next,*q=j->next,*g,*h,*s,*r;
	int flag=0;
	InitList(h);   //初始化h，h作为每个元素每次乘的和链表
	while(p!=NULL){
		while(q!=NULL){
				InitList(g),    r=g;		
			s=(ListNode*)malloc(sizeof(ListNode));
			s->data=p->data*q->data;
			s->index=p->index+q->index;
			r->next=s;
			r=s;
			r->next=NULL;

			h=Plus(g,h);
			DestoryList(g);

			q=q->next;
		}
		q=j->next;
		p=p->next;
	}
    Put(h);
	return h;
}

int main()
{
	int i = 0,n=0,k=0,flag=0;
	ListNode* l,*j,*p,*s;
	InitList(l), InitList(j);

	printf("********************\n1.输入两个多项式\n2.加法\n3.乘法\n4.退出\n********************\n");
	scanf("%d", &k);
	while (1) {
		switch (k){
		    case 1: Input(l, j);                            break;
			case 2: printf("加法是："); p=Plus(l, j);Put(p); break;
			case 3: printf("乘法是：");s=Seck(l, j);         break;
			case 4: return 0;   break;
		
		}
		printf("按键选择："); 
		scanf("%d", &k);
	}

    system("pause");
	return 0;
}
/*3
-7 1 6 0 3 5
4
2 2 7 1 -4 5 2 0
*//*	Input(l, j);
    p=Plus(l,j);
    Put(p);

	s=Seck(l,j);*/