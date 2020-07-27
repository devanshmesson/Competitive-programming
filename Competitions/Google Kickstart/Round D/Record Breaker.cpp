//Problem-https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
#include<bits/stdc++.h>
using namespace std;
main()
{
   #define int long long int 
   int t;
   cin>>t;
   for(int j=1;j<=t;j++)
   {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0,mx=-1;

    for(int i=0;i<n;i++)
    {
     if(a[i]>mx && a[i]>a[i+1] && i<n-1)ans++;   
     else if(i==n-1 && a[i]>mx)ans++;
     mx=max(mx,a[i]);  
    }
    cout<<"Case #"<<j<<": "<<ans<<endl;
   }
  return 0;
}
