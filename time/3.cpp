#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <stdlib.h>
 
int Show(void) 
{ 
  char str[100]; 
  time_t t; 
  struct tm *lt; 
  t = time(NULL); 
  lt = localtime(&t); 
  strftime(str,100,"%Y-%m-%d  %H:%M:%S ",lt); 
  printf("当前日期及时间是:\n%s\n",str);  
  return 0; 
} 
void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() )
      ;
}
 
 
main() 
{ 
        while(true)
    {
    system("cls");
    Show();
    sleep(1000);
    }
}