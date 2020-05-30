#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a[6];
    int p;
    for(int i=0;i<5;i++)cin>>a[i];
    cin>>p;
    for(int i=0;i<5;i++)a[i]*=p;
    int sum=0,ans=0;
    for(int i=0;i<5;i++)
    {
        sum=24-a[i];
        ans+=sum;
    }
    if(ans>=0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    
  }
}
