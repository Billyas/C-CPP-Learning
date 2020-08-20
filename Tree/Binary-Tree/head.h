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

int Level(BTNode* b, ElemType x, int h);//Ѱ�Ҷ�Ӧx���Ĳ���

void LevalNodeNum(BTNode* b, int h, int k, int& n);//Ѱ�Ҷ�Ӧx���Ĳ���

void CreateBTree(BTNode*& b, char* str);//����������

void DestoryBTree(BTNode*& b);//�ݻٶ�����

BTNode* FindNode(BTNode* b, ElemType x);//Ѱ��ֵΪx�Ľ��

BTNode* LchildNode(BTNode* p);//�������ӽ��

BTNode* RchildNode(BTNode* p);//�����Һ��ӽ��

int BTHeight(BTNode* b);  //����߶�

void DispBTree(BTNode* b); //���������

void PreOrder(BTNode* b);//�������

void InOrder(BTNode* b);//�������

void PostOrder(BTNode* b);//�������

void LevelOrder(BTNode* b);//��α���

BTNode* CreateBTree1(char* pre, char* in, int n);//�����������Ƴ�������

BTNode* CreateBtree2(char* post, char* in, int n);//�����������Ƴ�������