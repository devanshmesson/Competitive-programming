#include<bits/stdc++.h>
using namespace std;
main()
{ 
 int t;
 cin>>t;
 while(t--)
 {
   int n,cnt=0;
   cin>>n;
   int a[n+1];
   map<int,int>mp;
   for(int i=0;i<n;i++)
    {
      cin>>a[i];
      mp[a[i]]++;
    }
    int ok=0;
    for(auto x:mp)
    {
      cnt++;
      if(cnt>=2){ok=1;break;}
    }
    if(ok)cout<<1<<endl;
    else cout<<n<<endl;
 } 
}
