# ifndef _HEAD_H
# define _HEAD_H

# include <stdio.h>
# include <stdlib.h>
# define ElemType char
# define maxsize 100
# define N 100
typedef struct head1
{
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
}HTNode;

typedef struct SS
{
    char cd[N];    //���ǰ�ڵ�
    int start;     //��ʾcd��start����n0�������ǹ�������
}HCode;           


# endif