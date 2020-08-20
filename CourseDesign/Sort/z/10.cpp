#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20002
typedef int KeyType;
typedef int InfoType;
typedef struct SS
{
    KeyType key;   //�ؼ�����
    InfoType data; //����������
} RecType;         //�����Ԫ�ص�����

//��������
void swap(RecType &a, RecType &b)
{
    RecType c;
    c = a;
    a = b;
    b = c;
}
int compare = 0 , move = 0;  //�ؼ��ֱȽϺ��ƶ��Ĵ���
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

            do    //�����ƶ�һ��λ�ã��ڿռ��tmp��
            {
                R[j + 1] = R[j];
                move++;    //�ƶ���һ
                j--;
                compare++; //�Ƚϴ�����һ
            } while (j >= 0 && R[j].key > tmp.key);

            R[j + 1] = tmp; //����tmp���ڶ�Ӧ��λ��
        }
    }
    compare += n-1;
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
        }
    }

    compare+=n-1;
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
                compare++;
        }
        R[i] = R[j]; //�ҵ�������R[j],����R[i]��
        move++;
        while (i < j && R[i].key <= tmp.key)
        {    i++;     //��������ɨ��,��һ������tmp.key��R[i]
             compare++;
        }
        R[j] = R[i]; //�ҵ�������R[i],����R[j]��
        move++;
    }
    R[i] = tmp;
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

int main()
{
    RecType a[MAX];
    int i;
    srand((unsigned)time(NULL));

    for (i = 0; i < MAX; i++)
        a[i].key = rand() % 100;
    printf("α��������ɵ�20002���������\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    /*ֱ�Ӳ������򷨵��������*/
    /*InsertSort(a, MAX);

    printf("\n\n\n����ֱ�Ӳ����������������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');

    printf("\n\nֱ�Ӳ������򷨣�\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);*/
    //һ���Ƚ���98240531�Σ��ƶ���98220530��
///////////////////////////////////////////////////////////////////////////////
    /*�۰�������򷨵��������*/
    /*   compare = 0;
       move = 0;
    BinInsertSort(a, MAX);

    printf("\n\n\n�����۰�����������������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\n�۰��������\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);*/
    //һ���Ƚ���275449�Σ��ƶ���98319559��
//////////////////////////////////////////////////////////////////////////////
    /*ϣ�������㷨*/
    /*compare = 0;
    move = 0;
    ShellSort(a,MAX);

        printf("\n\n\n����ϣ�������㷨����������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\nϣ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);*/
    //һ���Ƚ���215214�Σ��ƶ���215214��
/////////////////////////////////////////////////////////////////////////////
    /*ð������*/
   /* compare = 0;
    move = 0;
    BubbleSort(a,MAX);

     printf("\n\n\n����ð�����򷨺���������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');
    
    printf("\n\nð�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);*/
    //һ���Ƚ���99118844�Σ��ƶ���297356532��
//////////////////////////////////////////////////////////////////////////    
    /*���������㷨*/
    compare = 0;
    move = 0;
    QuickSort(a,0,MAX);
         printf("\n\n\n���ÿ��������㷨����������£�\n\n\n");
    for (i = 0; i < MAX; i++)
        printf("%3d%c", a[i].key, (i + 1) % 10 ? ' ' : '\n');

    printf("\n\n���������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n",compare,move);
    //һ���Ƚ���1939776�Σ��ƶ���86186��
///////////////////////////////////////////////////////////////////////////
    system("pause");
    return 0;
}