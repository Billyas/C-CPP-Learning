#include "head.h"
#include "stack.cpp"
#include "queue.cpp"
#include "2.cpp"

int main()
{
    int k;
    SqStack *st; //停车位的栈结构
    SqQueue *qu; //候车位的队列结构
    InitQueue(qu);
    InitStack(st);
    ShowTime();
    menu();

    printf("请输入选择：");
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
        printf("请输入选择：");
        scanf("%d", &k);
    }

    system("pause");
    return 0;
}

/* Pre_Park(qu);
    Park(st, qu);
    getchar(); //////注意存在很多地方需要清空；
    Pre_Park(qu);
    Park(st, qu);
    Exit(st);*/