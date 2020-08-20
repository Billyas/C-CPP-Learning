
# include "head.h"
# include "BTNode.cpp"
# include "TBNode.cpp"

int main ()
{
    BTNode * T, *G;
    char a[] = "A(B(D(,G)),C(E,F))";
    CreateBTree(T,a);

    G=CreateThread(T);

  //  DispBTree(T);

   ThInOrder(G);

    putchar(10);
    system("pause");
}

/*
#ifndef _HEAD_H
#define _HEAD_H
 
#endif
*/