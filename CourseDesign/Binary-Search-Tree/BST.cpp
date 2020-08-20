/**
 * 2020/6/4
 * 晴朗
**/
/**
 * 二叉排序树的基本定义
 * (1) 左子树的所有节点小于根节点
 * (2) 若右子树非空，则右子树的所有节点值大于根节点
 * (3) 根节点的左右节点本身又是一个二叉排序树    ^^^敲黑板 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KeyType int
#define InfoType int
//////////////////////////////////
//二叉排序树的结构体定义类型
typedef struct node
{
    KeyType key;         //元素类型
    InfoType data;       //关键字项
    struct node *lchild; //左孩子指针
    struct node *rchild; //右孩子指针
} BSTNode;
/////////////////////////////////////////////
//二叉排序树的创建和插入
//插入算法，bt插入的树，k为插入值
bool InsertBST(BSTNode *&bt, KeyType k)
{
    if (bt == NULL)
    {
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = NULL;
        return true;
    }
    else if (k == bt->key)
        return false;
    else if (k < bt->key)
        return InsertBST(bt->lchild, k);
    else if (k > bt->key)
        return InsertBST(bt->rchild, k);
}
///////////////////////////////////////////
//二叉树的创建算法
//对n个类型的树建立他的二叉树排序树
BSTNode *CreateBST(KeyType a[], int n)
{
    BSTNode *bt = NULL;
    int i = 0;
    while (i < n)
    {
        InsertBST(bt, a[i]);
        i++;
    }
    return bt;
}
////////////////////////////////////
//二叉排序树的查找函数
BSTNode *SearchBST(BSTNode *bt, KeyType k)
{
    if (bt == NULL || bt->key == k)
        return bt;
    if (k < bt->key)
        return SearchBST(bt->lchild, k);
    else
        return SearchBST(bt->rchild, k);
}
//查找其双亲节点的函数
BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f)
{
    if (bt == NULL)
    {
        f1 = NULL;
        return (NULL);
    }
    else if (k == bt->key)
    {
        f = f1;
        return bt;
    }
    else if (k < bt->key)
        return SearchBST1(bt->lchild, k, bt, f);
    else
        return SearchBST1(bt->rchild, k, bt, f);
}

//////////////////////////////////////////////////////////////
//最完美的删除二叉排序树的函数
void Deletel(BSTNode *p, BSTNode *&r)
{
    BSTNode *q;
    if (r->rchild != NULL)
        Deletel(p, r->rchild);
    else
    {
        p->data = r->data;
        p->key = r->key;
        q = r;
        r = r->lchild;
        free(q);
    }
}
void Delete(BSTNode *&p)
{
    BSTNode *q;
    if (p->rchild == NULL)
    {
        q = p;
        p = p->lchild;
        free(q);
    }
    else if (p->lchild == NULL)
    {
        q = p;
        p = p->rchild;
        free(q);
    }
    else
        Deletel(p, p->lchild);
}

bool DeleteBST(BSTNode *&bt, KeyType k)
{
    if (bt == NULL)
        return false;
    else
    {
        if (k < bt->key)
            return DeleteBST(bt->lchild, k);
        else if (k > bt->key)
            return DeleteBST(bt->rchild, k);
        else
        {
            Delete(bt);
            return true;
        }
    }
}
////////////////////////////////////
//中序遍历二叉树
void inorder(BSTNode *t) //中序遍历二叉排序树
{
    if (t)
    {
        inorder(t->lchild);
        printf("%8d", t->key);
        inorder(t->rchild);
    }
}
void menu()
{
    printf("******************************************************\n");
    printf("                  二叉排序树的基本操作                 \n");
    printf("                 1.创建二叉排序树                      \n");
    printf("                 2.插入二叉排序树                      \n");
    printf("                 3.中序遍历二叉排序树                   \n");
    printf("                 4.删除二叉排序树                       \n");
    printf("                 5.退出                                \n");
    printf("******************************************************\n");
}
////////////////////////////////////
int main()
{
    BSTNode *Bt, *f1, *f;
    int b[100], k, e;
    int a[10];
    //Bt = CreateBST(a, 10);
    //SearchBST(Bt, 6);
    //SearchBST1(Bt, 6, f1, f);
    menu();
    printf("请操作选择：");
    scanf("%d", &k);

    while (k != 5)
    {
        switch (k)
        {
        case 1:
            int b;
            printf("请输入需要排序的数的个数:");
            scanf("%d", &b);
            
            printf("请输入你的数:");

            for(int i=0 ;i<b; i++) {
                if(i!=b-1)  scanf("%d ",&a[i]);
                else        scanf("%d",&a[i]);
            }
            Bt = CreateBST(a, b);
            printf("创建成功！\n");
            break;

        case 2:
            printf("请输入要插入的数字:");
            scanf("%d", &e);
            if (InsertBST(Bt, e) == true)
                printf("插入成功！\n");
            else
                printf("插入失败，已经存在相同的元素。\n");
            break;

        case 3:
            printf("以下是中序遍历的结果:\n");
            inorder(Bt);
            printf("\n\n");
            break;
 
        case 4:
            printf("请输入你要元素:");
            scanf("%d",&e);
            if (DeleteBST(Bt,e) == true)
                printf("删除成功\n");
            else
                printf("删除失败\n");
            break;

        default : 
            break;

        }
        system("pause");
        system("cls");
        menu();
        printf("请操作选择:");
        scanf("%d", &k);
    }

    //printf("\n\n");
    //inorder(Bt);
    //DeleteBST(Bt, 4);

    system("pause");
    return 0;
}
