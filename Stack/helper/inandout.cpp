
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
         
         if(a[j]<a[i])//�ҵ�����С��Ԫ�أ�����Щ����С��Ԫ��Ҫ���ɵݼ�
          {
              if(a[j]>item)
                return false;
              else
            {
              item=a[j];//���ں���һ��a[j]���Ƚϣ����ж��Ƿ�Ϊ�ݼ� 
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
       for(int i=0;i<a.size();i++)//�����жϽ�ջ�������ʱ��size
     { 
     
      k=1; 
      for(int j=i+1;j<a.size();j++) //�����ж�ÿ�������ڵĵݼ����е����size
       {
         if(a[j]<a[i])
          {
         k++;          
          }
         size.push_back(k); 
       }
   }
   size.sort();
   cout<<" "<<size.back(); //�������size
     }
    else
       cout<<"No"; 
   
   system("pause");
       return 0;      
    
   }
