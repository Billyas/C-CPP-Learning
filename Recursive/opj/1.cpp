//µÝ¹éµ¹ÐòÊä³ö×Ö·û´®
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void fun(char a[],int j)
{
    if(a[j]=='#'){
        
    }else 
    {
        fun(a,j+1);
        printf("%c",a[j]);

    }
}

int main ()
{
    int i=0,n=0,j=0;
    char a[100];
    scanf("%s",a);
    n=strlen(a);
    a[n]='#';
    fun(a,j);
    system("pause");
    return 0;
}

