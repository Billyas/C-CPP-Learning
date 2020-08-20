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
    char cd[N];    //存放前节点
    int start;     //表示cd【start。。n0】部分是哈夫曼码
}HCode;           


# endif