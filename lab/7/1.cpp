#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define BTNode TBTNode
#define MaxSize 100
#define maxsize 100
typedef struct node
{
    ElemType data;
    int ltag, rtag; //�����ı��
    struct node *lchild;
    struct node *rchild;
} BTNode;

BTNode *pre; //ȫ�ֱ�����ָ������

char Pre[100];
char In[100];
int i = 0;

void CreateBTree(BTNode *&b, char *str) //����������
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

void DestoryBTree(BTNode *&b) //�ݻٶ�����
{
    if (b != NULL)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b, ElemType x) //Ѱ��ֵΪx�Ľ��
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

BTNode *LchildNode(BTNode *p) //�������ӽ��
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) //�����Һ��ӽ��
{
    return p->rchild;
}

int BTHeight(BTNode *b) //����߶�
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

void DispBTree(BTNode *b) //���������
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
//��������ĵݹ���ʽ
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
//��������ĵݹ��㷨
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
//����ǰ��������Ƴ�����������
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

void Thread(TBTNode *&p) //���ɶ�����������
{
    if (p != NULL)
    {
        Thread(p->lchild);
        if (p->lchild == NULL) //�ڵ�����Ϊ��ʱ��ֱ��ָ��ǰ���Ľڵ�����
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        else
            p->ltag = 0;

        if (pre->rchild == NULL) //�Һ���Ϊ��ʱ��ָ���̵Ľ������λ��
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

TBTNode *CreateThread(TBTNode *b) //�Ѷ�����ת������������ʽ
{
    TBTNode *root;
    root = (BTNode *)malloc(sizeof(BTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;

    if (b == NULL)
        root->lchild = root; //ԭ������Ϊ�գ���ָ��ָ���Լ�root
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
            p = p->lchild;                      //�ҵ�����ĵ�һ���ڵ�
        printf("%c", p->data);                  //���������˵�����Ѿ����������ҵ�Ҷ�ӽڵ㣬ֱ�����
        while (p->rtag == 1 && p->rchild != tb) //����������е���һ���ڵ�ֵ
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild; //���ݵ�p��ǰһ���ڵ������ֱ������һ�����Һ��ӽڵ�
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