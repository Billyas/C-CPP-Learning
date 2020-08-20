#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{

    //cout<<"good study";
    //cout<<" day day up";
    //cout<<" OK"<<endl;
    
  //  system("pause");
    
    char n;
    int num;
    //cin.get(n);
    cin>>num;
    cout<<"here is "<<num<<endl;
     cin.get(n);                       //接受输入的'\n'
    cout<<"请按任意键继续. . .";
     cin.get(n);                       //继续接受字符类似与system（“pause”）
        return 0;
}