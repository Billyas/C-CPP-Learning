/* 二叉树的链式存储结构
 * 2020/5/7
 * 天气多云
 */
# include <stdio.h>
# include <stdlib.h>
# define ElemType char
# define MaxSize 100
#define maxsize 100
typedef struct node
{
    ElemType data;
    struct node* lchild;
    struct node* rchild;
}BTNode;



typedef struct SSS{
    BTNode*  data[maxsize];
    int front;
    int rear;
}SqQueue;

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

bool deQueue(SqQueue *& q, BTNode* &e)
{
    if(q->front==q->rear)
        return false;

     q->front=(q->front + 1)%maxsize;   
    e=q->data[q->front];

     return true;    
}



void CreateBTree(BTNode*& b, char* str)//创建二叉树
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

void LevelOrder(BTNode * b)
//层次遍历的算法
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

BTNode* CreateBTree1(char *pre, char *in, int n)
//根据前序和中序推出二叉树序列
{
    BTNode * b;
    char *p;
    int k;
    if(n<=0) return NULL;
    b=(BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;

    for(p = in; p < in+n; p++)
        if(*p == *pre)  break;

    k = p-in;
    b->lchild=CreateBTree1(pre+1, in, k);
    b->rchild=CreateBTree1(pre+k+1, p+1, n-k-1);
    return b;
}

BTNode *CreateBtree2(char *post, char *in, int n)
//根据后序和中序来还原二叉树
{
    BTNode *b;
    char r,*p;
    int k;
    if(n<=0) return NULL;
    r= *(post+n-1);
    b=(BTNode*)malloc(sizeof(BTNode));
    b->data=r;

    for(p = in; p < in+n; p++)
        if(*p==r) break;

    k=p-in;
    b->lchild=CreateBtree2(post,in,k);
    b->rchild=CreateBtree2(post+k,p+1,n-k-1);
    return b;
}


int main()
{
    BTNode* T, * h;
    char a[] = "A(B(D(,G)),C(E,F))";
    CreateBTree(T, a);

    h = FindNode(T, 'A');
    printf("%c\n", h->data);

    printf("%d\n", BTHeight(T));

    DispBTree(T);

    printf("\n This is the three type travelsal:\n");
    printf("preorder:");
    PreOrder(T);
    putchar(10);

    printf("inorder:");
    InOrder(T);
    putchar(10);

    printf("postorder");
    PostOrder(T);
    putchar(10);
    
    int k = 1;
    printf("\nNOde 'A' is in the %d level.\n",Level(T , 'C', k));
    
    int p=0;
    LevalNodeNum(T, 1, 4, p);
    printf("\nThe level 4 have %d Node.",p);

    printf("\n\nthis is the levelorder:");
    LevelOrder(T);
    
    putchar(10);
    system("pause");
    return 0;

}