#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define BTNode TBTNode
#define MaxSize 100
#define maxsize 100
typedef struct node
{
    ElemType data;
    int ltag, rtag; //线索的标记
    struct node *lchild;
    struct node *rchild;
} BTNode;

BTNode *pre; //全局变量的指针类型

char Pre[100];
char In[100];
int i = 0;

void CreateBTree(BTNode *&b, char *str) //创建二叉树
{
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];

    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL)
                b = p;
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DestoryBTree(BTNode *&b) //摧毁二叉树
{
    if (b != NULL)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b, ElemType x) //寻找值为x的结点
{
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

BTNode *LchildNode(BTNode *p) //返回左孩子结点
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) //返回右孩子结点
{
    return p->rchild;
}

int BTHeight(BTNode *b) //输出高度
{
    int lchildh, rchildh;
    if (b == NULL)
        return 0;
    else
    {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

void DispBTree(BTNode *b) //输出二叉树
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

void PreOrder(BTNode *b)
//先序遍历的递归形式
{
    if (b != NULL)
    {
        printf("%c ", b->data);
        Pre[i] = b->data;
        i++;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}
void InOrder(BTNode *b)
//中序遍历的递归算法
{
    if (b != NULL)
    {
        InOrder(b->lchild);
        In[i] = b->data;
        i++;
        printf("%c ", b->data);
        InOrder(b->rchild);
    }
}

BTNode *CreateBTree1(char *pre, char *in, int n)
//根据前序和中序推出二叉树序列
{
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode));
    b->data = *pre;

    for (p = in; p < in + n; p++)
        if (*p == *pre)
            break;

    k = p - in;
    b->lchild = CreateBTree1(pre + 1, in, k);
    b->rchild = CreateBTree1(pre + k + 1, p + 1, n - k - 1);
    return b;
}

void Thread(TBTNode *&p) //生成二叉树的线索
{
    if (p != NULL)
    {
        Thread(p->lchild);
        if (p->lchild == NULL) //节点左孩子为空时就直接指向前驱的节点线索
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        else
            p->ltag = 0;

        if (pre->rchild == NULL) //右孩子为空时则指向后继的结点线索位置
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        else
            pre->rtag = 0;

        pre = p;
        Thread(p->rchild);
    }
}

TBTNode *CreateThread(TBTNode *b) //把二叉链转换成线索的形式
{
    TBTNode *root;
    root = (BTNode *)malloc(sizeof(BTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;

    if (b == NULL)
        root->lchild = root; //原二叉链为空，则指针指回自己root
    else
    {
        root->lchild = b;
        pre = root;
        Thread(b);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;
}

void ThInOrder(TBTNode *tb)
{
    TBTNode *p = tb->lchild;

    while (p != tb)
    {
        while (p->ltag == 0)
            p = p->lchild;                      //找到中序的第一个节点
        printf("%c", p->data);                  //如果无左孩子说明是已经到达了树梢的叶子节点，直接输出
        while (p->rtag == 1 && p->rchild != tb) //输出在中序中的下一个节点值
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild; //回溯到p的前一个节点或者是直接找下一个的右孩子节点
    }
}
int main()
{
    char a[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    int n = 14;
    BTNode *t, *b;
    CreateBTree(t, a);
    b = FindNode(t, 'H');
    printf("the leftchild is %c , the right child is %c \n", b->lchild->data, b->rchild->data);

    printf("the tree height is %d .\n", BTHeight(t));

    printf("this is the preorder:");
    PreOrder(t);
    i = 0;
    printf("\nthis is the inorder:");
    InOrder(t);

    DestoryBTree(t);
    printf("\ncreat by preorder and inorder");
    b = CreateBTree1(Pre, In, n);
    putchar(10);
    DispBTree(b);
    putchar(10);

    TBTNode *g;
    g = CreateThread(t);
    printf("this is the Inorder:");
    ThInOrder(b);
    putchar(10);
    system("pause");
    return 0;
}