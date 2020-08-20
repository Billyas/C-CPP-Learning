/* 2020/05/10
 * ���꣬��ѩ����ѧ��
 * �һ�û�С�������
 * ���鲻���
 * 1:�����������ֱ���
*/
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


//���еĻ�������
void InitQueue(SqQueue *& q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

void DestoryQueue(SqQueue *& q)
{
    free(q);
}

bool QueueEmpty(SqQueue * q)
{
    return (q->front==q->rear);
}

bool enQueue (SqQueue *& q,BTNode* e)
{
    if((q->rear+1)%maxsize==q->front)
        return false;
    q->rear=(q->rear+1)%maxsize;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *& q, BTNode*& e)
{
    if(q->front==q->rear)
        return false;

     q->front=(q->front + 1)%maxsize;   
    e=q->data[q->front];

     return true;    
}







void CreateBTree(BTNode*& b, char* str)//����������
{
    BTNode* St[MaxSize], * p;
    int top = -1, k, j = 0;
    char ch;
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

BTNode* FindNode(BTNode* b, elemtype x)//Ѱ��ֵΪx�Ľ��
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

void LevelOrder(BTNode * b)
//��α������㷨
{
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);
    enQueue(qu, b);

    while(!QueueEmpty(qu))
    {
        deQueue(qu, p);
        printf("%c ",p->data);
        if(p->lchild!=NULL)
            enQueue(qu, p->lchild);
        
        if(p->rchild!=NULL)
            enQueue(qu, p->rchild);
    }
}

int main ()
{
    char a[100];
    BTNode* T;
    scanf("%s",a);
    
    CreateBTree(T, a);
    DispBTree(T);
    putchar(10);

    PreOrder(T);
    putchar(10);
    PreOrder(T);
    putchar(10);

    InOrder(T);
    putchar(10);
    InOrder(T);
    putchar(10); 

    PostOrder(T);
    putchar(10);
    PostOrder(T);
    putchar(10);

    LevelOrder(T);
    putchar(10);
    system("pause");
    return 0;
}
//����
//A(B(D,E(G,)),C(,F))