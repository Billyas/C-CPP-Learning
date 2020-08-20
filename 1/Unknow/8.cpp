#include <stdio.h>
int main()
{
    int m,a[100],h;
    printf("ÇëÊä³öMµÄÖµ£º");
    scanf("%d",&m);

    for(int i=0;i<m;i++){

        scanf("%d",&a[i]);
    }

    for(int i=0; i<m;i++){
        if(a[i]%2==0)
            printf("%d ",a[i]);
    }
    
}