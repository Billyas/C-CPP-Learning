# include <stdio.h>
# include <stdlib.h>
# define ElemType BTNode
# define elemtype char
# define MaxSize 100
#define maxsize 100
typedef struct node
{
    elemtype data;
    struct node* lchild;
    struct node* rchild;
}BTNode;

typedef struct SSS{
    BTNode * data[maxsize];
    int front;
    int rear;
}SqQueue;
