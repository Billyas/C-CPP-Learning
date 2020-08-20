#include "head.h"

//返回当前日期及时间
struct tm *ShowTime(void)
{
    char str[100];
    time_t t;
    struct tm *lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(str, 100, "%Y-%m-%d  %H:%M:%S ", lt);
    printf("当前日期及时间是:\n%s\n", str);

    return lt;
}
//返回Unix时间戳
time_t UnixTime(void)
{
    char str[80];
    time_t t;
    struct tm *lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(str, 80, "%Y-%m-%d  %H:%M:%S ", lt);
    //printf("\n当前日期及时间是:\n%d-%d-%d  %d:%d:%d \n", lt->tm_year, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    printf("\n当前日期及时间是:\n%s\n", str);
    return t;
}
//Unix时间戳转换成本地时间str并显示
char *TransformTime(time_t t)
{
    char *str;
    struct tm *lt;
    lt = localtime(&t);
    strftime(str, 100, "%Y-%m-%d  %H:%M:%S ", lt);
    printf("当前日期及时间是:\n%s\n", str);
    return str;
}

void menu()
{
    printf("\t**************************************************\t\n");
    printf("\t               停车管理系统                    \t\n\n");
    printf("\t停车位总数量：%d\t停车位剩余：%d\t候车位数量：%d   \t\n\n", maxsize, maxsize - Park_Num, PrePark_Num);
    printf("\t             1.候车区登记                        \t\n\n");
    printf("\t             2.停车登记                        \t\n\n");
    printf("\t             3.离开登记                      \t\n\n");
    printf("\t             4.退出                            \t\n\n");
    printf("\t**************************************************\t\n");
}

//候车登记函数
void Pre_Park(SqQueue *qu)
{
    Car c;
    getchar();
    if (PrePark_Num < MaxSize)
    {
        printf("请输入你的车号牌号:");
        scanf("%[^\n]", c.a);
        //printf("%s", c.a);
        c.wait = PrePark_Num + 1; //记录其在候车区位置
        PrePark_Num++;
        c.park = -1;
        if (enQueue(qu, c)) //进队列
            printf("成功进入候车区，等待停车中，请耐心等待^-^\n");
    }
    else
        printf("非常抱歉，候车位已经满了-_-\n");
}

//进入停车区登记
void Park(SqStack *st, SqQueue *qu)
{
    Car c;
    if (Park_Num < maxsize)
    {
        deQueue(qu, c);
        c.park = Park_Num + 1;
        Park_Num++;
        PrePark_Num--;
        c.wait = -1; //out prepark area
        c.start = UnixTime();
        if (Push(st, c))
            printf("成功进入停车区，停车的费用是每小时%d元RMB，请记得及时提车哦！^-^\n", Price);
    }
    else
        printf("十分抱歉，停车位已经满了，请您耐心等待\n");
}

//停车费用统计
double ParkingFee(Car c)
{
    double time;
    c.finish = UnixTime();

    time = difftime(c.finish, c.start);
    printf("您一共停留%.2f小时\n", time / 3600);
    return (time / 3600 * Price); //time是以秒为单位的，价格按时间分钟计算
}

//退出停车位
void Exit(SqStack *st)
{
    char s[20];
    Car c[maxsize], g;
    int k, i = 0, h;
    printf("请输入您的车牌号：");
    getchar();
    scanf("%[^\n]", s);
    //printf("%s\n", s);

    if ((k = ElemEmpty(st, s)) != 0)
    {
        printf("您的停车位置是%d号，正在协调帮你移出停车场，请稍等片刻。\n", k);
        GetTop(st, g);
        while (strcmp(g.a, s) != 0)
        {
            i++;
            Pop(st, c[i]);
            printf("车牌号为：%s的车暂时离开了停车区\n", c[i].a);
            GetTop(st, g);
        }
        printf("现在您可以驶出停车场，请安全驾驶！");
        Pop(st, g); //出栈
        Park_Num--;
        printf("您本次停车费用是%.2f,请及时缴费。", ParkingFee(g));
        printf("\n成功驶出！\n");

        if (i)
            while (i != 0)
            {
                Push(st, c[i]);
                printf("车牌号为：%s的车重新回到了停车区\n", c[i].a);
                i--;
            }
    }
    else
        printf("未找到您的车辆，请确认是否已经停入停车区。-_-\n");
}