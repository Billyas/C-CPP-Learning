//汉诺塔问题 
#include <iostream>
#include <cstdlib>
using namespace std;
 
//将编号为numdisk的盘子从init杆移至desti杆 
void moveOne(int numDisk, string init, string desti) 
{
	cout << "Move disk No. " << numDisk << " from " << init << " to " << desti << endl;
}
//将numDisks个盘子从init杆借助temp杆移至desti杆
void move(int numDisks, string init, string temp, string desti)
{
	if(numDisks == 1)
		moveOne(1, init, desti);
	else
	{
		 
		move(numDisks-1, init, desti, temp);//首先将上面的（numDisk-1）个盘子从init杆借助desti杆移至temp杆
		moveOne(numDisks, init, desti);		//然后将编号为numDisks的盘子从init杆移至desti杆
		move(numDisks-1, temp, init, desti);//最后将上面的（numDisks-1）个盘子从temp杆借助init杆移至desti杆 
	}
} 
 
int main()
{
	move(3, "A", "B", "C");	 
    system("pause");
	return 0;
}
/*
//===============运行结果==================
Move disk No. 1 from A to C
Move disk No. 2 from A to B
Move disk No. 1 from C to B
Move disk No. 3 from A to C
Move disk No. 1 from B to A
Move disk No. 2 from B to C
Move disk No. 1 from A to C
请按任意键继续. . .
*/