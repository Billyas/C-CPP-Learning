# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define ElemType BTNode
# define elemtype char
# define MaxSize 100
typedef struct node
{
    elemtype data;
    struct node* lchild;
    struct node* rchild;
}BTNode;

void CreateBTree(BTNode*& b, char* str)//创建二叉树
{
    BTNode* St[MaxSize], * p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];

    while (ch != '\0')
    {
        switch (ch)
        {
        case '(': top++; St[top] = p; k = 1; break;
        case ')': top--;                 break;
        case ',': k = 2;                   break;
        default: p = (BTNode*)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL)  b = p;
            else
            {
                switch (k)
                {
                case 1: St[top]->lchild = p; break;
                case 2: St[top]->rchild = p; break;
                }
            }
        }
        j++;
        ch = str[j];
    }


}

void DestoryBTree(BTNode*& b)//摧毁二叉树
{
    if (b != NULL)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}

void PreOrder(BTNode * b)
//先序遍历的递归形式
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void DispBTree(BTNode* b) //输出二叉树
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

BTNode* CreateBTree1(char *pre, char *in, int n)
//根据前序和中序推出二叉树序列
{
    BTNode * b;
    char *p;
    int k;
    if(n<=0) return NULL;
    b=(BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;

    for(p = in; p < in+n; p++)
        if(*p == *pre)  break;

    k = p-in;
    b->lchild=CreateBTree1(pre+1, in, k);
    b->rchild=CreateBTree1(pre+k+1, p+1, n-k-1);
    return b;
}

BTNode *CreateBtree2(char *post, char *in, int n)
//根据后序和中序来还原二叉树
{
    BTNode *b;
    char r,*p;
    int k;
    if(n<=0) return NULL;
    r= *(post+n-1);
    b=(BTNode*)malloc(sizeof(BTNode));
    b->data=r;

    for(p = in; p < in+n; p++)
        if(*p==r) break;

    k=p-in;
    b->lchild=CreateBtree2(post,in,k);
    b->rchild=CreateBtree2(post+k,p+1,n-k-1);
    return b;
}

int main ()
{
    char a[100],b[100];
    int n;
    BTNode *T;
    scanf("%s",a);
    scanf("%s",b);
    n=strlen(a);
   // printf("%d",n);
   // T=CreateBTree1(a, b, n);
    //PreOrder(T);
    T=CreateBtree2(b, a, n);
    PreOrder(T);
    putchar(10);
    system("pause");
    return 0;
}
/*
ACBDFEG
ABDCGEF
*/