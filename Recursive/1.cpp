//��ŵ������ 
#include <iostream>
#include <cstdlib>
using namespace std;
 
//�����Ϊnumdisk�����Ӵ�init������desti�� 
void moveOne(int numDisk, string init, string desti) 
{
	cout << "Move disk No. " << numDisk << " from " << init << " to " << desti << endl;
}
//��numDisks�����Ӵ�init�˽���temp������desti��
void move(int numDisks, string init, string temp, string desti)
{
	if(numDisks == 1)
		moveOne(1, init, desti);
	else
	{
		 
		move(numDisks-1, init, desti, temp);//���Ƚ�����ģ�numDisk-1�������Ӵ�init�˽���desti������temp��
		moveOne(numDisks, init, desti);		//Ȼ�󽫱��ΪnumDisks�����Ӵ�init������desti��
		move(numDisks-1, temp, init, desti);//�������ģ�numDisks-1�������Ӵ�temp�˽���init������desti�� 
	}
} 
 
int main()
{
	move(3, "A", "B", "C");	 
    system("pause");
	return 0;
}
/*
//===============���н��==================
Move disk No. 1 from A to C
Move disk No. 2 from A to B
Move disk No. 1 from C to B
Move disk No. 3 from A to C
Move disk No. 1 from B to A
Move disk No. 2 from B to C
Move disk No. 1 from A to C
�밴���������. . .
*/