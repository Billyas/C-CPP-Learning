
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;
 
int get_n(int a, int b)
{
	int temp1 = pow(10.0, (double)b);
	int temp2 = pow(10.0, (double)(b - 1));
	return (a % temp1 - a % temp2) / temp2;
}
 
int main()
{
	queue <int> n_queue[10];
	//queue <int> temp_queue;
	int n = 0;
	scanf("%d", &n);
	int num[10000] = {0};
	for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
	for(int i = 0; ; ++i)
	{
		int zero_count = 0;
		for(int j = 0; j < n; ++j)
		{
			int temp = get_n(num[j], i + 1);
			n_queue[temp].push(num[j]);
			if (!temp) zero_count++;
		}
		int cur = 0;
		if (zero_count != n)
		{
			printf("Step%d.\n", i + 1);
			for(int j = 0; j < 10; ++j)
			{
				printf("Queue%d:", j);
				while(!n_queue[j].empty())
				{
					int temp = n_queue[j].front();
					//temp_queue.push(temp);
					num[cur++] = temp;
					n_queue[j].pop();
					printf("%d", temp);
					if (!n_queue[j].empty()) printf(" ");
				}
				printf("\n");
			}
		}
		else
		{
			while(!n_queue[0].empty())
			{
				int temp = n_queue[0].front();
				//temp_queue.push(temp)
				n_queue[0].pop();
				printf("%d", temp);
				if (!n_queue[0].empty()) printf(" ");
			}
			printf("\n");
			break;
		}
	}
	return 0;
}