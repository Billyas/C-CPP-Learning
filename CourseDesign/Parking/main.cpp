#include "head.h"
#include "stack.cpp"
#include "queue.cpp"
#include "2.cpp"

int main()
{
    int k;
    SqStack *st; //ͣ��λ��ջ�ṹ
    SqQueue *qu; //��λ�Ķ��нṹ
    InitQueue(qu);
    InitStack(st);
    ShowTime();
    menu();

    printf("������ѡ��");
    scanf("%d", &k);
    while (k != 4)
    {
        switch (k)
        {
        case 1:
            Pre_Park(qu);
            break;
        case 2:
            Park(st, qu);
            break;
        case 3:
            Exit(st);
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
        menu();
        printf("������ѡ��");
        scanf("%d", &k);
    }

    system("pause");
    return 0;
}

/* Pre_Park(qu);
    Park(st, qu);
    getchar(); //////ע����ںܶ�ط���Ҫ��գ�
    Pre_Park(qu);
    Park(st, qu);
    Exit(st);*/