# include "head.h"

//先序遍历的非递归算法
void PreOrder1(BTNode* b)
{
	BTNode* p;
	SqStack* st;
	
	InitStack(st);

	if (b != NULL)
	{
		Push(st, b);

		while (!StackEmpty(st))
		{
			Pop(st, p);
			printf("%c ", p->data);
			if (p->rchild != NULL)
				Push(st, p->rchild);
			if (p->lchild != NULL)
				Push(st, p->lchild);
		}
		printf("\n");
	}
	DestroyStack(st);
}