#include "head.h"
// 一些二叉树的一些算法
int Level(BTNode * b, ElemType x, int h)
//寻找对应x结点的层数
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
//在k层有多少个结点
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