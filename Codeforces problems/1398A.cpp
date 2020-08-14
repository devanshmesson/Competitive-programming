#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];

   if(a[0]+a[1]<=a[n-1])
   {
    cout<<1<<" "<<2<<" "<<n<<endl;
   }
   else 
   {
    cout<<-1<<endl;
   }
  } 
} 
