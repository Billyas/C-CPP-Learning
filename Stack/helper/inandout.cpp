
   #include<bits/stdc++.h>
   using namespace std;
   bool isRight(vector<int> a)
   {
    //int marked[a.size()];
    for(int i=0;i<a.size();i++)
     {
       //if(marked[i]) continue;
   
      int item=a[i];
      //marked[i]=true;
      for(int j=i+1;j<a.size();j++) 
       {
         //if(marked[j])    continue;
         
         if(a[j]<a[i])//找到比它小的元素，而这些比它小的元素要构成递减
          {
              if(a[j]>item)
                return false;
              else
            {
              item=a[j];//用于和下一个a[j]作比较，来判断是否为递减 
            }
           //marked[j]=true;     
          }
       }
              
    }
    return true;
    }


   int main()
   {
   int n,x,k=1;
   vector<int> a;
   list<int> size; 
   cin>>n;
   for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    if(isRight(a))
     {
       cout<<"Yes";
       for(int i=0;i<a.size();i++)//用于判断进栈个数最大时的size
     { 
     
      k=1; 
      for(int j=i+1;j<a.size();j++) //就是判断每个数所在的递减数列的最大size
       {
         if(a[j]<a[i])
          {
         k++;          
          }
         size.push_back(k); 
       }
   }
   size.sort();
   cout<<" "<<size.back(); //输出最大的size
     }
    else
       cout<<"No"; 
   
   system("pause");
       return 0;      
    
   }
