#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

int main ()
{
    gotoxy(5,12);
    printf("hello world\n");
    gotoxy(20,12);
    printf("feel good");

    for(int i=0;i<100;i++){
       gotoxy(35,12);
        printf("%d",i);
        Sleep(500);
        system("cls");
    }
    system("pause");
    return 0;
}