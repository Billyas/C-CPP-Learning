#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{
	initgraph(640, 480);
	line(200, 240, 440, 240);
	line(320, 120, 320, 360);
	_getch();
	closegraph();

	return 0;
}