#include "head.h"
// һЩ��������һЩ�㷨
int Level(BTNode * b, ElemType x, int h)
//Ѱ�Ҷ�Ӧx���Ĳ���
{
    int l;
    if(b==NULL)
        return 0;
    else if(b->data==x)
        return h;
    else
    {
        l=Level(b->lchild, x, h+1);
        if(l)      return l;
        else       return Level(b->rchild, x, h+1);
        
    }  
}

void LevalNodeNum(BTNode *b, int h, int k, int &n)
//��k���ж��ٸ����
{
    if(b==NULL)   return;
    else
    {
        if(h==k)  n++;
        else if(h<k)
        {
            LevalNodeNum(b->lchild, h+1, k, n);
            LevalNodeNum(b->rchild, h+1, k, n);
        }
    }
    
}