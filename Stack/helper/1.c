
 
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h> 
 
 
//typedef int DataType;
typedef char DataType;
 
 
 
#define MAX_SIZE 100
 
typedef struct Stack
{
	DataType _arr[MAX_SIZE];
	int _top;
}Stack;
 
void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}
 
int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}
 
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_top == MAX_SIZE)
	{
		printf("’ª“—æ≠¬˙¡À£°\n");
	}
	s->_arr[s->_top] = data;
	s->_top++;
}
void StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("’ª“—æ≠ø’¡À£°\n");
		return;
	}
	s->_top--;
 
}
DataType StackTop(Stack* s)
{
	assert(s);
	return s->_arr[s->_top - 1];
}
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
 
 
//
void Test()
{
	Stack s;
	StackInit(&s);
 
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
 
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));
 
 
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));
}
 
 
 
////¿®∫≈∆•≈‰/////
int isBracket(char ch)
{
	if (('(' == ch || ')' == ch) ||
		('[' == ch || ']' == ch) ||
		('{' == ch || '}' == ch))
		return 1;
	return 0;
}
int MatchBrackets(const char* pStr)
{
	int len = 0, i = 0;
	Stack s;
	if (NULL == pStr)
	{
		return 1;
	}
	StackInit(&s);
	len = strlen(pStr);
	for (; i < len; ++i)
	{
		if (isBracket(pStr[i]))
		{
			if ('(' == pStr[i] || '[' == pStr[i] || '{' == pStr[i])
			{
				StackPush(&s, pStr[i]);
			}
			else
			{
				if (StackEmpty(&s))
				{
					printf("”“¿®∫≈±»◊Û¿®∫≈∂‡£°\n");
					return 0;
				}
				else
				{
					//”√µ±«∞µƒ¿®∫≈∫Õ’ª∂•‘™Àÿ∆•≈‰
					char top = StackTop(&s);
					if (('(' == top && ')' == pStr[i] )||
                    ('[' == top && ']' == pStr[i]) ||
                    ('{' == top && '}' == pStr[i]))
				{
					StackPop(&s);
				}
			
					else
					{
						printf("◊Û”“¿®∫≈¥Œ–Ú∆•≈‰”–ŒÛ£°\n");
						return 0;
					}
 
				}
			}
		}
	}
	if (!-StackEmpty(&s))
	{
		printf("◊Û¿®∫≈±»”“¿®∫≈∂‡£°\n");
		return 0;
	}
 
	printf("¿®∫≈∆•≈‰’˝»∑£°£°£°\n");
	return 1;
}
 
 
 
 
void TestMatchBrackets()
{
	char a[] = "(())abc{[(])}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]()}";
	char e[] = "{}";
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
	MatchBrackets(e);
 
 
}



int main()
{
	//TestMatchBrackets();
    
     int i=0,m,k=0;
    
    char a[100],e;
    scanf("%s",a);


    MatchBrackets(a);



	system("pause");
	return 0;
}

//{{{{)))
//{([)]}