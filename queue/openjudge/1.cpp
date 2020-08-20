#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ElemType int
#define MaxSize  2000
typedef struct ss{
    ElemType data[MaxSize];
    int front,rear;   
}SqQueue;

void InitQueue(SqQueue* &q)
{ 
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}

void DestoryQueue(SqQueue* &q)
{
    free(q);
}

bool QueueEmpty(SqQueue* q)
{
    return (q->front==q->rear);
}

bool enQueue(SqQueue*& q,ElemType e)
{
    if(q->rear==MaxSize-1)
        return false;

    q->rear++;
    q->data[q->rear]=e;
    return true;

}

bool deQueue(SqQueue*& q,ElemType &e)
{
    if(q->rear==q->front)
        return false;
    q->front++;
    e=q->data[q->front];
    return true;    
}

int Num(int h)
{
    int i=0;
    if(h==0) return 1;
    while(h>0){
        i++;
        h/=10;
    }
    return i;
}

int data(int g,int num) //返回num的第g位数字
{
    int result,i=1;
    int k=Num(num);  //获取位数
    if(num==0||g>k) return 0;
    else if(num<=9&&g==1) return num;
 
    
    while(num>=10&&i<g){
        num/=10;
        i++;
    }
    result=num%10;
     return result;
}

 int main ()
 {
      int n,i=0,j,a[100],max=0,k=0,e,t=0;
      scanf("%d\n",&n);

      SqQueue *q[10];

      for(i=0;i<10;i++){
          InitQueue(q[i]);
      }
      
   for(i = 0; i < n; i++){
          if(i!=n-1) scanf("%d ",&a[i]);
          else scanf("%d",&a[i]);
      }   // a[i]='\0';

    for(i = 0; i < n; i++)  //找出最大值
    {
        k=Num(a[i]);
        if(k>max)
            max=k;      
    }

  //  printf("%d\n",max);
      for(i = 1; i <= max; i++)     //
    {
        printf("Step%d.\n",i);
        
        for(j=0;j<10;j++) {         //建立0-9的队对应的数字并输出

            for(k=0;k<n;k++)
            {
                if(data(i,a[k])==j)
                    enQueue(q[j],a[k]);
            }
            

        } 
           t=0;
           for(j=0;j<10;j++){
              printf("Queue%d:",j);
              while(!QueueEmpty(q[j])){
                deQueue(q[j],e);
               a[t++]=e;
               printf("%d ",e); 
            }printf("\n");
      }
        //printf("\n");
    }

   for(i=0;i<n;i++){
       printf("%d ",a[i]);
   }printf("\n");


   system("pause");
   return 0;

 }

 /*
20
41 67 34 0 69 24 78 58 62 64 5 45 81 27 61 91 95 42 27 36


  4
  1 2 3 4  
    */


