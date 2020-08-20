#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
void fun(int k)
{
  switch(k) {
    case 0: printf("\t    \n\t    \n\t    \n\t    _\n"); break;
    case 1: printf("\t    \n\t    \n\t    \n\t****_\n"); break;
    case 2: printf("\t    \n\t    \n\t****\n\t    _\n"); break;
    case 3: printf("\t    \n\t    \n\t****\n\t****_\n"); break;
    case 4: printf("\t    \n\t****\n\t    \n\t    _\n"); break;
    case 5: printf("\t    \n\t****\n\t    \n\t****_\n"); break;
    case 6: printf("\t    \n\t****\n\t****\n\t    _\n"); break;
    case 7: printf("\t    \n\t****\n\t****\n\t****_\n"); break;
    case 8: printf("\t****\n\t    \n\t    \n\t    _\n"); break;
    case 9: printf("\t****\n\t    \n\t    \n\t****_\n"); break;  
  }
}
int Show(void) 
{ 
  char str[100]; 
  time_t t; 
  struct tm *lt; 
  t = time(NULL); 
  lt = localtime(&t); 
  strftime(str,100,"%Y-%m-%d  %H:%M:%S ",lt); 
  printf("当前日期及时间是:\n%s\n",str);
  
  //gotoxy(35,2);
  fun(lt->tm_hour/10);
  fun(lt->tm_hour%10);
  printf("\t    \n\t  *  \n\t  *  \n\t    \n");
  fun(lt->tm_min/10);
  fun(lt->tm_min%10); 

  return 0; 
} 





void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() )
      ;
}
 
 
int main() 
{ 
        while(true)
    {
    system("cls");
    Show();
    sleep(1000);
    }
}