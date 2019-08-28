#include <iostream>

using namespace std;

int main()
{
  int t1,t2,t3,a[1000000]={0},cnt=0;
  int x,y,z;
  cin>>t1>>t2>>t3;
  for(int i=0;i<t1;i++)
  {
      cin>>x;
       a[x]+=1;
  }
  for(int i=0;i<t2;i++)
  {
      cin>>y;
       a[y]+=1;
  }
  for(int i=0;i<t3;i++)
  {
      cin>>z;
       a[z]+=1;
  }
  for(int i=0;i<1000000;i++)
  {
      if(a[i]>=2)
      {
         cnt++;
      }
  }
  cout<<cnt<<endl;
  for(int i=0;i<1000000;i++)
  {
       if(a[i]>=2)
      {
           cout<<i<<endl;
      }

    }

    return 0;
}
