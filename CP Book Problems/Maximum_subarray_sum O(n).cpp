#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int main() 
{ 
  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  int ans=0,m=INT_MIN;
  for(int i=0;i<n;i++)
  {
   ans=max(a[i],ans+a[i]);
   m=max(m,ans);
  }
  cout<<m<<endl;

}

