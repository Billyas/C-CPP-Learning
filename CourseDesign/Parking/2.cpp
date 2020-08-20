#include "head.h"

//���ص�ǰ���ڼ�ʱ��
struct tm *ShowTime(void)
{
    char str[100];
    time_t t;
    struct tm *lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(str, 100, "%Y-%m-%d  %H:%M:%S ", lt);
    printf("��ǰ���ڼ�ʱ����:\n%s\n", str);

    return lt;
}
//����Unixʱ���
time_t UnixTime(void)
{
    char str[80];
    time_t t;
    struct tm *lt;
    t = time(NULL);
    lt = localtime(&t);
    strftime(str, 80, "%Y-%m-%d  %H:%M:%S ", lt);
    //printf("\n��ǰ���ڼ�ʱ����:\n%d-%d-%d  %d:%d:%d \n", lt->tm_year, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    printf("\n��ǰ���ڼ�ʱ����:\n%s\n", str);
    return t;
}
//Unixʱ���ת���ɱ���ʱ��str����ʾ
char *TransformTime(time_t t)
{
    char *str;
    struct tm *lt;
    lt = localtime(&t);
    strftime(str, 100, "%Y-%m-%d  %H:%M:%S ", lt);
    printf("��ǰ���ڼ�ʱ����:\n%s\n", str);
    return str;
}

void menu()
{
    printf("\t**************************************************\t\n");
    printf("\t               ͣ������ϵͳ                    \t\n\n");
    printf("\tͣ��λ��������%d\tͣ��λʣ�ࣺ%d\t��λ������%d   \t\n\n", maxsize, maxsize - Park_Num, PrePark_Num);
    printf("\t             1.�����Ǽ�                        \t\n\n");
    printf("\t             2.ͣ���Ǽ�                        \t\n\n");
    printf("\t             3.�뿪�Ǽ�                      \t\n\n");
    printf("\t             4.�˳�                            \t\n\n");
    printf("\t**************************************************\t\n");
}

//�򳵵ǼǺ���
void Pre_Park(SqQueue *qu)
{
    Car c;
    getchar();
    if (PrePark_Num < MaxSize)
    {
        printf("��������ĳ����ƺ�:");
        scanf("%[^\n]", c.a);
        //printf("%s", c.a);
        c.wait = PrePark_Num + 1; //��¼���ں���λ��
        PrePark_Num++;
        c.park = -1;
        if (enQueue(qu, c)) //������
            printf("�ɹ�����������ȴ�ͣ���У������ĵȴ�^-^\n");
    }
    else
        printf("�ǳ���Ǹ����λ�Ѿ�����-_-\n");
}

//����ͣ�����Ǽ�
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
            printf("�ɹ�����ͣ������ͣ���ķ�����ÿСʱ%dԪRMB����ǵü�ʱ�ᳵŶ��^-^\n", Price);
    }
    else
        printf("ʮ�ֱ�Ǹ��ͣ��λ�Ѿ����ˣ��������ĵȴ�\n");
}

//ͣ������ͳ��
double ParkingFee(Car c)
{
    double time;
    c.finish = UnixTime();

    time = difftime(c.finish, c.start);
    printf("��һ��ͣ��%.2fСʱ\n", time / 3600);
    return (time / 3600 * Price); //time������Ϊ��λ�ģ��۸�ʱ����Ӽ���
}

//�˳�ͣ��λ
void Exit(SqStack *st)
{
    char s[20];
    Car c[maxsize], g;
    int k, i = 0, h;
    printf("���������ĳ��ƺţ�");
    getchar();
    scanf("%[^\n]", s);
    //printf("%s\n", s);

    if ((k = ElemEmpty(st, s)) != 0)
    {
        printf("����ͣ��λ����%d�ţ�����Э�������Ƴ�ͣ���������Ե�Ƭ�̡�\n", k);
        GetTop(st, g);
        while (strcmp(g.a, s) != 0)
        {
            i++;
            Pop(st, c[i]);
            printf("���ƺ�Ϊ��%s�ĳ���ʱ�뿪��ͣ����\n", c[i].a);
            GetTop(st, g);
        }
        printf("����������ʻ��ͣ�������밲ȫ��ʻ��");
        Pop(st, g); //��ջ
        Park_Num--;
        printf("������ͣ��������%.2f,�뼰ʱ�ɷѡ�", ParkingFee(g));
        printf("\n�ɹ�ʻ����\n");

        if (i)
            while (i != 0)
            {
                Push(st, c[i]);
                printf("���ƺ�Ϊ��%s�ĳ����»ص���ͣ����\n", c[i].a);
                i--;
            }
    }
    else
        printf("δ�ҵ����ĳ�������ȷ���Ƿ��Ѿ�ͣ��ͣ������-_-\n");
}