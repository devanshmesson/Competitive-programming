#include <iostream>
 
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
 
 if(n>=1 && m<=100)
  {
      if(n>=1 && k<=100)
      {
    if(m>=n && k>=n)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
      }
  }
 
 
    return 0;
}
