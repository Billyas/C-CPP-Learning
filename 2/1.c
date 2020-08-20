# include <stdio.h>
# include <string.h>

int main ()
{
    char s[100];
    int i=0, count=0;
    printf("enter input sting\n");
    gets(s);

    while(s[i]!='\0'){
        if(s[i]>='a'&&s[i]<='z')
            count++;
            i++;
    }
    printf("%d\n",count);
    
}