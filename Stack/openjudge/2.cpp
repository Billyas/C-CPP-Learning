#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
typedef struct Stack
{
int top;
char elem[MaxSize];
}ss;
bool Pop(struct Stack*s ,char &ch)
{
if(s->top > -1)
{
ch=s->elem[s->top];
s->top--;
return true;
}
else
return false;
}//
void Push(char ch , struct Stack*s)
{
s->top++;
s->elem[s->top]=ch;
}//
int main ()
{
struct Stack *st=(struct Stack*)malloc(sizeof(struct Stack));
st->top=-1;
char str[MaxSize];
scanf("%s",str);
int i;
char ch;
for(i=0;i<strlen(str);i++)
{
if(str[i]=='{' || str[i]=='[' ||str[i]=='(' )
Push(str[i],st);
else 
{
if(!Pop(st ,ch))
{
printf("Extra right brackets\n");
return 0;
}
if((ch=='{'&& str[i]=='}') ||( ch=='['&& str[i]==']') ||(ch=='(' && str[i]==')'))
{
continue;
}
else
{
printf("Brackets not match\n");
return 0;
}
}
}
if(st->top > -1)
{
printf("Extra left brackets\n");
return 0;
}
printf("Brackets match\n");
    return 0;
}