# include "head.h"
//���ֳ������㷨
///////////////////////////////////////////////
//ֱ�Ӳ��������㷨
//ʱ�临�Ӷ�O(n^2)
void InsertSort(RecType R[], int n)
{
    int i, j;
    RecType tmp;

    for (i = 1; i < n; i++)    //forѭ����һ���Ƚ���n-1�Σ�if�ж����
    {
        if (R[i].key < R[i - 1].key) //һ������������Ĺؼ��֣��ͽ��в���
        {
            tmp = R[i];
            j = i - 1;
            compare++;
            do    //�����ƶ�һ��λ�ã��ڿռ��tmp��
            {
                R[j + 1] = R[j];
                move++;    //�ƶ���һ
                j--;
                compare++; //�Ƚϴ�����һ
            } while (j >= 0 && R[j].key > tmp.key);

            R[j + 1] = tmp; //����tmp���ڶ�Ӧ��λ��
            move+=2; //�ƶ���temp
        }
    }
    
}
////////////////////////////////////////////////////
//�۰�������� 
//�����������뵽�����������ǰ��Ĳ�������ʵ������������ֱ����
//�����������۰������Ѱ�ҵĸĽ��㷨
void BinInsertSort(RecType R[], int n)
{
    int i, j, low, high, mid;
    RecType tmp;

    for (i = 1; i < n; i++)  //�Ѿ��Ƚ���n-1��
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            low = 0;
            high = i - 1;
            
            compare++;

            while (low <= high)  
            {
                compare++;  //while����Ƚ�
                mid = (low + high) / 2;
                if (tmp.key < R[mid].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (j = i - 1; j >= high + 1; j--)
            {      
                R[j + 1] = R[j];
                move++;//�ƶ�������һ
            }
            R[high + 1] = tmp;
            move += 2;//tmp����
        }
    }

}
///////////////////////////////////////////////////
//ϣ�������㷨
void ShellSort(RecType R[], int n)
{
    int i, j, d;
    RecType tmp;
    d = n / 2;

    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            tmp = R[i];
            j = i - d;

            while (j >= 0 && tmp.key < R[j].key)
            {
                compare++;
                move++;
                R[j + d] = R[j];
                j = j - d;
            }
            R[j + d] = tmp;
            move += 2;//tmp�������β���
        }
        d = d / 2;
    }
}
///////////////////////////////////////////////////
//ð�������㷨
void BubbleSort(RecType R[], int n)
{
    int i, j;
    bool exchange;
    RecType tmp;

    for (i = 0; i < n - 1; i++)
    {
        exchange = false;

        for (j = n - 1; j > i; j--)
            if (R[j].key < R[j - 1].key)
            {
                compare ++;
                move += 3;
                tmp = R[j - 1];
                R[j - 1] = R[j];
                R[j] = tmp;
                exchange = true;
            }

        if (!exchange)
            return;
    }
}
/////////////////////////////////////////////////////////
/*���������㷨*/
int partition(RecType R[], int s, int t) //һ�˻���
{
    int i = s, j = t;
    RecType tmp = R[i]; //��R[i]Ϊ��׼
    while (i < j)       //�����˽������м�ɨ��,ֱ��i=jΪֹ
    {
        while (j > i && R[j].key >= tmp.key)
        {
                j--;     //��������ɨ��,��һ��С��tmp.key��R[j]
                compare++;//���бȽ�
        }
        R[i] = R[j]; //�ҵ�������R[j],����R[i]��
        move++;      //�ƶ�+1
        while (i < j && R[i].key <= tmp.key)
        {    i++;      //��������ɨ��,��һ������tmp.key��R[i]
             compare++;//�Ƚϼ�һ
        }
        R[j] = R[i]; //�ҵ�������R[i],����R[j]��
        move++;      //�ƶ���һ
    }
    R[i] = tmp;
    move+=2; //temp�Ľ���
    return i;
}

void QuickSort(RecType R[], int s, int t)
//��R[s..t]��Ԫ�ؽ��п�������
{
    int i;
    if (s < t) //���������ٴ�������Ԫ�ص����
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1); //��������ݹ�����
        QuickSort(R, i + 1, t); //��������ݹ�����
    }
}
/////////////////////////////////////////////////////

void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.ֱ�Ӳ�������\n");
    printf("\t\t2.�۰��������\n");
    printf("\t\t3.ϣ������\n");
    printf("\t\t4.ð������\n");
    printf("\t\t5.��������\n");
    printf("\t\t6.Ч�ʱȽ�\n");
    printf("\t\t7.�˳�\n");
    printf("***************************************************\n");
}


//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void FirstFun(RecType a[], int n)
{
     int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);
    
    InsertSort(a, MAX);

    printf("\n\n\n����ֱ�Ӳ����������������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\nֱ�Ӳ������򷨣�\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    Analy[0].com = compare;
    Analy[0].mov = move;
    strcpy(Analy[0].name, "ֱ�Ӳ�������");
}
//�˵�2
void SecondFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    BinInsertSort(a, MAX);

    printf("\n\n\n�����۰�����������������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\n�۰��������\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    Analy[1].com = compare;
    Analy[1].mov = move;
    strcpy(Analy[1].name, "�۰��������");
}

//�˵�3
void ThirdFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    ShellSort(a,MAX);

        printf("\n\n\n����ϣ�������㷨����������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\nϣ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    Analy[2].com = compare;
    Analy[2].mov = move;
    strcpy(Analy[2].name, "ϣ�������㷨");
}
//�˵�4
void FourthFun(RecType a[], int n)
{
     int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);

    compare = 0;
    move = 0;
    BubbleSort(a,MAX);

     printf("\n\n\n����ð�����򷨺���������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
    
    printf("\n\nð�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    Analy[3].com = compare;
    Analy[3].mov = move;
    strcpy(Analy[3].name, "ð�������㷨");
}
//�˵�5
void FifthFun(RecType a[], int n)
{
    int i;
     for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');
        putchar(10);
    
    compare = 0;
    move = 0;
    QuickSort(a,0,MAX);
         printf("\n\n\n���ÿ��������㷨����������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 20 ? ' ' : '\n');

    printf("\n\n���������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    Analy[4].com = compare;
    Analy[4].mov = move;
    strcpy(Analy[4].name, "���������㷨");
}
//�˵�6
void SixthFun(RecType a[], int n)
{
    int i;
    printf("���������㷨�ıȽ����ƶ������ĶԱȣ�\n\n");
    //printf("   ����\t\t\t\t�Ƚϴ���\t\t\t�ƶ�����\n");
    printf("   ����          �Ƚϴ���          �ƶ�����\n");

    for(i = 0; i < 5; i++)
        printf("%-17s%-18d%d\n",Analy[i].name,Analy[i].com,Analy[i].mov);
}