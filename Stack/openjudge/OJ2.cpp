# include <stdio.h>
# include <stdlib.h>
#define ElemType int 
#define maxsize 100
typedef struct {
    ElemType data[maxsize];
    int top;
}SqStack;
void InitStack(SqStack*& s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
  if(s!=NULL) s->top = -1;
}

void DestroyStack(SqStack*& s)
{
    free(s);
}

bool StackEmpty(SqStack*& s)
{
    return (s->top == -1);
}

bool Push(SqStack*& s, ElemType e)
{
    if (s->top == maxsize - 1)
        return false;

    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack*& s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack* s, ElemType &e)
{
    if (s->top == -1)
        return false;

    e = s->data[s->top];
    return true;
}

int main ()
{
   int i=0,n=0,j=0,size=0;
   int flag=1;
   SqStack*s;  InitStack(s);
   ElemType e,a[maxsize];
   scanf("%d\n",&n);

   for(i = 0; i < n; i++){
      if(i==n-1) scanf("%d",&a[i]);
      else scanf("%d ",&a[i]);
   }

   for(i = 0;i < n; i++){//代表对n各个进行分析
        
        if(i==0){

           for(j = 1;j <= a[i]; j++)//进栈的到第一个的位置
               Push(s,j);
            if((s->top+1)>size) size= s->top+1;
            Pop(s,e);             //出栈第一个元素
        }
        else {
           
           if(a[i]>a[i-1]){           //如果第二个元素比前一个大，继续进栈
              for( ; j <= a[i]; j++)
                 Push(s,j);
                
               if((s->top+1)>size) size=s->top+1;
              Pop(s,e);
           }else if(a[i]<a[i-1]){

                      if(Pop(s,e)&&a[i]==e){
                         int f=1;
                      }else{
                        flag=0;
                        printf("No\n");
                          system("pause");
                          return 0;
                      }

           }

        }

   }

   if(flag)
   printf("Yes %d\n",size);
   

 system("pause");
  return 0;

   

}