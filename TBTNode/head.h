#ifndef _HEAD_H
#define _HEAD_H

# include <stdio.h>
# include <stdlib.h>

# define ElemType char
# define BTNode TBTNode
# define MaxSize 100
#define maxsize 100
typedef struct node
{
    ElemType data;        
    int ltag, rtag;      //线索的标记
    struct node* lchild;
    struct node* rchild;
}BTNode;

BTNode * pre;//全局变量的指针类型


//寻找对应x结点的层数
int Level(BTNode* b, ElemType x, int h);
//寻找对应x结点的层数
void LevalNodeNum(BTNode* b, int h, int k, int& n);
//创建二叉树
void CreateBTree(BTNode*& b, char* str);
//摧毁二叉树
void DestoryBTree(BTNode*& b);
//寻找值为x的结点
BTNode* FindNode(BTNode* b, ElemType x);
//返回左孩子结点
BTNode* LchildNode(BTNode* p);
//返回右孩子结点
BTNode* RchildNode(BTNode* p);
//输出高度
int BTHeight(BTNode* b);  
//输出二叉树
void DispBTree(BTNode* b); 
//先序遍历
void PreOrder(BTNode* b);
//中序遍历
void InOrder(BTNode* b);
//后序遍历
void PostOrder(BTNode* b);

 
#endif