#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=2;
    printf("This is a test file!\r\n¡Ë—©∑º is %d%c\r\nInput a number: ",n,n+64);
    scanf("%d",&n);
    printf("The number is %d\n",n);
    for(int i = 0; i < n; i++ ){
           printf("%d\n",n);
    }



    system("pause");
    return 0;
}