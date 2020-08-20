/**
 * 2020/6/4
 * ����
**/
/**
 * �����������Ļ�������
 * (1) �����������нڵ�С�ڸ��ڵ�
 * (2) ���������ǿգ��������������нڵ�ֵ���ڸ��ڵ�
 * (3) ���ڵ�����ҽڵ㱾������һ������������    ^^^�úڰ� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KeyType int
#define InfoType int
//////////////////////////////////
//�����������Ľṹ�嶨������
typedef struct node
{
    KeyType key;         //Ԫ������
    InfoType data;       //�ؼ�����
    struct node *lchild; //����ָ��
    struct node *rchild; //�Һ���ָ��
} BSTNode;
/////////////////////////////////////////////
//�����������Ĵ����Ͳ���
//�����㷨��bt���������kΪ����ֵ
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
//�������Ĵ����㷨
//��n�����͵����������Ķ�����������
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
//�����������Ĳ��Һ���
BSTNode *SearchBST(BSTNode *bt, KeyType k)
{
    if (bt == NULL || bt->key == k)
        return bt;
    if (k < bt->key)
        return SearchBST(bt->lchild, k);
    else
        return SearchBST(bt->rchild, k);
}
//������˫�׽ڵ�ĺ���
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
//��������ɾ�������������ĺ���
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
//�������������
void inorder(BSTNode *t) //�����������������
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
    printf("                  �����������Ļ�������                 \n");
    printf("                 1.��������������                      \n");
    printf("                 2.�������������                      \n");
    printf("                 3.�����������������                   \n");
    printf("                 4.ɾ������������                       \n");
    printf("                 5.�˳�                                \n");
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
    printf("�����ѡ��");
    scanf("%d", &k);

    while (k != 5)
    {
        switch (k)
        {
        case 1:
            int b;
            printf("��������Ҫ��������ĸ���:");
            scanf("%d", &b);
            
            printf("�����������:");

            for(int i=0 ;i<b; i++) {
                if(i!=b-1)  scanf("%d ",&a[i]);
                else        scanf("%d",&a[i]);
            }
            Bt = CreateBST(a, b);
            printf("�����ɹ���\n");
            break;

        case 2:
            printf("������Ҫ���������:");
            scanf("%d", &e);
            if (InsertBST(Bt, e) == true)
                printf("����ɹ���\n");
            else
                printf("����ʧ�ܣ��Ѿ�������ͬ��Ԫ�ء�\n");
            break;

        case 3:
            printf("��������������Ľ��:\n");
            inorder(Bt);
            printf("\n\n");
            break;
 
        case 4:
            printf("��������ҪԪ��:");
            scanf("%d",&e);
            if (DeleteBST(Bt,e) == true)
                printf("ɾ���ɹ�\n");
            else
                printf("ɾ��ʧ��\n");
            break;

        default : 
            break;

        }
        system("pause");
        system("cls");
        menu();
        printf("�����ѡ��:");
        scanf("%d", &k);
    }

    //printf("\n\n");
    //inorder(Bt);
    //DeleteBST(Bt, 4);

    system("pause");
    return 0;
}
