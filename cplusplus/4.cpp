#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main ()
{
    int num;
	srand((unsigned) (time(NULL)));
    num=rand()%100+1;
    double f;
  /*  cin>>num;
    cout<<"you have "
        <<num
        <<" right"
        <<endl;*/

        cin>>f;
      double  k=sqrt(f);

        cout<<k<<endl;
    cout<<num;

        cin.get();
        cin.get();
        return 0;
}