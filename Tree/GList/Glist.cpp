/**   ʫ��Զ��
 * ��������ز�������
 * 2020/5/01
 * Good Day
 **/
#include <stdio.h>
#include <stdlib.h>
#define ElemType char

typedef struct lnode
{
    int tag;     //�ڵ��ʾ��tag==0��ʾΪԭ�ӽڵ㣬tag==1����ʾΪ�ӱ�ڵ㡣
    union
    {
        ElemType data;//������
        struct lnode *sublist; //ָ���ӱ��ָ��
    }val;
    struct lnode * link;  //ָ����һ��Ԫ��
}GLNode;

int GLLength(GLNode * g)
{
    int n=0;
    GLNode *gl;
    while (gl!=NULL)
    {
        n++;
        gl=gl->link;
    }

    return n;
} 

int GLDepth (GLNode * g)
{
    GLNode *gl;
    int maxd=0, dep;
    if(g->tag==0)
        return 0;
    gl=g->val.sublist;

    if(gl==NULL)
        return 1;

    while(gl!=NULL){
        if(gl->tag==1)
        {
            dep=GLDepth(gl);
            if(dep>maxd)
                maxd=dep;
        }
        gl=gl->link;
    }

    return (maxd+1);
}

void DispGL (GLNode * g)  //��������
{
    if (g!=NULL)
    {
        if(g->tag==0)
            printf("%c",g->val.data);
        else 
            {
                printf("(");
                if(g->val.sublist==NULL)
                    printf("#");
                else 
                    DispGL(g->val.sublist);
                printf(")");    
            }

        if(g->link!=NULL)
        {
            printf(",");
            DispGL(g->link);
        }
    }
        
}

GLNode * CreatGL(char * &s)
{
    GLNode *g;
    char ch= *s++;
    if(ch!='\0')
    {
        g=(GLNode *)malloc(sizeof(GLNode));
        if(ch=='(')
        {
            g->tag=1;
            g->val.sublist=CreatGL(s);
        }
        else if(ch==')')
            g=NULL;
        else if(ch=='#')
            g=NULL;
        else
        {
            g->tag=0;
            g->val.data=ch;
        }
        
    }
    else 
        g=NULL;
    ch=*s++;
    if(g!=NULL){
        if(ch==',')
            g->link=CreatGL(s);
        else
            g->link=NULL;
    }
    return g;
}

void DestroyGL(GLNode *& g)
{
    GLNode *g1, *g2;
    g1=g->val.sublist;

    while(g1!=NULL)
    {
        if(g1->tag==0)
        {
            g2=g1->link;
            free(g1);
            g1=g2;
        }
        else
        {
            g2=g1->link;
            DestroyGL(g1);
            g1=g2;
        }
        
    }
    free(g);
}