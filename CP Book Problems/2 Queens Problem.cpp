#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int ans(int n)
{
 if(n==1 || n==2)return 0;
 return (ans(n-1)+((n-1)*(n-2)*((2*n)-1))-(n-1)*(n-2));
}

int main() 
{ 
  
  int n;
  cin>>n;
  cout<<ans(n);


  }

