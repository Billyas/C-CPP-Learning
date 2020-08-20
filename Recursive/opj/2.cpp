//十进制转换成二进制的递归算法
#include <stdio.h>
#include <stdlib.h>

void fun (int h)
{
    if(h<2)
        printf("%d",h);
    else {
        
        fun(h/2);
        printf("%d",h%2);

    }
}

int main ()
{
    int i=0,h;
    scanf("%d",&h);
    fun(h);
    system("pause");
    return 0;
}