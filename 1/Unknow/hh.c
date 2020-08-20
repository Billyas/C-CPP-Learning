# include <stdio.h>
#include <stdlib.h>
float SB(float a)
{
    if(a>3) return 2*a+1;
    else if(a==3) return 10;
    else return 1.2;

}

int main ()
{
    float a,m;
    m=scanf("%f",&a);

    printf("%.3f\n",SB(a));
    system("pause");
}
