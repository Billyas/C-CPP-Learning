# include "head.h"
# include "source.cpp"

int main ()
{
    RecType a[MAX];
    int i, k;
    srand((unsigned)time(NULL));
    menu();
    printf("请选择操作：");
    scanf("%d",&k);

    while(k!=7)
    {
        switch(k) {
            case 1:  FirstFun(a,MAX);  break;
            case 2:  SecondFun(a,MAX); break;
            case 3:  ThirdFun(a,MAX);  break;
            case 4:  FourthFun(a,MAX); break;
            case 5:  FifthFun(a,MAX);  break;
            case 6:  SixthFun(a,MAX);  break;
            default:   break;
        }
        
        system("pause");
        system("cls");
        menu();
        printf("请选择操作：");
        scanf("%d",&k);

    }


    system("pause");
    return 0;
}