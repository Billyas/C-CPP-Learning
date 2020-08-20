# include <stdio.h>
# include <stdlib.h>

# define ElemType char
# define BTNode TBTNode
# define MaxSize 100
# define maxsize 100
typedef struct node
{
    ElemType data;        
    int ltag, rtag;      //线索的标记
    struct node* lchild;
    struct node* rchild;
}BTNode;

BTNode * pre;//全局变量的指针类型

void CreateBTree(BTNode*& b, char* str)//创建二叉树
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

void DestoryBTree(BTNode*& b)//摧毁二叉树
{
    if (b != NULL)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
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

void Thread(TBTNode *& p)   //生成二叉树的线索
{
    if(p!=NULL)
    {
        Thread(p->lchild);     
        if(p->lchild==NULL)   //节点左孩子为空时就直接指向前驱的节点线索
        {
            p->lchild = pre;
            p->ltag = 1;
            
        }
        else
            p->ltag = 0;

        if(pre->rchild == NULL)    //右孩子为空时则指向后继的结点线索位置
        {
            pre->rchild = p;
            pre->rtag = 1;

        }
        else 
            pre->rtag = 0;
        
        pre = p;
        Thread(p->rchild);
    }
}

TBTNode * CreateThread(TBTNode * b)        //把二叉链转换成线索的形式
{
    TBTNode *root;
    root = (BTNode * )malloc(sizeof(BTNode));
    root->ltag = 0;   root->rtag = 1;
    root->rchild = b;

    if(b == NULL)
        root->lchild = root;    //原二叉链为空，则指针指回自己root
    else
    {
        root->lchild = b;
        pre = root;
        Thread(b);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;
}

void ThInOrder(TBTNode * tb)
{
    TBTNode *p = tb->lchild;

    while(p!=tb)
    {
        while(p->ltag==0)  p = p->lchild;//找到中序的第一个节点
        printf("%c",p->data);            //如果无左孩子说明是已经到达了树梢的叶子节点，直接输出
        while(p->rtag==1&&p->rchild!=tb)  //输出在中序中的下一个节点值
        {
            p=p->rchild;
            printf("%c",p->data);
        } 
        p=p->rchild;                   //回溯到p的前一个节点或者是直接找下一个的右孩子节点

    }
}

int main ()
{
    BTNode * T, *G;
    char a[] = "A(B(D(,G)),C(E,F))";
    CreateBTree(T,a);
    DispBTree(T);
    printf("\n");
    
    G=CreateThread(T);


    ThInOrder(G);

    putchar(10);
    system("pause");
}