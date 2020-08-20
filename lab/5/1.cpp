# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#define maxsize 100
typedef struct SSS
{
    char data[maxsize];
    int length;
}SqString;

void StrAssign(SqString & s, char cstr[]);

void DestoryStr(SqString &s);

void DispStr(SqString s);

int BF(SqString s,SqString t);

void GetNext(SqString t, int next[]);

int KMPIndex(SqString s, SqString t);

int StrCount2(SqString s,SqString t);

void GetNextval(SqString t, int nextval[]);

int KMPIndex1(SqString s,SqString t);

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

    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.data[i] == t.data[j])
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

int StrCount2(SqString s,SqString t)	
//����KMP�㷨��t��s�г��ֵĴ���
{  int i=0,j=0,count=0;
   int next[maxsize];
   GetNext(t,next);
   while (i<s.length && j<t.length) 
   {  if (j==-1 || s.data[i]==t.data[j])
      {  i++;				//i��j����1
         j++;
      }	
      else
         j=next[j]; 			//i���䣬j����
      if (j>=t.length)			//�ɹ�ƥ��1��
      {  count++;
         j=0;				//j����Ϊ0������ƥ��
      }
   }
   return count;
}

void GetNextval(SqString t, int nextval[])
{
    int j=0,k=-1;
    nextval[0]=-1;

    while(j<t.length)
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++; k++;
            if (t.data[j] != t.data[k])
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




void Printf(char a[])
{
    int i=0;
    while(a[i]!='\0'){
        printf("%c ",a[i++]);
    }
    printf("\n");
}

void Menu()
{
    printf("****************************\n");
    printf("      1.���������ģʽ��       \n");
    printf("      2.���BF�㷨�Ĳ��ҽ��   \n");
    printf("      3.���next����          \n");
    printf("      4.���nextval����       \n");
    printf("      5.���KMP�㷨���ҽ��    \n");
    printf("      6.���KMP��ǿ������㷨  \n");
    printf("      7.����Ӵ����ִ���       \n");
    printf("      8.�˳�                  \n");
    printf("*****************************\n");
}

int main ()
{
    int i=0,j=0,k,next[100],nextval[100],o,p;
    //char a[100], b[100],c[100];
 /*   printf("enter sting S:");
    scanf("%s",a);
    printf("enter string t1��");
    scanf("%s",b); 
    printf("enter string t2��");
    scanf("%s",c);
*/  
    char a[]="abcabcdabcdeabcdefabcdefg",b[]="abcdeabcdefab",c[]="abcde";

    SqString s,t,t2;

    StrAssign(s,a);
    StrAssign(t,b);
    StrAssign(t2,c);
    Menu();
    scanf("%d",&j);
    while(j!=8)
    {    
        switch(j) {
            case 1:   printf("������"),Printf(a);
                      printf("ģʽ��t1��"),Printf(b);
                      printf("ģʽ��t2��"),Printf(c);
                       break;
            case 2:   printf(" BFƥ��ģʽ��t1: ");
                      k=BF(s,t); 
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��\n");
                   
                      printf(" BFƥ��ģʽ��t2: ");
                      k=BF(s,t2); 
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��\n");
                    break;
            case 3:   printf("t1�õ�next���飺");
                      GetNext(t,next);
                      for(int i=0; i<t.length; i++)
                          printf("%d ",next[i]);
                          printf("\n");
                   
                      printf("t2�õ�next���飺");
                      GetNext(t2,next);
                      for(int i=0; i<t2.length; i++)
                          printf("%d ",next[i]);
                          printf("\n");
                    break;
            case 4:   printf("��ȡt1��nextval���飺");
                      GetNextval(t,nextval);
                      for(int i=0; i<t.length; i++)
                          printf("%d ",nextval[i]);
                          printf("\n");

                      printf("��ȡt2��nextval���飺");
                       GetNextval(t2,nextval);
                      for(int i=0; i<t2.length; i++)
                          printf("%d ",nextval[i]);
                          printf("\n");
                    break;
            case 5:   printf("KMP�㷨��t1��");
                      k=KMPIndex(s,t);
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��");

                      printf("KMP�㷨��t2��");
                       k=KMPIndex(s,t2);
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��");
                    break;
            case 6:   printf("KMP��ǿ�㷨��t1: ");
                      k=KMPIndex1(s,t);
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��");

                      printf("KMP��ǿ�㷨��t2: ");
                      k=KMPIndex1(s,t2);
                      if(k!=-1)  printf("%d\n",k);
                      else       printf("δ�ҵ���ģʽ��");
                    break;
            case 7:    o=StrCount2(s,t); p=StrCount2(s,t2);
                      printf("�Ӵ�t1�ĳ��ִ���Ϊ��%d\n",o);
                      printf("�Ӵ�t2�ĳ��ִ���Ϊ��%d\n",p);
                      break;
            default: break;
               
        }
         scanf("%d",&j);
    }

    system("pause");
}
//����Ŀ�괮s=��abcabcdabcdeabcdefabcdefg����ģʽ��t1=��abcdeabcdefab����t2=��abcde����
