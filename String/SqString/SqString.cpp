#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct SSS
{
    char data[maxsize];
    int length;

}SqString;

void StrAssign(SqString & s, char cstr[])
{
    int i=0;
    for(i = 0; cstr[i] != '\0'; i++ )
         s.data[i]=cstr[i];
    s.length = i;
}

void DestoryStr(SqString &s)
{
}

void StrCopy(SqString &s,SqString t)
{
    int i=0;
    for(i = 0; i < t.length; i++){
        s.data[i] = t.data[i];
        s.length=t.length;
    }
}

bool StrEqual(SqString s,SqString t)
{
     int i;

    if(s.length!=t.length)
        return false;
    else 
    
        for(i = 0; i < s.length; i++)
        {
            if(s.data[i] != t.data[i])
                return false;
        }
    return true;
}

int StrLength(SqString s)
{
    return s.length;
}

SqString Concat(SqString s,SqString t)//��������
{
    int i;
    SqString str;
    str.length=s.length + t.length;

    for(i = 0; i < s.length; i++)
        str.data[i]=s.data[i];
    for(i = 0; i <t.length; i++)
        str.data[s.length+i]=t.data[i];
    return str;
}

SqString SubStr(SqString s, int i, int j) //��s�дӵ�i��λ�ÿ�ʼ����j���ַ����Ӵ�
{
    int k;
    SqString str;                         //���ÿմ�
    str.length = 0;

    if(i <= 0 || i>s.length || j < 0 || i+j-1>s.length)
        return str;                      //���󷵻ؿմ�
    
    for(k = i-1; k < i+j-1; k++)
       str.data[k-i+1]=s.data[k];

    str.length = j;
    return str;
    
}

SqString InsStr(SqString s1, int i,SqString s2)//��s2�嵽s1��iλ����
{
    int j;
    SqString str;
    str.length = 0;

    if(i <= 0|| i > s1.length)
        return str;
    
    for(j = 0; j < i-1; j++)
        str.data[j] = s1.data[j];

    for(j = 0; j < s2.length; j++)
        str.data[i+j-1] = s2.data[j]; 

    for(j=i-1; j<s1.length; j++)
        str.data[j+s2.length]=s1.data[j];
    
    str.length=s1.length+s2.length;
    return str;
}

SqString DelStr(SqString s,int i,int j)//��i��ɾ��j��Ԫ��
{
    int k;
    SqString str;
    str.length=0;

    if(i<=0 || i>s.length || i+j>s.length+1)
        return str;

    for(k = 0;k < i-1; k++)
        str.data[k]=s.data[k];

    for(k=i+j-1; k < s.length; k++ )
        str.data[k-j]=s.data[k];

    str.length=s.length-j;
    return str;
}

SqString RepStr(SqString s, int i,int j,SqString t) //��i-jλ�õĴ�����t
{
    int k;
    SqString str;
    str.length=0;

    if(i<=0 || i>s.length || i+j-1>s.length)
        return str;
    
    for(k = 0;k < i-1; k++)
       str.data[k]=s.data[k];
    
    for(k=0; k<t.length; k++)
       str.data[i+k-1]=t.data[k];

    for(k = i+j-1;k < s.length; k++)
       str.data[t.length+k-j]=s.data[k];

    str.length=s.length+t.length-j;
    return str;
}

void DispStr(SqString s)
{
    int i;
    if(s.length > 0)
    {
        for(i=0;i<s.length;i++)
            printf("%c",s.data[i]);
        
        printf("\n");

    }
}

int BF(SqString s,SqString t)
{
    int i=0,j=0;

    while(i<s.length&&j<t.length)
    {
        if(s.data[i]==t.data[j])
        {
            i++,j++;
        }
        else 
        {
            i=i-j+1; j=0;
        }
    }

    if(j>=t.length)
        return (i-t.length);
    else 
        return -1;
}

void GetNext(SqString t, int next[])
{
    int j,k;
    j=0; k=-1;
    next[0]=-1;
    while(j<t.length-1)
    {
        if(k==-1 || t.data[j]==t.data[k])
        {
            j++; k++;
            next[j]=k;

        }
        else
            k=next[k];
    }
}


int KMPIndex(SqString s, SqString t)
{
    int next[maxsize], i=0, j=0;
    GetNext(t,next);

    while(i<s.length&&j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }

    if(j>=t.length)
        return (i-t.length);
    else
        return (-1);
}

void GetNextval(SqString t, int nextval[])
{
    int j=0,k=-1;
    nextval[0]=-1;

    while(j<t.length)
    {
        if(k==-1 || t.data[j]==t.data[k])
        {
            j++; k++;
            if(t.data[j]!=t.data[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }
        else 
            k=nextval[k];
    }

}

int KMPIndex1(SqString s,SqString t)
{
    int nextval[maxsize],i=0,j=0;
    GetNextval(t,nextval);

    while(i<s.length&&j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++; j++;
        }
        else  
            j=nextval[j];
    }

    if(j>=t.length)
        return(i-t.length);
    else 
        return (-1);
}

int main ()
{
    int i=0;
    char a[]={"luck  dog"},b[]={"you"},c[]={"dog"};
    SqString s,p,q;
    StrAssign(s,a);
    StrAssign(p,b);
    StrAssign(q,c);

    DispStr(s);
    DispStr(p);
    DispStr(q);


    if(StrEqual(s,p)) printf("yes");
    else printf("no\n");

    printf("s���ĳ��ȣ�%d\n",StrLength(s));
       printf("����������\n");
        DispStr(Concat(s,p));
    printf("��s���ĵ�����λ��ȡ��λ���Ӵ�\n");
        DispStr(SubStr(s,6,3));
    printf("��s���ĵ�����λ�ò���p���Ӵ�\n");
        DispStr(InsStr(s,6,p));
    printf("��s���ĵ�����λ��ɾ����λ���Ӵ�\n");
        DispStr(DelStr(s,6,4));
    printf("��s���ĵ��ߵ�λ���滻��p���Ӵ�\n");
        DispStr(RepStr(s,7,3,p));
   // StrCopy(s,p);
    printf("�����㷨���Ӵ��Ƿ���ڣ�");
        printf("%d\n",BF(s,p));

    printf("KMP�����Ƿ�����Ӵ���");
        printf("%d\n",KMPIndex(s,q));

    printf("KMP��ǿ������Ƿ�����Ӵ���");
        printf("%d\n",KMPIndex1(s,q));

    system("pause");
    return 0;
}