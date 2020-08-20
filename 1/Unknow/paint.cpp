#include <windows.h>//引入wingdi.h
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
 
#define PI 3.1416
 
#define ORIGINX 0 //曲线起点X坐标
#define ORIGINY 200 //曲线起点Y坐标
#define LENGTHX 800 //X坐标轴长度
#define LENGTHY 300 //Y坐标轴长度
#define XDATALEN 300//X坐标数据量
 
HDC hdc = 0;//控制台绘图设备描述句柄 HDC
HPEN hPen, hPen2;//画笔变量
HPEN hPenOld;
TCHAR title[256];//控制台程序标题
int times = 0;//绘制次数变量
double datay[XDATALEN];//曲线纵坐标数组
 
  //绘制清屏矩形
void ClearWind(HDC hdc)
{
 HPEN hPen;
 HBRUSH hBrush;
 hBrush = CreateSolidBrush(RGB(0, 0, 0));
 hPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
 SelectObject(hdc, hBrush);
 SelectObject(hdc, hPen);
 //绘制黑色矩形，范围可根据需要自行更改
 Rectangle(hdc, ORIGINX, 0, ORIGINX + LENGTHX + 1, ORIGINY + LENGTHY + 1);
}
 
int main()
{
 //获取控制台标题
 GetConsoleTitle(title, 256);
 //先通过FindWindow函数借助标题获取窗口句柄HWND，之后再利用GetDC函数借助HWND获取HDC
 hdc = GetDC(FindWindow(0, title));
 hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//设置曲线画笔,红色
 hPen2 = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//设置X轴画笔,蓝色
 hPenOld = (HPEN)SelectObject(hdc, hPen);
 
 while (1)
 {
 ClearWind(hdc);//清屏
 hPenOld = (HPEN)SelectObject(hdc, hPen);//选择画笔
 MoveToEx(hdc, ORIGINX, ORIGINY, NULL);//移动到起点
 
 for (int i = 0; i < XDATALEN; i++)
 {
 datay[i] = sin(0.1*i + times);//生成曲线纵坐标数组
 }
 
 for (int i = 0; i < XDATALEN; i++)
 {
 //绘制线段,连接前一个点与下一个点，第二个参数为目标点x坐标，第三个参数为y坐标
 LineTo(hdc, LENGTHX * i / XDATALEN + ORIGINX, 0.5 * LENGTHY * datay[i] + ORIGINY);
 }
 //创建绘制x轴的pen并将其选入设备上下文
 hPenOld = (HPEN)SelectObject(hdc, hPen2);//选择画笔
 MoveToEx(hdc, ORIGINX, ORIGINY, NULL);//移动到起点
 LineTo(hdc, ORIGINX + LENGTHX, ORIGINY);//绘制X轴直线
 times++;
 Sleep(100);//延时100ms
 
 if (kbhit())//检查是否有按键按下
 {
 if (_getch() == 0x1b)//若按下ESC键跳出循环
 {
 break;
 }
 }
 }
 
 DeleteObject(hPen);//删除画笔
 DeleteObject(hPen2);//删除画笔
 return 0;
}