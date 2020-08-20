#include <stdio.h> 
#include <string.h> 
#include <time.h> 

int Show(void) 
{ 
   char str[100]; 
   time_t t; 
   struct tm *lt; 
   t = time(NULL); 
   lt = localtime(&t); 
   strftime(str,100,"%Y-%m-%d  %H:%M:%S ",lt); 
   printf("当前日期及时间是:\n%s\n",str); 
   getchar(); 
   return 0; 
} 

main()
{
Show();
}