#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
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