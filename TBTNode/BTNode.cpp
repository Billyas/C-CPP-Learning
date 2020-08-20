/* ����������ʽ�洢�ṹ
 * 2020/5/7
 * ��������
 */
# include "head.h"

/* 2020/5/11
 * ���±���ɶ��ļ�����ʽ
 * ������*****
 */
////interesting

//��������Ҫ�Ķ������Ĳ������ͺ���
void CreateBTree(BTNode*& b, char* str)//����������
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

void DestoryBTree(BTNode*& b)//�ݻٶ�����
{
    if (b != NULL)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}

BTNode* FindNode(BTNode* b, ElemType x)//Ѱ��ֵΪx�Ľ��
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

BTNode* LchildNode(BTNode* p)//�������ӽ��
{
    return p->lchild;
}

BTNode* RchildNode(BTNode* p)//�����Һ��ӽ��
{
    return p->rchild;
}

int BTHeight(BTNode* b)  //����߶�
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

void DispBTree(BTNode* b) //���������
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
//��������ĵݹ���ʽ
{
    if(b!=NULL)
    {
        printf("%c ",b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode * b)
//��������ĵݹ��㷨
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        printf("%c ",b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode * b)
//��������ĵݹ��㷨 
{
    if(b!=NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ",b->data);
    }
}

