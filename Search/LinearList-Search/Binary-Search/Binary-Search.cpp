#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int InforType;
typedef struct head
{
    KeyType key;    //��Źؼ���
    InforType data; //����������
} RecType;          //����Ԫ������

//////////////////////////////////////////////////
//���ַ������۰���ҷ�
int BinSearch(RecType R[], int n, KeyType k)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (R[mid].key == k)
            return mid + 1;
        if (R[mid].key > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////
int main()
{
    int i = 0;
    RecType k[100];

    for (i = 0; i < 100; i++) //���ṹ�帳ֵ
        k[i].key = i + 1;

    printf("�۰뷨����---˳�����4���ڵ�λ����%d\n", BinSearch(k, 100, 4));
    system("pause");
    return 0;
}