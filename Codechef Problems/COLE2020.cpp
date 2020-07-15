#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,ok=1;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]%2==0)ok=0;
  }
  if(ok==0){cout<<"NO"<<endl;}
  else cout<<"YES"<<endl;
 }
}
