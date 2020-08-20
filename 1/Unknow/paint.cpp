#include <windows.h>//����wingdi.h
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
 
#define PI 3.1416
 
#define ORIGINX 0 //�������X����
#define ORIGINY 200 //�������Y����
#define LENGTHX 800 //X�����᳤��
#define LENGTHY 300 //Y�����᳤��
#define XDATALEN 300//X����������
 
HDC hdc = 0;//����̨��ͼ�豸������� HDC
HPEN hPen, hPen2;//���ʱ���
HPEN hPenOld;
TCHAR title[256];//����̨�������
int times = 0;//���ƴ�������
double datay[XDATALEN];//��������������
 
  //������������
void ClearWind(HDC hdc)
{
 HPEN hPen;
 HBRUSH hBrush;
 hBrush = CreateSolidBrush(RGB(0, 0, 0));
 hPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
 SelectObject(hdc, hBrush);
 SelectObject(hdc, hPen);
 //���ƺ�ɫ���Σ���Χ�ɸ�����Ҫ���и���
 Rectangle(hdc, ORIGINX, 0, ORIGINX + LENGTHX + 1, ORIGINY + LENGTHY + 1);
}
 
int main()
{
 //��ȡ����̨����
 GetConsoleTitle(title, 256);
 //��ͨ��FindWindow�������������ȡ���ھ��HWND��֮��������GetDC��������HWND��ȡHDC
 hdc = GetDC(FindWindow(0, title));
 hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�������߻���,��ɫ
 hPen2 = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//����X�ử��,��ɫ
 hPenOld = (HPEN)SelectObject(hdc, hPen);
 
 while (1)
 {
 ClearWind(hdc);//����
 hPenOld = (HPEN)SelectObject(hdc, hPen);//ѡ�񻭱�
 MoveToEx(hdc, ORIGINX, ORIGINY, NULL);//�ƶ������
 
 for (int i = 0; i < XDATALEN; i++)
 {
 datay[i] = sin(0.1*i + times);//������������������
 }
 
 for (int i = 0; i < XDATALEN; i++)
 {
 //�����߶�,����ǰһ��������һ���㣬�ڶ�������ΪĿ���x���꣬����������Ϊy����
 LineTo(hdc, LENGTHX * i / XDATALEN + ORIGINX, 0.5 * LENGTHY * datay[i] + ORIGINY);
 }
 //��������x���pen������ѡ���豸������
 hPenOld = (HPEN)SelectObject(hdc, hPen2);//ѡ�񻭱�
 MoveToEx(hdc, ORIGINX, ORIGINY, NULL);//�ƶ������
 LineTo(hdc, ORIGINX + LENGTHX, ORIGINY);//����X��ֱ��
 times++;
 Sleep(100);//��ʱ100ms
 
 if (kbhit())//����Ƿ��а�������
 {
 if (_getch() == 0x1b)//������ESC������ѭ��
 {
 break;
 }
 }
 }
 
 DeleteObject(hPen);//ɾ������
 DeleteObject(hPen2);//ɾ������
 return 0;
}