# include <stdio.h>
# include <stdlib.h>
# define BTNode TBTNode
# define ElemType char
# define MaxSize 100
#define maxsize 100
typedef struct node
{
    ElemType data;
    int ltag, rtag;
    struct node* lchild;
    struct node* rchild;
}BTNode;

typedef struct SSS{
    ElemType data[maxsize];
    int front;
    int rear;
}SqQueue;

TBTNode* pre;

void InitQueue(SqQueue*& q);

void DestoryQueue(SqQueue*& q);

bool QueueEmpty(SqQueue* q);

bool enQueue(SqQueue*& q, BTNode* e);

bool deQueue(SqQueue*& q, BTNode*& e);

int Level(BTNode* b, ElemType x, int h);//寻找对应x结点的层数

void LevalNodeNum(BTNode* b, int h, int k, int& n);//寻找对应x结点的层数

void CreateBTree(BTNode*& b, char* str);//创建二叉树

void DestoryBTree(BTNode*& b);//摧毁二叉树

BTNode* FindNode(BTNode* b, ElemType x);//寻找值为x的结点

BTNode* LchildNode(BTNode* p);//返回左孩子结点

BTNode* RchildNode(BTNode* p);//返回右孩子结点

int BTHeight(BTNode* b);  //输出高度

void DispBTree(BTNode* b); //输出二叉树

void PreOrder(BTNode* b);//先序遍历

void InOrder(BTNode* b);//中序遍历

void PostOrder(BTNode* b);//后序遍历

void LevelOrder(BTNode* b);//层次遍历

BTNode* CreateBTree1(char* pre, char* in, int n);//先序与中序推出二叉树

BTNode* CreateBtree2(char* post, char* in, int n);//后序与中序推出二叉树