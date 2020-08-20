# include <stdio.h>
# include <math.h>
# include <stdlib.h>
int main ()
{
    float k;
    for(int i = 1; i <= 10000; i++){
        k=1.0/i;
        printf("%f\n",pow(i,k));
//神奇的开n次方出来
    }
    
    putchar(10);
    system("pause");
    return 0;
    
}