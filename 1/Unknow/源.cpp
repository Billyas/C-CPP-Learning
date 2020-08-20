//#pragma warning(disable:4996)

# include <stdio.h>
# include <stdlib.h>
#define ElemType char

typedef struct dlistnode {
	ElemType data;
	struct dlistnode* pre;
	struct dlistnode* next;
}DLinkNode;

void CreatListTail(DLinkNode*& L, ElemType* a, int n)
{
	int i = 0;
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;

	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
	if(s)	s->data = a[i];
		
		s->pre = r;
		r->next = s;

		r = s;
	}
	r->next = NULL;
}

void DisplayList(DLinkNode* L) 
{
	DLinkNode* p=L->next;
	
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}

	printf("\n");
}

void ListLength(DLinkNode* L)
{
	int i = 0;
	DLinkNode* p = L->next;

	while (p != NULL) {
		i++;
		p = p->next;
	}
	printf("%d\n", i);
}

bool bbb(DLinkNode* L)
{
	return(L->next == NULL);
}

void PutList(DLinkNode* L)
{
	int i = 0;
	DLinkNode* p=L;
	while (p != NULL&&i<3) {
		i++;
		p = p->next;
	}
	if(p) printf("%c\n", p->data);
}

void PutLocat(DLinkNode* L)
{
	int i = 0;
	DLinkNode* p = L;
	while (p != NULL && p->data != 'a') {
		i++;
		p = p->next;
	}

	if (p != NULL) {
		printf("%d\n", i);
	}
}

bool InsertElem(DLinkNode*& L, int j,ElemType e)
{
	int i = 0;
	DLinkNode* p = L, * s ;

	while (p != NULL && i < j - 1) {
		i++;	
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		if(s) s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			p->next->pre = s;

		s->pre = p;
		p->next = s;

		return true;
	}

}
bool DeletElem(DLinkNode* L, int n) 
{
	int i = 0;
	DLinkNode* p = L,*s;

	while (p != NULL && i < n-1) {
		i++;
		p = p->next;
	}

	if (p == NULL) return false;
	else {
		s = p->next;
		if (s == NULL) return false;

		if(s->next!=NULL)
		s->next->pre = p;
		p->next = s->next;
		free(s);
		return true;
	}


}
bool ListDelet(DLinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L, * q;

	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	q = p;
	if (p == NULL)
		return false;
	else 
	{
		q = p->next;		
		if (q == NULL)	   
			return false;
		e = q->data;
		p->next = q->next;		
		if (q->next != NULL)    	
			q->next->pre = p;	
		free(q);		   	
		return true;
	}

}

void DestoryDLink(DLinkNode*& L)
{
	DLinkNode* s = L->next;

	while (s != NULL) {
		free(s->pre);
		s = s->next;
	}
}

int main()
{
	int i = 0, n = 0;
	char a[100];
	DLinkNode* L;
	scanf("%d\n", &n);

	for (i = 0; i < n; i++) {
		if (i == n - 1) scanf("%c", &a[i]);
		else scanf("%c ", &a[i]);
	}

	CreatListTail(L, a, n);

	DisplayList(L);

	ListLength(L);

	if (bbb(L) == 0)
		printf("no\n");

	PutList(L);

	PutLocat(L);

	char e = 'f';
	InsertElem(L, 4, e);
	DisplayList(L);

	//DeletElem(L, 5);
	ListDelet(L, 5, e);
	DisplayList(L);

	DestoryDLink(L);
	system("pause");
}
/*
5
a b c d e
*/