/*
Time bohat keemti hai!
Har samay kaam ke baare me socho!
machaate machaate!
*/
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
      int n,k,l;
      cin>>n>>k>>l;
      int ans=(n/k); 
      if(n%k!=0)ans++;

      if(k==1 && n>k && l>=ans){cout<<-1<<endl;continue;}
      if(l>=ans)
      {
        for(int i=1;i<=n;i++)
        {
          if(i%k!=0)cout<<i%k<<" ";
          else cout<<k<<" ";
        }
        cout<<endl;
      }
      else cout<<-1<<endl;
    }
}
