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
    int ltag, rtag;      //�����ı��
    struct node* lchild;
    struct node* rchild;
}BTNode;

BTNode * pre;//ȫ�ֱ�����ָ������


//Ѱ�Ҷ�Ӧx���Ĳ���
int Level(BTNode* b, ElemType x, int h);
//Ѱ�Ҷ�Ӧx���Ĳ���
void LevalNodeNum(BTNode* b, int h, int k, int& n);
//����������
void CreateBTree(BTNode*& b, char* str);
//�ݻٶ�����
void DestoryBTree(BTNode*& b);
//Ѱ��ֵΪx�Ľ��
BTNode* FindNode(BTNode* b, ElemType x);
//�������ӽ��
BTNode* LchildNode(BTNode* p);
//�����Һ��ӽ��
BTNode* RchildNode(BTNode* p);
//����߶�
int BTHeight(BTNode* b);  
//���������
void DispBTree(BTNode* b); 
//�������
void PreOrder(BTNode* b);
//�������
void InOrder(BTNode* b);
//�������
void PostOrder(BTNode* b);

 
#endif