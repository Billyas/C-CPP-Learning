#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int InforType;
typedef struct head
{
    KeyType key;    //��Źؼ���
    InforType data; //����������
} RecType;          //����Ԫ������

////////////////////////////////////////////////////////////
//˳�����
int SeqSearch(RecType R[], int n, KeyType k)
{
    int i = 0;
    while (i < n && R[i].key != k)
        i++;

    if (i >= n)
        return 0; ////δ�ҵ�����0��
    else
        return i + 1; //�߼��ϵ����
}

///�Ľ����˳����ң��������жϵĹ���
int SeqSearch1(RecType R[], int n, KeyType k)
{
    int i = 0;
    R[n].key = k;
    while (R[i].key != k)
        i++;

    if (i == n)
        return 0;
    else
        return i + 1;
}
/////////////////////////////////////////////////////////////
int main()
{
    int i = 0;
    RecType k[100];

    for (i = 0; i < 100; i++) //���ṹ�帳ֵ
        k[i].key = i + 1;

    printf("��˳�����9���ڵ�λ����%d\n", SeqSearch(k, 100, 9));
    printf("�Ľ������˳�����4���ڵ�λ����%d\n", SeqSearch1(k, 100, 4));
    return 0;
}