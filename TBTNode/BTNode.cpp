/* 二叉树的链式存储结构
 * 2020/5/7
 * 天气多云
 */
# include "head.h"

/* 2020/5/11
 * 重新编码成多文件的形式
 * 天气晴*****
 */
////interesting

//以下是主要的二叉树的操作类型函数
void CreateBTree(BTNode*& b, char* str)//创建二叉树
{
    BTNode* St[MaxSize], * p;
    int top = -1, k, j = 0;
    char ch;
    p = (BTNode*)malloc(sizeof(BTNode));
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

BTNode* FindNode(BTNode* b, ElemType x)//寻找值为x的结点
{
    BTNode* p;
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

BTNode* LchildNode(BTNode* p)//返回左孩子结点
{
    return p->lchild;
}

BTNode* RchildNode(BTNode* p)//返回右孩子结点
{
    return p->rchild;
}

int BTHeight(BTNode* b)  //输出高度
{
    int lchildh, rchildh;
    if (b == NULL)  return 0;
    else
    {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return(lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
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

void PreOrder(BTNode * b)
//先序遍历的递归形式
{
    if(b!=NULL)
    {
        printf("%c ",b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode * b)
//中序遍历的递归算法
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        printf("%c ",b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode * b)
//后序遍历的递归算法 
{
    if(b!=NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ",b->data);
    }
}

