#include<bits/stdc++.h>
using namespace std;
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a;
    cin>>n>>a;

    if((1&a)==1)
    {
      if(n%2==0)cout<<"Even"<<endl;
      else cout<<"Odd"<<endl;
    }
    else 
      {
        if(n==1)cout<<"Even"<<endl;
        else cout<<"Impossible"<<endl;
      }
  }   
}

/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
